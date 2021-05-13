/*
 * flash.h
 *
 *  Created on: May 9, 2021
 *      Author: evan
 */

#ifndef FLASH_H_
#define FLASH_H_

extern void write_value_to_flash(unsigned value, unsigned address);
extern void erase_flash_page (unsigned address);

extern unsigned const FLASH_BASE_REG;
extern unsigned const USER_FLASH_BASE_ADDR;

extern unsigned const FLASH_MEM_ADDR_OFFSET;
extern unsigned const FLASH_MEM_DATA_OFFSET;
extern unsigned const FLASH_MEM_CTL_OFFSET;

extern unsigned const FLASH_CTL_WRITE_MEM_BITMASK;
extern unsigned const FLASH_CTL_ERASE_MEM_BITMASK;

extern unsigned const MEM_SYSCTL_PROT_REG_BASE;

extern unsigned const BOOTCFG_OFFSET;
extern unsigned const FLASH_MEM_READ_ENABLE;
extern unsigned const FLASH_MEM_PROG_ENABLE;


extern unsigned const BOOTCFG_KEY_BITMASK;
extern unsigned const BOOTCFG_KEY_VAL_TRUE;
extern unsigned const BOOTCFG_KEY_VAL_FALSE;

#endif /* FLASH_H_ */
