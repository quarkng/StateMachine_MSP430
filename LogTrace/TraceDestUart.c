/*
 * TraceDestUart.c
 *
 *  Created on: Dec 10, 2014
 *      Author: Quark
 */


#include <TraceDestUart.h>

static void writeFunc(TraceDestBase_t* context, LogTraceLevel_t level, const char *group, const char *msg);

//**********************************************************************************************************************

void TraceDestUart_Init(TraceDestUart_t *context, TraceDestUart_SendFunc sndFunc,
						TraceDestUart_SendStringFunc sndStrFunc)
{
	context->base.writeFunc  = writeFunc;
	context->send    	     = sndFunc;
	context->sendStr 		 = sndStrFunc;
}

//**********************************************************************************************************************

static void writeFunc(TraceDestBase_t* context, LogTraceLevel_t level, const char *group, const char *msg)
{
	TraceDestUart_t *ctx = (TraceDestUart_t*) context;
	char lvlText = '0' + (char) level;

	(*ctx->sendStr)(group);
	(*ctx->send)(",", 1);

	(*ctx->send)((uint8_t*) &lvlText, 1);
	(*ctx->send)(",", 1);

	(*ctx->sendStr)(msg);
	(*ctx->send)("\r\n", 2);
}

