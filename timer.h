/*
 * timer.h
 *
 *  Created on: Sep 5, 2021
 *      Author: evan
 */

#ifndef TIMER_H_
#define TIMER_H_

extern unsigned const TIMER_BASE_REG;
extern unsigned const TIMER_CTL_OFFSET;
extern unsigned const TIMER_A_MODE_OFFSET;
extern unsigned const TIMER_A_INTERVAL_OFFSET;
extern unsigned const TIMER_A_VAL_OFFSET;
extern unsigned const TIMER0_BASE_ADDR;
void poll_timer(int seconds);


#endif /* TIMER_H_ */
