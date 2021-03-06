//Paxston Gulledge
//PRG422 - Week 4 Final Project
//Demonstrates the catching and handling of exceptions in different scenarios
#include "stdafx.h"
#include<iostream>
#include<string>
#include<conio.h>
#include "Inventory.h"
using namespace std;

//Max items for inventory
//This is to easily change the number of the array for testing purposes without having to
//change every for loop
const int maxItems = 3;

int main()
{
	Inventory items[maxItems];
	exception exceptionA;
	bool exceptions[3] = { 0, 0, 0 };
	int currentItem = 0;
	//Part 1. If Stock is less than 0 or greater than 999, or quantity is less than 0, or price is greater than 100, we want to set all fields
	//for that object to 0. We get the info, check it, and then throw an exception if so
	
	for (int i = 0; i < maxItems; i++)
	{
		try
		{
			//Get the object
			cin >> items[i];
			//Check the conditions
			if ((items[i].stockNumber < 0 || items[i].stockNumber > 999) || (items[i].quantity < 0) || (items[i].price > 100.00))
			{
				//If any are true, we throw to exceptionA
				throw exceptionA;
			}
		}
		//exceptionA sets all the fields to 0
		catch (exception exceptionA)
		{
			items[i].stockNumber = 0;
			items[i].quantity = 0;
			items[i].price = 0;
		}
	}
	//After we have done this we display the objects
	for (int i = 0; i < maxItems; i++)
	{
		cout << items[i];
	}

	

	//---------------------------------------------------------------------------------------------------------------------------------------------
	
	//Part 2. If stock is less than 0 or greater than 999, we ask the user to re-enter it. If the price is greater than 100 then we set it to 99.99
	//We need to check for both of them to make the adjustments, so we utilize a bool array to set the different conditions to true
	//If either condition is true at the end of checking then we throw the exception for that object
	for (int i = 0; i < maxItems; i++)
	{
		exceptions[0] = false;
		exceptions[1] = false;
		try
		{
			//Get the object
			cin >> items[i];
			//Check the stock number
			if (items[i].stockNumber < 0 || items[i].stockNumber > 999)
			{
				//exceptions0 will ask them to reenter the stock number
				exceptions[0] = true;
			}
			//Check the price
			if (items[i].price > 100)
			{
				//exceptions1 will set the price to 99.99
				exceptions[1] = true;
			}
			//If either exception is true we throw to exceptionA
			if (exceptions[0] || exceptions[1])
				throw exceptionA;
		}
		catch (exception exceptionA)
		{
			if (exceptions[0] == true) 
			{
				cout << endl << "Please enter an appropriate stock number:" << endl;
				cin >> items[i].stockNumber;
			} 
			if (exceptions[1] == true)
			{
				items[i].price = 99.99;
			}
		}
	}

	//After we have done this we display the objects
	for (int i = 0; i < maxItems; i++)
	{
		cout << items[i];
	}

	//---------------------------------------------------------------------------------------------------------------------------------------------

	//Part 3 If we have an invalid stock number we set it to 999, otherwise we do nothing else
	for (int i = 0; i < maxItems; i++)
	{
		try
		{
			//Get the object
			cin >> items[i];
			//Check the stock number
			if (items[i].stockNumber < 0 || items[i].stockNumber > 999)
			{
				//If wrong then we throw exceptionA
				throw exceptionA;
			}
		}
		//if exception is thrown we set the stockNumber to 999
		catch (exception exceptionA)
		{
			items[i].stockNumber = 999;
		}
	}

	//After we have done this we display the objects
	for (int i = 0; i < maxItems; i++)
	{
		cout << items[i];
	}

	//---------------------------------------------------------------------------------------------------------------------------------------------

	
	//Part 4. If any of the errors are caught, improper stock number, quantity, or price, we stop accepting data and display what we have
	//We also clear exceptions[0] in case it was previously set to false, while it is false we assume we have no errors, and when we detect 1
	//we set it to true and no further information is accepted
	
	exceptions[0] = false;
	for (int i = 0; i < maxItems; i++)
	{
		if (!exceptions[0])
		{
			try
			{
				//Get the object
				cin >> items[i];
				//Check the conditions
				if ((items[i].stockNumber < 0 || items[i].stockNumber > 999) || (items[i].quantity < 0) || (items[i].price > 100.00))
				{
					//If any are true, we throw to exceptionA
					exceptions[0] = true;
					//Set the current item to one less than I, because the current I is incorrect and we dont want to show
					currentItem = i-1;
					throw exceptionA;
				}
			}
			//exceptionA reports an error was detected and no more data will be collected
			catch (exception exceptionA)
			{
				cout << endl << "Incorrect data entered. No more data will be allowed to be entered." << endl << endl;
			}
		
		}
	}

	//After we have done this we display the objects
	//We only go to currentItem, because we only want correct items entered.
	for (int i = 0; i <= currentItem; i++)
	{
		cout << items[i];
	}
	


	// Force the console to stay open until a key is pressed
	cout << endl;
	system("pause");
	return 0;
}