/*
 * DiagTrace.c
 *
 *  Created on: Dec 10, 2014
 *      Author: Quark
 */


#include <LogTrace.h>
#include <BytesToHexString.h>


static TraceDestBase_t* dest[LogTrace_MAX_DEST];
static uint8_t countDestAdded;
static LogTraceLevel_t lowestLevel;


#ifdef LogTrace_BUFFER_IN_STATIC_RAM
static char buffer[LogTrace_BUFFER_SIZE];
#endif


static LogTraceLevel_t FindLowestLevel( void );



void LogTrace_Init( void )
{
	countDestAdded = 0;
	lowestLevel = LogTraceLevel_OFF;
}


// Returns Destination Handle
int8_t LogTrace_AddTraceDestination(TraceDestBase_t *traceDestObj, LogTraceLevel_t level)
{
	int8_t destHandle = -1;

	if( countDestAdded < LogTrace_MAX_DEST )
	{
		dest[countDestAdded] = traceDestObj;
		destHandle = countDestAdded;
		countDestAdded++;

		LogTrace_SetTraceLevelForDest( destHandle, level );
	}
	return destHandle;
}


// Allows changing the trace level of a specific destination
void LogTrace_SetTraceLevelForDest(uint8_t destHandle, LogTraceLevel_t level)
{
	if( LogTraceLevel_IsValidLevel( level ) == 0 )
	{
		// Log invalid level value
	}
	else if( destHandle < countDestAdded )
	{
		dest[ destHandle ]->level = level;
		lowestLevel = FindLowestLevel();
	}
	else
	{
		// Log invalid destination handle
	}
}


static LogTraceLevel_t FindLowestLevel( void )
{
	LogTraceLevel_t lvl = LogTraceLevel_OFF;
	uint8_t i;

	for( i = 0; i < countDestAdded; i++ )
	{
		if( LogTraceLevel_TestLevel( lvl, dest[i]->level ) == 0 )
		{
			lvl = dest[i]->level;
		}
	}

	return lvl;
}




void LogTrace_Write(LogTraceLevel_t level, const char *group, const char *msg )
{
	uint8_t i;

	if( LogTraceLevel_TestLevel( lowestLevel, level ) != 0 )
	{
		for( i = 0; i < countDestAdded; i++ )
		{
			if( LogTraceLevel_TestLevel( dest[i]->level, level ) != 0 )
			{
				(*(dest[ i ]->writeFunc))(dest[i], level, group, msg);
			}
		}
	}
}


void LogTrace_WriteHex(LogTraceLevel_t level, const char *group, const void *bytes, uint8_t bytesCount )
{
#ifdef LogTrace_BUFFER_IN_STACK
	char buffer[LogTrace_BUFFER_SIZE];
#endif
	BytesToHexString( buffer, LogTrace_BUFFER_SIZE, bytes, bytesCount);
	LogTrace_Write(level, group, buffer );
}

