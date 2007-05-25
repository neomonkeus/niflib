/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

#include "../include/ObjectRegistry.h"

namespace Niflib {

map<string, obj_factory_func> * ObjectRegistry::object_map = NULL;

void ObjectRegistry::RegisterObject( const string & type_name, obj_factory_func create_func ) {
	if (object_map == NULL) {
		cout << "Initializing object map" << endl;
		object_map = new map<string, obj_factory_func>;
	}

	(*object_map)[type_name] = create_func;
}

NiObject * ObjectRegistry::CreateObject( const string & type_name ) {
	if (object_map == NULL) {
		throw runtime_error("Object Map was never initialized");
		//object_map = new map<string, obj_factory_func>;
	}
	
	NiObject * object = NULL;

	map<string, obj_factory_func>::iterator it;
	it = (*object_map).find(type_name);

	if ( it != (*object_map).end() ) {
		//Requested type has been registered
		return it->second();
	} else {
		//An unknown type has been encountered
		return NULL; //Return null
	}
}

} //End namespace Niflib