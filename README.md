# rapoo-keyboard-driver

Some bugfix for rapoo keyboard where some keys are invalid.

# Quick Usage

Compile the driver module with make, make install and run ./install-rapoo-keyboard-driver.sh.

Job done! Then enjoy typing!

# Install in UEFI Security Mode

1. Generating key pairs with openssl and signing your kernel mod.

   ```bash
   openssl req -new -x509 -newkey rsa:2048 -keyout MOK.priv -outform DER -out MOK.der -nodes -days 36500 -subj "/CN=Rapoo-Keyboard/"
   ```

2. Import key.

   ```bash
   sudo mokutil --import MOK.der
   ```

3. Reboot system and enroll key.


4. Compile.

    ```bash
    make && sudo make install
    ```
    Now your mod is installed in `/lib/modules/$(uname -r)/kernel/drivers/hid/`

5. Sign mod.

   ```bash
   sudo kmodsign sha512 MOK.priv MOK.der /lib/modules/$(uname -r)/kernel/drivers/hid/hid-rapoo.ko
   ```

6. Insert mod.

   ```bash
   sudo insmod /lib/modules/$(uname -r)/kernel/drivers/hid/hid-rapoo.ko
   ```

7. Launch mod.

   ```bash
   sudo modprobe hid-rapoo 
   ```

8. Now you can use your keyboard.

9. DEBUG: print kernel logs

   ```bash
   dmesg
   ```

# Notice

After installing new kernel(contains compile and install kernel),
you must reinstall hid-rapoo module again by "make install".