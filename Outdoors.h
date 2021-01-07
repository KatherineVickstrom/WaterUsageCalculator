/****************************************************************
File: Outdoors.h
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
#include <string>
#ifndef OUTDOORS_H
#define OUTDOORS_H

using namespace std;

const int OUTSIZE = 3;

class Outdoors {
public:
	Outdoors() {
		totalOutdoors = 0.0;
		for (int i = 0; i < OUTSIZE; i++) {
			outTotals[i] = 0;
		}
	}
	Outdoors(double totalOutdoors, double outTotals[]) {
		this->totalOutdoors = totalOutdoors;
		this->outTotals[OUTSIZE] = outTotals[OUTSIZE];
	}
	//prints outdoor water consumption and tips on how to reduce outdoor water consumption
	void print() {
		cout << "Outdoor water consumption: " << totalOutdoors << " gallon(s) per day.\n";
		cout << "\t\tTips for Reducing Water Consumption Outdoors\n";
		cout << "\t\t1. Employ drought resistent landscaping\n";
		cout << "\t\t2. Water plants between 5pm and 9am\n";
		cout << "\t\t3. Wash car less frequently\n";
		cout << "\t\t4. Use self service car wash, it is most efficient\n";
		cout << "\t\t5. Cover pool when not in use\n\n";
	}
	//calculates daily water uage on lawn
	void lawn() {
		string lawn;
		double numLawnSqFt;
		cout << "Do you water your lawn? (y/n) ";
		cin.ignore();
		getline(cin, lawn);
		//validates input
		while ((lawn != "y") && (lawn != "n")) {
			cout << "Bad input, reenter: ";
			getline(cin, lawn);
		}
		cout << endl;
		if (lawn == "y") {
			cout << "How many square feet is your lawn? ";
			cin >> numLawnSqFt;
			//validates input
			while ((!cin) || numLawnSqFt < 0 || numLawnSqFt > 800000) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Bad input, reenter: ";
				cin >> numLawnSqFt;
			}
			/*if elses calcuates daily water usage on lawn based on lawn squarefootage
			and then adds that value to the outTotals array*/
			if (numLawnSqFt <= 99 && numLawnSqFt >= 1) {
				outTotals[0] = 17.0;
			}
			else if (numLawnSqFt > 99 && numLawnSqFt <= 500) {
				outTotals[0] = 99.0;
			}
			else if (numLawnSqFt > 500 && numLawnSqFt <= 1000) {
				outTotals[0] = 248.0;
			}
			else if (numLawnSqFt > 1000 && numLawnSqFt <= 5000) {
				outTotals[0] = 990.0;
			}
			else if (numLawnSqFt > 5000 && numLawnSqFt <= 10000) {
				outTotals[0] = 2470.0;
			}
			else if (numLawnSqFt > 10000 && numLawnSqFt <= 40000) {
				outTotals[0] = 8250.0;
			}
			else if (numLawnSqFt > 40000) {
				outTotals[0] = 14375.0;
			}
			cout << endl;
		}
	}
	//calculates daily water usage on car washes
	void carWash() {
		double numCarWash;
		int typeCarWash;
		cout << "How many times do you wash your car per month? ";
		cin >> numCarWash;
		//validates input
		while ((!cin) || numCarWash < 0 || numCarWash > 60) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Bad input, reenter: ";
			cin >> numCarWash;
		}
		cout << endl;
		if (numCarWash > 0) {
			cout << "What type of car wash? (enter 1, 2, or 3)\n";
			cout << "1. Garden hose car wash\n";
			cout << "2. Full service car wash\n";
			cout << "3. Self service car wash\n";
			cin >> typeCarWash;
			//validates input
			while ((!cin) || (typeCarWash < 1) || (typeCarWash > 3)) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Bad input, reenter: ";
				cin >> typeCarWash;
			}
			/*calcuates daily water usage on car washes based on what kind of car wash and how many car washes per month
			and then adds that value to the outTotals array*/
			switch (typeCarWash) {
				//Garden hose car wash
			case 1:
				outTotals[1] = (100 * numCarWash) / 30;
				break;
				//Full service car wash
			case 2:
				outTotals[1] = (58 * numCarWash) / 30;
				break;
				//Self service car wash
			case 3:
				outTotals[1] = (15 * numCarWash) / 30;
				break;
			}
			cout << endl;
		}
	}
	//calculates daily water usage on pool
	void pool() {
		string pool;
		cout << "Do you have a pool? (y/n) ";
		cin.ignore();
		getline(cin, pool);
		//validates input
		while ((pool != "y") && (pool != "n")) {
			cout << "Bad input, reenter: ";
			getline(cin, pool);
		}
		cout << endl;
		//calculates daily water usage on pool based on how many months the pool is left uncovered
		/*calcuates daily water usage on poool based on how many months the pool is left uncovered
		and then adds that value to the outTotals array*/
		if (pool == "y") {
			double monthsPoolUncovered;
			cout << "How many months out of the year do you leave the pool uncovered? ";
			cin >> monthsPoolUncovered;
			//validates input
			while ((!cin) || monthsPoolUncovered < 0 || monthsPoolUncovered > 12) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Bad input, reenter: ";
				cin >> monthsPoolUncovered;
			}
			outTotals[2] = (monthsPoolUncovered * 1000) / 365;
		}
		cout << endl;
	}
	/*calculates total daily water usage for the outdoors by running through the array that holds
	the values for the water usage of appliance in the outdoors and adding the values together*/
	double totalO() {
		for (int i = 0; i < OUTSIZE; i++) {
			totalOutdoors += outTotals[i];
		}
		return totalOutdoors;
	}
private:
	double outTotals[OUTSIZE];
	double totalOutdoors;
};

#endif