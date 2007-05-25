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
#include "../../include/obj/NiBlendPoint3Interpolator.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBlendPoint3Interpolator::TYPE("NiBlendPoint3Interpolator", &NiBlendInterpolator::TYPE );

NiBlendPoint3Interpolator::NiBlendPoint3Interpolator() {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiBlendPoint3Interpolator::~NiBlendPoint3Interpolator() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiBlendPoint3Interpolator::GetType() const {
	return TYPE;
}

//A static bool to force the initialization to happen pre-main
bool NiBlendPoint3Interpolator::obj_initialized = NiBlendPoint3Interpolator::Register();

bool NiBlendPoint3Interpolator::Register() {
	//Register this object type with Niflib
	ObjectRegistry::RegisterObject( "NiBlendPoint3Interpolator", NiBlendPoint3Interpolator::Create );

	//Do this stuff just to make sure the compiler doesn't optimize this function and the static bool away.
	obj_initialized = true;
	return obj_initialized;
}

NiObject * NiBlendPoint3Interpolator::Create() {
	return new NiBlendPoint3Interpolator;
}

void NiBlendPoint3Interpolator::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiBlendInterpolator::Read( in, link_stack, info );
	NifStream( pointValue, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiBlendPoint3Interpolator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiBlendInterpolator::Write( out, link_map, info );
	NifStream( pointValue, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiBlendPoint3Interpolator::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiBlendInterpolator::asString();
	out << "  Point Value:  " << pointValue << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiBlendPoint3Interpolator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiBlendInterpolator::FixLinks( objects, link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiBlendPoint3Interpolator::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiBlendInterpolator::GetRefs();
	return refs;
}

//--BEGIN MISC CUSTOM CODE--//

Vector3 NiBlendPoint3Interpolator::GetPointValue() const {
	return pointValue;
}

void NiBlendPoint3Interpolator::SetPointValue( Vector3 value ) {
	pointValue = value;
}

//--END CUSTOM CODE--//
