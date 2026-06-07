# 🐝 BeeHale – Edge AI Based Beehive Health Monitoring System

> **Listening to the Hive, Protecting the Future of Agriculture**

## 📌 Overview

BeeHale is an Edge AI-powered beehive health monitoring system developed on the Silicon Labs SiWG917 platform. The system continuously monitors hive health using bee acoustic signals and environmental sensing without disturbing the bees.

By combining machine learning, embedded systems, and sensor data, BeeHale enables real-time detection of abnormal hive conditions directly on the device without requiring cloud connectivity. The solution supports sustainable beekeeping, precision agriculture, and early detection of hive stress.

---

## 🚀 Problem Statement

Beekeeping plays a vital role in agriculture through pollination, but traditional hive monitoring relies on manual inspections that are:

* Time-consuming
* Labor-intensive
* Stressful to bee colonies
* Unable to provide continuous monitoring

BeeHale addresses these challenges through non-invasive, real-time monitoring using Edge AI and sensor fusion.

---

## 🎯 Key Features

* 🔊 Acoustic-based hive monitoring
* 🧠 Edge AI inference on-device
* ⚡ Real-time anomaly detection
* 🌡️ Temperature & humidity monitoring
* 🌫️ Gas level monitoring
* 🌐 Fully offline operation
* 📊 Interactive dashboard visualization
* 🚨 Early warning and alert generation
* 🔋 Low-power embedded deployment
* ☀️ Future-ready for solar-powered operation

---

## 🌾 Use Case

BeeHale is designed for:

* Commercial beekeepers
* Small-scale beekeepers
* Agricultural researchers
* Universities and research institutions
* Precision agriculture applications

The system helps detect hive abnormalities early, reducing colony losses and improving pollination efficiency.

---

## 🧠 Machine Learning Details

### Model Type

* CNN (Convolutional Neural Network)

### Input Data

* Bee acoustic signals (.wav files)

### Feature Extraction

* MFCC (Mel Frequency Cepstral Coefficients)
* RMS Energy
* Zero Crossing Rate (ZCR)

### Training Framework

* Python
* TensorFlow

### Optimization

* INT8 Quantization
* TensorFlow Lite Micro Deployment

### Output Classes

* C1 – Low Activity
* C2 – Normal Activity
* C3 – High / Stressed Activity

---

## ⚙️ How It Works

### Step 1: Audio Acquisition

A microphone continuously captures bee sounds from the hive.

### Step 2: Audio Processing

Audio is divided into 1-second segments.

### Step 3: Feature Extraction

MFCC, RMS, and ZCR features are extracted from the audio.

### Step 4: Edge AI Inference

The TensorFlow Lite Micro model performs real-time classification directly on the SiWG917.

### Step 5: Environmental Monitoring

Additional sensor data is collected from:

* Temperature sensor
* Humidity sensor
* Gas sensor

### Step 6: Output Generation

Results are displayed through:

* VCOM Console
* Dashboard Interface

---

## 🏗️ Hardware Used

### Silicon Labs Platform

* SiWG917 Wi-Fi 6 + BLE MCU

### Sensors

* Microphone Module
* SI7021 Temperature & Humidity Sensor
* MQ-2 Gas Sensor
* RF Communication Module

### Power System

* Battery / External Power Supply

---

## 💻 Software Used

### Edge AI Development

* Python
* TensorFlow
* TensorFlow Lite Micro
* Simplicity Studio
* Simplicity SDK
* Embedded C/C++

### Dashboard Development

* React 18
* Vite
* Tailwind CSS
* Framer Motion
* Recharts

---

## 📊 Performance

| Metric            | Value             |
| ----------------- | ----------------- |
| Accuracy          | 85–90%            |
| Inference Latency | 20–50 ms          |
| Deployment        | Edge Device       |
| Quantization      | INT8              |
| Connectivity      | Offline Supported |

---

## 🌐 Dashboard

The BeeHale Dashboard provides:

* Hive Activity Status
* Temperature Monitoring
* Humidity Monitoring
* Gas Monitoring
* Alert Notifications
* Analytics Visualization

The dashboard is built using React and provides a modern interface for monitoring hive conditions.

---

## ▶️ Running the Dashboard

### Install Node.js

Download:
https://nodejs.org

### Install Dependencies

```bash
npm install
```

### Start Development Server

```bash
npm run dev
```

Open:

```text
http://localhost:5173
```

---

## 📁 Project Structure

```text
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
```

---

## 🔗 API Integration

Replace mock data inside:

```text
src/hooks/useHiveData.js
```

Example:

```javascript
const res = await fetch('/api/sensor-data')
const data = await res.json()
```

Expected APIs:

```text
/api/hive-status
/api/sensor-data
/api/audio-analysis
/api/hive-weight
/api/alerts
```

---

## 🎥 Demo Video

Real-time demonstration of BeeHale:

https://drive.google.com/file/d/1bOJbrjWIn-V6KN6KXmXyCaCnTuVHnaMf/view?usp=drive_link

### Demonstrated Features

* Queen Bee Detection
* Acoustic Classification
* Temperature Monitoring
* Humidity Monitoring
* Gas Monitoring
* Edge AI Inference
* Dashboard Visualization

---

## 📊 Dataset

Bee Audio Dataset:

https://drive.google.com/file/d/1GqWX5Ds9rGky8JEO-Evcs3ukNrUnrnTc/view

---

## 🏆 Achievement

🥈 Second Runner-Up – Silicon Labs Edge Intelligence Challenge 2026

💰 Received ₹10,000 Prototype Funding from Silicon Labs

📍 Grand Finale conducted at T-Hub, Government of Telangana

---

## 📈 Future Scope

* Wi-Fi Connectivity
* Cloud Integration
* Mobile Application
* Multi-Hive Monitoring
* Predictive Analytics
* Advanced Anomaly Detection
* Solar-Powered Deployment

---

## 👥 Team

### Priyavarshini V

* AI Model Development
* TensorFlow Training
* Feature Engineering
* System Integration

### Hariharan

* Embedded Systems Development
* Firmware Integration
* Sensor Interfacing
* SiWG917 Deployment

### Anushya

* Dataset Collection
* Testing & Validation
* Documentation
* Field Evaluation

---

## 🙏 Acknowledgement

We sincerely thank Silicon Labs, Sri Eshwar College of Engineering, and the Center of Excellence on Embedded Systems for providing guidance, resources, and hands-on training that enabled the successful development of BeeHale.

---

## ⭐ Support

If you like this project, consider giving it a ⭐ on GitHub and sharing it with the embedded systems and Edge AI community.

**BeeHale – Listening to the Hive, Protecting the Future of Agriculture.** 🐝🌱
