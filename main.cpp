/****************************************************************
File: main.cpp
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
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include "Kitchen.h"
#include "Bathroom.h"
#include "Outdoors.h"
#include <windows.h>

using namespace std;

//function for setting window size
void SetWindow(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle 
	SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size 
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size 
}

int main() {
	//sets window size
	SetWindow(100, 50);
	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	//sets text color
	SetConsoleTextAttribute(hConsole, 11);
	//vector holds total gallons used per part of the house
	vector<double> gallons;
	//name of user
	string name = "";
	//total water usage
	double total = 0.0;
	//object for outdoor class water usage
	Outdoors o;
	//object for kitchen class water usage
	Kitchen k;
	//object for bathroom class water usage
	Bathroom b;

	cout << "\t\tWelcome to our Water Consumption Calculator!\n\n";
	cout << "\tWe will ask you some questions about your water usage\n";
	cout << "\tand then calculate an estimate of how many gallons of\n";
	cout << "\twater you use per day. Let's get started!\n\n";
	cout << "Enter your name: ";
	getline(cin, name);
	cout << endl;
	cout << "Okay " << name << ".\n";
	cout << "First we have some questions about your water usage in your kitchen.\n\n";
	//object calls the function that asks the questions about kitchen sink usage and completes calculations
	k.sink();
	//object calls the function that asks the questions about dishwasher usage and completes calculations
	k.dishwasher();
	//object calls the function that asks the questions about washing machine usage and completes calculations
	k.washingMachine();
	//object calls the function that gets the total water usage for kitchen and pushes the value into the vector
	gallons.push_back(k.totalK());
	cout << "So far so good, " << name << ".\n";
	cout << "Next, we have some questions about your water usage in your bathroom.\n\n";
	//object calls the function that asks the questions about toilet usage and completes calculations
	b.toilet();
	//object calls the function that asks the questions about shower usage and completes calculations
	b.showers();
	//object calls the function that asks the questions about bathroom sink usage and completes calculations
	b.sink();
	//object calls the function that gets the total water usage for bathroom and pushes the value into the vector
	gallons.push_back(b.totalB());
	cout << "Almost done " << name << "!\n";
	cout << "Lastly, we have some questions about your water usage outdoors.\n\n";
	//object calls the function that asks the questions about lawn watering and completes calculations
	o.lawn();
	//object calls the function that asks the questions about car washes and completes calculations
	o.carWash();
	//object calls the function that asks the questions about pool ownership and completes calculations
	o.pool();
	//object calls the function that gets the total water usage for outdoors and pushes the value into the vector
	gallons.push_back(o.totalO());
	cout << "Congratulations for completing the Water Consumption Calculator " << name << "!\n";
	cout << "Here are your results... \n";
	//for loop goes through vector to add all the totals up for each part of home to get overall total
	for (int i = 0; i < gallons.size(); i++) {
		total += gallons.at(i);
	}
	//outputs the total water consumption for the entire home
	cout << "Total water consumption: " << setprecision(2) << fixed << total << " gallons per day.\n\n";
	/*object calls the function that prints the water usage for the kitchen
	as well as tips on how to reduce water consumption in the kitchen*/
	k.print();
	/*object calls the function that prints the water usage for the bathroom
	as well as tips on how to reduce water consumption in the bathroom*/
	b.print();
	/*object calls the function that prints the water usage outdoors
	as well as tips on how to reduce water consumption outdoors*/
	o.print();
	cout << endl;
	return 0;
}