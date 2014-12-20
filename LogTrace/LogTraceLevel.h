/*
 * LogTraceLevel.h
 *
 *  Created on: Dec 10, 2014
 *      Author: Quark
 */

#ifndef LOGTRACELEVEL_H_
#define LOGTRACELEVEL_H_

#include <stdint.h>
#include <stdbool.h>

typedef enum LogTraceLevelEnum
{
	LogTraceLevel_OFF     = 0,
	LogTraceLevel_ERROR   = 1,
	LogTraceLevel_WARNING = 2,
	LogTraceLevel_INFO    = 3,
	LogTraceLevel_VERBOSE = 4
} LogTraceLevel_t;


inline bool LogTraceLevel_IsValidLevel( LogTraceLevel_t level )
{
	return ( ((uint8_t) level) <= LogTraceLevel_VERBOSE);
}


// If this function returns true, then the message with the "msgLevel" should be included in the
// log destination with the level set to "setting".
inline uint8_t LogTraceLevel_TestLevel( LogTraceLevel_t setting, LogTraceLevel_t msgLevel )
{
	return (setting >= msgLevel);
}


#endif /* LOGTRACELEVEL_H_ */
