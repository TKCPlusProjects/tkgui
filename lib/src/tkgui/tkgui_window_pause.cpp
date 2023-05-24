#include <tkgui/tkgui_window_pause.hpp>

namespace tkht {
namespace tkgui {
WindowPause::WindowPause() : Window("TKGUI_WINDOW_PAUSE") {}

void WindowPause::SetOptions(vector<pair<const char*, function<void()>>> options) {
  if (!option_table) {
    option_table = make_shared<tkgui::ViewTableOption>();
    option_table->pos = ImVec2(content_size.x * 0.4f, content_size.y * 0.3f);
    option_table->size = ImVec2(content_size.x * 0.2f, content_size.y * 0.4f);
    
    option_table->height_func = [=](int index) {
      return option_table->size.y * 0.25f;
    };
  }
  option_table->cell_list.clear();
  for (pair<const char*, function<void()>> option_pair : options) {
    option_table->cell_list.push_back(make_shared<tkgui::ViewTableOption::Cell>(option_pair.first, option_pair.second));
  }
}

void WindowPause::OnUpdateSize(int width, int height) {
  pos = ImVec2();
  size = ImVec2(width, height);
  content_pos = pos;
  content_size = size;

  option_table->pos = ImVec2(content_size.x * 0.4f, content_size.y * 0.3f);
  option_table->size = ImVec2(content_size.x * 0.2f, content_size.y * 0.4f);
}
void WindowPause::OnDisplay() {
  Window::Begin();
  {
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
    ImGui::PushFont(Font(FontType_Button));

    option_table->Display();

    ImGui::PopFont();
    ImGui::PopStyleColor(1);
  }
  if (ImGui::IsKeyPressed(ImGuiKey_Escape) && WindowFocused()) {
    Hide();
  };
  Window::End();
}
} // namespace tkgui
} // namespace tkht
