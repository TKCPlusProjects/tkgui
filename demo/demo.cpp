#include <tkgui/tkgui.hpp>

int main() 
{
  tkht::Debug = true;

  tkgm::Load();
  
  tkgui::Init(tkgm::video->window_width->Get(),
              tkgm::video->window_height->Get(), "tksurvivor");

  shared_ptr<tkgui::WindowMain> main_window = make_shared<tkgui::WindowMain>();
  main_window->SetText("Welcome Survivor");
  main_window->SetOptions({
    {"New", [=](){ cout << "New" << endl; }},
    {"Load", [=](){ cout << "Load" << endl; }},
    {"Settings", [=](){ cout << "Settings" << endl; }},
    {"About", [=](){ cout << "About" << endl; }},
    {"Exit", [=](){ cout << "Exit" << endl; }},
  });
  main_window->UpdateSize(Width, Height);

  tkgui::Display([=](){
    main_window->Display();
  });

  tkgui::Exit();

  return 1;
}