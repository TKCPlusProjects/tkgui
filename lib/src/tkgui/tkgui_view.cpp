#include <tkgui/tkgui_view.hpp>

namespace tkht {
namespace tkgui {
View::View() {}

void View::Add(shared_ptr<View> child) {
  children.push_back(child);
}

void View::Display() {
  if (hide) return;
  
  ImGui::SetCursorPos(pos);
  ImGui::BeginChild(ViewID(), size, false, UIFlags);
  {
    OnDisplay();
    OnDisplayChildren();
  }
  ImGui::EndChild();
}
void View::OnDisplay() {
  
}
void View::OnDisplayChildren() {
  for (shared_ptr<View> child : children) child->Display();
}
} // namespace tkgui
} // namespace tkht
