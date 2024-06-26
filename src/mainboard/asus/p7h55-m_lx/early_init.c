/* SPDX-License-Identifier: GPL-2.0-or-later */

#include <bootblock_common.h>
#include <device/dram/ddr3.h>
#include <northbridge/intel/ironlake/raminit.h>
#include <southbridge/intel/ibexpeak/pch.h>
#include <superio/ite/it8718f/it8718f.h>
#include <superio/ite/common/ite.h>

#define SERIAL_DEV PNP_DEV(0x2e, IT8718F_SP1)
#define GPIO_DEV PNP_DEV(0x2e, IT8718F_GPIO)
#define EC_DEV PNP_DEV(0x2e, IT8718F_EC)

/* Early mainboard specific GPIO setup.
 * We should use standard gpio.h eventually
 */

void bootblock_mainboard_early_init(void)
{
	/* Set default GPIOs on superio */
	ite_reg_write(GPIO_DEV, 0x25, 0x00);
	ite_reg_write(GPIO_DEV, 0x26, 0xc7);
	ite_reg_write(GPIO_DEV, 0x27, 0x80);
	ite_reg_write(GPIO_DEV, 0x28, 0x41);
	ite_reg_write(GPIO_DEV, 0x29, 0x0a);
	ite_reg_write(GPIO_DEV, 0x2c, 0x01);
	ite_reg_write(GPIO_DEV, 0x62, 0x08);
	ite_reg_write(GPIO_DEV, 0x72, 0x00);
	ite_reg_write(GPIO_DEV, 0x73, 0x00);
	ite_reg_write(GPIO_DEV, 0xb8, 0x00);
	ite_reg_write(GPIO_DEV, 0xbb, 0x40);
	ite_reg_write(GPIO_DEV, 0xc0, 0x00);
	ite_reg_write(GPIO_DEV, 0xc1, 0xc7);
	ite_reg_write(GPIO_DEV, 0xc2, 0x80);
	ite_reg_write(GPIO_DEV, 0xc3, 0x01);
	ite_reg_write(GPIO_DEV, 0xc4, 0x0a);
	ite_reg_write(GPIO_DEV, 0xc8, 0x00);
	ite_reg_write(GPIO_DEV, 0xc9, 0x04);
	ite_reg_write(GPIO_DEV, 0xcb, 0x00);
	ite_reg_write(GPIO_DEV, 0xcc, 0x02);
	ite_reg_write(GPIO_DEV, 0xf0, 0x10);
	ite_reg_write(GPIO_DEV, 0xf1, 0x40);
	ite_reg_write(GPIO_DEV, 0xf6, 0x26);
	ite_reg_write(GPIO_DEV, 0xfc, 0x52);

	ite_reg_write(EC_DEV, 0xf0, 0x80);
	ite_reg_write(EC_DEV, 0xf1, 0x00);
	ite_reg_write(EC_DEV, 0xf2, 0x0a);
	ite_reg_write(EC_DEV, 0xf3, 0x80);
	ite_reg_write(EC_DEV, 0x70, 0x00); // Don't use IRQ9
	ite_reg_write(EC_DEV, 0x30, 0x01); // Enable

	ite_enable_serial(SERIAL_DEV, CONFIG_TTYS0_BASE);

	/* Disable SIO reboot */
	ite_reg_write(GPIO_DEV, 0xEF, 0x7E);

	/* IRQ routing */
	RCBA32(D31IP) = 0x00002210;
	RCBA32(D30IP) = 0x00002100;
	RCBA32(D29IP) = 0x10004321;
	RCBA32(D28IP) = 0x00214321;
	RCBA32(D27IP) = 0x00000001;
	RCBA32(D31IR) = 0x00410032;
	RCBA32(D29IR) = 0x32100237;
	RCBA32(D27IR) = 0x00000000;
}

void mb_get_spd_map(u8 spd_map[4])
{
	spd_map[0] = 0x50;
	spd_map[2] = 0x52;
}
