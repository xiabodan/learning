@echo off

adb push find.sh /data/local/tmp/find.sh
adb shell chmod +x /data/local/tmp/find.sh
adb push busybox-a64 /data/local/tmp/busybox-a64
adb shell chmod +x /data/local/tmp/busybox-a64

adb shell ./data/local/tmp/find.sh

adb shell /data/local/tmp/busybox-a64 tar -czf /data/local/tmp/framework.tar.gz  /system/framework/  /data/local/tmp/app.tar.gz
adb pull /data/local/tmp/framework.tar.gz
pause
