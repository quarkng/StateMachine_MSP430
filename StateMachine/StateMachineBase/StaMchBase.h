/*
 * StaMchBase.h
 *
 *  Created on: Dec 21, 2014
 *      Author: Quark
 */

#ifndef STAMCHBASE_H_
#define STAMCHBASE_H_

#include <stdbool.h>

#include "StaMchSignal.h"
#include "StaMchState.h"

typedef struct
{
	int16_t currentState;
	int16_t previousState;
	int16_t previousSignal;
	int16_t nextState;

	uint8_t stateCount;
	uint8_t sigCount;
	const StaMchState_t *states;
	const StaMchSignal_t *signals;

	uint32_t runIteration;
}
StaMchBase_t;



void StaMchBase_Init( StaMchBase_t *context,
					  uint8_t stateCount, uint8_t sigCount,
					  const StaMchState_t *states, const StaMchSignal_t *signals);

// Checks if the tables have reasonable values.  Return number of errors found.
uint16_t StaMchBase_CheckTables( const StaMchBase_t *context );

void StaMchBase_SetInitialState( StaMchBase_t *context, uint8_t initialStateEnumVal);


void StaMchBase_RunStateFunc( StaMchBase_t *context );
bool StaMchBase_SignalTransition( StaMchBase_t *context, uint8_t signalEnumVal );


// This is used for checking transition tables and state tables
void StaMchBase_PrintCsvTable( const StaMchBase_t *context );

#endif /* STAMCHBASE_H_ */
