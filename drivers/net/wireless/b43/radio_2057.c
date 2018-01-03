/*

  Broadcom B43 wireless driver
  IEEE 802.11n 2057 radio device data tables

  Copyright (c) 2010 Rafał Miłecki <zajec5@gmail.com>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; see the file COPYING.  If not, write to
  the Free Software Foundation, Inc., 51 Franklin Steet, Fifth Floor,
  Boston, MA 02110-1301, USA.

*/

#include "b43.h"
#include "radio_2057.h"
#include "phy_common.h"

static u16 r2057_rev4_init[42][2] = {
	{ 0x0E, 0x20 }, { 0x31, 0x00 }, { 0x32, 0x00 }, { 0x33, 0x00 },
	{ 0x35, 0x26 }, { 0x3C, 0xff }, { 0x3D, 0xff }, { 0x3E, 0xff },
	{ 0x3F, 0xff }, { 0x62, 0x33 }, { 0x8A, 0xf0 }, { 0x8B, 0x10 },
	{ 0x8C, 0xf0 }, { 0x91, 0x3f }, { 0x92, 0x36 }, { 0xA4, 0x8c },
	{ 0xA8, 0x55 }, { 0xAF, 0x01 }, { 0x10F, 0xf0 }, { 0x110, 0x10 },
	{ 0x111, 0xf0 }, { 0x116, 0x3f }, { 0x117, 0x36 }, { 0x129, 0x8c },
	{ 0x12D, 0x55 }, { 0x134, 0x01 }, { 0x15E, 0x00 }, { 0x15F, 0x00 },
	{ 0x160, 0x00 }, { 0x161, 0x00 }, { 0x162, 0x00 }, { 0x163, 0x00 },
	{ 0x169, 0x02 }, { 0x16A, 0x00 }, { 0x16B, 0x00 }, { 0x16C, 0x00 },
	{ 0x1A4, 0x00 }, { 0x1A5, 0x00 }, { 0x1A6, 0x00 }, { 0x1AA, 0x00 },
	{ 0x1AB, 0x00 }, { 0x1AC, 0x00 },
};

static u16 r2057_rev5_init[44][2] = {
	{ 0x00, 0x00 }, { 0x01, 0x57 }, { 0x02, 0x20 }, { 0x23, 0x6 },
	{ 0x31, 0x00 }, { 0x32, 0x00 }, { 0x33, 0x00 }, { 0x51, 0x70 },
	{ 0x59, 0x88 }, { 0x5C, 0x20 }, { 0x62, 0x33 }, { 0x63, 0x0f },
	{ 0x64, 0x0f }, { 0x81, 0x01 }, { 0x91, 0x3f }, { 0x92, 0x36 },
	{ 0xA1, 0x20 }, { 0xD6, 0x70 }, { 0xDE, 0x88 }, { 0xE1, 0x20 },
	{ 0xE8, 0x0f }, { 0xE9, 0x0f }, { 0x106, 0x01 }, { 0x116, 0x3f },
	{ 0x117, 0x36 }, { 0x126, 0x20 }, { 0x15E, 0x00 }, { 0x15F, 0x00 },
	{ 0x160, 0x00 }, { 0x161, 0x00 }, { 0x162, 0x00 }, { 0x163, 0x00 },
	{ 0x16A, 0x00 }, { 0x16B, 0x00 }, { 0x16C, 0x00 }, { 0x1A4, 0x00 },
	{ 0x1A5, 0x00 }, { 0x1A6, 0x00 }, { 0x1AA, 0x00 }, { 0x1AB, 0x00 },
	{ 0x1AC, 0x00 }, { 0x1B7, 0x0c }, { 0x1C1, 0x01 }, { 0x1C2, 0x80 },
};

static u16 r2057_rev5a_init[45][2] = {
	{ 0x00, 0x15 }, { 0x01, 0x57 }, { 0x02, 0x20 }, { 0x23, 0x6 },
	{ 0x31, 0x00 }, { 0x32, 0x00 }, { 0x33, 0x00 }, { 0x51, 0x70 },
	{ 0x59, 0x88 }, { 0x5C, 0x20 }, { 0x62, 0x33 }, { 0x63, 0x0f },
	{ 0x64, 0x0f }, { 0x81, 0x01 }, { 0x91, 0x3f }, { 0x92, 0x36 },
	{ 0xC9, 0x01 }, { 0xD6, 0x70 }, { 0xDE, 0x88 }, { 0xE1, 0x20 },
	{ 0xE8, 0x0f }, { 0xE9, 0x0f }, { 0x106, 0x01 }, { 0x116, 0x3f },
	{ 0x117, 0x36 }, { 0x126, 0x20 }, { 0x14E, 0x01 }, { 0x15E, 0x00 },
	{ 0x15F, 0x00 }, { 0x160, 0x00 }, { 0x161, 0x00 }, { 0x162, 0x00 },
	{ 0x163, 0x00 }, { 0x16A, 0x00 }, { 0x16B, 0x00 }, { 0x16C, 0x00 },
	{ 0x1A4, 0x00 }, { 0x1A5, 0x00 }, { 0x1A6, 0x00 }, { 0x1AA, 0x00 },
	{ 0x1AB, 0x00 }, { 0x1AC, 0x00 }, { 0x1B7, 0x0c }, { 0x1C1, 0x01 },
	{ 0x1C2, 0x80 },
};

static u16 r2057_rev7_init[54][2] = {
	{ 0x00, 0x00 }, { 0x01, 0x57 }, { 0x02, 0x20 }, { 0x31, 0x00 },
	{ 0x32, 0x00 }, { 0x33, 0x00 }, { 0x51, 0x70 }, { 0x59, 0x88 },
	{ 0x5C, 0x20 }, { 0x62, 0x33 }, { 0x63, 0x0f }, { 0x64, 0x13 },
	{ 0x66, 0xee }, { 0x6E, 0x58 }, { 0x75, 0x13 }, { 0x7B, 0x13 },
	{ 0x7C, 0x14 }, { 0x7D, 0xee }, { 0x81, 0x01 }, { 0x91, 0x3f },
	{ 0x92, 0x36 }, { 0xA1, 0x20 }, { 0xD6, 0x70 }, { 0xDE, 0x88 },
	{ 0xE1, 0x20 }, { 0xE8, 0x0f }, { 0xE9, 0x13 }, { 0xEB, 0xee },
	{ 0xF3, 0x58 }, { 0xFA, 0x13 }, { 0x100, 0x13 }, { 0x101, 0x14 },
	{ 0x102, 0xee }, { 0x106, 0x01 }, { 0x116, 0x3f }, { 0x117, 0x36 },
	{ 0x126, 0x20 }, { 0x15E, 0x00 }, { 0x15F, 0x00 }, { 0x160, 0x00 },
	{ 0x161, 0x00 }, { 0x162, 0x00 }, { 0x163, 0x00 }, { 0x16A, 0x00 },
	{ 0x16B, 0x00 }, { 0x16C, 0x00 }, { 0x1A4, 0x00 }, { 0x1A5, 0x00 },
	{ 0x1A6, 0x00 }, { 0x1AA, 0x00 }, { 0x1AB, 0x00 }, { 0x1AC, 0x00 },
	{ 0x1B7, 0x05 }, { 0x1C2, 0xa0 },
};

static u16 r2057_rev8_init[54][2] = {
	{ 0x00, 0x08 }, { 0x01, 0x57 }, { 0x02, 0x20 }, { 0x31, 0x00 },
	{ 0x32, 0x00 }, { 0x33, 0x00 }, { 0x51, 0x70 }, { 0x59, 0x88 },
	{ 0x5C, 0x20 }, { 0x62, 0x33 }, { 0x63, 0x0f }, { 0x64, 0x0f },
	{ 0x6E, 0x58 }, { 0x75, 0x13 }, { 0x7B, 0x13 }, { 0x7C, 0x0f },
	{ 0x7D, 0xee }, { 0x81, 0x01 }, { 0x91, 0x3f }, { 0x92, 0x36 },
	{ 0xA1, 0x20 }, { 0xC9, 0x01 }, { 0xD6, 0x70 }, { 0xDE, 0x88 },
	{ 0xE1, 0x20 }, { 0xE8, 0x0f }, { 0xE9, 0x0f }, { 0xF3, 0x58 },
	{ 0xFA, 0x13 }, { 0x100, 0x13 }, { 0x101, 0x0f }, { 0x102, 0xee },
	{ 0x106, 0x01 }, { 0x116, 0x3f }, { 0x117, 0x36 }, { 0x126, 0x20 },
	{ 0x14E, 0x01 }, { 0x15E, 0x00 }, { 0x15F, 0x00 }, { 0x160, 0x00 },
	{ 0x161, 0x00 }, { 0x162, 0x00 }, { 0x163, 0x00 }, { 0x16A, 0x00 },
	{ 0x16B, 0x00 }, { 0x16C, 0x00 }, { 0x1A4, 0x00 }, { 0x1A5, 0x00 },
	{ 0x1A6, 0x00 }, { 0x1AA, 0x00 }, { 0x1AB, 0x00 }, { 0x1AC, 0x00 },
	{ 0x1B7, 0x05 }, { 0x1C2, 0xa0 },
};

void r2057_upload_inittabs(struct b43_wldev *dev)
{
	struct b43_phy *phy = &dev->phy;
	u16 *table = NULL;
	u16 size, i;

	if (phy->rev == 7) {
		table = r2057_rev4_init[0];
		size = ARRAY_SIZE(r2057_rev4_init);
	} else if (phy->rev == 8 || phy->rev == 9) {
		if (phy->radio_rev == 5) {
			if (phy->radio_rev == 8) {
				table = r2057_rev5_init[0];
				size = ARRAY_SIZE(r2057_rev5_init);
			} else {
				table = r2057_rev5a_init[0];
				size = ARRAY_SIZE(r2057_rev5a_init);
			}
		} else if (phy->radio_rev == 7) {
			table = r2057_rev7_init[0];
			size = ARRAY_SIZE(r2057_rev7_init);
		} else if (phy->radio_rev == 9) {
			table = r2057_rev8_init[0];
			size = ARRAY_SIZE(r2057_rev8_init);
		}
	}

	if (table) {
		for (i = 0; i < 10; i++) {
			pr_info("radio_write 0x%X ", *table);
			table++;
			pr_info("0x%X\n", *table);
			table++;
		}
	}
}
