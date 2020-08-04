#ifndef __ALBUM_H__
#define __ALBUM_H__
#include <iostream>
#include <vector>
#include <string>
#include "requirements.hpp"
#include "music.hpp"
#include "user.hpp"
#include "artist.hpp"
using namespace std;

class Music;
class Artist;
class User;

class Album : public MusicContainer{
public:
	Album(string _UTArtist_name , string _albumName) : UTArtist_name(_UTArtist_name) , albumName(UTArtist_name + "-" + _albumName){}
	List list();
	List list_musics();
	string get_name(){return albumName;}
	Artist* getArtist(){return albumArtist;}
	void goToArtist(){}
	vector<Music*> get_musics(){return musics;}
	void addTo(string completeName){}
	void add_music(Music* selectedMusic);
	string get_type(){return "Album";}
	void remove(string){}
	void remove_music(string completeName ,User* user);
	void rate(int rate_value);
	string _getArtist(){return UTArtist_name;}
	int get_length();
	string get_short_name();
	int getRate(){}
	int getURates();
	void putCriticRate(int rate_value);
	int getCriticRate();
	void play(){}
	List search(string , List&);
	MusicContainer* findSelectedMusicContainer(string completeName);
	void validate(){}
	void remove_music(Music* selectedMusic);
	void setArtist(Artist* newArtist){albumArtist = newArtist;}
private:
	string UTArtist_name;
	vector<Music*>musics;
	string albumName;
	Artist* albumArtist;
	vector<int>rates;
	vector<int>cRates;
};

#endif