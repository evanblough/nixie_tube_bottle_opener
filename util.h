/*
 * util.h
 *
 *  Created on: May 9, 2021
 *      Author: evan
 */

#ifndef UTIL_H_
#define UTIL_H_


static inline volatile unsigned * offset_reg (unsigned base, unsigned offset) { return (volatile unsigned *) (base | offset); };

#endif /* UTIL_H_ */
