#ifndef CONFIG_H
#define CONFIG_H

// =========================
// RFID RC522
// =========================
#define RFID_SS_PIN 10
#define RFID_RST_PIN 9

// =========================
// Stepper ULN2003
// =========================
#define STEPPER_IN1 2
#define STEPPER_IN2 3
#define STEPPER_IN3 4
#define STEPPER_IN4 5

// =========================
// Servo Door
// =========================
#define SERVO_PIN 6

// =========================
// Floor Sensors
// =========================
#define FLOOR1_SENSOR A0
#define FLOOR2_SENSOR A1
#define FLOOR3_SENSOR A2
#define FLOOR4_SENSOR A3

// =========================
// LCD I2C
// =========================
#define LCD_ADDRESS 0x27

// =========================
// Door
// =========================
#define DOOR_OPEN_ANGLE 90
#define DOOR_CLOSE_ANGLE 0
#define DOOR_OPEN_TIME 3000

// =========================
// Stepper
// =========================
#define MAX_SPEED 600
#define ACCELERATION 300

#endif