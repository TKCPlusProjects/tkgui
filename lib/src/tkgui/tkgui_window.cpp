#include <tkgui/tkgui_window.hpp>

namespace tkht {
namespace tkgui {
Window::Window(const char *name) : name(name) {}

void Window::Show() { showing = true; }
void Window::Hide() { showing = false; }

void Window::AddSubwindow(shared_ptr<Window> window) {
  subwindows.push_back(window);
}

void Window::UpdateSize(int width, int height) {
  OnUpdateSize(width, height);
  OnUpdateSizeSubwindows(width, height);
};
void Window::OnUpdateSize(int width, int height) {
  pos = ImVec2();
  size = ImVec2(width, height);
  content_pos = pos;
  content_size = size;
}
void Window::OnUpdateSizeSubwindows(int width, int height) {
  for (shared_ptr<Window> window : subwindows) window->UpdateSize(width, height);
}

void Window::Display() {
  if (showing) {
    OnDisplay();
    OnDisplaySubwindows();
  }
}
void Window::OnDisplay() {
  Begin();
  End();
}
void Window::OnDisplaySubwindows() {
  for (shared_ptr<Window> window : subwindows) window->Display();
}

void Window::Begin(bool fixed) {
  if (!fixed) WindowDisplay(name);
  ImGui::SetNextWindowPos(pos);
  ImGui::SetNextWindowSize(size);
  ImGui::Begin(name, nullptr, UIFlags);
  ImGui::SetCursorPos(content_pos);
  ImGui::BeginChild(ViewID(), content_size, true, UIFlags | ImGuiWindowFlags_NoScrollWithMouse);
}
void Window::End() { 
  ImGui::EndChild();
  ImGui::End();
}
} // namespace tkgui
} // namespace tkht
