#include <tkgui/tkgui_view_option.hpp>

namespace tkht {
namespace tkgui {
void ViewTableOptionCell::OnDisplay() {
  shared_ptr<ViewTableOption> table = this->table.lock();

  if (ImGui::Button(text, size)) {
    table->action = action;
  }
}

shared_ptr<ViewTableOptionCell> ViewTableOption::CreateCell(const char* text, function<void()> action) {
  shared_ptr<ViewTableOptionCell> cell = ViewTable::CreateCell();
  cell->text = text;
  cell->action = action;
  return cell;
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
