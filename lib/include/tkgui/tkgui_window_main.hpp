#ifndef tkgui_window_start_hpp
#define tkgui_window_start_hpp

#include <tkgui/tkgui_window.hpp>
#include <tkgui/tkgui_view_title.hpp>
#include <tkgui/tkgui_view_option.hpp>

namespace tkht {
namespace tkgui {
class WindowMain : public Window {
public:
  shared_ptr<tkgui::ViewTitle> title;
  shared_ptr<tkgui::ViewTableOption> option;
  
  WindowMain();

  void SetText(const char* text);
  void SetOptions(vector<pair<const char*, function<void()>>> options);

  void OnUpdateSize(int width, int height) override;
  void OnDisplay() override;
};
} // namespace tkgui
} // namespace tkht

#endif /* tkgui_window_start_hpp */
