

#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cctype>


using namespace std;

#include "Bank.h"

Bank::Bank()
{
   accountNumber = "9999";
   name = "";
   balance = 0.0;
}//end of constructor

Bank::Bank(string acc, string user, double bal)
{
   accountNumber = acc;
   name = user;
   balance = bal;
}//end of constructor

string Bank::interestOrMin()
{
   string output = "";
   //if account is checkings we get the min bal
   if (account == 'c')
   {
      output = "Minimum balance required is:$";
      output += to_string(specFieldOne);
      
   }//end of if statement
   //else if its savings we get the interest rate
   else if (account == 's')
   {
      output = "Interest Rate is: ";
      output += to_string(specFieldOne);
   }//end of else if statement
   return output;
}//end of function

string Bank::timeOrFee()
{
   string output = "";
   //if account is checkings we get the fee
   if (account == 'c')
   {
      output = "Monthly fee is:$";
      output += to_string(specFieldTwo);
   }//end of if statement
   //else if its savings we get the compounded time
   else if (account == 's')
   {
      int time = specFieldTwo;
      output = "Compounded time is: ";
      output += to_string(time);
   }//end of else if statement
   return output;
}//end of function



string Bank::withdraw(double money)
{
   string leftOver;
   //if balance is big enough we withdraw and show new balance
   if (balance >= money)
   {
      balance -= money;
      leftOver = "The remainin balance is:$";
      leftOver+= to_string(balance);
   }//end of if statement

   //else we send them an eror message
   else
   {
      leftOver = "Insufficent funds for withdrawl!";
   }//end of else statement

   return leftOver;
}//end of withdraw function

double Bank::deposit(double money)
{
   balance += money;
   return balance;
}//end of deposit function

void Bank::setName(string newName)
{
   name = newName;
}//end of setName function
void Bank::setBalance(double newBalance)
{
   balance = newBalance;
}//end of setBalance function
void Bank::setAccountNumber(string newAcc)
{
   accountNumber = newAcc;
}//end of setAccountNumber function
string Bank::getAccountNumber()
{
   return accountNumber;
}//end of getAccount Number function

string Bank::getName()
{
   return name;
}//end of getname function
double Bank::getBalance()
{
   return balance;
}//end of getBalance function

Bank::~Bank()
{
}//end of deconstructor



//DERIVED CLASS FUNCTIONS

Savings::Savings()
{

}//end of constructor
Savings::Savings (string acc,string user,double bal)
{
   accountNumber = acc;
   name = user;
   balance = bal;
   interestRate = .01;
   compoundTime = 365;
   specFieldOne = interestRate;
   specFieldTwo = compoundTime;
   account = 's';

}//end of constructor


void Savings::setInterestRate(double interest)
{
   interestRate = interest;
}//end of interestRate function

void Savings::setCompundTime(int days)
{
   compoundTime = days;
}//end of setCompundTime functions

double Savings::getInterestRate()
{
   return interestRate;
}//end of getInterest Function
int Savings::getCompoundTime()
{
   return compoundTime;
}//end of compoundTIme function
double Savings::addInterest(int days)
{
   //calculating the interest compounded over time
   double amount;
   amount = balance *((interestRate / compoundTime) *days);
   balance += amount;
   return amount;
}//end of addInterest function
Savings::~Savings()
{
}//end of deconstructor

//NEXT DERIVED CLASS FUNCTIONS

Checking::Checking()
{

}//end of constructor
Checking::Checking(string acc, string user, double bal)
{
   accountNumber = acc;
   name = user;
   balance = bal;
   minBal = 10;
   fee = 5;
   specFieldOne = minBal;
   specFieldTwo = fee;
   account = 'c';

}//end of constructor


void Checking :: setMinBal(double min)
{
   minBal = min;
}//end of setMinBal function
void Checking::setFee(double charge)
{
   fee = charge;
}//end of setFee function
double Checking::getMinBal()
{
   return minBal;
}//end of getMinBal function
double Checking::getFee()
{
   return fee;
}//end of getFee function
Checking::~Checking()
{
}//end of deconstructor



