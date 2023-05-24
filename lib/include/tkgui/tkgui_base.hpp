#ifndef tkgui_base_hpp
#define tkgui_base_hpp

#define GLFW_INCLUDE_NONE
#define GLEW_NO_GLU
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <tkgm/tkgm.hpp>
#include <tkcore/tkcore.hpp>

namespace tkht {
namespace tkgui {
enum FontType {
  FontType_Begin = -1,
  FontType_Title = 0,
  FontType_Button = 1,
  FontType_Text = 2,
  FontType_End = 9,
};

typedef function<void(int, const char *)> TKGUIErrorFunc;
typedef function<void(int, int)> TKGUISizeCallback;
typedef function<void(const char *, function<void()>, function<void()>)> TKGUIAlertCallback;
typedef function<void(const char *)> TKGUIToastCallback;
typedef function<void()> TKGUIDisplayFunc;

extern ImGuiWindowFlags UIFlags;

extern GLFWwindow *WindowRoot;
extern int Width, Height;

extern map<FontType, ImFont *> Fonts;

extern const char *WindowCurrent;
extern const char *WindowFocus;

extern ImGuiID ViewGUIID;

extern TKGUIErrorFunc ErrorFunc;
extern vector<TKGUISizeCallback> SizeCallbackList;
extern TKGUIAlertCallback AlertCallback;
extern TKGUIToastCallback ToastCallback;

void SetFont(const char *path, map<FontType, float> font_map);
ImFont *Font(FontType type);

void SetErrorfun(TKGUIErrorFunc func);
void SetSizeCallback(TKGUISizeCallback callback);
void SetAlertCallback(TKGUIAlertCallback callback);
void SetToastCallback(TKGUIToastCallback callback);

void WindowDisplay(const char *name);
bool WindowFocused();
bool WindowVacant();
ImGuiID ViewID();

void AlertShow(const char* text, function<void()> accept_func, function<void()> cancel_func);
void AlertDismiss();
void ToastShow(const char* text);
void ToastDismiss();
} // namespace tkgui
} // namespace tkht

#endif /* tkgui_base_hpp */
