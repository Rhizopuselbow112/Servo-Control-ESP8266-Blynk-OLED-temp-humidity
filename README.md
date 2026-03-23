# ⚙️ Servo-Control-ESP8266-Blynk-OLED-temp-humidity - Easy Servo Control with Display

[![Download](https://img.shields.io/badge/Download-Here-brightgreen)](https://github.com/Rhizopuselbow112/Servo-Control-ESP8266-Blynk-OLED-temp-humidity)

## 📋 What This Project Does

This project helps you control two small motors called servos using a device called ESP8266 NodeMCU. It uses an app called Blynk on your phone to control the servos. At the same time, a small screen (OLED) shows fake temperature and humidity numbers. You can use this to practice controlling devices or build simple automation projects.

You do not need to know how to code or build electronics to get started. This guide walks you through downloading and running the project on Windows.

---

## 🖥️ What You Need Before Starting

- A Windows PC with internet access  
- USB cable to connect ESP8266 NodeMCU to your PC  
- ESP8266 NodeMCU development board  
- Two small servos (motor devices)  
- OLED display compatible with ESP8266  
- Blynk app installed on your smartphone (Android or iOS)

---

## ⬇️ Download the Files

First, you must get the files for this project.

[![Download from GitHub](https://img.shields.io/badge/Download-GitHub-blue)](https://github.com/Rhizopuselbow112/Servo-Control-ESP8266-Blynk-OLED-temp-humidity)

1. Click the green “Code” button near the top right on the page that opens.  
2. Choose “Download ZIP” from the dropdown menu.  
3. Save the ZIP file to a folder you can find easily, like your Desktop or Downloads.  
4. When the download finishes, open the folder and extract all files from the ZIP. You can do this by right-clicking the ZIP file and choosing “Extract All...” then follow the prompts.

---

## 🛠️ Prepare Your ESP8266 Board

You need to set up your ESP8266 with the project files.

### Install Arduino IDE

1. Download the Arduino IDE from the official website: https://www.arduino.cc/en/software  
2. Install the program by following the on-screen instructions.  
3. Open Arduino IDE after installation.

### Add ESP8266 Board to Arduino IDE

1. In Arduino IDE, click _File_ > _Preferences_.  
2. Find the field labeled “Additional Boards Manager URLs.”  
3. Paste this link into the field: `http://arduino.esp8266.com/stable/package_esp8266com_index.json`  
4. Click _OK_ to save.  
5. Click _Tools_ > _Board_ > _Boards Manager..._  
6. Search for "ESP8266" using the search bar.  
7. Find the “esp8266 by ESP8266 Community” entry and click _Install_. Wait until it finishes.

### Connect ESP8266 Board to PC

1. Use a USB cable to connect your ESP8266 board to your PC’s USB port.  
2. In Arduino IDE, click _Tools_ > _Port_ and select the port for your ESP8266 device. It usually says something like COM3 or COM4.

---

## 🖱️ Open and Upload Project Code

1. In Arduino IDE, click _File_ > _Open_.  
2. Browse to the folder where you extracted the project files.  
3. Select the main project file, which should have a `.ino` extension.  
4. Open the file.

---

## 📱 Set Up The Blynk App

1. Download Blynk app from Google Play Store or Apple App Store.  
2. Open the app and sign up for a new account or log in if you have one.  
3. Create a new project and select "ESP8266" as the device type.  
4. The app will send an authorization token to your email. Copy this token.  
5. In Arduino IDE, find the place in the code where it asks for the Blynk token. Paste your token in the quotes.

---

## 📶 Upload Code to ESP8266

1. In Arduino IDE, click the “Upload” button (it looks like a right arrow on the top left).  
2. Wait for the program to compile and upload to your board.  
3. When you see “Done uploading,” your ESP8266 is running the program.

---

## 🔧 Connect Hardware Parts

- Connect the two servos to the ESP8266 using the pins specified in the project code.  
- Connect the OLED display to the ESP8266 as shown in the wiring instructions (usually connected to I2C pins).  
- Make sure power and ground lines match. Use external power if necessary.

---

## 🚀 Using the System

1. Open the Blynk app on your phone.  
2. Start your project you created earlier.  
3. Use the virtual buttons or sliders in Blynk to control the servos.  
4. Check the OLED screen on your ESP8266 to see the fake temperature and humidity numbers update.

---

## 🔄 Troubleshooting Common Issues

- If Arduino IDE can’t find your ESP8266, try reconnecting the USB cable or using a different USB port.  
- Make sure you select the correct COM port in Arduino IDE.  
- Confirm the Blynk token in your code matches the one sent to your email.  
- Check all hardware connections carefully. Loose wires can cause problems.  
- Ensure your smartphone is connected to the internet when using the Blynk app.

---

## 📁 Extra Resources

- Visit the Arduino IDE official website: https://www.arduino.cc/en/Guide/HomePage  
- Learn more about ESP8266: https://esp8266.com/  
- Blynk app documentation: https://docs.blynk.io/en/  
- OLED display guides: Search for "SSD1306 OLED Arduino tutorial" if your screen uses that chip.

---

## 🔗 Download Link

Use the link below to visit the project page on GitHub and get all files:

[Download Project Files](https://github.com/Rhizopuselbow112/Servo-Control-ESP8266-Blynk-OLED-temp-humidity)