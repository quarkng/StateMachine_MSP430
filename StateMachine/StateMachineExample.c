/*
 * StateMachineExample.c
 *
 *  Created on: Dec 21, 2014
 *      Author: Quark
 */


#include "StateMachineExample.h"
#include "StateMachineExample_Tables.h"
#include "StateMachineExample_StateAndSig.h"
#include "StateMachineExample_Functions.h"

#include "StateMachineBase/StaMchBase.h"


 static StaMchBase_t stateMachine;

//****************************************************************************************

void StateMachineExample(void)
{

	StaMchBase_Init( &stateMachine,	ExSta_Count, ExSig_Count, stateTbl, signalTbl);

	if( StaMchBase_CheckTables(&stateMachine) != 0 )
	{
		for(;;) {} // Trap on severe error
	}

	StaMchBase_PrintCsvTable( &stateMachine );


	StaMchBase_SetInitialState( &stateMachine, ExStaAAA );

	while( ! exitExample )
	{
		StaMchBase_RunStateFunc( & stateMachine );
	}
}

//****************************************************************************************
bool StateMachineExample_Signal(uint8_t signalEnumVal)
{
	return StaMchBase_SignalTransition( &stateMachine, signalEnumVal );
}
