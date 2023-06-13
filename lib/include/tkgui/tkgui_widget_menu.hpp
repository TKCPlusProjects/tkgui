#ifndef tkgui_widget_menu_hpp
#define tkgui_widget_menu_hpp

#include <tkgui/tkgui_widget.hpp>

namespace tkht {
namespace tkgui {
class MenuItem : public Widget {
protected:
  function<void()> action;
public:
  const char* text;
  vector<shared_ptr<MenuItem>> items;

  MenuItem(const char* text, function<void()> action);
  MenuItem(const char* text, vector<shared_ptr<MenuItem>> items);

  void Pin() override;
};
} // namespace tkgui
} // namespace tkht

#endif /* tkgui_widget_menu_hpp */
