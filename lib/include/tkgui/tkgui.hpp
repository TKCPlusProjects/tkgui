#ifndef tkgui_hpp
#define tkgui_hpp

#include <tkgui/tkgui_base.hpp>
#include <tkgui/tkgui_view.hpp>
#include <tkgui/tkgui_view_title.hpp>
#include <tkgui/tkgui_view_setting.hpp>
#include <tkgui/tkgui_view_option.hpp>
#include <tkgui/tkgui_view_table.hpp>
#include <tkgui/tkgui_view_navigator.hpp>
#include <tkgui/tkgui_window.hpp>
#include <tkgui/tkgui_window_main.hpp>
#include <tkgui/tkgui_window_alert.hpp>
#include <tkgui/tkgui_window_setting.hpp>
#include <tkgui/tkgui_window_toast.hpp>
#include <tkgui/tkgui_window_pause.hpp>
#include <tkgui/tkgui_scene.hpp>

using namespace tkht::tkgui;

namespace tkht {
namespace tkgui {
void UpdateWindowSize(int width, int height);

void Init(int width, int height, const char *title);
void Display(TKGUIDisplayFunc func);
void Exit();

void AlertShow(const char* text, function<void()> accept_func, function<void()> cancel_func);
void AlertDismiss();

void ToastShow(const char* text);
void ToastDismiss();
} // namespace tkgui
} // namespace tkht

#endif /* tkgui_hpp */
