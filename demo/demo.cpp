#include <tkgui/tkgui.hpp>

class ViewTableTitleCell;
class ViewTableTitle;

class ViewTableTitleCell : public ViewTableCell<ViewTableTitle> {
public:
  const char* title;
  
  shared_ptr<Popup> popup;

  void OnDisplay() override;
};

class ViewTableTitle : public ViewTable<ViewTableTitle, ViewTableTitleCell> {
public:
  function<void(int)> add_action;
  function<void(int)> remove_action;

  shared_ptr<ViewTableTitleCell> CreateCell(const char* title);
  void OnDisplay() override;
};

void ViewTableTitleCell::OnDisplay() {
  ImGui::Separator();
  ImGui::PushStyleColor(ImGuiCol_Text, is_select ? ImVec4(0.6f, 0.0f, 0.0f, 1.0f) : ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
  ImGui::SetNextItemWidth(50.0f);
  ImGui::LabelText("##", "%d", index);
  ImGui::PopStyleColor(1);

  ImGui::SameLine();
  ImGui::SetNextItemWidth(100.0f);
  ImGui::LabelText("##", "%s", title);
  popup->Pin();
  
  ImGui::SameLine();
  if (ImGui::Button("+", ImVec2(30.0f, 30.0f))) {
    SetTableAction([=](auto table){ table->add_action(index); });
  }
  ImGui::SameLine();
  if (ImGui::Button("-", ImVec2(30.0f, 30.0f))) {
    SetTableAction([=](auto table){ table->remove_action(index); });
  }

  ImGui::Separator();
}

shared_ptr<ViewTableTitleCell> ViewTableTitle::CreateCell(const char* title) {
  shared_ptr<ViewTableTitleCell> cell = ViewTable::CreateCell();
  cell->title = title;
  cell->popup = make_shared<Popup>(vector<shared_ptr<MenuItem>>{
    make_shared<MenuItem>("Select", [=](){ select_index = cell->index; }),
    make_shared<MenuItem>("Hello", [=](){ printf("Hello\n"); }),
    make_shared<MenuItem>("World", [=](){ printf("World\n"); }),
    make_shared<MenuItem>("Others", vector<shared_ptr<MenuItem>>{
      make_shared<MenuItem>("Bezingga", [=](){ printf("Bezingga\n"); }),
      make_shared<MenuItem>("Yahaha", [=](){ printf("Yahaha\n"); }),
    }),
  });
  return cell;
}

void ViewTableTitle::OnDisplay() {
  ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
  ImGui::PushFont(Font(FontType_Button));
  {
    ViewTable::OnDisplay();
  }
  ImGui::PopFont();
  ImGui::PopStyleColor(1);
}

class WindowTitle : public Window {
public:
  shared_ptr<ViewTableTitle> title_table;

  WindowTitle();

  void InsertTitle(const char* title, int index = 0);
  void RemoveTitle(int index = 0);
  
  void OnUpdateSize(int width, int height) override;
  void OnDisplay() override;
};

WindowTitle::WindowTitle() : Window("TKGPG_WINDOW_VERTEX") {
  title_table = make_shared<ViewTableTitle>();
  title_table->height_func = [=](int i) {
    return 32.0f;
  };
  title_table->add_action = [=](int i){
    title_table->cell_list.insert(title_table->cell_list.begin() + i + 1, title_table->CreateCell("Yahaha"));
  };
  title_table->remove_action = [=](int i){
    title_table->cell_list.erase(title_table->cell_list.begin() + i);
  };
  
  title_table->cell_list.push_back(title_table->CreateCell("Yahaha"));

  Show();
}

void WindowTitle::OnUpdateSize(int width, int height) {
  pos = ImVec2(width * 0.7f, 0.0f);
  size = ImVec2(width * 0.3f, height);

  title_table->pos = ImVec2();
  title_table->size = size;
}

void WindowTitle::OnDisplay() {
  title_table->Display();
}

enum CurrentWindowDisplay {
  Main,
  Title,
};

static CurrentWindowDisplay display = Main;

int main() {
  tkht::Debug = true;
  tkht::SubscribeSignalCrash();

  tkgm::Load();
  
  Init(tkgm::video->window_width->Get(), tkgm::video->window_height->Get(), "tksurvivor");

  shared_ptr<WindowMain> main_window = make_shared<WindowMain>();
  main_window->SetText("Welcome Survivor");
  main_window->SetOptions({
    {"New", [=](){ display = Title; }},
    {"Load", [=](){ cout << "Load" << endl; }},
    {"Settings", [=](){ cout << "Settings" << endl; }},
    {"About", [=](){ cout << "About" << endl; }},
    {"Exit", [=](){ cout << "Exit" << endl; }},
  });
  main_window->UpdateSize(Width, Height);

  shared_ptr<WindowTitle> title_window = make_shared<WindowTitle>();
  title_window->UpdateSize(Width, Height);

  Display([=](){
    switch (display) {
    case Main: {
      main_window->Display();
    } break;
    case Title: {
      title_window->Display();

      if (ImGui::IsKeyPressed(ImGuiKey_Escape)) {
        display = Main;
      }
    } break;
    }
  });

  Exit();

  return 1;
}