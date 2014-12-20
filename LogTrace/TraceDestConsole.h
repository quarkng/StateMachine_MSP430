/*
 * TraceDestConsole.h
 *
 *  Created on: Dec 10, 2014
 *      Author: Quark
 */

#ifndef TRACEDESTCONSOLE_H_
#define TRACEDESTCONSOLE_H_

#include <stdint.h>

#include <TraceDestBase.h>


typedef struct
{
	TraceDestBase_t base;
}
TraceDestConsole_t;

void TraceDestConsole_Init(TraceDestConsole_t *obj);


#endif /* TRACEDESTCONSOLE_H_ */
