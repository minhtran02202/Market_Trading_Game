//Minh Tran
//07/29/2021
//This is where the node functions declared.
//Node is used to hook a cil data to the dll

#include "game.h"

//Constructor and add cil data
node::node(cil * c, int len): next(nullptr), previous(nullptr)
{
	//know location of node
	location = len;

	//Downcasting to add cil to node
	metro * m = dynamic_cast<metro *>(c);
	agri * a= dynamic_cast<agri *>(c);
	ind * i = dynamic_cast<ind *>(c);

	if(m)
		head = new metro(*m);
	else if(a)
		head = new agri(*a);
	else if(i)
		head = new ind(*i);
}

//Destructor
node::~node()
{
	if(head) delete head;
	head=nullptr;
}

//Display cil data
int node::display()
{
	if(!head) return 0;
	cout<<"This stats location is "<<location;
	return head->display();
}

//Retrieve cil data to play pointer
int node::retrieve(cil *& play, int save_lo)
{
	//exit if player's input of location is not correct
	if(save_lo != location) return 0;

	//if node has a cil data
	if(head){

		//Downcasting to copy data to play pointer
		metro * m = dynamic_cast<metro *>(head);
		agri * a= dynamic_cast<agri *>(head);
		ind * i = dynamic_cast<ind *>(head);

		if(m)
			play = new metro(*m);
		else if(a)
			play = new agri(*a);
		else if(i)
			play = new ind(*i);
		return 1;
	}
	return 0;
}

//Next and previous pointers and setters
node *& node::get_next(){return next;}
void node::set_next(node *& set){next = set;}
node *& node::get_previous(){return previous;}
void node::set_previous(node *& set){previous = set;}

