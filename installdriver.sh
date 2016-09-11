#!/bin/bash

#install rapoo v500 driver

rmmod hid-rapoo hid_generic
modprobe hid-rapoo hid_generic
