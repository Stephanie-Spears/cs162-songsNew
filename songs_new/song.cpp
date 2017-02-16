#include <iostream>
#include <cstring>
#include "song.h"

void Song::setTitle(char inTitle[])		
{
	strcpy(title, inTitle);
}
void Song::setArtist(char inArtist[])
{
	strcpy(artist, inArtist);
}
void Song::setDuration(char inDuration[])
{
	strcpy(duration, inDuration);
}
void Song::setAlbum(char inAlbum[])	
{
	strcpy(album, inAlbum);
}

void Song::print() //why do i need this when i have songlist print?
{

	cout << "Title: " << title << endl;
	cout << "Artist: " << artist << endl;
	cout << "Duration: " << duration << endl;
	cout << "Album: " << album << endl;

}

void Song::retTitle(char outTitle[])
{
	strcpy(outTitle, title);
}
void Song::retArtist(char outArtist[])
{
	strcpy(outArtist, artist);
}
void Song::retDuration(char outDuration[])
{
	strcpy(outDuration, duration);
}
void Song::retAlbum(char outAlbum[])
{
	strcpy(outAlbum, album);
}

