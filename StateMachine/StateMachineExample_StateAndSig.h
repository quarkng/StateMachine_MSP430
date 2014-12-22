/*
 * StateMachineExample.h
 *
 *  Created on: Dec 21, 2014
 *      Author: Quark
 */

#ifndef STATEMACHINEEXAMPLE_STATEANDSIG_H_
#define STATEMACHINEEXAMPLE_STATEANDSIG_H_

typedef enum
{
	ExStaAAA,
	ExStaBBB,
	ExStaCCC,
	ExStaDDD,
	ExStaEEE,
	ExStaFFF,
	ExSta_EXIT,
	//...................
	ExSta_Count
} ExampleState_t;

typedef enum
{
	ExSigW,
	ExSigX,
	ExSigY,
	ExSigZ,
	//...................
	ExSig_Count
} ExampleSignal_t;

#endif /* STATEMACHINEEXAMPLE_STATEANDSIG_H_ */
