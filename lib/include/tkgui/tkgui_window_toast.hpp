#ifndef tkgui_window_toast_hpp
#define tkgui_window_toast_hpp

#include <tkgui/tkgui_window.hpp>
#include <tkgui/tkgui_view_title.hpp>

namespace tkht {
namespace tkgui {
class WindowToast : public Window {
public:
  shared_ptr<tkgui::ViewTitle> title;

  WindowToast();

  void SetText(const char* text);

  void OnUpdateSize(int width, int height) override;
  void OnDisplay() override;
};
} // namespace tkgui
} // namespace tkht

#endif /* tkgui_window_toast_hpp */
