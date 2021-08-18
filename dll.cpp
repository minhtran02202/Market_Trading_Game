//Minh Tran
//07/29/2021
//This is where the double linked list
//functions are declared. It has remove all,
//insert, remove one node and display all

#include "game.h"

//Constructor
list::list(): tail(nullptr), head(nullptr), length(0)
{
}

//Destructor
list::~list()
{
	remove_all();
}

//remove all data
int list::remove_all()
{
	return remove_all(head);
	//remove_tail(tail);
}

int list::remove_all(node *& head)
{
	//Recursively remove all nodes
	if(!head) return 0;
	remove_all(head->get_next());
	delete head;
	head = nullptr;
	return 1;
}

//add data to dll
void list::insert(cil * c)
{
	//Update length of the list
	++ length;

	//Create list if list is empty
	if(!head){
		head = new node(c, length);
		tail = head;
		tail->get_next() = nullptr;
		tail->get_previous() = nullptr;
	}

	//Add node at the end of the list
	else{
		node * temp = tail;
		tail->get_next() = new node(c, length);
		tail = tail->get_next();
		tail->set_previous(temp);
		tail->get_next() = nullptr;
	}
}

//display all data
int list::display()
{
	if(!head) return 0;
	return display_head(head);
}

int list::display_head(node * head)
{
	//Display data recursively
	if(!head) return 1;
	head->display();
	return display_head(head->get_next());
}

//remove and retrieve the last data
int list::remove(cil *& play, int location)
{
	if(location==0 || length<location) return 0;

	//if(length - location < location) 
		//remove_from_tail(tail, play, location);

	remove_from_head(head, play, location);
	--length;
	return 1;

}

//Remove by tail traversing
int list::remove_from_tail(node *& tail, cil *& play, int location)
{
	//exit if list is empty
	if(!tail) return 0;

	//When traversed to the right node
	if(tail->retrieve(play, location) == 1){
		node * temp = tail;

		//If there is only one node in the list
		if(!tail->get_previous() && !tail->get_next()){
			cout<<"Here?"<<endl;
			delete tail; head = tail = nullptr;
			return 1;
		}
		
		//if temp->previous exist	
		if(temp->get_previous()){
			temp->get_previous()->set_next(temp->get_next());
			tail = temp->get_previous();
			delete temp;
		}

		//if temp->next exist
		if(temp->get_next()){
			//if we are at head
			if(!temp->get_previous()){
				temp->get_next()->get_previous()=nullptr;
				delete tail; tail=nullptr;
			}

			//if there is data at temp->previous
			else{
				temp->get_next()->set_previous(temp->get_previous());
				tail = temp->get_next();
				delete temp;
			}
		}
		return 1;
	}

	//Recursively move to previous node if not match
	return remove_from_tail(head->get_previous(), play, location);
}

//Remove by head traversing
int list::remove_from_head(node *& head, cil *& play, int location)
{
	//exit if list is empty
	if(!head) return 0;

	//When traversed to the right node
	if(head->retrieve(play, location) == 1){
		node * temp = head;

		//If only one node in the list
		if(!head->get_previous() && !head->get_next()){
			cout<<"Here?"<<endl;
			delete head; head = tail = nullptr;
			return 1;
		}
		
		//if temp->previous exist
		if(temp->get_previous()){
			
			//if we are at tail
			if(!temp->get_next()) {
				temp->get_previous()->get_next()=nullptr;
				delete head;
				head = nullptr;
			}

			//if we are not at tail
			else {
				temp->get_previous()->set_next(temp->get_next());
				head = temp->get_previous();
				delete temp;
			}
		}
		
		//if temp->next exist
		if(temp->get_next()){
				temp->get_next()->set_previous(temp->get_previous());
				head = temp->get_next();
				delete temp;
		}
		return 1;
	}
	
	//Recursively move to next node if not match
	return remove_from_head(head->get_next(), play, location);
}

