/*
 * LogTrace_TraceDestBase.h
 *
 *  Created on: Dec 10, 2014
 *      Author: Quark
 */

#ifndef TRACEDESTBASE_H_
#define TRACEDESTBASE_H_

#include <LogTraceLevel.h>

typedef struct TraceDestBase
{
	LogTraceLevel_t level;
	void (*writeFunc)(struct TraceDestBase *context, LogTraceLevel_t level, const char *group, const char *msg);
}
TraceDestBase_t;



#endif /* TRACEDESTBASE_H_ */
