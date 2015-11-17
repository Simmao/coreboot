/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2016 Intel Corp.
 * (Written by Lance Zhao <lijian.zhao@intel.com> for Intel Corp.)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#include <arch/acpi.h>
#include <cpu/x86/smm.h>
#include <soc/acpi.h>
#include <soc/iomap.h>
#include <soc/pm.h>

unsigned long acpi_fill_mcfg(unsigned long current)
{
	/* PCI Segment Group 0, Start Bus Number 0, End Bus Number is 255 */
	current += acpi_create_mcfg_mmconfig((void *) current,
					     CONFIG_MMCONF_BASE_ADDRESS, 0, 0,
					     255);
	return current;
}

unsigned long acpi_fill_madt(unsigned long current)
{
	return current;
}

static int acpi_sci_irq(void)
{
	int sci_irq = 9;
	return sci_irq;
}

void soc_fill_common_fadt(acpi_fadt_t * fadt)
{
	const uint16_t pmbase = ACPI_PMIO_BASE;

	fadt->sci_int = acpi_sci_irq();
	fadt->smi_cmd = 0;	/* No Smi Handler as SMI_CMD is 0*/

	fadt->pm1a_evt_blk = pmbase + PM1_STS;
	fadt->pm1a_cnt_blk = pmbase + PM1_CNT;
	fadt->pm_tmr_blk = pmbase + PM1_TMR;
	fadt->gpe0_blk = pmbase + GPE0_STS(0);

	fadt->pm1_evt_len = 4;
	fadt->pm1_cnt_len = 2;
	fadt->pm_tmr_len = 4;
	/* There are 4 GPE0 STS/EN pairs each 32 bits wide. */
	fadt->gpe0_blk_len = 2 * GPE0_REG_MAX * sizeof(uint32_t);
	fadt->p_lvl2_lat = ACPI_FADT_C2_NOT_SUPPORTED;
	fadt->p_lvl3_lat = ACPI_FADT_C3_NOT_SUPPORTED;
	fadt->flush_size = 0x400;	/* twice of cache size*/
	fadt->flush_stride = 0x10;	/* Cache line width  */
	fadt->duty_offset = 1;
	fadt->duty_width = 3;
	fadt->day_alrm = 0xd;
	fadt->iapc_boot_arch = ACPI_FADT_LEGACY_DEVICES | ACPI_FADT_8042;

	fadt->flags = ACPI_FADT_WBINVD | ACPI_FADT_C1_SUPPORTED |
	    ACPI_FADT_C2_MP_SUPPORTED | ACPI_FADT_SLEEP_BUTTON |
	    ACPI_FADT_RESET_REGISTER | ACPI_FADT_SEALED_CASE |
	    ACPI_FADT_S4_RTC_WAKE | ACPI_FADT_PLATFORM_CLOCK;

	fadt->reset_reg.space_id = 1;
	fadt->reset_reg.bit_width = 8;
	fadt->reset_reg.addrl = 0xcf9;
	fadt->reset_value = 6;

	fadt->x_pm1a_evt_blk.space_id = 1;
	fadt->x_pm1a_evt_blk.bit_width = fadt->pm1_evt_len * 8;
	fadt->x_pm1a_evt_blk.addrl = pmbase + PM1_STS;

	fadt->x_pm1b_evt_blk.space_id = 1;

	fadt->x_pm1a_cnt_blk.space_id = 1;
	fadt->x_pm1a_cnt_blk.bit_width = fadt->pm1_cnt_len * 8;
	fadt->x_pm1a_cnt_blk.addrl = pmbase + PM1_CNT;

	fadt->x_pm1b_cnt_blk.space_id = 1;

	fadt->x_pm_tmr_blk.space_id = 1;
	fadt->x_pm_tmr_blk.bit_width = fadt->pm_tmr_len * 8;
	fadt->x_pm_tmr_blk.addrl = pmbase + PM1_TMR;

	fadt->x_gpe1_blk.space_id = 1;
}
