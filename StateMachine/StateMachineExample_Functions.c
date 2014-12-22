/*
 * StateMachineExample.c
 *
 *  Created on: Dec 21, 2014
 *      Author: Quark
 */

#include "intrinsics.h"

#include "StateMachineExample.h"
#include "StateMachineExample_StateAndSig.h"
#include "StateMachineExample_Tables.h"

#include "HwAbUart.h"
#include "BytesToHexString.h"

//****************************************************************************************
static void DoEntry(int16_t enteredState, int16_t prevState, int16_t signal )
{
	const char* enteredStateName = stateTbl[enteredState].name;
	const char* prevStateName = (prevState < 0) ? "N/A" : stateTbl[prevState].name;
	const char* signalName = (signal < 0) ? "N/A" : signalTbl[signal].name;

	while( HwAbUart_IsDoneTransmitting() ) {} // BUSY WAIT

	HwAbUart_SendString("Entered [");
	HwAbUart_SendString(enteredStateName);
	HwAbUart_SendString("] from [");
	HwAbUart_SendString(prevStateName);
	HwAbUart_SendString("] on signal [");
	HwAbUart_SendString(signalName);
	HwAbUart_SendString("]\r\n");
}

static void DoRun( int16_t currentState, uint32_t iteration )
{
	const char* currentStateName = stateTbl[currentState].name;

	while( HwAbUart_IsDoneTransmitting() ) {} // BUSY WAIT
	if( iteration < 16 )
	{
		char hexStr[16];

		HwAbUart_SendString("Run [");
		HwAbUart_SendString(currentStateName);
		HwAbUart_SendString("] iteration [0x");
		BytesToHexString( hexStr, sizeof(hexStr)/sizeof(hexStr[0]), &iteration, sizeof(iteration) );
		HwAbUart_SendString(hexStr);
		HwAbUart_SendString("]\r\n");
	}

	__delay_cycles(1000000);
}

static void DoExit(int16_t exitingState, int16_t nextState, int16_t signal )
{
	const char* exitingStateName = stateTbl[exitingState].name;
	const char* nextStateName = stateTbl[nextState].name;
	const char* signalName = signalTbl[signal].name;

	while( HwAbUart_IsDoneTransmitting() ) {} // BUSY WAIT

	HwAbUart_SendString("Exiting [");
	HwAbUart_SendString(exitingStateName);
	HwAbUart_SendString("] to [");
	HwAbUart_SendString(nextStateName);
	HwAbUart_SendString("] on signal [");
	HwAbUart_SendString(signalName);
	HwAbUart_SendString("]\r\n");
}

//****************************************************************************************
void StateAEntry( int16_t otherStateEnumVal, int16_t signalEnumval )
{
	DoEntry(ExStaAAA, otherStateEnumVal, signalEnumval);

}void StateARun( uint32_t iteration )
{
	DoRun(ExStaAAA, iteration);
}
void StateAExit( int16_t otherStateEnumVal, int16_t signalEnumval )
{
	DoExit(ExStaAAA, otherStateEnumVal, signalEnumval);
}
//****************************************************************************************
void StateBEntry( int16_t otherStateEnumVal, int16_t signalEnumval )
{
	DoEntry(ExStaBBB, otherStateEnumVal, signalEnumval);

}void StateBRun( uint32_t iteration )
{
	DoRun(ExStaBBB, iteration);
}
void StateBExit( int16_t otherStateEnumVal, int16_t signalEnumval )
{
	DoExit(ExStaBBB, otherStateEnumVal, signalEnumval);
}

