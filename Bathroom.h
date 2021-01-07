/****************************************************************
File: Bathroom.h
Description: This project allows a user to calculate their estimated
water usage in their home. It asks them questions about their usage
and then performs calculations. The program outputs the estmated
water usage in the bathroom, kitchen, outdoors, and the overall total.
It outputs tips on how to save water in each area of their home.
We figured out the calculation methodology in this PDF:
http://gracelinks.org/media/pdf/WFC20Methodology2015.pdf
Author: Katherine Vickstrom, Phillip Halverson, and Richard Townson
Class: CSCI-120-35
Date: May 19, 2016
I hereby certify that this program is entirely my own work.
*****************************************************************/
#include <limits>
#include <iostream>
#ifndef BATHROOM_H
#define BATHROOM_H

using namespace std;

const int BATHSIZE = 3;

class Bathroom {
public:
	Bathroom() {
		totalBathroom = 0.0;
		for (int i = 0; i < BATHSIZE; i++) {
			bathTotals[i] = 0;
		}
	}

	Bathroom(double totalBathroom, double bathTotals[]) {
		this->totalBathroom = totalBathroom;
		this->bathTotals[BATHSIZE] = bathTotals[BATHSIZE];
	}

	//prints bathroom water consumption and tips on how to reduce bathroom water consumption
	void print() {
		cout << "Bathroom water consumption: " << totalBathroom << " gallon(s) per day.\n";
		cout << "\t\tTips for Reducing Water Consumption in the Bathroom\n";
		cout << "\t\t1. Buy low flow sink which uses 1.5gpm vs. 5gpm (gallons per minute)\n";
		cout << "\t\t2. Don't let faucent run needlessly\n";
		cout << "\t\t3. Buy low flow toilet\n";
		cout << "\t\t4. Buy low flow shower head and/or take shorter showers\n\n";
	}
	//calculates daily water uage on toilet
	void toilet() {
		double toiletFlush;
		cout << "How many times do you flush the toilet per day? ";
		cin >> toiletFlush;
		//validates input
		while ((!cin) || toiletFlush < 0 || toiletFlush > 100) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Bad input, reenter: ";
			cin >> toiletFlush;
		}
		cout << endl;
		/*calcuates daily water usage on toilet based on how many times it it flushed per day
		and then adds that value to the bathTotals array*/
		bathTotals[0] = toiletFlush *= 3.5;
	}
	//calculates daily water uage on showers
	void showers() {
		double numShowers;
		cout << "How many showers do you take per week? ";
		cin >> numShowers;
		//validates input
		while ((!cin) || numShowers < 0 || numShowers > 100) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Bad input, reenter: ";
			cin >> numShowers;
		}
		cout << endl;
		/*calcuates daily water usage on showers based on how many showers are taken per week
		and then adds that value to the bathTotals array*/
		bathTotals[1] = (numShowers * 40) / 7;
	}
	//calculates daily water uage on bathroom sink
	void sink() {
		double minutesSinkUse;
		cout << "How many minutes per day do you use your bathroom sink? ";
		cin >> minutesSinkUse;
		//validates input
		while ((!cin) || minutesSinkUse < 0 || minutesSinkUse > 1440) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Bad input, reenter: ";
			cin >> minutesSinkUse;
		}
		cout << endl;
		/*calcuates daily water usage on bathroom sink based on how many minutes it's used per day
		and then adds that value to the bathTotals array*/
		bathTotals[2] = minutesSinkUse *= 5;
	}
	/*calculates total daily water usage for the bathroom by running through the array that holds
	the values for the water usage of appliance in the bathroom and adding the values together*/
	double totalB() {
		for (int i = 0; i < BATHSIZE; i++) {
			totalBathroom += bathTotals[i];
		}
		return totalBathroom;
	}
private:
	double bathTotals[BATHSIZE];
	double totalBathroom;
};

#endif
