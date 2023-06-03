#include <tkgui/tkgui_view_setting.hpp>

namespace tkht {
namespace tkgui {
void ViewTableSettingCell::OnDisplay() {
  shared_ptr<ViewTableSetting> table = this->table.lock();

  ImVec2 text_size = ImGui::CalcTextSize(item->title);
  ImVec2 text_pos = ImVec2(size.x * 0.05f, (size.y - text_size.y) * 0.5f);
  ImGui::SetCursorPos(text_pos);
  ImGui::Text("%s", item->title);
  ImGui::SameLine();
  ImGui::SetCursorPosX(size.x * 0.4f);
  ImGui::SetCursorPosY(ImGui::GetCursorPosY() - ImGui::GetStyle().ItemInnerSpacing.y);
  ImGui::SetNextItemWidth(size.x * 0.55f);
  switch (item->type) {
  case tkgm::SetItem::Type_Checkbox: {
    shared_ptr<tkgm::CheckboxItem> type_item = static_pointer_cast<tkgm::CheckboxItem>(item);
    ImGui::Checkbox("##Checkbox", &(type_item->value));
    } break;
    
  case tkgm::SetItem::Type_SliderInt: {
    shared_ptr<tkgm::SliderIntItem> type_item = static_pointer_cast<tkgm::SliderIntItem>(item);
    ImGui::SliderInt("##SliderInt", &(type_item->value), type_item->min, type_item->max, "%d");
    } break;
  case tkgm::SetItem::Type_SliderFloat: {
    shared_ptr<tkgm::SliderFloatItem> type_item = static_pointer_cast<tkgm::SliderFloatItem>(item);
    ImGui::SliderFloat("##SliderFloat", &(type_item->value), type_item->min, type_item->max, "%.0f");
    } break;
  case tkgm::SetItem::Type_KeyButton: {
    shared_ptr<tkgm::KeyButtonItem> type_item = static_pointer_cast<tkgm::KeyButtonItem>(item);
    if (ImGui::Button(type_item->name, ImVec2(ImGui::CalcItemWidth(), ImGui::GetFrameHeight()))) {
      table->action = [=](){
        table->key_action(type_item);
      };
    }
    } break;
  default:
    break;
  }
}

shared_ptr<ViewTableSettingCell> ViewTableSetting::CreateCell(shared_ptr<tkgm::SetItem> item) {
  shared_ptr<ViewTableSettingCell> cell = ViewTable::CreateCell();
  cell->item = item;
  return cell;
}

void ViewTableSetting::OnDisplay() {
  ImGui::PushFont(Font(FontType_Button));

  ViewTable::OnDisplay();

  ImGui::PopFont();
}
} // namespace tkgui
} // namespace tkht
