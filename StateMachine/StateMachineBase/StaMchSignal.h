/*
 * StaMchSignal.h
 *
 *  Created on: Dec 21, 2014
 *      Author: Quark
 */

#ifndef STAMCHSIGNAL_H_
#define STAMCHSIGNAL_H_

#include <stdint.h>

typedef struct
{
	uint8_t    enumVal;
	const char *name;
} StaMchSignal_t;

typedef struct
{
	int16_t signalEnumVal;
	int16_t nextStateEnumVal;
} StaMchSignalTableEntry_t;


#endif /* STAMCHSIGNAL_H_ */
