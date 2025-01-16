#pragma once

#include "Globals.h"
#include "Vector.hpp"
#include "Classes.hpp"
#include "RustStructs.h"
//#include <codecvt>
#include <string>
#include <iostream>
#include <vector>
#include "xor.h"
//std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
//
//#define UTF8_TO_UTF16(str) converter.from_bytes(str).c_str( )
//#define UTF16_TO_UTF8(str) converter.to_bytes(str).c_str( )

namespace SDK
{
	namespace utils
	{
		namespace mono
		{
			char* get_class_name(void* const networkable_class)
			{
				return *reinterpret_cast<char**>(*reinterpret_cast<std::intptr_t*>(networkable_class) + 0x10);
			}

			char* get_obj_name(void* const networkable_class)
			{
				return *reinterpret_cast<char**>(reinterpret_cast<std::intptr_t>(networkable_class) + 0x60);
			}

			uint32_t get_entity_type(void* const networkable_class)
			{
				const auto class_name = get_class_name(networkable_class);

			 


				if (utils::functions::stricmp(class_name, xorstr_("BaseNPC")) == NULL)
					return enums::BaseNPC;


			//	if (utils::functions::stricmp(class_name, xorstr_("TreeMarker")) == NULL)
			//		return enums::TreeMarker;

			//	if (utils::functions::stricmp(class_name, xorstr_("TreeEntity")) == NULL)
			//		return enums::TreeEntity;

				if (utils::functions::stricmp(class_name, xorstr_("TunnelDweller")) == NULL)
					return enums::TunnelDweller;

				if (utils::functions::stricmp(class_name, xorstr_("BasePlayer")) == NULL)
					return enums::BasePlayer;

				if (utils::functions::stricmp(class_name, xorstr_("ModularCar")) == NULL)
					return enums::ModularCar;
				
				if (utils::functions::stricmp(class_name, xorstr_("BasicCar")) == NULL)
					return enums::BasicCar;

				if (utils::functions::stricmp(class_name, xorstr_("BaseHelicopterVehicle")) == NULL)
					return enums::BaseHelicopterVehicle;

				if (utils::functions::stricmp(class_name, xorstr_("VehicleModuleSeating")) == NULL)
					return enums::VehicleModuleSeating;

				if (utils::functions::stricmp(class_name, xorstr_("TrainCar")) == NULL)
					return enums::TrainCar;

				if (utils::functions::stricmp(class_name, xorstr_("BaseVehicleSeat")) == NULL)
					return enums::BaseVehicleSeat;

					if (utils::functions::stricmp(class_name, xorstr_("BaseRidableAnimal")) == NULL)
					return enums::BaseRidableAnimal;

					if (utils::functions::stricmp(class_name, xorstr_("SubmarineDuo")) == NULL)
					return enums::SubmarineDuo;
						if (utils::functions::stricmp(class_name, xorstr_("ModularCarGarage")) == NULL)
					return enums::ModularCarGarage;


				if (utils::functions::stricmp(class_name, xorstr_("SAMSite")) == NULL)
					return enums::SAMSite;
			//	if (utils::functions::stricmp(class_name, xorstr_("BaseHelicopterVehicle")) == NULL)
			//		return enums::BaseHelicopterVehicle;

			//	if (utils::functions::stricmp(class_name, xorstr_("CollectableEasterEgg")) == NULL)
			//		return enums::CollectableEasterEgg;

				//if (utils::functions::stricmp(class_name, xorstr_("Helicopter")) == NULL)
				//	return enums::Helicopter;


				/*if (utils::functions::stricmp(class_name, xorstr_("CollectableEasterEgg")) == NULL)
					return enums::CollectableEasterEgg;

				if (utils::functions::stricmp(class_name, xorstr_("RustigeEgg")) == NULL)
					return enums::RustigeEgg;

				*/



				if (utils::functions::stricmp(class_name, xorstr_("StorageContainer")) == NULL)
					return enums::StorageContainer;

				//if (utils::functions::stricmp(class_name, xorstr_("SleepingBag")) == NULL)
				//	return enums::SleepingBag;
				
				//if (utils::functions::stricmp(class_name, xorstr_("DecayEntity")) == NULL)
				//	return enums::DecayEntity;

				if (utils::functions::stricmp(class_name, xorstr_("MiniCopter")) == NULL)
					return enums::MiniCopter;

				if (utils::functions::stricmp(class_name, xorstr_("RidableHorse")) == NULL)
					return enums::Horse;

					if (utils::functions::stricmp(class_name, xorstr_("Horse")) == NULL)
					return enums::Horse1;

				if (utils::functions::stricmp(class_name, xorstr_("BradleyAPC")) == NULL)
					return enums::BradleyAPC;

			//	if (utils::functions::stricmp(class_name, xorstr_("BasePortal")) == NULL)
			//		return enums::BasePortal;
			//	if (utils::functions::stricmp(class_name, xorstr_("VehicleModuleStorage")) == NULL)
			//		return enums::VehicleModuleStorage;

				//if (utils::functions::stricmp(class_name, xorstr_("BuildingPrivlidge")) == NULL)
				//	return enums::BuildingPrivlidge;

				if (utils::functions::stricmp(class_name, xorstr_("LootableCorpse")) == NULL)
					return enums::LootableCorpse;



				// 
				// 
				// 
				//if (utils::functions::stricmp(class_name, xorstr_("Boar")) == NULL)
				//	return enums::Boar;


				//if (utils::functions::stricmp(class_name, xorstr_("GrenadeWeapon")) == NULL)
				//	return enums::GrenadeWeapon;

				//if (utils::functions::stricmp(class_name, xorstr_("RidableHorse")) == NULL)
				//	return enums::Horse;


				if (utils::functions::stricmp(class_name, xorstr_("Bear")) == NULL)
					return enums::Bear;

				if (utils::functions::stricmp(class_name, xorstr_("Boar")) == NULL)
					return enums::Boar;


				//if (utils::functions::stricmp(class_name, xorstr_("BradleyAPC")) == NULL)
				//	return enums::BradleyAPC;



				//if (utils::functions::stricmp(class_name, xorstr_("BaseMelee")) == NULL)
				//	return enums::BaseMelee;

				//if (utils::functions::stricmp(class_name, xorstr_("BaseOven")) == NULL)
				//	return enums::BaseOven;

				if (utils::functions::stricmp(class_name, xorstr_("Scientist")) == NULL)
					return enums::Scientist;
				if (utils::functions::stricmp(class_name, xorstr_("SupplyDrop")) == NULL)
					return enums::SupplyDrop;

			//	if (utils::functions::stricmp(class_name, xorstr_("Recycler")) == NULL)
			//		return enums::Recycler;
				//if (utils::functions::stricmp(class_name, xorstr_("Scientist")) == NULL)
				//	return enums::Scientist;

				if (utils::functions::stricmp(class_name, xorstr_("CollectibleEntity")) == NULL)
					return enums::CollectibleEntity;
				if (utils::functions::stricmp(class_name, xorstr_("OreResourceEntity")) == NULL)
					return enums::OreResourceEntity;
				
			/*	if (utils::functions::stricmp(class_name, xorstr_("patrolhelicopter")) == NULL)
					return enums::patrolhelicopter;

					if (utils::functions::stricmp(class_name, xorstr_("Patrol")) == NULL)
					return enums::patrol;*/

				//if (utils::functions::stricmp(class_name, xorstr_("BaseProjectile")) == NULL)
				//	return enums::BaseProjectile;

			//	if (utils::functions::stricmp(class_name, xorstr_("patrol")) == NULL)
			//		return enums::patrol; 
				if (utils::functions::stricmp(class_name, xorstr_("LootContainer")) == NULL)
					return enums::LootContainer;
				if (utils::functions::stricmp(class_name, xorstr_("ScientistNPC")) == NULL)
					return enums::ScientistNPC;
				//if (utils::functions::stricmp(class_name, xorstr_("Stag")) == NULL)
				//	return enums::Deer;


				//

				if (utils::functions::stricmp(class_name, xorstr_("StashContainer")) == NULL)
					return enums::StashContainer;

				//if (utils::functions::stricmp(class_name, xorstr_("Chicken")) == NULL)
				//	return enums::Chicken;
				//
				if (utils::functions::stricmp(class_name, xorstr_("Wolf")) == NULL)
					return enums::Wolf;

				if (utils::functions::stricmp(class_name, xorstr_("HotSpot")) == NULL)
					return enums::HotSpot;
				if (utils::functions::stricmp(class_name, xorstr_("CodeLock")) == NULL)
					return enums::CodeLock;

				//if (utils::functions::stricmp(class_name, xorstr_("ResourceEntity")) == NULL)
				//	return enums::ResourceEntity;

				/*if (utils::functions::stricmp(class_name, xorstr_("StashContainer")) == NULL)
					return enums::StashContainer;

				if (utils::functions::stricmp(class_name, xorstr_("DroppedItem")) == NULL)
					return enums::DroppedItem;

				if (utils::functions::stricmp(class_name, xorstr_("TreeEntity")) == NULL)
					return enums::TreeEntity;

				if (utils::functions::stricmp(class_name, xorstr_("FreeableLootContainer")) == NULL)
					return enums::FreeableLootContainer;

				if (utils::functions::stricmp(class_name, xorstr_("Recycler")) == NULL)
					return enums::Recycler;

				if (utils::functions::stricmp(class_name, xorstr_("TorchWeapon")) == NULL)
					return enums::TorchWeapon;

				if (utils::functions::stricmp(class_name, xorstr_("ExcavatorArm")) == NULL)
					return enums::ExcavatorArm;

				if (utils::functions::stricmp(class_name, xorstr_("LightListener")) == NULL)
					return enums::LightListener;


				if (utils::functions::stricmp(class_name, xorstr_("JunkPileWater")) == NULL)
					return enums::JunkPileWater;

				if (utils::functions::stricmp(class_name, xorstr_("VendingMachineMapMarker")) == NULL)
					return enums::VendingMachineMapMarker;

				if (utils::functions::stricmp(class_name, xorstr_("ItemPickup")) == NULL)
					return enums::ItemPickup;

				if (utils::functions::stricmp(class_name, xorstr_("HackableLockedCrate")) == NULL)
					return enums::HackableLockedCrate;

				if (utils::functions::stricmp(class_name, xorstr_("Keycard")) == NULL)
					return enums::Keycard;

				if (utils::functions::stricmp(class_name, xorstr_("Planner")) == NULL)
					return enums::Planner;

				if (utils::functions::stricmp(class_name, xorstr_("HotSpot")) == NULL)
					return enums::HotSpot;



				if (utils::functions::stricmp(class_name, xorstr_("ProjectileWeaponMod")) == NULL)
					return enums::ProjectileWeaponMod;

				if (utils::functions::stricmp(class_name, xorstr_("BaseChair")) == NULL)
					return enums::BaseChair;

					if (utils::functions::stricmp(class_name, xorstr_("LightListener")) == NULL)
					return enums::LightListener;

				if (utils::functions::stricmp(class_name, xorstr_("MiniCopter")) == NULL)
					return enums::MiniCopter;

				if (utils::functions::stricmp(class_name, xorstr_("DroppedItemContainer")) == NULL)
					return enums::DroppedItemContainer;

				if (utils::functions::stricmp(class_name, xorstr_("Container")) == NULL)
					return enums::Container;



				if (utils::functions::stricmp(class_name, xorstr_("AutoTurret")) == NULL)
					return enums::AutoTurret;

				if (utils::functions::stricmp(class_name, xorstr_("GunTrap")) == NULL)
					return enums::GunTrap;

				if (utils::functions::stricmp(class_name, xorstr_("FlameTurret")) == NULL)
					return enums::FlameTurret;

				if (utils::functions::stricmp(class_name, xorstr_("Trap")) == NULL)
					return enums::Trap;

				if (utils::functions::stricmp(class_name, xorstr_("Landmine")) == NULL)
					return enums::Landmine;


				if (utils::functions::stricmp(class_name, xorstr_("CommunityEntity")) == NULL)
					return enums::CommunityEntity;*/

				//if (utils::functions::stricmp(class_name, xorstr_("Landmine")) == NULL)
				//	return enums::Landmine;
				if (utils::functions::stricmp(class_name, xorstr_("AutoTurret")) == NULL)
					return enums::AutoTurret;
				if (utils::functions::stricmp(class_name, xorstr_("ZiplineLaunchPoint")) == NULL)
					return enums::ZiplineLaunchPoint;

				return enums::Undefined;
			}
			uint32_t get_entity_type2(void* const networkable_class)
			{
				const auto class_name = get_class_name(networkable_class);

					std::printf("name %s  \n", class_name);

 
				return enums::Undefined;
			}


			maths::vec3_t get_object_pos(GameObject* game_object)
			{
				if (!game_object)
					return {};
				const auto object_transform =
					*reinterpret_cast<intptr_t*>(std::intptr_t(game_object) + 0x8);

				if (!object_transform)
					return {};

				const auto visual_state =
					*reinterpret_cast<intptr_t*>(object_transform + 0x38);

				if (!visual_state)
					return {};

				return *reinterpret_cast<utils::maths::vec3_t*>(visual_state + 0x90);
			}

			maths::vec3_t get_transform_pos(void* transform)
			{
				if (!transform)
					return {};

				maths::vec3_t position{};

				static const auto get_position_injected = reinterpret_cast<uint64_t(__fastcall*)(void*, maths::vec3_t&)>(variables::get_pos_injected_fn);
				get_position_injected(transform, position);

				return position;
			}

			struct Ray
			{
				maths::vec3_t start;
				maths::vec3_t direction;
			};

			bool is_visible(utils::maths::vec3_t origin, utils::maths::vec3_t destination, float max_distance = 500.f)
			{
				//std::uintptr_t physics_scene;
				//reinterpret_cast< void( __fastcall* )( std::uintptr_t& ) >( variables::physics_scene_fn )( physics_scene );

				//Ray ray_;
				//ray_.direction = ( destination - origin ).normalized( );
				//ray_.start = origin;

				std::uintptr_t RaycastHitinfo;
				return reinterpret_cast<bool(__fastcall*)
					(maths::vec3_t start, maths::vec3_t end, std::uintptr_t & hitInfo, int layerMask)>
					(variables::ray_cast_fn)(origin, destination, RaycastHitinfo, 525313);
			}


			void normalize_angle(float& Yaw, float& Pitch) {
				if (Pitch < -89)
					Pitch = -89;

				else if (Pitch > 89)
					Pitch = 89;

				if (Yaw < -360)
					Yaw += 360;

				else if (Yaw > 360)
					Yaw -= 360;
			}

			float get_bullet_velocity(const char* weapon_name)
			{
				if (utils::functions::stricmp(weapon_name, ("rifle.bolt")) == NULL)
					return 656.25f;

				if (utils::functions::stricmp(weapon_name, ("rifle.ak")) == NULL)
					return 575.f;

				if (utils::functions::stricmp(weapon_name, ("rifle.lr300")) == NULL)
					return 375.f;

				if (utils::functions::stricmp(weapon_name, ("rifle.semiauto")) == NULL)
					return 375.f;

				if (utils::functions::stricmp(weapon_name, ("smg.mp5")) == NULL)
					return 180.f;

				if (utils::functions::stricmp(weapon_name, ("smg.thompson")) == NULL)
					return 300.f;

				if (utils::functions::stricmp(weapon_name, ("smg.2")) == NULL)
					return 240.f;

				if (utils::functions::stricmp(weapon_name, ("pistol.m92")) == NULL)
					return 300.f;

				if (utils::functions::stricmp(weapon_name, ("pistol.semiauto")) == NULL)
					return 300.f;

				if (utils::functions::stricmp(weapon_name, ("pistol.python")) == NULL)
					return 300.f;

				if (utils::functions::stricmp(weapon_name, ("bow.hunting")) == NULL)
					return 50.f;

				if (utils::functions::stricmp(weapon_name, ("crossbow")) == NULL)
					return 75.f;

				return 250.f;
			}



			float bullet_drop(utils::maths::vec3_t origin, utils::maths::vec3_t destination, float projectile_speed)
			{
				float distance = origin.distance(destination);

				if (distance < 0.001)
					return 0;

				float m_gravity = 9.81f;
				float m_time = distance / projectile_speed;

				return (float)(0.5 * m_gravity * m_time * m_time);
			}

			//maths::vec3_t get_transform_position( void* transform )
			//{
			//    if ( !transform )
			//		return;

			//    maths::vec3_t position{};

			//	static const auto get_position_injected = reinterpret_cast< uint64_t( __fastcall* )( void*, maths::vec3_t& ) >( std::uintptr_t( variables::unity_player_base ) + 0x9276a0 );
			//	get_position_injected( transform, position );

			//	return position;
			//}
		}
	}
}