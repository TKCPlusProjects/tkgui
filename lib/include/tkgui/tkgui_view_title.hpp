#ifndef tkgui_view_title_hpp
#define tkgui_view_title_hpp

#include <tkgui/tkgui_view.hpp>

namespace tkht {
namespace tkgui {
class ViewTitle : public View {
public:
  const char *text;

  void OnDisplay() override;
};
} // namespace tkgui
} // namespace tkht

#endif /* tkgui_view_title_hpp */
