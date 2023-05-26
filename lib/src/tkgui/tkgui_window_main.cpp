#include <tkgui/tkgui_window_main.hpp>

namespace tkht {
namespace tkgui {
WindowMain::WindowMain() : Window("TKGUI_WINDOW_MAIN") { Show(); }

void WindowMain::SetText(const char* text) {
  if (!title) {
    title = make_shared<tkgui::ViewTitle>();
    title->pos = ImVec2(0.0f, content_size.y * 0.1f);
    title->size = ImVec2(content_size.x * 1.0f, content_size.y * 0.3f);
  }
  title->text = text;
}

void WindowMain::SetOptions(vector<pair<const char*, function<void()>>> options) {
  if (!option) {
    option = make_shared<tkgui::ViewTableOption>();
    option->pos = ImVec2(content_size.x * 0.4f, content_size.y * 0.5f);
    option->size = ImVec2(content_size.x * 0.2f, content_size.y * 0.4f);

    option->height_func = [=](int index) {
      return option->size.y * 0.25f;
    };
  }
  option->cell_list.clear();
  for (pair<const char*, function<void()>> option_pair : options) {
    option->cell_list.push_back(make_shared<tkgui::ViewTableOption::Cell>(option_pair.first, option_pair.second));
  }
}

void WindowMain::OnUpdateSize(int width, int height) {
  pos = ImVec2();
  size = ImVec2(width, height);
  content_pos = pos;
  content_size = size;

  title->pos = ImVec2(0.0f, content_size.y * 0.1f);
  title->size = ImVec2(content_size.x * 1.0f, content_size.y * 0.3f);
  option->pos = ImVec2(content_size.x * 0.4f, content_size.y * 0.5f);
  option->size = ImVec2(content_size.x * 0.2f, content_size.y * 0.4f);
}
void WindowMain::OnDisplay() {
  Window::Begin(true);
  {
    title->Display();
  }
  {
    ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
    ImGui::PushFont(Font(FontType_Button));

    option->Display();

    ImGui::PopFont();
    ImGui::PopStyleColor(1);
  }
  Window::End();
}
} // namespace tkgui
} // namespace tkht
