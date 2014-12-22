/*
 * StaMchState.h
 *
 *  Created on: Dec 20, 2014
 *      Author: Quark
 */

#ifndef STAMCHSTATE_H_
#define STAMCHSTATE_H_

#include <stdint.h>
#include "StaMchSignal.h"

typedef void (*StaMchStateChangeFunc_t)(int16_t otherStateEnumVal, int16_t signalEnumval);
typedef void (*StaMchStateRun_t)( uint32_t iteration );

typedef struct
{
	uint8_t    				  		enumVal;
	const char 				 	   *name;
	StaMchStateChangeFunc_t   		entryFunc;
	StaMchStateRun_t          		runFunc;
	StaMchStateChangeFunc_t   	    exitFunc;
	const StaMchSignalTableEntry_t *transitions;
}
StaMchState_t;


void StaMchState_Init( StaMchState_t *context,  uint8_t enumVal, const char *name);




#endif /* STAMCHSTATE_H_ */
