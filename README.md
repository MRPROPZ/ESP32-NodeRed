# แลปเกี่ยวกับการสื่อสารผ่านโพรโทคอล MQTT

**อุปกรณ์ที่ใช้**: Raspberry pi 400 เครื่อง 02\
**SSID**: UMR-LAB_02\
**Password**: Ubon2565\
**user of rpi**: pi\
**password of rpi**: raspberry\
**IP raspberry pi**: 192.168.1.202\
**Gateway raspberry pi**: 192.168.1.1\
**DNS server**: 8.8.8.8

## วิธีการติดตั้ง

1. ดาวน์โหลด Raspberry PI OS with desktop v.5.10 [ติดตั้ง](https://www.raspberrypi.com/software/operating-systems/ )
2. ทำการแตกไฟล์ zip ด้วยโปรแกรม Winrar จะได้ไฟล์นามสกุล .iso
3. ดาวน์โหลดโปรแกรม BelenaEtcher สำหรับใช้ flash ไฟล์ลง micro sd [ติดตั้ง](https://www.balena.io/etcher)
4. หลังจากติดตั้งเสร็จ ให้เลือก select image เป็นชื่อไฟล์.iso และ select drive เป็น micro sd จากนั้นคลิก ***Flash!***
5. รอจนกว่า Flash Complete! (หมายเหตุ: ถ้าไม่ขึ้น Flash Complete! ให้ทำใหม่)
6. เสียบ micro sd เข้าเครื่องคอม
7. เข้าไปที่ this pc > micro sd drive > config > แก้ hdmi safe > ลบ # ออกข้างหน้า hdmi_safe = 1
8. บันทึกและลองเอาไปเสียบที่ raspberry pi 400 ดู

## การสั่งงาน RPi ผ่านเครือข่าย

```c
# update time, software, version
sudo date -s 'ปี-เดือน-วัน ชั่วโมง:นาที:วินาที'
sudo apt-get update
sudo apt-get install

# test ssh 
ssh pi@ไอพี
```
## ติดตั้ง Node-Red
1. ตอบ yes, yes, no

```bash
bash <(curl -sL https://raw.githubusercontent.com/node-red/linux-installers/master/deb/update-nodejs-and-nodered)
sudo systemctl enable nodered.service
reboot
```

## ทดสอบ Node-Red

```c
http://localhost:1880
// เช็ค ip ifconfig

```

## ติดตั้ง Node-Red Dashboard

```bash
node-red-stop
cd .node-red
npm install node-red-dashboard
reboot

```

## ทดสอบ Node-Red Dashboard

```c
http://192.168.1.202:1880/ui
// เช็ค ip ifconfig

```

## ติดตั้ง MQTT Server

```c
sudo apt install -y  mosquitto mosquitto-clients
sudo systemctl enable mosquitto.service
mosquitto -v

```

## ติดตั้ง MQTTLens
1. ใช้ browser chrome **เท่านั้น!** [ติดตั้ง](https://www.google.com/chrome/)
2. โหลด extension MQTTLens [ติดตั้ง](https://chrome.google.com/webstore/detail/mqttlens/hemojaaeigabkbcookmlgmdigohjobjm?hl=th)
3. ตั้งค่าตามนี้\
Connection name: PubSubclient\
Hostname: tcp://192.168.1.202\
Port: 1883
4. SAVE CHANGES
5. ถ้าขึ้นสีเขียวแปลว่าใช้งานได้

## ทดสอบการทำงานของ MQTT Lens
1. Subscribe ตั้งเป็น test
2. Publish ตั้งเป็น test
3. Message ตั้งเป็น Hello
4. กดปุ่ม SUBSCRIBE และ PUBLISH 
5. สังเกตจะต้องขึ้นข้อความตอบกลับมาว่า Hello

## การใช้งานโพรโทคอล MQTT บน ESP32
1. ติดตั้ง Library > PubSubClient by Nick O'Leary Version 2.7.0 ใน Arduino IDE
2. คัดลอกโค้ดจากไฟล์ ESP32-Nodered มารัน

## License

[MIT](https://choosealicense.com/licenses/mit/)
