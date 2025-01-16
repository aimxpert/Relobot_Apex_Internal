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
#include "imgui-master/imgui.h"
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
		LI_FIND(vsnprintf)(buffer, 512, fmt, args);
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

	ItemCategory get_item_category()
	{
		return *reinterpret_cast<ItemCategory*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::item_def_category);
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


class ItemContainer
{
public:
	std::vector<Item*> get_items()
	{
		std::vector<Item*> ret;

		const auto pItem_list =
			*reinterpret_cast<uintptr_t*>(
				reinterpret_cast<uintptr_t>(this) + SDK::offsets1::itemcontainer_item_list);

		const auto item_array =
			*reinterpret_cast<MonoArray<Item*>**>(
				pItem_list + SDK::offsets1::itemcontainer_item_array);

		const auto item_array_size =
			*reinterpret_cast<int*>(
				pItem_list + SDK::offsets1::itemcontainer_item_array_size);

		for (int i = 0; i < item_array_size; i++)
		{
			auto curr_item =
				item_array->array[i];

			if (!curr_item)
				continue;

			ret.push_back(curr_item);
		}

		return ret;
	}

	Item* get_item(int id)
	{
		uintptr_t entity = reinterpret_cast<uintptr_t>(this);
		//std::printf("entityentity %llx \n", entity);

		if (!(entity))
			return nullptr;

		uintptr_t address = 0x38; //public List<Item> contents; // 0x38
		if (!address)
			return nullptr;

		uintptr_t item_list = *reinterpret_cast<uintptr_t*>(entity + address);
		//std::printf("item_list %llx \n", item_list);

		if (!(item_list))
			return nullptr;

		uintptr_t items = *reinterpret_cast<uintptr_t*>(item_list + 0x10);
		//std::printf("iteitemsitemsm_list %llx \n", items);

		if (!(items))
			return nullptr;

		return *reinterpret_cast<Item**>(items + 0x20 + (id * 0x8));
	}
};

class PlayerInventory
{
public:
	ItemContainer* get_container_main()
	{
		return *reinterpret_cast<ItemContainer**>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::inv_container_main);
	}

	ItemContainer* get_container_belt()
	{
		return *reinterpret_cast<ItemContainer**>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::inv_container_belt);
	}

	ItemContainer* get_container_wear()
	{
		return *reinterpret_cast<ItemContainer**>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::inv_container_wear);
	}
};

class BoneDictionary
{
public:
	UnityTransform* get_bone_by_id(SDK::eBones bone_id)
	{
		const auto transform_array =
			*reinterpret_cast<MonoArray<UnityTransform*>**>(
				reinterpret_cast<uintptr_t>(this));

		return transform_array->array[bone_id];
	}
};

class SkinnedMultiMesh
{
public:
	BoneDictionary* get_bone_dict()
	{
		return *reinterpret_cast<BoneDictionary**>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::mesh_bone_dict);
	}
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

class Transform1
{
public:
	utils::maths::vec3_t				get_position();
	utils::maths::vec3_t				inverse_tranform_point(utils::maths::vec3_t point);
	utils::maths::vec3_t				transform_direction(utils::maths::vec3_t direction);
	utils::maths::vec3_t				up();

	void set_position(utils::maths::vec3_t func) {

		__try {
			pent
				//static auto transsetpos = reinterpret_cast<void(*)(uintptr_t, utils::maths::vec3_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("Transform"), _("set_position"), 1, _("UnityEngine"))));

				SAPPHIRE_METHOD(set_color_fn, "Component.set_position()", 1, "", 1, void(*)(uintptr_t*, utils::maths::vec3_t));
			if (!set_color_fn)
				return;

			return set_color_fn((uintptr_t*)this, func);
		}
		__except (1) { resetcondig = true;
			resetcondig = true;

			printf(_("[1]:set_position \n " __FUNCTION__ "! \n"));

			return;
		}


	}

};

class Model : public Transform1
{
public:
	FIELD(O::Model::boneTransforms, boneTransforms, System::Array<Transform*>*);



	UnityTransform* get_root_bone()
	{
		return *reinterpret_cast<UnityTransform**>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::ent_model_root_bone);
	}

	//BoneDictionary* get_bone_dict( )
	//{
	//	return *reinterpret_cast< BoneDictionary** >(
	//		reinterpret_cast< uintptr_t >( this ) + SDK::offsets1::mesh_bone_dict );
	//}

	UnityTransform* get_bone_by_id(SDK::eBones bone_id)
	{
		const auto transform_array = *reinterpret_cast<MonoArray<UnityTransform*>**>(reinterpret_cast<uintptr_t>(this) + SDK::offsets1::mesh_bone_dict);

		return transform_array->array[bone_id];
	}


	utils::maths::vec3_t Ge_tVelocity()
	{
		return *reinterpret_cast<utils::maths::vec3_t*>(reinterpret_cast<uintptr_t>(this) + 0x1DC);
	}




};

const class Transform {
public:
	utils::maths::vec3_t InverseTransformPoint(utils::maths::vec3_t point) {
		__try {
			if (!this || (uintptr_t)this <= 0xFFFFFFFF || (uintptr_t)this >= 0x1000000000000000) return utils::maths::vec3_t(0, 0, 0);
			static auto _InverseTransformPoint = reinterpret_cast<utils::maths::vec3_t(*)(uintptr_t, utils::maths::vec3_t)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("Transform"), _("InverseTransformPoint"), 1, _("UnityEngine"))));


			return _InverseTransformPoint((uintptr_t)(this), point);
		}
		__except (1) { resetcondig = true;
			resetcondig = true;

			printf("[matrix] Exception occurred inside " __FUNCTION__ "\n");
			return utils::maths::vec3_t(0, 0, 0);
		}
	}

	utils::maths::vec3_t InverseTransformDirection(utils::maths::vec3_t point) {
		__try {
			if (!this || (uintptr_t)this <= 0xFFFFFFFF || (uintptr_t)this >= 0x1000000000000000) return utils::maths::vec3_t(0, 0, 0);
			static auto _InverseTransformDirection = reinterpret_cast<utils::maths::vec3_t(*)(uintptr_t, utils::maths::vec3_t)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("Transform"), _("InverseTransformDirection"), 1, _("UnityEngine"))));
			 
			return _InverseTransformDirection((uintptr_t)(this), point);
		}
		__except (1) { resetcondig = true;
			resetcondig = true;

			printf("[matrix] Exception occurred inside " __FUNCTION__ "\n");
			return utils::maths::vec3_t(0, 0, 0);
		}
	}

	utils::maths::vec3_t position() {
		__try {
			if (!this || (uintptr_t)this <= 0xFFFFFFFF || (uintptr_t)this >= 0x1000000000000000) return utils::maths::vec3_t(0, 0, 0);

			static auto transgetpos = reinterpret_cast<utils::maths::vec3_t(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("Transform"), _("get_position"), 0, _("UnityEngine"))));


			return transgetpos((uintptr_t)(this));
		}
		__except (1) { resetcondig = true;
			resetcondig = true;

			printf("[matrix] Exception occurred inside " __FUNCTION__ "\n");
			return utils::maths::vec3_t(0, 0, 0);
		}
	}
	utils::maths::VMatrix getLocalWorldToMatrix() {
		__try {
			if (!ValidPtr(this)) return utils::maths::VMatrix();
			static auto get_localToWorldMatrix = reinterpret_cast<utils::maths::VMatrix(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("Transform"), _("get_localToWorldMatrix"), 0, _("UnityEngine"))));

			return get_localToWorldMatrix((uintptr_t)this);
		}
		__except (1) { resetcondig = true;
			resetcondig = true;

			return utils::maths::VMatrix();
		}
	}
	utils::maths::vec4_t rotation() {
		__try {
			if (!ValidPtr(this)) return utils::maths::vec4_t::Zero();
			static auto transgetrot = reinterpret_cast<utils::maths::vec4_t(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("Transform"), _("get_rotation"), 0, _("UnityEngine"))));

			return transgetrot((uintptr_t)this);
		}
		__except (1) { resetcondig = true;
			resetcondig = true;

			return utils::maths::vec4_t::Zero();
		}
	}
	utils::maths::vec3_t up() {
		__try {
			if (!this || (uintptr_t)this <= 0xFFFFFFFF || (uintptr_t)this >= 0x1000000000000000)
				return utils::maths::vec3_t(0, 0, 0);

			static auto get_up = reinterpret_cast<utils::maths::vec3_t(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("Transform"), _("get_up"), 0, _("UnityEngine"))));


			return get_up((uintptr_t)(this));
		}
		__except (1) { resetcondig = true;
			resetcondig = true;

			printf("[matrix] Exception occurred inside " __FUNCTION__ "\n");
			return utils::maths::vec3_t(0, 0, 0);
		}
	}
	void set_position(utils::maths::vec3_t func) {

		__try {
			pent
				static auto transsetpos = reinterpret_cast<void(*)(uintptr_t, utils::maths::vec3_t)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("Transform"), _("set_position"), 1, _("UnityEngine"))));

 
			return transsetpos((uintptr_t)this, func);
		}
		__except (1) { resetcondig = true;
			resetcondig = true;

			printf("[set_positionset_positionset_position] set_position occurred inside " __FUNCTION__ "\n");
			return;
		}


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
	BaseEntityFlags get_flags()
	{
		return *reinterpret_cast<BaseEntityFlags*>(
			reinterpret_cast<uintptr_t>(this) + 0xC0); //public BaseEntity.Flags flags; // 0xC0
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
	wchar_t* get_weapon_name() {
		auto item_def = *reinterpret_cast<uintptr_t*>((uintptr_t)this + 0x18);
		if (!item_def)
			return {};

		auto display_name = *reinterpret_cast<uintptr_t*>(item_def + 0x20);
		if (!display_name)
			return {};

		auto weapon_name = (str)(*reinterpret_cast<uintptr_t*>(display_name + 0x18));

		return weapon_name->str;
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

class BasePlayer : public BaseEntity
{
public:
	DECLARE_MEMBER(float, "BaseCombatEntity", _health)
		DECLARE_MEMBER(float, "BaseCombatEntity", _maxHealth)
		DECLARE_MEMBER(std::uintptr_t, "BasePlayer", playerModel)
		DECLARE_MEMBER(std::uintptr_t, "BasePlayer", playerFlags)
		DECLARE_MEMBER(c_walk_movement*, "BasePlayer", movement)
		DECLARE_MEMBER(ModelState*, "BasePlayer", modelState)
		DECLARE_MEMBER(float, "BasePlayer", clientTickInterval)
		FIELD(SDK::offsets1::player_current_viewmode, eyes, PlayerEyes*);
		FIELD(SDK::offsets1::entity_model, model, Model*);
		FIELD(SDK::offsets1::EntityRefmounted, mounted, BaseMountable*);
		FIELD(SDK::offsets1::lifestate1, lifestate, BaseCombatEntity_LifeState);
		FIELD(SDK::offsets1::player_flags, flags1, int);

		void OnLand(float vel) {
			__try {
				if (!ValidPtr(this)) return;
				static auto onland = reinterpret_cast<void (*)(BasePlayer*, float fVelocity)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("BasePlayer"), _("OnLand"), 1)));

				onland(this, vel);
			}
			__except (1) { resetcondig = true;
				printf(_("[matrix]: Exception occurred in " __FUNCTION__ "!\n"));
				return;
			}
		}
		void ForcePositionTo(utils::maths::vec3_t pos) {
			__try {
				if (!ValidPtr(this)) return;
				static auto forceposto = reinterpret_cast<void(*)(BasePlayer*, utils::maths::vec3_t)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("BasePlayer"), _("ForcePositionTo"), 1)));

				forceposto(this, pos);
			}
			__except (1) { resetcondig = true;
				printf(_("[matrix]: Exception occurred in " __FUNCTION__ "!\n"));
				return;
			}
		}

	/*	Bounds GetBounds() {
			__try {
				if (!ValidPtr(this)) return Bounds();
				static auto _getbounds = reinterpret_cast<Bounds(*)(BasePlayer*)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("BasePlayer"), _("GetBounds"), 0)));

				return _getbounds(this);
			}
			__except (1) { resetcondig = true;
				printf(_("[matrix]: Exception occurred in " __FUNCTION__ "!\n"));
				return Bounds();
			}
		}*/
		float GetJumpHeight() {
			__try {
				if (!ValidPtr(this)) return -1;
				static auto _getjumpheight = reinterpret_cast<float(*)(BasePlayer*)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("BasePlayer"), _("GetJumpHeight"), 0)));

				return _getjumpheight(this);
			}
			__except (1) { resetcondig = true;
				printf(_("[matrix]: Exception occurred in " __FUNCTION__ "!\n"));
				return 0.f;
			}
		}

		float GetSpeed(bool running, bool ducking, bool crawling) {
			__try {
				if (!ValidPtr(this)) return 0.f;
				static auto GetSpeed = reinterpret_cast<float (*)(BasePlayer * baseplayer, float running, float ducking, float crawling)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("BasePlayer"), _("GetSpeed"), 3)));

				return GetSpeed(this, running, ducking, crawling);
			}
			__except (1) { resetcondig = true;
				printf(_("[matrix]: Exception occurred in " __FUNCTION__ "!\n"));
				return 0.f;
			}
		}


		bool IsSwimming() {
			__try {
				if (!ValidPtr(this)) return false;
				static auto IsSwimming = reinterpret_cast<bool (*)(BasePlayer*)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("BasePlayer"), _("IsSwimming"), 0)));

				return IsSwimming(this);
			}
			__except (1) { resetcondig = true;
				printf(_("[matrix]: Exception occurred in " __FUNCTION__ "!\n"));
				return false;
			}
		}


		float GetRadius() {
			__try {
				if (!ValidPtr(this)) return 0.f;
				static auto _GetRadius = reinterpret_cast<float(*)(BasePlayer*)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("BasePlayer"), _("GetRadius"), 0)));

				return _GetRadius(this);
			}
			__except (1) { resetcondig = true;
				printf(_("[matrix]: Exception occurred in " __FUNCTION__ "!\n"));
				return 0.f;
			}
		}

		float GetHeight() {
			__try {
				if (!ValidPtr(this)) return 0.f;
				static auto GetHeight = reinterpret_cast<float(*)(BasePlayer*)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("BasePlayer"), _("GetHeight"), 0)));

				return GetHeight(this);
			}
			__except (1) { resetcondig = true;
				printf(_("[matrix]: Exception occurred in " __FUNCTION__ "!\n"));
				return 0.f;
			}
		}
		bool is_alive() {
			__try {
				if (!ValidPtr((uintptr_t*)this)) return 0;
				return this->lifestate() == BaseCombatEntity_LifeState::Alive;
			}
			__except (1) { resetcondig = true;
				printf(_("[matrix]: Exception occurred in " __FUNCTION__ "!\n"));
				return false;
			}
		}

		bool SETis_alive() {
			__try {
				if (!ValidPtr((uintptr_t*)this)) return 0;
				return this->lifestate() = BaseCombatEntity_LifeState::Dead;
			}
			__except (1) {
				resetcondig = true;
				printf(_("[matrix]: Exception occurred in " __FUNCTION__ "!\n"));
				return false;
			}
		}
		bool SETis_alive1() {
			__try {
				if (!ValidPtr((uintptr_t*)this)) return 0;
				*reinterpret_cast<float*>(this + SDK::offsets1::player_health) = 100;
 				return this->lifestate() = BaseCombatEntity_LifeState::Alive;

			}
			__except (1) {
				resetcondig = true;
				printf(_("[matrix]: Exception occurred in " __FUNCTION__ "!\n"));
				return false;
			}
		}




		void SendClientTick() {
			__try {
				if (!ValidPtr(this)) return;
				static auto _SendClientTick = reinterpret_cast<void(*)(BasePlayer*)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("BasePlayer"), _("SendClientTick"), 0)));

				_SendClientTick(this);
			}
			__except (1) { resetcondig = true;
				printf(_("[matrix]: Exception occurred in " __FUNCTION__ "!\n"));
				return;
			}
		}

		std::string read_ascii(uint64_t address, std::size_t size = 0x50)
		{
			return std::string(reinterpret_cast<const char*>(address));
		}
		BaseMountable* GetMounted() {
			__try {
				if (!ValidPtr(this)) return nullptr;
				static auto getmounted = reinterpret_cast<BaseMountable * (*)(BasePlayer*)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("BasePlayer"), _("GetMounted"), 0)));

				return getmounted(this);
			}
			__except (1) { resetcondig = true;
				printf(_("[matrix]: Exception occurred in " __FUNCTION__ "!\n"));
				return nullptr;
			}
		}
		float GetJumpHeight1() {
			__try {
				if (!ValidPtr(this)) return -1;
				static auto _getjumpheight = reinterpret_cast<float(*)(BasePlayer*)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("BasePlayer"), _("GetJumpHeight"), 0)));

				return _getjumpheight(this);
			}
			__except (1) { resetcondig = true;
				printf(_("[matrix]: Exception occurred in " __FUNCTION__ "!\n"));
				return 0.f;
			}
		}
		float BoundsPadding() {
			__try {
				if (!ValidPtr(this)) return 0.f;
				static auto _BoundsPadding = reinterpret_cast<float(*)(BasePlayer*)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("BaseEntity"), _("BoundsPadding"), 0)));

				return _BoundsPadding(this);
			}
			__except (1) { resetcondig = true;
				printf(_("[matrix]: Exception occurred in " __FUNCTION__ "!\n"));
				return 0.f;
			}
		}
		utils::maths::vec3_t GetParentVelocity() {
			__try {
				if (!ValidPtr(this)) return utils::maths::vec3_t::Zero();
				static auto getparentvel = reinterpret_cast<utils::maths::vec3_t(*)(BaseEntity*)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("BaseEntity"), _("GetParentVelocity"), 0)));

				return getparentvel(this);
			}
			__except (1) { resetcondig = true;
				printf(_("[matrix]: Exception occurred in " __FUNCTION__ "!\n"));
				return utils::maths::vec3_t(0, 0, 0);
			}
		}
		float max_velocity() {
			__try {
				if (!ValidPtr(this)) return 0.f;
				static auto get_maxspeed = reinterpret_cast<float(*)(BasePlayer*)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("BasePlayer"), _("GetMaxSpeed"), 0)));

				float s = get_maxspeed(this);
				auto m = this->mounted() || interactive_debug;
				if (m)
					return s * 4;
				return s;
			}
			__except (1) { resetcondig = true;
				printf(_("[matrix]: Exception occurred in " __FUNCTION__ "!\n"));
				return 0;
			}
		}
		std::string get_class_name2()
		{
			uintptr_t entity = reinterpret_cast<uintptr_t>(this);
			if (!(entity))
				return std::string();

			uintptr_t object_unk = *reinterpret_cast<uintptr_t*>(entity);
			if (!(object_unk))
				return std::string();

			uintptr_t class_name_ptr = *reinterpret_cast<uintptr_t*>(object_unk + 0x10);
			if (!(class_name_ptr))
				return std::string();

			return read_ascii(class_name_ptr);
		}

	char* get_class_name() {
		pent
			if (!this || (uintptr_t)this < 0xFFFFFFFF || (uintptr_t)this > 0xF000000000000000)
				return ((char*)"");
		auto bp = *reinterpret_cast<uintptr_t*>(this);
		if (!bp)
			return ((char*)"");
		return (char*)*reinterpret_cast<uintptr_t*>(bp + 0x10);
	}


	void SetPlayerFlag(PlayerFlags flag) {
		__try {
			if (!ValidPtr(this)) return;
			int PlayerFlag = *reinterpret_cast<int*>((uintptr_t)this + SDK::offsets1::player_flags);

			*reinterpret_cast<int*>((uintptr_t)this + SDK::offsets1::player_flags) = PlayerFlag |= (int)flag;
		}
		__except (1) { resetcondig = true;
			printf(_("[matrix]: Exception occurred in " __FUNCTION__ "!\n"));
			return;
		}
	}



	void ServerRPC1(rust11::string func) {

		__try {
			pent

				SAPPHIRE_METHOD(set_color_fn, "BaseEntity.ServerRPC()", 1, "funcName", 1, void(*)(BaseEntity*, rust11::string));
			if (!set_color_fn)
				return;

			return set_color_fn(this, func);
		}
		__except (1) { resetcondig = true;
			printf("[ServerRPC1]  occurred inside " __FUNCTION__ "\n");

			return;
		}


	}
	//	closestpoint = reinterpret_cast<utils::maths::vec3_t(*)(BaseEntity*, utils::maths::vec3_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseEntity"), _("ClosestPoint"), 1, _(""), _(""))));

	SDK::utils::maths::vec3_t ClosestPoint(SDK::utils::maths::vec3_t func) {

		__try {
			pent

			static auto closestpoint = reinterpret_cast<SDK::utils::maths::vec3_t(*)(BaseEntity*, SDK::utils::maths::vec3_t)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("BaseEntity"), _("ClosestPoint"), 1)));

			return closestpoint(this, func);
		}
		__except (1) { resetcondig = true;
			printf(_("[1]: ClientInput \n " __FUNCTION__ "!  ClientInput\n"));

			return SDK::utils::maths::vec3_t::Zero();
		}


	}

	
	void ClosestPoin1t() {

		__try {
			pent		
 

		}
		__except (1) { 
			resetcondig = true;
			printf(_("[1]: ClientInput \n " __FUNCTION__ "!  ClientInput\n"));

			return ;
		}


	}



	void ClientInput(InputState* func) {

		__try {
			pent
				//	static auto bpclientinput = reinterpret_cast<void(*)(BasePlayer*, InputState*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BasePlayer"), _("ClientInput"), 1)));
				// void ClientInput(InputState state) { }

				SAPPHIRE_METHOD(set_color_fn, "BasePlayer.ClientInput()", 1, "state", 1, void(*)(BasePlayer*, InputState*));
			if (!set_color_fn)
				return;

			return set_color_fn(this, func);
		}
		__except (1) { resetcondig = true;
			printf(_("[1]: ClientInput \n " __FUNCTION__ "!  ClientInput\n"));

			return;
		}


	}

	auto userid() {
		auto id = *reinterpret_cast<uintptr_t**>((uintptr_t*)this + O::BaseNetworkable::net);
		
		auto userid2 = *reinterpret_cast<int*>((uintptr_t*)id + 0x10);
		return userid2;  
	 
	}


	auto get_last_sent_ticket_time() {
		return *reinterpret_cast<float*>((uintptr_t)this + 0x7EC);//	private float lastSentTickTime; // 0x674
	}
	int get_active_weapon_id()
	{
		uintptr_t entity = reinterpret_cast<uintptr_t>(this);
		if (!entity)
			return int();

		return *reinterpret_cast<int*>(entity + 0x740);
	}
	ItemContainer* get_belt()
	{
		uintptr_t entity = reinterpret_cast<uintptr_t>(this);

		if (!(entity))
			return nullptr;

		uintptr_t address = 0x28; //public ItemContainer containerBelt; // 0x28
		if (!address)
			return nullptr;

		return *reinterpret_cast<ItemContainer**>(entity + address);
	}
	PlayerInventory* get_inventory()
	{
		uintptr_t entity = reinterpret_cast<uintptr_t>(this);
		if (!(entity))
			return nullptr;

		uintptr_t address = offsets1::player_inventory;
		if (!address)
			return nullptr;

		return *reinterpret_cast<PlayerInventory**>(entity + address);
	}

	Item* get_held_item()
	{
		uintptr_t entity = reinterpret_cast<uintptr_t>(this);
		if (!entity)
			return nullptr;

		int active_item_id = get_active_weapon_id();

		if (!active_item_id || active_item_id == NULL)
		{
			return nullptr;
		}

		for (int i = 0; i < 6; i++)
		{
			PlayerInventory* inventory = get_inventory();

			if (!(reinterpret_cast<uintptr_t>(inventory)))
				continue;

			ItemContainer* belt = inventory->get_container_belt();

			if (!(reinterpret_cast<uintptr_t>(belt)))
				continue;

			Item* weapon = belt->get_item(i);

			if (!(reinterpret_cast<uintptr_t>(weapon)))
				continue;

			if (active_item_id == weapon->get_item_uid())
			{
				//	std::printf("weapon %s \n", weapon->get_item_name()->get_data().c_str());

				return weapon;
			}
		}

		return nullptr;
	}


	void modify_player_flags(int flag)
	{
		*reinterpret_cast<int*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::player_flags) = flag;
	}

	void set_admin_flag(int flag) {
		int PlayerFlag = *reinterpret_cast<int*>((uintptr_t)this + SDK::offsets1::player_flags);

		*reinterpret_cast<int*>((uintptr_t)this + SDK::offsets1::player_flags) = PlayerFlag |= (int)flag;
	}
	UnityTransform* get_bone_transform(int bone_id) {
		uintptr_t entity_model = *reinterpret_cast<uintptr_t*>((uintptr_t)this + 0xB8); //public Model model; // 
		uintptr_t bone_dict = *reinterpret_cast<uintptr_t*>(entity_model + 0x48);
		UnityTransform* BoneValue = *reinterpret_cast<UnityTransform**>(bone_dict + 0x20 + bone_id * 0x8);

		return BoneValue;
	}
	auto is_local_player() -> bool
	{
		if (!this)
			return false;

		auto player_model = this->playerModel();
		if (!player_model)
			return false;

		SAPPHIRE_FIELD("PlayerModel", isLocalPlayer);
		return *reinterpret_cast<bool*>(player_model + isLocalPlayer);
	}
	auto name() -> const wchar_t*
	{
		SAPPHIRE_FIELD("BasePlayer", _displayName);
		auto player_name = reinterpret_cast<managed_system::string*>(*reinterpret_cast<std::uintptr_t*>(this + _displayName));
		return player_name->buffer;
	}

	void SpiderMan() {
		*reinterpret_cast<float*>(this + 0xb0) = 0.f;
	}
	float get_health()
	{
		return *reinterpret_cast<float*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::player_health);
	}

	float get_max_health()
	{
		return *reinterpret_cast<float*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::player_max_health);
	}

	PlayerInventory* get_player_inventory()
	{
		return *reinterpret_cast<PlayerInventory**>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::player_inventory);
	}

	PlayerBelt* get_player_belt()
	{
		return *reinterpret_cast<PlayerBelt**>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::player_belt);
	}

	PlayerInput* get_player_input()
	{
		return *reinterpret_cast<PlayerInput**>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::player_input);
	}

	MonoString* get_display_name()
	{
		return *reinterpret_cast<MonoString**>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::player_name);
	}

	PlayerModel* get_player_model_derivate()
	{
		return *reinterpret_cast<PlayerModel**>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::player_model_derivate);
	}

	/*c_model_state* get_player_model()
	{
		return *reinterpret_cast<c_model_state**>(
			reinterpret_cast<uintptr_t>(this) + 0x600);
	}*/

	BaseMovement* get_player_base_movement()
	{
		return *reinterpret_cast<BaseMovement**>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::player_movement);
	}
	bool is_sleeping2()
	{
		__try {
			if (!ValidPtr((uintptr_t*)this)) return 0;
			auto Flags = this->flags1();
			return Flags & 16;
		}
		__except (1) { resetcondig = true;
			printf(_("[matrix]: Exception occurred in " __FUNCTION__ "!\n"));
			return 0;
		}
	}
	bool is_sleeping()
	{
		const auto currentFlag = *reinterpret_cast<int*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::player_flags);

		return ((currentFlag & PlayerFlags2::Sleeping) == PlayerFlags2::Sleeping);
	}

	std::uint32_t get_team()
	{
		return *reinterpret_cast<std::uint32_t*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::player_team);
	}

	std::uint32_t get_active_item_id()
	{
		return *reinterpret_cast<std::uint32_t*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::player_activeitem);
	}

	/*uintptr_t get__lookingAtEntity()
	{
		return *reinterpret_cast<uintptr_t*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::player_looking_at);
	}*/


	void set_admin_flag(PlayerFlags12 flag) {
		int PlayerFlag = *reinterpret_cast<int*>((uintptr_t)this + SDK::offsets1::player_flags);

		*reinterpret_cast<int*>((uintptr_t)this + SDK::offsets1::player_flags) = PlayerFlag |= (int)flag;
	}
	/*void modify_current_view_mode(CameraMode view)
	{
		*reinterpret_cast<int*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::player_viewmode) = view;
	}*/

	Item* get_active_item()
	{
		const auto active_item_id = this->get_active_item_id();
		if (!active_item_id)
			return nullptr;

		const auto inventory = this->get_player_inventory();

		if (!inventory)
			return nullptr;

		const auto belt =
			inventory->get_container_belt();

		if (!belt)
			return nullptr;

		auto items =
			belt->get_items();

		for (const auto& item : items)
		{
			if (!item)
				return nullptr;

			if (item->get_item_uid() == active_item_id)
				return item;
		}

		return nullptr;
	}



	std::vector<Item*> get_BuildingPrivlidge()
	{
		std::vector<Item*> ret;

		const auto pItem_list =
			*reinterpret_cast<uintptr_t*>(
				reinterpret_cast<uintptr_t>(this) + 0x620); //public List<PlayerNameID> authorizedPlayers; // 0x590

		const auto item_array =
			*reinterpret_cast<MonoArray<Item*>**>(
				pItem_list + SDK::offsets1::itemcontainer_item_array);

		const auto item_array_size =
			*reinterpret_cast<int*>(
				pItem_list + SDK::offsets1::itemcontainer_item_array_size);

		for (int i = 0; i < item_array_size; i++)
		{
			auto curr_item =
				item_array->array[i];

			if (!curr_item)
				continue;

			ret.push_back(curr_item);
		}

		return ret;
	}


};

class TOD_CycleParameters
{
public:
	void modify_hour_cycle(float hour)
	{
		*reinterpret_cast<float*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::SkyTOD_CycleParametersHours) = hour;
	}
};

class TOD_DayParameters
{
public:
	void modify_ambient_multiplier(float ambient)
	{
		*reinterpret_cast<float*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::SkyTOD_DayParametersAmbientMultipler) = ambient;
	}

	void modify_reflection_multiplier(float reflection)
	{
		*reinterpret_cast<float*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::SkyTOD_DayParametersReflectionMultipler) = reflection;
	}
};

class TOD_Sky
{
public:
	TOD_CycleParameters* get_cycle_parameters()
	{
		return *reinterpret_cast<TOD_CycleParameters**>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::SkyTOD_CycleParameters);
	}

	TOD_DayParameters* get_day_parameters()
	{
		return *reinterpret_cast<TOD_DayParameters**>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::SkyTOD_DayParameters);
	}
};

class BaseCamera
{
public:
	SDK::utils::maths::mat4x4_t get_view_matrix()
	{
		return *reinterpret_cast<SDK::utils::maths::mat4x4_t*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::base_camera_view_matrix);
	}

	SDK::utils::maths::vec3_t get_position()
	{
		return *reinterpret_cast<SDK::utils::maths::vec3_t*>(
			reinterpret_cast<uintptr_t>(this) + SDK::offsets1::base_camera_position);
	}
};

struct unk2
{
	char pad_0[0x28];
	BaseEntity* entity;
};

struct GameObject
{
	char pad_0[0x18];
	unk2* unk;
};

struct MonoObject
{
	char pad_1[0x30];
	GameObject* object;
	char pad_2[0x1c];
	std::uint16_t tag;
	char pad_3[0xa];
	char* name;
	//MonoString* name;


};

struct unk1
{
	char pad_0[0x8];
	unk1* next;
	MonoObject* object;
};

struct BufferList
{
	char pad_0[0x10];
	std::uint32_t size;
	void* buffer;
};

struct Dictionary
{
	char pad_0[0x20];
	BufferList* keys;
	BufferList* values;
};

struct EntityRealm
{
	char pad_0[0x10];
	Dictionary* list;
};

struct BaseNetworkable
{
	char pad_0[0xb8];
	EntityRealm* entity_realm;
};

#define offset(name, value) const static std::uintptr_t m_##name = value
offset(mod, 0xE8);
offset(camlerp, 0x20);
offset(camspeed, 0x2C);
offset(camlookspeed, 0x34);
offset(item_definition, 0x20);
offset(projectile_spread, 0x30);
offset(projectile_velocity_spread, 0x38);

offset(OcclusionCulling_c, 56966008); // OcclusionCulling_c*
offset(tod_sky_c, 56976808); // tod_sky_c*
offset(ConVar_Culling_c, 56965952); // ConVar_Culling_c*
offset(flashbangoverlay_c, 56902048); // flashbangoverlay_c*
offset(convar_admin_c, 56954176); // convar_admin_c*
offset(localplayer_c, 56971600); // localplayer_c*
offset(convar_graphics_c, 56967448); // convar_graphics_c*
offset(BaseEntity_c, 56957136); // System_Collections_Generic_List_BaseGameMode__c*
offset(ConVar_Client_c, 56959376); // ConVar_Client_c*
offset(Skinnable_c, 57026592); // Skinnable_c*
offset(Maincamera_c, 56968928); // Maincamera_c*

template<typename t>
auto read_chain(const std::uintptr_t address, const std::vector<std::uintptr_t> chain) -> t
{
	auto current = address;

	for (int i = 0; i < chain.size() - 1; i++)
	{
		current = *reinterpret_cast<std::uintptr_t*>(current + chain[i]);
		if (!current)
			continue;

	}
	return *reinterpret_cast<t*>(current + chain[chain.size() - 1]);
};

template <typename t>
class c_list
{
public:

	auto size() -> const std::uint32_t
	{
		return *reinterpret_cast<std::uintptr_t*>(reinterpret_cast<std::uintptr_t>(this) + 0x10);
	}

	auto get(const std::uint32_t idx) -> t
	{
		return read_chain<t>(reinterpret_cast<std::uintptr_t>(this), { 0x18, 0x20ull + (idx * 0x8ull) });
	}
};

class c_base_entity
{
public:

	auto get_client_entities() -> c_list<std::uintptr_t>*
	{



		return  read_chain<c_list<std::uintptr_t>*>(reinterpret_cast<std::uintptr_t>(this), { 0x20, 0x10, 0x28 });
	}
};

class c_convar_client
{
public:

	auto set_camspeed(const float speed) -> void
	{
		*reinterpret_cast<float*>(reinterpret_cast<std::uintptr_t>(this) + m_camspeed) = speed;
	}

	auto set_camlerp(const float lerp) -> void
	{
		*reinterpret_cast<float*>(reinterpret_cast<std::uintptr_t>(this) + m_camlerp) = lerp;
	}

	auto set_camlookspeed(const float speed) -> void
	{
		*reinterpret_cast<float*>(reinterpret_cast<std::uintptr_t>(this) + m_camlookspeed) = speed;
	}
};

struct Ray {
	utils::maths::vec3_t origin1;
	utils::maths::vec3_t dir1;
	Ray(utils::maths::vec3_t o, utils::maths::vec3_t d) {
		origin1 = o;
		dir1 = d;
	}
};

class HitTest
{
public:
	BaseEntity* get_hit_entity();
	utils::maths::vec3_t				get_hit_normal();
	void				set_hit_entity(BaseEntity* entity);
	void				set_hit_transform(UnityTransform* transform);
	void				set_hit_hitpoint(utils::maths::vec3_t hit_point);
	void				set_hit_distance(float distance);
	void				set_max_distance(float distance);
	void				set_did_hit(bool didhit);
	void				set_damage_properties(uintptr_t properties);
	void				set_attack_ray(Ray);
	void				set_hit_normal(utils::maths::vec3_t);
};

void HitTest::set_hit_distance(float distance)
{
	uintptr_t entity = reinterpret_cast<uintptr_t>(this);

	if (!(entity))
		return;



	memory::write<float>(reinterpret_cast<uintptr_t>(this) + 0xA8, distance);


}

void HitTest::set_hit_hitpoint(utils::maths::vec3_t new_hitpoint)
{
	uintptr_t entity = reinterpret_cast<uintptr_t>(this);

	if (!(entity))
		return;


	memory::write<utils::maths::vec3_t>(reinterpret_cast<uintptr_t>(this) + 0x90, new_hitpoint);

}


BaseEntity* HitTest::get_hit_entity()
{
	uintptr_t entity = reinterpret_cast<uintptr_t>(this);

	if (!(entity))
		return nullptr;

	return *reinterpret_cast<BaseEntity**>(entity + 0x88);
}

std::string read_ascii(uint64_t address, std::size_t size)
{
	return std::string(reinterpret_cast<const char*>(address));
}
class c_game_assembly
{
public:

	auto get_base_entity(uintptr_t SDK) -> c_base_entity* // System_Collections_Generic_List_BaseGameMode__c*
	{
		return  read_chain<c_base_entity*>(SDK, { m_BaseEntity_c, 0xB8 }); // "Signature": "BaseEntity_c*"
	}

	auto get_convar_client(uintptr_t SDK) -> c_convar_client*
	{
		return  read_chain<c_convar_client*>(SDK, { m_ConVar_Client_c, 0xB8 }); // "Signature": "ConVar_Client_c*"
	}
}*
assembly;



Transform1* BaseEntity::get_transform1()
{
	uintptr_t entity = reinterpret_cast<uintptr_t>(this);
	if (!entity)
		return nullptr;
	SAPPHIRE_FIELD("Component", get_transform);

	uintptr_t method = il2cpp_lib::method3(xorstr_("Component"), xorstr_("get_transform"), 0, xorstr_("UnityEngine"));
	if (!method)	
		return nullptr;
	

	uintptr_t method_ptr = *reinterpret_cast<uintptr_t*>(method);
	if (method_ptr)
		return nullptr;
	

	auto get_transform1 = reinterpret_cast<Transform1 * (*)(uintptr_t entity)>(method_ptr);
	return get_transform1(entity);
}

utils::maths::vec3_t  Transform1::get_position()
{
	uintptr_t transform = reinterpret_cast<uintptr_t>(this);
	if (!(transform))
		return utils::maths::vec3_t();
	SAPPHIRE_FIELD("Transform", get_position);

	uintptr_t method = get_position;
	if (!(method))
		return utils::maths::vec3_t();

	uintptr_t method_ptr = *reinterpret_cast<uintptr_t*>(method);
	if (!(method_ptr))
		return utils::maths::vec3_t();

	auto get_transform_position = reinterpret_cast<utils::maths::vec3_t(*)(uintptr_t transform)>(method_ptr);
	return get_transform_position(transform);
}

utils::maths::vec3_t Transform1::inverse_tranform_point(utils::maths::vec3_t point)
{
	uintptr_t transform = reinterpret_cast<uintptr_t>(this);
	if (!transform)
		return utils::maths::vec3_t();


	SAPPHIRE_FIELD("Transform", InverseTransformPoint);

	uintptr_t method = InverseTransformPoint; //il2cpp_lib::method3(xorstr_("Transform"), xorstr_("InverseTransformPoint"), 1, xorstr_("UnityEngine"));
	if (!(method))
	{
		return utils::maths::vec3_t();
	}

	uintptr_t method_ptr = *reinterpret_cast<uintptr_t*>(method);
	if (!(method_ptr))
	{
		return utils::maths::vec3_t();
	}

	auto inverse_tranform_point = reinterpret_cast<utils::maths::vec3_t(*)(uintptr_t transform, utils::maths::vec3_t position)>(method_ptr);
	return inverse_tranform_point(transform, point);
}


utils::maths::vec3_t Transform1::transform_direction(utils::maths::vec3_t point) {
	__try {
		if (!this || (uintptr_t)this <= 0xFFFFFFFF || (uintptr_t)this >= 0x1000000000000000) return utils::maths::vec3_t(0, 0, 0);
		static auto _InverseTransformDirection = reinterpret_cast<utils::maths::vec3_t(*)(uintptr_t, utils::maths::vec3_t)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("Transform"), _("InverseTransformDirection"), 1, _("UnityEngine"))));

		return _InverseTransformDirection((uintptr_t)(this), point);
	}
	__except (1) { resetcondig = true;
		printf("[matrix] Exception occurred inside " __FUNCTION__ "\n");
		return utils::maths::vec3_t(0, 0, 0);
	}
}


class Bounds {
public:
	utils::maths::vec3_t m_center;
	utils::maths::vec3_t m_extents;
	utils::maths::vec3_t center;
	utils::maths::vec3_t extents;
	utils::maths::vec3_t max;
	utils::maths::vec3_t min;
	utils::maths::vec3_t size;
};

class BaseHelicopter_Weakspot {
public:
	FIELD(0x20, maxHealth, float);
	FIELD(0x24, health, float);
};

class StringPool {
public:
	static unsigned int Get(System::String str) {
		__try {
			typedef unsigned int(__stdcall* StringPool_Get)(System::String str);
			auto z = ((StringPool_Get)((std::intptr_t)GetModuleHandleW(xorstr_(L"GameAssembly.dll")) + oStringPool))(str);//public static uint Get(string str) { }  dump.cs public class StringPool // TypeDefIndex: 2663
			printf("%d\n", z);
			return z;
		}
		__except (1) { resetcondig = true;
			printf(_("[matrix]: Exception occurred in " __FUNCTION__ "!\n"));
			return 0;
		}
	}
};
class BaseHelicopter {
public:
	FIELD(O::BaseHelicopter::weakspots, weakspots, System::Array<BaseHelicopter_Weakspot*>*);
};
const class Projectile {
public:
	FIELD(O::Projectile::drag, drag, float);
	FIELD(O::Projectile::gravityModifier, gravityModifier, float);
	FIELD(O::Projectile::initialVelocity, initialVelocity, utils::maths::vec3_t);
	FIELD(O::Projectile::currentPosition, currentPosition, utils::maths::vec3_t);
	FIELD(O::Projectile::currentVelocity, currentVelocity, utils::maths::vec3_t);
	FIELD(O::Projectile::thickness, thickness, float);
	FIELD(O::Projectile::hitTest, hitTest, HitTest*);
	FIELD(O::Projectile::previousPosition, previousPosition, utils::maths::vec3_t);
	FIELD(O::Projectile::traveledTime, traveledTime, float);
	FIELD(O::Projectile::traveledDistance, traveledDistance, float);
	FIELD(O::Projectile::projectileID, projectileID, int);
	FIELD(O::Projectile::integrity, integrity, int);


};

class AttackEntity1 : public HeldEntity {
public:
	FIELD(O::AttackEntity::nextAttackTime, nextAttackTime, float);
	FIELD(O::AttackEntity::timeSinceDeploy, timeSinceDeploy, float);
	FIELD(O::AttackEntity::deployDelay, deployDelay, float);
	FIELD(O::AttackEntity::repeatDelay, repeatDelay, float);
};

const class BaseProjectile1 : public Transform1 {
public:
	FIELD(O::BaseProjectile::projectileVelocityScale, projectileVelocityScale, float);
	FIELD(O::BaseProjectile::aimCone, aimCone, float);
	FIELD(O::BaseProjectile::hipAimCone, hipAimCone, float);
	FIELD(O::BaseProjectile::aimConePenaltyMax, aimConePenaltyMax, float);
	FIELD(O::BaseProjectile::aimconePenaltyPerShot, aimconePenaltyPerShot, float);
	FIELD(O::BaseProjectile::stancePenaltyScale, stancePenaltyScale, float);
	FIELD(O::BaseProjectile::reloadTime, reloadTime, float);
	FIELD(O::BaseProjectile::primaryMagazine, primaryMagazine1, Magazine*);
	FIELD(O::Projectile::drag, drag, float);
	FIELD(O::Projectile::gravityModifier, gravityModifier, float);
	FIELD(O::Projectile::initialVelocity, initialVelocity, utils::maths::vec3_t);
	FIELD(O::Projectile::currentPosition, currentPosition, utils::maths::vec3_t);
	FIELD(O::Projectile::currentVelocity, currentVelocity, utils::maths::vec3_t);
	FIELD(O::Projectile::thickness, thickness, float);
	FIELD(O::Projectile::hitTest, hitTest, HitTest*);
	FIELD(O::Projectile::previousPosition, previousPosition, utils::maths::vec3_t);
	FIELD(O::Projectile::traveledTime, traveledTime, float);
	FIELD(O::Projectile::traveledDistance, traveledDistance, float);
	FIELD(O::Projectile::projectileID, projectileID, int);
	FIELD(O::Projectile::integrity, integrity, int);
	 
	Transform* transform() {
		__try {
			if (!ValidPtr(this)) return nullptr;

			static auto gettrans = reinterpret_cast<uintptr_t(*)(uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("Component"), _("get_transform"), 0, _("UnityEngine"))));

			return (Transform*)gettrans((uintptr_t)this);
		}
		__except (1) { resetcondig = true;
			return nullptr;
		}
	}

	void remove_ammo() {
		__try {
			if (!ValidPtr(this)) return;
			const auto mag = *reinterpret_cast<uintptr_t*>((uintptr_t)this + O::BaseProjectile::primaryMagazine);
			if (!ValidPtr((uintptr_t*)mag)) return;
			auto ammo = *reinterpret_cast<int*>(mag + 0x1C);
			*reinterpret_cast<int*>(mag + 0x1C) = (ammo - 1);

			//il2::updateammodisplay((uintptr_t)this);
			//il2::shot_fired((uintptr_t)this);
		//	il2::did_attack_client_side((uintptr_t)this);
		}
		__except (1) { resetcondig = true;
			printf("[remove_ammo]  occurred inside " __FUNCTION__ "\n");

			return;
		}
	}

	int ammo_left() {
		__try {
			if (!ValidPtr(this)) return -1;
			const auto mag = *reinterpret_cast<uintptr_t*>((uintptr_t)this + O::BaseProjectile::primaryMagazine);
			if (!ValidPtr((uintptr_t*)mag)) return -1;
			const auto ammo = *reinterpret_cast<int*>(mag + 0x1C);
			return ammo;
		}
		__except (1) { resetcondig = true;
			printf(_("[matrix]: Exception occurred in " __FUNCTION__ "!\n"));
			return -1;
		}
	}
	uintptr_t get_damage_properties() {
		pent
			return *reinterpret_cast<uintptr_t*>((uintptr_t)this + O::BaseMelee::damageProperties);
	}

	uint32_t get_size() { pent return *reinterpret_cast<uint32_t*>((uintptr_t)this + 0x18); }

	float oyx = 0.f;
	float oyy = 0.f;
	float opx = 0.f;
	float opy = 0.f;


	void set_success_fraction() {
		pent
			* reinterpret_cast<float*>((uintptr_t)this + 0x3A0) = 1.f; //	public float successFraction; // 0x3A0

	}

	void set_did_spark_this_frame(bool state) {//eoka
		pent
			* reinterpret_cast<bool*>((uintptr_t)this + 0x3B0) = state; //	private bool _didSparkThisFrame; // 0x3B0
	}
	int max_ammo() {
		__try {
			if (!ValidPtr(this)) return -1;
			const auto mag = *reinterpret_cast<uintptr_t*>((uintptr_t)this + O::BaseProjectile::primaryMagazine);
			if (!ValidPtr((uintptr_t*)mag)) return -1;
			const auto ammo = *reinterpret_cast<int*>(mag + 0x18);
			return ammo;
		}
		__except (1) { resetcondig = true;
			printf(_("[matrix]: Exception occurred in " __FUNCTION__ "!\n"));
			return -1;
		}
	}
};
class col {
public:
	float r;
	float g;
	float b;
	float a;
	col(float rr, float gg, float bb, float aa) {
		r = rr;
		g = gg;
		b = bb;
		a = aa;
	}
};
 class Time {
public:
	static float deltaTime() {
		__try {
			//	return get_deltaTime();
			static auto get_deltaTime = reinterpret_cast<float(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("Time"), _("get_deltaTime"), 0, _("UnityEngine"))));

 			return get_deltaTime();
		}
		__except (1) { resetcondig = true;
			printf(_("[matrix]: Exception occurred inside " __FUNCTION__ "\n"));
			return -1.f;
		}
	}

	static float realtimeSinceStartup() {
		__try {
			//	return get_realtimesincestartup();
			static auto get_realtimesincestartup = reinterpret_cast<float(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("Time"), _("get_realtimeSinceStartup"), 0, _("UnityEngine"))));

 
			return get_realtimesincestartup();
		}
		__except (1) { resetcondig = true;
			printf(_("[matrix]: Exception occurred inside " __FUNCTION__ "\n"));
			return -1.f;
		}
	}
	static float time() {
		__try {
			//	return get_time();
			SAPPHIRE_METHOD(get_renderers_fn, "UnityEngine::Time.get_time()", 0, "", -1, float(*)());
			return get_renderers_fn();
		}
		__except (1) { resetcondig = true;
			printf(_("[matrix]: Exception occurred inside " __FUNCTION__ "\n"));
			return -1.f;
		}
	}
	static float fixedTime() {
		__try {
			//	return get_fixedTime();
			SAPPHIRE_METHOD(get_renderers_fn, "UnityEngine::Time.get_fixedTime()", 0, "", -1, float(*)());
			return get_renderers_fn();
		}
		__except (1) { resetcondig = true;
			printf(_("[matrix]: Exception occurred inside " __FUNCTION__ "\n"));
			return -1.f;
		}
	}
	static auto getTimescale() -> float {
		SAPPHIRE_METHOD(get_screen_width_fn, "UnityEngine::Time.get_timeScale()", 0, "", -1, float (*)());
		return get_screen_width_fn();
	}

	float getTimescale1() {
		__try {
			//	//	static auto get_timeScale = reinterpret_cast<float(*)()>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("Time"), _("get_timeScale"), 0, _("UnityEngine"))));

			SAPPHIRE_METHOD(get_renderers_fn, "UnityEngine::Time.get_timeScale()", 0, "", -1, float(*)());
			return get_renderers_fn();

		}
		__except (1) { resetcondig = true;
			printf(_("[matrix]: Exception occurred inside " __FUNCTION__ "\n"));
			return -1.f;
		}
	}


	static void setTimescale(float scale) {
		__try {
			//static auto set_timeScale = reinterpret_cast<void(*)(float)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("Time"), _("set_timeScale"), 1, _("UnityEngine"))));

			SAPPHIRE_METHOD(set_color_fn, "UnityEngine::Time.set_timeScale()", 1, "", 1, void(*)(float));
			if (!set_color_fn)
				return;

			set_color_fn(scale);
		}
		__except (1) { resetcondig = true;
			printf(_("[matrix]: Exception occurred inside " __FUNCTION__ "\n"));
		}
	}
};


bool LineCircleIntersection(utils::maths::vec3_t center,
	float radius,
	utils::maths::vec3_t rayStart,
	utils::maths::vec3_t rayEnd,
	float& offset)
{
	utils::maths::vec2_t P(rayStart.x, rayStart.z);
	utils::maths::vec2_t Q(rayEnd.x, rayEnd.z);

	float a = Q.y - P.y;
	float b = P.x - Q.x;
	float c = (a * (P.x) + b * (P.y)) * -1.f;

	float x = center.x;
	float y = center.z;

	float c_x = (b * ((b * x) - (a * y)) - a * c) / (std::pow(a, 2) + std::pow(b, 2));
	float c_y = (a * ((-b * x) + (a * y)) - (b * c)) / (std::pow(a, 2) + std::pow(b, 2));

	utils::maths::vec2_t closestPoint(c_x, c_y);

	float distance = P.Distance2(Q);

	if (P.Distance2(closestPoint) > distance || Q.Distance2(closestPoint) > distance)
	{
		return false;
	}

	if (radius > closestPoint.Distance2(utils::maths::vec2_t(center.x, center.z)))
	{
		utils::maths::vec2_t P(rayStart.x, rayStart.y);
		utils::maths::vec2_t Q(rayEnd.x, rayEnd.y);

		float a = Q.y - P.y;
		float b = P.x - Q.x;
		float c = (a * (P.x) + b * (P.y)) * -1.f;

		float x = center.x;
		float y = center.y;

		float c_x = (b * ((b * x) - (a * y)) - a * c) / (std::pow(a, 2) + std::pow(b, 2));
		float c_y = (a * ((-b * x) + (a * y)) - (b * c)) / (std::pow(a, 2) + std::pow(b, 2));

		utils::maths::vec2_t closestPoint(c_x, c_y);
		if (radius > closestPoint.Distance2(utils::maths::vec2_t(center.x, center.y)))
		{
			return true;
		}
		else
		{
			offset += std::fabs(center.y - closestPoint.y);
			return false;
		}
	}

	return false;
}
bool GetPrediction(
	utils::maths::vec3_t origin,
	utils::maths::vec3_t original_velocity,
	utils::maths::vec3_t target,
	utils::maths::vec3_t targetvelocity,
	utils::maths::vec3_t& aimbot_velocity,
	float& travelTime,
	float drag,
	float gravityModifier,
	float timescale) {
	utils::maths::vec3_t gravity = utils::maths::vec3_t(0, -9.81f, 0);
	int current_sims = 0;
	int max_sims = 100;

	float offset = -.5f;
	bool with_travel = false;
gl:
	while (current_sims < max_sims) {
		travelTime = 0;
		auto pos = origin;
		auto orig = pos;
		float num = Time::deltaTime() * timescale;

		int num3 = (int)(8.f / num);

		utils::maths::vec3_t vt = target + utils::maths::vec3_t(0, offset, 0);
		utils::maths::vec3_t ovelocity = (vt - origin).Normalized11() * original_velocity.length1();
		utils::maths::vec3_t velocity = ovelocity;

		for (size_t i = 0; i < num3; i++) {
			orig = pos;
			pos += velocity * num;
			velocity += gravity * gravityModifier * num;
			velocity -= velocity * drag * num;
			travelTime += num;
			if (LineCircleIntersection(target, 0.07f, orig, pos, offset)) {
				aimbot_velocity = ovelocity;
				break;
			}
		}

		if (!aimbot_velocity.empty())
			break;

		offset += .05f;
		current_sims++;
	}

	if (with_travel) return true;

	if (travelTime > 0) {
		auto finalVel = (utils::maths::vec3_t(targetvelocity.x, 0, targetvelocity.z) * 0.91f) * travelTime;
		target += finalVel;
		aimbot_velocity = utils::maths::vec3_t::Zero();
		with_travel = true; offset = -.5f; current_sims = 0;
		goto gl;
	}
}

#define STR_MERGE_IMPL(a, b) a##b
#define STR_MERGE(a, b) STR_MERGE_IMPL(a, b)
#define MAKE_PAD(size) STR_MERGE(_pad, __COUNTER__)[size]
#define member(type, name, offset) struct {unsigned char MAKE_PAD(offset); type name;}
#define min(a,b)            (((a) < (b)) ? (a) : (b))



class Attack {
public:
	union {
		member(utils::maths::vec3_t, pointStart, 0x10);
		member(utils::maths::vec3_t, pointEnd, 0x1C);
		member(unsigned int, hitID, 0x28);
		member(unsigned int, hitBone, 0x30);
		member(utils::maths::vec3_t, hitNormalLocal, 0x34);
		member(utils::maths::vec3_t, hitPositionLocal, 0x40);
		member(utils::maths::vec3_t, hitNormalWorld, 0x4C);
		member(utils::maths::vec3_t, hitPositionWorld, 0x58);
		member(unsigned int, hitPartID, 0x64);
		member(unsigned int, hitMaterialID, 0x68);
		member(unsigned int, hitItem, 0x48);
	};
};
class PlayerAttack {
public:
	union {
		member(Attack*, attack, 0x10);
	};
};

class PlayerProjectileAttack {
public:
	union {
		member(PlayerAttack*, playerAttack, 0x10);
		member(utils::maths::vec3_t, hitVelocity, 0x18);
		member(float, hitDistance, 0x24);
		member(float, travelTime, 0x28);
	};
};

static bool LineOfSightRadius(utils::maths::vec3_t source, utils::maths::vec3_t destination, uintptr_t ent, float p1 = 0.18f, int layer = 1218519041) {
	__try {
		static auto LineOfSightInternal = reinterpret_cast<bool(*)(utils::maths::vec3_t, utils::maths::vec3_t, int, float, float, float, uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("GamePhysics"), _("LineOfSightInternal"), -1)));

		return LineOfSightInternal(source, destination, layer, p1, 0, 0, ent);
	}
	__except (true)
	{ 
		printf("[LineOfSightRadius]  occurred inside " __FUNCTION__ "\n");

		return false; 
	}
}

static bool is_visible(utils::maths::vec3_t source, utils::maths::vec3_t destination, uintptr_t ent = 0, float p1 = 0.18f) {
	return LineOfSightRadius(source, destination, ent, p1)
		&& LineOfSightRadius(destination, source, ent, p1);
}

bool PLOS(utils::maths::vec3_t a, utils::maths::vec3_t b, int layerMask = 10551296) {
	return is_visible(a, b, (uintptr_t)local_player);
}

bool TestNoClipping(BasePlayer* ply = local_player,
	utils::maths::vec3_t oldPos = utils::maths::vec3_t(0, 0, 0),
	utils::maths::vec3_t newPos = utils::maths::vec3_t(0, 0, 0),
	float radius = 0.01f,
	float backtracking = 0.01f)
{
	utils::maths::vec3_t normalized = (newPos - oldPos).Normalized11();
	utils::maths::vec3_t vector = oldPos - normalized * backtracking;
	float magnitude = (newPos - vector).Length();
	Ray z = Ray(vector, normalized);

	bool flag = false; //unity::Raycast(z, magnitude + radius, 429990145);


	typedef bool (*AAA)(Ray, float, float, int);
	//real rust 0x2298A50
	//alkad rust 0x2271FB0
	flag = ((AAA)((std::intptr_t)GetModuleHandleW(xorstr_(L"GameAssembly.dll")) + oSphereCast))(z, radius, magnitude, 429990145);
	return flag;
}
class TickInterpolator {
private:
	struct Segment {
		utils::maths::vec3_t point;
		float length;
		Segment(utils::maths::vec3_t a, utils::maths::vec3_t b) {

			this->point = b;
			this->length = a.distance(b);
		}
	};
public:
	std::vector<Segment> points = std::vector<Segment>();
	int index;
	float len;
	utils::maths::vec3_t currentPoint;
	utils::maths::vec3_t startPoint;
	utils::maths::vec3_t endPoint;

	void Reset() {

		this->index = 0;
		this->currentPoint = this->startPoint;
	}
	void Reset(utils::maths::vec3_t point) {

		this->points.clear();
		this->index = 0;
		this->len = 0.f;
		this->endPoint = point;
		this->startPoint = point;
		this->currentPoint = point;
	}
	void AddPoint(utils::maths::vec3_t point) {

		Segment segment = Segment(this->endPoint, point);
		this->points.push_back(segment);
		this->len += segment.length;
		this->endPoint = segment.point;
	}
	bool MoveNext(float distance) {

		float num = 0.f;
		while (num < distance && this->index < this->points.size()) {

			Segment segment = this->points[this->index];
			this->currentPoint = segment.point;
			num += segment.length;
			this->index++;
		}
		return num > 0.f;
	}
	bool HasNext() {

		return this->index < this->points.size();
	}
};
bool ValidateEyePos(utils::maths::vec3_t pos,
	utils::maths::vec3_t offset = utils::maths::vec3_t(0, 0, 0))
{
	bool flag = true;
	auto loco = local_player;
	auto eyepos = loco->eyes()->position() + offset;
	float num = 1.5f;
	float num2 = 2.f / 60.f;
	float deltatime = Time::deltaTime();
	//float smooth_deltatime = get_smoothdeltaTime();
	//float fixed_deltatime = get_fixeddeltaTime();
	float num3 = 2.f * deltatime;
	float num4 = (1.f + num2 + num3) * num;
	float num5 = loco->max_velocity() + loco->GetParentVelocity().Length();
	float num6 = loco->BoundsPadding() + num4 * num5;
	float num7 = eyepos.distance(pos);
	float num8 = fabs(loco->GetParentVelocity().y);
	float num9 = loco->BoundsPadding() + num4 + num8 + loco->GetJumpHeight();
	float num10 = fabs(eyepos.y - pos.y);

	if (num10 > num9)
	{
		flag = false;
	}

	utils::maths::vec3_t re_p = loco->model()->boneTransforms()->get(47)->position() + loco->model()->boneTransforms()->get(47)->up() * (loco->eyes()->viewOffset().y + loco->eyes()->EyeOffset().y);

	auto t = loco->transform();
	utils::maths::vec3_t loco_position = t->position();
	utils::maths::vec3_t actual_eye_pos = loco->eyes()->position();

	//LOS from eyes.center to eyes.position on server, i think eyes.position is lastSentTick.pos
	//if(loco->is_visible(, pos))

	if (!LineOfSightRadius(misc::v_LastSentTickPos, eyepos, (uintptr_t)local_player, .2f))
		flag = false;
	//if (!loco->is_visible(cLastTickPos, eyepos, 0.18f)) {
	//	//local_player->console_echo(_(L"[matrix]: ValidateEyePos - eye_los caught"));
	//	flag = true;
	//}

	if (loco_position.distance(loco->eyes()->position()) > 0.06f
		&& TestNoClipping(loco, misc::v_LastSentTickPos, loco_position, .3f))
		//&& TestNoClipping(loco, cLastTickEyePos, position2))
	{
		flag = false;
	}
	else if (loco_position.distance(loco->eyes()->position()) > 0.01f
		&& TestNoClipping(loco, actual_eye_pos, eyepos, 0.02f)) {
		flag = false;
	}

	//if (!flag)
	//{
	//	//AddViolation(loco, 
	//	//	antihacktype::EyeHack, 
	//	//	protections::eye_penalty); 
	//}
	//else if (protections::eye_protection >= 5 &&
	//	loco->modelState()->has_flag(ModelState_Flag::Mounted)) {
	//	eye_history.push_back(pos);
	//}

	return flag;
}

bool can_manipulate(BasePlayer* ply)
{
	if (!ply)
		return false;
	if (!ply->get_entity_model())
		return false;
	 

	if (!best_target.ent)
		return false;

	if (!best_target.ent->get_entity_model())
		return false;


	bool IsMounted = ply->GetMounted() ? 1 : 0;
	static auto get_maxspeed = reinterpret_cast<float(*)(BasePlayer*)>(*reinterpret_cast<uintptr_t*>(il2cpp_lib::method3(_("BasePlayer"), _("GetMaxSpeed"), 0)));

	float maxVelocity = get_maxspeed(ply);
	if (IsMounted)
		maxVelocity *= 4;
	float _timeSinceLastTick = Time::realtimeSinceStartup() - ply->get_last_sent_ticket_time();
	float timeSinceLastTickClamped = max(0.f, min(_timeSinceLastTick, 1.f));
	float mm_eye = 0.1f + (timeSinceLastTickClamped + 2.f / 60.f) * 1.5f * maxVelocity;

	//utils::maths::vec3_t v = *reinterpret_cast<utils::maths::vec3_t*>((uintptr_t)ply + O::BasePlayer::eyes);
	utils::maths::vec3_t re_p = ply->model()->boneTransforms()->get(47)->position() + ply->model()->boneTransforms()->get(47)->up() * (ply->eyes()->viewOffset().y + ply->eyes()->EyeOffset().y);
	//utils::maths::vec3_t re_p = ply->transform()->position() + ply->transform()->up() * (ply->eyes()->get_view_offset().y + v.y);

	auto pos = best_target.pos;

	if (is_visible(re_p, pos, 0)) {
		best_lean = utils::maths::vec3_t(0, 0, 0);
		return true;
	}
	auto layermask = 1218519041;

	auto HitScan = [&](utils::maths::vec3_t from, bool do_ = true, int val = 0) {
		utils::maths::vec3_t head_pos_ = best_target.pos;

		
		if (!do_)
			return std::make_pair(false, head_pos_);

		 
			return std::make_pair(PLOS(from, head_pos_, layermask), head_pos_);
	};

	//HitScan returns pair { lineofsight, targetposition }
	misc::best_target = utils::maths::vec3_t::Zero();

	auto do_check = [&](utils::maths::vec3_t a) {
		utils::maths::vec3_t p = re_p + a;

		//check between manip pos and eye pos
		if (!is_visible(p, re_p, 0))
			return false;

		//if (!ply->is_visible(p - utils::maths::vec3_t(0, 0.3, 0), re_p)) //double check not too low as likes to shoot from just under the ground
		//	return false;

	
		//check between manip pos and player pos
		if (!is_visible(p, pos, 0))
		{
			if (!thick_bullet || !targetbehindwall) return false;
			bool t = false;
			utils::maths::vec3_t z = pos;
 			std::array<utils::maths::vec3_t, 10> positions = {
				z + utils::maths::vec3_t(0, .3f, 0),
				z + utils::maths::vec3_t(0, 1.f, 0),
				z + utils::maths::vec3_t( thickness / 2, 0, 0),
				z + utils::maths::vec3_t(- thickness / 2, 0, 0),
				z + utils::maths::vec3_t(0, 0,  thickness / 2),
				z + utils::maths::vec3_t(0, 0, - thickness / 2),
				z + utils::maths::vec3_t( thickness - 0.02f, 0, 0),
				z + utils::maths::vec3_t(- thickness + 0.02f, 0, 0),
				z + utils::maths::vec3_t(0, 0,  thickness - 0.02f),
				z + utils::maths::vec3_t(0, 0, - thickness + 0.02f)
			};
 			for (auto v : positions) {
				 
				if (is_visible(p, v, 0))
				{
					if (is_visible(z, v, 0))
					{
						t = true;
						misc::best_target = v;
						break;
					}
				}
			}

			if (!t) return false;
		}

		//fuck you
		if (!ValidateEyePos(p))
			return false;

		 

		best_lean = p;
		//misc::best_target = pos;
		return true;
	};

	int points =  thick_bullet ? 7 : 20;
	for (float y = 0; y < 1.5f; y +=  targetbehindwall ? 0.3f : 0.1f) {
		float step = (M_PI_2) / points;
		float x, z, current = 0;
		for (size_t i = 0; i < points; i++)
		{
			x = utils::maths::vec3_t::my_sin(current) * mm_eye;
			z = utils::maths::vec3_t::my_cos(current) * mm_eye;

			utils::maths::vec3_t p1 = utils::maths::vec3_t(x, y, z);
			utils::maths::vec3_t p2 = utils::maths::vec3_t(-x, y, z);
			utils::maths::vec3_t p3 = utils::maths::vec3_t(x, y, -z);
			utils::maths::vec3_t p4 = utils::maths::vec3_t(-x, y, -z);

			if (do_check(p1)) return true;
			if (do_check(p2)) return true;
			if (do_check(p3)) return true;
			if (do_check(p4)) return true;

			current += step;
		}
	}
	for (float y = 0; y > -1.5f; y -=   targetbehindwall ? 0.3f : 0.1f) {
		float step = (M_PI_2) / points;
		float x, z, current = 0;
		for (size_t i = 0; i < points; i++)
		{
			x = utils::maths::vec3_t::my_sin(current) * mm_eye;
			z = utils::maths::vec3_t::my_cos(current) * mm_eye;

			utils::maths::vec3_t p1 = utils::maths::vec3_t(x, y, z);
			utils::maths::vec3_t p2 = utils::maths::vec3_t(-x, y, z);
			utils::maths::vec3_t p3 = utils::maths::vec3_t(x, y, -z);
			utils::maths::vec3_t p4 = utils::maths::vec3_t(-x, y, -z);

			if (do_check(p1)) return true;
			if (do_check(p2)) return true;
			if (do_check(p3)) return true;
			if (do_check(p4)) return true;

			current += step;
		}
	}

	best_lean = utils::maths::vec3_t(0, 0, 0);
	return false;
}

class ModelState {
public:
	bool HasFlag(ModelState_Flag flag) {
		__try {
			if (!ValidPtr(this)) return false;
			int flags = *reinterpret_cast<int*>((uintptr_t)this + O::ModelState::flags);
			return (flags & (int)flag) != 0;
		}
		__except (1) { resetcondig = true;
			printf(_("[matrix]: Exception occurred in " __FUNCTION__ "!\n"));
			return false;
		}
	}
	float WaterLevel() {
		__try {
			if (!ValidPtr(this)) return 0.f;
			return *reinterpret_cast<float*>((uintptr_t)this + O::ModelState::waterLevel);
		}
		__except (1) { resetcondig = true;
			printf(_("[matrix]: Exception occurred in " __FUNCTION__ "!\n"));
			return 0.f;
		}
	}
	void SetFlag(ModelState_Flag flag) {
		__try {
			if (!ValidPtr(this)) return;
			int flags = *reinterpret_cast<int*>((uintptr_t)this + O::ModelState::flags);
			*reinterpret_cast<int*>((uintptr_t)this + O::ModelState::flags) = flags |= (int)flag;
		}
		__except (1) { resetcondig = true;
			printf(_("[matrix]: Exception occurred in " __FUNCTION__ "!\n"));
			return;
		}
	}
	void RemoveFlag(ModelState_Flag flag) {
		__try {
			if (!ValidPtr(this)) return;
			int flags = *reinterpret_cast<int*>((uintptr_t)this + O::ModelState::flags);
			flags &= ~(int)flag;
			*reinterpret_cast<int*>((uintptr_t)this + O::ModelState::flags) = flags;
		}
		__except (1) { resetcondig = true;
			printf(_("[matrix]: Exception occurred in " __FUNCTION__ "!\n"));
			return;
		}
	}

};

void DisableServerCommands() {
	__try {
		auto klass = *reinterpret_cast<uintptr_t*>((std::intptr_t)GetModuleHandleW(xorstr_(L"GameAssembly.dll")) + oConsoleSystem_Index_c);
		if (!klass)
			return;
		auto fieldz = *reinterpret_cast<uintptr_t*>(klass + 0xb8);
		if (!fieldz)
			return;
		struct consolesystem_command {
			FIELD(0x10, Name, System::String*);
			FIELD(0x58, AllowRunFromServer, bool);
		};

		auto all = *reinterpret_cast<System::Array<consolesystem_command*>**>(fieldz + 0x10);
		if (all->size() < 1)
			return;
		for (size_t i = 0; i < all->size(); i++) {
			auto m = all->get(i);
			if (!wcscmp(m->Name()->str, L"noclip")
				&& m->AllowRunFromServer())
				m->AllowRunFromServer() = false;
			else if (!wcscmp(m->Name()->str, L"debugcamera")
				&& m->AllowRunFromServer())
				m->AllowRunFromServer() = false;
			else if (!wcscmp(m->Name()->str, L"camspeed")
				&& m->AllowRunFromServer())
				m->AllowRunFromServer() = false;
			else if (!wcscmp(m->Name()->str, L"camlerp")
				&& m->AllowRunFromServer())
				m->AllowRunFromServer() = false;
		}
	}
	__except (1) { resetcondig = true;
		printf(_("failed to hook console commands\n"));
	}
}

const class BaseMelee {
public:
	FIELD(O::BaseMelee::maxDistance, maxDistance, float);
	char* get_classname() {
		__try {
			if (!ValidPtr(this)) return nullptr;
			auto bp = *reinterpret_cast<uintptr_t*>((uintptr_t)this);
			if (!ValidPtr((uintptr_t*)bp)) return nullptr;
			return (char*)*reinterpret_cast<uintptr_t*>(bp + 0x10);
		}
		__except (1) { resetcondig = true;
			printf(_("[matrix]: Exception occurred inside " __FUNCTION__ "\n"));
			return nullptr;
		}
	}
	void DoAttack() {
		__try {
			//static auto bmdoattack = reinterpret_cast<void(*)(BaseMelee*)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseMelee"), _("DoAttack"), 0)));

			if (!ValidPtr(this))
				return;

			SAPPHIRE_METHOD(set_color_fn, "BaseMelee.DoAttack", 1, "", 1, void(*)(BaseMelee*));
			if (!set_color_fn)
				return;
			set_color_fn(this);

			//il2::bmdoattack(this);
		}
		__except (1) { resetcondig = true;
			printf(_("[matrix]: Exception occurred in " __FUNCTION__ "!\n"));
			return;
		}
	}

};
class HitTest2 {
public:
	uintptr_t game_object() {

		return *reinterpret_cast<uintptr_t*>((uintptr_t)this + 0x70);
	}

	GameObject* get_gameobject()
	{
		auto gameObject = game_object();
		if (!gameObject)
			return nullptr;

		return *reinterpret_cast<GameObject**>(gameObject + 0x10);
	}

	void set_hit_transform(uintptr_t* hit_transform) {

		*reinterpret_cast<uintptr_t**>((uintptr_t)this + 0xB0) = hit_transform;
	}

	void set_hit_material(System::string material) {

		*reinterpret_cast<System::string*>((uintptr_t)this + 0xC0) = material;
	}

	void set_hit_type(HitTestType hit_type) {

		*reinterpret_cast<int*>((uintptr_t)this + 0x10) = (int)hit_type;
	}

	void set_ignore_entity(BasePlayer* entity_to_ignore) {

		*reinterpret_cast<BasePlayer**>((uintptr_t)this + 0x80) = entity_to_ignore;
	}

	void set_radius(float radius) {

		*reinterpret_cast<float*>((uintptr_t)this + 0x2C) = radius;
	}

	void set_did_hit(bool did_hit) {

		*reinterpret_cast<bool*>((uintptr_t)this + 0x66) = did_hit;
	}

	void set_attack_ray(Ray ray) {

		*reinterpret_cast<Ray*>((uintptr_t)this + 0x14) = ray;
	}

	void set_best_hit(bool best_hit) {

		*reinterpret_cast<bool*>((uintptr_t)this + 0x65) = best_hit;
	}

	void set_max_distance(float max_dist) {

		*reinterpret_cast<float*>((uintptr_t)this + 0x34) = max_dist; 
	}
	void set_hit_distance(float max_dist) {

		*reinterpret_cast<float*>((uintptr_t)this + 0xA8) = max_dist;//	public float HitDistance; // 0xA8

	}
	void set_hit_hitpoint(utils::maths::vec3_t new_hitpoint)
	{
		uintptr_t entity = reinterpret_cast<uintptr_t>(this);

		if (!(entity))
			return;

		memory::write<utils::maths::vec3_t>(entity + 0x90, new_hitpoint);
	}
	
	void set_hit_direction(utils::maths::vec3_t  max_dist) {

		*reinterpret_cast<utils::maths::vec3_t*>((uintptr_t)this + 0x1F8) = max_dist;
	}

	void set_hit_entity(BasePlayer* entity) {

		*reinterpret_cast<BasePlayer**>((uintptr_t)this + 0x88) = entity;
	}

	BasePlayer* get_hit_entity() {

		return *reinterpret_cast<BasePlayer**>((uintptr_t)this + 0x88);
	}

	void set_hit_point(utils::maths::vec3_t hit_point) {

		*reinterpret_cast<utils::maths::vec3_t*>((uintptr_t)this + 0x90) = hit_point;
	}

	void set_hit_normal(utils::maths::vec3_t hit_nromal) {

		*reinterpret_cast<utils::maths::vec3_t*>((uintptr_t)this + 0x9C) = hit_nromal;
	}
	void set_damage_properties(uintptr_t damage_properties) {

		*reinterpret_cast<uintptr_t*>((uintptr_t)this + 0x68) = damage_properties;
	}
};
void StartAttackCooldown(uintptr_t* f11, float func) {
	//	static auto StartAttackCooldown = reinterpret_cast<void(*)(AttackEntity*, float)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("AttackEntity"), _("StartAttackCooldown"), 1)));

	__try {
		pent

			SAPPHIRE_METHOD(set_color_fn, "AttackEntity.StartAttackCooldown()", 1, "cooldown", 1, void(*)(uintptr_t*, float));
		if (!set_color_fn)
			return;

		return set_color_fn(f11, func);
	}
	__except (1) { resetcondig = true;
		printf(_("[StartAttackCooldown]: \n " __FUNCTION__ "! \n"));

		return;
	}


}
void ProcessAttack(uintptr_t* f11, uintptr_t func) {
	//	static auto ProcessAttack = reinterpret_cast<void(*)(BaseMelee*, uintptr_t)>(*reinterpret_cast<uintptr_t*>(il2cpp::method(_("BaseMelee"), _("ProcessAttack"), 1)));

	__try {
		pent

			SAPPHIRE_METHOD(set_color_fn, "BaseMelee.ProcessAttack()", 1, "hit", 1, void(*)(uintptr_t*, uintptr_t));
		if (!set_color_fn)
			return;

		return set_color_fn(f11, func);
	}
	__except (1) { resetcondig = true;
		printf(_("[ProcessAttack]: \n " __FUNCTION__ "! \n"));

		return;
	}


}




void attack_melee( aim_target1 target, aim_targetFarm FARM, BaseProjectile* melee, BasePlayer* lp, bool is_player = false) {
	pent
		if (!melee)
			return;
		if (!lp)
			return;

		if (melee->nextAttackTime() >= Time::time())
			return;
		auto hit_test_class = il2cpp_lib::find_class(_("HitTest"));
		if (!hit_test_class)
			return;
	if (melee->timeSinceDeploy() < melee->deployDelay())
		return;

	if (!is_player) {
		pent
			HitTest2* hit_test = (HitTest2*)il2cpp_lib::object_new(hit_test_class);

		auto Ent = target.ent;
		if (!Ent)
			return;

		auto GetT = target.ent->model();
		if (!GetT)
			return;

		auto GetT2 = GetT->boneTransforms();
		if (!GetT2)
			return;

		auto trans = GetT2->get(48);
 
		if (!trans)
			return;

		Ray ray = Ray(lp->eyes()->position(), (target.pos - lp->eyes()->position()).Normalized11());

		hit_test->set_max_distance(1000);
		hit_test->set_hit_transform((uintptr_t*)trans);
		hit_test->set_attack_ray(ray);
		hit_test->set_did_hit(true);
		hit_test->set_hit_entity((BasePlayer*)target.ent);
		hit_test->set_hit_point(trans->InverseTransformPoint(target.pos));
		hit_test->set_hit_normal(utils::maths::vec3_t(0, 0, 0));
		hit_test->set_damage_properties(melee->get_damage_properties());

		 StartAttackCooldown((uintptr_t*)melee, melee->repeatDelay());

		 ProcessAttack((uintptr_t*)melee, (uintptr_t)hit_test);
	}
	else {
		if (!FARM.entFARM)
			return;

		HitTest2* hit_test = (HitTest2*)il2cpp_lib::object_new(hit_test_class);

	 


		auto trans = FARM.entFARM->transform();

		if (!trans)
			return;
		Ray ray = Ray(lp->eyes()->position(), (trans->position() - lp->eyes()->position()).Normalized11());

		auto v = trans->InverseTransformPoint(lp->ClosestPoint(trans->position()));//_InverseTransformPoint(trans, target.pos);
	//	auto v = trans->InverseTransformPoint(trans->position());//_InverseTransformPoint(trans, target.pos);

		hit_test->set_max_distance(1000);
		hit_test->set_hit_transform((uintptr_t*)trans);
		hit_test->set_attack_ray(ray);
		hit_test->set_did_hit(true);
		hit_test->set_hit_entity((BasePlayer*)FARM.entFARM);
		hit_test->set_hit_point(v);
		hit_test->set_hit_normal(trans->InverseTransformDirection(trans->position()));
		hit_test->set_damage_properties(melee->get_damage_properties());		 

		if (!strcmp(melee->get_classname(), _("Jackhammer"))) {
			StartAttackCooldown((uintptr_t*)melee, 0.05f);
		}
		else
			StartAttackCooldown((uintptr_t*)melee, melee->repeatDelay());

		ProcessAttack((uintptr_t*)melee, (uintptr_t)hit_test);
	/*	hit_test->set_max_distance(1000);
		hit_test->set_hit_transform((uintptr_t*)trans);
		hit_test->set_attack_ray(ray);
		hit_test->set_did_hit(true);
		hit_test->set_hit_entity((BasePlayer*)FARM.entFARM);
		hit_test->set_hit_point(trans->InverseTransformPoint(FARM.world_distanceFarm));
		hit_test->set_hit_normal(utils::maths::vec3_t(0, 0, 0));
		hit_test->set_damage_properties(melee->get_damage_properties());

		 StartAttackCooldown((uintptr_t*)melee, melee->repeatDelay());

		 ProcessAttack((uintptr_t*)melee, (uintptr_t)hit_test);*/
	}
	return;
}
#define powww(a)	(a) * (a)

float Calc3D_Dist(const utils::maths::vec3_t& Src, const utils::maths::vec3_t& Dst) {
	return sqrt(powww((Src.x - Dst.x)) + powww((Src.y - Dst.y)) + powww((Src.z - Dst.z)));
}

 

template <class t = uintptr_t>
inline t get_closest_object_of_class(std::string class_to_find, int max_dist)
{
	int best_distance = max_dist;
	uintptr_t best_object = NULL;
	auto c_ents = il2cpp_lib::field(xorstr_("BaseNetworkable"), xorstr_("clientEntities"), false);

	auto entity_realm = memory::read(c_ents + 0x10);
	if (!entity_realm)
	{
		return NULL;
	}

	auto buffer_list = memory::read(entity_realm + 0x28);
	if (!buffer_list)
	{
		return NULL;
	}

	uintptr_t object_list = memory::read(buffer_list + 0x18);
	if (!object_list)
	{
		return NULL;
	}

	auto object_list_size = *reinterpret_cast<std::uint32_t*>(buffer_list + 0x10);
	if (!object_list_size)
	{
		return NULL;
	}

	try
	{
		for (auto i = 0; i < object_list_size; i++)
		{
			////////std::cout << "current_object" << std::endl;
			auto current_object = *reinterpret_cast<BaseEntity**>(object_list + (0x20 + (i * 8)));

			if (!current_object)
			{
				continue;
			}

			std::string class_name = current_object->get_class_name(); //hook_get_class_name(current_object);

			if (class_name == class_to_find)
			{
				////////std::cout << "Found: " << class_name << std::endl;
				auto unk1 = memory::read((uintptr_t)current_object + 0x10);
				if (!unk1)
				{
					continue;
				}

				auto unk2 = memory::read(unk1 + 0x30);
				if (!unk2)
				{
					continue;
				}

				auto unk3 = memory::read(unk2 + 0x30);
				if (!unk3)
				{
					continue;
				}

				if (!current_object)
				{
					continue;
				}

				auto player_visual = memory::read(unk3 + 0x8);

				if (!player_visual)
				{
					continue;
				}

				auto visual_state = memory::read(player_visual + 0x38);

				if (!visual_state)
				{
					continue;
				}

				utils::maths::vec3_t position = *reinterpret_cast<utils::maths::vec3_t*>(visual_state + 0x90);

 				auto distance = get_position().distance(position);

				////////std::cout << "Distance: " << std::dec << (int)distance << std::endl;

				if ((int)distance < best_distance)
				{
					best_distance = distance;
					best_object = reinterpret_cast<uintptr_t>(current_object);

				}
			}
		}
	}

	catch (...)
	{
	}

	return reinterpret_cast<t>(best_object);
}


struct bone_t {
	SDK::utils::maths::vec3_t screen;
	int8_t     index;
	bool       on_screen;
	SDK::utils::maths::vec3_t world_position;
	bool visible;
};
struct bounds_t {
	float left, right, top, bottom, center;
	bool empty() {
		if (left == FLT_MAX
			|| right == FLT_MIN
			|| top == FLT_MAX
			|| bottom == FLT_MIN)
			return true;
		return false;
	}
};

const bool get_bounds(bounds_t& out, BasePlayer* ply, float expand = 0) {
	std::array<bone_t, 20> bones = {
		bone_t{ SDK::utils::maths::vec3_t{}, 2, false, SDK::utils::maths::vec3_t{}, false },  // l_hip
		bone_t{ SDK::utils::maths::vec3_t{}, 3, false, SDK::utils::maths::vec3_t{}, false },  // l_knee
		bone_t{ SDK::utils::maths::vec3_t{}, 6, false, SDK::utils::maths::vec3_t{}, false },  // l_ankle_scale
		bone_t{ SDK::utils::maths::vec3_t{}, 5, false, SDK::utils::maths::vec3_t{}, false },  // l_toe
		bone_t{ SDK::utils::maths::vec3_t{}, 24, false, SDK::utils::maths::vec3_t{}, false }, // l_upperarm
		bone_t{ SDK::utils::maths::vec3_t{}, 25, false, SDK::utils::maths::vec3_t{}, false }, // l_forearm
		bone_t{ SDK::utils::maths::vec3_t{}, 26, false, SDK::utils::maths::vec3_t{}, false }, // l_hand
		bone_t{ SDK::utils::maths::vec3_t{}, 27, false, SDK::utils::maths::vec3_t{}, false }, // l_index1

		bone_t{ SDK::utils::maths::vec3_t{}, 48, false, SDK::utils::maths::vec3_t{}, false }, // jaw
		bone_t{ SDK::utils::maths::vec3_t{}, 18, false, SDK::utils::maths::vec3_t{}, false }, // spine1
		bone_t{ SDK::utils::maths::vec3_t{}, 21, false, SDK::utils::maths::vec3_t{}, false }, // spine3
		bone_t{ SDK::utils::maths::vec3_t{}, 1, false, SDK::utils::maths::vec3_t{}, false },  // pelvis
		bone_t{ SDK::utils::maths::vec3_t{}, 23, false, SDK::utils::maths::vec3_t{}, false }, // l_clavicle

		bone_t{ SDK::utils::maths::vec3_t{}, 17, false, SDK::utils::maths::vec3_t{}, false }, // r_ankle_scale
		bone_t{ SDK::utils::maths::vec3_t{}, 15, false, SDK::utils::maths::vec3_t{}, false }, // r_foot
		bone_t{ SDK::utils::maths::vec3_t{}, 14, false, SDK::utils::maths::vec3_t{}, false }, // r_knee
		bone_t{ SDK::utils::maths::vec3_t{}, 55, false, SDK::utils::maths::vec3_t{}, false }, // r_upperarm
		bone_t{ SDK::utils::maths::vec3_t{}, 56, false, SDK::utils::maths::vec3_t{}, false }, // r_forearm
		bone_t{ SDK::utils::maths::vec3_t{}, 57, false, SDK::utils::maths::vec3_t{}, false }, // r_hand
		bone_t{ SDK::utils::maths::vec3_t{}, 76, false, SDK::utils::maths::vec3_t{}, false }  // r_ulna
	};

	bounds_t bounds;
	bounds = { FLT_MAX, FLT_MIN, FLT_MAX, FLT_MIN };

	for (auto& [bone_screen, bone_idx, on_screen, world_position, visible] : bones) {

		auto Transform = ply->model()->boneTransforms()->get(bone_idx);

		world_position = Transform->position();

		if (bone_idx == 48) // lol
			world_position.y += 0.2f;

		bone_screen = screen_transform(world_position);
		if (bone_screen.x < bounds.left)
			bounds.left = bone_screen.x;
		if (bone_screen.x > bounds.right)
			bounds.right = bone_screen.x;
		if (bone_screen.y < bounds.top)
			bounds.top = bone_screen.y;
		if (bone_screen.y > bounds.bottom)
			bounds.bottom = bone_screen.y;
		on_screen = true;
	}

	if (bounds.left == FLT_MAX)
		return false;
	if (bounds.right == FLT_MIN)
		return false;
	if (bounds.top == FLT_MAX)
		return false;
	if (bounds.bottom == FLT_MIN)
		return false;

	bounds.left -= expand;
	bounds.right += expand;
	bounds.top -= expand;
	bounds.bottom += expand;

	bounds.center = bounds.left + ((bounds.right - bounds.left) / 2);

	out = bounds;

	return true;
};
#define ABS(N) ((N<0)?(-N):(N))

bool GetKey1(int key) {
	return !(!GetAsyncKeyState(key));
}

unsigned short lfsr = 0xACE1u;
unsigned int bit = 0;
unsigned my_rand()
{
	if (!lfsr) {
		lfsr = 0xACE1u; bit = 0;
	}
	bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & 1;
	return lfsr = (lfsr >> 1) | (bit << 15);
}

float my_floor(float x)
{
	if (x == 0.0)
		return 0;

	union {
		float input;
		int   output;
	} data;

	data.input = x;

	int exp = data.output & (255 << 23);
	exp = exp >> 23;

	int man = data.output & ((1 << 23) - 1);

	int pow = exp - 127;
	int mulFactor = 1;

	int i = ABS(pow);
	while (i--)
		mulFactor *= 2;

	unsigned long long denominator = 1 << 23;
	unsigned long long numerator = man + denominator;

	bool negative = (data.output >> 31) != 0;

	if (pow < 0)
		denominator *= mulFactor;
	else
		numerator *= mulFactor;

	float res = 0.0;
	while (numerator >= denominator) {
		res++;
		numerator -= denominator;
	}

	if (negative) {
		res = -res;
		if (numerator != 0)
			res -= 1;
	}

	return res;
}

float my_fmod(float a, float b) { return (a - b * my_floor(a / b)); }



void ColorConvertHSVtoRGB2(float h, float s, float v, float& out_r, float& out_g, float& out_b)
{
	if (s == 0.0f)
	{
		// gray
		out_r = out_g = out_b = v;
		return;
	}

	h = my_fmod(h, 1.0f) / (60.0f / 360.0f);
	int   i = (int)h;
	float f = h - (float)i;
	float p = v * (1.0f - s);
	float q = v * (1.0f - s * f);
	float t = v * (1.0f - s * (1.0f - f));

	switch (i)
	{
	case 0: out_r = v; out_g = t; out_b = p; break;
	case 1: out_r = q; out_g = v; out_b = p; break;
	case 2: out_r = p; out_g = v; out_b = t; break;
	case 3: out_r = p; out_g = q; out_b = v; break;
	case 4: out_r = t; out_g = p; out_b = v; break;
	case 5: default: out_r = v; out_g = p; out_b = q; break;
	}
}

D3DCOLOR HSVD(float h, float s, float v, float a = 1.0f)
{
	float r, g, b;
	ColorConvertHSVtoRGB2(h, s, v, r, g, b);

	return D3DCOLOR_ARGB((int)r, (int)g, (int)b, (int)a);

}


inline float NormalizeAngle(float angle) {
	while (angle > 360.0f) {
		angle -= 360.0f;
	}
	while (angle < 0.0f) {
		angle += 360.0f;
	}
	return angle;
}

inline SDK::utils::maths::vec3_t NormalizeAngles(SDK::utils::maths::vec3_t angles) {
	angles.x = NormalizeAngle(angles.x);
	angles.y = NormalizeAngle(angles.y);
	angles.z = NormalizeAngle(angles.z);
	return angles;
}

inline SDK::utils::maths::vec3_t EulerAngles(utils::maths::vec4_t q1) {
	float num = q1.w * q1.w;
	float num2 = q1.x * q1.x;
	float num3 = q1.y * q1.y;
	float num4 = q1.z * q1.z;
	float num5 = num2 + num3 + num4 + num;
	float num6 = q1.x * q1.w - q1.y * q1.z;
	SDK::utils::maths::vec3_t vector;
	if (num6 > 0.4995f * num5) {
		vector.y = 2.0f * std::atan2f(q1.y, q1.x);
		vector.x = 1.57079637f;
		vector.z = 0.0f;
		return NormalizeAngles(vector * 57.2958f);
	}
	if (num6 < -0.4995f * num5) {
		vector.y = -2.0f * std::atan2f(q1.y, q1.x);
		vector.x = -1.57079637f;
		vector.z = 0.0f;
		return NormalizeAngles(vector * 57.2958f);
	}
	utils::maths::vec4_t quaternion = utils::maths::vec4_t(q1.w, q1.z, q1.x, q1.y);
	vector.y = std::atan2f(2.0f * quaternion.x * quaternion.w + 2.0f * quaternion.y * quaternion.z, 1.0f - 2.0f * (quaternion.z * quaternion.z + quaternion.w * quaternion.w));
	vector.x = std::asin(2.0f * (quaternion.x * quaternion.z - quaternion.w * quaternion.y));
	vector.z = std::atan2f(2.0f * quaternion.x * quaternion.y + 2.0f * quaternion.z * quaternion.w, 1.0f - 2.0f * (quaternion.y * quaternion.y + quaternion.z * quaternion.z));
	return NormalizeAngles(vector * 57.2958f);
}

__forceinline void FillRectangle(const utils::maths::vec2_t& Start, const utils::maths::vec2_t& Sz, ImU32 Clr) {
	__try {
		auto* window = ImGui::GetOverlayDrawList();

		window->AddRectFilled({ Start.x,Start.y }, { Sz.x,Sz.y }, Clr);
	}
	__except (true) { return; }
}
D3DCOLOR FLOAT4TOD3DCOLOR(float Col[])
{
	ImU32 col32_no_alpha = ImGui::ColorConvertFloat4ToU32(ImVec4(Col[0], Col[1], Col[2], Col[3]));
	float a = (col32_no_alpha >> 24) & 255;
	float r = (col32_no_alpha >> 16) & 255;
	float g = (col32_no_alpha >> 8) & 255;
	float b = col32_no_alpha & 255;
	return D3DCOLOR_ARGB((int)a, (int)b, (int)g, (int)r);
}

__forceinline void String(const utils::maths::vec2_t& Start, const std::wstring Str, ImU32 Clr, bool outline = true)
{
	__try {
		auto* window = ImGui::GetOverlayDrawList();
		//void ImDrawList::AddText(const ImVec2 & pos, ImU32 col, const char* text_begin, const char* text_end)
		auto s = std::string(Str.begin(), Str.end());

		window->AddText({ Start.x,Start.y }, Clr, s.c_str());

	}
	__except (true) { return; }
}

__forceinline void Line(const utils::maths::vec2_t& Start, const utils::maths::vec2_t& End, ImU32 Clr, float Thick = 1.5f, bool outline = false)
{

	__try {
		auto* window = ImGui::GetOverlayDrawList();

		window->AddLine({ Start.x,Start.y }, { End.x,End.y }, Clr, Thick);
	}
	__except (true) { return; }
}
__forceinline void Rectangle2(const utils::maths::vec2_t& Start, const utils::maths::vec2_t& Sz, ImU32 Clr, float Thick = 1.5f)
{
	__try {
		auto* window = ImGui::GetOverlayDrawList();

		window->AddRect({ Start.x,Start.y }, { Sz.x,Sz.y }, Clr, Thick);
	}
	__except (true) { return; }
}

 
const char* const BoxTyesStr[] = {
"None",
"Full",
"Corner",
"3DCube",
"3D Box"
};
const char* const HealthTyeStr[] = {
 "none",
" Side",
"Bottom",
"Fill box",
"Text"
};

void FilledRect(float x, float y, float w, float h, ImColor clr, float rounding, ImDrawCornerFlags flags) {
	auto* window = ImGui::GetOverlayDrawList();

	window->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), clr, rounding, flags);
}
 

void drawHealthbar(SDK::utils::maths::vec2_t ScreenPositionA, SDK::utils::maths::vec2_t ScreenPositionB, float Width, float Height, int health, int healthMax) {


	if (healthMax == 0)
		return;


	for (int i = 0; i < Height; i++) {
		Line({ ScreenPositionA.x - 1, ScreenPositionA.y + i }, { ScreenPositionA.x + Width + 1, ScreenPositionA.y + i }, 1, (0, 0, 0, 255), 1); // Draw background
		if (i > 0 && i < Height - 1) {
			Line({ ScreenPositionA.x, ScreenPositionA.y + i }, { ScreenPositionA.x + (Width * health / healthMax), ScreenPositionA.y + i, }, 1, (255, 0, 0, 255), 1); // Draw background

		}
	}
}
float gradient_1[] = { 255.f, 255.f, 255.f };
float gradient_2[] = { 255.f, 255.f, 255.f };
ImColor color_grad1 = ImColor( gradient_1[0],  gradient_1[1],  gradient_1[2]);
ImColor color_grad2 = ImColor( gradient_2[0],  gradient_2[1],  gradient_2[2]);

void DrawPlayer(BasePlayer* ply, bool npc) {
	if (!ValidPtr(ply))
		return;
	if (!ValidPtr(ply->model()))
		return;
	if (!ValidPtr(ply->model()->boneTransforms()))
		return;
	auto lp = local_player;
	if (!ValidPtr(lp))
		return;
	if (npc && !SDK::userinterface::settings::esp_bot)
		return;


	auto userid = ply->userid();
	bounds_t bounds;
	bool visible = false, is_teammate = false;

	if (get_bounds(bounds, ply, 4)) {
		visible = ply->is_visible();

		float box_width = bounds.right - bounds.left;
		float box_height = bounds.bottom - bounds.top;


		auto box_color2 = visible ?
			boxesvisible
			: boxesinvisible;
	 

	/*	if (healthbar) {
			ImColor color_grad1 = ImColor(gradient_1[0], gradient_1[1], gradient_1[2]);
			ImColor color_grad2 = ImColor(gradient_2[0], gradient_2[1], gradient_2[2]);

			DrawLineGradient(Entity_x + Entity_w - 8.f, Entity_y, 5, Entity_h * (ply_hp / CurOff), color_grad1, color_grad2, 1, true);
			Rect(Entity_x + Entity_w - 8.f, Entity_y, 5, Entity_h, ImColor(0, 0, 0), 0, 0);
			if ((int)unity_player->health() <= 99) {
				std::string string;
				char buf[256] = { 0 }; sprintf_s(buf, ("%d"), (int)unity_player->health());
				string += buf;
				DrawString(Entity_x + Entity_w - 6.f, Entity_y + (Entity_h * CurOff) - 4, ImColor({ Hemp[0]  ,Hemp[1] ,  Hemp[2] , 255.f }), render2::centered_x | render2::outline, fSmall, fotsize, string.c_str());
			}
		}
*/

		//top left
		Line({ bounds.left, bounds.top }, { bounds.left + (box_width / 4), bounds.top }, (0, 0, 0, 1), 4.f);
		Line({ bounds.left, bounds.top }, { bounds.left + (box_width / 4), bounds.top }, FLOAT4TOD3DCOLOR(box_color2), 2.f);
		Line({ bounds.left, bounds.top }, { bounds.left, bounds.top + (box_height / 4) }, (0, 0, 0, 1), 4.f);
		Line({ bounds.left, bounds.top }, { bounds.left, bounds.top + (box_height / 4) }, FLOAT4TOD3DCOLOR(box_color2), 2.f);
		////top right
		Line({ bounds.right, bounds.top }, { bounds.right - (box_width / 4), bounds.top }, (0, 0, 0, 1), 4.f);
		Line({ bounds.right, bounds.top }, { bounds.right - (box_width / 4), bounds.top }, FLOAT4TOD3DCOLOR(box_color2), 2.f);
		Line({ bounds.right, bounds.top }, { bounds.right, bounds.top + (box_height / 4) }, (0, 0, 0, 1), 4.f);
		Line({ bounds.right, bounds.top }, { bounds.right, bounds.top + (box_height / 4) }, FLOAT4TOD3DCOLOR(box_color2), 2.f);
		////bottom left
		Line({ bounds.left, bounds.bottom }, { bounds.left + (box_width / 4), bounds.bottom }, (0, 0, 0, 1), 4.f);
		Line({ bounds.left, bounds.bottom }, { bounds.left + (box_width / 4), bounds.bottom }, FLOAT4TOD3DCOLOR(box_color2), 2.f);
		Line({ bounds.left, bounds.bottom }, { bounds.left, bounds.bottom - (box_height / 4) }, (0, 0, 0, 1), 4.f);
		Line({ bounds.left, bounds.bottom }, { bounds.left, bounds.bottom - (box_height / 4) }, FLOAT4TOD3DCOLOR(box_color2), 2.f);
		////bottom right
		Line({ bounds.right, bounds.bottom }, { bounds.right - (box_width / 4), bounds.bottom }, (0, 0, 0, 1), 4.f);
		Line({ bounds.right, bounds.bottom }, { bounds.right - (box_width / 4), bounds.bottom }, FLOAT4TOD3DCOLOR(box_color2), 2.f);
		Line({ bounds.right, bounds.bottom }, { bounds.right, bounds.bottom - (box_height / 4) }, (0, 0, 0, 1), 4.f);
		Line({ bounds.right, bounds.bottom }, { bounds.right, bounds.bottom - (box_height / 4) }, FLOAT4TOD3DCOLOR(box_color2), 2.f);


	}
}