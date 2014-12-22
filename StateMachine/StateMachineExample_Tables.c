/*
 * StateMachineExample_Tables.c
 *
 *  Created on: Dec 21, 2014
 *      Author: Quark
 */

#include "StateMachineExample_Tables.h"
#include "StateMachineExample_StateAndSig.h"
#include "StateMachineExample_Functions.h"

//****************************************************************************************
// --- STATE TRANSITION SIGNALS TABLES ---
const StaMchSignal_t signalTbl[ExSig_Count] = {
	// enumVal ,name
	{ ExSigW, "Signal W" },
	{ ExSigX, "Signal X" },
	{ ExSigY, "Signal Y" },
	{ ExSigZ, "Signal Z" }
};

static const StaMchSignalTableEntry_t SignalsStateA[] = {	// Signals expected in State A
	// signalEnumVal, nextStateEnumVal
	{ ExSigW,	ExStaBBB },
	{ ExSigX,	ExStaFFF },
	{ -1, -1 } // Always end with negative values.  Indicates end-of-list.
};

static const StaMchSignalTableEntry_t SignalsStateB[] = {	// Signals expected in State B
	// signalEnumVal, nextStateEnumVal
	{ ExSigW,	ExStaCCC },
	{ -1, -1 } // Always end with negative values.  Indicates end-of-list.
};

//****************************************************************************************
// --- STATES TABLE ---

const StaMchState_t stateTbl[ExSta_Count] = {
	// enumVal, name, ,entryFunc, runFunc, exitFunc
	{ ExStaAAA, "StateA", &StateAEntry, &StateARun, &StateAExit, SignalsStateA },
	{ ExStaBBB, "StateB", &StateBEntry, &StateBRun, &StateBExit, SignalsStateB }
};








