/*
 * StateMachineExample.c
 *
 *  Created on: Dec 21, 2014
 *      Author: Quark
 */

#include "intrinsics.h"

#include "StateMachineExample.h"
#include "StateMachineExample_Functions.h"
#include "StateMachineExample_StateAndSig.h"
#include "StateMachineExample_Tables.h"

#include "HwAbUart.h"
#include "BytesToHexString.h"


bool exitExample = false;

//****************************************************************************************
static void ProcessRx( uint8_t rx )
{
	while( ! HwAbUart_IsDoneTransmitting() ) {} // BUSY WAIT
	HwAbUart_SendString("Received ");
	HwAbUart_Send(&rx, 1);
	HwAbUart_SendString("\r\n");
	while( ! HwAbUart_IsDoneTransmitting() ) {} // BUSY WAIT

	switch( rx )
	{
		case 'w':
		case 'W':
			StateMachineExample_Signal(ExSigW);
			break;

		case 'x':
		case 'X':
			StateMachineExample_Signal(ExSigX);
			break;

		case 'y':
		case 'Y':
			StateMachineExample_Signal(ExSigY);
			break;

		case 'z':
		case 'Z':
			StateMachineExample_Signal(ExSigZ);
			break;

		default:
			HwAbUart_SendString("Type W,X,Y, or Z to send a signal.\r\n");
		break;
	}

}

//****************************************************************************************
static void DoEntry(int16_t enteredState, int16_t prevState, int16_t signal )
{
	const char* enteredStateName = stateTbl[enteredState].name;
	const char* prevStateName = (prevState < 0) ? "N/A" : stateTbl[prevState].name;
	const char* signalName = (signal < 0) ? "N/A" : signalTbl[signal].name;

	while( ! HwAbUart_IsDoneTransmitting() ) {} // BUSY WAIT

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
	uint8_t  rx;
	bool valid;

	while( ! HwAbUart_IsDoneTransmitting() ) {} // BUSY WAIT
	if( iteration < 5 )
	{
		char hexStr[16];
		uint8_t iter = iteration;

		HwAbUart_SendString("Run [");
		HwAbUart_SendString(currentStateName);
		HwAbUart_SendString("] iteration [");
		BytesToHexString( hexStr, sizeof(hexStr)/sizeof(hexStr[0]), &iter, sizeof(iter) );
		HwAbUart_SendString(hexStr);
		HwAbUart_SendString("]\r\n");
	}

	rx = HwAbUart_GetRxByte(&valid);
	if( valid )
	{
		ProcessRx( rx );
	}

	__delay_cycles(1000000);
}

static void DoExit(int16_t exitingState, int16_t nextState, int16_t signal )
{
	const char* exitingStateName = stateTbl[exitingState].name;
	const char* nextStateName = stateTbl[nextState].name;
	const char* signalName = signalTbl[signal].name;

	while( ! HwAbUart_IsDoneTransmitting() ) {} // BUSY WAIT

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

}
void StateARun( uint32_t iteration )
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

}
void StateBRun( uint32_t iteration )
{
	DoRun(ExStaBBB, iteration);
}
void StateBExit( int16_t otherStateEnumVal, int16_t signalEnumval )
{
	DoExit(ExStaBBB, otherStateEnumVal, signalEnumval);
}
//****************************************************************************************
void StateCEntry( int16_t otherStateEnumVal, int16_t signalEnumval )
{
	DoEntry(ExStaCCC, otherStateEnumVal, signalEnumval);

}
void StateCRun( uint32_t iteration )
{
	DoRun(ExStaCCC, iteration);
}
void StateCExit( int16_t otherStateEnumVal, int16_t signalEnumval )
{
	DoExit(ExStaCCC, otherStateEnumVal, signalEnumval);
}
//****************************************************************************************
void StateDEntry( int16_t otherStateEnumVal, int16_t signalEnumval )
{
	DoEntry(ExStaDDD, otherStateEnumVal, signalEnumval);

}
void StateDRun( uint32_t iteration )
{
	DoRun(ExStaDDD, iteration);
}
void StateDExit( int16_t otherStateEnumVal, int16_t signalEnumval )
{
	DoExit(ExStaDDD, otherStateEnumVal, signalEnumval);
}
//****************************************************************************************
void StateEEntry( int16_t otherStateEnumVal, int16_t signalEnumval )
{
	DoEntry(ExStaEEE, otherStateEnumVal, signalEnumval);

}
void StateERun( uint32_t iteration )
{
	DoRun(ExStaEEE, iteration);
}
void StateEExit( int16_t otherStateEnumVal, int16_t signalEnumval )
{
	DoExit(ExStaEEE, otherStateEnumVal, signalEnumval);
}
//****************************************************************************************
void StateFEntry( int16_t otherStateEnumVal, int16_t signalEnumval )
{
	DoEntry(ExStaFFF, otherStateEnumVal, signalEnumval);
}
void StateFRun( uint32_t iteration )
{
	DoRun(ExStaFFF, iteration);
}
void StateFExit( int16_t otherStateEnumVal, int16_t signalEnumval )
{
	DoExit(ExStaFFF, otherStateEnumVal, signalEnumval);
}
//****************************************************************************************
void StateExitEntry( int16_t otherStateEnumVal, int16_t signalEnumval )
{
	DoEntry(ExSta_EXIT, otherStateEnumVal, signalEnumval);
	exitExample = true;
}
void StateExitRun( uint32_t iteration )
{
	DoRun(ExSta_EXIT, iteration);
}
void StateExitExit( int16_t otherStateEnumVal, int16_t signalEnumval )
{
	DoExit(ExSta_EXIT, otherStateEnumVal, signalEnumval);
}

