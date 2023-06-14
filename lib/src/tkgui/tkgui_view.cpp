#include <tkgui/tkgui_view.hpp>

namespace tkht {
namespace tkgui {
View::View(bool auto_pos, ImGuiWindowFlags flags) : auto_pos(auto_pos), flags(flags) {}

void View::Add(shared_ptr<View> view) {
  subviews.push_back(view);
}

void View::Display() {
  if (hide) return;
  
  if (!auto_pos) ImGui::SetCursorPos(pos);
  ImGui::BeginChild(ViewID(), size, false, flags);
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
