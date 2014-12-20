/*
 * BytesToHexString.h
 *
 *  Created on: Dec 10, 2014
 *      Author: Quark
 */

#ifndef BYTESTOHEXSTRING_H_
#define BYTESTOHEXSTRING_H_

#include <stdint.h>

void BytesToHexString( char* stringBuff, uint16_t buffLen, const void *bytes, uint8_t bytesCount );


#endif /* BYTESTOHEXSTRING_H_ */
