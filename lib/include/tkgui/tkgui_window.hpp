#ifndef tkgui_window_hpp
#define tkgui_window_hpp

#include <tkgui/tkgui_base.hpp>

namespace tkht {
namespace tkgui {
class Window {
protected:
  const char *name;
  bool showing = false;
public:
  ImVec2 pos, size;
  bool content_border = false;
  ImVec2 content_pos, content_size;
  vector<shared_ptr<Window>> subwindows; 

  Window(const char *name);

  virtual void Show();
  virtual void Hide();

  void AddSubwindow(shared_ptr<Window> window);

  void UpdateSize(int width, int height);
  virtual void OnUpdateSize(int width, int height);
  virtual void OnUpdateSizeSubwindows(int width, int height);
  
  void Display();
  virtual void OnDisplay();
  virtual void OnDisplaySubwindows();

  void Begin(bool fixed = false);
  void End();
};
} // namespace tkgui
} // namespace tkht

#endif /* tkgui_window_hpp */
