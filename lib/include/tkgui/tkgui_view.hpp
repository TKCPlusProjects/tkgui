#ifndef tkgui_view_hpp
#define tkgui_view_hpp

#include <tkgui/tkgui_base.hpp>

namespace tkht {
namespace tkgui {
class View {
protected:
  ImGuiWindowFlags flags;
public:
  bool hide = false;
  bool auto_pos = false;
  ImVec2 pos, size;
  vector<shared_ptr<View>> subviews;

  View(bool auto_pos = false, ImGuiWindowFlags flags = UIFlags);

  void Add(shared_ptr<View> view);

  void Display();
  virtual void OnDisplay() = 0;
  virtual void OnDisplaySubviews();
};
} // namespace tkgui
} // namespace tkht

#endif /* tkgui_view_hpp */
