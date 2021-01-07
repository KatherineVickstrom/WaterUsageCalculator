/****************************************************************
File: Kitchen.h
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
#ifndef KITCHEN_H
#define KITCHEN_H

using namespace std;

const int KITSIZE = 3;

class Kitchen {
public:
	Kitchen() {
		totalKitchen = 0.0;
		for (int i = 0; i < KITSIZE; i++) {
			kitTotals[i] = 0;
		}
	}
	Kitchen(double totalKitchen, double kitTotals[]) {
		this->totalKitchen = totalKitchen;
		this->kitTotals[KITSIZE] = kitTotals[KITSIZE];
	}
	//prints kitchen water consumption and tips on how to reduce kitchen water consumption
	void print() {
		cout << "Kitchen water consumption: " << totalKitchen << " gallon(s) per day.\n";
		cout << "\t\tTips for Reducing Water Consumption in the Kitchen\n";
		cout << "\t\t1. Buy low flow sink which uses 1.5gpm vs. 5gpm (gallons per minute)\n";
		cout << "\t\t2. Don't let faucent run needlessly\n";
		cout << "\t\t3. Buy a dishwasher, they use much less water. Better yet, get an energy\n\t\t efficient dishwasher\n";
		cout << "\t\t4. Buy energy efficient washing machine\n\n";
	}
	//calculates daily water uage on dishwasher
	void dishwasher() {
		double numDishWash;
		string dishwasher;
		cout << "Do you have a dishwasher? (y/n) ";
		cin.ignore();
		getline(cin, dishwasher);
		//validates input
		while ((dishwasher != "y") && (dishwasher != "n")) {
			cout << "Bad input, reenter: ";
			getline(cin, dishwasher);
		}
		cout << endl;
		cout << "How many times do you wash dishes per week? ";
		cin >> numDishWash;
		//validates input
		while ((!cin) || numDishWash < 0 || numDishWash > 100) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Bad input, reenter: ";
			cin >> numDishWash;
		}
		cout << endl;
		
		/*calcuates daily water usage for dish washing based on how dishes are washed and how many time they're washed per week
		and then adds that value to the kitTotals array*/
		if (dishwasher == "y") {
			kitTotals[0] = (numDishWash * 15) / 7;
		}
		else {
			kitTotals[0] = (numDishWash * 20) / 7;
		}
	}
	//calculates daily water usage on washing machine
	void washingMachine() {
		double numClothesWash;
		cout << "How many loads of laundry do you do per week? ";
		cin >> numClothesWash;
		//validates input
		while ((!cin) || numClothesWash < 0 || numClothesWash > 100) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Bad input, reenter: ";
			cin >> numClothesWash;
		}
		cout << endl;
		/*calcuates daily water usage on washing machine based on how many loads are done per week
		and then adds that value to the kitTotals array*/
		kitTotals[1] = (numClothesWash * 41) / 7;
	}
	//calculates daily water usage on kitchen sink
	void sink() {
		double minutesSinkUse;
		cout << "How many minutes per day do you use your kitchen sink? ";
		cin >> minutesSinkUse;
		//validates input
		while ((!cin) || minutesSinkUse < 0 || minutesSinkUse > 1440) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Bad input, reenter: ";
			cin >> minutesSinkUse;
		}
		cout << endl;
		/*calcuates daily water usage on kitchen sink based on how many minutes it's used per day
		and then adds that value to the kitTotals array*/
		kitTotals[2] = minutesSinkUse * 5;
	}
	/*calculates total daily water usage for the kitchen by running through the array that holds
	the values for the water usage of appliance in the kitchen and adding the values together*/
	double totalK() {
		for (int i = 0; i < KITSIZE; i++) {
			totalKitchen += kitTotals[i];
		}
		return totalKitchen;
	}
private:
	double kitTotals[KITSIZE];
	double totalKitchen;
};

#endif