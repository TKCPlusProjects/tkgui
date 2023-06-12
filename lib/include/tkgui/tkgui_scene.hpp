#ifndef tkgui_scene_hpp
#define tkgui_scene_hpp

#include <tkgui/tkgui_window.hpp>

namespace tkht {
namespace tkgui {
class Scene {
public:
  vector<shared_ptr<tkgui::Window>> windows;

  Scene();

  void AddWindow(shared_ptr<tkgui::Window> window);

  void UpdateSize(int width, int height);
  virtual void OnUpdateSize(int width, int height) = 0;
  virtual void OnUpdateSizeSubwindows(int width, int height);

  void Display();
  virtual void OnDisplay() = 0;
  virtual void OnDisplayWindows();
};
} // namespace tkgui
} // namespace tkht

#endif /* tkgui_scene_hpp */
