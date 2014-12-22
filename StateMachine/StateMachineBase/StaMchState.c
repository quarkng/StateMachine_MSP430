/*
 * StaMchState.c
 *
 *  Created on: Dec 20, 2014
 *      Author: Quark
 */


#include "StaMchState.h"

static const StaMchSignalTableEntry_t emptyTransitions[] = {
	{ -1, -1 } // Always end with negative values.  Indicates end-of-list.
};



void StaMchState_Init( StaMchState_t *context,  uint8_t enumVal, const char *name)
{
	context->enumVal 	= enumVal;
	context->name    	= name;
	context->entryFunc	= 0;
	context->runFunc  = 0;
	context->exitFunc	= 0;
	context->transitions = emptyTransitions;
}
