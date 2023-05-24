#include <tkgui/tkgui_window_toast.hpp>

namespace tkht {
namespace tkgui {
WindowToast::WindowToast() : Window("TKGUI_WINDOW_WAITING") {}

void WindowToast::SetText(const char* text) {
  if (title == nullptr) {
    title = make_shared<tkgui::ViewTitle>();
    title->pos = ImVec2();
    title->size = ImVec2(content_size.x * 1.0f, content_size.y * 1.0f);
  }
  title->text = text;
  if (text) {
    Show();
  } else {
    Hide();
  }
}

void WindowToast::OnUpdateSize(int width, int height) {
  pos = ImVec2();
  size = ImVec2(width, height);
  content_pos = ImVec2(size.x * 0.1f, size.y * 0.1f);
  content_size = ImVec2(size.x * 0.8f, size.y * 0.8f);

  if (title) {
    title->pos = ImVec2();
    title->size = ImVec2(content_size.x * 1.0f, content_size.y * 1.0f);
  }
}

void WindowToast::OnDisplay() {
  Window::Begin();
  {
    title->Display();
  }
  Window::End();
}
} // namespace tkgui
} // namespace tkht
