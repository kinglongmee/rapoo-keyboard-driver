# rapoo-keyboard-driver

Some bugfix for rapoo keyboard where some keys are invalid.

# Quick Usage

Compile the driver module with make, make install and run ./install-rapoo-keyboard-driver.sh.

Job done! Then enjoy typing!

# Install in UEFI Security Mode

1. Compile.

   ```bash
   make && sudo make install
   ```

2. Generating key pairs with openssl and signing your kernel mod.

   ```bash
   openssl req -new -x509 -newkey rsa:2048 -keyout MOK.priv -outform DER -out MOK.der -nodes -days 36500 -subj "/CN=Rapoo-Keyboard/"
   ```

3. Import key.

   ```bash
   sudo mokutil --import MOK.der
   ```

4. Reboot system and enroll key.

5. Insert mod.

   ```bash
   sudo insmod ./hid-rapoo.ko
   ```

6. Launch mod.

   ```bash
   sudo modprobe hid-rapoo 
   ```

7. Now you can use your keyboard.

8. DEBUG: print kernel logs

   ```bash
   dmesg
   ```

# Notice

After installing new kernel(contains compile and install kernel),
you must reinstall hid-rapoo module again by "make install".