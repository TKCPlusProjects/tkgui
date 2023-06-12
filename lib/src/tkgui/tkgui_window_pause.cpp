#include <tkgui/tkgui_window_pause.hpp>

namespace tkht {
namespace tkgui {
WindowPause::WindowPause() : Window("TKGUI_WINDOW_PAUSE", true) {
  option_table = make_shared<tkgui::ViewTableOption>();
  option_table->height_func = [=](int index) {
    return option_table->size.y * 0.25f;
  };
}

void WindowPause::SetOptions(vector<pair<const char*, function<void()>>> options) {
  option_table->cell_list.clear();
  for (pair<const char*, function<void()>> option_pair : options) {
    option_table->cell_list.push_back(option_table->CreateCell(option_pair.first, option_pair.second));
  }
}

void WindowPause::OnUpdateSize(int width, int height) {
  pos = ImVec2();
  size = ImVec2(width, height);

  option_table->pos = ImVec2(size.x * 0.4f, size.y * 0.3f);
  option_table->size = ImVec2(size.x * 0.2f, size.y * 0.4f);
}
void WindowPause::OnDisplay() {
  option_table->Display();
  if (ImGui::IsKeyPressed(ImGuiKey_Escape) && WindowFocused()) {
    Hide();
  };
}
} // namespace tkgui
} // namespace tkht
