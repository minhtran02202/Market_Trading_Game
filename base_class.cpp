//Minh Tran
//07/29/2021
//This is where the base class functions declared

#include "game.h"

//Constructor with rng
cil::cil(): specialty(nullptr), need(nullptr), trade_rate(0)
{
	balance = (rand() % 5 + 1) * 1000;
	inventory = (rand() % 3 + 1) * 1000;
}

//Copy constructor
cil::cil(const cil & src)
{
	//Copy data from src
	if(src.specialty){
		specialty = new char[strlen(src.specialty)+1];
		strcpy(specialty, src.specialty);
	}
	if(src.need){
		need = new char[strlen(src.need)+1];
		strcpy(need, src.need);
	}

	balance = src.balance;
	inventory = src.inventory;
	trade_rate = src.trade_rate;

}

//Destructor
cil::~cil()
{
	if(specialty) delete[]specialty;
	if(need) delete[]need;
	need = nullptr;
	specialty = nullptr;
}

int cil::decide(){return 0;};
int cil::update_balance(){return 0;};

//Check if player wins
int cil::check()
{
	if(balance >= 10000) return 1;
	return 0;
}

//Buy and sell
int cil::trade_buy(cil * partner, int num)
{
	//Total cost of the trade
	int cost = trade_rate * num;

	//Exit if balance don't have enough
	if(balance<cost) return 0;

	//Exit if parter don't have enough items 
	//to sell. Else, partner sell.
	if(partner->sell(num) == 0) return 0;;

	//You buy
	balance -= cost;
	inventory += num;

	//Increase trade_rate by num of items you buy	
	if(num<20) trade_rate += 0.2;
	else if(num<35) trade_rate += 0.4;
	else trade_rate += 0.8;

	return 1;
}

//Sell and buy
int cil::trade_sell(cil * partner, int num)
{
	//Exit if you don't have enough items
	if(inventory<num) return 0;

	//Exit if parter don't have enough monney
	//Else, they buy
	if(partner->buy(num)==0) return 0;

	//You sell
	
	//Total amount to be paid
	int paid = trade_rate * num;
	//Decrease inventory and update balance
	inventory -= num;
	balance += paid;
	return 1;
}

//Partner buy
int cil::buy(int num)
{
	//Find total cost of trade
	int cost = trade_rate * num;
	//Exit if don't have enough
	if(balance<cost) return 0;

	//Update balance and inventory
	balance -= cost;
	inventory += num;

	return 1;
}

//Partner sell
int cil::sell(int num)
{
	//Exit if inventory not enough
	if(inventory<num) return 0;

	//Find total to be paid
	int paid = trade_rate * num;

	//Update balance and inventory
	inventory -= num;
	balance += paid;
	return 1;
}

//Display data
int cil::display()
{
	cout<<'\n';
	if(specialty) cout<<"This cilvilization specialty is: "<<specialty<<endl;
	if(need) cout<<"This cilvilization need: "<<need<<endl;

	cout<<"Money balance is: "<<balance<<endl;
	cout<<"Inventory is: "<<inventory<<endl;
	if(specialty)
		cout<<"Trade rate is: "<<trade_rate<<" dollar"<<'/'<<specialty<<endl;

	cout<<'\n';
	return 1;
}
