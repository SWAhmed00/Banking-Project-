// Author:        Syed Wajih Ahmed  
// Course:        CS1337.009
// Date started:  3/27/2019 
// Assignment:    Assignment 5
// Compiler:      Visual Studios 2018
//This program uses classes and pointes to objects to keep track of bank accounts. The program allows one to 
//create a savings checkings or normal bank account.One can then withdraw or deposit to that account. 
//The user can also request to have all the accounts displayed to them. We will use functions to 
//accomplish all of the menu choices that will allow the user to compete the tasks stated above along with using 
//a base class and two derived classess


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cctype>


using namespace std;
#include "Bank.h"
//prototyping functions
bool checkAccNumb(Bank *pointer[], string acc, int size);
void depositMoney(Bank * ptr[], string acc, double amount, int size);
void withdrawMoney(Bank * ptr[], string acc, double amount, int size);
void displayAccountInfo(Bank object);

int main()
{
   Bank *pointer[100];//holds all the objects
   int choice;//holds users menu choice
   int  counter = 0;//counts the number of objects created
   string accNumb;//hold account number
   string name;//holds name
   double bal;//holds balance
   bool exists;//flag to see if account number exists
   double amount;//holds money depositing or wirhdrawing

   cout << fixed << setprecision(2);
 

   //do while loop for menu
   do
   {
      cout << "1.Create a Savings account     " << endl;
      cout << "2.Create a Checkings account   " << endl;
      cout << "3.Create a normal Bank account " << endl;
      cout << "4.Deposit money into an account" << endl;
      cout << "5.Withdraw from an account     " << endl;
      cout << "6.Display info for all accounts" << endl;
      cout << "7.EXIT THE PROGRAM             " << endl;
      cin >> choice;
      //if they chose 1, create a savings account object
      if (choice == 1)
      {
         //do while loop to get a valid account number
         do
         {
            cout << "Please enter a  valid account number " << endl;
            cin >> accNumb;
            exists=checkAccNumb(pointer,accNumb,counter);
         } //end of do while loop
         while ((accNumb == "") && (!exists));
         //do while loop to get a valid account name
         do
         {
            cout << "Please enter a name for the account " << endl;
            cin >> name;
         }//end of do while loop 
         while (name == "");
         //do while loop to get a valid balance
         do
         {
            cout << "Please enter a valid balance" << endl;
            cin >> bal;
         }//end of do while loop
         while (bal<0);
      
         //creating a new object with valid info
         pointer[counter] = new Savings(accNumb,name,bal);
         counter++;
         
      }//end of if statemnt

      //if they chose choice 2 we create a checkings account
      else if (choice == 2)
      {
         //do while loop to get a valid account number
         do
         {
            cout << "Please enter a  valid account number " << endl;
            cin >> accNumb;
           exists= checkAccNumb(pointer, accNumb, counter);
         }//end of do while loop 
         while ((accNumb == "") && (!exists));
         //do while loop to get a valid account name
         do
         {
            cout << "Please enter a name for the account " << endl;
            cin >> name;
         }//end of do while loop
         while (name == "");
         //do while loop to get a valid balance
         do
         {
            cout << "Please enter a valid balance" << endl;
            cin >> bal;
         }//end of do while loop 
         while (bal < 0);
         
        
         
         //creating a new object
         pointer[counter] = new Checking(accNumb, name, bal);
         counter++;

      }//end of else if statement
      //if they choise 3 we create a bank object
      else if (choice == 3)
      {
         pointer[counter] = new Bank();
         counter++;
      }//end of else if statement
      //if they chose 4 we try to deposit the amount into their account
      else if (choice == 4)
      {
         cout << "Please enter a account number and the amount of money to deposit" << endl;
         cin >> accNumb >> amount;
         //makes sure amount is positive
         if (amount > 0)
         {
            //calls function to proccess the amount and account number
            depositMoney(pointer, accNumb, amount, counter);
         }//end of if statement

         //else show them an eror message
         else 
         {
            cout << "invalid amount of money entered" << endl;
         }//end of else statement

      }//end of else if statement

      //if they chose 5 we try to withdraw money from their account
      else if (choice == 5)
      {
         cout << "Please enter a account number and the amount of money to withdraw" << endl;
         cin >> accNumb >> amount;
         //makes sure amount is positive
         if (amount > 0)
         {
            //function to process the withdrawl
            withdrawMoney(pointer, accNumb, amount, counter);
         }//end of if statement

         //else show thema an eror message
         else
         {
            cout << "invalid amount of money entered" << endl;
         }//end of else statement

      }//end of else if statement

      //if they enter 6 we display all the accounts
      else if (choice == 6)
      {
         //for loop to output all the accounts that exist
         for (int count = 0; count < counter; count++)
         {
           
            //function that will display current objects informaton
            displayAccountInfo(*pointer[count]);
         }//end of for loop
      }//end of else if statement

      //else eror message and tell them to put a valid choice if it isnt 7
      else if (choice != 7)
      {
         cout << "Please enter a valid menu choice" << endl;
      }//end of else if statement
   }//end of do while loop 
   while (choice != 7);


   system("pause");
   return 0;
}//end of main function
/**************************************************************************
 *Function to check and see if the user enterd account number is already 
 *in use by another account or not.boolean true or false is returned
***************************************************************************/
bool checkAccNumb(Bank *pointer[],string acc,int size)
{
   cout << fixed << setprecision(2);
   bool found=false;//flag to see if account number is found
   string secondAcc;//string to comapre the account number being tested against
   int counter = 0;//counter
   //if another objec exists we check the account number
   if (size >= 1)
   {
      //while loop that runs until the account number is found or all the objects have been looked at
      while (!found && (counter < size))
      {
         //if we find a matching account number we change flag to true and send eror message
         secondAcc = pointer[counter]->getAccountNumber();
         if (acc == secondAcc)
         {
            found = true;
            cout << "Account number is in use" << endl;
         }//end of if statement

         //else we increment the counter
         else
         {
            counter++;
         }//end of else statement

      }//end of while loop
     
   }//end of if statement

   return found;
}//end of checkAccNumber function

/**************************************************************************
 *Function to deposit money to a certain account after making sure the
 *account number exists.nothing is returned
***************************************************************************/

void depositMoney(Bank * ptr[],string acc,double amount,int size)
{
   cout << fixed << setprecision(2);
   bool found = false;//flag to see if account number exists
   string secondAcc;//string to hold account number we will be testing against
   int counter = 0;//counter
   double newBal;//holds the new variable
   
      //while loop will run until account number is found or all objects
      //have been inspected
      while (!found && (counter < size))
      {
         //if we find a matching account number we change flag to true and add the money 
         //and display the new balance
         secondAcc = ptr[counter]->getAccountNumber();
         if (acc == secondAcc)
         {
            found = true;
            newBal = ptr[counter]->deposit(amount);
            cout << "New Balance is: $" << newBal << endl;
         }//end of if statement

         //else we increment the counter
         else
         {
            counter++;
         }//end of else statement

      }//end of while loop

      //if we dont find it we tell them they had the wrong account number
      if (!found)
      {
         cout << "Invalid Account Number!" << endl;
      }//end of if statement



}//end of depositMoney function

/**************************************************************************
 *Function to withdraw money from a certain account after making sure the 
 *account number exists.nothing is returned
***************************************************************************/

void withdrawMoney(Bank * ptr[], string acc, double amount, int size)
{
   bool found = false;//falg to see if account number is found
   string secondAcc;//string to hold account number we will be testing against
   int counter = 0;//counter
   string newBal;//string to hold the new balance
   cout << fixed << setprecision(2);
   //while loop will run until account number is found or all objects have been inspected
   while (!found && (counter < size))
   {
      //if we find a matching account number we change flag to true
      //and call the withdraw function to try and pull the money out of the account
      //and then display their new balance
      secondAcc = ptr[counter]->getAccountNumber();
      if (acc == secondAcc)
      {
         found = true;
         newBal = ptr[counter]->withdraw(amount);
         cout <<newBal << endl;
      }//end of if statement

      //else we increment the counter
      else
      {
         counter++;
      }//end of else statement

   }//end of while loop

   //if not found we show an eror message
   if (!found)
   {
      cout << "Invalid Account Number!" << endl;
   }//end of if statement



}//end of depositMoney function


/**************************************************************************
 *Function to display  all the bank accounts 
 *nothing is returned
***************************************************************************/

void displayAccountInfo(Bank object)
{
   cout << fixed << setprecision(2);
   string acc;//holds account number
   string name;//holds name of account holder
   double bal;//holds balance
   string specFieldOne;//holds min balance OR interest rate depending on type of account
   string specFieldTwo;//holds fee OR compound time depending on type of account

   //getting all the information for the account
   acc = object.getAccountNumber();
   name = object.getName();
   bal = object.getBalance();
   specFieldOne = object.interestOrMin();
   specFieldTwo = object.timeOrFee();
   
   //displayint the information to the user
   cout << "Account Number: " << acc << endl;
   cout << "Name:  " << name << endl;
   cout << "Balance:   $" << bal << endl;
   cout << specFieldOne << endl;
   cout << specFieldTwo << endl;

}//end of displayAccountInfo function