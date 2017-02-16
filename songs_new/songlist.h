#ifndef SONGLIST_H
#define SONGLIST_H

#include <iostream>
#include <cstring>
#include <fstream>
#include "song.h"

class SongList
{
public:
	void loadSongs();

	void printSong(int);
	void addSong(Song);
	void removeSong(int);
	void searchAlbum(char[]);
	void searchArtist(char[]);
	
	void saveSongs();

	int length();

private:
	Song list[100]; //An array of Song named "list" inside class Songlist.
	int index = 0;
};

#endif