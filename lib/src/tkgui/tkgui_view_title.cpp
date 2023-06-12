#include <tkgui/tkgui_view_title.hpp>

namespace tkht {
namespace tkgui {
void ViewTitle::OnDisplay() {
  ImGui::PushFont(Font(FontType_Title));
  {
    if (text) {
      ImVec2 text_size = ImGui::CalcTextSize(text);
      ImVec2 text_pos = ImVec2((size.x - text_size.x) * 0.5f, size.y * 0.4f);
      ImGui::SetCursorPos(text_pos);
      ImGui::Text("%s", text);
    }
  }
  ImGui::PopFont();
}
} // namespace tkgui
} // namespace tkht
