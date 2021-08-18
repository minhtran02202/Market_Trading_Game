//Minh Tran
//07/29/2021
//This is where the 3 civilizations functions declared
//They all have the same functions but each is slightly
//different than the others

#include "game.h"


//Constructor
metro::metro()
{
	//Rng if this is a comp
	iq = (rand() % 120 + 1);

	char temp1[MAX] = "tech";
	char temp2[MAX] = "food";

	//Assign specialty and need
	specialty = new char[strlen(temp1)+1];
	strcpy(specialty, temp1);
	need = new char[strlen(temp2)+1];
	strcpy(need, temp2);

	//Set trade rate base on iq
	if(iq < 85)
		trade_rate = 20;
	else if(iq < 100)
		trade_rate = 40;
	else
		trade_rate = 60;
}

//Copy constructor
metro::metro(const metro & src): cil(src)
{
	iq = src.iq;
}

//User decide IQ
int metro::decide()
{
	cout<<"IQ has significant effect on the production of technology. "<<endl
		<<"which affect the trading rate because of the output of the civilization. "<<endl;
	cout<<"Decide your cilvilization population IQ from 70-120: ";
	cin>>iq; cin.ignore(100,'\n');

	//Set trade rate base on iq
	if(iq < 85)
		trade_rate = 20;
	else if(iq < 100)
		trade_rate = 40;
	else
		trade_rate = 60;
	return 1;
}

//Display all data
int metro::display()
{
	cout<<'\n'<<"Metropolitan"<<endl;
	cout<<"-----------"<<endl;
	return cil::display();
}

//Update balance when user skip turn
int metro::update_balance()
{	
	//Only update if balance below 1000
	if(balance<1000){
		if(iq < 85)
			balance += 1000;
		else if(iq < 100)
			balance += 1500;
		else
			balance += 2000;
	}
	return 1;
}

//--------------------------------------

//Constructor
agri::agri(){
	//Rng if this is a comp
	temp = (rand() % 40 + 1);

	char temp1[MAX] = "food";
	char temp2[MAX] = "equip";

	//Assign specialty and need
	specialty = new char[strlen(temp1)+1];
	strcpy(specialty, temp1);
	need = new char[strlen(temp2)+1];
	strcpy(need, temp2);

	//Set trade rate base on temp
	if(temp < 21)
		trade_rate = 30;
	else if(temp < 35)
		trade_rate = 50;
	else
		trade_rate = 30;
}

//Copy constructor
agri::agri(const agri & src): cil(src)
{
	temp = src.temp;
}

//User decide temperature
int agri::decide()
{
	cout<<"Temperature has significant effect on the production of food. "<<endl
		<<"which affect the trading rate because of the output of the civilization. "<<endl
		<<"Decide your cilvilization average temperature "
		<<"from 0-40 degree C: ";
	cin>>temp; cin.ignore(100, '\n');

	//Set trade rate base on temp
	if(temp < 21)
		trade_rate = 30;
	else if(temp < 35)
		trade_rate = 50;
	else
		trade_rate = 30;
	return 1;
}

//Display all data
int agri::display()
{
	cout<<'\n'<<"Agriculture"<<endl;
	cout<<"-----------"<<endl;
	return cil::display();
}


//Update when user skip turn
int agri::update_balance()
{
	//Only update if balance below 1000
	if(balance<1000){
		if(temp < 21)
			balance += 1000;
		else if(temp < 35)
			balance += 2000;
		else
			balance += 1000;
	}
	return 1;
}
//-----------------------------------------

//Constructor
ind::ind(){
	//rng if this is a comp
	aqi = (rand() % 150 + 1);
	char temp1[MAX] = "equip";
	char temp2[MAX] = "tech";

	//assign specialty and need
	specialty = new char[strlen(temp1)+1];
	strcpy(specialty, temp1);
	need = new char[strlen(temp2)+1];
	strcpy(need, temp2);

	//set trade_rate base on aqi
	if(aqi < 51)
		trade_rate = 60;
	else if(aqi < 101)
		trade_rate = 40;
	else
		trade_rate = 20;
}

//Copy constructor
ind::ind(const ind & src): cil(src)
{
	aqi = src.aqi;
}

//User decide average AQI
int ind::decide()
{
	cout<<"Air quality has significant effect on the workers' health, "<<endl
		<<"which affect the trading rate because of the output of the civilization. "<<endl;
	cout<<"Decide your air quality "
		<<"from 0-150 AQI (Air Quality Index): ";
	cin>>aqi; cin.ignore(100, '\n');

	//Set trade_rate base on aqi
	if(aqi < 51)
		trade_rate = 60;
	else if(aqi < 101)
		trade_rate = 40;
	else
		trade_rate = 20;
	return 1;
}

//Display all data
int ind::display()
{
	cout<<'\n'<<"Industrial"<<endl;
	cout<<"-----------"<<endl;
	return cil::display();
}

//Update when user skip turn
int ind::update_balance()
{
	//only update if balance below 1000
	if(balance<1000){
		if(aqi < 51)
			balance += 2000;
		else if(aqi < 101)
			balance += 1500;
		else
			balance += 1000;
	}
	return 1;
}
