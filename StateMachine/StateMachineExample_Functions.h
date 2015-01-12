/*
 * StateMachineExample_Functions.h
 *
 *  Created on: Dec 21, 2014
 *      Author: Quark
 */

#ifndef STATEMACHINEEXAMPLEFUNCTIONS_H_
#define STATEMACHINEEXAMPLEFUNCTIONS_H_

#include <stdbool.h>
#include "InfUserStream.h"

extern bool exitExample;

void StateMachineExampleFunctions_Init( const InfUserStream_t *userStream );


void StateAEntry( int16_t otherStateEnumVal, int16_t signalEnumval );
void StateARun( uint32_t iteration );
void StateAExit( int16_t otherStateEnumVal, int16_t signalEnumval );

void StateBEntry( int16_t otherStateEnumVal, int16_t signalEnumval );
void StateBRun( uint32_t iteration );
void StateBExit( int16_t otherStateEnumVal, int16_t signalEnumval );

void StateCEntry( int16_t otherStateEnumVal, int16_t signalEnumval );
void StateCRun( uint32_t iteration );
void StateCExit( int16_t otherStateEnumVal, int16_t signalEnumval );

void StateDEntry( int16_t otherStateEnumVal, int16_t signalEnumval );
void StateDRun( uint32_t iteration );
void StateDExit( int16_t otherStateEnumVal, int16_t signalEnumval );

void StateEEntry( int16_t otherStateEnumVal, int16_t signalEnumval );
void StateERun( uint32_t iteration );
void StateEExit( int16_t otherStateEnumVal, int16_t signalEnumval );

void StateFEntry( int16_t otherStateEnumVal, int16_t signalEnumval );
void StateFRun( uint32_t iteration );
void StateFExit( int16_t otherStateEnumVal, int16_t signalEnumval );

void StateExitEntry( int16_t otherStateEnumVal, int16_t signalEnumval );
void StateExitRun( uint32_t iteration );
void StateExitExit( int16_t otherStateEnumVal, int16_t signalEnumval );


#endif /* STATEMACHINEEXAMPLEFUNCTIONS_H_ */
