/* SPDX-License-Identifier: GPL-2.0-or-later */

#include <device/azalia_device.h>

const u32 cim_verb_data[] = {
	0x10ec0272,	/* Codec Vendor / Device ID: Realtek ALC272X */
	0x10250379,	/* Subsystem ID  */
	0,		/* Number of 4 dword sets */
};

const u32 pc_beep_verbs[0] = {};

AZALIA_ARRAY_SIZES;
