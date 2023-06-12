#include <tkgui/tkgui_window_alert.hpp>

namespace tkht {
namespace tkgui {
WindowAlert::WindowAlert() : Window("TKGUI_WINDOW_ALERT", true) {
  title = make_shared<tkgui::ViewTitle>();
}

void WindowAlert::SetText(const char* text) {
  title->text = text;
}

void WindowAlert::OnUpdateSize(int width, int height) {
  pos = ImVec2();
  size = ImVec2(width, height);

  title->pos = ImVec2(size.x * 0.1f, size.y * 0.1f);
  title->size = ImVec2(size.x * 0.8f, size.y * 0.8f);
}

void WindowAlert::OnDisplay() {
  title->Display();
  ImGui::PushFont(Font(FontType_Text));
  {
    float button_width = size.x * 0.2f;
    float button_height = size.y * 0.1f;
    float button_space = size.x * 0.1f;
    
    ImGui::SetCursorPosY(size.y * 0.6f);
    ImGui::SetCursorPosX((size.x - button_space) * 0.5f - button_width);
    if (ImGui::Button("Accept", ImVec2(button_width, button_height))) {
      if (accept_func) accept_func();
      Hide();
    }
    ImGui::SameLine();
    ImGui::SetCursorPosX((size.x - button_space) * 0.5f + button_space);
    if (ImGui::Button("Cancel", ImVec2(button_width, button_height))) {
      if (cancel_func) cancel_func();
      Hide();
    }
  }
  ImGui::PopFont();
}
} // namespace tkgui
} // namespace tkht
