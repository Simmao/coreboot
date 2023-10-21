/* SPDX-License-Identifier: GPL-2.0-only */

#include <console/console.h>
#include <northbridge/intel/ironlake/ironlake.h>
#include <types.h>

void die_notify(void)
{
	for (unsigned int i = 0; i < 0x4000; i += 4) {
		const u32 r = mchbar_read32(i);
		if (r)
			printk(BIOS_DEBUG, "0x%04x: 0x%08x\n", i, r);
	}
}
