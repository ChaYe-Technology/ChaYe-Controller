#include "Mouse.h"
#include "Keyboard.h"

int mouse_l_pin = D6;
int mouse_r_pin = D7;
int mouse_m_pin = D8;

int scroll_0_pin = D9;
int scroll_1_pin = D10;

int joystick_x_pin = A0;
int joystick_y_pin = A1;
int joystick_b_pin = D2;

int scroll_0_pre = digitalRead(scroll_0_pin);
int scroll_1_pre = digitalRead(scroll_1_pin);
int prev_state = 0; // Stores the state of the pins (0-3)

int x_min = 97;
int x_mid = 507;
int x_max = 910;

int y_min = 4;
int y_mid = 504;
int y_max = 990;

long angle = -1;

void setup() {
  Mouse.begin();
  Keyboard.begin();

  pinMode(mouse_l_pin, INPUT_PULLUP);
  pinMode(mouse_r_pin, INPUT_PULLUP);
  pinMode(mouse_m_pin, INPUT_PULLUP);

  pinMode(scroll_0_pin, INPUT_PULLUP);
  pinMode(scroll_1_pin, INPUT_PULLUP);
  
  pinMode(joystick_b_pin, INPUT_PULLUP);
}

void loop() {
  mouse();
  joystick();
}

void mouse() {
  mouse_helper_pin(mouse_l_pin, MOUSE_LEFT);
  mouse_helper_pin(mouse_r_pin, MOUSE_RIGHT);
  mouse_helper_pin(mouse_m_pin, MOUSE_MIDDLE);
}

void mouse_helper_pin(int pin, char button) {
  if (digitalRead(pin) == LOW) {
    Mouse.press(button);
  } else {
    Mouse.release(button);
  }
}

void joystick() {
  int x_in = analogRead(joystick_x_pin) - x_mid;
  int y_in = analogRead(joystick_y_pin) - y_mid;
  
  long distanceSquared = (long)x_in * x_in + (long)y_in * y_in;
  
  if (distanceSquared > 2500) {
    angle = atan2(y_in, x_in) * 57.296; 
    if (angle < 0) {
      angle += 360;
    }
  } else {
    angle = -1;
  }

  if (angle < 0) {             // None
    joystick_helper_wasd(0,0,0,0);
  } else if (angle < 22.5) {   // Left
    joystick_helper_wasd(0,1,0,0);
  } else if (angle < 67.5) {   // Down Left
    joystick_helper_wasd(0,1,1,0);
  } else if (angle < 112.5) {  // Down
    joystick_helper_wasd(0,0,1,0);
  } else if (angle < 157.5) {  // Down Right
    joystick_helper_wasd(0,0,1,1);
  } else if (angle < 202.5) {  // Right
    joystick_helper_wasd(0,0,0,1);
  } else if (angle < 247.5) {  // Up Right
    joystick_helper_wasd(1,0,0,1);
  } else if (angle < 292.5) {  // Up
    joystick_helper_wasd(1,0,0,0);
  } else if (angle < 337.5) {  // Up Left
    joystick_helper_wasd(1,1,0,0);
  } else {                     // Left (Again)
    joystick_helper_wasd(0,1,0,0);
  }
}

void joystick_helper_wasd(int w, int a, int s, int d) {
    if (w == 1) {
      Keyboard.press('w');
    } else {
      Keyboard.release('w');
    }

    if (a == 1) {
      Keyboard.press('a');
    } else {
      Keyboard.release('a');
    }

    if (s == 1) {
      Keyboard.press('s');
    } else {
      Keyboard.release('s');
    }

    if (d == 1) {
      Keyboard.press('d');
    } else {
      Keyboard.release('d');
    }
  }
