#ifndef LUDOGAME_H
#define LUDOGAME_H

#include<iostream>
#include "LudoBoard.h"
#include "LudoPlayer.h"


class LudoGame {
		const string colors[4] = {"red", "green", "purple", "blue"};
		Board* curr_board;
		string WinOrder[4];
		int i=0;
		Player* players[4];
		int curr_piece;
	public:
		LudoGame():curr_board(new Board) {}
		
		void InitPlayers(){
			for(int i=0; i<4; i++) {
				cout<<"Enter Name of Player #"<<i+1<<endl;
				players[i]=new Player;
				for(int j=0; j<4; j++) {
					players[i]->pieces[j]=new Piece(colors[i],curr_board->colorjails[i],curr_board->win);
				}
			}
		}

		void checkcaptures(int cp,int t) {
			Node* temp=players[t]->pieces[cp]->position;
			for(int i=0; i<3; i++) {
				for(int j=0; j<4; j++) {
					if(players[t]->pieces[cp]->position == players[(t+1+i)%4]->pieces[j]->position &&  temp->kill == true) {
						players[(t+i+1)%4]->pieces[j]->getcaptured();
						players[(t+i+1)%4]->checktrapped();
						cout<<endl<<players[(t+i+1)%4]->getname()<<"'s Piece #"<<j<<" was Caputred!"<<endl<<endl;
						curr_board->updatejail((t+i+1)%4,3);
					}
				}
			}
		}

		void play() {
			title();
			cout<<endl;
			system("pause");
			cout<<endl;
			InitPlayers();
			int turns=0;
			int p=-1;
			bool activegame=true;
			while(activegame) {
				system("cls");
				curr_board->display();
				cout<<"\n\nRound #"<<((turns+1)/4)+1<<"\t| Turn: "<<(turns+1)%4<<endl;
				p=players[turns%4]->turn(curr_piece);
				if(p==2) {
					curr_board->updatejail(turns%4,2);
				}
				if(!(players[turns%4]->playstate())) {
					WinOrder[i++]=players[turns%4]->getname();
				}
				if(players[0]->playstate()||players[1]->playstate()||players[2]->playstate()||players[3]->playstate()) {
					activegame=true;
				} else {
					activegame=false;
				}
				checkcaptures(curr_piece,turns%4);
				turns++;
				system("pause");
			}
		}

		void title() {

			SetConsoleTextAttribute(hConsole,  100);
			printf("                                                      ");
			cout<<endl;

			SetConsoleTextAttribute(hConsole,  100);
			printf("  ");

			SetConsoleTextAttribute(hConsole,  228);
			printf("                                                  ");
			SetConsoleTextAttribute(hConsole,  100);
			printf("  ");	//line0
			cout<<endl;
			SetConsoleTextAttribute(hConsole,  100);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("                                                  ");
			SetConsoleTextAttribute(hConsole,  100);
			printf("  ");	//line1
			cout<<endl;

			SetConsoleTextAttribute(hConsole,  100);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("      ");
			SetConsoleTextAttribute(hConsole,  65);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("        ");
			SetConsoleTextAttribute(hConsole,  33);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("    ");
			SetConsoleTextAttribute(hConsole,  33);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  84);
			printf("      ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("      ");
			SetConsoleTextAttribute(hConsole,  19);
			printf("    ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("        ");									//line2
			SetConsoleTextAttribute(hConsole,  100);
			printf("  ");
			cout<<endl;


			SetConsoleTextAttribute(hConsole,  100);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("      ");
			SetConsoleTextAttribute(hConsole,  65);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("        ");
			SetConsoleTextAttribute(hConsole,  33);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("    ");
			SetConsoleTextAttribute(hConsole,  33);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  84);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("    ");
			SetConsoleTextAttribute(hConsole,  84);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  19);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("    ");
			SetConsoleTextAttribute(hConsole,  19);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("      ");									//line3
			SetConsoleTextAttribute(hConsole,  100);
			printf("  ");
			cout<<endl;

			SetConsoleTextAttribute(hConsole,  100);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("      ");
			SetConsoleTextAttribute(hConsole,  65);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("        ");
			SetConsoleTextAttribute(hConsole,  33);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("    ");
			SetConsoleTextAttribute(hConsole,  33);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  84);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("    ");
			SetConsoleTextAttribute(hConsole,  84);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  19);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("    ");
			SetConsoleTextAttribute(hConsole,  19);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("      ");									//line4
			SetConsoleTextAttribute(hConsole,  100);
			printf("  ");
			cout<<endl;


			SetConsoleTextAttribute(hConsole,  100);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("      ");
			SetConsoleTextAttribute(hConsole,  65);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("        ");
			SetConsoleTextAttribute(hConsole,  33);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("    ");
			SetConsoleTextAttribute(hConsole,  33);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  84);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("    ");
			SetConsoleTextAttribute(hConsole,  84);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  19);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("    ");
			SetConsoleTextAttribute(hConsole,  19);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("      ");									//line5
			SetConsoleTextAttribute(hConsole,  100);
			printf("  ");
			cout<<endl;

			SetConsoleTextAttribute(hConsole,  100);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("      ");
			SetConsoleTextAttribute(hConsole,  65);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("        ");
			SetConsoleTextAttribute(hConsole,  33);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("    ");
			SetConsoleTextAttribute(hConsole,  33);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  84);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("    ");
			SetConsoleTextAttribute(hConsole,  84);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  19);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("    ");
			SetConsoleTextAttribute(hConsole,  19);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("      ");								//line6
			SetConsoleTextAttribute(hConsole,  100);
			printf("  ");
			cout<<endl;

			SetConsoleTextAttribute(hConsole,  100);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("      ");
			SetConsoleTextAttribute(hConsole,  65);
			printf("        ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  33);
			printf("        ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  84);
			printf("      ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("      ");
			SetConsoleTextAttribute(hConsole,  19);
			printf("    ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("        ");								//line7
			SetConsoleTextAttribute(hConsole,  100);
			printf("  ");
			cout<<endl;

			SetConsoleTextAttribute(hConsole,  100);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("                                                  ");	//line8
			SetConsoleTextAttribute(hConsole,  100);
			printf("  ");
			cout<<endl;
			SetConsoleTextAttribute(hConsole,  100);
			printf("  ");
			SetConsoleTextAttribute(hConsole,  228);
			printf("                                                  ");	//line9
			SetConsoleTextAttribute(hConsole,  100);
			printf("  ");
			cout<<endl;

			SetConsoleTextAttribute(hConsole,  100);
			printf("                                                      ");
			cout<<endl;
			
			SetConsoleTextAttribute(hConsole,  228);
			printf("                                                      \n");
			printf("      --A Data Structures & Algorithms Project--      \n");
			printf("            Created and Tested by Group 21            \n");
			printf("         Rehan Ur Rehman Sharif | CT - 22084          \n");
			printf("         Maha Jameel            | CT - 22055          \n");
			printf("         Muhammad Taqi Haider   | CT - 22092          \n");
			printf("                                                      ");
			cout<<endl;
			SetConsoleTextAttribute(hConsole,  15);
		}
};

#endif