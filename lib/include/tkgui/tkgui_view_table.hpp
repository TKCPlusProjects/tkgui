#ifndef tkgui_view_table_hpp
#define tkgui_view_table_hpp

#include <tkgui/tkgui_view.hpp>

namespace tkht {
namespace tkgui {
class ViewTable: public View {
public:
  class Cell: public View {};

  vector<shared_ptr<Cell>> cell_list;

  function<int()> count_func;
  function<float(int)> height_func;
  function<void(int, ImVec2)> display_func;

  void OnDisplay() override;
};
} // namespace tkgui
} // namespace tkht

#endif /* tkgui_view_table_hpp */
