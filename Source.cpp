//Becca Daniel
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include "Bank.h"

using namespace std;

//Setting the initial deposit amount
void Bank::SetFirstDeposit(double deposit) {
	total = deposit;
}
//Setting the monthly deposit amount
void Bank::SetMonthlyDeposit(double monthly) {
	reoccuringDeposit = monthly;
}
//Setting the interest rate
void Bank::SetRate(double interest) {
	yearlyInterest = interest;
}
//Setting the number of years
void Bank::SetYears(int years) {
	totalYears = years;
}
//Getting the initial deposit amount
double Bank::GetFirstDeposit() const {
	return total;
}
//Getting the monthly deposit amount
double Bank::GetMonthlyDeposit() const {
	return reoccuringDeposit;
}
//Getting the interest rate
double Bank::GetRate() const {
	return yearlyInterest;
}
//Getting the number of years
int Bank::GetYears() const {
	return totalYears;
}
//Code to calculate results without a monthly deposit
double Bank::NoMonthlyDeposit(double deposit, double interest, int years) {
	total = deposit;

	const int lineWidth = 80;

	cout << setw(lineWidth) << setfill('~') << " " << setfill(' ') << endl;
	cout << "         Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << setw(lineWidth) << setfill('~') << " " << setfill(' ') << endl;
	cout << setw(5) << left << "Year     "
		<< setw(30) << right << "        Year End Balance     " 
		<< setw(30) << right << "        Year End Earned Interest" << endl;
	cout << setw(lineWidth) << setfill('~') << " " << setfill(' ') << endl;

	for (int i = 0; i < years; ++i) {
		totalInterest = total * (interest / 100.0);
		total += totalInterest;
		cout << setw(5) << left << (i + 1)
			<< setw(30) << right << "$" << fixed << setprecision(2) << total
			<< setw(30) << right << "$" << fixed << setprecision(2) << totalInterest
			<< endl;
	}
	return total;
}
//Code to calculate results with a monthly deposit
double Bank::YesMonthlyDeposit(double deposit, double monthly, double interest, int years) {
	total = deposit;

	const int lineWidth = 80;

	cout << setw(lineWidth) << setfill('~') << " " << setfill(' ') << endl;
	cout << "         Balance and Interest With Additional Monthly Deposits" << endl;
	cout << setw(lineWidth) << setfill('~') << " " << setfill(' ') << endl;
	cout << setw(5) << left << "Year     "
		<< setw(30) << right << "        Year End Balance     "
		<< setw(30) << right << "        Year End Earned Interest" << endl;
	cout << setw(lineWidth) << setfill('~') << " " << setfill(' ') << endl;

	for (int i = 0; i < years; ++i) {
		yearlyInterest = 0;

		for (int month = 0; month < 12; ++month) {
			double monthlyInterest = (total + reoccuringDeposit) * (interest / 100.0 / 12.0);
			yearlyInterest += monthlyInterest;
			total += reoccuringDeposit + monthlyInterest;
		}
		cout << setw(5) << left << (i + 1)
			<< setw(30) << right << "$" << fixed << setprecision(2) << total
			<< setw(30) << right << "$" << fixed << setprecision(2) << yearlyInterest
			<< endl;
	}
	return total;
}
//This starts the main program that the user sees/interacts with
void Bank::process() {
	double deposit, monthly, rate;
	int years;
	string reDo;

	do {

		cout << "What will your initial deposit be? ";
		cin >> deposit;
		while (deposit < 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Your input was invalid. Please try again with a positive number." << endl;
			cin >> deposit;
		}
		SetFirstDeposit(deposit);


		cout << "What will your monthly deposit be? ";
		cin >> monthly;
		while (monthly < 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Your input was invalid. Please try again with a positive number." << endl;
			cin >> monthly;
		}
		SetMonthlyDeposit(monthly);


		cout << "What is the annual interest? ";
		cin >> rate;
		while (rate < 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Your input was invalid. Please try again with a positive number." << endl;
			cin >> rate;
		}
		SetRate(rate);


		cout << "How many years do you plan on investing? ";
		cin >> years;
		while (years < 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Your input was invalid. Please try again with a positive number." << endl;
			cin >> years;
		}
		SetYears(years);

		cout << setw(50) << setfill('~') << "" << setfill(' ') << endl;
		cout << setw(20) << setfill(' ') << "" << "Data Input" << setw(20) << setfill(' ') << "" << endl;
		cout << setw(50) << setfill('~') << "" << setfill(' ') << endl;
		cout << "Initial Deposit: $" << fixed << setprecision(2) << deposit << endl;
		cout << "Monthly Deposit: $" << fixed << setprecision(2) << monthly << endl;
		cout << "Annual Interest Rate: " << fixed << setprecision(2) << rate << "%" << endl;
		cout << "Number of Years: " << years << endl;
		//This part determines the output depending on if there was a monthly deposit or not
		double final;
		if (monthly == 0) {
			 final = NoMonthlyDeposit(deposit, rate, years);
		}
		else {
			final = YesMonthlyDeposit(deposit, monthly, rate, years);
		}
		cout << "Press Enter to continue...." << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get();

		//This is asking the user if they want to start over
		cout << "Would you like to start over? Yes or No: ";
		cin >> reDo;
		while (reDo != "yes" && reDo != "Yes" && reDo != "no" && reDo != "No") {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Hm, that doesn't seem right. Please answer with yes or no.";
			cin >> reDo;
		}
	} while (reDo == "yes" || reDo == "Yes");
		}