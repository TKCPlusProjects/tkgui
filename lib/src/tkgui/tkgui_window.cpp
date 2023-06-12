#include <tkgui/tkgui_window.hpp>

namespace tkht {
namespace tkgui {

Window::Window(const char *name, bool modal, ImGuiWindowFlags flags) : name(name), modal(modal), hide(modal), flags(flags) {}

void Window::Show() { hide = false; }
void Window::Hide() { hide = true; }

void Window::Add(shared_ptr<Window> window) {
  subwindows.push_back(window);
}

void Window::UpdateSize(int width, int height) {
  OnUpdateSize(width, height);
  OnUpdateSizeSubwindows(width, height);
};
void Window::OnUpdateSizeSubwindows(int width, int height) {
  for (shared_ptr<Window> window : subwindows) window->UpdateSize(width, height);
}

void Window::Display() {
  if (hide) return;

  if (modal) WindowDisplay(name);
  ImGui::SetNextWindowPos(pos);
  ImGui::SetNextWindowSize(size);
  ImGui::Begin(name, nullptr, flags);
  {
    OnDisplay();
    OnDisplaySubwindows();
  }
  ImGui::End();
}
void Window::OnDisplaySubwindows() {
  for (shared_ptr<Window> window : subwindows) window->Display();
}
} // namespace tkgui
} // namespace tkht
