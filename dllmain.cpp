#include <Windows.h>
#include <cstdint>
#include <vector>
#include "Vector.hpp"
#include "ImportFunctions.h"
#include "Utils.h"
#include "Globals.h"
#include "Classes.hpp"
#include "Mono.h"
#include "Renderer.h"
#include "Hooker.h"
#include "menu_config.h"
#include "xor.h"
#include "sapphire_hook.hpp"
#include "hooks.hpp"
#include <d3d9types.h>

//#include "RebirthGuardSDK.h"
//#include "RGString.h"
//#pragma comment(lib, "RebirthGuard.lib")
#include "systemmm.h"
#include "hoooook.h"
#include "laze.h"
#include "skStr.h"
#include "auth.hpp"

int font_size = 12;
float esp_max_distance = 130;

float aimCones = 0;
float bulletSpeed = 0;
float sightRange = 0;
int autoshootkey = 0;
int suicidekey = VK_F10;
bool no_playercollision = 0;
bool no_playercollision1 = 0;
bool no_playercollision2 = 1;
bool rocketprediction = 0;
bool suicide = 0;
bool cratess = 0;
bool autoshoot = 0;
bool doubletap = 0;
bool desync = 0;
bool manipulator2 = 0;
int desynckey;
bool instant_med = 0;
bool silent_melee = 0;
bool silent_farm = 0;
bool silent_farm1 = 0;
bool uknlol = 0;
bool uknlol1 = 0;
#pragma warning(disable : 4996).
//std::string t = RGS("");
float SizeBar = 50;
bool podepegar = false;
float tick_time_when_called;
uint32_t entity_type;
BasePlayer* Pickup = nullptr;
bool flash;
bool rpcppu = false;
bool farmhelp = 1;
bool autopickup;
BasePlayer* itemf = nullptr;
typedef void* (__stdcall* tmemcpy)(void* dest, const void* src, size_t count);
static tmemcpy omemcpy = nullptr;
float disstash = 1.5;
bool ficadeboa = false;
bool Torrentt = false;
bool predictionaim = 0;
bool predictionaim1 = 0;
bool predictionaim11 = 0;
bool predictionaim111 = 0;
bool coletartudo = false;
bool manipulator = false;
bool manipulate_vis = false;
//
#pragma code_seg(".text")
inline int64_t get_rbx_value()
{
	static __declspec(allocate(".text")) char fn_stub[] = {
		0x48,
		0x89,
		0xD8, // mov    rax,rbx
		0xc3 // ret
	};

	return ((int64_t(*)())(&fn_stub))();
}
typedef void(__stdcall* serverrpc_funcHK)(DWORD64, rust11::string);
static serverrpc_funcHK original_serverrpc = nullptr;
//

void __fastcall hkCreateProjectile(DWORD64 ecx, rust11::string prefab_path) {

	///
		//std::printf("ecx %llx \n RPC %s \n", ecx, prefab_path.zpad);


	return original_serverrpc(ecx, prefab_path);
}

typedef float(__stdcall* jectileV)(DWORD64, bool);
static jectileV original_GetProjectileVelocityScale = nullptr;
//
float __fastcall HKGetProjectileVelocityScale(DWORD64 ecx, bool prefab_path) {


	//std::printf("VelocityScale %llx  RPC %i \n", ecx, prefab_path);
	//std::printf("VelocityScale %f  \n", ecx, HKGetProjectileVelocityScale);

	if (GetAsyncKeyState(VK_NUMPAD0))
		return 2.f;
	if (GetAsyncKeyState('E'))
		return -1;
	return original_GetProjectileVelocityScale(ecx, prefab_path);
}

utils::maths::vec3_t screen_position1321;
BasePlayer* treeee = nullptr;
HMODULE mNvwf2;
bool RecoilControlSystem;
bool RecoilControlSystem1;
bool prediction1;
bool prediction2;
bool aim1;
bool aim11;
bool aim111 = true;
bool TestSentrygun;

bool init_swapchain_hook;
#define PI 3.14159265358979323846f
WNDPROC oriWndProc = NULL;
bool toggle_menu;
bool toggle_menu2;
bool TESTTTT = 1;
bool TESTTTT11 = 1;
bool sempreon = true;
float Tempo;
bool esp_bot;
bool esp_bot_snap;
bool esp_bot_healh;
using namespace SDK;
using namespace SDK::utils::maths;
int playerfov = 90;
int zoomfov = 30;
bool Setfov;
inline auto screen_transform(utils::maths::vec3_t wrld) -> utils::maths::vec3_t;
bool HotkeyButton(const char* label, int* key, const ImVec2& size_arg);
bool HotkeyButtonEx(const char* label, int* key, const ImVec2& size_arg, ImGuiButtonFlags flags);

void __stdcall resolve_module_info()
{
	variables::window_handle = FindWindowA(0, variables::window_class_name);

}
int aimkeyfarm = VK_CAPITAL;
int aimkey = VK_CAPITAL;
int aimkey4trigger = VK_CAPITAL;
int aimkey2;
int aimkeyManipulator = VK_CAPITAL;
int aimkeyall;
int aimkeyFood;
int aimkeyFoodStas;
int aimkeyberry;
int aimkeyEGG;
int aimkeyHemp;
int aimkeyHemp1 = VK_LSHIFT;

utils::maths::vec3_t position14;
float __fastcall hkGetDistanceScale(void* ecx) {

	return 0.f;
}
static int keystatus = 0;

void MenuDesignInterface()
{
	ImGuiStyle* style = &ImGui::GetStyle();

	style->WindowPadding = ImVec2(15, 15);
	style->WindowRounding = 5.0f;
	style->FramePadding = ImVec2(5, 5);
	style->FrameRounding = 4.0f;
	style->ItemSpacing = ImVec2(12, 8);
	style->ItemInnerSpacing = ImVec2(8, 6);
	style->IndentSpacing = 25.0f;
	style->ScrollbarSize = 15.0f;
	style->ScrollbarRounding = 9.0f;
	style->GrabMinSize = 5.0f;
	style->GrabRounding = 3.0f;

	style->Colors[ImGuiCol_Text] = ImVec4(0.80f, 0.80f, 0.83f, 1.00f);
	style->Colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	//style->Colors[ImGuiCol_ChildWindowBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	style->Colors[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	style->Colors[ImGuiCol_Border] = ImVec4(0.80f, 0.80f, 0.83f, 0.88f);
	style->Colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
	style->Colors[ImGuiCol_FrameBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_FrameBgActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_TitleBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 0.98f, 0.95f, 0.75f);
	style->Colors[ImGuiCol_TitleBgActive] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	style->Colors[ImGuiCol_MenuBarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	//style->Colors[ImGuiCol_ComboBg] = ImVec4(0.19f, 0.18f, 0.21f, 1.00f);
	style->Colors[ImGuiCol_CheckMark] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	style->Colors[ImGuiCol_SliderGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	style->Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style->Colors[ImGuiCol_Button] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_ButtonHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_ButtonActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_Header] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_HeaderHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_HeaderActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	//	style->Colors[ImGuiCol_Column] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	//	style->Colors[ImGuiCol_ColumnHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	//	style->Colors[ImGuiCol_ColumnActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style->Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	//		style->Colors[ImGuiCol_CloseButton] = ImVec4(0.40f, 0.39f, 0.38f, 0.16f);
		//	style->Colors[ImGuiCol_CloseButtonHovered] = ImVec4(0.40f, 0.39f, 0.38f, 0.39f);
		//	style->Colors[ImGuiCol_CloseButtonActive] = ImVec4(0.40f, 0.39f, 0.38f, 1.00f);
	style->Colors[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
	style->Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
	style->Colors[ImGuiCol_PlotHistogram] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
	style->Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
	style->Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.25f, 1.00f, 0.00f, 0.43f);
	//style->Colors[ImGuiCol_ModalWindowDarkening] = ImVec4(1.00f, 0.98f, 0.95f, 0.73f);


}
void Next()
{
	ImGui::Dummy(ImVec2(0, 0));
	ImGui::SameLine();
	ImGui::Dummy(ImVec2(0, 0));
	ImGui::SameLine();
}
void ChangeKey(void* blank);
void HotkeyButton(int aimkey, int aimkey2, void* changekey, int status);
namespace hotkeys
{
	int aimkey;
	int aimkey2;
	int airstuckey;
}
const char* listbox_items[] = { "Head", "neck", "torso", "stomach" };

bool HotkeyButton(const char* label, int* key, const ImVec2& size_arg);
bool HotkeyButtonEx(const char* label, int* key, const ImVec2& size_arg, ImGuiButtonFlags flags);
void BuildMenuMain()
{


	ImGui::SetNextWindowSize({ 500, 500 });
	float SpaceLineOne = 120.f;
	//
	ImGui::Begin(xorstr_("Apex Private"), &Globals::Open, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);
	{
		ImGui::Text(_(""));
		Next();
		ImGui::Checkbox(xorstr_("Enabled "), &Globals::Visuals::Enabled);	Next();
		ImGui::Checkbox(xorstr_("Show Items"), &Globals::Visuals::esp_item_glow);	Next();
		ImGui::Checkbox(xorstr_("Show info"), &Globals::Visuals::esp_player_glow);	Next();
		ImGui::Checkbox(xorstr_("Show Distance"), &Globals::Visuals::esp_player_Distance);	Next();
		/*ImGui::Checkbox(xorstr_("Show Spectator"), &Globals::Visuals::speclist);	Next();*/
		ImGui::Checkbox(xorstr_("Esp Box"), &Globals::Visuals::esp_player_box);

		if (Globals::Visuals::esp_player_box) {

			ImGui::Checkbox(xorstr_("stand box"), &Globals::Visuals::stand_box);
			ImGui::Checkbox(xorstr_("corner box"), &Globals::Visuals::corner_box);


		}


		Next();
		ImGui::Checkbox(xorstr_("Skelet"), &Globals::Visuals::esp_player_skeleton);	Next();
		ImGui::Spacing(); Next();
		/*ImGui::Checkbox(xorstr_("Trigger"), &Globals::Visuals::TriggetBot);	Next();
		ImGui::Spacing(); Next();
		ImGui::Text(xorstr_(" TriggerKey: "));
		HotkeyButton(xorstr_("press key Trigger"), &aimkey4trigger, ImVec2(50, 50));*/

		ImGui::Checkbox(xorstr_("Aimbot"), &Globals::Visuals::aimbot);	Next();
		ImGui::Checkbox(xorstr_("Hide team"), &Globals::Visuals::esp_hideteam);	Next();
		ImGui::SliderFloat(xorstr_("Distance"), &esp_max_distance, 0, 1000);	Next();
		//	ImGui::SliderInt(_("Boness"), &Globals::Visuals::bone_limiter, 0, 1000);	Next();
		//ImGui::SliderInt(_("Font Size"), &font_size, 10, 20);	Next();

		if (Globals::Visuals::aimbot) {

			ImGui::Combo(xorstr_("Bone List"), &Globals::Visuals::bone_choice, listbox_items, IM_ARRAYSIZE(listbox_items)); Next();



			if (Globals::Visuals::bone_choice == 0)
				Globals::Visuals::bone_choice2 = 8;

			if (Globals::Visuals::bone_choice == 1)
				Globals::Visuals::bone_choice2 = 5;

			if (Globals::Visuals::bone_choice == 2)
				Globals::Visuals::bone_choice2 = 15;

			if (Globals::Visuals::bone_choice == 3)
				Globals::Visuals::bone_choice2 = 3;




			ImGui::Text(xorstr_("Aim Key: ")); ImGui::SameLine(SpaceLineOne);
			HotkeyButton(xorstr_("press key"), &aimkey, ImVec2(50, 50));
			// Only when holding weapon
		//	ImGui::Text(_("Aim Key 2: ")); ImGui::SameLine(SpaceLineOne); 
		//	HotkeyButton(xorstr_("press key 2"), &aimkey2, ImVec2(50, 50));

			ImGui::Checkbox(xorstr_("Show Fov "), &Globals::Visuals::show_fov);	Next();
			ImGui::SliderFloat(xorstr_("Aimbot Fov"), &Globals::Visuals::fov_value, 0, 500);	Next();
			//ImGui::Checkbox(xorstr_("Cap Aimbot Distance"), &Globals::Visuals::cap_aimbot_distance);	Next();
		//	ImGui::Checkbox(_("Prediction test"), &Globals::Visuals::aimbot_predictiontest);	Next();
			ImGui::Checkbox(xorstr_("Prediction"), &Globals::Visuals::aimbot_prediction);	Next();
			//ImGui::Checkbox(_("only shooting"), &Globals::Visuals::aimbot_onlyshooting);	Next();
			ImGui::Checkbox(xorstr_("Visiblity check"), &Globals::Visuals::aimbot_visiblity_check);	Next();
			ImGui::Checkbox(xorstr_("RCS Aimbot"), &Globals::Visuals::rcs_aimbot);	Next();
			//ImGui::Checkbox(_("RCS standalone"), &Globals::Visuals::rcs_standalone);	Next();
			//ImGui::Checkbox(_("Aimbot Smooth"), &Globals::Visuals::aimbo_smoothing);	Next();
			ImGui::SliderInt(xorstr_("Smooth"), &Globals::Visuals::smooth_value, 1, 50);	Next();
			if (Globals::Visuals::smooth_value < 1)
				Globals::Visuals::smooth_value = 1;
		}

		ImGui::Spacing(); Next();
		Next(); Next();
		ImGui::Text(_(""));
	}
	ImGui::End();
}


extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);


long long CALLBACK hWndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplWin32_WndProcHandler(hwnd, uMsg, wParam, lParam) && toggle_menu == true)
	{
		return 1l;
	}

	return CallWindowProc(oriWndProc, hwnd, uMsg, wParam, lParam);
}


BasePlayer* resultant_target_entityfarm = nullptr;
std::vector<BasePlayer*> unity_entity_farm;
std::vector<BasePlayer*> unity_entity_STASH;
std::vector<BasePlayer*> valid_EGGS;
std::vector<BasePlayer*> valid_Coisas;
int toggleDebugcamera = 0;


class clr_t {
public:
	float r, g, b, a;
	clr_t(float _r, float _g, float _b, float _a) : r(_r / 255), g(_g / 255), b(_b / 255), a(_a / 255) {}
	clr_t(float _r, float _g, float _b) : r(_r / 255), g(_g / 255), b(_b / 255), a(1) {}

	static clr_t from_hsb(float hue, float saturation, float brightness) {
		float h = hue == 1.0f ? 0 : hue * 6.0f;
		float f = h - (int)h;
		float p = brightness * (1.0f - saturation);
		float q = brightness * (1.0f - saturation * f);
		float t = brightness * (1.0f - (saturation * (1.0f - f)));

		if (h < 1) {
			return clr_t((brightness * 255), (t * 255), (p * 255));
		}
		else if (h < 2) {
			return clr_t((q * 255), (brightness * 255), (p * 255));
		}
		else if (h < 3) {
			return clr_t((p * 255), (brightness * 255), (t * 255));
		}
		else if (h < 4) {
			return clr_t((p * 255), (q * 255), (brightness * 255));
		}
		else if (h < 5) {
			return clr_t((t * 255), (p * 255), (brightness * 255));
		}
		else {
			return clr_t((brightness * 255), (p * 255), (q * 255));
		}
	}
};
class c_visuals
{
public:
	auto run() -> void;

	struct shot_record_t
	{
		float m_time;
		utils::maths::vec3_t m_start, m_end;
		int m_damage;
	};

	std::vector< shot_record_t > m_shots;
private:
	std::uintptr_t client_entities, shader;
	std::uintptr_t client_entities1, shader1;
	struct box_t
	{
		vector2 pos;
		vector2 size;
	};

	auto chams(BasePlayer* player) -> void;
	auto hand_chams() -> void;
	auto draw_tracers() -> void;
	auto render_player(BasePlayer* player) -> void;
};

namespace visuals
{
	inline c_visuals object;
}

inline std::uintptr_t  camera = 0;
inline auto view_matrix() -> SDK::utils::maths::mat4x4_t
{
	SAPPHIRE_ICALL(get_main_camera_fn, "UnityEngine.Camera::get_main()", std::uintptr_t(*)());

	if (!camera) {
		camera = get_main_camera_fn();
	}

	auto camera_ = *reinterpret_cast<std::uintptr_t*>(camera + 0x10);
	if (!camera_) {
		return {};
	}

	auto matrix = *reinterpret_cast<SDK::utils::maths::mat4x4_t*>(camera_ + 0x2e4);
	if (!matrix.m) {
		return {};
	}

	return matrix;
}

SDK::utils::maths::vec3_t get_position()
{

	SAPPHIRE_ICALL(get_main_camera_fn, "UnityEngine.Camera::get_main()", std::uintptr_t(*)());

	if (!camera) {
		camera = get_main_camera_fn();
	}

	auto camera_ = *reinterpret_cast<std::uintptr_t*>(camera + 0x10);
	if (!camera_) {
		return {};
	}

	auto matrix = *reinterpret_cast<SDK::utils::maths::vec3_t*>(camera_ + 0x42C);


	return matrix;
}



class c_screen {
public:
	static auto get_width() -> int {
		SAPPHIRE_METHOD(get_screen_width_fn, "UnityEngine::Screen.get_width()", 0, "", -1, int (*)());
		return get_screen_width_fn();
	}

	static auto get_height() -> int {
		SAPPHIRE_METHOD(get_screen_height_fn, "UnityEngine::Screen.get_height()", 0, "", -1, int (*)());
		return get_screen_height_fn();
	}
};
inline auto screen_transform(utils::maths::vec3_t wrld) -> utils::maths::vec3_t
{
	auto matrix = view_matrix();

	if (!matrix.m) {
		return { 0,0,0 };
	}

	utils::maths::vec3_t out;
	const auto temp = matrix.transpose();

	auto trans = utils::maths::vec3_t{ temp[3][0], temp[3][1], temp[3][2] };
	auto up = utils::maths::vec3_t{ temp[1][0], temp[1][1], temp[1][2] };
	auto right = utils::maths::vec3_t{ temp[0][0], temp[0][1], temp[0][2] };

	float w = trans.Dot(wrld) + temp[3][3];

	if (w < 0.1f) {
		return utils::maths::vec3_t(0, 0, 0);
	}

	float x = right.Dot(wrld) + temp[0][3];
	float y = up.Dot(wrld) + temp[1][3];

	out.x = (static_cast<float>(c_screen::get_width()) / 2) * (1 + x / w);
	out.y = (static_cast<float>(c_screen::get_height()) / 2) * (1 - y / w);
	out.z = 0.0f;

	return out;
}
BasePlayer* local_player_ret = nullptr;
static const char* KeyNames[] = {
   "Press Key",
   "Left Mouse",
   "Right Mouse",
   "Cancel",
   "Middle Mouse",
   "X1 Mouse",
   "X2 Mouse",
   "Unknown",
   "Backspace",
   "Tab",
   "unknown",
   "unknown",
   "Clear",
   "Return",
   "unknown",
   "unknown",
   "Shift",
   "Control",
   "Menu",
   "Pause",
   "Caps Lock",
   "Kana",
   "unknown",
   "vk_junja",
   "vk_final",
   "vk_kanji",
   "unknown",
   "Escape",
   "Convert",
   "Nonconvert",
   "Accept",
   "Modechange",
   "Space",
   "Page Up",
   "Page Down",
   "End",
   "Home",
   "Left",
   "Up",
   "Right",
   "Down",
   "Select",
   "Print",
   "Execute",
   "Snapshot",
   "Insert",
   "Delete",
   "Help",
   "0",
   "1",
   "2",
   "3",
   "4",
   "5",
   "6",
   "7",
   "8",
   "9",
   "unknown",
   "unknown",
   "unknown",
   "unknown",
   "unknown",
   "unknown",
   "unknown",
   "a",
   "b",
   "c",
   "d",
   "e",
   "f",
   "g",
   "h",
   "i",
   "j",
   "k",
   "l",
   "m",
   "n",
   "o",
   "p",
   "q",
   "r",
   "s",
   "t",
   "u",
   "v",
   "w",
   "x",
   "y",
   "z",
   "Windows",
   "Windows",
   "Apps",
   "unknown",
   "Sleep",
   "Numpad 0",
   "Numpad 1",
   "Numpad 2",
   "Numpad 3",
   "Numpad 4",
   "Numpad 5",
   "Numpad 6",
   "Numpad 7",
   "Numpad 8",
   "Numpad 9",
   "Multiply",
   "Add",
   "Separator",
   "Subtract",
   "Decimal",
   "Divide",
   "F1",
   "F2",
   "F3",
   "F4",
   "F5",
   "F6",
   "F7",
   "F8",
   "F9",
   "F10",
   "F11",
   "F12",
   "F13",
   "F14",
   "F15",
   "F16",
   "F17",
   "F18",
   "F19",
   "F20",
   "F21",
   "F22",
   "F23",
   "F24",
   "unknown",
   "unknown",
   "unknown",
   "unknown",
   "unknown",
   "unknown",
   "unknown",
   "unknown",
   "Numlock",
   "Scroll",
   "vk_oem_nec_equal",
   "vk_oem_fj_masshou",
   "vk_oem_fj_touroku",
   "vk_oem_fj_loya",
   "vk_oem_fj_roya",
   "unknown",
   "unknown",
   "unknown",
   "unknown",
   "unknown",
   "unknown",
   "unknown",
   "unknown",
   "unknown",
   "Shift",
   "Shift",
   "Control",
   "Control",
   "Menu",
   "Menu"
};


bool KeyPressed(int* key)
{
	int i = 0;
	while (i < 256)
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) // Unsafe but works
		{
			return true;
		}
		if (GetAsyncKeyState(i) & 0x8000) // Unsafe but works
		{
			*key = i;
			return true;
		}
		i++;
	}
	return false;
}
bool KeyPressed1(int* key)
{
	int i = 0;
	while (i < 256)
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) // Unsafe but works
		{
			return true;
		}
		if (GetAsyncKeyState(i) & 0x8000) // Unsafe but works
		{
			*key = i;
			return true;
		}
		i++;
	}
	return false;
}

bool HotkeyButtonEx(const char* label, int* key, const ImVec2& size_arg, ImGuiButtonFlags flags)
{
	if (ImGui::Button(KeyNames[*key]))
	{
		while (true)
		{
			Sleep(1);
			if (!GetAsyncKeyState(VK_LBUTTON)) // fucking dumb way to wait until button is no longer pressed but it works. Fix soon.
				break;
		}
		*key = 0;
	}
	if (*key == 0)
		KeyPressed(key);
	return true;
}
bool HotkeyButtonEx1(const char* label, int* key, const ImVec2& size_arg, ImGuiButtonFlags flags)
{
	if (ImGui::Button(KeyNames[*key]))
	{
		while (true)
		{
			Sleep(1);
			if (!GetAsyncKeyState(VK_LBUTTON)) // fucking dumb way to wait until button is no longer pressed but it works. Fix soon.
				break;
		}
		*key = 0;
	}
	if (*key == 0)
		KeyPressed1(key);
	return true;
}
static bool Items_ArrayGetter(void* data, int idx, const char** out_text)
{
	const char* const* items = (const char* const*)data;
	if (out_text)
		*out_text = items[idx];
	return true;
}
static int realkey = 0;
bool GetKey(int key)
{
	realkey = key;
	return true;
}
void ChangeKey(void* blank)
{
	keystatus = 1;
	while (true)
	{
		for (int i = 0; i < 0x87; i++)
		{
			if (GetKeyState(i) & 0x8000)
			{
				aimkey = i;
				keystatus = 0;
				return;
			}
		}
	}
}
void HotkeyButton(int aimkey, int aimkey2, void* changekey, int status)
{
	const char* preview_value = NULL;
	if (aimkey >= 0 && aimkey < IM_ARRAYSIZE(KeyNames))
		Items_ArrayGetter(KeyNames, aimkey, &preview_value);

	std::string aimkeys;
	if (preview_value == NULL)
		aimkeys = "Select Key";
	else
		aimkeys = preview_value;

	if (status == 1)
	{
		aimkeys = "Press key to bind";
	}
	if (ImGui::Button(aimkeys.c_str(), ImVec2(125, 20)))
	{
		if (status == 0)
		{
			CreateThreadSafe(changekey);

		}
	}
}

bool HotkeyButton(const char* label, int* key, const ImVec2& size_arg)
{
	return HotkeyButtonEx(label, key, size_arg, 0);
}
bool HotkeyButton1(const char* label, int* key, const ImVec2& size_arg)
{
	return HotkeyButtonEx1(label, key, size_arg, 0);
}
enum e_player_flags : int {
	unused_1 = (1 << 0),
	unused_2 = (1 << 1),
	is_admin = (1 << 2),
	receiving_snapshot = (1 << 3),
	sleeping = (1 << 4),
	spectating = (1 << 5),
	wounded = (1 << 6),
	is_developer = (1 << 7),
	connected = (1 << 8),
	third_person_viewmode = (1 << 10),
	eyes_viewmode = (1 << 11),
	chat_mute = (1 << 12),
	no_sprint = (1 << 13),
	aiming = (1 << 14),
	display_sash = (1 << 15),
	relaxed = (1 << 16),
	safe_zone = (1 << 17),
	server_fall = (1 << 18),
	workbench_1 = (1 << 20),
	workbench_2 = (1 << 21),
	workbench_3 = (1 << 22),
};
__forceinline vector2 CalcAngle3(const utils::maths::vec3_t& Src, const utils::maths::vec3_t& Dst) {
#define M_PI 3.14159265358979323846f
#define M_PI_F ((float)(M_PI))
#define RAD2DEG(x) ((float)(x) * (float)(180.f / M_PI_F))
	utils::maths::vec3_t dir = Src - Dst;
	return vector2{ RAD2DEG(std::asin(dir.y / dir.length())), RAD2DEG(-std::atan2(dir.x, -dir.z)) };
}
utils::maths::vec3_t CalculateAngle(const utils::maths::vec3_t& src, const utils::maths::vec3_t& dst)
{
	utils::maths::vec3_t vAngle;
	utils::maths::vec3_t delta{ (src.x - dst.x), (src.y - dst.y), (src.z - dst.z) };
	double hyp = sqrt(delta.x * delta.x + delta.y * delta.y);

	vAngle.x = float(atanf(float(delta.z / hyp)) * 57.295779513082f);
	vAngle.y = float(atanf(float(delta.y / delta.x)) * 57.295779513082f);
	vAngle.z = 0.0f;

	if (delta.x >= 0.0)
		vAngle.y += 180.0f;

	//if (vAngle.y > 180.f) vAngle.y -= 360.f;
	//if (vAngle.y < -180.f) vAngle.y += 360.f;

	return vAngle;
}
void Normalize3322(float& Yaw, float& Pitch) {
	if (Pitch < -89) Pitch = -89;
	else if (Pitch > 89) Pitch = 89;
	if (Yaw < -360) Yaw += 360;
	else if (Yaw > 360) Yaw -= 360;
}

#define RAD2DEG(x) ((float)(x) * (float)(180.f / M_PI_F))
__forceinline utils::maths::vec2_t  CalcAngle2(const utils::maths::vec3_t& Src, const utils::maths::vec3_t& Dst) {
	utils::maths::vec3_t dir = Src - Dst;
	float length = dir.Length();
	return utils::maths::vec2_t{ RAD2DEG(asin(dir.y / length)), RAD2DEG(-atan2(dir.x, -dir.z)) };
}

utils::maths::vec3_t CalculateAngle44(const utils::maths::vec3_t& src, const utils::maths::vec3_t& dst)
{
	utils::maths::vec3_t vAngle;
	utils::maths::vec3_t delta{ (src.x - dst.x), (src.y - dst.y), (src.z - dst.z) };
	double hyp = sqrt(delta.x * delta.x + delta.y * delta.y);

	vAngle.x = float(atanf(float(delta.z / hyp)) * 57.295779513082f);
	vAngle.y = float(atanf(float(delta.y / delta.x)) * 57.295779513082f);
	vAngle.z = 0.0f;

	if (delta.x >= 0.0)
		vAngle.y += 180.0f;

	//if (vAngle.y > 180.f) vAngle.y -= 360.f;
	//if (vAngle.y < -180.f) vAngle.y += 360.f;

	return vAngle;
}

void Normalize21(float& Yaw, float& Pitch) {
	if (Pitch < -89) Pitch = -89;
	else if (Pitch > 89) Pitch = 89;
	if (Yaw < -360) Yaw += 360;
	else if (Yaw > 360) Yaw -= 360;
}
#define powFFFFFFFFFFFFFFFFFFFFFF(n) (n)*(n)

__forceinline float Distance3D(const utils::maths::vec3_t& Src, const utils::maths::vec3_t& Dst)
{
	return std::sqrt(powFFFFFFFFFFFFFFFFFFFFFF((Src.x - Dst.x), 2) + powFFFFFFFFFFFFFFFFFFFFFF((Src.y - Dst.y), 2) + powFFFFFFFFFFFFFFFFFFFFFF((Src.z - Dst.z), 2));
}

vector2 NormalizeAngles(vector2 angle)
{
	while (angle.x > 89.0f)
		angle.x -= 180.f;

	while (angle.x < -89.0f)
		angle.x += 180.f;

	while (angle.y > 180.f)
		angle.y -= 360.f;

	while (angle.y < -180.f)
		angle.y += 360.f;

	return angle;
}


float GetFov(vector2 viewAngle, vector2 aimAngle)
{
	vector2 delta = aimAngle - viewAngle;
	delta = NormalizeAngles(delta);
	return sqrt(pow(delta.x, 2.0f) + pow(delta.y, 2.0f));
}

utils::maths::vec3_t CalcAngle(utils::maths::vec3_t viewAngle, utils::maths::vec3_t aimPos)
{
	utils::maths::vec3_t angle = { 0, 0, 0 };

	utils::maths::vec3_t delta = aimPos - viewAngle;

	angle.x = -asin(delta.z / delta.Size()) * (180.0f / PI); // pitch
	angle.y = atan2(delta.y, delta.x) * (180.0f / PI);       // yaw

	return angle;

}
vec3_t calculate_angle1(const vec3_t& src, const vec3_t& dst) {
	const auto direction = src - dst;

	return { std::asin(direction.y / direction.length()) * 57.2957795131f, -std::atan2(direction.x, -direction.z) * 57.2957795131f, 0.f };
}

namespace rust {
	class list {
	public:
		template <typename T>
		T get_value() {
			auto list = *reinterpret_cast<uintptr_t*>(this + 0x10);
			if (!list)
				return 0;

			auto value = *reinterpret_cast<T*>(list + 0x28);
			if (!value)
				return 0;
			return value;
		}

		int get_size() {
			auto value = get_value<uintptr_t>();
			if (!value)
				return 0;

			auto size = readf1<int>(value + 0x10);
			if (!size)
				return 0;
		}

		template <typename T>
		T get_buffer() {
			auto value = get_value<uintptr_t>();

			return *reinterpret_cast<uintptr_t*>(value + 0x18);
		}
	};
}
#define powww(a)	(a) * (a)
struct rust_str
{
	char zpad[128];
};

bool podes = false;
bool podes1 = false;


void MainThe() {


	while (true)
	{


		if (podes) {
			Sleep(300);

		}

		if (coletartudo) {
			Sleep(300);
		}


		Sleep(100);
	}





}

float ColorWeapon[] = { 0.45f, 0.55f, 0.60f, 1.00f };
float ColorAmmunition[] = { 0.45f, 0.55f, 0.60f, 1.00f };
float ColorAttire[] = { 0.45f, 0.55f, 0.60f, 1.00f };
float ColorComponent[] = { 0.45f, 0.55f, 0.60f, 1.00f };
float ColorFood[] = { 0.45f, 0.55f, 0.60f, 1.00f };
float ColorTool[] = { 0.45f, 0.55f, 0.60f, 1.00f };
float ColorMedical[] = { 0.45f, 0.55f, 0.60f, 1.00f };



bool onecee = false;

bool onecee1 = false;
uint64_t valBase;
void DrawCircle1(const DirectX::XMFLOAT2& from, float radius, DirectX::XMFLOAT4 color, float thickness)
{
	ImDrawList* window = ImGui::GetBackgroundDrawList();

	window->AddCircle(ImVec2(from.x, from.y), radius, ImGui::GetColorU32(ImVec4(color.x / 255, color.y / 255, color.z / 255, color.w / 255)), 180, thickness);
}
namespace SDK1
{
#define MAX_PLAYER_COUNT 128
#define MAX_ENTITY_OBJ_COUNT 50000


	template<typename t>
	t Read(uintptr_t addr) {
		if (addr < 0xfffff)
			return t();
		if (addr > 0x7FFFFFFFFFFF)
			return t();

		return *reinterpret_cast<t*>(addr);
	}



	namespace functions
	{

	}
	enum cBoneId : std::uint32_t
	{
		head = 8,
		neck = 7,
		torso = 15,
		l_shoulder = 11,
		r_shoulder = 35,
		l_elbow = 13,
		r_elbow = 37,
		l_hand = 15,
		r_hand = 39,
		stomach = 3,
		lower_stomach = 0,
		l_hip = 57,
		r_hip = 62,
		l_knee = 58,
		r_knee = 63,
		l_foot = 65,
		r_foot = 60
	};

	/*enum cBoneId : std::uint32_t
	{
		head = 8,
		neck = 5,
		torso = 15,
		l_shoulder = 18,
		r_shoulder = 50,
		l_elbow = 20,
		r_elbow = 53,
		l_hand = 15,
		r_hand = 39,
		stomach = 2,
		lower_stomach = 0,
		l_hip = 57,
		r_hip = 62,
		l_knee = 58,
		r_knee = 63,
		l_foot = 60,
		r_foot = 65*/

	struct glow_mode
	{
		BYTE GeneralGlowMode, BorderGlowMode, BorderSize, TransparentLevel;
	};

	struct CGlobalVars {
		/*0x00*/double realtime;
		/*0x08*/int32_t framecount;
		/*0x0c*/float absoluteframetime;
		/*0x10*/float curtime;
		/*0x14*/float curtime2;
		/*0x18*/float curtime3;
		/*0x1c*/float curtime4;
		/*0x20*/float frametime;
		/*0x24*/float curtime5;
		/*0x28*/float curtime6;
		/*0x2c*/float zero;
		/*0x30*/float frametime2;
		/*0x34*/int32_t maxClients;
		/*0x38*/int32_t unk38;
		/*0x3c*/int32_t unk3C;
		/*0x40*/int32_t tickcount;
		/*0x44*/float interval_per_tick;
		/*0x48*/float interpolation_amount;
	};
	namespace offsets
	{
		// START OFFSET
		static   auto global_vars = 0x17c5c20; // GlobalVars
		static   auto entity_list_off = 0x1eaacc8; //[ConVars].gamepad_aim_assist_melee updated 2024/05/03 # [Miscellaneous].cl_entitylist
		static   auto entity_name_list = 0xc790230; //NameList
		static   auto entity_user_cmd = 0x0;
		static   auto set_fov_scale = 0x0;

		// Camera Information
		static   auto view_renderer = 0x74dbfa8; //ViewRender
		static   auto view_matrix = 0x11a350;  //ViewMatrix
		static   auto camera_position = 0x1ed0; //CPlayer!camera_origin
		static   auto aim_punch = 0x2438; //m_currentFrameLocalPlayer.m_vecPunchWeapon_Angle
		static   auto view_angles1 = 0x2534 - 0x14 /*0x2574 - 0x14*/; //m_ammoPoolCapacity - 0x14
		static   auto OFFSET_BREATH_ANGLES = view_angles1 - 0x10 /*0x2574 - 0x14*/; //m_ammoPoolCapacity - 0x14

		// Entity Information
		static   auto entity_origin = 0x017c; //m_vecAbsOrigin
		static   auto entity_health = 0x0318; // m_iHealth
		static   auto entity_maxhealth = 0x0460; // m_iMaxHealth
		static   auto entity_shield = 0x01a0; // m_shieldHealth
		static   auto entity_maxshield = 0x01a4; // m_shieldHealthMax
		static   auto entity_team = 0x0328; // m_iTeamNum 
		static   auto entity_velocity = 0x0170; // m_vecAbsVelocity
		static   auto entity_lifestate = 0x0680; // m_lifeState
		static   auto entity_bleedoutstate = 0x26e0; // m_bleedoutState
		static   auto entity_bonetransform = 0x0da0 + 0x48; //m_nForceBone + 0x48 0x0f50
		static   auto entity_currentweapon = 0x1934; //m_latestPrimaryWeapons
		static   auto entity_objname = 0x0468; //m_iSignifierName
		static   auto entity_name_index = 0x038;
		static   auto entity_item_id = 0x1558; //m_customScriptInt
		static   auto entityiname_id = 0x1524; //0x1524
		static   auto entity_lastvisibletime = 0x1990; // CPlayer!lastVisibleTime=
		static   auto entity_studiohdr = 0xff0; // CBaseAnimating!m_pStudioHdr

		// Glow
		static   auto entity_glow_enable = 0x3c8;
		static   auto entity_glow_time = 0x3A4;
		static   auto entity_glow_context = 0x3C8;
		static   auto entity_glow_distance = 0x3B4;
		static   auto entity_glow_type = 0x03d0;
		static   auto entity_glow_visible_type = 0x3d0;
		static   auto entity_glow_fade = 0x388;

		// Weapon Information
		static   auto wep_projectilespeed = 0x1ea4; // m_flProjectileSpeed
		static   auto wep_projectilegravity = 0x1eac + 8; // m_flProjectileScale
		static   auto wep_m_ammoInClip = 0x1554; // m_ammoInClip


		// END OFFSET
#define GLOW_FADE 0x388
#define GLOW_DISTANCE 0x3B4
#define GLOW_CONTEXT 0x298
#define GLOW_LIFE_TIME 0x3A4
#define GLOW_VISIBLE_TYPE 0x278
#define GLOW_TYPE 0x2C0
#define GLOW_COLOR 0x1D0
#define GLOW_COLOR2 0x1D4 // GLOW_COLOR + 0x4
#define GLOW_COLOR3 0x1D8 // GLOW_COLOR + 0x8


#define OFFSET_GLOW_T1              0x262 //16256 = enabled, 0 = disabled 
#define OFFSET_GLOW_T2              0x2dc //1193322764 = enabled, 0 = disabled 
#define OFFSET_GLOW_ENABLE          0x3c8 //7 = enabled, 2 = disabled

#define OFFSET_GLOW_THROUGH_WALLS   0x3d0 //2 = enabled, 5 = disabled
		//inline uintptr_t glow_lifetime = 0x0380; // + 36 // m_highlightServerFadeEndTimes  
		//inline uintptr_t glow_distance = 0x0380; // +52 // m_highlightServerFadeEndTimes  
		//inline uintptr_t glow_visibletype = 0x0318; // + 12 // m_highlightTeamBits 
		//inline uintptr_t glow_fade = 0x388; // +8 // m_highlightServerFadeEndTimes
	}
	__forceinline float screen_distance_from_center__(utils::maths::vec2_t Position)
	{
		ImGuiIO& io = ImGui::GetIO();

		return sqrt(pow(abs(Position.x - (io.DisplaySize.x / 2)), 2) + pow(abs(Position.y - (io.DisplaySize.y / 2)), 2));
	}

	bool WorldToScreen(D3DMATRIX ViewMatrix, Vector3 Position, Vector3& Output)
	{
		ImGuiIO& io = ImGui::GetIO();

		Vector3 vTransformed;

		vTransformed.x = (float)(Position.y * ViewMatrix.m[0][1]) + (float)(Position.x * ViewMatrix.m[0][0]) + (float)(Position.z * ViewMatrix.m[0][2]) + ViewMatrix.m[0][3];
		vTransformed.y = (float)(Position.y * ViewMatrix.m[1][1]) + (float)(Position.x * ViewMatrix.m[1][0]) + (float)(Position.z * ViewMatrix.m[1][2]) + ViewMatrix.m[1][3];
		vTransformed.z = (float)(Position.y * ViewMatrix.m[3][1]) + (float)(Position.x * ViewMatrix.m[3][0]) + (float)(Position.z * ViewMatrix.m[3][2]) + ViewMatrix.m[3][3];

		if (vTransformed.z < 0.001f)
			return false;

		vTransformed.x *= 1.0 / vTransformed.z;
		vTransformed.y *= 1.0 / vTransformed.z;

		const int width = io.DisplaySize.x;
		const int height = io.DisplaySize.y;

		Output.x = width / 2.0f + vTransformed.x * (width / 2.0f);
		Output.y = height / 2.0f - vTransformed.y * (height / 2.0f);

		return true;
	}

	void NormalizeAngles(Vector3* angles)
	{
		if (!std::isfinite(angles->x) || !std::isfinite(angles->y))
		{
			*angles = Vector3(0, 0, 0);
			return;
		}

		angles->x = std::clamp(angles->x, -89.9999f, 89.9999f);
		angles->y = std::remainderf(angles->y, 360.0f);
		angles->z = 0.0f;
	}


	Vector3 CalcAngle(const Vector3 src, const Vector3 dst)
	{
		Vector3 result = Vector3();

		Vector3 relative = src - dst;
		float magnitude = sqrtf(powf(relative.x, 2) + powf(relative.y, 2));
		float yawAngle = RAD2DEG(std::atanf(relative.y / relative.x));

		result.x = RAD2DEG(std::atanf(relative.z / magnitude));
		result.y = (relative.x) > 0 ? yawAngle + 180.f : yawAngle;
		result.z = 0.f;

		NormalizeAngles(&result);

		return result;
	}
	//Vector3 calculate_angle1(const Vector3& src, const Vector3& dst) {
	//	const auto direction = src - dst;

	//	return { std::asin(direction.y / direction.length()) * 57.2957795131f, -std::atan2(direction.x, -direction.z) * 57.2957795131f, 0.f };
	//}

	__forceinline utils::maths::vec2_t  CalcAngle2(const Vector3& Src, const Vector3& Dst) {
		Vector3 dir = Src - Dst;
		float length = dir.Length();
		return utils::maths::vec2_t{ RAD2DEG(asin(dir.y / length)), RAD2DEG(-atan2(dir.x, -dir.z)) };
	}
#define M_PI		3.14159265358979323846	// matches value in gcc v2 math.h
	struct SVector
	{
		float x;
		float y;
		float z;
		SVector(float x1, float y1, float z1)
		{
			x = x1;
			y = y1;
			z = z1;
		}
	};
	Vector3 CalcAnglen(const Vector3& src, const Vector3& dst)
	{
		Vector3 angle = Vector3();
		SVector delta = SVector((src.x - dst.x), (src.y - dst.y), (src.z - dst.z));

		double hyp = sqrt(delta.x * delta.x + delta.y * delta.y);

		angle.x = atan(delta.z / hyp) * (180.0f / M_PI);
		angle.y = atan(delta.y / delta.x) * (180.0f / M_PI);
		angle.z = 0;
		if (delta.x >= 0.0) angle.y += 180.0f;

		return angle;
	}
	Vector3 CalculateAngle(const Vector3& src, const Vector3& dst)
	{
		Vector3 vAngle;
		Vector3 delta{ (src.x - dst.x), (src.y - dst.y), (src.z - dst.z) };
		double hyp = sqrt(delta.x * delta.x + delta.y * delta.y);

		vAngle.x = float(atanf(float(delta.z / hyp)) * 57.295779513082f);
		vAngle.y = float(atanf(float(delta.y / delta.x)) * 57.295779513082f);
		vAngle.z = 0.0f;

		if (delta.x >= 0.0)
			vAngle.y += 180.0f;

		//if (vAngle.y > 180.f) vAngle.y -= 360.f;
		//if (vAngle.y < -180.f) vAngle.y += 360.f;

		return vAngle;
	}
	Vector3 CalculateAngle1(const Vector3& src, const Vector3& dst) {
		const auto direction = src - dst;

		return { std::asin(direction.y / direction.length()) * 57.2957795131f, -std::atan2(direction.x, -direction.z) * 57.2957795131f, 0.f };
	}

	struct EHandle
	{
		uint32_t value = 0xffffffff;

		inline bool is_valid() const { return value != 0xffffffff; }
		inline size_t index() const { return (value & 0xffff) << 5; }
	};

	class cViewMatrix
	{
	public:
		D3DMATRIX GetViewMatrix()
		{
			return Read<D3DMATRIX>(reinterpret_cast<std::uintptr_t>(this));
		}
	};

	class cViewRenderer
	{
	public:
		cViewMatrix* GetViewMatrixPtr()
		{
			return Read<cViewMatrix*>(reinterpret_cast<std::uintptr_t>(this) + offsets::view_matrix);
		}

		Vector3 GetCameraPosition()
		{
			return Read<Vector3>(reinterpret_cast<std::uintptr_t>(this) + offsets::camera_position);
		}
	};

	class cNameMap
	{
	public:
		const char* GetNameByIndex(std::uintptr_t index)
		{
			return Read<const char*>(reinterpret_cast<std::uintptr_t>(this) + ((index - 1) * 24)); // offset need be changed
		}
	};
	template <typename T = void*>
	inline auto IsValidPtr(T ptr) -> bool {
		return (ptr && ptr > (T)0xFFFFF && ptr < (T)0x7FFFFFFFFFFF);
	}
	class cEntity
	{
	public:
		void start_glowing(int i);
		void stop_glowing();
		const char* GetObjName()
		{

			auto name_ptr = Read<const char*>(reinterpret_cast<std::uintptr_t>(this) + offsets::entity_objname);
			if (!IsValidPtr((void*)name_ptr))
				return "";

			return name_ptr;

			//if (!IsValidPtr((void*)name_ptr))
			//	return nullptr;

			//return Read<const char*>(name_ptr);
		}

		bool IsPlayer()
		{
			const auto obj_name = Read<const char*>(reinterpret_cast<std::uintptr_t>(this) + offsets::entity_objname);

			if (!IsValidPtr((void*)obj_name))
				return false;

			return (std::string(obj_name) == _("player"));
		}

		int GetBleedOutStatus()
		{
			return Read<int>(reinterpret_cast<std::uintptr_t>(this) + offsets::entity_bleedoutstate);
		}

		int GetLifeState()
		{
			return Read<int>(reinterpret_cast<std::uintptr_t>(this) + offsets::entity_lifestate);
		}

		int GetTeamId()
		{
			return Read<int>(reinterpret_cast<std::uintptr_t>(this) + offsets::entity_team);
		}

		int GetHealth()
		{
			return Read<int>(reinterpret_cast<std::uintptr_t>(this) + offsets::entity_health);
		}

		int GetMaxHealth()
		{
			return Read<int>(reinterpret_cast<std::uintptr_t>(this) + offsets::entity_maxhealth);
		}

		int GetShield()
		{
			return Read<int>(reinterpret_cast<std::uintptr_t>(this) + offsets::entity_shield);
		}

		int GetMaxShield()
		{
			return Read<int>(reinterpret_cast<std::uintptr_t>(this) + offsets::entity_maxshield);
		}

		Vector3 GetVelocity()
		{
			return Read<Vector3>(reinterpret_cast<std::uintptr_t>(this) + offsets::entity_velocity);
		}

		bool IsAlive()
		{
			return this->GetBleedOutStatus() == 0 && this->GetLifeState() == 0;
		}

		bool IsValidEntity()
		{
			if (!this->IsPlayer() || !this->IsAlive())
				return false;

			auto entity_health = this->GetHealth();
			auto entity_team = this->GetTeamId();

			if (entity_health < 0 || entity_health > 100 || entity_team < 0 || entity_team > 32)
				return false;

			return true;
		}

		bool IsFriendly(class cEntity* LocalPlayer)
		{
			return (this->GetTeamId() == LocalPlayer->GetTeamId());
		}

		const char* GetPlayerName(class cNameMap* name_list)
		{
		std:uintptr_t name_index =
			Read<std::uintptr_t>(reinterpret_cast<std::uintptr_t>(this) + offsets::entity_name_index);

		return name_list->GetNameByIndex(name_index);
		}

		std::uintptr_t GetBoneArray()
		{
			return Read<std::uintptr_t>(reinterpret_cast<std::uintptr_t>(this) + offsets::entity_bonetransform);
		}

		Vector3 GetOrigin()
		{
			return Read<Vector3>(reinterpret_cast<std::uintptr_t>(this) + offsets::entity_origin);
		}

		int GetHitboxBoneIndex(int HitboxId)
		{
			const auto studio_model = Read<std::uintptr_t>(reinterpret_cast<std::uintptr_t>(this) + offsets::entity_studiohdr);

			if (!IsValidPtr((void*)studio_model))
				return -1;

			const auto studio_hdr = Read<std::uintptr_t>(studio_model + 0x8);

			if (!IsValidPtr((void*)studio_hdr))
				return -1;

			const auto hitbox_set = Read<uint16_t>(studio_hdr + 0xB4);

			if (!hitbox_set)
				return -1;

			const auto hitbox_array = studio_hdr + hitbox_set;

			int bone_index = Read<int>(hitbox_array + Read<int>(hitbox_array + 0x8) + (HitboxId * 0x2C));

			return ((bone_index < 0) || (bone_index > 255)) ? -1 : bone_index;
		}

		Vector3 base_position()
		{
			return *(Vector3*)(this + offsets::entity_origin);
		}
		typedef struct bone_t
		{
			uint8_t pad1[0xCC];
			float x;
			uint8_t pad2[0xC];
			float y;
			uint8_t pad3[0xC];
			float z;
		}bone_t;


		Vector3 GetBonePositionById(int id)
		{
			Vector3 position = base_position();

			uintptr_t boneArray = *(uintptr_t*)(this + offsets::entity_bonetransform);

			if (!IsValidPtr((void*)boneArray))
				return Vector3();

			Vector3 bone = Vector3();
			uint32_t boneloc = (id * 0x30);


			bone_t bo = Read<bone_t>(boneArray + boneloc);

			bone.x = bo.x + position.x;
			bone.y = bo.y + position.y;
			bone.z = bo.z + position.z;

			return bone;
		}


		void EnableBloodHunt(Vector3 colour)
		{
			auto org_glowmode = Read<glow_mode>(reinterpret_cast<std::uintptr_t>(this) + offsets::entity_glow_type);

			if (org_glowmode.GeneralGlowMode > (BYTE)255 || org_glowmode.GeneralGlowMode < (BYTE)0)
				return;

			if (org_glowmode.BorderGlowMode > (BYTE)255 || org_glowmode.BorderGlowMode < (BYTE)0)
				return;

			if (org_glowmode.BorderSize > (BYTE)255 || org_glowmode.BorderSize < (BYTE)0)
				return;

			if (org_glowmode.TransparentLevel > (BYTE)255 || org_glowmode.TransparentLevel < (BYTE)0)
				return;

			auto enable = Read<BYTE>(reinterpret_cast<std::uintptr_t>(this) + offsets::entity_glow_enable);
			auto context = Read<BYTE>(reinterpret_cast<std::uintptr_t>(this) + offsets::entity_glow_context);

			if (enable < (BYTE)0 || enable >(BYTE)255)
				return;

			if (context < (BYTE)0 || context >(BYTE)255)
				return;
			BYTE  test = 2; BYTE  test1 = 7;
			*(BYTE*)(reinterpret_cast<std::uintptr_t>(this) + offsets::entity_glow_context) = test1;
			*(BYTE*)(reinterpret_cast<std::uintptr_t>(this) + offsets::entity_glow_context) = test;


		}


		bool ModifyGlowType(glow_mode value)
		{
			auto org_glowmode = Read<glow_mode>(reinterpret_cast<std::uintptr_t>(this) + offsets::entity_glow_type);

			if (org_glowmode.GeneralGlowMode > (BYTE)255 || org_glowmode.GeneralGlowMode < (BYTE)0)
				return false;

			if (org_glowmode.BorderGlowMode > (BYTE)255 || org_glowmode.BorderGlowMode < (BYTE)0)
				return false;

			if (org_glowmode.BorderSize > (BYTE)255 || org_glowmode.BorderSize < (BYTE)0)
				return false;

			if (org_glowmode.TransparentLevel > (BYTE)255 || org_glowmode.TransparentLevel < (BYTE)0)
				return false;

			if (value.GeneralGlowMode == (BYTE)146)
				value.TransparentLevel = 1;
			*(glow_mode*)(reinterpret_cast<std::uintptr_t>(this) + offsets::entity_glow_type) = value;


			return true;
		}

		bool IsPlayerVisible()
		{
			float cur_time = Read<float>(valBase + offsets::global_vars + 0x10); //curTime

			float visible_time = Read<float>(reinterpret_cast<std::uintptr_t>(this) + offsets::entity_lastvisibletime);

			return visible_time > 0.0f && fabsf(visible_time - cur_time) < 0.1f;
		}
	};

	class cItem : public cEntity
	{
	public:

		enum eItemType
		{
			Weapon,
			Heal,
			Equipment,
			Grenade,
			Attachement,
			Trash
		};

		int GetItemId()
		{
			return Read<int>(reinterpret_cast<std::uintptr_t>(this) + offsets::entity_item_id);
		}

		__forceinline const char* GetLootName1(int LootID, eItemType* LootType, int* LootLevel)
		{
			switch (LootID)

			{
			case 1: *LootType = Weapon; return xorstr_("Kraber");
			case 7: *LootType = Weapon; return xorstr_("L-Star");
			case 12: *LootType = Weapon; return xorstr_("Havoc");
			case 17: *LootType = Weapon; return xorstr_("Devotion");
			case 22: *LootType = Weapon; return xorstr_("TrippleTake");
			case 27:*LootType = Weapon; return xorstr_("Flatline");
			case 32:*LootType = Weapon; return xorstr_("Hemlock");
			case 37: *LootType = Weapon; return xorstr_("G7-Scout");
			case 42: *LootType = Weapon; return xorstr_("Alternator");
			case 47:*LootType = Weapon; return xorstr_("R-99");
			case 52:*LootType = Weapon; return xorstr_("Prowler");
			case 57: *LootType = Weapon; return xorstr_("Volt");
			case 62:  *LootType = Weapon; return xorstr_("Longbow");
			case 67:  *LootType = Weapon; return xorstr_("ChargeRifle");
			case 72: *LootType = Weapon; return xorstr_("Spitfire");
			case 77: *LootType = Weapon; return xorstr_("R-301");
			case 97: *LootType = Weapon; return xorstr_("Wingman");
			case 102: *LootType = Weapon; return xorstr_("P-2020");
			case 107: *LootType = Weapon; return xorstr_("RE-45");
			case 108: *LootType = Weapon; return xorstr_("Sentinel");
			case 113: *LootType = Weapon; return xorstr_("Bocek");
			case 115: *LootType = Weapon; return xorstr_("Repeater");
			case 127: *LootType = Weapon; return xorstr_("Rampage");
			case 128: *LootType = Weapon; return xorstr_("C.A.R.");


			case 208:*LootType = Weapon; return xorstr_("Mag Light 1");
			case 209:*LootType = Weapon; return xorstr_("Mag Light 2");
			case 210:*LootType = Weapon; return xorstr_("Mag Light 3");
			case 211:*LootType = Weapon; return xorstr_("Mag Light 4");

			case 216: *LootType = Weapon; return xorstr_("Energy Magazine 1");
			case 217: *LootType = Weapon; return xorstr_("Energy Magazine 2");
			case 218: *LootType = Weapon; return xorstr_("Energy Magazine 3");
			case 219: *LootType = Weapon; return xorstr_("Energy Magazine 4");


			case 212:*LootType = Weapon; return xorstr_("Heavy Magazine 1");
			case 213:*LootType = Weapon; return xorstr_("Heavy Magazine 2");
			case 214:*LootType = Weapon; return xorstr_("Heavy Magazine 3");
			case 215:*LootType = Weapon; return xorstr_("Heavy Magazine 4");

			case 125:   *LootType = Weapon; return xorstr_("Sniper");
			case 129:  *LootType = Weapon; return xorstr_("Arrows");

			case 159: *LootType = Heal; *LootLevel = 2; return xorstr_("Accelerant");
			case 160: *LootType = Heal; *LootLevel = 3; return xorstr_("Phoenix");
			case 161: *LootType = Heal; *LootLevel = 2; return xorstr_("Medkit");
			case 162: *LootType = Heal; *LootLevel = 1; return xorstr_("Syringe");
			case 163: *LootType = Heal; *LootLevel = 2; return xorstr_("Battery");
			case 164: *LootType = Heal; *LootLevel = 1; return xorstr_("Cell");

			case 165: *LootType = Equipment; *LootLevel = 1; return xorstr_("Helmet 1");
			case 166: *LootType = Equipment; *LootLevel = 2; return xorstr_("Helmet 2");
			case 167: *LootType = Equipment; *LootLevel = 3; return xorstr_("Helmet 3");
			case 168: *LootType = Equipment; *LootLevel = 4; return xorstr_("Helmet 4");


			case 169: *LootType = Equipment; *LootLevel = 1; return xorstr_("Shield");
			case 170: *LootType = Equipment; *LootLevel = 2; return xorstr_("Shield");
			case 172: *LootType = Equipment; *LootLevel = 3; return xorstr_("Shield");
			case 183: *LootType = Equipment; *LootLevel = 4; return xorstr_("Shield");

			case 184: *LootType = Equipment; *LootLevel = 1; return xorstr_("Backpack");
			case 185: *LootType = Equipment; *LootLevel = 2; return xorstr_("Backpack");
			case 186: *LootType = Equipment; *LootLevel = 3; return xorstr_("Backpack");
			case 187: *LootType = Equipment; *LootLevel = 4; return xorstr_("Backpack");

			case 188: *LootType = Grenade; return xorstr_("Molotov");
			case 189: *LootType = Grenade; return xorstr_("Grenade");
			case 190: *LootType = Grenade; return xorstr_("ArcStar");

			case 191: *LootType = Attachement; *LootLevel = 1; return xorstr_("1x HCOG");
			case 192: *LootType = Attachement; *LootLevel = 2; return xorstr_("2x HCOG");
			case 193: *LootType = Attachement; *LootLevel = 1; return xorstr_("1x Holo");
			case 194: *LootType = Attachement; *LootLevel = 2; return xorstr_("2x Holo");
			case 195: *LootType = Attachement; *LootLevel = 4; return xorstr_("1x Digital");
			case 196: *LootType = Attachement; *LootLevel = 3; return xorstr_("3x HCOG");
			case 197: *LootType = Attachement; *LootLevel = 3; return xorstr_("4x Holo");
			case 198: *LootType = Attachement; *LootLevel = 2; return xorstr_("6x Sniper");
			case 199: *LootType = Attachement; *LootLevel = 3; return xorstr_("8x Sniper");
			case 200: *LootType = Attachement; *LootLevel = 4; return xorstr_("10x Sniper");

			case 201: *LootType = Attachement; *LootLevel = 1; return xorstr_("Barrel");
			case 202: *LootType = Attachement; *LootLevel = 2; return xorstr_("Barrel");
			case 203: *LootType = Attachement; *LootLevel = 3; return xorstr_("Barrel");
			case 204: *LootType = Attachement; *LootLevel = 3; return xorstr_("Barrel");
			case 205: *LootType = Attachement; *LootLevel = 1; return xorstr_("LightMag");
			case 206: *LootType = Attachement; *LootLevel = 2; return xorstr_("LightMag");
			case 207: *LootType = Attachement; *LootLevel = 3; return xorstr_("LightMag");

			case 220: *LootType = Attachement; *LootLevel = 4; return xorstr_("SniperMag");



			default: *LootType = Trash; *LootLevel = 1; return xorstr_("");
			}
		}
		__forceinline const char* GetLootName(int LootID, eItemType* LootType, int* LootLevel)
		{
			switch (LootID)
			{
			case 1: *LootType = Weapon; return xorstr_("Kraber");
			case 8: *LootType = Weapon; return xorstr_("L-Star");
			case 13: *LootType = Weapon; return xorstr_("Havoc RIFLE");
			case 18: *LootType = Weapon; return xorstr_("Devotion LMG");
			case 23: *LootType = Weapon; return xorstr_("Tripple TAKE");
			case 28:*LootType = Weapon; return xorstr_("VK-47 Flatline");
			case 33:*LootType = Weapon; return xorstr_("Hemlock");
			case 39: *LootType = Weapon; return xorstr_("G7-Scout");
			case 44: *LootType = Weapon; return xorstr_("Alternator");
			case 49:*LootType = Weapon; return xorstr_("R-99");
			case 55:*LootType = Weapon; return xorstr_("Prowler");
			case 60: *LootType = Weapon; return xorstr_("Volt Smg");
			case 65:  *LootType = Weapon; return xorstr_("Longbow");
			case 70:  *LootType = Weapon; return xorstr_("ChargeRifle");
			case 75: *LootType = Weapon; return xorstr_("Spitfire");
			case 80: *LootType = Weapon; return xorstr_("R-301");
			case 95: *LootType = Weapon; return xorstr_("Mozambique Shotgun");
			case 85: *LootType = Weapon; return xorstr_("Eva-8 Auto");
			case 90: *LootType = Weapon; return xorstr_("Peacekeeper");
			case 2: *LootType = Weapon; return xorstr_("Mastiff Shotgun");
			case 105: *LootType = Weapon; return xorstr_("Wingman");
			case 110: *LootType = Weapon; return xorstr_("P-2020");
			case 115: *LootType = Weapon; return xorstr_("RE-45");
			case 121: *LootType = Weapon; return xorstr_("Sentinel");
			case 126: *LootType = Weapon; return xorstr_("Bocek");
			case 128: *LootType = Weapon; return xorstr_("Repeater");
			case 145: *LootType = Weapon; return xorstr_("Rampage LMG");
			case 150: *LootType = Weapon; return xorstr_("C.A.R. SMG");
			case 134: *LootType = Weapon; return xorstr_("NEMESIS BURSTAR");
			case 210: *LootType = Weapon; return xorstr_("THROWING KNIFE");

			case 231:*LootType = Weapon; return xorstr_("Mag Light 1");
			case 232:*LootType = Weapon; return xorstr_("Mag Light 2");
			case 233:*LootType = Weapon; return xorstr_("Mag Light 3");
			case 234:*LootType = Weapon; return xorstr_("Mag Light 4");

			case 349: *LootType = Weapon; return xorstr_("Energy Magazine 1");
			case 240: *LootType = Weapon; return xorstr_("Energy Magazine 2");
			case 241: *LootType = Weapon; return xorstr_("Energy Magazine 3");
			case 242: *LootType = Weapon; return xorstr_("Energy Magazine 4");


			case 238:*LootType = Weapon; return xorstr_("Heavy Magazine 1");
			case 237:*LootType = Weapon; return xorstr_("Heavy Magazine 2");
			case 236:*LootType = Weapon; return xorstr_("Heavy Magazine 3");
			case 235:*LootType = Weapon; return xorstr_("Heavy Magazine 4");

			case 125:   *LootType = Weapon; return xorstr_("Sniper");
			case 129:  *LootType = Weapon; return xorstr_("Arrows");

			case 181: *LootType = Heal; *LootLevel = 2; return xorstr_("Accelerant");
			case 182: *LootType = Heal; *LootLevel = 3; return xorstr_("Phoenix");
			case 183: *LootType = Heal; *LootLevel = 2; return xorstr_("Medkit");
			case 184: *LootType = Heal; *LootLevel = 1; return xorstr_("Syringe");
			case 185: *LootType = Heal; *LootLevel = 2; return xorstr_("Shield Battery");
			case 186: *LootType = Heal; *LootLevel = 1; return xorstr_("Shield Cell");

			case 187: *LootType = Equipment; *LootLevel = 1; return xorstr_("Helmet 1");
			case 188: *LootType = Equipment; *LootLevel = 2; return xorstr_("Helmet 2");
			case 189: *LootType = Equipment; *LootLevel = 3; return xorstr_("Helmet 3");
			case 190: *LootType = Equipment; *LootLevel = 4; return xorstr_("Helmet 4");


			case 192: *LootType = Equipment; *LootLevel = 1; return xorstr_("1x Shield");
			case 193: *LootType = Equipment; *LootLevel = 2; return xorstr_("2x Shield");
			case 194: *LootType = Equipment; *LootLevel = 3; return xorstr_("3x Shield");
			case 195: *LootType = Equipment; *LootLevel = 4; return xorstr_("4x Shield");
			case 200: *LootType = Equipment; *LootLevel = 5; return xorstr_("5x EVO Shield");

			case 206: *LootType = Equipment; *LootLevel = 1; return xorstr_("1x Backpack");
			case 207: *LootType = Equipment; *LootLevel = 2; return xorstr_("2x Backpack");
			case 208: *LootType = Equipment; *LootLevel = 3; return xorstr_("3x Backpack");
			case 209: *LootType = Equipment; *LootLevel = 4; return xorstr_("4x Backpack");

			case 211: *LootType = Grenade; return xorstr_("Termite Grenade");
			case 212: *LootType = Grenade; return xorstr_("Frag Grenade");
			case 213: *LootType = Grenade; return xorstr_("Arc Star");

			case 214: *LootType = Attachement; *LootLevel = 1; return xorstr_("1x HCOG");
			case 215: *LootType = Attachement; *LootLevel = 2; return xorstr_("2x HCOG");
			case 216: *LootType = Attachement; *LootLevel = 1; return xorstr_("1x Holo");
			case 217: *LootType = Attachement; *LootLevel = 2; return xorstr_("2x Holo");
			case 218: *LootType = Attachement; *LootLevel = 4; return xorstr_("1x Digital");
			case 219: *LootType = Attachement; *LootLevel = 3; return xorstr_("3x HCOG");
			case 220: *LootType = Attachement; *LootLevel = 3; return xorstr_("4x Holo");
			case 221: *LootType = Attachement; *LootLevel = 2; return xorstr_("6x Sniper");
			case 222: *LootType = Attachement; *LootLevel = 3; return xorstr_("8x Sniper");
			case 223: *LootType = Attachement; *LootLevel = 4; return xorstr_("10x Sniper");

			case 224: *LootType = Attachement; *LootLevel = 1; return xorstr_("1x Barrel");
			case 225: *LootType = Attachement; *LootLevel = 2; return xorstr_("2x Barrel");
			case 226: *LootType = Attachement; *LootLevel = 3; return xorstr_("3x Barrel");


			case 243: *LootType = Attachement; *LootLevel = 1; return xorstr_("1x SniperMag");
			case 244: *LootType = Attachement; *LootLevel = 2; return xorstr_("2x SniperMag");
			case 245: *LootType = Attachement; *LootLevel = 3; return xorstr_("SniperMag");
			case 246: *LootType = Attachement; *LootLevel = 4; return xorstr_("3x SniperMag");



			case 247: *LootType = Attachement; *LootLevel = 1; return xorstr_("1x Shotgun Bolt");
			case 248: *LootType = Attachement; *LootLevel = 2; return xorstr_("2x Shotgun Bolt");
			case 249: *LootType = Attachement; *LootLevel = 3; return xorstr_("3x Shotgun Bolt");
			case 250: *LootType = Attachement; *LootLevel = 4; return xorstr_("4x Shotgun Bolt");





			case 260: *LootType = Attachement; *LootLevel = 3; return xorstr_("DISRUPTOR ROUNDS");
			case 271: *LootType = Attachement; *LootLevel = 3; return xorstr_("BOOSTED LOADER");
			case 261: *LootType = Attachement; *LootLevel = 3; return xorstr_("HAMMERPOINT ROUNDS");
			case 257: *LootType = Attachement; *LootLevel = 3; return xorstr_("TURBOCHARGER");
			case 259: *LootType = Attachement; *LootLevel = 3; return xorstr_("SKULLPIERCER RIFLING");


			case 228: *LootType = Attachement; *LootLevel = 1; return xorstr_("1x Laser Sight");
			case 229: *LootType = Attachement; *LootLevel = 2; return xorstr_("2x Laser Sight");
			case 230: *LootType = Attachement; *LootLevel = 3; return xorstr_("3x Laser Sight");

			case 239: *LootType = Attachement; *LootLevel = 1; return xorstr_("1x Extended Energy Mag");
			case 2401: *LootType = Attachement; *LootLevel = 2; return xorstr_("2x Extended Energy Mag");
			case 2413: *LootType = Attachement; *LootLevel = 3; return xorstr_("3x Extended Energy Mag");
			case 2424: *LootType = Attachement; *LootLevel = 4; return xorstr_("4x Extended Energy Mag");


			case 254: *LootType = Attachement; *LootLevel = 1; return xorstr_("1x Sniper Stock");
			case 255: *LootType = Attachement; *LootLevel = 2; return xorstr_("2x Sniper Stock");
			case 256: *LootType = Attachement; *LootLevel = 3; return xorstr_("3x Sniper Stock");





			case 251: *LootType = Attachement; *LootLevel = 1; return xorstr_("1x Standard Stock");
			case 252: *LootType = Attachement; *LootLevel = 2; return xorstr_("2x Standard Stock");
			case 253: *LootType = Attachement; *LootLevel = 3; return xorstr_("3x Standard Stock");


			case 282: *LootType = Attachement; *LootLevel = 1; return xorstr_("Evac Tower");


			case 140: *LootType = Attachement; *LootLevel = 1; return xorstr_("Energy Ammo");
			case 142: *LootType = Attachement; *LootLevel = 1; return xorstr_("Heavy Rounds");
			case 139: *LootType = Attachement; *LootLevel = 1; return xorstr_("Light Rounds");
			case 143: *LootType = Attachement; *LootLevel = 1; return xorstr_("Sniper Ammo");
			case 141: *LootType = Attachement; *LootLevel = 1; return xorstr_("Shotgun Shells");




			case 202: *LootType = Attachement; *LootLevel = 1; return xorstr_("1x Knockdown Shield");
			case 203: *LootType = Attachement; *LootLevel = 2; return xorstr_("2x Knockdown Shield");
			case 204: *LootType = Attachement; *LootLevel = 3; return xorstr_("3x Knockdown Shield");
			case 205: *LootType = Attachement; *LootLevel = 4; return xorstr_("4x Knockdown Shield");

			default: *LootType = Trash; *LootLevel = 1; return xorstr_("");
			}
		}

	};

	struct glowFade
	{
		int a, b;
		float c, d, e, f;
	};

	class cl_EntityList
	{
	public:

		template<typename TClass>
		TClass GetEntityByHandle(EHandle handle)
		{
			if (!handle.is_valid())
				return TClass();

			return Read<TClass>(reinterpret_cast<std::uintptr_t>(this) + handle.index());
		}

		std::vector<class cEntity*> GetAllEntities(class cLocalPlayer* LocalPlayer)
		{
			std::vector<class cEntity*> buffer;

			for (std::uintptr_t i = 0; i <= MAX_PLAYER_COUNT; i++)
			{
				cEntity* curr_entity =
					Read<cEntity*>(reinterpret_cast<std::uintptr_t>(this) + (i << 5));

				if (!IsValidPtr((void*)curr_entity) || (std::uintptr_t)LocalPlayer == (std::uintptr_t)curr_entity)
					continue;

				buffer.push_back(curr_entity);
			}

			return buffer;
		}


		std::vector<class cItem*> GetAllObj(class cLocalPlayer* LocalPlayer)
		{
			std::vector<class cItem*> buffer;

			for (std::uintptr_t i = 0; i <= MAX_ENTITY_OBJ_COUNT; i++)
			{
				class cItem* curr_entity = Read<class cItem*>(reinterpret_cast<std::uintptr_t>(this) + (i << 5));

				if (!IsValidPtr((void*)curr_entity) || (std::uintptr_t)LocalPlayer == (std::uintptr_t)curr_entity)
					continue;

				auto entity_obj_name = curr_entity->GetObjName();

				if (!IsValidPtr((void*)entity_obj_name))
					continue;

				if (std::string(entity_obj_name).find(xorstr_("prop_survival")) == std::string::npos)
					continue;

				auto item_id = curr_entity->GetItemId();

				if (!item_id)
					continue;

				buffer.push_back(curr_entity);
			}

			return buffer;
		}

	};
	struct GlowMode
	{
		int8_t GeneralGlowMode, BorderGlowMode, BorderSize, TransparentLevel;
	};

	void EnableGlow1(std::uintptr_t  colour)
	{
		*(int*)(reinterpret_cast<int*>(colour) + 0x02f0) = 1;



	}
#define OFFSET_GLOW_T1 0x262+ 0x30 //16256 = enabled, 0 = disabled
#define OFFSET_GLOW_T2 0x2dc+ 0x30 //1193322764 = enabled, 0 = disabled
#define OFFSET_GLOW_ENABLE 0x294 //7 = enabled, 2 = disabled
#define OFFSET_GLOW_THROUGH_WALLS 0x278 //2 = enabled, 5 = disabled
	void EnableGlow(std::uintptr_t  colour)
	{
		*(uint8_t*)(colour + OFFSET_GLOW_T1) = 16256;
		*(uint8_t*)(colour + OFFSET_GLOW_T2) = 1193322764;
		*(uint8_t*)(colour + OFFSET_GLOW_ENABLE) = 7;
		*(uint8_t*)(colour + OFFSET_GLOW_THROUGH_WALLS) = 2;


	}
	cItem* get_entiy(uintptr_t idx) {
		return *(cItem**)(valBase + offsets::entity_list_off + (idx << 5));
	}
	cItem* get_localEntity() {
		return *(cItem**)(valBase + 0x21d2738);
	}
	int GetItemId1(cItem* curr_entity)
	{
		return Read<int>((std::uintptr_t)curr_entity + offsets::entity_item_id);
	}
	void EnableGlowItems(Vector3 weapon_col,
		Vector3 medical_col,
		Vector3 equipment_col,
		Vector3 throwables_col,
		Vector3 attachments_col,
		glow_mode glowmode)
	{
		cItem* local_entity = get_localEntity();
		if (!local_entity)
			return;
		const auto entity_list = reinterpret_cast<cl_EntityList*>(valBase + offsets::entity_list_off);

		if (!IsValidPtr((void*)entity_list))
			return;

		for (const auto curr_entity1 : entity_list->GetAllObj((cLocalPlayer*)local_entity))
		{

			if (!IsValidPtr((void*)curr_entity1))
				continue;
			// std::printf("local_entity %llx \n", local_entity);
			auto curr_entity = static_cast<cItem*>(curr_entity1);


			if (curr_entity == local_entity)
				continue;

			//std::printf("curr_entity %llx \n", curr_entity);

			auto entity_obj_name = curr_entity->GetObjName();
			if (!entity_obj_name)
				continue;

			std::printf("name %s \n", entity_obj_name);

			//	if (std::string(entity_obj_name).find(xorstr_("prop_survival")) == std::string::npos)
				//continue;
				//std::printf("entity_obj_name2 %s \n", entity_obj_name);

			auto item_id = GetItemId1((cItem*)curr_entity);
			if (!IsValidPtr((void*)item_id))
				continue;

			std::printf("item_id %i \n", item_id);

			//	std::printf("item_id %llx \n", item_id);

			cItem::eItemType item_type{};
			int item_level;
			auto item_name = curr_entity->GetLootName(item_id, &item_type, &item_level);
			std::printf("item_name %s \n", item_name);

			if (item_type == cItem::eItemType::Trash)
				continue;
			//
							//if (!curr_entity->ModifyGlowType(glowmode))
							//	continue;

			EnableGlow((std::uintptr_t)curr_entity);

			/*switch (item_type)
			{
			case SDK::cItem::Weapon:
				this->EnableGlow(weapon_col);
				break;
			case SDK::cItem::Heal:
				this->EnableGlow(medical_col);
				break;
			case SDK::cItem::Equipment:
				this->EnableGlow(equipment_col);
				break;
			case SDK::cItem::Grenade:
				this->EnableGlow(throwables_col);
				break;
			case SDK::cItem::Attachement:
				this->EnableGlow(attachments_col);
				break;
			default:
				return;
			}*/
		}
	}
	class cUserCmd
	{
	public:
		//void WriteSilentViewAngles(utils::maths::vec2_t angle)
		//{
		//	auto m_pCommands = Read<std::uintptr_t>(reinterpret_cast<std::uintptr_t>(this) + 0xF8);

		//	if (!IsValidPtr((void*)m_pCommands))
		//		return;

		//	auto first_command_number{ Read<int>(m_pCommands) };
		//	while (first_command_number == Read<int>(m_pCommands)); //verifies that current usercmd is latest
		//	auto next_cmd_number{ Read<int>(m_pCommands + 0x218) + 1 }; //Grab next current usercmd (0x218 is size of UserCmd)

		//	std::uintptr_t current_command{ m_pCommands + 0x218 * (next_cmd_number % 750) };
		//	while (next_cmd_number != Read<int>(current_command)); //Wait for usercmd to be accessed
		//	std::uintptr_t old_command{ m_pCommands + 0x218 * ((next_cmd_number - 1) % 750) };

		//	Read<int>(old_command + 0x38) = 1;
		//	Read<utils::maths::vec2_t>(old_command + 0xC) = angle;

		//	next_cmd_number = Read<int>(current_command) + 1;
		//}
	};

	class cWeapon
	{
	public:
		float GetProjectileSpeed()
		{


			return Read<float>(reinterpret_cast<std::uintptr_t>(this) + offsets::wep_projectilespeed);
		}

		float GetProjectileGravity()
		{
			return Read<float>(reinterpret_cast<std::uintptr_t>(this) + offsets::wep_projectilegravity);
		}
		int GetProjectilinclip()
		{
			return Read<int>(reinterpret_cast<std::uintptr_t>(this) + offsets::wep_m_ammoInClip);
		}
		int Getanmenclip()
		{
			return Read<int>(reinterpret_cast<std::uintptr_t>(this) + offsets::entityiname_id);
		}
	};

	class cLocalPlayer : public cEntity
	{
	public:

		utils::maths::vec2_t GetViewAngles()
		{
			return Read<utils::maths::vec2_t>(reinterpret_cast<std::uintptr_t>(this) + offsets::view_angles1);
		}
		Vector3 GetViewAngles2()
		{
			return Read<Vector3>(reinterpret_cast<std::uintptr_t>(this) + offsets::view_angles1);
		}

		Vector3 GetAimPunch()
		{
			return Read<Vector3>(reinterpret_cast<std::uintptr_t>(this) + offsets::OFFSET_BREATH_ANGLES);
		}
		utils::maths::vec2_t GetAimPunch2()
		{
			return Read<utils::maths::vec2_t>(reinterpret_cast<std::uintptr_t>(this) + offsets::aim_punch);
		}
		void WriteGetAimPunch(Vector3 angle)
		{

			*(Vector3*)(reinterpret_cast<std::uintptr_t>(this) + offsets::aim_punch) = angle;

		}
		Vector3 GetCameraPosition()
		{
			return Read<Vector3>(reinterpret_cast<std::uintptr_t>(this) + offsets::camera_position);
		}

		void WriteViewAngles(utils::maths::vec2_t angle)
		{

			*(utils::maths::vec2_t*)(reinterpret_cast<std::uintptr_t>(this) + offsets::view_angles1) = angle;

		}
		void WriteViewAngles2(Vector3 angle)
		{

			*(Vector3*)(reinterpret_cast<std::uintptr_t>(this) + offsets::view_angles1) = angle;

		}

		cWeapon* GetCurrentWeapon(class cl_EntityList* entity_list)
		{
			auto current_weapons = Read<EHandle>(reinterpret_cast<std::uintptr_t>(this) + offsets::entity_currentweapon);

			return entity_list->GetEntityByHandle<class cWeapon*>(current_weapons);
		}
	};
}
DWORD64 GetEntityById(int Ent, DWORD64 Base)
{
	DWORD64 EntityList = Base + SDK1::offsets::entity_list_off; //updated
	if (!EntityList)
		return NULL;
	DWORD64 BaseEntity = SDK1::Read<DWORD64>(EntityList);
	if (!BaseEntity)
		return NULL;
	return  SDK1::Read<DWORD64>(EntityList + (Ent << 5));
}
struct clr {
	float r, g, b, a;
};
SDK1::cEntity* resultant_target_entity = nullptr;

std::vector<SDK1::cEntity*> valid_players;
std::vector<SDK1::cEntity*> valid_players4trigger;
void draw_line(const ImVec2& from, const ImVec2& to, clr color, float thickness) {
	ImDrawList* VALO = ImGui::GetBackgroundDrawList();
	VALO->AddLine(from, to, ImGui::GetColorU32({ color.r / 255.0f, color.g / 255.0f, color.b / 255.0f, color.a / 255.0f }), thickness);
}

void draw_circle(const ImVec2& position, float radius, clr color, float thickness, uint32_t segments) {
	ImDrawList* VALO = ImGui::GetBackgroundDrawList();
	VALO->AddCircle(position, radius, ImGui::GetColorU32({ color.r / 255.0f, color.g / 255.0f, color.b / 255.0f, color.a / 255.0f }), segments, thickness);
}

void draw_rect(const ImVec2& from, const ImVec2& to, clr color, float rounding, float thickness) {
	ImDrawList* VALO = ImGui::GetBackgroundDrawList();
	VALO->AddRect(from, to, ImGui::GetColorU32({ color.r / 255.0f, color.g / 255.0f, color.b / 255.0f, color.a / 255.0f }), rounding, NULL, thickness);
}

void draw_rect_filled(const ImVec2& from, const ImVec2& to, clr color, float rounding) {
	ImDrawList* VALO = ImGui::GetBackgroundDrawList();
	VALO->AddRectFilled(from, to, ImGui::GetColorU32({ color.r / 255.0f, color.g / 255.0f, color.b / 255.0f, color.a / 255.0f }), rounding, NULL);
}

float sqrtf1(float _X
) {
	return _mm_cvtss_f32(_mm_sqrt_ss(_mm_set_ss(_X)));



}
SDK1::cEntity* get_closest_player(SDK1::cLocalPlayer* local_player, D3DMATRIX& view_matrix, std::vector<SDK1::cEntity*> list, float field_of_view, bool cap_distance)
{
	SDK1::cEntity* resultant_target_entity_temp = nullptr;
	float closestTocenter = FLT_MAX;
	ImGuiIO& io = ImGui::GetIO();

	for (const auto curr_entity : list)
	{
		if (!curr_entity->IsPlayer() || !curr_entity->IsAlive() || curr_entity->IsFriendly(local_player))
			continue;

		if (Globals::Visuals::aimbot_visiblity_check && !curr_entity->IsPlayerVisible())
			continue;

		auto target_bone_pos_w = curr_entity->GetBonePositionById((SDK1::cBoneId)Globals::Visuals::bone_choice2);
		if (target_bone_pos_w.empty())
			continue;

		Vector3 target_bone_pos{};
		if (!SDK1::WorldToScreen(view_matrix, target_bone_pos_w, target_bone_pos))
			continue;

		if (target_bone_pos.empty())
			continue;


		if (cap_distance)
		{
			auto local_pos = local_player->GetOrigin();

			if (local_pos.empty())
				continue;

			auto distance_relative = local_pos.distance(target_bone_pos_w) / 100.f;


		}
		auto dx = target_bone_pos.x - (io.DisplaySize.x / 2);

		auto dy = target_bone_pos.y - (io.DisplaySize.y / 2);
		auto dist = sqrtf1(dx * dx + dy * dy);
		if (dist < field_of_view && dist < closestTocenter) {
			closestTocenter = dist;
			resultant_target_entity_temp = curr_entity;
		}
	}

	return resultant_target_entity_temp;
}
Vector3 CalcAnglen(const Vector3& src, const Vector3& dst)
{
	Vector3 angle = Vector3();
	Vector3 delta = Vector3((src.x - dst.x), (src.y - dst.y), (src.z - dst.z));

	double hyp = sqrt(delta.x * delta.x + delta.y * delta.y);

	angle.x = atan(delta.z / hyp) * (180.0f / M_PI);
	angle.y = atan(delta.y / delta.x) * (180.0f / M_PI);
	angle.z = 0;
	if (delta.x >= 0.0) angle.y += 180.0f;

	return angle;
}
void monkey(Vector3& angle)
{
	while (angle.x > 89.0f)
		angle.x -= 180.f;

	while (angle.x < -89.0f)
		angle.x += 180.f;

	while (angle.y > 180.f)
		angle.y -= 360.f;

	while (angle.y < -180.f)
		angle.y += 360.f;
}
void __stdcall main_aimbot(SDK1::cLocalPlayer* LocalPlayer, D3DMATRIX& view_matrix, SDK1::cl_EntityList* entity_list)
{
	ImDrawList* VALO = ImGui::GetBackgroundDrawList();
	ImGuiIO& io = ImGui::GetIO();


	auto local_weapon = LocalPlayer->GetCurrentWeapon(entity_list);
	if (SDK1::IsValidPtr((void*)local_weapon))
	{

		auto projectile_speed = local_weapon->GetProjectileSpeed();
		std::printf("projectile_speed %f \n", projectile_speed);

		auto projectile_gravity = local_weapon->GetProjectileGravity();
		std::printf("projectile_gravity %f \n", projectile_gravity);

		auto projectile_Ammo = local_weapon->GetProjectilinclip();
		std::printf("GetProjectilinclip %i \n", projectile_Ammo);
		auto Getanmenclip = local_weapon->Getanmenclip();
		std::printf("Getanmenclip %i \n", Getanmenclip); // try in traing mode now



	}


	if (!GetAsyncKeyState(aimkey))
		resultant_target_entity = nullptr;



	if (GetAsyncKeyState(aimkey))
	{
		if (!resultant_target_entity)
			resultant_target_entity = get_closest_player(LocalPlayer, view_matrix, valid_players, Globals::Visuals::fov_value, Globals::Visuals::cap_aimbot_distance);
		auto is_visible = resultant_target_entity->IsPlayerVisible();
		if (!is_visible && Globals::Visuals::aimbot_visiblity_check)
		{
			resultant_target_entity = nullptr;
			return;
		}



		if (!resultant_target_entity)
			return;

		auto target_bone_pos_w = resultant_target_entity->GetBonePositionById((SDK1::cBoneId)Globals::Visuals::bone_choice2);
		if (target_bone_pos_w.empty())
		{
			resultant_target_entity = nullptr;
			return;
		}

		auto local_position = LocalPlayer->GetCameraPosition();

		auto local_weapon = LocalPlayer->GetCurrentWeapon(entity_list);
		if (!SDK1::IsValidPtr((void*)local_weapon))
		{
			resultant_target_entity = nullptr;
			return;

		}
		//auto projectile_Ammo = local_weapon->GetProjectilinclip();
		//if (projectile_Ammo < 1) // - Hold Weapon Fix go online and use aimbot
		//
		//{
		//	resultant_target_entity = nullptr;
		//	return;
		//}

		//auto projectile_Ammo1 = local_weapon->Getanmenclip();
		//if (projectile_Ammo1 < 1)

		//{
		//	resultant_target_entity = nullptr;
		//	return;
		//}

		//if (projectile_Ammo1 == 109 || projectile_Ammo1 == 3043)
		{

			auto ViewAngles = LocalPlayer->GetViewAngles2();
			auto SwayAngles = LocalPlayer->GetAimPunch();


			auto CalculatedAngles = CalcAnglen(local_position, target_bone_pos_w);
			if (Globals::Visuals::rcs_aimbot)
			{


				CalculatedAngles -= SwayAngles - ViewAngles;
				monkey(CalculatedAngles);
			}

			Vector3 Delta = CalculatedAngles - ViewAngles;

			monkey(Delta);

			Vector3 SmoothedAngles = ViewAngles + Delta / Globals::Visuals::smooth_value;

			LocalPlayer->WriteViewAngles({ SmoothedAngles.x, SmoothedAngles.y });
			return;

		}


		if (Globals::Visuals::aimbot_prediction)
		{


			if (SDK1::IsValidPtr((void*)local_weapon))
			{
				//	auto projectile_Ammo1 = local_weapon->Getanmenclip();
				//	std::printf("projectile_Ammo %i \n", projectile_Ammo1);

					//OutputDebugStringA("[#] A2");




				auto distance = local_position.distance(target_bone_pos_w);

				if (distance != 0.f)
				{
					//OutputDebugStringA("[#] A3");

					//distance /= 100.f;

				/*	auto base = Read<cWeapon*>((std::uintptr_t)local_weapon + 0x1a50);
					if (!base)
						return;*/


					auto projectile_speed = local_weapon->GetProjectileSpeed();
					std::printf("projectile_speed %f \n", projectile_speed);



					auto projectile_gravity = local_weapon->GetProjectileGravity();
					std::printf("projectile_gravity %f \n", projectile_gravity);

					//OutputDebugStringA("[#] A4");

					//if (projectile_speed > 1.f)
					{
						//OutputDebugStringA("[#] A5");

						auto calc_time = distance / projectile_speed;

						//OutputDebugStringA("[#] A5.5");

						auto player_velocity = resultant_target_entity->GetVelocity();

						//OutputDebugStringA("[#] A6");

						target_bone_pos_w.x += ((player_velocity.x /*- local_velocity.x*/) * calc_time);
						target_bone_pos_w.y += ((player_velocity.y /*- local_velocity.y*/) * calc_time);
						target_bone_pos_w.z += ((740.f * projectile_gravity * 0.5f) * (calc_time * calc_time));
						//target_bone_pos_w.z += .5 * std::asinf((projectile_gravity * distance) / powf(projectile_speed, 2));
					}

				}
			}
		}

		auto ViewAngles = LocalPlayer->GetViewAngles2();
		auto SwayAngles = LocalPlayer->GetAimPunch();

		if (Globals::Visuals::aimbot_onlyshooting && SwayAngles.x == 0)
			return;

		auto CalculatedAngles = CalcAnglen(local_position, target_bone_pos_w);


		if (Globals::Visuals::rcs_aimbot)
		{


			CalculatedAngles -= SwayAngles - ViewAngles;
			monkey(CalculatedAngles);
		}

		Vector3 Delta = CalculatedAngles - ViewAngles;

		monkey(Delta);

		Vector3 SmoothedAngles = ViewAngles + Delta / Globals::Visuals::smooth_value;

		LocalPlayer->WriteViewAngles({ SmoothedAngles.x, SmoothedAngles.y });

		/*	Vector3 SmoothedAngles = ViewAngles + Delta;

			SmoothedAngles.normalize();

			SmoothedAngles.x = ((float)((int)((SmoothedAngles.x + 0.005) * 100))) / 100;
			SmoothedAngles.y = ((float)((int)((SmoothedAngles.y + 0.005) * 100))) / 100;
			SmoothedAngles.z = ((float)((int)((SmoothedAngles.z + 0.005) * 100))) / 100;

			SmoothedAngles.normalize();
			std::printf("SmoothedAngles %f %f %f \n", SmoothedAngles.x, SmoothedAngles.y, SmoothedAngles.z);

			LocalPlayer->WriteViewAngles({ SmoothedAngles.x, SmoothedAngles.y });*/

	}
}

void __stdcall Trigger(SDK1::cLocalPlayer* LocalPlayer, D3DMATRIX& view_matrix, SDK1::cl_EntityList* entity_list
)
{
	ImDrawList* VALO = ImGui::GetBackgroundDrawList();
	ImGuiIO& io = ImGui::GetIO();


	auto local_weapon = LocalPlayer->GetCurrentWeapon(entity_list);
	if (!SDK1::IsValidPtr((void*)local_weapon))
	{
		return;

	}
	float closestTocenter = FLT_MAX;


	float DistoTrigger = 50;

	if (GetAsyncKeyState(aimkey4trigger)) {

		for (const auto curr_entity : valid_players4trigger)
		{
			if (!curr_entity->IsPlayer() || !curr_entity->IsAlive() || curr_entity->IsFriendly(LocalPlayer))
				continue;

			if (Globals::Visuals::aimbot_visiblity_check && !curr_entity->IsPlayerVisible())
				continue;

			auto target_bone_pos_w = curr_entity->GetBonePositionById((SDK1::cBoneId)Globals::Visuals::bone_choice2);
			if (target_bone_pos_w.empty())
				continue;

			Vector3 target_bone_pos{};
			if (!SDK1::WorldToScreen(view_matrix, target_bone_pos_w, target_bone_pos))
				continue;

			if (target_bone_pos.empty())
				continue;



			auto curr_origin = curr_entity->GetOrigin();
			if (curr_origin.empty())
				continue;


			auto local_pos = LocalPlayer->GetOrigin();

			auto distance_relative = curr_origin.distance(local_pos) / 100.f;

			// if enemy is more 40 metter 
			if (distance_relative > 10 && distance_relative < 20)
				DistoTrigger = 100; // this life inside fov == DistoTrigger


			if (distance_relative > 20 && distance_relative < 30)
				DistoTrigger = 80;// this


			if (distance_relative > 30 && distance_relative < 40)
				DistoTrigger = 70;// this


			if (distance_relative > 40 && distance_relative < 50)
				DistoTrigger = 30;// this

			if (distance_relative > 50)
				DistoTrigger = 20;



			auto dx = target_bone_pos.x - (io.DisplaySize.x / 2);

			auto dy = target_bone_pos.y - (io.DisplaySize.y / 2);
			auto dist = sqrtf1(dx * dx + dy * dy);
			if (dist < DistoTrigger && dist < closestTocenter) { // 50 - More = Good low = not good 
				closestTocenter = dist;
				SendMessage(variables::window_handle, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(io.DisplaySize.x / 2, io.DisplaySize.y / 2));
			}



		}
	}




}
void __stdcall render_player_skeletal(D3DMATRIX view_matrix, SDK1::cEntity* curr_entity, ImU32 color)
{
	ImDrawList* VALO = ImGui::GetBackgroundDrawList();

	/*
		auto test_w = curr_entity->GetBonePositionById((SDK1::cBoneId)Globals::Visuals::bone_limiter);

	Vector3 test_pos{};
		if (!SDK1::WorldToScreen(view_matrix, test_w, test_pos))
			return;
		VALO->AddText(font_size,{ test_pos.x,test_pos.y }, color, std::to_string(Globals::Visuals::bone_limiter).c_str());


	return;*/

	auto l_foot_position_w = curr_entity->GetBonePositionById(SDK1::cBoneId::l_foot);
	auto l_knee_position_w = curr_entity->GetBonePositionById(SDK1::cBoneId::l_knee);
	auto l_hip_position_w = curr_entity->GetBonePositionById(SDK1::cBoneId::l_hip);
	auto lowerstomach_position_w = curr_entity->GetBonePositionById(SDK1::cBoneId::lower_stomach);
	auto r_foot_position_w = curr_entity->GetBonePositionById(SDK1::cBoneId::r_foot);
	auto r_knee_position_w = curr_entity->GetBonePositionById(SDK1::cBoneId::r_knee);
	auto r_hip_position_w = curr_entity->GetBonePositionById(SDK1::cBoneId::r_hip);
	auto stomach_position_w = curr_entity->GetBonePositionById(SDK1::cBoneId::stomach);
	auto torso_position_w = curr_entity->GetBonePositionById(SDK1::cBoneId::torso);
	auto neck_position_w = curr_entity->GetBonePositionById(SDK1::cBoneId::neck);
	auto l_hand_position_w = curr_entity->GetBonePositionById(SDK1::cBoneId::l_hand);
	auto l_elbow_position_w = curr_entity->GetBonePositionById(SDK1::cBoneId::l_elbow);
	auto l_shoulder_position_w = curr_entity->GetBonePositionById(SDK1::cBoneId::l_shoulder);
	auto r_hand_position_w = curr_entity->GetBonePositionById(SDK1::cBoneId::r_hand);
	auto r_elbow_position_w = curr_entity->GetBonePositionById(SDK1::cBoneId::r_elbow);
	auto r_shoulder_position_w = curr_entity->GetBonePositionById(SDK1::cBoneId::r_shoulder);

	if (l_foot_position_w.empty() || l_knee_position_w.empty()
		|| l_hip_position_w.empty()
		|| lowerstomach_position_w.empty()
		|| r_foot_position_w.empty()
		|| r_knee_position_w.empty()
		|| r_hip_position_w.empty()
		|| stomach_position_w.empty()
		|| torso_position_w.empty()
		|| neck_position_w.empty()
		|| l_hand_position_w.empty()
		|| l_elbow_position_w.empty()
		|| l_shoulder_position_w.empty()
		|| r_hand_position_w.empty()
		|| r_elbow_position_w.empty()
		|| r_shoulder_position_w.empty())
		return;

	Vector3 l_foot_position{};
	if (!SDK1::WorldToScreen(view_matrix, l_foot_position_w, l_foot_position))
		return;

	Vector3 l_knee_position{};
	if (!SDK1::WorldToScreen(view_matrix, l_knee_position_w, l_knee_position))
		return;

	Vector3 l_hip_position{};
	if (!SDK1::WorldToScreen(view_matrix, l_hip_position_w, l_hip_position))
		return;

	Vector3 lowerstomach_position{};
	if (!SDK1::WorldToScreen(view_matrix, lowerstomach_position_w, lowerstomach_position))
		return;

	Vector3 r_foot_position{};
	if (!SDK1::WorldToScreen(view_matrix, r_foot_position_w, r_foot_position))
		return;

	Vector3 r_knee_position{};
	if (!SDK1::WorldToScreen(view_matrix, r_knee_position_w, r_knee_position))
		return;

	Vector3 r_hip_position{};
	if (!SDK1::WorldToScreen(view_matrix, r_hip_position_w, r_hip_position))
		return;

	Vector3 stomach_position{};
	if (!SDK1::WorldToScreen(view_matrix, stomach_position_w, stomach_position))
		return;

	Vector3 torso_position{};
	if (!SDK1::WorldToScreen(view_matrix, torso_position_w, torso_position))
		return;

	Vector3 neck_position{};
	if (!SDK1::WorldToScreen(view_matrix, neck_position_w, neck_position))
		return;

	Vector3 l_hand_position{};
	if (!SDK1::WorldToScreen(view_matrix, l_hand_position_w, l_hand_position))
		return;

	Vector3 l_elbow_position{};
	if (!SDK1::WorldToScreen(view_matrix, l_elbow_position_w, l_elbow_position))
		return;

	Vector3 l_shoulder_position{};
	if (!SDK1::WorldToScreen(view_matrix, l_shoulder_position_w, l_shoulder_position))
		return;

	Vector3 r_hand_position{};
	if (!SDK1::WorldToScreen(view_matrix, r_hand_position_w, r_hand_position))
		return;

	Vector3 r_elbow_position{};
	if (!SDK1::WorldToScreen(view_matrix, r_elbow_position_w, r_elbow_position))
		return;

	Vector3 r_shoulder_position{};
	if (!SDK1::WorldToScreen(view_matrix, r_shoulder_position_w, r_shoulder_position))
		return;


	VALO->AddLine({ l_foot_position.x, l_foot_position.y }, { l_knee_position.x, l_knee_position.y }, color, 2.f);
	VALO->AddLine({ l_knee_position.x, l_knee_position.y }, { l_hip_position.x, l_hip_position.y }, color, 2.f);
	VALO->AddLine({ l_hip_position.x, l_hip_position.y }, { stomach_position.x, stomach_position.y }, color, 2.f);
	VALO->AddLine({ r_foot_position.x, r_foot_position.y }, { r_knee_position.x, r_knee_position.y }, color, 2.f);
	VALO->AddLine({ r_knee_position.x, r_knee_position.y }, { r_hip_position.x, r_hip_position.y }, color, 2.f);
	VALO->AddLine({ r_hip_position.x, r_hip_position.y }, { stomach_position.x, stomach_position.y }, color, 2.f);
	VALO->AddLine({ stomach_position.x, stomach_position.y }, { torso_position.x, torso_position.y }, color, 2.f);
	VALO->AddLine({ torso_position.x, torso_position.y }, { neck_position.x, neck_position.y }, color, 2.f);
	VALO->AddLine({ l_hand_position.x, l_hand_position.y }, { l_elbow_position.x, l_elbow_position.y }, color, 2.f);
	VALO->AddLine({ l_elbow_position.x, l_elbow_position.y }, { l_shoulder_position.x, l_shoulder_position.y }, color, 2.f);
	VALO->AddLine({ l_shoulder_position.x, l_shoulder_position.y }, { neck_position.x, neck_position.y }, color, 2.f);
	VALO->AddLine({ r_hand_position.x, r_hand_position.y }, { r_elbow_position.x, r_elbow_position.y }, color, 2.f);
	VALO->AddLine({ r_elbow_position.x, r_elbow_position.y }, { r_shoulder_position.x, r_shoulder_position.y }, color, 2.f);
	VALO->AddLine({ r_shoulder_position.x, r_shoulder_position.y }, { neck_position.x, neck_position.y }, color, 2.f);
}

void DrawRect(int x, int y, int w, int h, int thickness, auto colorbox)
{
	ImDrawList* VALO = ImGui::GetBackgroundDrawList();

	VALO->AddRect(ImVec2(x, y), ImVec2(x + w, y + h), colorbox, 0, 0, thickness);

}
//void DrawFilledRect(int x, int y, int w, int h)
//{
//	ImDrawList* VALO = ImGui::GetBackgroundDrawList();
//	auto ColorBox = IM_COL32(0, 0, 255, 255);
//
//	VALO->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ColorBox, 0, 0);
//}
void DrawFilledRect2(int x, int y, int w, int h, auto colorbox)
{
	ImDrawList* VALO = ImGui::GetBackgroundDrawList();

	VALO->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), colorbox, 0, 0);
}
void DrawCornerBox(int x, int y, int w, int h, int borderPx, auto colorbox)
{
	auto color = IM_COL32(0, 0, 255, 255);

	DrawFilledRect2(x + borderPx, y, w / 3, borderPx, colorbox); //top 
	DrawFilledRect2(x + w - w / 3 + borderPx, y, w / 3, borderPx, colorbox); //top 
	DrawFilledRect2(x, y, borderPx, h / 3, colorbox); //left 
	DrawFilledRect2(x, y + h - h / 3 + borderPx * 2, borderPx, h / 3, colorbox); //left 
	DrawFilledRect2(x + borderPx, y + h + borderPx, w / 3, borderPx, colorbox); //bottom 
	DrawFilledRect2(x + w - w / 3 + borderPx, y + h + borderPx, w / 3, borderPx, colorbox); //bottom 
	DrawFilledRect2(x + w + borderPx, y, borderPx, h / 3, colorbox);//right 
	DrawFilledRect2(x + w + borderPx, y + h - h / 3 + borderPx * 2, borderPx, h / 3, colorbox);//right 
}

bool IsSpectator_New(uint64_t playeraddr)
{
	const auto local_player = *reinterpret_cast<SDK1::cLocalPlayer**>(valBase + 0x2259868); // offsed need be changed
	if (!SDK1::IsValidPtr((void*)local_player))
		return 0;


	auto SpectatorList = *reinterpret_cast<uint64_t**>(valBase + 0x1EACCE8); // offsed need be changed
	if (!SDK1::IsValidPtr((void*)SpectatorList))
		return 0;

	int PlayerData = *reinterpret_cast<int*>(playeraddr + 0x38);

	int Index = *reinterpret_cast<int*>(SpectatorList + PlayerData * 8 + 0x964);


	const auto entity_list = reinterpret_cast<SDK1::cl_EntityList*>(valBase + SDK1::offsets::entity_list_off);
	

	if (!SDK1::IsValidPtr((void*)entity_list))
		return 0;


	auto SpectatorAddr = *reinterpret_cast<SDK1::cLocalPlayer**>(valBase + entity_list + ((Index & 0xFFFF) << 5));
	if ((uintptr_t)SpectatorAddr == (uintptr_t)local_player)
		return true;


	return false;
}

void __stdcall main_visuals()
{
	ImDrawList* VALO = ImGui::GetBackgroundDrawList();
	auto colorVis1 = IM_COL32(0, 255, 0, 255);
	auto colorVis3 = IM_COL32(0, 0, 255, 255);
	auto colorVis2 = IM_COL32(0, 255, 255, 255);
	ImGuiIO& io = ImGui::GetIO();

	if (!onecee) {
		valBase = (uintptr_t)LI_FN(GetModuleHandleA)(_("r5apex.exe"));
		//testingmouse();
		onecee = true;
	}




	if (Globals::Visuals::show_fov)
	{
		DrawCircle1({ (float)io.DisplaySize.x / 2, (float)io.DisplaySize.y / 2 }, Globals::Visuals::fov_value, { 0,255,0,255 }, 1.0f);
	}




	//*reinterpret_cast<int*>(valBase + 0x01fb0680 + 0x6c) = 1;



	const auto local_player = *reinterpret_cast<SDK1::cLocalPlayer**>(valBase + 0x2259868); // OFFSET NEED CHANGED
	//	 if (testing)
	//std::printf("local_player %llx \n", local_player);
	if (!SDK1::IsValidPtr((void*)local_player))
		return;


	//if (Globals::Visuals::rcs_standalone)
	//{

	//	main_rcs(local_player);
	//}

	//VALO->AddText(ImVec2{ 200,200 }, colorVis1, ("local_player : " + std::to_string((uintptr_t)local_player)).c_str());	 

	const auto entity_list = reinterpret_cast<SDK1::cl_EntityList*>(valBase + SDK1::offsets::entity_list_off);
	//	 if (testing)
		// std::printf("entity_list %llx \n", entity_list);

	if (!SDK1::IsValidPtr((void*)entity_list))
		return;






	const auto view_renderer = *reinterpret_cast<SDK1::cViewRenderer**>(valBase + SDK1::offsets::view_renderer);
	if (!SDK1::IsValidPtr((void*)view_renderer))
		return;
	//std::printf("view_renderer %llx \n", view_renderer);

	//VALO->AddText(ImVec2{ 200,280 }, colorVis1, ("view_renderer : " + std::to_string((uintptr_t)view_renderer)).c_str());


	auto view_matrix_ptr = view_renderer->GetViewMatrixPtr();
	// if (testing)
	// std::printf("view_matrix_ptr %llx \n", view_matrix_ptr);

	if (!SDK1::IsValidPtr((void*)view_matrix_ptr))
		return;

	//VALO->AddText(ImVec2{ 200,300 }, colorVis1, ("view_matrix_ptr : " + std::to_string((uintptr_t)view_matrix_ptr)).c_str());


	auto view_matrix = view_matrix_ptr->GetViewMatrix();
	//	 if (testing)
	//	 std::printf("view_matrix %llx \n", view_matrix);


	auto local_pos = local_player->GetOrigin();
	//if (testing)
	//std::printf("local_pos %f %f %f \n", local_pos.x, local_pos.y, local_pos.z);

	if (local_pos.empty())
		return;

	//std::cout << local_pos.x << " " << local_pos.y << " " << local_pos.z << std::endl;

	//bool item_found{};

	//for (int i = 0; item_found == false && i < 10000; i++)
	//{
	//	auto Entity = (SDK1::cItem*)GetEntityById(i, valBase);
	//	if (Entity == 0)
	//		continue;
	//	if (!Entity)
	//		continue;

	//	auto curr_origin = SDK1::Read<Vector3>((DWORD64)Entity + SDK1::offsets::entity_origin);

	//	if (curr_origin.empty())
	//		continue;
	//	int itemid = SDK1::Read<int>((DWORD64)Entity + SDK1::offsets::entity_item_id);
	//	if (itemid == 0) // check if entity is an item, you need to check class name afaik
	//		continue;
	//	if (itemid < 0)
	//		continue;
	//	Vector3 screen_position{};

	//	if (!SDK1::WorldToScreen(view_matrix, curr_origin, screen_position))
	//		continue;

	//	//std::printf("itemid %i \n", itemid);
	//	//	std::printf("item_id %llx \n", item_id);

	//	SDK1::cItem::eItemType item_type{};
	//	int item_level;
	//	auto item_name = Entity->GetLootName(itemid, &item_type, &item_level);

	//	if (item_type == SDK1::cItem::eItemType::Trash)
	//	{
	//		continue;
	//	}

	//	item_found = true;

	//	//std::printf("item_name %s \n", item_name);
	//	VALO->AddText({ screen_position.x,screen_position.y }, colorVis2, item_name);
	//	//	std::printf("Entity %llx \n", Entity);

	//	//	EnableGlow((DWORD64)Entity);

	//}

	const auto highlights = *reinterpret_cast<uint8_t**>(valBase + 0xade4bc0); // offset need be changed
	if (!SDK1::IsValidPtr((void*)highlights))
		return;

	for (size_t i = 26; i < 50; ++i)
	{
		uint8_t compare[4]{};
		memcpy(compare, highlights + 0x34 * i, sizeof(compare));

		if (Globals::Visuals::esp_item_glow)
		{
			if (compare[0] == 135 && compare[1] == 135)
			{
				const uint8_t parameters[4] = { 137, 138, compare[2], 192 };
				memcpy(highlights + 0x34 * i, parameters, sizeof(parameters));
			}
			else if (compare[0] == 0 && (compare[1] == 110 || compare[1] == 129))
			{
				const uint8_t parameters[4] = { 0, 138, compare[2], 192 };
				memcpy(highlights + 0x34 * i, parameters, sizeof(parameters));
			}
		}
		else
		{
			if (compare[0] == 137 && compare[1] == 138)
			{
				const uint8_t parameters[4] = { 135, 135, compare[2], 192 };
				memcpy(highlights + 0x34 * i, parameters, sizeof(parameters));
			}
			else if (compare[0] == 0 && compare[1] == 138)
			{
				const uint8_t parameters[4] = { 0, 110, compare[2], 192 };
				memcpy(highlights + 0x34 * i, parameters, sizeof(parameters));
			}
		}
	}



	for (const auto curr_entity : entity_list->GetAllEntities(local_player))
	{
		if (!SDK1::IsValidPtr((void*)curr_entity))
			continue;
		//std::printf("curr_entity %llx \n", curr_entity);

		if (!curr_entity->IsValidEntity())
			continue;

		auto curr_origin = curr_entity->GetOrigin();
		if (curr_origin.empty())
			continue;

		Vector3 screen_position{};
		if (!SDK1::WorldToScreen(view_matrix, curr_origin, screen_position))
			continue;


		//std::cout << screen_position.x << " " << screen_position.y << std::endl;


		if (Globals::Visuals::esp_hideteam && curr_entity->IsFriendly(local_player))
			continue;

		//std::cout << "nigger\n";

		//if(IsSpectator_New((uint64_t)curr_entity) == true && Globals::Visuals::speclist)
		//	VALO->AddText({ 200,200 }, colorVis1, _(" Spectator Waching :"));


		auto distance_relative = curr_origin.distance(local_pos) / 100.f;
		//	std::printf("distance_relative %f \n", distance_relative);


		if (distance_relative > esp_max_distance)
			continue;
		//	if (testing)
		//	std::printf("distance_relative %f \n", distance_relative);

		const auto entity_name_map = reinterpret_cast<SDK1::cNameMap*>(valBase + SDK1::offsets::entity_name_list);
		//	if (testing)
		//	std::printf("entity_name_map %llx \n", entity_name_map);

		if (!SDK1::IsValidPtr((void*)entity_name_map))
			continue;
		auto curr_name = curr_entity->GetPlayerName(entity_name_map);
		//	if (testing)
		//	std::printf("curr_name %s \n", curr_name);

		if (!SDK1::IsValidPtr((void*)curr_name))
			continue;

		auto curr_health = SDK1::Read<int>((uintptr_t)curr_entity + SDK1::offsets::entity_health);/* curr_entity->GetHealth();*/
		if (curr_health < 1)
			continue;

		//	std::printf("curr_health %f \n", curr_health);

			//	if (testing)
			//	std::printf("curr_health %i \n", curr_health);
		//

		auto curr_max_health = SDK1::Read<int>((uintptr_t)curr_entity + SDK1::offsets::entity_maxhealth);/* curr_entity->GetHealth();*/
		//std::printf("curr_max_health %f \n", curr_max_health);




		auto curr_shield = SDK1::Read<int>((uintptr_t)curr_entity + SDK1::offsets::entity_shield);/* curr_entity->GetHealth();*/
		//if (testing)
		//std::printf("curr_shield %i \n", curr_shield);
		//std::printf("curr_shield %f \n", curr_shield);

		auto curr_max_shield = SDK1::Read<int>((uintptr_t)curr_entity + SDK1::offsets::entity_maxshield);/* curr_entity->GetHealth();*/

		//	std::printf("curr_max_shield %i \n", curr_max_shield);

		auto is_visible = curr_entity->IsPlayerVisible();
		//	std::printf("is_visible %i \n", is_visible);
		//std::printf("curr_max_shield %f \n", curr_max_shield);


		if (is_visible)
			valid_players.push_back(curr_entity);


		// ESP BOX
		if (Globals::Visuals::esp_player_box)
		{ // test dll
			ImU32  colorVis;

			if (is_visible)
				colorVis = IM_COL32(0, 255, 0, 255);
			if (!is_visible)
				colorVis = IM_COL32(255, 0, 0, 255);

			auto entityHead = curr_entity->GetBonePositionById(SDK1::cBoneId::head);

			Vector3 S_entityHead;
			if (!SDK1::WorldToScreen(view_matrix, entityHead, S_entityHead))
				continue;


			float hight = S_entityHead.distance(screen_position);
			float width = hight / 2.f;


			if (Globals::Visuals::stand_box == true) {



				DrawRect(S_entityHead.x - (width / 2), S_entityHead.y, width, hight, 3, colorVis);
			}

			if (Globals::Visuals::corner_box == true) {
				DrawCornerBox(S_entityHead.x - (width / 2), S_entityHead.y, width, hight, 3, colorVis);
			}


		}

		if (Globals::Visuals::esp_player_glow)
		{


			VALO->AddText({ screen_position.x,screen_position.y }, colorVis3, curr_name);
			VALO->AddText({ screen_position.x,screen_position.y + 15 }, colorVis1, (_("HP :") + std::to_string((int)curr_health)).c_str());
			VALO->AddText({ screen_position.x,screen_position.y + 30 }, colorVis2, (_("Shield :") + std::to_string((int)curr_shield)).c_str());


		}


		if (Globals::Visuals::esp_player_Distance)
		{



			VALO->AddText({ screen_position.x,screen_position.y - 15 }, colorVis1, (_(" ") + std::to_string((int)distance_relative)).c_str());



		}


		if (Globals::Visuals::esp_player_skeleton)
		{
			ImU32  colorVis;

			if (is_visible)
				colorVis = IM_COL32(0, 255, 0, 255);
			if (!is_visible)
				colorVis = IM_COL32(255, 0, 0, 255);

			render_player_skeletal(view_matrix, curr_entity, colorVis);
		}
	}


	if (Globals::Visuals::aimbot)
	{


		main_aimbot(local_player, view_matrix, entity_list);
	}

	if (Globals::Visuals::TriggetBot)
	{

		Trigger(local_player, view_matrix, entity_list);
	}


	/*if (Globals::Visuals::aimbot1)
   {


	   main_aimbot1(local_player, view_matrix, entity_list);
   }*/

	valid_players.clear();
	return;
}
bool umabez;
int vezesMenu = 0;

uintptr_t do_fixed_update_ptr, client_input_ptr;

HRESULT __stdcall my_present(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT flags)
{
	if (!variables::renderer_intialized)
	{
		rendering::temp::g_pSwapChain = pSwapChain;

		if (SUCCEEDED(rendering::temp::g_pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)(&rendering::temp::g_pd3dDevice))))
		{

			rendering::temp::g_pd3dDevice->GetImmediateContext(&rendering::temp::g_pd3dDeviceContext);
		}

		ID3D11Texture2D* renderTargetTexture = nullptr;
		if (SUCCEEDED(rendering::temp::g_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<PVOID*>(&renderTargetTexture))))
		{


			if (SUCCEEDED(rendering::temp::g_pd3dDevice->CreateRenderTargetView(renderTargetTexture, NULL, &rendering::temp::g_mainRenderTargetView)))
			{

			}

			renderTargetTexture->Release();
		}

		UINT viewport_count = 1;
		D3D11_VIEWPORT viewport;
		rendering::temp::g_pd3dDeviceContext->RSGetViewports(&viewport_count, &viewport);
		variables::game_screen_X = viewport.Width;
		variables::game_screen_Y = viewport.Height;


		ImGui::CreateContext();
		ImGui_ImplDX11_Init(rendering::temp::g_pd3dDevice, rendering::temp::g_pd3dDeviceContext);
		rendering::Renderer::GetInstance()->Initialize();
		ImGui_ImplDX11_CreateDeviceObjects();
		MenuDesignInterface();

		variables::renderer_intialized = true;
	}

	rendering::temp::g_pd3dDeviceContext->OMSetRenderTargets(1, &rendering::temp::g_mainRenderTargetView, NULL);



	ImGui_ImplDX11_NewFrame();

	rendering::Renderer::GetInstance()->BeginScene();

	if (userinterface::settings::esp)
		main_visuals();

	rendering::Renderer::GetInstance()->EndScene();

	if (GetKeyState(VK_INSERT) & 1)
	{
		userinterface::settings::esp = 1;
		resetcondig = false;
		toggle_menu = true;
		ImGui::GetIO().MouseDrawCursor = true;
	}
	else {
		toggle_menu = false;
		ImGui::GetIO().MouseDrawCursor = false;
	}

	/*if (GetKeyState(VK_NUMPAD9) & 1)
		TESTTTT = 1; you know medal.tv
	else
		TESTTTT = 0;*/


	if (resetcondig)
	{
		userinterface::settings::esp = false;
	}
	if (toggle_menu)
		BuildMenuMain();


	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	return rendering::o_pPresent(pSwapChain, SyncInterval, flags);
}

HRESULT __stdcall rSZE(IDXGISwapChain* pThis, UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags) {
	if (rendering::temp::g_mainRenderTargetView) {
		rendering::temp::g_pd3dDeviceContext->OMSetRenderTargets(0, 0, 0);
		rendering::temp::g_mainRenderTargetView->Release();
	}
	//SetWindowDisplayAffinity(hWnd2, WDA_EXCLUDEFROMCAPTURE);

	HRESULT hr = rendering::resize_buffers_original(pThis, BufferCount, Width, Height, NewFormat, SwapChainFlags);
	//SetWindowDisplayAffinity(hWnd2, WDA_EXCLUDEFROMCAPTURE);
	ID3D11Texture2D* pBuffer;
	pThis->GetBuffer(0, __uuidof(ID3D11Texture2D),
		(void**)&pBuffer);

	rendering::temp::g_pd3dDevice->CreateRenderTargetView(pBuffer, NULL,
		&rendering::temp::g_mainRenderTargetView);

	pBuffer->Release();

	rendering::temp::g_pd3dDeviceContext->OMSetRenderTargets(1, &rendering::temp::g_mainRenderTargetView, NULL);

	// Set up the viewport.
	D3D11_VIEWPORT vp;
	vp.Width = Width;
	vp.Height = Height;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;
	rendering::temp::g_pd3dDeviceContext->RSSetViewports(1, &vp);
	return hr;
}

bool GetStringFromRegistry(HKEY hKey, const std::string& subKey, const std::string& valueName, std::string& data) {
	HKEY hSubKey;
	if (RegOpenKeyEx(hKey, subKey.c_str(), 0, KEY_QUERY_VALUE, &hSubKey) != ERROR_SUCCESS) {
		std::wcerr << L"Error opening registry key." << std::endl;
		return false;
	}

	DWORD dataSize = 0;
	if (RegQueryValueEx(hSubKey, valueName.c_str(), nullptr, nullptr, nullptr, &dataSize) != ERROR_SUCCESS) {
		std::wcerr << L"Error querying registry value size." << std::endl;
		RegCloseKey(hSubKey);
		return false;
	}

	std::vector<char> buffer(dataSize / sizeof(char) + 1);

	if (RegQueryValueEx(hSubKey, valueName.c_str(), nullptr, nullptr, reinterpret_cast<LPBYTE>(buffer.data()), &dataSize) != ERROR_SUCCESS) {
		std::wcerr << L"Error querying registry value." << std::endl;
		RegCloseKey(hSubKey);
		return false;
	}

	RegCloseKey(hSubKey);

	data = buffer.data();
	return true;
}

HMODULE module12;
int MainThread()
{
	variables::window_handle = FindWindowA(0, variables::window_class_name);


	static bool fff = false;

	//AllocConsole();
	//freopen("CONIN$", "r", stdin);
	//freopen("CONOUT$", "w", stdout);



	//	ss = (TestS)((DWORD64)GetModuleHandleA("GameAssembly.dll") + 0x531F00); si

	TCHAR fileName[MAX_PATH + 1];
	DWORD charsWritten = GetModuleFileName(NULL, fileName, MAX_PATH + 1);

	std::string expectedPath(fileName);

	if (charsWritten != 0)
	{
		//MessageBoxA(0, 0, 0, 0);

		if (expectedPath.find(xorstr_("r5apex.exe")) != std::string::npos)
		{

			//MessageBoxA(0, "ok", "ok", 0);

			if (rendering::CreateDeviceD3D(variables::window_handle) == E_FAIL)
			{
				rendering::CleanupDeviceD3D();
				return 0;
			}


			Sleep(200);
			const auto pSwapchain =
				reinterpret_cast<std::uintptr_t*>(rendering::g_pSwapChain);

			const auto pSwapChainVT =
				reinterpret_cast<std::uintptr_t*>(pSwapchain[0]);


			rendering::o_pPresent = reinterpret_cast<rendering::tD3D11Present>(pSwapChainVT[8]);

			rendering::resize_buffers_original = reinterpret_cast<rendering::ResizeBuffers>(pSwapChainVT[13]);

			oriWndProc = (WNDPROC)SetWindowLongPtr(variables::window_handle, GWLP_WNDPROC, (DWORD_PTR)hWndProc);

			auto hooker_handler = new utils::h5o5ok5s::Hooker();
			//il2cpp1::init();
			Sleep(200);
			hooker_handler->HookFunction(reinterpret_cast<PVOID*>(&rendering::o_pPresent), my_present);
			hooker_handler->HookFunction(reinterpret_cast<PVOID*>(&rendering::resize_buffers_original), rSZE);

			HANDLE unn;
			unn = CreateMutexA(NULL, FALSE, xorstr_("N48uW9AzsS9wGOiLSStlJXlyB"));


			rendering::g_pd3dDevice->Release();
			rendering::g_pd3dDeviceContext->Release();
			rendering::g_pSwapChain->Release();

		}
		else
			FreeLibraryAndExitThread(module12, 0);
	}
	return 0;
}

extern "C" __declspec(dllexport)
bool __stdcall DllMain(HMODULE module1, std::uint32_t call_reason, void*)
{

	if (call_reason == DLL_PROCESS_ATTACH)
	{
		//module12 = module1;
		//LoadLibrary(xorstr_("tier0_s64.dll"));
		CreateThreadSafe(MainThread);

	}

	return true;
}


