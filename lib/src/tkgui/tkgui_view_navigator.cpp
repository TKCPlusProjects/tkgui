#include <tkgui/tkgui_view_navigator.hpp>

namespace tkht {
namespace tkgui {
void ViewNavigator::OnDisplay() {
  ImGui::PushFont(Font(FontType_Button));
  {
    float margin = size.y * 0.2f;
    
    if (text) {
      ImVec2 title_size = ImGui::CalcTextSize(text);
      ImVec2 title_pos = ImVec2((size.x - title_size.x) * 0.5f, margin);
      ImGui::SetCursorPos(title_pos);
      ImGui::Text("%s", text);
    }

    float close_side = size.y * 0.4f;
    ImVec2 close_size = ImVec2(close_side, close_side);
    ImVec2 close_pos = ImVec2(size.x - close_side - margin, margin);
    ImGui::SameLine();
    ImGui::SetCursorPos(close_pos);
    if (ImGui::Button(" ", close_size)) {
      close_func();
    }

    float close_margin = close_side * 0.2f;
    float close_content = close_side - close_margin;
    ImVec2 pos_draw = ImGui::GetItemRectMin();
    ImDrawList *draw_list = ImGui::GetWindowDrawList();
    draw_list->AddLine(
        ImVec2(pos_draw.x + close_margin, pos_draw.y + close_margin),
        ImVec2(pos_draw.x + close_content, pos_draw.y + close_content),
        IM_COL32(255, 255, 255, 255), 1.0f);
    draw_list->AddLine(
        ImVec2(pos_draw.x + close_content, pos_draw.y + close_margin),
        ImVec2(pos_draw.x + close_margin, pos_draw.y + close_content),
        IM_COL32(255, 255, 255, 255), 1.0f);
  }
  ImGui::PopFont();
}
} // namespace tkgui
} // namespace tkht
