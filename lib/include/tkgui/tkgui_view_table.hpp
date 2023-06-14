#ifndef tkgui_view_table_hpp
#define tkgui_view_table_hpp

#include <tkgui/tkgui_view.hpp>

namespace tkht {
namespace tkgui {
template <typename Tt>
class ViewTableCell : public View {
public:
  int index = 0;
  bool is_select = false;
  weak_ptr<Tt> table;

  ViewTableCell(ImGuiWindowFlags flags = UIFlags) : View(true, flags) {}
  void SetTableAction(function<void(shared_ptr<Tt>)> action) {
    this->table.lock()->action = action;
  }
};

template <typename Tt, typename Tc>
class ViewTable : public View, public enable_shared_from_this<Tt> {
public:
  int select_index;
  function<float(int)> height_func;
  function<void(shared_ptr<Tt>)> action;
  vector<shared_ptr<Tc>> cell_list;

  ViewTable(bool auto_pos = false, ImGuiWindowFlags flags = UIFlags) : View(auto_pos, flags) {}

  shared_ptr<Tc> CreateCell() {
    shared_ptr<Tc> cell = make_shared<Tc>();
    cell->table = Tt::weak_from_this();
    return cell;
  }
  void OnDisplay() override {
    if (ImGui::BeginTable("TKGUI_VIEW_TABLE", 1, ImGuiTableFlags_None)) {
      ImGuiListClipper clipper;
      clipper.Begin(cell_list.size());
      while (clipper.Step()) {
        for (int row = clipper.DisplayStart; row < clipper.DisplayEnd; row++) {
          ImGui::TableNextRow();
          ImGui::TableSetColumnIndex(0);
          float height = height_func(row);
          shared_ptr<Tc> cell = cell_list[row];
          cell->index = row;
          cell->is_select = row == select_index;
          cell->pos = ImVec2(0, height * row);
          cell->size = ImVec2(size.x, height);
          cell->Display();
        }
      }
      ImGui::EndTable();
    }

    if (action) action(Tt::shared_from_this()); action = nullptr;
  }
};
} // namespace tkgui
} // namespace tkht

#endif /* tkgui_view_table_hpp */
