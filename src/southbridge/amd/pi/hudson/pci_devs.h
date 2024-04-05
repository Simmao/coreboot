/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef _PI_HUDSON_PCI_DEVS_H_
#define _PI_HUDSON_PCI_DEVS_H_

#include <device/pci_def.h>

/* XHCI */
#define XHCI_DEV		0x10
#define XHCI_FUNC		0
#define XHCI_DEVFN		PCI_DEVFN(XHCI_DEV, XHCI_FUNC)

#define XHCI2_DEV		0x10
#define XHCI2_FUNC		1
#define XHCI2_DEVFN		PCI_DEVFN(XHCI2_DEV, XHCI2_FUNC)

/* SATA */
#define SATA_DEV		0x11
#define SATA_FUNC		0
#define SATA_IDE_DEVID		0x7800
#define AHCI_DEVID_MS		0x7801
#define AHCI_DEVID_AMD		0x7804
#define SATA_DEVFN		PCI_DEVFN(SATA_DEV, SATA_FUNC)

/* OHCI */
#define OHCI1_DEV		0x12
#define OHCI1_FUNC		0
#define OHCI2_DEV		0x13
#define OHCI2_FUNC		0
#define OHCI3_DEV		0x16
#define OHCI3_FUNC		0
#define OHCI4_DEV		0x14
#define OHCI4_FUNC		5
#define OHCI1_DEVFN		PCI_DEVFN(OHCI1_DEV, OHCI1_FUNC)
#define OHCI2_DEVFN		PCI_DEVFN(OHCI2_DEV, OHCI2_FUNC)
#define OHCI3_DEVFN		PCI_DEVFN(OHCI3_DEV, OHCI3_FUNC)
#define OHCI4_DEVFN		PCI_DEVFN(OHCI4_DEV, OHCI4_FUNC)

/* EHCI */
#define EHCI1_DEV		0x12
#define EHCI1_FUNC		2
#define EHCI2_DEV		0x13
#define EHCI2_FUNC		2
#define EHCI3_DEV		0x16
#define EHCI3_FUNC		2
#define EHCI1_DEVFN		PCI_DEVFN(EHCI1_DEV, EHCI1_FUNC)
#define EHCI2_DEVFN		PCI_DEVFN(EHCI2_DEV, EHCI2_FUNC)
#define EHCI3_DEVFN		PCI_DEVFN(EHCI3_DEV, EHCI3_FUNC)

/* SMBUS */
#define SMBUS_DEV		0x14
#define SMBUS_FUNC		0
#define SMBUS_DEVFN		PCI_DEVFN(SMBUS_DEV, SMBUS_FUNC)

/* HD Audio */
#define HDA_DEV			0x14
#define HDA_FUNC		2
#define HDA_DEVFN		PCI_DEVFN(HDA_DEV, HDA_FUNC)

/* LPC BUS */
#define PCU_DEV			0x14
#define LPC_DEV			PCU_DEV
#define LPC_FUNC		3
#define LPC_DEVFN		PCI_DEVFN(LPC_DEV, LPC_FUNC)

/* PCI Ports */
#define SB_PCI_PORT_DEV		0x14
#define SB_PCI_PORT_FUNC	4
#define SB_PCI_PORT_DEVFN	PCI_DEVFN(SB_PCI_PORT_DEV, SB_PCI_PORT_FUNC)

/* SD Controller */
#define SD_DEV			0x14
#define SD_FUNC			7
#define SD_DEVFN		PCI_DEVFN(SD_DEV, SD_FUNC)

#endif /* _PI_HUDSON_PCI_DEVS_H_ */
