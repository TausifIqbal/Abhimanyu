# Abhimanyu Chakravyuha

## Question statement
Imagine Abhimanyu in Chakravyuha. There are 11 circles in the Chakravyuha surrounded by different enemies.
Abhimanyu is located in the innermost circle and has to cross all the 11 circles to reach Pandavas army back. 
 

Given:
- Each circle is guarded by different enemy where enemy is equipped with k1, k2……k11 powers
- Abhmanyu start from the innermost circle with p power Abhimanyu has a boon to skip fighting enemy
a times 
- Abhmanyu can recharge himself with power b times 
- Battling in each circle will result in loss of the same power from Abhimanyu as the enemy. 
- If Abhmanyu enter the circle with energy less than the respective enemy, he will lose the battle
-   k3 and k7 enemies are endured with power to regenerate themselves once with half of their initial 
power and can attack Abhimanyu from behind if he is battling in iteratively next circle 
  

  
Write an algorithm to find if Abhimanyu can cross the Chakravyuh and test it with two sets of test cases.

## Solution
    - if abhimanyu can skip all enemies  answer will always YES
    - if count of enemy having power more than abhimanyu max power is more than  number of fight abhimanyu can skip then answer will always NO


    - track state (circle,abhimanyu current power, recharge left, fight skip),
    if abhimanyu can reach circle N+1 with valid state then he can break the chakravyuha

## Run
    compile:   g++ abhimanyu.cpp
    run:       ./abhimanyu test1.txt