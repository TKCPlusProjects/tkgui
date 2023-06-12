#ifndef tkgui_window_hpp
#define tkgui_window_hpp

#include <tkgui/tkgui_base.hpp>

namespace tkht {
namespace tkgui {
class Window {
protected:
  ImGuiWindowFlags flags;
  const char *name;
public:
  bool hide, modal;
  ImVec2 pos, size;
  vector<shared_ptr<Window>> subwindows;

  Window(const char *name, bool modal = false, ImGuiWindowFlags flags = tkgui::UIFlags);

  void Show();
  void Hide();

  void Add(shared_ptr<Window> window);

  void UpdateSize(int width, int height);
  virtual void OnUpdateSize(int width, int height) = 0;
  virtual void OnUpdateSizeSubwindows(int width, int height);
  
  void Display();
  virtual void OnDisplay() = 0;
  virtual void OnDisplaySubwindows();
};
} // namespace tkgui
} // namespace tkht

#endif /* tkgui_window_hpp */
