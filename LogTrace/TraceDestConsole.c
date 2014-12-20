/*
 * TraceDestConsole.c
 *
 *  Created on: Dec 10, 2014
 *      Author: Quark
 */

#include <stdio.h>
#include <TraceDestConsole.h>

static void writeFunc(TraceDestBase_t* context, LogTraceLevel_t level, const char *group, const char *msg);



void TraceDestConsole_Init(TraceDestConsole_t *context)
{
	context->base.writeFunc = writeFunc;
}

static void writeFunc(TraceDestBase_t* context, LogTraceLevel_t level, const char *group, const char *msg)
{
	char lvlText = '0' + (char) level;

	printf("%s,%c,%s\r\n", group, lvlText, msg); // Requires HEAP memory!!!
}

