/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

//--BEGIN FILE HEAD CUSTOM CODE--//
//--END CUSTOM CODE--//

#include "../../include/FixLink.h"
#include "../../include/ObjectRegistry.h"
#include "../../include/NIF_IO.h"
#include "../../include/obj/NiShadeProperty.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiShadeProperty::TYPE("NiShadeProperty", &NiProperty::TYPE );

NiShadeProperty::NiShadeProperty() : flags((unsigned short)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiShadeProperty::~NiShadeProperty() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiShadeProperty::GetType() const {
	return TYPE;
}

//A static bool to force the initialization to happen pre-main
bool NiShadeProperty::obj_initialized = NiShadeProperty::Register();

bool NiShadeProperty::Register() {
	//Register this object type with Niflib
	ObjectRegistry::RegisterObject( "NiShadeProperty", NiShadeProperty::Create );

	//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
	obj_initialized = true;
	return obj_initialized;
}

NiObject * NiShadeProperty::Create() {
	return new NiShadeProperty;
}

void NiShadeProperty::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiProperty::Read( in, link_stack, info );
	NifStream( flags, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiShadeProperty::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiProperty::Write( out, link_map, info );
	NifStream( flags, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiShadeProperty::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiProperty::asString();
	out << "  Flags:  " << flags << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiShadeProperty::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiProperty::FixLinks( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiShadeProperty::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiProperty::GetRefs();
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//

unsigned short NiShadeProperty::GetFlags() const {
   return flags;
}

void NiShadeProperty::SetFlags( unsigned short n ) {
   flags = n;
}

//--END CUSTOM CODE--//
