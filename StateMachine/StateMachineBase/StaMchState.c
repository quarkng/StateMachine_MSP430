/*
 * StaMchState.c
 *
 *  Created on: Dec 20, 2014
 *      Author: Quark
 */


#include "StaMchState.h"

void StaMchState_Init( StaMchState_t *context,  uint8_t enumVal, const char *name)
{
	context->enumVal 	= enumVal;
	context->name    	= name;
	context->entryFunc	= 0;
	context->runFunc  = 0;
	context->exitFunc	= 0;
}
