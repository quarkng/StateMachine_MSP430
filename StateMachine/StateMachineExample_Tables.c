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

static const StaMchSignalTableEntry_t SignalsStateC[] = {
	{ ExSigW,	ExStaDDD },
	{ -1, -1 }
};

static const StaMchSignalTableEntry_t SignalsStateD[] = {
	{ ExSigW,	ExStaEEE },
	{ ExSigY,	ExStaAAA },
	{ -1, -1 }
};

static const StaMchSignalTableEntry_t SignalsStateE[] = {
	{ ExSigW,	ExStaFFF },
	{ ExSigZ,	ExSta_EXIT },
	{ -1, -1 }
};

static const StaMchSignalTableEntry_t SignalsStateF[] = {
	{ ExSigZ,	ExStaEEE },
	{ -1, -1 }
};

static const StaMchSignalTableEntry_t SignalsStateExit[] = {
	{ -1, -1 }
};

//****************************************************************************************
// --- STATES TABLE ---

const StaMchState_t stateTbl[ExSta_Count] = {
	// enumVal,   name,        entryFunc,       runFunc,       exitFunc,       transitions
	{ ExStaAAA,   "StateA",    &StateAEntry,    &StateARun,    &StateAExit,    SignalsStateA },
	{ ExStaBBB,   "StateB",    &StateBEntry,    &StateBRun,    &StateBExit,    SignalsStateB },
	{ ExStaCCC,   "StateC",    &StateCEntry,    &StateCRun,    &StateCExit,    SignalsStateC },
	{ ExStaDDD,   "StateD",    &StateDEntry,    &StateDRun,    &StateDExit,    SignalsStateD },
	{ ExStaEEE,   "StateE",    &StateEEntry,    &StateERun,    &StateEExit,    SignalsStateE },
	{ ExStaFFF,   "StateF",    &StateFEntry,    &StateFRun,    &StateFExit,    SignalsStateF },
	{ ExSta_EXIT, "StateExit", &StateExitEntry, &StateExitRun, &StateExitExit, SignalsStateExit },
};

