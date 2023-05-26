#ifndef tkgui_window_pause_hpp
#define tkgui_window_pause_hpp

#include <tkgui/tkgui_window.hpp>
#include <tkgui/tkgui_view_option.hpp>

namespace tkht {
namespace tkgui {
class WindowPause : public Window {
public:
  shared_ptr<tkgui::ViewTableOption> option;
  
  WindowPause();

  void SetOptions(vector<pair<const char*, function<void()>>> options);

  void OnUpdateSize(int width, int height) override;
  void OnDisplay() override;
};
} // namespace tkgui
} // namespace tkht

#endif /* tkgui_window_pause_hpp */
