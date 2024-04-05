/* SPDX-License-Identifier: GPL-2.0-only */

#include <arch/mmu.h>
#include <bootblock_common.h>
#include <symbols.h>

void bootblock_mainboard_init(void)
{
	mmu_init();

	/* Everything below DRAM is device memory */
	mmu_config_range((void *)0, (uintptr_t)_dram, MA_DEV | MA_RW);
	mmu_config_range(_dram, (uintptr_t)CONFIG_DRAM_SIZE_MB * MiB, MA_MEM | MA_RW);

	mmu_config_range(_ttb, REGION_SIZE(ttb), MA_MEM | MA_S | MA_RW);
	mmu_config_range(_bootblock, REGION_SIZE(bootblock), MA_MEM | MA_S | MA_RW);
	mmu_config_range(_romstage, REGION_SIZE(romstage), MA_MEM | MA_S | MA_RW);
	mmu_config_range(_ramstage, REGION_SIZE(ramstage), MA_MEM | MA_S | MA_RW);

	mmu_config_range(_bl31, REGION_SIZE(bl31), MA_MEM | MA_S | MA_RW);

	mmu_config_range((void *)CONFIG_ECAM_MMCONF_BASE_ADDRESS, CONFIG_ECAM_MMCONF_LENGTH,
			 MA_DEV | MA_RW);

	mmu_enable();
}
