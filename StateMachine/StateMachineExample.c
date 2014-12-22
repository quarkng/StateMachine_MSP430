/*
 * StateMachineExample.c
 *
 *  Created on: Dec 21, 2014
 *      Author: Quark
 */


#include "StateMachineExample.h"

#include "StateMachineBase/StaMchBase.h"

//****************************************************************************************

typedef enum
{
	ExStaAAA,
	ExStaBBB,
	ExStaCCC,
	ExStaDDD,
	ExStaEEE,
	ExStaFFF,
	//...................
	ExSta_Count
} ExampleState_t;

typedef enum
{
	ExSigW,
	ExSigX,
	ExSigY,
	ExSigZ,
	//...................
	ExSig_Count
} ExampleSignal_t;


static void StateAEntry( int16_t otherStateEnumVal, int16_t signalEnumval );
static void StateARun( uint32_t iteration );
static void StateAExit( int16_t otherStateEnumVal, int16_t signalEnumval );


//****************************************************************************************
// --- STATE TRANSITION SIGNALS TABLES ---
StaMchSignal_t signals[ExSig_Count] = {
	// enumVal ,name
	{ ExSigW, "Signal W" },
	{ ExSigX, "Signal X" },
	{ ExSigY, "Signal Y" },
	{ ExSigZ, "Signal Z" }
};

//****************************************************************************************
// --- STATES TABLE ---

StaMchState_t states[ExSta_Count] = {
	// enumVal, name, ,entryFunc, runFunc, exitFunc
	{ ExStaAAA, "StateA", &StateAEntry, &StateARun, &StateAExit }
};



//****************************************************************************************
static void DoEntry(const char* prevStateName, const char* enteredStateName, const char* signalName)
{

}


//****************************************************************************************
static void StateAEntry( int16_t otherStateEnumVal, int16_t signalEnumval )
{
	DoEntry( states[otherStateEnumVal].name, states[ExStaAAA].name, signals[signalEnumval].name );
}
static void StateARun( uint32_t iteration )
{

}
static void StateAExit( int16_t otherStateEnumVal, int16_t signalEnumval )
{

}




