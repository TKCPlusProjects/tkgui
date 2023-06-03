#ifndef tkgui_view_option_hpp
#define tkgui_view_option_hpp

#include <tkgui/tkgui_view_table.hpp>

namespace tkht {
namespace tkgui {
class ViewTableOptionCell;
class ViewTableOption;

class ViewTableOptionCell : public ViewTableCell<ViewTableOption> {
public:
  const char* text;
  function<void()> action;

  void OnDisplay() override;
};
class ViewTableOption : public ViewTable<ViewTableOption, ViewTableOptionCell> {
public:
  shared_ptr<ViewTableOptionCell> CreateCell(const char* text, function<void()> action);
  void OnDisplay() override;
};
} // namespace tkgui
} // namespace tkht

#endif /* tkgui_view_option_hpp */
