#ifndef _LIB_H_
#define _LIB_H_
#include <iostream>
#include <vector>
#include <string>
#include "playlist.hpp"
#include "album.hpp"
#include "artist.hpp"
#include "requirements.hpp"
#include "music.hpp"
using namespace std;


#define LB "library"
#define PLS "playlists"

class NotAuthorized;

class Library : public MusicContainer{
public:
	List list();
	List list_musics();
	List list_albums();
	List list_artists();
	bool findDestinationForAdding(string completeName , Music* selectedMusic);
	bool findDestinationForAdding(string completeName , Album* selectedMusic);
	string get_type(){return "Library";}
	string get_short_name(){return get_type();}
	string get_name(){return get_type();}
	List search(string , List&);
	MusicContainer* findSelectedMusicContainer(string completeName);
	void addToValidateMusics(Music* musicSelected);
	void addToValidateAlbums(Album* selectedAlbum);
	void addToNotValidateAlbums(Album* newAlbum);
	Artist* findArtist(string username);
	void addArtist(Artist* newArtist);
	Album* NotvalidatedNewMusics;
	vector<Album*> NotvalidatedNewAlbums;
private:
	vector <Artist*> UTArtistsInLib;
	vector <Album*> albumsInLib;
	Album* validatedNewMusics;
};



#endif 