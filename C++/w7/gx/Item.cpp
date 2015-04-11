//Item.cpp
//
#include <iostream>
#include <iomanip>
#include "Item.h"

using namespace std;

Item::Item(){num = 0; price = 0;}
Item::Item(int n, double p){num = n; price = p;}
bool Item::empty() const{
	if(num == 0 && price == 0)
		return true;
	else
		return false;
}
void Item::operator=(double p){price = p;}
void Item::display(std::ostream & os) const {
	os << setw(8) << left<<num;
	os <<setw(10) << right << fixed <<setprecision (2) << price;
}




std::istream & operator >> (std::istream & is, Item & i){
	int a;
	double b;
	
	cout<<"Item Number : ";
	is >> a;
	cout <<"price      : ";
	is >> b;
	if(a>0 && b>0)
		{Item x(a,b);i=x;}
	else
		{Item x;i=x;}
		

}

std::ostream & operator << (std::ostream & os, const Item & i){
	i.display(os);
}

