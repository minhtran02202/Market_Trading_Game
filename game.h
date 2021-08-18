//Minh Tran
//07/29/2021
//This file contain the inilizations of the 3 
//civilizations, the node and dll
//
//Each civilization has a money balance,
//their specialty of production
//inventory to store their products
//what they need to keep producing
//and their currency trade exchange rate
//
//Each also has a factor that will affect their 
//production rate from climate, intelligence, and air quaility

#include <iostream>
#include <cctype>
#include <cstring>
#include <ctime>
#include <cstdlib>

using namespace std;

//Constants
const int MAX = 100;

//Base class
class cil{
	public:

//make a main to test the 3 cils and add comments
		cil();
		cil(const cil &);
		~cil(); 	

		//virtual functions
		virtual int decide();
		virtual int display();
		virtual int update_balance();

		//You buy, comp sell
		int trade_buy(cil * partner, int num_to_buy);
		//comp buy, you sell
		int trade_sell(cil * partner, int num_to_sell);
		//Check if player wins 
		int check();

	protected:
		//Use in trade_s functions
		int buy(int num);
		int sell(int num);
		//This is my currency. How much money the cil have
		int balance;
		//How much goods/services available to trade
		int inventory;
		//Use in trades (dollars/goods)
		float trade_rate;
		//What the cil produce
		char * specialty;
		//What the cil buy
		char * need;

};

//3 civilizations
class metro: public cil{
	public:
		metro();
		metro(const metro &);
		
		//User choose cil average IQ
		int decide();
		//Display all data
		int display();
		//Add money balance and inventory if user skip turn
		int update_balance();

	private:
		int iq;
};

class agri: public cil{
	public:
		agri();
		agri(const agri &);
		
		//User choose cil average temperature
		int decide();
		//Display all data
		int display();
		//Add money balance and inventory if user skip turn
		int update_balance();

	private:
		int temp;
};

class ind: public cil{
	public:
		ind();
		ind(const ind &);

		//User choose cil average Air Quality Index
		int decide();
		//Display all data
		int display();
		//Add money balance and inventory if user skip turn
		int update_balance();

	private:
		int aqi;
};

//Node for dll
class node{
	public:
		//Add cil to node
		node(cil * add, int len);
		//Destructor
		~node();

		//Display cil 
		int display();

		//Remove and retrieve a cil node to user
		int retrieve(cil *& retrieve, int location);

		//Getters and setters
		node *& get_next();
		void set_next(node *& set);
		node *& get_previous();
		void set_previous(node *& set);
	private:
		//Number of saves uptil now
		int location;
		cil * head;
		node * next;
		node * previous;
};

	
//dll
class list{
	public:
		//Constructor and Destructors
		list();
		~list();

		//add data to dll
		void insert(cil * add);
		//remove and retrieve the last data
		int remove(cil *& retrieve, int location);
		//display wrapper
		int display();
		//remove all data
		int remove_all();
	private:
		//Remove a node starting from head or tail
		int remove_from_head(node *& head, cil *& retrieve, int location);
		int remove_from_tail(node *& head, cil *& retrieve, int location);

		//display all data
		int display_head(node * head);
		//The first node of the dll
		int remove_all(node *& head);
		//int remove_tail(cil *& head);
		int length;
		node * head;
		node * tail;
};
