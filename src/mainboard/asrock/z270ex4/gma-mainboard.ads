-- SPDX-License-Identifier: GPL-2.0-or-later

with HW.GFX.GMA;
with HW.GFX.GMA.Display_Probing;

use HW.GFX.GMA;
use HW.GFX.GMA.Display_Probing;

private package GMA.Mainboard is

	ports : constant Port_List :=
		(HDMI1, -- mainboard DVI port
		 HDMI2,
		 HDMI3, -- mainboard HDMI port
		 others => Disabled);

end GMA.Mainboard;
