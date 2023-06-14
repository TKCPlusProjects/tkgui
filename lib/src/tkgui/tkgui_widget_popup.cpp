#include <tkgui/tkgui_widget_popup.hpp>

namespace tkht {
namespace tkgui {
Popup::Popup(vector<shared_ptr<MenuItem>> items) : Widget(), items(items) {}

void Popup::Pin() {
  ImGuiID menu_id = tkgui::ViewID();
  if (ImGui::IsMouseReleased(ImGuiMouseButton_Right) && ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenBlockedByPopup)) {
    ImGui::OpenPopupEx(menu_id, ImGuiPopupFlags_None);
  }
  ImGuiWindowFlags flags = 
  ImGuiWindowFlags_NoDecoration |
  ImGuiWindowFlags_NoNav |
  ImGuiWindowFlags_AlwaysAutoResize;
  if (ImGui::BeginPopupEx(menu_id, flags)) {
    ImGui::Dummy(ImVec2(0.0f, 5.0f));
    for (shared_ptr<MenuItem> item : items) item->Pin();
    ImGui::Dummy(ImVec2(0.0f, 5.0f));
    ImGui::EndPopup();
  }
}
} // namespace tkgui
} // namespace tkht