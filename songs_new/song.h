#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <cstring>

#define MAX_CHAR 50

using namespace std;

class Song
{
public:
	void setTitle(char[]);
	void setArtist(char[]);
	void setDuration(char[]);
	void setAlbum(char[]);

	void print();

	void retTitle(char[]);
	void retArtist(char[]);
	void retDuration(char[]);
	void retAlbum(char[]);

private:
	char title[MAX_CHAR];
	char artist[MAX_CHAR];
	char duration[MAX_CHAR];
	char album[MAX_CHAR];
};

#endif
