#include <tkgui/tkgui_base.hpp>

namespace tkht {
namespace tkgui {
ImGuiWindowFlags UIFlags = ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_NoNav;

GLFWwindow *WindowRoot;
int Width, Height;

map<FontType, ImFont *> Fonts;

const char *WindowCurrent = nullptr;
const char *WindowFocus = nullptr;

ImGuiID ViewGUIID = 0;

TKGUIErrorFunc ErrorFunc;
vector<TKGUISizeCallback> SizeCallbackList;
TKGUIAlertCallback AlertCallback;
TKGUIToastCallback ToastCallback;

void SetFont(const char *path, map<FontType, float> font_map) {
  ImFontConfig config;
  config.PixelSnapH = true;
  config.OversampleH = 1;
  config.OversampleV = 1;
  static const ImWchar ranges[] = {
      0x0020, 0x00FF, // 基本拉丁字符集（Basic Latin）
      0x4e00, 0x9FA5, // 中文字符集
      0,
  };
  ImGuiIO &io = ImGui::GetIO();
  for (FontType type = FontType_Begin; type < FontType_End;
       type = static_cast<FontType>(type + 1)) {
    map<FontType, float>::iterator it = font_map.find(type);
    if (it != font_map.end()) {
      Fonts[type] =
          io.Fonts->AddFontFromFileTTF(path, it->second, &config, ranges);
    }
  }
}
ImFont *Font(FontType type) { return Fonts[type]; }

void WindowDisplay(const char *name) { WindowCurrent = name; }
bool WindowFocused() { return WindowFocus == WindowCurrent; }
bool WindowVacant() { return WindowFocus == nullptr; }
ImGuiID ViewID() { return ++(ViewGUIID); }

void SetErrorfun(TKGUIErrorFunc func) { ErrorFunc = func; }
void SetSizeCallback(TKGUISizeCallback callback) {
  SizeCallbackList.push_back(callback);
}
void SetAlertCallback(TKGUIAlertCallback callback) { AlertCallback = callback; }
void SetToastCallback(TKGUIToastCallback callback) { ToastCallback = callback; }

void AlertShow(const char* text, function<void()> accept_func, function<void()> cancel_func) {
  AlertCallback(text, accept_func, cancel_func);
}
void AlertDismiss() {
  AlertCallback(nullptr, nullptr, nullptr);
}
void ToastShow(const char* text) {
  ToastCallback(text);
}
void ToastDismiss() {
  ToastCallback(nullptr);
}
} // namespace tkgui
} // namespace tkht
