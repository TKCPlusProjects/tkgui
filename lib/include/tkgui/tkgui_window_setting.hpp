#ifndef tkgui_window_setting_hpp
#define tkgui_window_setting_hpp

#include <tkgui/tkgui_window.hpp>
#include <tkgui/tkgui_view_navigator.hpp>
#include <tkgui/tkgui_view_setting.hpp>

namespace tkht {
namespace tkgui {
class WindowSetting : public Window {
public:
  shared_ptr<tkgui::ViewNavigator> navigator;
  vector<shared_ptr<tkgui::ViewTableSetting>>setting_tables;

  WindowSetting();

  void SetForms(vector<shared_ptr<tkgm::SetForm>> forms);

  void OnUpdateSize(int width, int height) override;
  void OnDisplay() override;
};
} // namespace tkgui
} // namespace tkht

#endif /* tkgui_window_setting_hpp */
