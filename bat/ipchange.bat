@echo off 
title IP_CHANGE 
mode con cols=80 lines=20 
color 1F 

:MENU 
cls 
echo. 
echo               1. wire-DHCP 
echo               2. wire-�Ǳ� DNS(164.124.107.9) 
echo               3. wire-�λ� DNS(192.168.137.1)
echo               4. wire-AGV
echo               5. LGIT-AGV
echo               6. wifi-DHCP
echo               0. exit 
echo. 
set /p num=���ϴ� �׸��� ��ȣ�� �Է����ּ��� :  
if "%num%"=="1" goto DHCP 
if "%num%"=="2" goto LOCATION_1 
if "%num%"=="3" goto LOCATION_2 
if "%num%"=="4" goto LOCATION_3 
if "%num%"=="5" goto LOCATION_4 
if "%num%"=="6" goto WDHCP
if "%num%"=="0" goto EXIT 
goto MENU 


:DHCP 
netsh -c int ip set address name="�̴���" source=dhcp 
netsh -c int ip set dns name="�̴���' source=dhcp 
goto SUCCESS1 


:WDHCP 
netsh -c int ip set address name="Wi-fi" source=dhcp 
netsh -c int ip set dns name="Wi-fi' source=dhcp 
goto SUCCESS1 


:LOCATION_1 
netsh -c int ip set address name="�̴��� 3" source=static addr=172.16.1.149 mask=255.255.255.0 gateway=172.16.1.1 gwmetric=0 
netsh -c int ip set dns name="�̴��� 3" source=static addr=164.124.107.9 register=PRIMARY 
netsh -c int ip add dns name="�̴��� 3" 203.248.242.2 index=2 
goto SUCCESS2 

:LOCATION_2 
netsh -c int ip set address name="�̴��� 3" source=static addr=192.168.137.123 mask=255.255.255.0 gateway=192.168.137.1 gwmetric=0 
netsh -c int ip set dns name="�̴��� 3" source=static addr=192.168.137.1 register=PRIMARY 
goto SUCCESS3 

:LOCATION_3 
netsh -c int ip set address name="�̴��� 3" source=static addr=192.168.192.60 mask=255.255.255.0  
goto SUCCESS4 

:LOCATION_4 
netsh -c int ip set address name="Wi-fi" source=static addr=192.168.192.160 mask=255.255.255.0 
goto SUCCESS5 



:EXIT 
exit 

:SUCCESS1 
cls 
echo. 
echo. 
echo. 
echo    DHCP �Ҵ� �Ϸ�!! 
echo. 
echo. 
echo. 
pause > nul 
goto EXIT 

:SUCCESS2 
cls 
echo. 
echo. 
echo. 
echo    ��ġ1 DNS �Ҵ� �Ϸ�!! 
echo. 
echo. 
echo. 
pause > nul 
goto EXIT 

:SUCCESS3 
cls 
echo. 
echo. 
echo. 
echo    ��ġ2 DNS �Ҵ� �Ϸ�!! 
echo. 
echo. 
echo. 
pause > nul 
goto EXIT 

:SUCCESS4 
cls 
echo. 
echo. 
echo. 
echo    ��ġ3 IP �Ҵ� �Ϸ�!! 
echo. 
echo. 
echo. 
pause > nul 
goto EXIT

:SUCCESS5 
cls 
echo. 
echo. 
echo. 
echo    ��ġ3 IP �Ҵ� �Ϸ�!! 
echo. 
echo. 
echo. 
pause > nul 
goto EXIT