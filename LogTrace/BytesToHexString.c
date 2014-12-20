/*
 * BytesToHexString.c
 *
 *  Created on: Dec 10, 2014
 *      Author: Quark
 */



#include <BytesToHexString.h>



void BytesToHexString( char* stringBuff, uint16_t buffLen, const void *bytes, uint8_t bytesCount )
{
	static const char hexVal[] = "0123456789ABCDEF";

	uint8_t i = 0;
	uint8_t *b = (uint8_t*) bytes;
	uint8_t *bEnd = &(b[bytesCount]);


	while( (b < bEnd) && (i < (buffLen-3)))
	{
		stringBuff[i] = hexVal[ (*b>>4) & 0x0F ];
		i++;
		stringBuff[i] = hexVal[ (*b) & 0x0F ];
		i++;
		stringBuff[i] = '.';
		b++;
	}

	// Null terminate the string
	if( i >= buffLen-1 )
	{
		i = buffLen-1;
	}
	stringBuff[i] = 0;
}
