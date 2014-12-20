/*
 * TraceDestUart.h
 *
 *  Created on: Dec 10, 2014
 *      Author: Quark
 */

#ifndef TRACEDESTUART_H_
#define TRACEDESTUART_H_

#include <stdint.h>

#include <TraceDestBase.h>

typedef void (*TraceDestUart_SendFunc)(const uint8_t *pui8Buffer, uint32_t ui32Count);
typedef void (*TraceDestUart_SendStringFunc)(const char *pcBuffer);

typedef struct
{
	TraceDestBase_t         	 base;
	TraceDestUart_SendFunc       send;
	TraceDestUart_SendStringFunc sendStr;
}
TraceDestUart_t;


void TraceDestUart_Init(TraceDestUart_t *context, TraceDestUart_SendFunc sndFunc,
						TraceDestUart_SendStringFunc sndStrFunc);


#endif /* TRACEDESTUART_H_ */
