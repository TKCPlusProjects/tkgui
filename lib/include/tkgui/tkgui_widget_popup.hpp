#ifndef tkgui_widget_popup_hpp
#define tkgui_widget_popup_hpp

#include <tkgui/tkgui_widget.hpp>
#include <tkgui/tkgui_widget_menu.hpp>

namespace tkht {
namespace tkgui {
class Popup : public Widget {
public:
  vector<shared_ptr<MenuItem>> items;

  Popup(vector<shared_ptr<MenuItem>> items);

  void Pin() override;
};
} // namespace tkgui
} // namespace tkht

#endif /* tkgui_widget_popup_hpp */
