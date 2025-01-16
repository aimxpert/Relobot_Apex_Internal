#pragma once
#include <Windows.h>
#include <string>
#include <vector>
#include <cstdint>
#include "vector.hpp"
#include "RustStructs.h"
#include "Globals.h"
#include "il2cpp_lib.hpp"
#include <iostream>
#include "xor.h"
#include "offsets.h"
#include "Utils.h"
#include <array>
#include <d3d9types.h>
#include "imgui/imgui.h"
#include "menu_config.h"
#include "laze.h"
using namespace SDK;
class Time;
class AttackEntity;
bool HealthBar;
bool BoxTipess;
bool healthbar;
bool isEli;
#define M_PI_2 1.57079632679489661923
bool resetcondig = false;
int hpbar = 0;
int boxtype = 0;
 
float boxesvisible[4] = { 0, 1, 0, 1 };
float boxesinvisible[4] = { 1, 0, 0, 1 };
namespace string12
{

	inline char buffer[512];

	inline const char* format(const char* fmt, ...) {
		va_list args;
		va_start(args, fmt);
		LI_FN(vsnprintf)(buffer, 512, fmt, args);
		va_end(args);
		return buffer;
	}
}

bool rainbowbox = false;
inline auto screen_transform(utils::maths::vec3_t wrld) -> utils::maths::vec3_t;

#define pent ;
struct weapon_data {
	float initial_velocity;
	float gravity_modifier;
	float drag;
	float initial_distance;
};
bool interactive_debug = 0;
bool interactive_debug1 = 1;
bool interactive_debug2 = 0;
bool interactive_debug3 = 0;
bool interactive_debug4 = 0;
bool interactive_debug5 = 0;
bool interactive_debug6 = 0;
bool interactive_debug7 = 0;
bool interactive_debug8 = 0;
bool interactive_debug9 = 0;
bool antideathbarrier = 0;

bool targetbehindwall = false;
bool thick_bullet = false;
bool podes213 = false;
bool autofarm = false;
inline utils::maths::vec3_t best_lean = utils::maths::vec3_t(0, 0, 0);
 float nextActionTime = 0, period = 1.4721, last_gesture_rpc = 0.f, last_revive_rpc = 0.f, last_refill_rpc = 0.f, last_fwd_fly = 0.f;
class BaseCamera;
class BasePlayer;
class Model;
utils::maths::vec3_t __stdcall get_skeletal_world(Model* entity_model, SDK::eBones bone, bool& status);
utils::maths::vec3_t get_local_head(BasePlayer* local_player);

BaseCamera* base_camera = nullptr;
BasePlayer* local_player = nullptr;
float fixedtimelastshot;
float desyncTime;
float thickness=1.f;
bool psilentmelee;
bool psilent=0;
int psilentkey=VK_CAPITAL;
 SDK::utils::maths::vec3_t get_position();

namespace mem {

	template<typename t>
	t read(uintptr_t addr) {
		if (addr < 0xffffff)
			return t();
		if (addr > 0x7fffffff0000)
			return t();

		return *reinterpret_cast<t*>(addr);
	}

	template<typename t>
	bool write(uintptr_t addr, t buffer) {
		*reinterpret_cast<t*>(addr) = buffer;
		return true;
	}
	//uintptr_t hook_virtual_function(const char* classname, const char* function_to_hook, void* target, const char* name_space);
}
namespace System {
	template<typename T = void*>
	class Array {
	public:
		uint32_t size() {
			if (!this || (uintptr_t)this < 0xFFFFFFFF || (uintptr_t)this > 0x1000000000000000) return 0;
			return *reinterpret_cast<uint32_t*>(this + 0x18);
		}
		T get(int idx) {
			__try {
				if (!this || (uintptr_t)this < 0xFFFFFFFF || (uintptr_t)this > 0x1000000000000000) return T{};




				auto ss = *reinterpret_cast<T*>(this + (0x20 + (idx * 0x8)));
				if (ss)
					return ss;

			}
			__except (1) { resetcondig = true;
				resetcondig = true;

				printf("[matrix]: Exception occured in get\n");

			}
		}
		void add(int idx, T value) {
			if (!this || (uintptr_t)this < 0xFFFFFFFF || (uintptr_t)this > 0x1000000000000000) return;
			*reinterpret_cast<T*>(this + (0x20 + (idx * 0x8))) = value;
		}


	};

	template<typename T = void*, typename K = void*>
	class ListDictionary
	{
	public:
		K get_value(uint32_t idx) {
			auto listhead = *reinterpret_cast<uintptr_t*>((uintptr_t)this + 0x10);
			if (idx > 0) {
				auto n = *reinterpret_cast<uintptr_t*>(listhead + (idx * 0x20));
				return *reinterpret_cast<K*>(n + 0x18);
			}
			return mem::read<K>(listhead + 0x18);
		}
		T get_key(uint32_t idx) {
			auto listhead = *reinterpret_cast<uintptr_t*>((uintptr_t)this + 0x10);
			if (idx > 0) {
				auto n = *reinterpret_cast<uintptr_t*>(listhead + (idx * 0x20));
				return *reinterpret_cast<T*>(n + 0x10);
			}
			return mem::read<T>(listhead + 0x10);
		}
		int32_t size() {
			return *reinterpret_cast<int32_t*>((uintptr_t)this + 0x1C);
		}
	};

	class List {
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

			auto size = mem::read<int>(value + 0x10);
			if (!size)
				return 0;
		}

		template <typename T>
		T get_buffer() {
			auto value = get_value<uintptr_t>();

			return *reinterpret_cast<uintptr_t*>(value + 0x18);
		}
	};
	template<typename T = void*, typename K = void*>
	class list {
	public:
		T get(uint32_t idx)
		{
			const auto internal_list = reinterpret_cast<uintptr_t>(this + 0x20);
			if (!internal_list) return 0;
			return *reinterpret_cast<T*>(internal_list + idx * sizeof(T));
		}

		T get_value(uint32_t idx)
		{
			const auto list = *reinterpret_cast<uintptr_t*>((uintptr_t)this + 0x10);
			if (!list) return 0;
			const auto internal_list = list + 0x20;
			return *reinterpret_cast<T*>(internal_list + idx * sizeof(T));
		}

		T operator[](uint32_t idx) { return get(idx); }

		const uint32_t get_size() { return *reinterpret_cast<uint32_t*>((uintptr_t)this + 0x18); }

		template<typename F>
		void for_each(const F callback)
		{
			for (uint32_t i = 0; i < get_size(); i++) {
				auto object = this->get(i);
				if (!object)
					continue;
				callback(object, i);
			}
		}

		void add(int idx, T value) {
			if (!this || (uintptr_t)this < 0xFFFFFFFF || (uintptr_t)this > 0xF000000000000000) return;
			*reinterpret_cast<T*>(this + (0x20 + (idx * 0x8))) = value;
		}
	};

	class String {
	public:
		char zpad[0x10];
		int size;
		wchar_t str[128 + 1];
		String() {}
		String(const wchar_t* st) {
			size = min(wcslen((wchar_t*)st), 128);
			for (int i = 0; i < size; i++) {
				str[i] = st[i];
			}
			str[size] = 0;
		}
		static String* a(const char* s) {
			return (String*)il2cpp_lib::new_string(s);
		}
	};
}
enum class Signal;
class Transform1;
class Bounds;
	class col;
class Object;
class Component;
class MonoString;
class Behaviour;
class FacepunchBehaviour;
class BaseMonoBehaviour;
class MonoBehaviour;
class Networkable;
class BaseNetworkable;
class GameObject;
class Transform;
class BaseEntity;
class Item;
class AttackEntity;
class BaseMelee;
class BaseProjectile;
class Bone;
class BoneCache;
class Model;
class ModelState;
class BasePlayer;
class HitTest;
class Shader;
class Material;
class Renderer;
class PlayerBelt;
class Terrain;
class Projectile;
class PlayerInventory;
class Magazine;
class TerrainHeightMap;
class TerrainCollision;
class TerrainMeta;
class InputState;
class ViewModel;
class SkinnedMultiMesh;
class Collider;
class CapsuleCollider;
class PlayerVoiceRecorder;
class BaseMovement;
class RaycastHit;
class BaseMountable;
class BaseVehicle;
class HeldEntity;
class TimeWarning;
class Object;
class Component;
class Behaviour;
class FacepunchBehaviour;
class BaseMonoBehaviour;
class MonoBehaviour;
class Networkable;
class BaseNetworkable;
class GameObject;
class Transform;
class BaseEntity;
class Item;
class AttackEntity;
class BaseMelee;
class BaseProjectile;
class Bone;
class BoneCache;
class Model;
class ModelState;
class BasePlayer;
class HitTest;
class Shader;
class Material;
class Renderer;
class PlayerBelt;
class Terrain;
class Projectile;
class PlayerInventory;
class Magazine;
class TerrainHeightMap;
class TerrainCollision;
class TerrainMeta;
class InputState;
class ViewModel;
class SkinnedMultiMesh;
class Collider;
class CapsuleCollider;
class PlayerVoiceRecorder;
class BaseMovement;
class RaycastHit;
class BaseMountable;
class BaseVehicle;
class HeldEntity;
class TimeWarning;
class Bounds;
struct unk2;
struct unk2;
const class Time;
class TickInterpolator;
class TickInterpolator;
struct TimeAverageValueData;
class TickHistory;
namespace misc {
	inline utils::maths::vec3_t best_target = utils::maths::vec3_t(0, 0, 0);
	inline utils::maths::vec3_t v_LastSentTickPos = utils::maths::vec3_t::Zero();
	inline float g_fLastShotTime = 0.f;
	inline bool autoshot = 0;
	inline bool wants_shoot = 0;



}

const class Sprite {
public:

};
enum class BuildingGrade;
enum class PlayerFlags;
class aim_target {
public:
	SDK::utils::maths::vec3_t pos;

	BasePlayer* ent = 0;
 
	float distance = 5000;
	float fov = 1;
	float maxfov = 0;

	int network_id;

	bool is_heli = false;
	bool visible = false;
	bool sleeping = false;
	bool teammate = false;
	bool found = false;

	/*Velocity related shit*/
	SDK::utils::maths::vec3_t avg_vel = SDK::utils::maths::vec3_t(0, 0, 0);
	std::vector<SDK::utils::maths::vec3_t> velocity_list = {};
	float last_frame = 0.f; // overwrite every fixedtime + deltatime

	bool operator<(const aim_target& b) {
		if (fov == maxfov) {
			return distance < b.distance;
		}
		else {
			return fov < b.fov;
		}
	}
	void Reset() {
		visible = false;
		sleeping = false;
		is_heli = false;
		teammate = false;
		found = false;
		avg_vel = { 0,0,0 };
		velocity_list.clear();
		last_frame = 0.f;
		network_id = -1;
		distance = 5000;
		fov = 0;
		ent = 0;
		pos = { 0,0,0 };
	}
};
aim_target best_target;

class aim_target1 {
public:
	SDK::utils::maths::vec3_t pos;

	BasePlayer* ent = 0;
 
	float distance = 5000;
	float fov = 1;
	float maxfov = 0;

	int network_id;

	bool is_heli = false;
	bool visible = false;
	bool sleeping = false;
	bool teammate = false;
	bool found = false;

	/*Velocity related shit*/
	SDK::utils::maths::vec3_t avg_vel = SDK::utils::maths::vec3_t(0, 0, 0);
	std::vector<SDK::utils::maths::vec3_t> velocity_list = {};
	float last_frame = 0.f; // overwrite every fixedtime + deltatime

	bool operator<(const aim_target& b) {
		if (fov == maxfov) {
			return distance < b.distance;
		}
		else {
			return fov < b.fov;
		}
	}
	void Reset() {
		visible = false;
		sleeping = false;
		is_heli = false;
		teammate = false;
		found = false;
		avg_vel = { 0,0,0 };
		velocity_list.clear();
		last_frame = 0.f;
		network_id = -1;
		distance = 5000;
		fov = 0;
		ent = 0;
		pos = { 0,0,0 };
	}
};
aim_target1 best_target1;

class aim_targetFarm {
public:
	 
	SDK::utils::maths::vec3_t world_distanceFarm;
	BasePlayer* entFARM = 0;

	void Reset() {

		entFARM = 0;
 		world_distanceFarm = { 0,0,0 };
	}
};
aim_targetFarm best_targetFARM;


enum class HitTestType
{
	Generic = 0,
	ProjectileEffect = 1,
	Projectile = 2,
	MeleeAttack = 3,
	Use = 4,
};



enum class PlayerFlags
{
	Unused1 = 1,
	Unused2 = 2,
	IsAdmin = 4,
	ReceivingSnapshot = 8,
	Sleeping = 16,
	Spectating = 32,
	Wounded = 64,
	IsDeveloper = 128,
	Connected = 256,
	ThirdPersonViewmode = 1024,
	EyesViewmode = 2048,
	ChatMute = 4096,
	NoSprint = 8192,
	Aiming = 16384,
	DisplaySash = 32768,
	Relaxed = 65536,
	SafeZone = 131072,
	ServerFall = 262144,
	Workbench1 = 1048576,
	Workbench2 = 2097152,
	Workbench3 = 4194304,
};
enum class ModelState_Flag
{
	Ducked = 1,
	Jumped = 2,
	OnGround = 4,
	Sleeping = 8,
	Sprinting = 16,
	OnLadder = 32,
	Flying = 64,
	Aiming = 128,
	Prone = 256,
	Mounted = 512,
	Relaxed = 1024,
	Crawling = 4096,
};

class default_t
{
public:
	template<typename T>
	operator T() const { return T(); }
};
default_t const defaultt = default_t();
#define NP(type) type nonptr = defaultt; if (!this || (uintptr_t)this <= 0xFFFFFFFF || (uintptr_t)this >= 0x7fffffff0000) return nonptr;
#define FIELD(offset,name,type)  type& name() { \
	__try { NP(type) \
	return *reinterpret_cast<type*>((uintptr_t)this + offset); \
	} __except(1) { type nonptr = defaultt; return nonptr; } }



enum class BuildingGrade
{
	None = -1,
	Twigs = 0,
	Wood = 1,
	Stone = 2,
	Metal = 3,
	TopTier = 4,
	Count = 5
};
enum class Signal {
	Attack,
	Alt_Attack,
	DryFire,
	Reload,
	Deploy,
	Flinch_Head,
	Flinch_Chest,
	Flinch_Stomach,
	Flinch_RearHead,
	Flinch_RearTorso,
	Throw,
	Relax,
	Gesture,
	PhysImpact,
	Eat,
	Startled
};
class BaseEntity;
bool IsValidPtr31(void* pointer)
{
	if (!pointer)
		return false;
	//0
	if (pointer < (void*)0xFFFFFFFF)
		return false;
	//0x6f575100676e6972
	if (pointer > (void*)0x7FFFFFFFFFFFFF)
		return false;

	return true;
}
bool ValidPtr(void* pointer)
{
	if (!pointer)
		return false;
	//0
	if (pointer < (void*)0xFFFFFFFF)
		return false;
	//0x6f575100676e6972
	if (pointer > (void*)0x7FFFFFFFFFFFFF)
		return false;

	return true;
}
struct weapon_stats_t {
	float initial_velocity;
	float gravity_modifier;
	float drag;
	float initial_distance;
};

enum weapon_types : int32_t {
	spear_stone = 1602646136,
	spear_wooden = 1540934679,
	hatchet = -1252059217,
	stonehatchet = -1583967946,
	pickaxe = -1302129395,
	stonepickaxe = 171931394,
	salvageaxe = -262590403,
	cleaver = -1978999529,
	hammer = -1506397857,
	icepick = -1780802565,
	sword = 1326180354,
	boneknife = 1814288539,
	butcherknife = -194509282,
	combatknife = 2040726127,
	rock = 963906841,
	snowball = -363689972
};

enum AmmoType : int32_t {
	shotgun = -1685290200,
	shotgun_slug = -727717969,
	shotgun_fire = -1036635990,
	shotgun_handmade = 588596902,

	rifle_556 = -1211166256,
	rifle_556_hv = 1712070256,
	rifle_556_fire = 605467368,
	rifle_556_explosive = -1321651331,

	pistol = 785728077,
	pistol_hv = -1691396643,
	pistol_fire = 51984655,

	arrow_wooden = -1234735557,
	arrow_hv = -1023065463,
	arrow_fire = 14241751,
	arrow_bone = 215754713,

	nailgun_nails = -2097376851,

	rocket_hv = -1841918730,
	rocket_incen = 1638322904,
	rocket_basic = -742865266
};

namespace protections {
	int flyhack_protection = 3;
	int speedhack_protection = 2;
	int eye_protection = 4;
	int projectile_protection = 6;

	float speedhack_slopespeed = 10.0f;
	float speedhack_forgiveness_inertia = 10.0f;
	float speedhack_forgiveness = 2.0f;
	float speedhack_penalty = 0.0f;
	bool speedhack_reject = true;

	float flyhack_penalty = 100.0f;
	bool flyhack_reject = true;

	float eyehack_penalty = 100.0f;
	float eye_penalty = 0.0f;

	int debuglevel = 4;
}

 
 
namespace memory
{

	template<typename t = uintptr_t>
	t read(uintptr_t address)
	{
		if (!address)
		{
			return t();
		}
		else if (address < 0xffffff)
		{
			return t();
		}
		else if (address > 0x7fffffff0000)
		{
			return t();
		}
		else
		{
			return *reinterpret_cast<t*>(address);
		}
	}

	template<typename t>
	bool write(uintptr_t address, t value)
	{
		*reinterpret_cast<t*>(address) = value;
		return true;
	}
}
namespace System {



	class string {
	public:
		char zpad[0x10];
		int size;
		wchar_t str[128 + 1];
		string() {}
		string(const wchar_t* st) {
			size = min(std::wcslen((wchar_t*)st), 128);
			for (int i = 0; i < size; i++) {
				str[i] = st[i];
			}
			str[size] = 0;
		}
		static string* a(const char* s) {
			return (string*)il2cpp_lib::string_new_wrapper(s);
		}
	};
}



#define ENGINECALL
template<typename t>
t readf1(uintptr_t addr) {
	if (addr < 0xfffff)
		return t();
	if (addr > 0x7FFFFFFFFFFF)
		return t();

	return *reinterpret_cast<t*>(addr);
}

namespace managed_system
{
	class string
	{
	public:
		char zpad[0x10]{ };
		int size{ };
		wchar_t buffer[128 + 1];
	public:
		string(const wchar_t* st)
		{
			size = min(utl::crt::string::wcslen(st), 128);
			for (int idx = 0; idx < size; idx++)
			{
				buffer[idx] = st[idx];
			}
			buffer[size] = 0;
		}
	};

	template<typename type>
	class list
	{
	public:
		type get(std::uint32_t idx)
		{
			const auto internal_list = reinterpret_cast<std::uintptr_t>(this + 0x20);
			return *reinterpret_cast<type*>(internal_list + idx * sizeof(type));
		}

		type value(std::uint32_t idx)
		{
			const auto list = *reinterpret_cast<std::uintptr_t*>(this + 0x10);
			const auto internal_list = list + 0x20;
			return *reinterpret_cast<type*>(internal_list + idx * sizeof(type));
		}

		auto size() -> const std::uint32_t { return *reinterpret_cast<std::uint32_t*>(this + 0x18); }
	};

	class list_dictionary
	{
	public:
		template <typename type>
		auto value() -> type
		{
			auto list = *reinterpret_cast<std::uintptr_t*>(this + 0x10);
			if (!list)
				return {};

			auto value = *reinterpret_cast<type*>(list + 0x28);
			if (!value)
				return {};

			return value;
		}

		auto size() -> int
		{
			auto val = value< std::uintptr_t >();
			if (!val)
				return {};

			auto size = *reinterpret_cast<int*>(val + 0x10);
			if (!size)
				return {};

			return size;
		}

		template <typename type>
		auto buffer() -> type
		{
			auto val = value< std::uintptr_t >();
			return *reinterpret_cast<std::uintptr_t*>(val + 0x18);
		}
	};
}

namespace SDK
{


	namespace offsets1
	{



		// TOD_Sky
		static constexpr auto SkyTOD_CycleParameters = 0x38;
		static constexpr auto SkyTOD_CycleParametersHours = 0x10;

		static constexpr auto SkyTOD_DayParameters = 0x50;
		static constexpr auto SkyTOD_DayParametersAmbientMultipler = 0x50;
		static constexpr auto SkyTOD_DayParametersReflectionMultipler = 0x54;

		// BaseCamera
		static constexpr auto base_camera_view_matrix = 0x2E4;
		static constexpr auto base_camera_position = 0x42C;

		// BaseEntity
		static constexpr auto entity_model = 0xB8;//0xB0;//0xB0; //	public Model model;
		static constexpr auto entity_is_visible = 0x138;//0x120;		//protected bool isVisible; // 0xC8

		//public Model model; // 0x118
		//public BaseEntity.Flags flags; // 0x120
		//protected string _name; // 0x138


		// BasePlayer
		static constexpr auto player_health = 0x24C;//OK //	protected float _health; // 0x22C

		static constexpr auto lifestate1 = 0x244;//	public BaseCombatEntity.LifeState lifestate; 
		static constexpr auto EntityRefmounted = 0x778;//private EntityRef mounted;
		static constexpr auto player_max_health = 0x250;//OK //BaseCombatEntity : _maxHealth
		static constexpr auto player_model = 0x130;//0xB0;
		//public BasePlayer.CameraMode currentViewMode; // 0x470
		//public BasePlayer.CameraMode selectedViewMode; // 0x474
		static constexpr auto player_current_viewmode = 0x828;//0x570;//public PlayerEyes eyes; // 0x5C0???
		static constexpr auto player_selected_viewmode = 0x828;//0x570;//public PlayerEyes eyes; // 0x5C0???
		//public BasePlayer.CameraMode currentViewMode; // 0x470
		static constexpr auto player_model_derivate = 0x5E8;//PlayerModel playerModel; // 0x490 222


		static constexpr auto player_sleeping = 0x651;//private bool wasSleeping; // 0x4D9 ??
		//public ulong currentTeam; // 0x4F8
		//public PlayerTeam clientTeam; // 0x500
		static constexpr auto player_team = 0x710;//ok //clientTeam 0x04F8??
		static constexpr auto player_activeitem = 0x740;//ok //	private uint clActiveItem; // 0x5D0 
		//public ModelState modelState; // 0x548 
		static constexpr auto player_flags = 0x820;//ok//	public BasePlayer.PlayerFlags playerFlags; // 0x688


		static constexpr auto player_inventory = 0x830;//ok	public PlayerInventory inventory; // 0x698

		static constexpr auto player_input = 0x608;//	public PlayerInput input; // 0x4E0

		static constexpr auto player_movement = 0x610;//ok public BaseMovement movement;
		static constexpr auto player_collision = 0x5F0;//ok
		static constexpr auto player_belt = 0x858;//ok			public PlayerBelt Belt; // 0x6C0

		static constexpr auto player_name = 0x880;//_displayName
		//public bool equippingBlocked; // 0x64C TODO
		//public float eggVision; // 0x650 TODO
		static constexpr auto eggVision = 0x650;

		// EntityModel
		static constexpr auto ent_model_root_bone = 0x20;

		static constexpr auto model_newvelocity = 0x224;
		static constexpr auto model_is_visible = 0x228;
		static constexpr auto model_is_localplayer = 0x239;//nternal bool isLocalPlayer; // 0x299
		static constexpr auto model_skin_mesh = 0x270;//0x218;//private SkinnedMultiMesh _multiMesh; // 0x270		

		// SkinnedMultiMesh
		//internal bool IsVisible; // 0x19
		//public Skeleton skeleton; // 0x20
		//public string[] boneNames; // 0x50

		//Model
		static constexpr auto mesh_bone_dict = 0x48; //internal BoneDictionary boneDict; // 0x58
		//public Transform[] boneTransforms; // 0x48

		// BoneDictionary
		static constexpr auto bone_transform_array = 0x20;// 0x20;//ransform[] transforms
		//public string[] names;  0x20

		// PlayerWalkMovement
		static constexpr auto ground_angle_new = 0xC8;
		static constexpr auto previous_velocity = 0xE4;
		static constexpr auto max_step_height = 0x98;
		static constexpr auto gravity_multiplier = 0x84;

		// PlayerInventory
		static constexpr auto inv_container_main = 0x20;
		static constexpr auto inv_container_belt = 0x28;
		static constexpr auto inv_container_wear = 0x30;

		// ItemContainer
		static constexpr auto itemcontainer_item_list = 0x40;
		static constexpr auto itemcontainer_item_array = 0x10;
		static constexpr auto itemcontainer_item_array_size = 0x18;

		// Item
		static constexpr auto item_info = 0x18;//0x18;
		static constexpr auto item_uid = 0x20;
		static constexpr auto item_amount = 0x2C;//0x28; 
		static constexpr auto item_name = 0x50;//0x50;
		static constexpr auto item_base_projectile = 0xA8;//private EntityRef heldEntity; // 0x98

		// Item Definition
		static constexpr auto item_def_id = 0x18;
		static constexpr auto item_def_shortname = 0x20;
		static constexpr auto item_def_category = 0x40;

		// BaseProjectile
		static constexpr auto base_projectile_drag = 0x24; //Projectile :
		static constexpr auto base_projectile_gravity = 0x28; //Projectile :
		static constexpr auto base_projectile_thickness = 0x2C; //Projectile :
		static constexpr auto mod_projectile = 0xE8; //Projectile :
		static constexpr auto base_projectile_maxdistance = 0x100; //Projectile :

		static constexpr auto base_projectile_distance = 0x268;
		static constexpr auto base_projectile_velocity = 0x26C;//projectileVelocityScale
		static constexpr auto base_projectile_automatic = 0x270;
		static constexpr auto base_projectile_sway = 0x2D8;
		static constexpr auto base_projectile_recoil = 0x2E0;
		static constexpr auto base_projectile_aimcone = 0x2F4;
		static constexpr auto base_projectile_hipaimcone = 0x2F0;
		static constexpr auto base_projectile_hipaimconepenaltymax = 0x2FC;
		static constexpr auto base_projectile_stancepenaltyscale = 0x308;

		//static constexpr auto base_projectile_maxdistance = 0x278;
		static constexpr auto base_projectile_strikesuccessfraction = 0x340;//FlintStrikeWeapon successFraction
		static constexpr auto base_projectile_currentholdprogress = 0x3A0;//public class CompoundBowWeapon : BowWeapon 

		// ItemModProjectile
		static constexpr auto mod_projectile_spread = 0x30;
		static constexpr auto mod_projectile_velocity = 0x34;
		//public float projectileVelocity; // 0x34
		//public float projectileVelocitySpread; // 0x38

	}
}

enum ItemCategory
{
	Weapon = 0,
	Construction = 1,
	Items = 2,
	Resources = 3,
	Attire = 4,
	Tool = 5,
	Medical = 6,
	Food = 7,
	Ammunition = 8,
	Traps = 9,
	Misc = 10,
	All = 11,
	Common = 12,
	Component = 13,
	Search = 14,
	Favourite = 15,
	Electrical = 16,
	Fun = 17
};

enum CameraMode
{
	FirstPerson = 0,
	ThirdPerson = 1,
	Eyes = 2,
	FirstPersonWithArms = 3,
	Last = 3,
};

enum PlayerFlags2
{
	IsAdmin = 4,
	Sleeping = 16,
	ThirdPersonViewmode = 1024
};
enum class PlayerFlags1
{
	Placeholder = 1,
	Unused2 = 2,
	IsAdmin = 4,
	ReceivingSnapshot = 8,
	Sleeping = 16,
	Spectating = 32,
	Wounded = 64,
	IsDeveloper = 128,
	Connected = 256,
	ThirdPersonViewmode = 1024,
	EyesViewmode = 2048,
	ChatMute = 4096,
	NoSprint = 8192,
	Aiming = 16384,
	DisplaySash = 32768,
	Relaxed = 65536,
	SafeZone = 131072,
	ServerFall = 262144,
	Workbench1 = 1048576,
	Workbench2 = 2097152,
	Workbench3 = 4194304,
};
enum class BaseEntityFlags
{
	Placeholder0 = 0,
	Placeholder = 1,
	On = 2,
	OnFire = 4,
	Open = 8,
	Locked = 16,
	Debugging = 32,
	Disabled = 64,
	Reserved1 = 128,
	Reserved2 = 256,
	Reserved3 = 512,
	Reserved4 = 1024,
	Reserved5 = 2048,
	Broken = 4096,
	Busy = 8192,
	Reserved6 = 16384,
	Reserved7 = 32768,
	Reserved8 = 65536,
	Reserved9 = 131072,
	Reserved10 = 262144,
	Reserved11 = 524288,
	InUse = 1048576,
};

template <typename t>
struct MonoArray
{
	char pad_0[0x20];
	t array[];
};

template <typename t>
struct MonoArraySecond
{
	char pad_0[0x30];
	t array[];
};

//struct MonoString
//{
//	char pad_0 [ 0x10 ];
//	int size;
//	wchar_t buffer;
//};
typedef struct Str12
{
	char stub[0x10];
	int len;
	wchar_t str[1];
} *str;

const class MonoString
{
public:
	std::string get_data()
	{
		std::string display_name_str;
		auto display_name_buffer = new wchar_t[this->get_size() + 1];

		auto display_name = reinterpret_cast<void*>(reinterpret_cast<uintptr_t>(this) + 0x14);

		memcpy(display_name_buffer, display_name, (this->get_size() * 2) + 1);

		display_name_buffer[this->get_size()] = '\0';
		auto display_name_w = std::wstring(display_name_buffer);
		display_name_str = std::string(display_name_w.begin(), display_name_w.end());
		delete[] display_name_buffer;
		return display_name_str;
	}

	int get_size()
	{
		return *reinterpret_cast<int*>(
			reinterpret_cast<uintptr_t>(this) + 0x10);
	}
};

struct UnityTransform
{
	char pad_0[0x10];
	void* transform;
};

class PlayerInput
{
public:

	utils::maths::vec2_t get_body_angles()
	{
		return *reinterpret_cast<utils::maths::vec2_t*>(reinterpret_cast<uintptr_t>(this) + 0x3C);
	}

	utils::maths::vec3_t get_body_angles2()
	{
		return *reinterpret_cast<utils::maths::vec3_t*>(reinterpret_cast<uintptr_t>(this) + 0x3C);
	}

	void modify_body_angles(utils::maths::vec2_t angles)
	{
		*reinterpret_cast<utils::maths::vec2_t*>(reinterpret_cast<uintptr_t>(this) + 0x3C) = angles;
	}

	void modify_body_angles2(utils::maths::vec3_t angles)
	{
		*reinterpret_cast<utils::maths::vec3_t*>(reinterpret_cast<uintptr_t>(this) + 0x3C) = angles;
	}


	utils::maths::vec2_t get_recoilAngles()
	{
		return *reinterpret_cast<utils::maths::vec2_t*>(reinterpret_cast<uintptr_t>(this) + 0x64);
	}
	void modify_recoilAngles(utils::maths::vec2_t angles)
	{
		*reinterpret_cast<utils::maths::vec2_t*>(reinterpret_cast<uintptr_t>(this) + 0x64) = angles;
	}
};

class RecoilProperties
{
public:
	float get_properties()
	{
		return *reinterpret_cast<float*>(
			reinterpret_cast<uintptr_t>(this) + 0x18);
	}

	void modify_recoil_properties(utils::maths::vec4_t settings)
	{
		*reinterpret_cast<utils::maths::vec4_t*>(
			reinterpret_cast<uintptr_t>(this) + 0x18) = settings;
	}
};

class ItemModProjectile
{
public:
	FIELD(O::ItemModProjectile::projectileVelocity, projectileVelocity, float);

	void modify_projectile_velocity(float percentage)
	{
		*reinterpret_cast<float*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::mod_projectile_velocity) = *reinterpret_cast<float*>(
				reinterpret_cast<uintptr_t>(this) + SDK::offsets1::mod_projectile_velocity) * percentage;
	}
};
class Magazine;


const class BaseViewModel {
public:

	static BaseViewModel* GetActiveModel() {
		__try {
			static auto get_activemodel = reinterpret_cast<uintptr_t(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("BaseViewModel"), _("get_ActiveModel"), 0)));

			return (BaseViewModel*)get_activemodel();
		}
		__except (1) { resetcondig = true;
			resetcondig = true;

			printf(_("[matrix]: Exception occurred in " __FUNCTION__ "!\n"));
			return nullptr;
		}
	}
};
const class ViewModel : public BaseViewModel {
public:

	void Play(wchar_t* anim) {
		__try {
			if (!ValidPtr((uintptr_t*)this))
				return;
			static auto viewmodelplay = reinterpret_cast<void(*)(uintptr_t, System::String, int)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("ViewModel"), _("Play"), 2)));
			 
			return viewmodelplay((uintptr_t)this, anim, 0);
		}
		__except (1) { resetcondig = true;
			resetcondig = true;

			printf(_("[matrix]: Exception occurred in " __FUNCTION__ "!\n"));
			return;
		}
	}
};

class BaseProjectile
{
public:
	FIELD(O::AttackEntity::nextAttackTime, nextAttackTime, float);
	FIELD(O::AttackEntity::timeSinceDeploy, timeSinceDeploy, float);
	FIELD(O::AttackEntity::deployDelay, deployDelay, float);
	FIELD(O::AttackEntity::repeatDelay, repeatDelay, float);
	uintptr_t get_damage_properties() {
		pent
			return *reinterpret_cast<uintptr_t*>((uintptr_t)this + 0x280); //public DamageProperties damageProperties; // 0x280

	}
	void remove_ammo() {
		__try {
			if (!ValidPtr(this)) return;
			const auto mag = *reinterpret_cast<uintptr_t*>((uintptr_t)this + O::BaseProjectile::primaryMagazine);
			if (!ValidPtr((uintptr_t*)mag)) 
				return;
			auto ammo = *reinterpret_cast<int*>(mag + 0x1C);

			*reinterpret_cast<int*>(mag + 0x1C) = (ammo - 1);
			static auto updateammodisplay = reinterpret_cast<void(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("BaseProjectile"), _("UpdateAmmoDisplay"), 0)));
			static auto shot_fired = reinterpret_cast<void(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("BaseProjectile"), _("ShotFired"), 0)));
			static auto did_attack_client_side = reinterpret_cast<void(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("BaseProjectile"), _("DidAttackClientside"), 0)));

			updateammodisplay((uintptr_t)this);
			shot_fired((uintptr_t)this);
			did_attack_client_side((uintptr_t)this);
		}
		__except (1) { resetcondig = true;
			resetcondig = true;

			printf(_("[1]:remove_ammo \n " __FUNCTION__ "! \n"));
			return;
		}
	}

	void LaunchProjectile() {
		__try {
			if (!ValidPtr(this))
				return;

		static auto launchproj = reinterpret_cast<void(*)(BaseProjectile*)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("BaseProjectile"), _("LaunchProjectile"), 0)));
		if (!ValidPtr(launchproj))
			return;
 
			launchproj(this);
		}
		__except (1) {  
			printf(_("\n [matrix]: Exception occurred in " __FUNCTION__ "!"));
			return;
		}
	}

	char* get_classname() {
		__try {
			if (!ValidPtr(this)) return nullptr;
			auto bp = *reinterpret_cast<uintptr_t*>((uintptr_t)this);
			if (!ValidPtr((uintptr_t*)bp)) return nullptr;
			return (char*)*reinterpret_cast<uintptr_t*>(bp + 0x10);
		}
		__except (1) { resetcondig = true;
			printf(_("[matrix]: Exception occurred inside " __FUNCTION__ "\n"));			resetcondig = true;

			return nullptr;
		}
	}

	int ammo_left() {
		__try {
			if (!ValidPtr(this)) return -1;
			const auto mag = *reinterpret_cast<uintptr_t*>((uintptr_t)this + O::BaseProjectile::primaryMagazine);
			if (!ValidPtr((uintptr_t*)mag))
				return -1;
			const auto ammo = *reinterpret_cast<int*>(mag + 0x1C);
			return ammo;
		}
		__except (1) { resetcondig = true;
			printf(_("[matrix]: Exception occurred in " __FUNCTION__ "!\n"));			resetcondig = true;

			return -1;
		}
	}
	weapon_stats_t get_stats(int32_t weapon_id) {

		if (!weapon_id)
			return weapon_stats_t{ (1000) };

		pent
			const auto primary_magazine = readf1<uintptr_t>((uintptr_t)this + 0x2C0);
		if (!primary_magazine)
			return weapon_stats_t{ (1000) };

		if (!IsValidPtr31((void*)primary_magazine))
			return weapon_stats_t{ (1000) };


		float velocity = (1000);
		float gravity_modifier = (1);
		float drag = (.001f);
		float distance = (0);

		auto velocity_scale = (1);
		bool scale_velocity = false;

		const auto ammo_definition = readf1<uintptr_t>((uintptr_t)primary_magazine + 0x20);
		if (!ammo_definition)
			return weapon_stats_t{ (1000) };

		if (ammo_definition) {

			const auto ammo_id = *reinterpret_cast<int32_t*>((uintptr_t)ammo_definition + 0x18);

			if (!ammo_id)
				return weapon_stats_t{ (1000) };

			if (ammo_id)
			{
				switch (ammo_id) {
					pent
				case rocket_basic:
					drag = (0.1f);
					gravity_modifier = (10.f);
					break;
				case rocket_hv:
					drag = (0.f);
					gravity_modifier = (0.f);
					break;

				case rocket_incen:
					drag = (0.1f);
					gravity_modifier = (10.f);
					break;

				case shotgun:
					velocity = (225);
					drag = (1);
					distance = (3);
					break;
				case shotgun_slug:
					velocity = (225);
					drag = (1);
					distance = (10);
					break;
				case shotgun_fire:
					velocity = 100;
					drag = 1;
					distance = 3;
					break;
				case shotgun_handmade:
					velocity = 100;
					drag = 1;
					distance = 0;
					break;
				case rifle_556:
					velocity = 375;
					drag = .6;
					distance = 15;
					break;
				case rifle_556_hv:
					velocity = 450;
					drag = .6;
					distance = 15;
					break;
				case rifle_556_fire:
					velocity = 225;
					drag = .6;
					distance = 15;
					break;
				case rifle_556_explosive:
					velocity = 225;
					gravity_modifier = 1.25;
					drag = .6;
					distance = 15;
					break;
				case pistol:
					velocity = 300;
					drag = .7;
					distance = 15;
					break;
				case pistol_hv:
					velocity = 400;
					drag = .7;
					distance = 15;
					break;
				case pistol_fire:
					velocity = 225;
					drag = .7;
					distance = 15;
					break;
				case arrow_wooden:
					velocity = 50;
					gravity_modifier = .75;
					drag = .005;
					break;
				case arrow_hv:
					velocity = 80;
					gravity_modifier = .5;
					drag = .005;
					break;
				case arrow_fire:
					velocity = 40;
					gravity_modifier = 1;
					drag = .01;
					break;
				case arrow_bone:
					velocity = 45;
					gravity_modifier = .75;
					drag = .01;
					break;
				case nailgun_nails:
					velocity = 50;
					gravity_modifier = .75;
					drag = .005;
					break;
				}
			}

			//scale_velocity = true;
		//	SAPPHIRE_METHOD(GetProjectileVelocityScale, "BaseProjectile.GetProjectileVelocityScale()", 1, "getMax", 1, float(*)(BaseProjectile* Player, bool MAX));
			//printf("GetProjectileVelocityScale %f \n", GetProjectileVelocityScale);

		//	velocity_scale = GetProjectileVelocityScale(this, false);
		}

		switch (weapon_id) {
		case spear_wooden:
			velocity = 25;
			scale_velocity = false;
			gravity_modifier = 2;
			drag = .1f;
			distance = .25f;
			break;
		case spear_stone:
			velocity = 30;
			scale_velocity = false;
			gravity_modifier = 2;
			drag = .1f;
			distance = .25f;
			break;
		case hatchet:
			velocity = 25;
			scale_velocity = false;
			gravity_modifier = 2;
			drag = .1f;
			distance = .25f;
			break;
		case stonehatchet:
			velocity = 25;
			scale_velocity = false;
			gravity_modifier = 2;
			drag = .1f;
			distance = .25f;
			break;
		case pickaxe:
			velocity = 25;
			scale_velocity = false;
			gravity_modifier = 2;
			drag = .1f;
			distance = .25f;
			break;
		case stonepickaxe:
			velocity = 25;
			scale_velocity = false;
			gravity_modifier = 2;
			drag = .1f;
			distance = .25f;
			break;
		case salvageaxe:
			velocity = 25;
			scale_velocity = false;
			gravity_modifier = 2;
			drag = .1f;
			distance = .25f;
			break;
		case cleaver:
			velocity = 25;
			scale_velocity = false;
			gravity_modifier = 2;
			drag = .1f;
			distance = .25f;
			break;
		case hammer:
			velocity = 25;
			scale_velocity = false;
			gravity_modifier = 2;
			drag = .1f;
			distance = .25f;
			break;
		case icepick:
			velocity = 25;
			scale_velocity = false;
			gravity_modifier = 2;
			drag = .1f;
			distance = .25f;
			break;
		case sword:
			velocity = 25;
			scale_velocity = false;
			gravity_modifier = 2;
			drag = .1f;
			distance = .25f;
			break;
		case boneknife:
			velocity = 25;
			scale_velocity = false;
			gravity_modifier = 2;
			drag = .1f;
			distance = .25f;
			break;
		case butcherknife:
			velocity = 25;
			scale_velocity = false;
			gravity_modifier = 2;
			drag = .1f;
			distance = .25f;
			break;
		case combatknife:
			velocity = 25;
			scale_velocity = false;
			gravity_modifier = 2;
			drag = .1f;
			distance = .25f;
			break;
		case rock:
			velocity = 15;
			scale_velocity = false;
			gravity_modifier = 2;
			drag = .1f;
			distance = .25f;
			break;
		case snowball:
			velocity = 25;
			scale_velocity = false;
			gravity_modifier = 2;
			drag = .1f;
			distance = .25f;
			break;
		}

		if (scale_velocity && (velocity_scale != 0))
			velocity *= velocity_scale;


		return { velocity, gravity_modifier, drag, distance };
	}

	RecoilProperties* get_recoil_properties()
	{
		return *reinterpret_cast<RecoilProperties**>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::base_projectile_recoil);
	}

	ItemModProjectile* get_item_mod()
	{
		return *reinterpret_cast<ItemModProjectile**>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::mod_projectile);
	}

	void modify_spread(float spread)
	{
		*reinterpret_cast<float*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::base_projectile_hipaimcone) = spread;

		*reinterpret_cast<float*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::base_projectile_hipaimconepenaltymax) = spread;

		*reinterpret_cast<float*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::base_projectile_aimcone) = spread;

		*reinterpret_cast<float*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::base_projectile_stancepenaltyscale) = spread;
	}

	float get_projectile_velocity()
	{
		return *reinterpret_cast<float*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::base_projectile_velocity);
	}

	void modify_sway(utils::maths::vec2_t sway)
	{
		*reinterpret_cast<utils::maths::vec2_t*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::base_projectile_sway) = sway;
	}

	void modify_weapon_fire_mode(bool automatic)
	{
		*reinterpret_cast<bool*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::base_projectile_automatic) = automatic;
	}

	void modify_distance_scale(float distance)
	{
		*reinterpret_cast<float*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::base_projectile_distance) = distance;
	}

	void modify_drag(float drag)
	{
		*reinterpret_cast<float*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::base_projectile_drag) = drag;
	}

	void modify_gravity(float gravity)
	{
		*reinterpret_cast<float*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::base_projectile_gravity) = gravity;
	}

	void modify_thickness(float thickness)
	{
		*reinterpret_cast<float*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::base_projectile_thickness) = thickness;
	}

	void modify_range(float range)
	{
		*reinterpret_cast<float*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::base_projectile_maxdistance) = range;
	}

	void modify_strike_success_fraction(float fraction)
	{
		*reinterpret_cast<float*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::base_projectile_strikesuccessfraction) = fraction;
	}

	void modify_current_hold_progress(float hold)
	{
		*reinterpret_cast<float*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::base_projectile_currentholdprogress) = hold;
	}

	Magazine* get_primaryMagazine()
	{
		return *reinterpret_cast<Magazine**>(
			reinterpret_cast<uintptr_t>(this) + 0x10);
	}
};

class ItemDefinition
{
public:
	int get_item_id()
	{
		return *reinterpret_cast<int*>(
			reinterpret_cast<uintptr_t>(this) + 0x20);
	}

	MonoString* get_item_shortname()
	{
		return *reinterpret_cast<MonoString**>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::item_def_shortname);
	}

};

class Item : ItemDefinition
{
public:
	FIELD(O::Item::info, info, ItemDefinition*);


	template<typename T = BaseEntity>
	T* GetHeldEntity() {
		if (!ValidPtr(this))
			return nullptr;

		__try {
			return *reinterpret_cast<T**>(this + O::Item::heldEntity);
		}
		__except (1) { resetcondig = true;
			printf(_("[1]:GetHeldEntity \n " __FUNCTION__ "! \n"));			resetcondig = true;


			return nullptr;
		}
	}
	ItemDefinition* get_item_info()
	{
		return *reinterpret_cast<ItemDefinition**>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::item_info);
	}


	int get_item_amount()
	{
		return *reinterpret_cast<int*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::item_amount);
	}
	int32_t get_item_definition_id()
	{
		const auto item_definition = this->info();
		if (!item_definition)
			return 0;

		return *reinterpret_cast<int32_t*>((uintptr_t)item_definition + 0x18);
	}
	int GetID() {
		__try {
			pent
				DWORD64 Info = mem::read<DWORD64>((uint64_t)this + 0x18); // public ItemDefinition info;

			int ID = mem::read<int>((DWORD64)Info + 0x18); // public int itemid; //ItemDefinition
			return ID;
		}
		__except (1) { resetcondig = true;
			resetcondig = true;

			printf(_("[1]:GetID \n " __FUNCTION__ "! \n"));

			return 0;
		}


	}
	std::uint32_t get_item_uid()
	{
		return *reinterpret_cast<std::uint32_t*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::item_uid);
	}

	MonoString* get_item_name()
	{
		return *reinterpret_cast<MonoString**>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::item_name);
	}

	BaseProjectile* get_base_projectile()
	{
		return *reinterpret_cast<BaseProjectile**>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::item_base_projectile);
	}
	std::string get_name()
	{
		uintptr_t entity = reinterpret_cast<uintptr_t>(this);
		if (!(entity))
		{
			return std::string();
		}

		uintptr_t address = offsets1::item_info; //il2cpp::value(xorstr_("Item"), xorstr_("info"))
		if (!address)
			return std::string();

		uintptr_t info = *reinterpret_cast<uintptr_t*>(entity + address);
		if (!(info))
			return std::string();

		uintptr_t address2 = 0x20; //public string shortname; // 0x20
		if (!address2)
			return std::string();

		MonoString* entity_name = *reinterpret_cast<MonoString**>(info + address2);
		if (!(reinterpret_cast<uintptr_t>(entity_name)))
			return std::string();




		return entity_name->get_data();
	}
	/*void modify_skin_id(const uint32_t skin_id)
	{
		*reinterpret_cast<uint32_t*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::item_skin) = skin_id;
	}*/

	bool is_gun()
	{
		uintptr_t entity = reinterpret_cast<uintptr_t>(this);

		if (!(entity))
			return false;

		std::string item_name = this->get_item_shortname()->get_data();
		//std::printf("item %s \n", item_name.c_str());;
		if (item_name.find(xorstr_("rifle.")) != std::string::npos && item_name.find(xorstr_("ammo.")) == std::string::npos)
		{
			return true;
		}
		else if (item_name.find(xorstr_("pistol.")) != std::string::npos && item_name.find(xorstr_("ammo.")) == std::string::npos)
		{
			return true;
		}
		else if (item_name.find(xorstr_("bow.")) != std::string::npos && item_name.find(xorstr_("ammo.")) == std::string::npos)
		{
			return true;
		}
		else if (item_name.find(xorstr_("cross")) != std::string::npos && item_name.find(xorstr_("ammo.")) == std::string::npos)
		{
			return true;
		}
		else if (item_name.find(xorstr_("lmg.")) != std::string::npos && item_name.find(xorstr_("ammo.")) == std::string::npos)
		{
			return true;
		}
		else if (item_name.find(xorstr_("hmlmg")) != std::string::npos && item_name.find(xorstr_("ammo.")) == std::string::npos)
		{
			return true;
		}
		else if (item_name.find(xorstr_("shotgun.")) != std::string::npos && item_name.find(xorstr_("ammo.")) == std::string::npos)
		{
			return true;
		}
		else if (item_name.find(xorstr_("smg.")) != std::string::npos && item_name.find(xorstr_("ammo.")) == std::string::npos)
		{
			return true;
		}//hmlmg
		else
			return false;
	}
	MonoString* get_display_name()
	{
		return *reinterpret_cast<MonoString**>(
			reinterpret_cast<uintptr_t>(this) + 0x10);
	}
};

class PlayerBelt
{
public:
	//Item* ENGINECALL get_active_item( )
	//{
	//	return reinterpret_cast< Item* >( reinterpret_cast< void * ( __thiscall* )( void* ) >( functions::get_active_item_fn )( this ) );
	//}
};


enum class e_model_state_flag {
	ducked = 1,
	jumped = 2,
	on_ground = 4,
	sleeping = 8,
	sprinting = 16,
	on_ladder = 32,
	flying = 64,
	aiming = 128,
	prone = 256,
	mounted = 512,
	relaxed = 1024,
};

class  c_model_state
{
public:
	auto set_flag(e_model_state_flag flag) -> void {
		int flags = *reinterpret_cast<int*>(this + 0x20);
		*reinterpret_cast<int*>(this + 0x20) = flags |= (int)flag;
	}
	auto set_flag1(e_model_state_flag flag) -> void {
		int flags = *reinterpret_cast<int*>(this + 0x24);
		*reinterpret_cast<int*>(this + 0x24) = flags |= (int)flag;
	}
};

class PlayerModel
{
public:
	bool is_visible()
	{
		return *reinterpret_cast<bool*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::model_is_visible);
	}

	bool is_local_player()
	{
		return *reinterpret_cast<bool*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::model_is_localplayer);
	}

	SkinnedMultiMesh* get_skin_mesh()
	{
		return *reinterpret_cast<SkinnedMultiMesh**>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::model_skin_mesh);
	}
	c_model_state* getmodelstate()
	{
		return *reinterpret_cast<c_model_state**>(
			reinterpret_cast<uintptr_t>(this) + 0x1B0);
	}

	utils::maths::vec3_t get_new_velocity()
	{
		return *reinterpret_cast<utils::maths::vec3_t*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::model_newvelocity);
	}
};

class BaseMovement
{
public:
	void modify_ground_angles(float angle)
	{
		*reinterpret_cast<float*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::ground_angle_new) = angle;
	}

	void modify_velocity(utils::maths::vec3_t velocity)
	{
		*reinterpret_cast<utils::maths::vec3_t*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::previous_velocity) = velocity;
	}

	void modify_step_height(float height)
	{
		*reinterpret_cast<float*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::max_step_height) = height;
	}

	void modify_gravity_multiplier(float multiplier)
	{
		*reinterpret_cast<float*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::gravity_multiplier) = multiplier;
	}
};






class BaseEntity
{
public:
	std::string			get_class_name1();
	Transform1* get_transform1();
	void				set_hit_direction(utils::maths::vec3_t value);

	Transform* transform() {
		__try {
			if (!ValidPtr(this)) return nullptr;

			static auto gettrans = reinterpret_cast<uintptr_t(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("Component"), _("get_transform"), 0, _("UnityEngine"))));

			return (Transform*)gettrans((uintptr_t)this);
		}
		__except (1) { resetcondig = true;
			resetcondig = true;

			printf("[transform]  occurred inside " __FUNCTION__ "\n");

			return nullptr;
		}
	}
	SDK::utils::maths::vec3_t GetWorldVelocity() {
		__try {
			if (!ValidPtr(this)) return SDK::utils::maths::vec3_t(0, 0, 0);
			typedef SDK::utils::maths::vec3_t(*GWV)(BaseEntity*);
			return ((GWV)((std::intptr_t)GetModuleHandleW(xorstr_(L"GameAssembly.dll")) + oGetWorldVelocity))(this);
		}
		__except (1) { resetcondig = true;
			resetcondig = true;

			printf(_(" [matrix]: Exception occurred in \n " __FUNCTION__ "! \n"));
			return SDK::utils::maths::vec3_t(0, 0, 0);
		}
	}
	char* get_class_name() {
		pent
			if (!this || (uintptr_t)this < 0xFFFFFFFF || (uintptr_t)this > 0xF000000000000000) return ((char*)"");
		auto bp = *reinterpret_cast<uintptr_t*>(this);
		return (char*)*reinterpret_cast<uintptr_t*>(bp + 0x10);
	}

	Model* get_entity_model()
	{
		return *reinterpret_cast<Model**>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::entity_model);
	}

	bool is_visible()
	{
		return *reinterpret_cast<bool*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::entity_is_visible);
	}

};
void BaseEntity::set_hit_direction(utils::maths::vec3_t value)
{
	uintptr_t entity = reinterpret_cast<uintptr_t>(this);
	if (!(entity))
		return;

	uintptr_t address = 0x1F8; //il2cpp::value(xorstr_("TreeEntity"), xorstr_("hitDirection"));
	if (!address)
		return;

	memory::write<utils::maths::vec3_t>(entity + address, value);
}
#define DECLARE_MEMBER( type, klass, name ) type & name( ) { SAPPHIRE_FIELD( klass, ##name ) return *reinterpret_cast< type* >( this + name ); }
class c_walk_movement
{
public:
	DECLARE_MEMBER(bool, "PlayerWalkMovement", flying)
		DECLARE_MEMBER(bool, "PlayerWalkMovement", swimming)
		DECLARE_MEMBER(float, "PlayerWalkMovement", landTime)
		DECLARE_MEMBER(float, "PlayerWalkMovement", jumpTime)
		DECLARE_MEMBER(float, "PlayerWalkMovement", groundTime)
		DECLARE_MEMBER(float, "PlayerWalkMovement", groundAngleNew)
		DECLARE_MEMBER(float, "PlayerWalkMovement", gravityMultiplier)
};



enum class PlayerFlags12
{
	Unused1 = 1,
	Unused2 = 2,
	IsAdmin = 4,
	ReceivingSnapshot = 8,
	Sleeping = 16,
	Spectating = 32,
	Wounded = 64,
	IsDeveloper = 128,
	Connected = 256,
	ThirdPersonViewmode = 1024,
	EyesViewmode = 2048,
	ChatMute = 4096,
	NoSprint = 8192,
	Aiming = 16384,
	DisplaySash = 32768,
	Relaxed = 65536,
	SafeZone = 131072,
	ServerFall = 262144,
	Workbench1 = 1048576,
	Workbench2 = 2097152,
	Workbench3 = 4194304,
};
class string23 {
public:
	char zpad[0x10];

	int size;
	wchar_t str[128 + 1];
	string23() {}
	string23(const wchar_t* st) {
		size = min(wcslen((wchar_t*)st), 128);
		for (int i = 0; i < size; i++) {
			str[i] = st[i];
		}
		str[size] = 0;
	}
};

class weapon : Item
{
public:



	int GetID()
	{
		const auto Info = readf1<uintptr_t>(reinterpret_cast<uintptr_t>(this) + 0x18);
		const int ID = readf1<int>(Info + 0x18);
		return ID;
	}

	int GetAmount()
	{
		return *reinterpret_cast<int*>(this + 0x30);
	}

	bool is_weapon() {
		const auto     item_definition = *reinterpret_cast<uintptr_t*>((uintptr_t)this + 0x18);
		if (!item_definition)
			return false;

		return *reinterpret_cast<uint32_t*>(item_definition + 0x40) == 0;
	}
	int32_t get_item_definition_id()
	{
		return *reinterpret_cast<int32_t*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::item_amount);
	}
	int32_t get_item_definition_id1()
	{
		const auto     item_definition = *reinterpret_cast<uintptr_t*>((uintptr_t)this + 0x18);
		if (!item_definition)
			return 0;

		return *reinterpret_cast<int32_t*>(item_definition + 0x18);
	}





	int LoadedAmmo()
	{
		const auto Held = readf1<DWORD64>(reinterpret_cast<uintptr_t>(this) + 0xA8);
		if (Held <= 0)
			return 0;
		const auto Magazine = readf1<DWORD64>(Held + 0x10);
		if (Magazine <= 0 || Magazine == 0x3F000000)
		{
			return 0;
		}
		const auto ammoType = readf1<DWORD64>(Magazine + 0x20);
		if (ammoType <= 0 || ammoType == 0x3F000000)
		{
			return 0;
		}
		const int ammo = readf1<int>(ammoType + 0x18);
		return ammo;
	}

	//weapon_data get_weapon_data()
	//{
	//	std::cout << "Getting get Entity" << std::endl;
	//	auto held = this->get_base_projectile();
	//	if (!held)
	//		return weapon_data{ (1000) };

	//	std::cout << "Converting Held Entity" << std::endl;
	//	BaseProjectile* base_projectile = reinterpret_cast<BaseProjectile*>(held);

	//	if (!base_projectile)
	//		return weapon_data{ (1000) };
	//	std::cout << "Getting Held Mag" << std::endl;
	//	Magazine* magazine = base_projectile->get_primaryMagazine();
	//	if (!magazine)
	//		return weapon_data{ (1000) };

	//	float velocity = (1000);
	//	float gravity_modifier = (1);
	//	float drag = (.001f);
	//	float distance = (0);

	//	auto velocity_scale = (1);
	//	bool scale_velocity = false;

	//	std::cout << "Getting Held Ammo Def" << std::endl;
	//	const auto ammo_definition = *reinterpret_cast<uintptr_t*>((uintptr_t)magazine + 0x20);
	//	if (ammo_definition) {
	//		// itemid
	//		//std::cout << "Getting Held Ammo ID" << std::endl;
	//		const auto ammo_id = *reinterpret_cast<int32_t*>(ammo_definition + 0x18);
	//		std::cout << "Switching: " << ammo_id << std::endl;
	//		switch (ammo_id) {
	//		case shotgun_slug:
	//			velocity = (225);
	//			drag = (1);
	//			distance = (10);
	//			break;
	//		case shotgun_fire:
	//			velocity = 100;
	//			drag = 1;
	//			distance = 3;
	//			break;
	//		case shotgun_handmade:
	//			velocity = 100;
	//			drag = 1;
	//			distance = 0;
	//			break;
	//		case rifle_556:
	//			velocity = 375;
	//			drag = .6;
	//			distance = 15;
	//			break;
	//		case rifle_556_hv:
	//			velocity = 450;
	//			drag = .6;
	//			distance = 15;
	//			break;
	//		case rifle_556_fire:
	//			velocity = 225;
	//			drag = .6;
	//			distance = 15;
	//			break;
	//		case rifle_556_explosive:
	//			velocity = 225;
	//			gravity_modifier = 1.25;
	//			drag = .6;
	//			distance = 15;
	//			break;
	//		case pistol:
	//			velocity = 300;
	//			drag = .7;
	//			distance = 15;
	//			break;
	//		case pistol_hv:
	//			velocity = 400;
	//			drag = .7;
	//			distance = 15;
	//			break;
	//		case pistol_fire:
	//			velocity = 225;
	//			drag = .7;
	//			distance = 15;
	//			break;
	//		case arrow_hv:
	//			velocity = 80;
	//			gravity_modifier = .5;
	//			drag = .005;
	//			break;
	//		case arrow_fire:
	//			velocity = 40;
	//			gravity_modifier = 1;
	//			drag = .01;
	//			break;
	//		case arrow_bone:
	//			velocity = 45;
	//			gravity_modifier = .75;
	//			drag = .01;
	//			break;
	//		case nailgun_nails:
	//			velocity = 50;
	//			gravity_modifier = .75;
	//			drag = .005;
	//			break;
	//		}
	//		std::cout << "Getting getprojectilevelocityscale" << std::endl;
	//		//scale_velocity = true;
	//		//velocity_scale = functions::getprojectilevelocityscale(reinterpret_cast<uintptr_t>(held), false);
	//	}

	//	//std::cout << "Getting Held Entity Def ID" << std::endl;
	//	switch (this->GetID()) {
	//	case spear_wooden:
	//		velocity = 25;
	//		scale_velocity = false;
	//		gravity_modifier = 2;
	//		drag = .1f;
	//		distance = .25f;
	//		break;
	//	case spear_stone:
	//		velocity = 30;
	//		scale_velocity = false;
	//		gravity_modifier = 2;
	//		drag = .1f;
	//		distance = .25f;
	//		break;
	//	}

	//	if (scale_velocity && (velocity_scale != 0))
	//		velocity *= velocity_scale;

	//	//std::cout << "Getting Held Entity" << std::endl;
	//	return { velocity, gravity_modifier, drag, distance };

	//}


};
namespace rust11 {

	unsigned int m_wcslen(wchar_t* str)
	{
		int cnt = 0;
		if (!str)
			return 0;
		for (; *str != '\0'; ++str)
			++cnt;
		return cnt;
	}
	class string {
	public:
		char zpad[0x10];

		int size;
		wchar_t str[128 + 1];
		string() {}
		string(const wchar_t* st) {
			size = min(m_wcslen((wchar_t*)st), 128);
			for (int i = 0; i < size; i++) {
				str[i] = st[i];
			}
			str[size] = 0;
		}
	};
}
namespace rust111 {
	unsigned int m_wcslen(wchar_t* str)
	{
		int cnt = 0;
		if (!str)
			return 0;
		for (; *str != '\0'; ++str)
			++cnt;
		return cnt;
	}
	class string {
	public:
		char zpad[0x10];

		int size;
		wchar_t str[128 + 1];
		string() {}
		string(const wchar_t* st) {
			size = min(m_wcslen((wchar_t*)st), 128);
			for (int i = 0; i < size; i++) {
				str[i] = st[i];
			}
			str[size] = 0;
		}
	};
}

class InputState {
public:
};

const class HeldEntity : public BaseEntity {
public:

	Item* GetItem() {
		__try {
			if (!ValidPtr((uintptr_t*)this)) return nullptr;
			//	return il2::_getitem((uintptr_t)this);
		}
		__except (1) { resetcondig = true;
			resetcondig = true;

			printf(_("[matrix]: Exception occurred in " __FUNCTION__ "!\n"));
			return nullptr;
		}
	}
};
const class PlayerEyes {
public:
	FIELD(O::PlayerEyes::viewOffset, viewOffset, SDK::utils::maths::vec3_t);

	//static auto PEyes_get_position = reinterpret_cast<SDK::utils::maths::vec3_t(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("PlayerEyes"), _("get_position"), 0)));

	SDK::utils::maths::vec3_t position() {
		__try {
			if (!ValidPtr((uintptr_t*)this))
				return SDK::utils::maths::vec3_t(0, 0, 0);
			static auto PEyes_get_position = reinterpret_cast<SDK::utils::maths::vec3_t(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("PlayerEyes"), _("get_position"), 0)));

			return PEyes_get_position((uintptr_t)this);
		}
		__except (1) { resetcondig = true;
			resetcondig = true;

			printf(_("[matrix]: Exception occurred in " __FUNCTION__ "!\n"));
			return SDK::utils::maths::vec3_t(0, 0, 0);
		}
	}
	SDK::utils::maths::vec4_t rotation() {
		__try {
			if (!ValidPtr((uintptr_t*)this))
				return SDK::utils::maths::vec4_t(0, 0, 0, 0);
			static auto PEyes_get_rotation = reinterpret_cast<SDK::utils::maths::vec4_t(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("PlayerEyes"), _("get_rotation"), 0)));

			return PEyes_get_rotation((uintptr_t)this);
		}
		__except (1) {
			printf(_("[matrix]: Exception occurred in " __FUNCTION__ "!\n"));
			return SDK::utils::maths::vec4_t(0, 0, 0, 0);
		}
	}
	SDK::utils::maths::vec3_t body_forward() {
		pent
			if (!this || (uintptr_t)this < 0xFFFFFFFF || (uintptr_t)this > 0xF000000000000000) return SDK::utils::maths::vec3_t(0, 0, 0);
		static auto bodyforward = reinterpret_cast<SDK::utils::maths::vec3_t(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("PlayerEyes"), _("BodyForward"), 0, _(""), _(""))));

		return bodyforward((uintptr_t)this);
	}


	SDK::utils::maths::vec3_t EyeOffset() {
		__try {
			auto kl = *reinterpret_cast<uintptr_t*>((std::intptr_t)GetModuleHandleW(xorstr_(L"GameAssembly.dll")) + oPlayerEyes_TypeInfo);
			if (!ValidPtr((uintptr_t*)kl)) return SDK::utils::maths::vec3_t(0, 0, 0);
			return *reinterpret_cast<SDK::utils::maths::vec3_t*>(kl + 0xB8); //eye offset is at + 0x0 from class
		}
		__except (1) { resetcondig = true;
			resetcondig = true;

			printf(_("[matrix]: Exception occurred in " __FUNCTION__ "!\n"));
			return SDK::utils::maths::vec3_t(0, 0, 0);
		}
	}
};

const class BaseMountable : public BaseEntity {
public:
	FIELD(O::BaseMountable::canWieldItems, canWieldItems, bool);
 
 };
enum BaseCombatEntity_LifeState {
	Alive = 0,
	Dead = 1
};

class BaseNetwork {
public:
};

class Client : public BaseNetwork {
public:
	FIELD(0x40, ConnectedAddress, System::string*);
	FIELD(0x48, ConnectedPort, int);
	FIELD(0x50, ServerName, System::string*);
};

class Server {
public:
	FIELD(0x28, ip, System::string*);
	FIELD(0x30, port, int);
};
class Networkable {
public:
	FIELD(0x48, sv, Server*);
	FIELD(0x50, cl, Client*);

	unsigned int get_id() {

		if (!this || (uintptr_t)this < 0xFFFFFFFF || (uintptr_t)this > 0xF000000000000000) return -1;
		return *reinterpret_cast<unsigned int*>((uintptr_t)this + 0x10);
	}
 
	template<typename T = uintptr_t>
	T* GetComponent(uintptr_t type) {
		pent
			__try {
			if (!this || !type) return nullptr;
			//static auto get_component = reinterpret_cast<uintptr_t(*)(uintptr_t, uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("Component"), _("GetComponent"), 0, _(""), _("UnityEngine"))));
//// 		get_component = reinterpret_cast<uintptr_t(*)(uintptr_t, uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Component"), _("GetComponent"), 0, _("UnityEngine"))));
		//	static auto get_component = reinterpret_cast<uintptr_t(*)(uintptr_t, uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Component"), _("GetComponent"), 0, _(""), _("UnityEngine"))));
			//static auto get_component = reinterpret_cast<uintptr_t(*)(uintptr_t, uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Component"), _("GetComponent"), 0, _(""), _("UnityEngine"))));

			//static auto get_component = reinterpret_cast<uintptr_t(*)(uintptr_t, uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("Component"), _("GetComponent"), 0, _(""), _("UnityEngine"))));

			SAPPHIRE_METHOD(set_color_fn, "UnityEngine::Component.GetComponent()", 1, "type", 1, uintptr_t(*)(uintptr_t, uintptr_t));
			auto ff = (T*)set_color_fn((uintptr_t)this, type);
			if(!ff)
			return nullptr;
			return ff;

		}
		__except (1) { resetcondig = true;
			printf(_("[GetComponent]: Exception occurred in " __FUNCTION__ "!\n"));
			return 0;
		}
	}

	System::list<uintptr_t>* GetComponentsInChildren(uintptr_t type) {
		pent
			if (!this || !type) return nullptr;
		static auto get_components_in_children = reinterpret_cast<uintptr_t(*)(uintptr_t, uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("Component"), _("GetComponentsInChildren"), 0, _(""), _("UnityEngine"))));

		return reinterpret_cast<System::list<uintptr_t>*>(get_components_in_children((uintptr_t)this, type));
	}
};