/*
 * flash.c
 *
 *  Created on: May 10, 2021
 *      Author: evan
 */
#include <flash.h>
#include <util.h>

unsigned const FLASH_BASE_REG = 0x400FD000u;
unsigned const USER_FLASH_BASE_ADDR = 0x00020000u;

unsigned const FLASH_MEM_ADDR_OFFSET = 0x0u;
unsigned const FLASH_MEM_DATA_OFFSET = 0x4u;
unsigned const FLASH_MEM_CTL_OFFSET = 0x8u;

unsigned const FLASH_CTL_WRITE_MEM_BITMASK = 0x1u;
unsigned const FLASH_CTL_ERASE_MEM_BITMASK = 0x2u;

unsigned const MEM_SYSCTL_PROT_REG_BASE = 0x400FE000u;

unsigned const BOOTCFG_OFFSET = 0x1D0u;
unsigned const FLASH_MEM_READ_ENABLE = 0x130u;
unsigned const FLASH_MEM_PROG_ENABLE = 0x134u;

unsigned const BOOTCFG_KEY_BITMASK = 0x1u << 4;
unsigned const BOOTCFG_KEY_VAL_TRUE = 0xA4420000u;
unsigned const BOOTCFG_KEY_VAL_FALSE = 0x71D50000u;


// Address: (0x0 - 0x3FFFF)
void write_value_to_flash(unsigned value, unsigned address){
    // Program a 32 Bit Word
    // 1. Write source data to FMD
    *offset_reg(FLASH_BASE_REG, FLASH_MEM_DATA_OFFSET) = value;
    // 2. Write Target Address to FMA
    *offset_reg(FLASH_BASE_REG, FLASH_MEM_ADDR_OFFSET) = address;
    // 3. Write the Flash memory write key and the WRITE bit to the FMC reg
    //      3a. KEY Bit of BOOTCFG register determines wether 0xA442 or 0x71D5
    unsigned boot_cfg_key = *offset_reg(MEM_SYSCTL_PROT_REG_BASE, BOOTCFG_OFFSET) & BOOTCFG_KEY_BITMASK;
    unsigned boot_key_val = (boot_cfg_key) ? BOOTCFG_KEY_VAL_TRUE : BOOTCFG_KEY_VAL_FALSE;
    *offset_reg(FLASH_BASE_REG, FLASH_MEM_CTL_OFFSET) |= (boot_key_val | FLASH_CTL_WRITE_MEM_BITMASK);
    // 4. Poll FMC until write bit is cleared
    while (*offset_reg(FLASH_BASE_REG, FLASH_MEM_CTL_OFFSET) & FLASH_CTL_WRITE_MEM_BITMASK);
}

void erase_flash_page (unsigned address) {
    //1. write page address
    *offset_reg(FLASH_BASE_REG, FLASH_MEM_ADDR_OFFSET) = address;
    //2. Write flash memkey and erase bit (bit 1)
    unsigned boot_cfg_key = *offset_reg(MEM_SYSCTL_PROT_REG_BASE, BOOTCFG_OFFSET) & BOOTCFG_KEY_BITMASK;
    unsigned boot_key_val = (boot_cfg_key) ? BOOTCFG_KEY_VAL_TRUE : BOOTCFG_KEY_VAL_FALSE;
    *offset_reg(FLASH_BASE_REG, FLASH_MEM_CTL_OFFSET) |= (boot_key_val | FLASH_CTL_ERASE_MEM_BITMASK);
    //3. Poll the erase bit
    while (*offset_reg(FLASH_BASE_REG, FLASH_MEM_CTL_OFFSET) & FLASH_CTL_ERASE_MEM_BITMASK);
}

