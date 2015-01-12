/*
 * StateMachineExample.h
 *
 *  Created on: Dec 21, 2014
 *      Author: Quark
 */

#ifndef STATEMACHINEEXAMPLE_H_
#define STATEMACHINEEXAMPLE_H_

#include <stdint.h>
#include <stdbool.h>
#include "InfUserStream.h"

void StateMachineExample(const InfUserStream_t *userStream);

bool StateMachineExample_Signal(uint8_t signalEnumVal);

#endif /* STATEMACHINEEXAMPLE_H_ */
