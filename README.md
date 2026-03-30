🐝 BeeHale – Edge ML-based Beehive Health Monitoring System
📌 Silicon Labs Project

BeeHale is an Edge AI-powered beehive monitoring system that enables real-time, non-invasive analysis of hive health using acoustic signals, environmental sensing, and a modern interactive dashboard.

🚀 Overview

Beekeeping plays a crucial role in agriculture, but traditional hive monitoring relies on manual inspection, which is time-consuming, disruptive, and inefficient.

BeeHale solves this by:

Monitoring hive conditions using sound + sensors
Performing on-device (edge) inference
Providing real-time insights without internet
Visualizing data through an interactive dashboard

🎯 Key Features:

🔊 Acoustic-based hive monitoring
⚡ Real-time edge inference (no cloud required)
🔋 Low power consumption
🌐 Works offline (edge deployment)
☀️ Solar panel for self-generation
🌡️ Temperature & humidity monitoring (Si7021)
🌫️ Gas detection (MQ-2)
📊 Live data visualization via dashboard
🚨 Smart alert system

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

Results are displayed on VCOM console + Dashboard UI

🏗️ Hardware Components:

SiWx917 (Silicon Labs) – Edge processing unit
Microphone – Audio input
Si7021 Sensor – Temperature & humidity
MQ-2 Sensor – Gas detection
Power supply / battery

💻 Software Stack:

🔹 Edge AI System
Python (Model training & preprocessing)
TensorFlow Lite Micro (Edge inference)
Simplicity Studio (Firmware development)
Embedded C / C++

🌐 Dashboard (Frontend)
React 18 + Vite
TailwindCSS
Framer Motion
Recharts

📊 Performance:

✅ Accuracy: ~85–90%
⚡ Inference latency: ~20–50 ms
🔋 Optimized for low memory (INT8 model)
🌐 Dashboard (Frontend UI)

A modern, animated React-based dashboard to visualize hive data and system outputs.

▶️ Run Dashboard Locally
1️⃣ Install Node.js
Download from: https://nodejs.org
2️⃣ Install dependencies
npm install
3️⃣ Run development server
npm run dev

Open 👉 http://localhost:5173

📁 Project Structure
src/
├── components/
│   ├── Navbar.jsx
│   ├── Hero.jsx
│   ├── Features.jsx
│   ├── Dashboard.jsx
│   ├── Analytics.jsx
│   ├── Alerts.jsx
│   ├── About.jsx
│   ├── Architecture.jsx
│   ├── FlyingBees.jsx
│   └── Footer.jsx
├── hooks/
│   └── useHiveData.js
├── data/
│   └── mockData.js
├── App.jsx
└── index.css
🔗 API Integration

Replace mock data in:

src/hooks/useHiveData.js

Example:

const res = await fetch('/api/sensor-data')
const data = await res.json()
Expected Endpoints:
/api/hive-status
/api/sensor-data
/api/audio-analysis
/api/hive-weight
/api/alerts

📷 Demo:

Live classification output (QB present/absent)
Sensor readings via VCOM console
Dashboard visualization of hive data

💡 Use Case:

Real-time beehive monitoring
Early detection of hive stress
Reduced manual inspection
Improved honey production
Smart agriculture solution

🏆 Achievement:

🏅 Received ₹10,000 prototype funding from Silicon Labs

📌 Future Scope:

Wi-Fi connectivity & cloud integration
Mobile app for alerts
Advanced analytics & prediction
Multi-hive monitoring system
Solar-powered deployment ☀️

⭐ Support:- If you like this project, consider giving it a ⭐ on GitHub!
