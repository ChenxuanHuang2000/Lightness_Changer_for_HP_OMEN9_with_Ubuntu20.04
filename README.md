# Lightness_Changer_for_HP_OMEN9_with_Ubuntu20.04
This script is written because the shortcut FN+F2/FN+F3 for HP OMEN9 screen brightness adjustment under HP OMEN20.04 is invalid, and this failure may be caused by the optimization of ubuntu20.04 system for Mac. The script works by using the built-in keyboard shortcut function of the Ubuntu system to adjust the screen brightness. The instructions for use are as follows:
1. Gitclone，and compile it with g++.
2. Set r & w permissions for the screen brightness file with the following:
   # sudo chmod 666 /sys/class/backlight/nvidia_wmi_ec_backlight/brightness
4. Set the startup shortcut keys for the two executable files formed after compilation in System Settings-Keyboard-Hotkeys, you can refer to my own settings:
   For darker:
   Alt+F2 
   /home/usrname/screen_brigntness_hotkey/brightness_down.out
   For brighter:
   Alt+F3
   /home/usrname/screen_brigntness_hotkey/brightness_up.out
5. Adjust the brightness for your screen with Hotkeys.

# Warning and Disclaimer: 
Using this script requires the modification of the read/write permission of the screen brightness file in the /sys directory, and the use of this script means that you are aware of and voluntarily bear any risks and consequences arising therefrom.
