#pragma once
#include <cstdint>
#include <Windows.h>
#include <Psapi.h>
#include <cstdint>
#include "Classes.hpp"

typedef std::intptr_t game_base;
typedef std::uint32_t game_offset;
namespace SDK
{
	namespace variables
	{
		std::intptr_t game_assembly_base;
		MODULEINFO game_assembly_mdlinfo;

		std::intptr_t unity_player_base	;
		MODULEINFO unity_player_mdlinfo;

		BaseNetworkable* base_networkable_addr = nullptr;
		void* game_object_manager_addr = nullptr;

		unsigned int game_screen_X;
		unsigned int game_screen_Y;

		HWND window_handle;
 
		LPCSTR window_class_name = "Apex Legends";
		LPCSTR window_wnd_name = "";

		HMODULE current_module_handle;

		bool renderer_executed;
		bool renderer_intialized;
		bool renderer_exit;

		float clearColor[4] = { 0.0f, 0.0f, 0.0f, 0.0f };

		static constexpr std::uintptr_t discord_present = 0x2D7338;
		static std::uintptr_t get_pos_injected_fn;
		static std::uintptr_t ray_cast_fn;
		static std::uintptr_t physics_scene_fn;

		namespace offsets
		{
		
		}

		namespace temp
		{
			BaseCamera* camera_object;
		}
	}
}namespace Globals
{
	static void* DllInstance = nullptr;
	static bool IsClosing = false;
	static bool Open = 1;
	static int Tab = 0;

	namespace Misc
	{
		static bool TurnCap = false;
		static bool SuperSprint = false;
		static bool VoiceSpam = false;
		static bool InstantSprintRegen = false;
		static bool MakeAdmin = false;
	}

	namespace Visuals
	{
		int bone_limiter;
		static bool Enabled = 1;
		static bool crosshair = 1;
		static bool show_fov = 1;

		static bool fov_modifier = 0;
		static bool Boxes = false; static bool esp_hideteam = false;
		static bool Corners = false; static bool debug_mode = false;
		static bool esp_item_glow = false;
		static int aim_Key = VK_RBUTTON;
		static int bone_choice;
		static int bone_choice2 = 5;

		static int esp_item_glow_type_choice;
		static bool esp_player_glow = 0;
		static bool esp_player_Distance = 0;
		static bool speclist = 0;
		static bool testtt = 0;
		static bool aimbot_predictiontest = 0;
		static bool aimbot_prediction = 0;
		static bool aimbot_onlyshooting = false;
		static bool cap_aimbot_distance = false;
		static bool esp_player_skeleton = 1;
		static bool esp_player_box = false; // is it good?
		static bool stand_box = 1;
		static bool corner_box = 1;
		static float fov_scale = 3.f;
		static float fov_value = 100;
		static float esp_player_glow_colour[4] = { 0.f, 1.f, 0.0f, 1.f };
		static 	float esp_item_glow_colour[4] = { 0.f, 1.f, 0.0f, 1.f };
		static 	int esp_glow_item_bordersize = 70;
		static	int esp_glow_item_transparentlevel = 75;
		static	bool rcs_standalone = 0;
		static	bool aimbot = 1;
		static	bool TriggetBot = 1;
		static	bool aimbot1 = 0;
		static	bool aimbot2 = 0;
		static	float rcs_factor = 10.f;
		static 	float esp_weapon_glow_colour[4] = { 0.f, 1.f, 0.0f, 1.f };
		static float esp_heal_glow_colour[4] = { 0.f, 1.f, 0.0f, 1.f };
		static 	float esp_equipment_glow_colour[4] = { 0.f, 1.f, 0.0f, 1.f };
		static 	float esp_throwables_glow_colour[4] = { 0.f, 1.f, 0.0f, 1.f };
		static float esp_attachments_glow_colour[4] = { 0.f, 1.f, 0.0f, 1.f };
		static bool Snaplines = false;
		static bool FilledBoxes = false;
		static bool DisplayInfo = false;
		static bool DisplayHealth = false;
		static bool DisplayNames = 1;
		static bool aimbot_visiblity_check = 1;
		static bool rcs_aimbot = 1;
		static bool aimbot_smoothing = 1;
		static int smooth_value = 28;

	}
}