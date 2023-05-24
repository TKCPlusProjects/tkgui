#include <tkgui/tkgui.hpp>

namespace tkht {
namespace tkgui {
tkgui::WindowAlert alert;
tkgui::WindowToast toast;

void GLFWErrorFunc(int error_code, const char *description) {
  if (ErrorFunc) {
    ErrorFunc(error_code, description);
  }
}
void GLFWWindowsizeCallback(GLFWwindow *window, int width, int height) {
  if (WindowRoot == window) {
    UpdateWindowSize(width, height);
  }
}
void LocalAlertCallback(const char* message, function<void()> accept_func, function<void()> cancel_func) {
  alert.SetText(message);
  alert.accept_func = accept_func;
  alert.cancel_func = cancel_func;
}
void LocalToastCallback(const char* message) {
  toast.SetText(message);
}

void UpdateWindowSize(int width, int height) {
  Width = width;
  Height = height;
  alert.UpdateSize(width, height);
  toast.UpdateSize(width, height);
  for (TKGUISizeCallback size_callback : SizeCallbackList) {
    size_callback(width, height);
  }
}

void Init(int width, int height, const char *title) {
  if (!glfwInit()) {
    Assert(false, "GLFW Init Failed");
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  UpdateWindowSize(width, height);
  WindowRoot = glfwCreateWindow(width, height, title, nullptr, nullptr);
  if (!WindowRoot) {
    glfwTerminate();
    Assert(false, "GLFW Create WindowRoot Failed");
  }

  glfwMakeContextCurrent(WindowRoot);
  glClearColor(0.3f, 0.3f, 0.3f, 1.0f);

  glewExperimental = GL_TRUE;
  glewInit();

  IMGUI_CHECKVERSION();   // 检查版本号是否一致
  ImGui::CreateContext(); // 创建上下文
  ImGuiIO &io = ImGui::GetIO();
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
  io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

  ImGui_ImplGlfw_InitForOpenGL(WindowRoot, true);
  ImGui_ImplOpenGL3_Init("#version 150");

  glfwSetErrorCallback(GLFWErrorFunc);
  glfwSetWindowSizeCallback(WindowRoot, GLFWWindowsizeCallback);
  SetAlertCallback(LocalAlertCallback);
  SetToastCallback(LocalToastCallback);
}

void NewFrame(GLbitfield mask) {
  glClear(mask);

  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();

  WindowDisplay(nullptr);
  ViewGUIID = 0;
}

void Render() {
  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

  glfwSwapBuffers(WindowRoot);
}

void Shutdown() {
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();

  glfwDestroyWindow(WindowRoot);
  glfwTerminate();
}

void Display(TKGUIDisplayFunc func) {
  while (!glfwWindowShouldClose(WindowRoot)) {
    glfwPollEvents();

    NewFrame(GL_COLOR_BUFFER_BIT);
    {
      ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
      ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(5.0f, 5.0f));
      ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2(0.0f, 0.0f));

      func();
      
      alert.Display();
      toast.Display();
      
      if (tkgm::control->Listening() == false) {
        ToastDismiss();
      }

      ImGui::PopStyleVar(3);

      WindowFocus = WindowCurrent;
    }
    Render();
  }
  Shutdown();
}

void Exit() { glfwSetWindowShouldClose(WindowRoot, GL_TRUE); }
} // namespace tkgui
} // namespace tkht