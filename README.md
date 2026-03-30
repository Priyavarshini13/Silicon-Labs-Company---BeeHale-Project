# Silicon-Labs-Company---BeeHale-Project
Edge ML-based Beehive Health Monitoring System

**🐝 BeeHale – Edge ML-based Beehive Health Monitoring System
📌 Silicon Labs Project**

BeeHale is an Edge AI-powered beehive monitoring system that enables real-time, non-invasive analysis of hive health using acoustic signals and environmental sensing.

🚀 Overview:

Beekeeping plays a crucial role in agriculture, but traditional hive monitoring relies on manual inspection, which is time-consuming and disruptive.

BeeHale solves this by:

Monitoring hive conditions using sound + sensors
Performing on-device (edge) inference
Providing real-time insights without internet

🎯 Key Features:

🔊 Acoustic-based hive monitoring
⚡ Real-time edge inference (no cloud required)
🔋 Low power consumption
🌐 Works offline (edge deployment)
🌡️ Temperature & humidity monitoring (Si7021)
🌫️ Gas detection (MQ-2)
📊 Live output via VCOM console

🧠 How It Works:

Microphone captures beehive audio
Audio is converted into 1-second segments
Features extracted:
RMS Energy
Zero Crossing Rate (ZCR)
MFCC
Machine Learning model processes data

Output classification:
C1: Low activity
C2: Normal activity
C3: High / stressed activity

🏗️ Hardware Components:

SiWx917 (Silicon Labs) – Edge processing unit
Microphone – Audio input
Si7021 Sensor – Temperature & humidity
MQ-2 Sensor – Gas detection
Power supply / battery

💻 Software Stack:

Python (Model training & preprocessing)
TensorFlow Lite Micro (Edge inference)
Simplicity Studio (Firmware development)
Embedded C / C++

📊 Performance:

✅ Accuracy: ~85–90%
⚡ Inference latency: ~20–50 ms
🔋 Low memory footprint (INT8 model)
🔧 Setup & Deployment

1️⃣ Clone the Repository
git clone https://github.com/your-username/beehale.git
2️⃣ Model Preparation
Train model using Python scripts
Convert to INT8 TFLite model
3️⃣ Deployment
Import project into Simplicity Studio
Replace model in /tflite/ folder
Build and flash to SiWx917
4️⃣ Run
Open VCOM console
View real-time output

📷 Demo:

Live classification output (QB present/absent)
Sensor readings displayed in console

💡 Use Case:

Real-time beehive monitoring
Early detection of hive stress
Reduces manual inspection
Improves honey production

🏆 Achievement:

🏅 Received ₹10,000 prototype funding from Silicon Labs for this project.

📌 Future Scope:

Wi-Fi connectivity & cloud dashboard
Mobile app for alerts
Advanced analytics & prediction
Multi-hive monitoring system
