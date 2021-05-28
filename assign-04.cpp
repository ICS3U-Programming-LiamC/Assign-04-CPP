// Copyright (c) 2021 Liam Csiffary All rights reserved.
//
// Created by: Liam Csiffary
// Date: May DATE, 2021
// This program STUFF STUFF

#include <iostream>
#include <cmath>

// SO MANY VARIABLES
int input1;
int input2;
int maxNum;
int biggerNum;
int smallerNum;
int counter;
int dividedNum;
int current;
int numOfProcesses;

int main() {
    // make the string version of the var
    std::string inputStr1;
    std::string inputStr2;

    // get the number from the user
    std::cout << "What is your input: ";
    std::cin >> inputStr1;
    std::cout << "What is your input: ";
    std::cin >> inputStr2;

    try {
        // try to turn it into a integer
        input1 = std::stoi(inputStr1);
        input2 = std::stoi(inputStr2);

        // make the max number that the lmc should be
        maxNum = input1*input2;

        // determines which of the inputs is bigger
        // and which is smaller
        if (input1 > input2) {
            biggerNum = input1;
            smallerNum = input2;
        } else {
            biggerNum = input2;
            smallerNum = input1;
        }

        // make current maximum so that it has something to
        // compare to when its compared to smaller numbers
        current = maxNum;

        // this will determine a plethora of posible numbers all
        // candidates for the lcm
        for (counter = 1; counter < smallerNum + 1; counter++) {
            numOfProcesses = numOfProcesses + 1;
            dividedNum = maxNum / counter;

            // is the number is divisible by both numbers
            if ((dividedNum % biggerNum == 0) && dividedNum % smallerNum == 0) {
                numOfProcesses = numOfProcesses + 1;
                // if the new number is smaller than the current
                // replace the current
                if (dividedNum < current) {
                    numOfProcesses = numOfProcesses + 1;
                    current = dividedNum;
                }
            }
        }

    // display the lcm to the user
    std::cout << "The LCM of " << input1 << " and " << input2
    << " is " << current << "\n";
    std::cout << numOfProcesses
    << " number of proccesses were excecuted during this code";

    // if could not turn into integer
    } catch (std::invalid_argument) {
        std::cout << "This is not a valid number\n";
    }
}
