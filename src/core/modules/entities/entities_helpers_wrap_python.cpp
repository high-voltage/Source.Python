/**
* =============================================================================
* Source Python
* Copyright (C) 2012 Source Python Development Team.  All rights reserved.
* =============================================================================
*
* This program is free software; you can redistribute it and/or modify it under
* the terms of the GNU General Public License, version 3.0, as published by the
* Free Software Foundation.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
* FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
* details.
*
* You should have received a copy of the GNU General Public License along with
* this program.  If not, see <http://www.gnu.org/licenses/>.
*
* As a special exception, the Source Python Team gives you permission
* to link the code of this program (as well as its derivative works) to
* "Half-Life 2," the "Source Engine," and any Game MODs that run on software
* by the Valve Corporation.  You must obey the GNU General Public License in
* all respects for all other code used.  Additionally, the Source.Python
* Development Team grants this exception to all derivative works.
*/

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include "entities_helpers_wrap.h"
#include "export_main.h"
#include "utilities/conversions.h"
#include "utilities/wrap_macros.h"

#include ENGINE_INCLUDE_PATH(entities_helpers_wrap.h)


//-----------------------------------------------------------------------------
// Forward declarations.
//-----------------------------------------------------------------------------
void export_entity_helper_functions(scope);
void export_entity_conversion_functions(scope);


//-----------------------------------------------------------------------------
// Declare the _entities._helpers module.
//-----------------------------------------------------------------------------
DECLARE_SP_SUBMODULE(_entities, _helpers)
{
	export_entity_helper_functions(_helpers);
	export_entity_conversion_functions(_helpers);
}


//-----------------------------------------------------------------------------
// Exports helper functions.
//-----------------------------------------------------------------------------
void export_entity_helper_functions(scope _helpers)
{
	def("create_entity",
		&create_entity,
		"Creates an entity of the given name and returns its index.",
		args("class_name")
	);

	def("remove_entity",
		&remove_entity,
		"Removes the entity matching the given index.",
		args("entity_index")
	);

	def("spawn_entity",
		&spawn_entity,
		"Spawns the entity matching the given index.",
		args("entity_index")
	);
}


//-----------------------------------------------------------------------------
// Exports conversion functions.
//-----------------------------------------------------------------------------
void export_entity_conversion_functions(scope _helpers)
{
	// Invalid results...
	_helpers.attr("INVALID_ENTITY_INDEX") = INVALID_ENTITY_INDEX;
	_helpers.attr("INVALID_ENTITY_INTHANDLE") = INVALID_EHANDLE_INDEX;

	// To Index conversions...
	EXPORT_CONVERSION_FUNCTION(unsigned int, Index, edict_t *, Edict);
	EXPORT_CONVERSION_FUNCTION(unsigned int, Index, CBaseHandle, BaseHandle);
	EXPORT_CONVERSION_FUNCTION(unsigned int, Index, int, IntHandle);
	EXPORT_CONVERSION_FUNCTION(unsigned int, Index, CPointer *, Pointer);
	EXPORT_CONVERSION_FUNCTION(unsigned int, Index, CBaseEntity *, BaseEntity);

	// To Edict conversions...
	EXPORT_CONVERSION_FUNCTION(edict_t *, Edict, unsigned int, Index, reference_existing_object_policy());
	EXPORT_CONVERSION_FUNCTION(edict_t *, Edict, CBaseHandle, BaseHandle, reference_existing_object_policy());
	EXPORT_CONVERSION_FUNCTION(edict_t *, Edict, int, IntHandle, reference_existing_object_policy());
	EXPORT_CONVERSION_FUNCTION(edict_t *, Edict, CPointer *, Pointer, reference_existing_object_policy());
	EXPORT_CONVERSION_FUNCTION(edict_t *, Edict, CBaseEntity *, BaseEntity, reference_existing_object_policy());

	// To BaseHandle conversions...
	EXPORT_CONVERSION_FUNCTION(CBaseHandle, BaseHandle, unsigned int, Index);
	EXPORT_CONVERSION_FUNCTION(CBaseHandle, BaseHandle, edict_t *, Edict);
	EXPORT_CONVERSION_FUNCTION(CBaseHandle, BaseHandle, int, IntHandle);
	EXPORT_CONVERSION_FUNCTION(CBaseHandle, BaseHandle, CPointer *, Pointer);
	EXPORT_CONVERSION_FUNCTION(CBaseHandle, BaseHandle, CBaseEntity *, BaseEntity);

	// To IntHandle conversions...
	EXPORT_CONVERSION_FUNCTION(int, IntHandle, unsigned int, Index);
	EXPORT_CONVERSION_FUNCTION(int, IntHandle, edict_t *, Edict);
	EXPORT_CONVERSION_FUNCTION(int, IntHandle, CBaseHandle, BaseHandle);
	EXPORT_CONVERSION_FUNCTION(int, IntHandle, CPointer *, Pointer);
	EXPORT_CONVERSION_FUNCTION(int, IntHandle, CBaseEntity *, BaseEntity);

	// To Pointer conversions...
	EXPORT_CONVERSION_FUNCTION(CPointer *, Pointer, unsigned int, Index, manage_new_object_policy());
	EXPORT_CONVERSION_FUNCTION(CPointer *, Pointer, edict_t *, Edict, manage_new_object_policy());
	EXPORT_CONVERSION_FUNCTION(CPointer *, Pointer, CBaseHandle, BaseHandle, manage_new_object_policy());
	EXPORT_CONVERSION_FUNCTION(CPointer *, Pointer, int, IntHandle, manage_new_object_policy());
	EXPORT_CONVERSION_FUNCTION(CPointer *, Pointer, CBaseEntity *, BaseEntity, manage_new_object_policy());
}
