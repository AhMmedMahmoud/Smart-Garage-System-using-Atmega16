# Smart-Garage-System-using-Atmega16
This project was written in C using Microchip Studio and Proteus 8 professional.
## Aim
simulate the embedded controller at a smart garage system
## Procedure Details
- There are  two PIR sensors, one at the entrance and the other at exit gate.
- the garage capacity is only 3 cars.

1- If a car approaches the sensor of the entrance gate
- If an empty space is found, servo motor is rotated by +90 ° in order to raise the metal barrier and open the road for 2sec util the car gets in completely. after 2sec servo is rotated at -90 ° in order to close The road.
the new number of cars inside garage is displayed on lcd and whether entry is allowed or not By the number of cars inside.
- If there isnot an empty space, number of cars inside garage and "Garage is Full" are displayed on lcd.

2- If a car approaches the sensor of the exit gate, servo motor is rotated at an angle of + 90 ° in order to raise the metal barrier and open the road for 2sec until the car comes out. after 2sec servo is rotated at -90 ° in orde to descend the metal barrier and close the road.
the new number of cars inside garage and "Enter is allowed" are displayed on lcd and so on..

## Simulation
![proteus simulation](https://user-images.githubusercontent.com/104006521/191812755-5d613402-7b22-495b-9ffb-6d22d6e189d0.png)

## Zip file 
[here](https://drive.google.com/file/d/1PCYbPR-aVwK0D4VCO-fg8L83dVmN6qBI/view?usp=sharing)
