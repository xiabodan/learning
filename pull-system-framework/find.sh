#!/bin/sh
#!/system/xbin
#!/system/bin

hwid=`pm path com.huawei.hwid | awk -F '/' '{print $4}'`
gms=`pm path com.google.android.gms | awk -F '/' '{print $4}'`
gsf=`pm path com.google.android.gsf | awk -F '/' '{print $4}'`
login=`pm path com.google.android.gsf.login | awk -F '/' '{print $4}'`
backuptransport=`pm path com.google.android.backuptransport | awk -F '/' '{print $4}'`
backup=`pm path com.google.android.backup | awk -F '/' '{print $4}'`
policy_sidecar_o=`pm path com.google.android.gms.policy_sidecar_o | awk -F '/' '{print $4}'`
instantapps=`pm path com.google.android.instantapps.supervisor | awk -F '/' '{print $4}'`
echo $hwid
echo $gms
echo $gsf
echo $login
echo $backuptransport
echo $backup
echo $policy_sidecar_o
echo $instantapps
r=`/data/local/tmp/busybox-a64 tar -czf /data/local/tmp/app.tar.gz /data/app/$hwid/ /data/app/$gms /data/app/$gsf /data/app/$login /data/app/$backuptransport /data/app/$backup /data/app/$policy_sidecar_o /data/app/$instantapps/`
