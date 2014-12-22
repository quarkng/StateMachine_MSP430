/*
 * StateMachineExample.h
 *
 *  Created on: Dec 21, 2014
 *      Author: Quark
 */

#ifndef STATEMACHINEEXAMPLEFUNCTIONS_H_
#define STATEMACHINEEXAMPLEFUNCTIONS_H_

#include <stdbool.h>

extern bool exitExample;


void StateAEntry( int16_t otherStateEnumVal, int16_t signalEnumval );
void StateARun( uint32_t iteration );
void StateAExit( int16_t otherStateEnumVal, int16_t signalEnumval );

void StateBEntry( int16_t otherStateEnumVal, int16_t signalEnumval );
void StateBRun( uint32_t iteration );
void StateBExit( int16_t otherStateEnumVal, int16_t signalEnumval );


#endif /* STATEMACHINEEXAMPLEFUNCTIONS_H_ */
