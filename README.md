# Lets encrypt auto renew on EC2

Small program that allows a user to identify thresholds for monitoring load across any server. 


## Output
```

▄▄▌         ▄▄▄· ·▄▄▄▄       ▄▄·  ▄▄▄· ▄▄▌   ▄▄·
██•  ▪     ▐█ ▀█ ██▪ ██     ▐█ ▌▪▐█ ▀█ ██•  ▐█ ▌▪
██▪   ▄█▀▄ ▄█▀▀█ ▐█· ▐█▌    ██ ▄▄▄█▀▀█ ██▪  ██ ▄▄
▐█▌▐▌▐█▌.▐▌▐█ ▪▐▌██. ██     ▐███▌▐█ ▪▐▌▐█▌▐▌▐███▌
▐█▌▐▌▐█▌.▐▌▐█ ▪▐▌██. ██     ▐███▌▐█ ▪▐▌▐█▌▐▌▐███▌
.▀▀▀  ▀█▄▀▪ ▀  ▀ ▀▀▀▀▀•     ·▀▀▀  ▀  ▀ .▀▀▀ ·▀▀▀ 


Current Load average of this system is:
1.70 1.93 2.26 3/1054 12915

Total number of system cores is 4
#################################

System Load should alert with a warning for anything above 3.50 3.40 3.30
System Load should alert with a critical for anything above 3.80


```


## build

```
gcc -o load_alert load_alert.c
```
