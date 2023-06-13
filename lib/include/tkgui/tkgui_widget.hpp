#ifndef tkgui_widget_hpp
#define tkgui_widget_hpp

#include <tkgui/tkgui_base.hpp>

namespace tkht {
namespace tkgui {
class Widget {
public:
  virtual void Pin() = 0;
};
} // namespace tkgui
} // namespace tkht

#endif /* tkgui_widget_hpp */
