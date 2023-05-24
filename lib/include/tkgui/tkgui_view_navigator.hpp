#ifndef tkgui_view_navigator_hpp
#define tkgui_view_navigator_hpp

#include <tkgui/tkgui_view.hpp>

namespace tkht {
namespace tkgui {
class ViewNavigator : public View {
public:
  const char *text;
  function<void()> close_func;

  void OnDisplay() override;
};
} // namespace tkgui
} // namespace tkht

#endif /* tkgui_view_navigator_hpp */
