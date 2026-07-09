# Posture-detection-and-alert-system-with-app-tracking-AI-chat-bot-assistance-system.
Dual-Zone Wearable Posture Monitoring and Correction System using two MPU6050 IMU sensors and an ESP32 to independently monitor upper and lower back posture. The device detects posture deviations in real time and provides localized vibration feedback through dedicated motors to encourage healthy spinal alignment.
# Dual-Zone Wearable Posture Monitoring and Correction System Using IMU Feedback

## Project Description

The **Dual-Zone Wearable Posture Monitoring and Correction System Using IMU Feedback** is a smart wearable device designed to continuously monitor and improve human posture by independently tracking the alignment of the **upper back (thoracic region)** and **lower back (lumbar region)**. The system addresses the growing prevalence of posture-related musculoskeletal disorders caused by prolonged sitting, excessive screen time, remote work, online education, and poor ergonomic practices.

Unlike conventional posture correctors that monitor only a single spinal region or provide generalized feedback, this system utilizes **two MPU6050 Inertial Measurement Unit (IMU) sensors**, each strategically positioned on the upper and lower back. These sensors measure three-axis acceleration and angular velocity, allowing the ESP32 microcontroller to calculate the **pitch** and **roll** angles of each spinal region independently. By continuously comparing these values against predefined ergonomic thresholds, the system accurately identifies posture deviations such as slouching, forward bending, and lateral leaning.

A key innovation of the project is its **dual-zone localized haptic feedback mechanism**. Each IMU is paired with a dedicated vibration motor that activates only when the corresponding spinal region exceeds the acceptable posture threshold. For example, if the upper back slouches, only the upper vibration motor is triggered, while incorrect lower-back posture activates only the lower vibration motor. This targeted feedback enables users to immediately recognize which part of their spine requires correction, leading to faster and more intuitive posture adjustments.

The prototype is built around an **ESP32 microcontroller**, which serves as the central processing unit for sensor data acquisition, posture analysis, and vibration control. The MPU6050 sensors communicate with the ESP32 using the **I²C communication protocol**, enabling reliable real-time data transfer while minimizing wiring complexity. The embedded algorithm continuously processes sensor data and determines posture status without requiring external computation.

The device is designed to be lightweight, compact, and comfortable for everyday use. It can be integrated into wearable belts, straps, harnesses, or smart garments, making it suitable for prolonged use in offices, classrooms, homes, and industrial workplaces. Since posture monitoring and correction are performed entirely on the device, it operates independently without requiring smartphone applications, Bluetooth connectivity, or cloud services for its core functionality.

The system is particularly beneficial for **students, office professionals, remote workers, gamers, drivers, healthcare workers, industrial employees, and individuals undergoing physiotherapy or spinal rehabilitation**. By providing immediate corrective feedback, the device encourages healthy posture habits, reduces prolonged spinal stress, minimizes musculoskeletal discomfort, and promotes long-term spinal health.

### Key Features

* **Dual IMU-based posture monitoring** for independent upper and lower back analysis.
* **Real-time pitch and roll angle calculation** using MPU6050 sensors.
* **ESP32-based processing** for fast and efficient posture detection.
* **Dedicated vibration motor for each spinal region** to provide localized haptic feedback.
* **Continuous real-time monitoring** without interrupting daily activities.
* **Lightweight, wearable, and battery-powered** design for portability and comfort.
* **No dependency on smartphones or external applications** for posture correction.
* **Low-cost implementation** using readily available electronic components.
* **Suitable for preventive healthcare, ergonomic workplaces, rehabilitation, education, and wearable health technology applications.**

### Applications

* Office and corporate workplaces
* Remote work and home offices
* Schools, colleges, and universities
* Physiotherapy and rehabilitation centers
* Sports training and fitness coaching
* Industrial and occupational safety
* Healthcare and preventive wellness
* Smart wearable technology

### Future Scope

The system can be further enhanced by integrating additional IMU sensors for full-spine monitoring, incorporating artificial intelligence for personalized posture analysis, embedding the electronics into smart clothing, and optionally adding cloud connectivity for long-term posture analytics and healthcare monitoring.

Overall, the **Dual-Zone Wearable Posture Monitoring and Correction System Using IMU Feedback** provides an affordable, practical, and intelligent solution for maintaining proper spinal alignment through precise dual-region monitoring and localized corrective feedback. Its innovative architecture, simplicity, and scalability make it suitable for both personal wellness applications and future commercial wearable healthcare products.
<img width="1200" height="1600" alt="pos" src="https://github.com/user-attachments/assets/d2edd40f-ba1d-491c-8b3a-32dec80ca97f" />

Android Application:
<img width="576" height="1280" alt="image" src="https://github.com/user-attachments/assets/2933f788-57df-41f8-b6cf-b1b5b9dc413a" />
<img width="576" height="1280" alt="image" src="https://github.com/user-attachments/assets/b6abd1cf-b510-4388-8abb-9551c8fde7a7" />
<img width="576" height="1280" alt="image" src="https://github.com/user-attachments/assets/963903cd-d0ba-4a70-af76-db9801ef77c1" />
<img width="576" height="1280" alt="image" src="https://github.com/user-attachments/assets/49f08d72-be19-4b9b-872a-07a6eaae2b79" />



