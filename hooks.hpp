#pragma once
#include "sapphire_hook.hpp"
#include "include.hpp"
#include "globals.hpp"

#define SAPPHIRE_HOOK( type, name, args ) inline impl::virt_hook_c name; type hk_##name args;
#define SAPPHIRE_SWAP( type, name, args ) inline impl::swap_ptr_c name; type hk_##name args;
#define HOOK_CUSTOM( addr, orig, repl ) orig = *addr; *addr = reinterpret_cast< std::uintptr_t >( repl ); 

namespace impl
{
	namespace hooks
	{
		SAPPHIRE_HOOK(void, bp_client_input, (BaseEntity* melee, HitTest* hittest))
	 SAPPHIRE_HOOK(void, bp_dofixedupdate, (c_walk_movement* base_player, c_model_state* input_state))

	}
}