# Smart Home Energy Monitoring System using ESP32, Wokwi & ThingSpeak

An IoT-based Smart Home Energy Monitoring System developed using ESP32, Wokwi, and ThingSpeak to monitor real-time electricity consumption. The system calculates voltage, current, power, energy usage, and estimated electricity cost while providing smart alerts through LEDs and a buzzer for different energy consumption levels. Real-time data is visualized on a ThingSpeak cloud dashboard with live graphs for efficient energy management and smart home automation.

---

# 📌 Project Overview

The **Smart Home Energy Monitoring System** is an IoT-based solution designed to monitor household electricity consumption in real time using **ESP32**, **Wokwi Simulation**, and **ThingSpeak Cloud**.

The system continuously monitors:

* ⚡ Voltage
* 🔌 Current
* 📊 Power Consumption
* 💡 Energy Usage (kWh)
* 💰 Estimated Electricity Cost
* 🚨 Energy Alert Status

The system helps users monitor energy consumption and reduce electricity wastage through cloud monitoring and smart alerts.

---

# 🚀 Features

✅ Real-Time Energy Monitoring
✅ Voltage, Current & Power Calculation
✅ Energy Consumption Tracking (kWh)
✅ Estimated Electricity Cost Calculation
✅ Smart LED Alert System
✅ Buzzer Alert for High Energy Usage
✅ ThingSpeak Cloud Dashboard Integration
✅ Live Graph Monitoring
✅ Wokwi Simulation Support
✅ ESP32 IoT-Based Implementation

---

# 🛠️ Technologies Used

| Technology            | Purpose                 |
| --------------------- | ----------------------- |
| ESP32                 | Microcontroller         |
| Wokwi                 | Circuit Simulation      |
| ThingSpeak            | Cloud Dashboard         |
| Arduino IDE / VS Code | Development Environment |
| GitHub                | Version Control         |

---

# ⚙️ Hardware Components

* ESP32 Development Board
* Potentiometer
* Green LED
* Yellow LED
* Red LED
* Buzzer
* 220Ω Resistors
* Jumper Wires

---

# 🏗️ Project Workflow

```text
Wokwi Simulation
        ↓
ESP32 Data Processing
        ↓
Energy Calculation
        ↓
Alert Generation
        ↓
ThingSpeak Cloud
        ↓
Real-Time Dashboard Visualization
```

---

# 🔌 Circuit Connections

## LED Connections

| Component  | GPIO Pin |
| ---------- | -------- |
| Green LED  | GPIO23   |
| Yellow LED | GPIO22   |
| Red LED    | GPIO21   |

### Buzzer Connection

| Component | GPIO Pin |
| --------- | -------- |
| Buzzer    | GPIO19   |

### Potentiometer Connection

| Potentiometer Pin | ESP32 Pin |
| ----------------- | --------- |
| VCC               | 3.3V      |
| GND               | GND       |
| SIG               | GPIO35    |

---

# ⚡ Working Principle

The potentiometer acts as a simulated current sensor in the Wokwi environment. The ESP32 continuously reads analog values and converts them into current readings.

### Power Formula

```text
Power = Voltage × Current
```

### Alert Logic

🟢 **0W – 500W** → Normal Usage

🟡 **500W – 1500W** → Moderate Usage

🔴 **Above 1500W** → High Energy Alert + Buzzer

The ESP32 uploads sensor data to **ThingSpeak every 15 seconds** for real-time monitoring.

---

# 📊 ThingSpeak Fields

| Field   | Parameter    |
| ------- | ------------ |
| Field 1 | Voltage      |
| Field 2 | Current      |
| Field 3 | Power        |
| Field 4 | Energy       |
| Field 5 | Cost         |
| Field 6 | Alert Status |

---

# 📂 Project Structure

```text
IoT-Smart-Home-Energy-Monitoring-System/
│── arduino_code/
│     └── smart_home_energy_monitoring.ino
│
│── docs/
│     └── project_report.pdf
│
│── images/
│     ├── wokwi_simulation.png
│     ├── wokwi_connection_diagram.png
│     ├── serial_monitor_normal_usage.png
│     ├── serial_monitor_moderate_usage.png
│     ├── serial_monitor_high_energy_alert.png
│     ├── thingspeak_dashboard.png
│     ├── thingspeak_graphs_voltage_current.png
│     └── thingspeak_graphs_power_energy_cost.png
│
│── outputs/
│     └── serial_monitor_output.png
│
│── README.md
│── requirements.txt
│── LICENSE
│── .gitignore
```

---

# 📸 Project Screenshots

## 1. Wokwi Simulation

![Wokwi Simulation](./images/wokwi_simulation.png)

---

## 2. Wokwi Circuit Connection

![Wokwi Circuit Connection](./images/wokwi_connection_diagram.png)

---

## 3. Serial Monitor - Normal Usage

![Normal Usage](./images/serial_monitor_normal_usage.png)

---

## 4. Serial Monitor - Moderate Usage

![Moderate Usage](./images/serial_monitor_moderate_usage.png)

---

## 5. Serial Monitor - High Energy Alert

![High Energy Alert](./images/serial_monitor_high_energy_alert.png)

---

## 6. ThingSpeak Dashboard

![ThingSpeak Dashboard](./images/thingspeak_dashboard.png)

---

## 7. ThingSpeak Graphs (Voltage & Current)

![ThingSpeak Graphs Voltage Current](./images/thingspeak_graphs_voltage_current.png)

---

## 8. ThingSpeak Graphs (Power, Energy & Cost)

![ThingSpeak Graphs Power Energy Cost](./images/thingspeak_graphs_power_energy_cost.png)

---

# 📈 Results

The system successfully:

✅ Monitored electricity consumption in real time
✅ Calculated voltage, current, and power
✅ Tracked energy usage (kWh)
✅ Estimated electricity cost
✅ Generated smart energy alerts
✅ Uploaded live data to ThingSpeak
✅ Displayed cloud-based graphs and analytics

---

# 🎯 Applications

* Smart Home Automation
* Energy Monitoring Systems
* Smart Buildings
* Electricity Bill Monitoring
* Industrial Energy Monitoring

---

# 🔮 Future Scope

* Real Sensor Integration
* Mobile App Support
* AI-Based Energy Prediction
* Smart Appliance Automation
* Automatic Energy Saving Recommendations

---

# 👨‍🏫 Mentor

**Umesh Yadav**
EDC IIT-Delhi

---

# 👨‍💻 Developed By

**Om Navgire**
**Department:** Electronics & Telecommunication Engineering (EXTC)
**College:** Prof. Ram Meghe Institute of Technology And Research, Amravati

---

# 📜 License

This project is developed for educational and learning purposes.

---

# ⭐ Show Your Support

If you found this project useful, please give it a **⭐ star on GitHub**.
