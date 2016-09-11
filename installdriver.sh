#!/bin/bash

#install rapoo v500 driver

rmmod hid-rapoo rmmod hid_generic usbhid hid;
modprobe hid hid-rapoo hid_generic usbhid;
