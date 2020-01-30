
fastboot oem unlock
# fastboot erase system
# fastboot erase cache
# fastboot erase config
# fastboot erase logs
# fastboot erase factory
# fastboot erase userdata

fastboot flash boot_a boot.img
fastboot flash system_a system.img
fastboot flash system_b system_other.img
# fastboot flash vendor_b vendor.img
# fastboot flash userdata userdata.img

fastboot reboot
