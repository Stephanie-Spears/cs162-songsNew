#include "songlist.h"

void SongList::loadSongs()
{

	fstream inputFile;
	char temp[MAX_CHAR];

	inputFile.open("songs.txt", fstream::in);

	inputFile.getline(temp, MAX_CHAR, ';');
	list[index].setTitle(temp);
	
	while (inputFile.good())
	{
		inputFile.getline(temp, MAX_CHAR, ';');
		list[index].setArtist(temp);
		inputFile.getline(temp, MAX_CHAR, ';');
		list[index].setDuration(temp);
		inputFile.getline(temp, MAX_CHAR, '\n');
		list[index].setAlbum(temp);
		index++;
		inputFile.getline(temp, MAX_CHAR, ';');
		list[index].setTitle(temp);	
	}
	inputFile.close();
}


void SongList::printSong(int num)
{
	char temp[MAX_CHAR];
	cout << "Index: " << num << endl;
	list[num].retTitle(temp);
	cout << "Title: " << temp << endl;
	list[num].retArtist(temp);
	cout << "Artist: " << temp << endl;
	list[num].retDuration(temp);
	cout << "Duration: " << temp << endl;
	list[num].retAlbum(temp);
	cout << "Album: " << temp << endl << endl;
}


void SongList::addSong(Song inSong)
{
	char temp[MAX_CHAR];

	inSong.retTitle(temp);
	list[index].setTitle(temp);

	inSong.retArtist(temp);
	list[index].setArtist(temp);

	inSong.retDuration(temp);
	list[index].setDuration(temp);

	inSong.retAlbum(temp);
	list[index].setAlbum(temp);

	index++;
}


void SongList::removeSong(int del)
{
	char temp[MAX_CHAR];

	for (int i = del; i < index-1; i++)
	{
		list[i + 1].retTitle(temp);
		list[i].setTitle(temp);

		list[i + 1].retArtist(temp);
		list[i].setArtist(temp);

		list[i + 1].retDuration(temp);
		list[i].setDuration(temp);

		list[i + 1].retAlbum(temp);
		list[i].setAlbum(temp);
	}
	index--;
}


void SongList::searchAlbum(char search[])
{
	char temp[MAX_CHAR];
	bool d = 0;

	for (int i = 0; i < index; i++)
	{
		list[i].retAlbum(temp);
		if (strcmp(temp, search) == 0)
		{
			printSong(i);
			d = 1;
		}
	}
	if (d == 0)
	{
		cout << "Album " << search << " was not found." << endl;
	}
}


void SongList::searchArtist(char search[])
{
	char temp[MAX_CHAR];
	int d = 0;

	for (int i = 0; i < index; i++)
	{
		list[i].retArtist(temp);
		if (strcmp(temp, search) == 0)
		{
			printSong(i);
			d = 1;
		}
	}
	if (d == 0)
	{
		cout << "Artist " << search << " was not found." << endl;
	}
}


void SongList::saveSongs()
{
	fstream outputFile;
	char temp[MAX_CHAR];

	outputFile.open("songs.txt", fstream::out);

		for (int i = 0; i < index; i++)
		{
			list[i].retTitle(temp);
			outputFile << temp << ';';

			list[i].retArtist(temp);
			outputFile << temp << ';';

			list[i].retDuration(temp);
			outputFile << temp << ';';
			if (i != index - 1)
			{
				list[i].retAlbum(temp);
				outputFile << temp << '\n';
			}
			else if (i == index - 1)
			{
				list[i].retAlbum(temp);
				outputFile << temp;
			}
		}

	outputFile.close();
}

int SongList::length()
{
	return index;
}
