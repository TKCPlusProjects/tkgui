#ifndef tkgui_view_hpp
#define tkgui_view_hpp

#include <tkgui/tkgui_base.hpp>

namespace tkht {
namespace tkgui {
class View {
protected:
  const ImGuiID identify;
public:
  bool hide;
  ImVec2 pos, size;
  vector<shared_ptr<View>> children;

  View();

  void Add(shared_ptr<View> child);

  void Display();
  virtual void OnDisplay();
  virtual void OnDisplayChildren();
};
} // namespace tkgui
} // namespace tkht

#endif /* tkgui_view_hpp */
