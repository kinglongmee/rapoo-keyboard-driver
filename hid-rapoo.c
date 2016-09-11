/*
 *  HID driver for rapoo v500 Keyboard
 *
 *  Copyright (c) 2016 Kinglong Mee < kinglongmee@gmail.com >
 */

/*
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 */

#include <linux/device.h>
#include <linux/hid.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/usb.h>

#define DEBUG_RAPOO

#define USB_VENDOR_ID_RAPOO		0x1c4f
#define USB_DEVICE_ID_RAPOO_V500	0x0059

static const struct hid_device_id hid_rapoo_devices[] = {
	{ HID_USB_DEVICE(USB_VENDOR_ID_RAPOO, USB_DEVICE_ID_RAPOO_V500) },
	{ }
};
MODULE_DEVICE_TABLE(hid, hid_rapoo_devices);

static int hid_rapoo_raw_event(struct hid_device *hdev, struct hid_report *report,
				u8 *data, int size)
{
	struct hid_field *field;
	int a = 0;

	if (hdev->claimed != HID_CLAIMED_HIDRAW && report->maxfield) {
		for (a = 0; a < report->maxfield; a++) {
			field = report->field[a];
			field->flags |= HID_MAIN_ITEM_VARIABLE;
		}
	}

	return 0;
}

static struct hid_driver hid_rapoo_driver = {
	.name = "hid_rapoo",
	.id_table = hid_rapoo_devices,
	.raw_event = hid_rapoo_raw_event,
};

static int __init hid_rapoo_init(void)
{
#ifdef DEBUG_RAPOO
	printk(KERN_INFO "hid-rapoo: RAPOO USB HID driver\n");
#endif
	return hid_register_driver(&hid_rapoo_driver);
}

static void __exit hid_rapoo_exit(void)
{
	hid_unregister_driver(&hid_rapoo_driver);
}

module_init(hid_rapoo_init);
module_exit(hid_rapoo_exit);
MODULE_LICENSE("GPL");

