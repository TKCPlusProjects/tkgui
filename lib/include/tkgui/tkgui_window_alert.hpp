#ifndef tkgui_window_alert_hpp
#define tkgui_window_alert_hpp

#include <tkgui/tkgui_window.hpp>
#include <tkgui/tkgui_view_title.hpp>

namespace tkht {
namespace tkgui {
class WindowAlert : public Window {
public:
  function<void()> accept_func;
  function<void()> cancel_func;

  shared_ptr<tkgui::ViewTitle> title;

  WindowAlert();

  void SetText(const char* text);

  void OnUpdateSize(int width, int height) override;
  void OnDisplay() override;
};
} // namespace tkgui
} // namespace tkht

#endif /* tkgui_window_alert_hpp */
