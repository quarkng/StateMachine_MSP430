/*
 * StateMachineExample.c
 *
 *  Created on: Dec 21, 2014
 *      Author: Quark
 */


#include "StateMachineExample.h"
#include "StateMachineExample_Tables.h"
#include "StateMachineExample_StateAndSig.h"

#include "StateMachineBase/StaMchBase.h"

//****************************************************************************************

void StateMachineExample(void)
{
	static StaMchBase_t stateMachine;

	StaMchBase_Init( &stateMachine,
			ExSta_Count, ExSig_Count,
			stateTbl, signalTbl);
}
