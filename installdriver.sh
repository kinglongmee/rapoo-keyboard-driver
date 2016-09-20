#!/bin/bash

#install rapoo v500 driver

rmmod hid-rapoo hid-generic
modprobe hid-rapoo
modprobe hid-generic
