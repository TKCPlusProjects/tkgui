#ifndef tkgui_scene_hpp
#define tkgui_scene_hpp

#include <tkgui/tkgui_window.hpp>

namespace tkht {
namespace tkgui {
class Scene {
public:
  ImVec2 size = ImVec2();
  vector<shared_ptr<tkgui::Window>> windows;

  Scene();

  void AddWindow(shared_ptr<tkgui::Window> window);

  void UpdateSize(int width, int height);
  virtual void OnUpdateSize(int width, int height);
  virtual void OnUpdateSizeSubwindows(int width, int height);

  void Display();
  virtual void OnDisplay();
  virtual void OnDisplayWindows();
};
} // namespace tkgui
} // namespace tkht

#endif /* tkgui_scene_hpp */
