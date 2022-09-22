# Smart-Garage-System-using-Atmega16
This project was written in C using Microchip Studio and Proteus 8 professional.
## Aim
manage entry and exit from the garage where the entrance and exit gate is closed with a rotating metal barrier
## Procedure Details
There are  two PIR sensors, one at the entrance and the other at exit gate.
1- if a car approaches the sensor of the entrance gate, microcontroller checks the number of cars inside the garage (because the garage capacity is only 3 cars) 
- If an empty space is found, servo motor is rotated by +90 ° in order to raise the metal barrier and open the road for 2sec util the car gets in completely. after 2sec servo is rotated at-90 ° in order to close The road.
the new number of cars inside garage is displayed on lcd and whether entry is available or not By the number of cars inside.
- If there isnot an empty space, "Garage is Full" is displayed on lcd.

2- if a car approaches the sensor of the exit gate, servo motor is rotated at an angle of + 90 ° in order to raise the metal barrier and open the road for 2sec until the car comes out.after 2sec servo is rotated at -90 ° in orde to descend the metal barrier and close the road.
the new number of cars inside garage is displayed on lcd and so on..

## Simulation
![proteus simulation](https://user-images.githubusercontent.com/104006521/191812755-5d613402-7b22-495b-9ffb-6d22d6e189d0.png)
