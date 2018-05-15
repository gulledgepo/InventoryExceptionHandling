//Paxston Gulledge
//PRG422 - Week 4 Final Project
//The header file declaring our class setting up our variables and functions
#include <iostream>
#include <string>
using namespace std;
#pragma once
class Inventory
{
public:
	friend ostream& operator<<(ostream&, const Inventory&);
	friend istream& operator>>(istream&, Inventory&);
public:
	Inventory();
	Inventory(int, int, float);
	void SetStockNumber(int);
	void SetQuantity(int);
	void SetPrice(float);
	void ShowItem();
	int stockNumber;
	int quantity;
	double price;

};

