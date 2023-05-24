#ifndef tkgui_view_setting_hpp
#define tkgui_view_setting_hpp

#include <tkgui/tkgui_view_table.hpp>

namespace tkht {
namespace tkgui {
class ViewTableSetting : public ViewTable {
public:
  class Cell : public ViewTable::Cell {
  public:
    shared_ptr<tkgm::SetItem> item;
    function<void()> action;
    Cell(shared_ptr<tkgm::SetItem> item, function<void()> action) : ViewTable::Cell(), item(item), action(action) {};

    void OnDisplay() override;
  };

  const char* text;
  void OnDisplay() override;
};

} // namespace tkgui
} // namespace tkht

#endif /* tkgui_view_setting_hpp */
