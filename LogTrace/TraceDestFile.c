/*
 * TraceDestUart.c
 *
 *  Created on: Dec 10, 2014
 *      Author: Quark
 */

#include <stdio.h>
#include <TraceDestFile.h>

static void writeFunc(TraceDestBase_t* context, LogTraceLevel_t level, const char *group, const char *msg);



void TraceDestFile_Init(TraceDestFile_t *obj, const char *filename)
{
	FILE *fid;

	fid = fopen(filename,"a");
	obj->fid = (void*)fid;
	obj->base.writeFunc = writeFunc;
}

static void writeFunc(TraceDestBase_t* context, LogTraceLevel_t level, const char *group, const char *msg)
{
	FILE *fid = (FILE*)( ((TraceDestFile_t*)context)->fid  );

	if( fid != 0 )
	{
		char lvlText = '0' + (char) level;

		fprintf(fid,"%s,%c,%s\n", group, lvlText, msg);

		//fflush(fid);
	}
}

