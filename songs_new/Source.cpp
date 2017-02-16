#include <iostream>
#include <fstream>
#include <cstring>
#include "song.h"
#include "songlist.h"

using namespace std;

int CallMenu();

Song getSong(); //getSong vs AddSong in songlist.cpp?


int main()
{
	SongList list; //should I rename myList? Because in class Songlist, there's already a var Song list.
	Song mySong;
	int iMenu_Result;
	int i = 0;
	bool bRunCode;
	char search[MAX_CHAR];

	list.loadSongs(); //in class SONGLIST-- member object Song list[100] is accessing member function "loadSongs()"

	bRunCode = true;

	//	iArraySize = i;

	while (bRunCode == true)
	{
		iMenu_Result = CallMenu();
		//get menu response

		if (iMenu_Result == 1)
		{
			for (int i = 0; i < list.length(); i++)
			{
				list.printSong(i);
			}
			//display all songs
		}
		else if (iMenu_Result == 2)
		{
			mySong = getSong();
			list.addSong(mySong); //what's this bit for again?
			//add song
		}

		else if (iMenu_Result == 3)
		{
			int num;
			bool bCheckInput;

			bCheckInput = false;
			while (bCheckInput == false)
			{
				cout << "Enter the song index you would like to remove: ";
				cin >> num;
				cin.clear();
				cin.ignore(100, '\n');

				if (0 > num || num > (list.length() -1))
				{
					cout << "Input error. Select an index number between 0 and " << (list.length() -1) << "." << endl;
				}
				else
				{
					bCheckInput = true;
				}
			}

			list.removeSong(num); //if i enter "0" it only lists up to song 3 index...if i add a song first, then do 0, it lists up to four...works except for last number won't delete
		
		}
		else if (iMenu_Result == 4)
		{
			cout << "Search Artist Name: ";
			cin.get(search, MAX_CHAR, '\n');
			cin.clear();
			cin.ignore(100, '\n');
			cout << endl << endl;
			list.searchArtist(search);
			//search song by artist
		}
		else if (iMenu_Result == 5)
		{
			cout << "Search Album Name: ";
			cin.get(search, MAX_CHAR, '\n');
			cin.clear();
			cin.ignore(100, '\n');
			cout << endl << endl;
			list.searchAlbum(search);
			//search song by album
		}
		else if (iMenu_Result == 6)
		{
			list.saveSongs();
			cout << "Saving changes and closing program. Goodbye." << endl;
			bRunCode = false;
		}
		else
		{
			cout << "Unknown Error. Exiting Program." << endl << endl;
			bRunCode = false;
		}
	}
	


	return 0;
}

int CallMenu()
{
	bool bValidInput;
	int iMenu_Result;

	bValidInput = true;

	while (bValidInput == true)
	{
		cout << "1) Display all songs" << endl;
		cout << "2) Add new song" << endl;
		cout << "3) Remove song" << endl;
		cout << "4) Search song by artist" << endl;
		cout << "5) Search song by album" << endl;
		cout << "6) Save all and Quit" << endl << endl;
		cout << "Enter Choice: ";
		cin >> iMenu_Result;
		cin.clear();
		cin.ignore(100, '\n');

		if (iMenu_Result == 1)
		{
			cout << "You Chose Option 1. " << endl << endl;
			return iMenu_Result;
		}
		else if (iMenu_Result == 2)
		{
			cout << "You Chose Option 2. " << endl << endl;
			return iMenu_Result;
		}
		else if (iMenu_Result == 3)
		{
			cout << "You Chose Option 3. " << endl << endl;
			return iMenu_Result;
		}
		else if (iMenu_Result == 4)
		{
			cout << "You Chose Option 4. " << endl << endl;
			return iMenu_Result;
		}
		else if (iMenu_Result == 5)
		{
			cout << "You Chose Option 5. " << endl << endl;
			return iMenu_Result;
		}
		else if (iMenu_Result == 6)
		{
			cout << "You Chose Option 6. " << endl << endl;
			return iMenu_Result;
		}
		else
		{
			cout << "Input error. Please choose an option from the menu." << endl << endl;
			cin.clear();
			cin.ignore(100, '\n');
		}
	}
	return (0);
}


Song getSong()
{
	char temp[MAX_CHAR];
	Song mySong;

	cout << "Please enter Title: ";
	cin.get(temp, MAX_CHAR, '\n');
	cin.clear();
	cin.ignore(100, '\n');
	mySong.setTitle(temp);

	cout << "Please enter Artist: ";
	cin.get(temp, MAX_CHAR, '\n');
	cin.clear();
	cin.ignore(100, '\n');
	mySong.setArtist(temp);

	cout << "Please enter Duration: ";
	cin.get(temp, MAX_CHAR, '\n');
	cin.clear();
	cin.ignore(100, '\n');
	mySong.setDuration(temp);

	cout << "Please enter Album: ";
	cin.get(temp, MAX_CHAR, '\n');
	cin.clear();
	cin.ignore(100, '\n');
	mySong.setAlbum(temp);

	cout << endl << endl;

	return mySong;
}














/*
char testvar[MAX_CHAR];
Song testsong;

cout << "title? ";
cin >> testvar;
testsong.setTitle(testvar);
cout << endl << endl;

cout << "artist? ";
cin >> testvar;
testsong.setArtist(testvar);
cout << endl << endl;

cout << "duration? ";
cin >> testvar;
testsong.setDuration(testvar);
cout << endl << endl;

cout << "album? ";
cin >> testvar;
testsong.setAlbum(testvar);
cout << endl << endl;

testsong.print();

cout << endl << endl;

return 0;
*/