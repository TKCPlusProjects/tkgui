#include <tkgui/tkgui_window_alert.hpp>

namespace tkht {
namespace tkgui {
WindowAlert::WindowAlert() : Window("TKGUI_WINDOW_ALERT") {}

void WindowAlert::SetText(const char* text) {
  if (title == nullptr) {
    title = make_shared<tkgui::ViewTitle>();
    title->pos = ImVec2();
    title->size = ImVec2(content_size.x * 1.0f, content_size.y * 0.5f);
  }
  title->text = text;
  if (text) {
    Show();
  } else {
    Hide();
  }
}

void WindowAlert::OnUpdateSize(int width, int height) {
  pos = ImVec2();
  size = ImVec2(width, height);
  content_pos = ImVec2(size.x * 0.1f, size.y * 0.1f);
  content_size = ImVec2(size.x * 0.8f, size.y * 0.8f);

  if (title) {
    title->pos = ImVec2();
    title->size = ImVec2(content_size.x * 1.0f, content_size.y * 0.5f);
  }
}

void WindowAlert::OnDisplay() {
  Window::Begin();
  ImGui::PushFont(Font(FontType_Text));
  {
    title->Display();
  }
  {
    float button_width = content_size.x * 0.2f;
    float button_height = content_size.y * 0.1f;
    float button_space = content_size.x * 0.1f;
    
    ImGui::SetCursorPosY(content_size.y * 0.6f);
    ImGui::SetCursorPosX((content_size.x - button_space) * 0.5f - button_width);
    if (ImGui::Button("Accept", ImVec2(button_width, button_height))) {
      if (accept_func) accept_func();
      Hide();
    }
    ImGui::SameLine();
    ImGui::SetCursorPosX((content_size.x - button_space) * 0.5f + button_space);
    if (ImGui::Button("Cancel", ImVec2(button_width, button_height))) {
      if (cancel_func) cancel_func();
      Hide();
    }
  }
  ImGui::PopFont();
  Window::End();
}
} // namespace tkgui
} // namespace tkht
