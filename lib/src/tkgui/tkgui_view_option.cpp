#include <tkgui/tkgui_view_option.hpp>

namespace tkht {
namespace tkgui {
void ViewTableOption::Cell::OnDisplay() {
  if (ImGui::Button(text, size)) action();
}

void ViewTableOption::OnDisplay() {
  ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
  ImGui::PushFont(Font(FontType_Button));

  ViewTable::OnDisplay();

  ImGui::PopFont();
  ImGui::PopStyleColor(1);
}
} // namespace tkgui
} // namespace tkht
