#ifndef __GERDABIFY_HANDLER_H__
#define __GERDABIFY_HANDLER_H__
#include <iostream>
#include <vector>
#include <string>
#include "requirements.hpp"
#include "music.hpp"
#include "home_page.hpp"
#include "player.hpp"
#include "artist.hpp"
#include "album.hpp"
#include "playlist.hpp"
#include "user.hpp"
#include "library.hpp"
#include "userhandler.hpp"

using namespace std;





class GerdabifyHandler {
public:
	GerdabifyHandler();
	void findDestinationForAdding(string completeName , string& type , int pos);
	List listOfPossibleMoves();
	void signup(UserData userData, string password);
	void login(string username, string password);
	void enterBrowserMode();
	void go_to_gome();
    void go_to_playlists();
    void goToLibrary();
    void goToAlbum();
    void goToArtist();
    List search(string);
    void select(string);
    List list(){state->list();}
    List list_musics(){state->list_musics();}
    List list_albums(){state->list_albums();}
    List list_playlists(){state->list_playlists();}
    List list_artists(){state->list_artists();}
    void play();
    void addTo(string);
    void goTo(string);
    void createPlaylist(string);
    void clear(string);
    void findDestination(string completeName);
    void findStateAndChange(MusicContainer* pastState , MusicContainer* newState);
    void remove(string);
    void orderMusicContainer(string, int);
    void rate(int rate_value);
    string getArtist();
    string getAlbum();
    int get_length();
    string get_name();
    string getCompleteName();
    int getRate();
    int getURates();
    int getCriticRate();
    void enterPlayerMode();
    void next();
    void pause();
    void repeat();
    void add_music(string musicName , string filePath);
    void addAlbum(string UTArtist_name , string albumName);
    bool is_user_logged_in(string token);
    void validate();
private:
	MusicContainer* state;
	Home* home;
	Browser* browser;
	User* user;
	Library* library;
	Music* musicSelected;
	Album* selectedAlbum;
	Artist* selectedArtist;
	PlaylistsHandler* playlists;
	PlayList* selectedPlayList;
	Play* player;
    static UserHandler* interState;
};

#endif