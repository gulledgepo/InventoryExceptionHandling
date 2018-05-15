//Paxston Gulledge
//PRG422 - Week 4 Final Project
//The header file defining out our class setting up our variables and functions
#include "stdafx.h"
#include "Inventory.h"
#include <iostream> 
#include <string> 
using namespace std;

//Generic call
Inventory::Inventory()
{
	stockNumber = 0;
	quantity = 0;
	price = 0;
}

//Specific call
Inventory::Inventory(int number, int inStock, float rate)
{
	stockNumber = number;
	quantity = inStock;
	price = rate;
}

//Sets the stock number of an inventory object
void Inventory::SetStockNumber(int number)
{
	stockNumber = number;
}

//Sets the quantity of an inventory object
void Inventory::SetQuantity(int inStock)
{
	quantity = inStock;
}

//Sets the price of an inventory object
void Inventory::SetPrice(float rate)
{
	price = rate;
}

//Shows the stock number, quantity, and price of an object.
void Inventory::ShowItem()
{
	cout << endl;
	cout << "Item Inventory information:" << endl;
	cout << "Stock number dialed: " << stockNumber << endl;
	cout << "Quantity: " << quantity << endl;
	cout << "Price per item: " << price << endl;
}

//Overloaded cout << to show details of the object
ostream& operator<<(ostream& out, const Inventory& aItem)
{
	out << "Item number " << aItem.stockNumber << " has " << aItem.quantity << " units in stock at a price of $" << aItem.price << " per unit." << endl;
	return out;
}

//Overloaded cin<< to get the parameters of the object
istream& operator>>(istream& in, Inventory& aItem)
{
	cout << endl; //to clear
	cout << "Enter the item's stock number:";
	in >> aItem.stockNumber;
	cout << "Enter the quantity of the item:";
	in >> aItem.quantity;
	cout << "Enter the price per unit of the item:";
	in >> aItem.price;
	cout << endl;
	return in;
}

