#include <tkgui/tkgui_widget_menu.hpp>

namespace tkht {
namespace tkgui {
MenuItem::MenuItem(const char* text, function<void()> action) : Widget(), text(text), action(action) {}
MenuItem::MenuItem(const char* text, vector<shared_ptr<MenuItem>> items) : Widget(), text(text), items(items) {}

void MenuItem::Pin() {
  ImGui::SetCursorPosX(5.0f);
  if (items.size() > 0) {
    if (ImGui::BeginMenu(text)) {
      ImGui::Dummy(ImVec2(0.0f, 5.0f));
      for (shared_ptr<MenuItem> item : items) item->Pin();
      ImGui::Dummy(ImVec2(0.0f, 5.0f));
      ImGui::EndPopup();
    }
  } else {
    if (ImGui::MenuItem(text)) action();
  }
}
} // namespace tkgui
} // namespace tkht
