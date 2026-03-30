/** @type {import('tailwindcss').Config} */
export default {
  content: ['./index.html', './src/**/*.{js,jsx}'],
  theme: {
    extend: {
      colors: {
        honey: { 300: '#FFD54F', 400: '#FFC107', 500: '#FFB300', 600: '#FF8F00' },
        dark: { 900: '#0a0a0a', 800: '#111111', 700: '#1a1a1a', 600: '#222222' },
      },
      fontFamily: { sans: ['Inter', 'sans-serif'] },
      animation: {
        'fly-bee': 'flyBee 18s linear infinite',
        'fly-bee-2': 'flyBee2 24s linear infinite',
        'fly-bee-3': 'flyBee3 20s linear infinite',
        'drip': 'drip 3s ease-in-out infinite',
        'pulse-glow': 'pulseGlow 2s ease-in-out infinite',
        'float': 'float 4s ease-in-out infinite',
        'spin-slow': 'spin 8s linear infinite',
        'honeycomb-fade': 'honeycombFade 4s ease-in-out infinite',
      },
      keyframes: {
        flyBee: {
          '0%': { transform: 'translate(-100px, 60vh) rotate(0deg)', opacity: '0' },
          '10%': { opacity: '1' },
          '45%': { transform: 'translate(50vw, 20vh) rotate(15deg)' },
          '90%': { opacity: '1' },
          '100%': { transform: 'translate(110vw, 70vh) rotate(-10deg)', opacity: '0' },
        },
        flyBee2: {
          '0%': { transform: 'translate(-80px, 30vh) rotate(5deg)', opacity: '0' },
          '10%': { opacity: '1' },
          '50%': { transform: 'translate(60vw, 80vh) rotate(-20deg)' },
          '90%': { opacity: '1' },
          '100%': { transform: 'translate(110vw, 10vh) rotate(10deg)', opacity: '0' },
        },
        flyBee3: {
          '0%': { transform: 'translate(-60px, 80vh) rotate(-5deg)', opacity: '0' },
          '10%': { opacity: '1' },
          '55%': { transform: 'translate(40vw, 40vh) rotate(25deg)' },
          '90%': { opacity: '1' },
          '100%': { transform: 'translate(110vw, 50vh) rotate(-15deg)', opacity: '0' },
        },
        drip: {
          '0%, 100%': { transform: 'scaleY(0)', transformOrigin: 'top', opacity: '0' },
          '30%': { opacity: '1' },
          '70%': { transform: 'scaleY(1)', transformOrigin: 'top', opacity: '1' },
          '90%': { opacity: '0' },
        },
        pulseGlow: {
          '0%, 100%': { boxShadow: '0 0 5px #FFC107, 0 0 10px #FFC10733' },
          '50%': { boxShadow: '0 0 20px #FFC107, 0 0 40px #FFC10766' },
        },
        float: {
          '0%, 100%': { transform: 'translateY(0px)' },
          '50%': { transform: 'translateY(-12px)' },
        },
        honeycombFade: {
          '0%, 100%': { opacity: '0.03' },
          '50%': { opacity: '0.07' },
        },
      },
    },
  },
  plugins: [],
}
