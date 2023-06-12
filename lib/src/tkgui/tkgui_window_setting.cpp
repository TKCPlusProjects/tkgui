#include <tkgui/tkgui_window_setting.hpp>

namespace tkht {
namespace tkgui {
WindowSetting::WindowSetting() : Window("TKGUI_WINDOW_OPTION", true) {
  navigator = make_shared<tkgui::ViewNavigator>();
  navigator->text = "ViewTableSetting";
  navigator->close_func = [=](){
    Hide();
  };
}

void WindowSetting::SetForms(vector<shared_ptr<tkgm::SetForm>> forms) {
  setting_tables.clear();
  for (shared_ptr<tkgm::SetForm> form : forms) {
    shared_ptr<tkgui::ViewTableSetting> setting_table = make_shared<tkgui::ViewTableSetting>();
    setting_table->text = form->name;
    setting_table->height_func = [=](int index) {
      return 50.0f;
    };
    setting_table->key_action = [=](shared_ptr<tkgm::KeyButtonItem> item){
      if (item->type == tkgm::SetItem::Type_KeyButton) {
        ToastShow("Pless Input The 'Key' ...");
        tkgm::control->Listen(dynamic_pointer_cast<KeyButtonItem>(item));
      }
    };
    for (shared_ptr<tkgm::SetItem> item : form->items) {
      setting_table->cell_list.push_back(setting_table->CreateCell(item));
    };
    setting_tables.push_back(setting_table);
  }
}

void WindowSetting::OnUpdateSize(int width, int height) {
  pos = ImVec2(width * 0.1f, height * 0.1f);
  size = ImVec2(width * 0.8f, height * 0.8f);
  
  navigator->pos = ImVec2();
  navigator->size = ImVec2(size.x, 50.0f);
}
void WindowSetting::OnDisplay() {
  navigator->Display();
  ImGui::BeginTabBar("TKGUI_VIEW_SETTING_TABBAR", ImGuiTabBarFlags_None);
  for (shared_ptr<tkgui::ViewTableSetting> setting_table : setting_tables) {
    if (ImGui::BeginTabItem(setting_table->text)) {
      setting_table->pos = ImGui::GetCursorPos();
      setting_table->size = ImVec2(size.x, size.y - setting_table->pos.y);
      setting_table->Display();
      ImGui::EndTabItem();
    }
  }
  ImGui::EndTabBar();
  if (ImGui::IsKeyPressed(ImGuiKey_Escape) && WindowFocused()) {
    AlertShow("Save the modifications?", [=](){ Hide(); }, nullptr);
  };
}
} // namespace tkgui
} // namespace tkht
