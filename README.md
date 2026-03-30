# 🐝 BeeHale – Smart Beehive Monitoring System

A modern, animated React frontend for an Edge AI–based IoT beehive health monitoring system.

## Quick Start

### 1. Install Node.js
Download from https://nodejs.org (LTS version recommended)

### 2. Install dependencies
```bash
npm install
```

### 3. Run development server
```bash
npm run dev
```

Open http://localhost:5173 in your browser.

## Project Structure

```
src/
├── components/
│   ├── Navbar.jsx          # Sticky navbar with active section tracking
│   ├── Hero.jsx            # Landing page with honey drip + CTA buttons
│   ├── Features.jsx        # Animated feature cards (6 system capabilities)
│   ├── Dashboard.jsx       # Live sensor gauges + AI confidence + status
│   ├── Analytics.jsx       # Historical charts (temp, humidity, weight, audio)
│   ├── Alerts.jsx          # Alert cards with glow animations
│   ├── About.jsx           # Problem/solution + colony collapse stats
│   ├── Architecture.jsx    # System flow diagram + tech stack
│   ├── FlyingBees.jsx      # Animated bees flying across screen
│   └── Footer.jsx          # Footer with links
├── hooks/
│   └── useHiveData.js      # API hooks (simulated): useHiveData, useHistoricalData
├── data/
│   └── mockData.js         # Mock sensor data + feature/alert definitions
├── App.jsx                 # Root: loading screen, bee cursor, section tracking
└── index.css               # Global styles, glassmorphism, honeycomb bg
```

## API Integration

Replace mock data in `src/hooks/useHiveData.js` with real fetch calls:

```js
// Example: replace generateSensorData() with:
const res = await fetch('/api/sensor-data')
const data = await res.json()
```

Endpoints expected:
- `GET /api/hive-status`
- `GET /api/sensor-data`
- `GET /api/audio-analysis`
- `GET /api/hive-weight`
- `GET /api/alerts`

## Tech Stack
- React 18 + Vite 5
- TailwindCSS 3
- Framer Motion 11
- Recharts 2
