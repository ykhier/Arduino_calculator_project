# 📟 Arduino Calculator with Keypad & LCD

## 🔗 Project Link
👉 https://www.tinkercad.com/things/jXA2IRlq3I1-stunning-turing-hango

---

## 📌 Overview
This project is a calculator system built using Arduino, featuring a keypad for input, an LCD display for output, and LED indicators for user interaction.

The system allows users to perform basic arithmetic operations and provides visual feedback using LEDs.

---

## 🛠️ Technologies & Components
- Arduino Uno  
- 4x4 Keypad  
- LCD Display (16x2)  
- LEDs (White, Yellow, RGB)  
- Breadboard & resistors  
- C++ (Arduino)  

---

## ⚙️ Features
- ✅ Input numbers using keypad  
- ✅ Supports operations:
  - Addition (+)
  - Subtraction (-)
  - Multiplication (*)
  - Division (/)
- ✅ Real-time display on LCD  
- ✅ Clear option (C)  
- ✅ Continuous calculations (using previous result)  

---

## 💡 Smart Behavior
- 🔢 Even numbers → White LED  
- 🔢 Odd numbers → Yellow LED  
- 🟢 Result = 0 → RGB animation  
- 🔴 Negative result → Red LED blinking  
- 🔵 If result contains digit 5 → Blue LED flashes  
- ⚠️ Division by zero → Error message on LCD  

---

## 🧠 How It Works
The system reads input from the keypad and builds numbers dynamically.  
When an operator is selected, it waits for the second number and performs the calculation.

The logic is implemented using:
- State variables (`flag`, `cnt`, `cntclear`)  
- A helper function `func()` to read numbers  
- LCD for user feedback  
- LEDs for visual indicators  

---

## 🚀 How to Run
1. Open the project in Tinkercad  
2. Click **Start Simulation**  
3. Use the keypad to enter numbers and operations  
4. View results on the LCD  

---

## 👨‍💻 Authors
- Yosef Khier  
- Sami  

---

## 📈 Future Improvements
- Add decimal number support  
- Improve UI messages  
- Add memory functions (M+, M-)  
- Convert to physical Arduino project  
