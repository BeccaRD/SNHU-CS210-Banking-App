//Becca Daniel
#pragma once
#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED
//Defining a class, which I chose to call Bank
class Bank {
public: //Setting the initial variables
	void SetFirstDeposit(double deposit);
	void SetMonthlyDeposit(double monthly);
	void SetRate(double interest);
	void SetYears(int years);

	//Getting the user input variables
	double GetFirstDeposit() const;
	double GetMonthlyDeposit() const;
	double GetRate() const;
	int GetYears() const;
	
	//Main function
	void process();
	//Calculates the results with or without a monthly deposit
	double NoMonthlyDeposit(double deposit, double interest, int years); 
	double YesMonthlyDeposit(double deposit, double monthly, double interest, int years);

private:
	double total{ 0.0 }; //Total balance
	int totalYears{ 0 }; //Total amount of years
	double reoccuringDeposit{ 0.0 }; //Monthly deposit amount
	double yearlyInterest{ 0.0 }; //Annual interest rate
	double totalInterest{ 0.0 }; //Total interest earned
};
#endif