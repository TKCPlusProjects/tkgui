#include <tkgui/tkgui_view.hpp>

namespace tkht {
namespace tkgui {
View::View(ImGuiWindowFlags flags) : flags(flags) {}

void View::Add(shared_ptr<View> view) {
  subviews.push_back(view);
}

void View::Display() {
  if (hide) return;
  
  ImGui::SetCursorPos(pos);
  ImGui::BeginChild(ViewID(), size, false, UIFlags);
  {
    OnDisplay();
    OnDisplaySubviews();
  }
  ImGui::EndChild();
}
void View::OnDisplaySubviews() {
  for (shared_ptr<View> view : subviews) view->Display();
}
} // namespace tkgui
} // namespace tkht
