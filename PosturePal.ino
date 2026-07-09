#include <WiFi.h>
#include <Firebase_ESP_Client.h>
#include <Wire.h>
#include <MPU6050.h>

// ✅ WiFi Credentials
#define WIFI_SSID "Redmi Note 11 Pro"
#define WIFI_PASSWORD "12345678"

// ✅ Firebase Config
#define FIREBASE_HOST "https://posturexpert-2e486-default-rtdb.asia-southeast1.firebasedatabase.app/"
#define FIREBASE_AUTH "Fc0Ws63mKPWYinfFAPtdU2uksJN6B81KtD2lRA1B"

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;
MPU6050 mpu1(0x68);  // First MPU6050 at address 0x68
MPU6050 mpu2(0x69);  // Second MPU6050 at address 0x69

// ✅ Vibration Motor Pin
#define VIBRATION_PIN 16  

// ✅ Posture Thresholds
#define PITCH_THRESHOLD 70   // Acceptable pitch range

// 🛠 WiFi Connection
void setupWiFi() {
    Serial.print("Connecting to WiFi...");
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\n✅ Connected to WiFi!");
}

// 🛠 Firebase Initialization
void setupFirebase() {
    config.database_url = FIREBASE_HOST;
    config.signer.tokens.legacy_token = FIREBASE_AUTH;
    Firebase.begin(&config, &auth);
    Firebase.reconnectWiFi(true);
    Serial.println("✅ Connected to Firebase!");
}

// 🛠 MPU6050 Initialization
void setupMPU() {
    Wire.begin();
    pinMode(VIBRATION_PIN, OUTPUT);

    Serial.println("Initializing MPU6050 #1...");
    mpu1.initialize();
    if (!mpu1.testConnection()) {
        Serial.println("❌ Failed to connect to MPU6050 #1!");
    } else {
        Serial.println("✅ MPU6050 #1 Connected!");
    }

    Serial.println("Initializing MPU6050 #2...");
    mpu2.initialize();
    if (!mpu2.testConnection()) {
        Serial.println("❌ Failed to connect to MPU6050 #2!");
    } else {
        Serial.println("✅ MPU6050 #2 Connected!");
    }
}

// 📊 Read Sensor Data & Detect Posture
void readAndDetectPosture(float &pitch1, float &pitch2, String &status1, String &status2) {
    int16_t ax1, ay1, az1, gx1, gy1, gz1;
    int16_t ax2, ay2, az2, gx2, gy2, gz2;

    // 🚀 Read MPU6050 #1
    mpu1.getMotion6(&ax1, &ay1, &az1, &gx1, &gy1, &gz1);
    float ax1f = ax1 / 16384.0, ay1f = ay1 / 16384.0, az1f = az1 / 16384.0;
    pitch1 = atan2(ay1f, sqrt(ax1f * ax1f + az1f * az1f)) * 180.0 / PI;

    // 🚀 Read MPU6050 #2
    mpu2.getMotion6(&ax2, &ay2, &az2, &gx2, &gy2, &gz2);
    float ax2f = ax2 / 16384.0, ay2f = ay2 / 16384.0, az2f = az2 / 16384.0;
    pitch2 = atan2(ay2f, sqrt(ax2f * ax2f + az2f * az2f)) * 180.0 / PI;

    // ✅ Posture Detection
    bool badPosture1 = (abs(pitch1) < PITCH_THRESHOLD);
    bool badPosture2 = (abs(pitch2) < PITCH_THRESHOLD);

    // Define status as "Correct" or "Incorrect"
    status1 = badPosture1 ? "Incorrect" : "Correct";
    status2 = badPosture2 ? "Incorrect" : "Correct";

    // 🚨 Vibrate if bad posture detected
    if (badPosture1 || badPosture2) {
        Serial.println("❌ Bad posture detected! Vibrating...");
        digitalWrite(VIBRATION_PIN, HIGH);
        delay(500);
        digitalWrite(VIBRATION_PIN, LOW);
    } else {
        Serial.println("✅ Correct posture detected!");
    }

    // Print pitch data
    Serial.println("MPU6050 #1 -> Pitch: " + String(pitch1) + "°  Status: " + status1);
    Serial.println("MPU6050 #2 -> Pitch: " + String(pitch2) + "°  Status: " + status2);
}

// 🔥 Send Real-Time Data to Firebase
void sendRealTimeDataToFirebase(float pitch1, float pitch2, String status1, String status2) {
    if (Firebase.ready()) {
        String path = "/RealTimePostureData";  // ✅ Single path for real-time data

        // ✅ Store real-time posture data
        Firebase.RTDB.setString(&fbdo, path + "/Sensor1/Pitch", String(pitch1, 2) + "°");
        Firebase.RTDB.setString(&fbdo, path + "/Sensor1/Status", status1);

        Firebase.RTDB.setString(&fbdo, path + "/Sensor2/Pitch", String(pitch2, 2) + "°");
        Firebase.RTDB.setString(&fbdo, path + "/Sensor2/Status", status2);

        Serial.println("✅ Real-time data sent to Firebase!");
    } else {
        Serial.println("❌ Failed to connect to Firebase!");
    }
}

// 🛠 Setup Function
void setup() {
    Serial.begin(115200);
    setupWiFi();
    setupFirebase();
    setupMPU();
}

// 🚀 Main Loop
void loop() {
    float pitch1, pitch2;
    String status1, status2;

    readAndDetectPosture(pitch1, pitch2, status1, status2);
    sendRealTimeDataToFirebase(pitch1, pitch2, status1, status2);

    delay(1500);  // Update every 2 seconds
}
