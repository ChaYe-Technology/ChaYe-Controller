# ChaYe Controller (Work in Progress)

### Purpose
A project aimed at creating a custom controller intending to replace mouse and keyboard for PC input, without
needing dedicated controller support for console controllers. Will also allow for simple typing input with
increase efficiency than using d-pad to navigate an on-screen keyboard.

### Reason
Moving from mobile gaming to PC and console gaming, one main benefit for mobile controls was using the screen
for 3D camera controls rather than a joystick. This controller replaces the right joystick with a touchpad.
Such a setup is much more similar to a mouse 3D camera controls as new camera positions are relative to the 
location of the previous camera position. A joystick on the other hand is like using arrow keys for camera 
controls, just with analog inputs for adjusting speed. Pairing the mobile camera controls with the vast button 
inputs a console controller eliminates the drawback of mobile gaming controls.

Keyboard inputs right now for console controllers are also very outdated. Rather than navigating a on-screen
keyboard, the joystick, touchpad, and buttons can be used to access sub-menus to faster typing.

### Tech Stack
Focused around a Xiao RP2350 microcontroller programmed using the Arduino IDE
##### Components
* Xiao RP2350
* Gulikit TMR PS5 Joystick
* Cirque TM040040-2024-303 (Touchpad)
* Kailh GM 8.0 (Mouse Switch)
* TTC Gold 10mm Rotary Encoder
* Alps Alpine SKRHADE010 (5-way Button)
* Alps Alpine SKRAAKE010 (Button)
* Alps Alpine SKRPABE010 (Button)
