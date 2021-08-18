//Minh Tran
//07/29/2021
//This where the client design the game
//using functions available from the game.h file

#include "game.h"

int main(){
	srand(time(0));

	cil * play, *comp1, *comp2;
	metro m; agri a; ind i;
	list save;

	int turn = 0;
	int load = 0;
	int trade_err=1;
	int end = 0;
	int choice = 0;
	int quit = 0;

	int choice2, choice3, b_s = 0;
	char res;

	//Display instruction
	cout<<"Do you want to see the menu?(Y/N): ";
	cin>>res; cin.ignore(100,'\n');
	if(toupper(res) == 'Y'){
		//display instructions
		cout<<'\n'<<"The objective of this game is to increase your money "
			<<"balance to 10,000 dollars in less than 20 turns. "<<endl;

		cout<<"At the start of the game, choose one of three available civilizations. "<<endl;

		cout<<"You then can buy materials to improve your production process, "
			<<"leading to increasing your trading rate "<<endl
			<<"and sell your product to make money. Through this buying and "
			<<"selling continuosly with the other two civilizations, you "<<endl
			<<"can achieve the 10,000 dollars goal."<<endl;
	}

	//Player choose one of 3 civilizations
	cout<<'\n'<<"Choose your civilization: metropolitan(1), agriculture(2), "<<endl
		<<"industrial(3): ";
	cin>>choice; cin.ignore(100,'\n');

	//if player choose metro
	if(choice == 1){
		play = &m;
		comp1 = &a;
		comp2 = &i;
	}

	//if player choose agriculture
	else if(choice == 2){
		play = &a;
		comp1 = &m;
		comp2 = &i;
	}

	//if player choose industrial
	else if(choice == 3)
	{
		play = &i;
		comp1 = &a;
		comp2 = &m;
	}

	//Player decide average iq, temp, or aqi
	play->decide();

	//Loop to next turn
	do{	
		//Display player info
		cout<<'\n'<<"Here is your civilization info: "<<endl;
		play->display();

		//Display comps info
		cout<<"Here are the computers info: "<<endl;
		comp1->display();
		comp2->display();

		//Counting turns
		++turn;
		cout<<'\n'<<"This is turn "<<turn<<endl;

		//What player can do
		cout<<'\n'<<"Do you want to buy(1), sell(2)? or skip to get updated stats?(3), "<<endl;
		cout<<"load a save(4), or quit(5)?: ";
		cin>>choice2; cin.ignore(100,'\n');

		//loop if trade is not successful
		do{
			
			//If player buy
			if(choice2 == 1){
				cout<<"How much do you want to buy?: "<<endl;
				cin>>b_s; cin.ignore(100,'\n');

				//Buy function
				trade_err = play->trade_buy(comp1, b_s);

				//Retry if not buying successfuly
				if(trade_err==0){
					cout<<"You don't have enough money for that. "
						<<"Please retry."<<endl;

					//Don't count this as a turn
					--turn;
				}
			}


			//If player sell
			else if(choice2 == 2){
				//Enter amount to sell
				cout<<"How much do you want to sell?: "<<endl;
				cin>>b_s; cin.ignore(100,'\n');

				//Sell function
				trade_err = play->trade_sell(comp2, b_s);

				//Retry if not selling successfuly
				if(trade_err==0){
					cout<<"You don't have enough inventory for that. "
						<<"Please retry."<<endl;
					//don't count this turn
					--turn;
				}
			}

			//If player skip turn
			else if(choice2==3){
				//Update balances and inventories
				play->update_balance();
				comp1->update_balance();
				comp2->update_balance();
				cout<<'\n'<<"Balances and inventories updated!"<<endl;
			}

			//If player load a save
			else if(choice2==4){
				int location;
				cout<<'\n'<<"Here are the saves from oldest to newest."<<endl;
				cout<<"-----------------------------------------"<<endl;

				//If the dll don't have any data
				if(save.display()==0){
					cout<<'\n'<<"There is no save currently. Please choose another option"<<endl;
					cout<<"-----------------------"<<endl;
				}

				//Display and ask which saves player want to load
				else{
					cout<<"Choose a stats location to load. Ex: first displayed stat"<<endl;
					cout<<"(enter 1), fifth displayed stat(enter 5): ";
					cin>>location; cin.ignore(100,'\n');

					//Retrieve the save
					save.remove(play, location);
					cout<<'\n'<<"Save loaded!"<<endl;
				}
				//Don't count this as a turn
				--turn;
				load = 1;
			}

			//If play quit
			else if(choice2==5)
				quit = 1;

			//Ask if user want to save the current trade if they didn't choose to
			//skip turn, load a save, or quit
			if(choice2!=3 && choice2 != 4 && choice2 != 5 && trade_err!=0){
				char res1;
				cout<<"Do you want to save this current stats?(Y/N): ";
				cin>>res1; cin.ignore(100,'\n');
				if(toupper(res1)=='Y'){
					save.insert(play);
					cout<<'\n'<<"Save!"<<endl;
				}
			}


		}while(trade_err==0);


		//Check if play reach 10,000 dollars
		end = play->check();

	} while(end != 1 && turn!=30 && quit != 1);

	//Message if player win
	if(end == 1) cout<<"Congratulations! You win the game!"<<endl;
	//Message if player lose
	if(turn == 20) cout<<"You lose. Good luck next time."<<endl;
	//Message if player quit
	if(quit == 1) cout<<"See you later!"<<endl;
	

	if(load==1){
		if(play) delete play;
		play = nullptr; 
	}
	return 0;
}

