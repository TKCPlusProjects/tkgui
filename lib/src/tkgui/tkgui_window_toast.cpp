#include <tkgui/tkgui_window_toast.hpp>

namespace tkht {
namespace tkgui {
WindowToast::WindowToast() : Window("TKGUI_WINDOW_WAITING", true) {
  title = make_shared<tkgui::ViewTitle>();
}

void WindowToast::SetText(const char* text) {
  title->text = text;
}

void WindowToast::OnUpdateSize(int width, int height) {
  pos = ImVec2();
  size = ImVec2(width, height);

  title->pos = ImVec2(size.x * 0.1f, size.y * 0.1f);
  title->size = ImVec2(size.x * 0.8f, size.y * 0.8f);
}

void WindowToast::OnDisplay() {
  title->Display();
}
} // namespace tkgui
} // namespace tkht
