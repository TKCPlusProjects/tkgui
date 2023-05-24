#include <tkgui/tkgui_view_table.hpp>

namespace tkht {
namespace tkgui {
void ViewTable::OnDisplay() {
  ImGui::BeginTable("TKGUI_VIEW_TABLE", 1, ImGuiTableFlags_None);
  ImGuiListClipper clipper;
  clipper.Begin(cell_list.size());
  while (clipper.Step()) {
    for (int row = clipper.DisplayStart; row < clipper.DisplayEnd; row++) {
      ImGui::TableNextRow();
      ImGui::TableSetColumnIndex(0);
      float height = height_func(row);
      shared_ptr<Cell> cell = cell_list[row];
      cell->pos = ImVec2(0, height * row);
      cell->size = ImVec2(size.x, height);
      cell->Display();
    }
  }
  ImGui::EndTable();
}
} // namespace tkgui
} // namespace tkht
