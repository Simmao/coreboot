/* SPDX-License-Identifier: GPL-2.0-only */

#include <device/azalia_device.h>

const u32 cim_verb_data[] = {
	0x10ec0662,	/* Codec Vendor / Device ID: Realtek */
	0x1b0a013f,	/* Subsystem ID */
	12,		/* Number of 4 dword sets */
	AZALIA_SUBVENDOR(0, 0x1b0a013f),
	AZALIA_PIN_CFG(0, 0x12, 0x411111f0),
	AZALIA_PIN_CFG(0, 0x14, 0x01014410),
	AZALIA_PIN_CFG(0, 0x15, 0x411111f0),
	AZALIA_PIN_CFG(0, 0x16, 0x411111f0),
	AZALIA_PIN_CFG(0, 0x18, 0x01a19c30),
	AZALIA_PIN_CFG(0, 0x19, 0x02a19931),
	AZALIA_PIN_CFG(0, 0x1a, 0x0181343f),
	AZALIA_PIN_CFG(0, 0x1b, 0x02214140),
	AZALIA_PIN_CFG(0, 0x1c, 0x411111f0),
	AZALIA_PIN_CFG(0, 0x1d, 0x4004c601),
	AZALIA_PIN_CFG(0, 0x1e, 0x01451120),

	0x80862805,	/* Codec Vendor / Device ID: Intel */
	0x80862805,	/* Subsystem ID */
	4,		/* Number of 4 dword sets */
	AZALIA_SUBVENDOR(3, 0x80862805),
	AZALIA_PIN_CFG(3, 0x05, 0x58560010),
	AZALIA_PIN_CFG(3, 0x06, 0x18560020),
	AZALIA_PIN_CFG(3, 0x07, 0x58560030),

};

const u32 pc_beep_verbs[0] = {};

AZALIA_ARRAY_SIZES;
