#ifndef tkgui_view_option_hpp
#define tkgui_view_option_hpp

#include <tkgui/tkgui_view_table.hpp>

namespace tkht {
namespace tkgui {
class ViewTableOption : public ViewTable {
public:
  class Cell : public ViewTable::Cell {
  public:
    const char* text;
    function<void()> action;
    Cell(const char* text, function<void()> action) : ViewTable::Cell(), text(text), action(action) {};

    void OnDisplay() override;
  };

  void OnDisplay() override;
};
} // namespace tkgui
} // namespace tkht

#endif /* tkgui_view_option_hpp */
