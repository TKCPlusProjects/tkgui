#include <tkgui/tkgui_window_main.hpp>

namespace tkht {
namespace tkgui {
WindowMain::WindowMain() : Window("TKGUI_WINDOW_MAIN") { 
  title = make_shared<tkgui::ViewTitle>();

  option_table = make_shared<tkgui::ViewTableOption>();
  option_table->height_func = [=](int index) {
    return option_table->size.y * 0.25f;
  };
}

void WindowMain::SetText(const char* text) {
  title->text = text;
}

void WindowMain::SetOptions(vector<pair<const char*, function<void()>>> options) {
  option_table->cell_list.clear();
  for (pair<const char*, function<void()>> option_pair : options) {
    option_table->cell_list.push_back(option_table->CreateCell(option_pair.first, option_pair.second));
  }
}

void WindowMain::OnUpdateSize(int width, int height) {
  pos = ImVec2();
  size = ImVec2(width, height);

  title->pos = ImVec2(0.0f, size.y * 0.1f);
  title->size = ImVec2(size.x * 1.0f, size.y * 0.3f);
  option_table->pos = ImVec2(size.x * 0.4f, size.y * 0.5f);
  option_table->size = ImVec2(size.x * 0.2f, size.y * 0.4f);
}
void WindowMain::OnDisplay() {
  title->Display();
  option_table->Display();
}
} // namespace tkgui
} // namespace tkht
