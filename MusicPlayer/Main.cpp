#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <sstream>
#include "MusicPlayer.h"
#define INVALID_ARGS "Invalid Argument\n"
using namespace std;

// Print general help instructions
void PrintHelp()
{
	cout << "Usage:\n";
	cout << "create n\n";
	cout << "delete n\n";
	cout << "insert m n\n";
	cout << "shuffle\n";
	cout << "play n\n";
}

int main()
{
	MusicPlayer* player = new MusicPlayer();
	string line;
	while (std::getline(cin, line))
	{
		std::istringstream input_stream(line);
		
		// playlist operation
		string command;
		
		// playlist id
		int number;
		
		// the ordinal
		int ordinal;

		if (input_stream >> command)
		{
			//exit command
			if (command.compare("exit") == 0)
				return 0;
			//create command
			else if(command.compare("create")==0)
			{
				if (input_stream >> number)
				{
					if(player->CreatePlaylist(number))
					player->PrintPlaylist();
				}
				else
				{
					cout << INVALID_ARGS;
					cout << "Syntax: create n\n";
				}
			}
			//delete command
			else if(command.compare("delete") == 0)
			{
				if (input_stream >> number)
				{
					player->DeleteMusic(number);
					player->PrintPlaylist();
				}
				else
				{ 
					cout << INVALID_ARGS;
					cout << "Syntax: delete n\n";
				}
			}
			//insert command
			else if(command.compare("insert") == 0)
			{
				if (input_stream >> ordinal>>number)
				{
					player->InsertMusic(number, ordinal);
					player->PrintPlaylist();
					
				}
				else 
				{
					cout << INVALID_ARGS;
					cout << "Syntax: insert n m\n";
				}
			}
			//shuffle command
			else if(command.compare("shuffle") == 0)
			{
				player->ShuffleMusic();
				player->PrintPlaylist();
			}
			//play command
			else if(command.compare("play") == 0)
			{
				if (input_stream >> number)
				{
					player->PlayTrackNumber(number);
					player->PrintPlaylist();
				}
				else
				{
					cout << INVALID_ARGS;
					cout << "Syntax: play n\n";
				}
			}
			else
			{
				cout << INVALID_ARGS;
				PrintHelp();
			}
		}
	}

	_getch();
}