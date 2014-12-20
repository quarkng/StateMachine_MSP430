/*
 * TraceDestFile.h
 *
 *  Created on: Dec 10, 2014
 *      Author: Quark
 */

#ifndef TRACEDESTFILE_H_
#define TRACEDESTFILE_H_

#include <stdint.h>

#include <TraceDestBase.h>


typedef struct
{
	TraceDestBase_t base;
	void *fid;
}
TraceDestFile_t;

void TraceDestFile_Init(TraceDestFile_t *obj, const char *filename);




#endif /* TRACEDESTFILE_H_ */
