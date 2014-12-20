/*
 * DiagTrace.h
 *
 *  Created on: Dec 10, 2014
 *      Author: Quark
 */

#ifndef LOGTRACE_H_
#define LOGTRACE_H_

#include <stdint.h>

#include <LogTraceLevel.h>
#include <TraceDestBase.h>


#define LogTrace_MAX_DEST     (3) // Max count of destinations for logging messages
#define LogTrace_BUFFER_SIZE (64) // String buffer length used to LogTrace

//--------------------------------------------------------------------
// Select one of the below to determine where the buffer should reside
//#define LogTrace_BUFFER_IN_STACK
#define LogTrace_BUFFER_IN_STATIC_RAM
//--------------------------------------------------------------------


void LogTrace_Init( void );


int8_t LogTrace_AddTraceDestination(TraceDestBase_t *traceDestObj, LogTraceLevel_t level); // Returns Destination Handle
void   LogTrace_SetTraceLevelForDest(uint8_t destHandle, LogTraceLevel_t level);


void LogTrace_Write(LogTraceLevel_t level, const char *group, const char *msg );
void LogTrace_WriteHex(LogTraceLevel_t level, const char *group, const void *bytes, uint8_t bytesCount );

#endif /* LOGTRACE_H_ */
