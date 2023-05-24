#include <tkgui/tkgui_scene.hpp>

namespace tkht {
namespace tkgui {
Scene::Scene() {}

void Scene::AddWindow(shared_ptr<tkgui::Window> window) {
  windows.push_back(window);
}

void Scene::UpdateSize(int width, int height) {
  OnUpdateSize(width, height);
  OnUpdateSizeSubwindows(width, height);
};
void Scene::OnUpdateSize(int width, int height) {
  size = ImVec2(width, height);
}
void Scene::OnUpdateSizeSubwindows(int width, int height) {
  for (shared_ptr<tkgui::Window> window : windows) window->UpdateSize(width, height);
}

void Scene::Display() {
  OnDisplay();
  OnDisplayWindows();
}
void Scene::OnDisplay() {
  
}
void Scene::OnDisplayWindows() {
  for (shared_ptr<tkgui::Window> window : windows) window->Display();
}
} // namespace tkgui
} // namespace tkht
