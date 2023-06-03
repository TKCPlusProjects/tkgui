#ifndef tkgui_view_setting_hpp
#define tkgui_view_setting_hpp

#include <tkgui/tkgui_view_table.hpp>

namespace tkht {
namespace tkgui {
class ViewTableSettingCell;
class ViewTableSetting;

class ViewTableSettingCell : public ViewTableCell<ViewTableSetting> {
public:
  shared_ptr<tkgm::SetItem> item;
  
  void OnDisplay() override;
};
class ViewTableSetting : public ViewTable<ViewTableSetting, ViewTableSettingCell> {
public:
  const char* text;
  function<void(shared_ptr<tkgm::KeyButtonItem>)> key_action;

  shared_ptr<ViewTableSettingCell> CreateCell(shared_ptr<tkgm::SetItem> item);
  void OnDisplay() override;
};

} // namespace tkgui
} // namespace tkht

#endif /* tkgui_view_setting_hpp */
