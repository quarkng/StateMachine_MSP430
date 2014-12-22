/*
 * StaMchBase.c
 *
 *  Created on: Dec 22, 2014
 *      Author: Quark
 */

#include "StaMchBase.h"

#include "HwAbUart.h"

//****************************************************************************************
void StaMchBase_Init( StaMchBase_t *context,
					  uint8_t stateCount, uint8_t sigCount,
					  const StaMchState_t *states, const StaMchSignal_t *signals)
{
	context->currentState =  -1;
	context->previousState = -1;
	context->previousSignal = -1;
	context->nextState = -9; // must be initialized differently than currentState

	context->stateCount = stateCount;
	context->sigCount = sigCount;
	context->states = states;
	context->signals = signals;
}

//****************************************************************************************
// Checks if the tables have reasonable values.  Return number of errors found.
uint16_t StaMchBase_CheckTables( const StaMchBase_t *context )
{
	uint16_t errors = 0;
	int16_t  i;

	if( context->stateCount == 0 )
	{
		errors++;
	}
	if( context->sigCount == 0 )
	{
		errors++;
	}

	// Check the signals table
	for( i = 0; i < context->sigCount; i++ )
	{
		const StaMchSignal_t *s = &(context->signals[i]);

		if( s->enumVal != i )
		{
			errors++;
		}
	}

	// Check the states table
	for( i = 0; i < context->stateCount; i++ )
	{
		bool    breakProperly = false;
		int16_t k;
		const StaMchSignalTableEntry_t *tran;
		const StaMchState_t *s = &(context->states[i]);

		if( s->enumVal != i )
		{
			errors++;
		}

		// Check transition table
		for(k=0; k <= context->sigCount; k++ )
		{
			tran = &(s->transitions[k]);

			if( tran->signalEnumVal >= 0 )
			{
				if( tran->nextStateEnumVal < 0 || tran->nextStateEnumVal >= context->stateCount )
				{
					errors++;
				}
				if( tran->signalEnumVal < 0 || tran->signalEnumVal >= context->sigCount )
				{
					errors++;
				}
			}
			else
			{
				breakProperly = true;
				break;
			}
		}
		if( ! breakProperly )
		{
			errors++; // Transition tables should end with entry containing negative values
		}

	}

	return errors;
}

//****************************************************************************************
void StaMchBase_SetInitialState( StaMchBase_t *context, uint8_t initialStateEnumVal)
{
	if( initialStateEnumVal < context->stateCount)
	{
		context->nextState = initialStateEnumVal;
		context->currentState = -1;
		context->previousState = -1;
		context->previousSignal = -1;
	}
	else
	{	// Do error logging!!!
	}
}
//****************************************************************************************
void StaMchBase_RunStateFunc( StaMchBase_t *context )
{
	if( context->nextState != context->currentState )
	{	// Transition pending.  Run Exit and Entry functions
		if( (context->nextState < 0) || (context->nextState >= context->stateCount) )
		{	// Invalid next state.  Did you forget to call StaMchBase_SetInitialState?
			for(;;) {}
			// return;
		}

		// --- Run exit function of previous state ---
		if( (context->currentState >= 0) && (context->currentState < context->stateCount) )
		{
			(*context->states[ context->currentState ].exitFunc)( context->nextState, context->previousSignal );
		}

		// --- Update to new current state ---
		context->previousState  = context->currentState;
		context->currentState = context->nextState;

		// --- Run entry function of new current state ---
		(*context->states[ context->currentState ].entryFunc)( context->previousState, context->previousSignal );
		context->runIteration = 0;
	}

	(*context->states[ context->currentState ].runFunc)( context->runIteration++ );
}
//****************************************************************************************
bool StaMchBase_SignalTransition( StaMchBase_t *context, uint8_t signalEnumVal )
{
	bool signalHasEffect = false;
	int16_t i;
	const StaMchState_t *state = &(context->states[context->currentState]);

	if( (context->currentState < 0) || (context->currentState >= context->stateCount) )
	{	// Current state is invalid.  Do nothing.
		return signalHasEffect;
	}

	for( i=0; i < context->sigCount; i++ )
	{
		if( (state->transitions[i].signalEnumVal == signalEnumVal)  )
		{	// Found matching signal in transtion table of current state.
			context->nextState = state->transitions[i].nextStateEnumVal;
			context->previousSignal = signalEnumVal;
			signalHasEffect = true;
			break;
		}
		else if ( state->transitions[i].signalEnumVal < 0 )
		{	// Reached end of transitions table.  Do nothing.
			break;
		}
	}

	return signalHasEffect;
}

//****************************************************************************************
void StaMchBase_PrintCsvTable( const StaMchBase_t *context )
{
	int16_t fromStaNum;
	int16_t toStaNum;

	while( ! HwAbUart_IsDoneTransmitting() ) {} // BUSY WAIT
	HwAbUart_SendString("\r\nFrom \\ To");

	// Header row.  List all the destination states.
	for( toStaNum=0; toStaNum < context->stateCount; toStaNum++ )
	{
		while( ! HwAbUart_IsDoneTransmitting() ) {} // BUSY WAIT
		HwAbUart_SendString(",");
		HwAbUart_SendString(context->states[toStaNum].name);
	}
	HwAbUart_SendString("\r\n");

	// Each state's transition list is represented by a row in the CSV output
	for( fromStaNum = 0; fromStaNum < context->stateCount; fromStaNum++ )
	{
		const StaMchState_t *fromState = &(context->states[fromStaNum]);
		HwAbUart_SendString(fromState->name);
		for( toStaNum = 0; toStaNum < context->stateCount; toStaNum++ )
		{
			int16_t transNum;
			bool printOrSymbol = false;

			HwAbUart_SendString(",");

			for( transNum=0; transNum < context->sigCount; transNum++ )
			{	// Find the matching signal in the transition table
				if( fromState->transitions[transNum].nextStateEnumVal == toStaNum )
				{
					int16_t sigNum = fromState->transitions[transNum].signalEnumVal;

					if( printOrSymbol )
					{
						HwAbUart_SendString(" | ");
					}
					HwAbUart_SendString( context->signals[sigNum].name );
					printOrSymbol = true;
				}
				else if( fromState->transitions[transNum].signalEnumVal < 0)
				{
					break; // end of transitions list
				}
			}
		}

		HwAbUart_SendString("\r\n");
	}
}
