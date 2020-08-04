#ifndef __ARTIST_H__
#define __ARTIST_H__
#include <iostream>
#include <vector>
#include <string>
#include "requirements.hpp"
#include "user.hpp"
#include "music.hpp"
#include "album.hpp"
using namespace std;

class Album;
class Music;

class Artist : public User{
public:
	Artist(User* user);
	List list();
	List list_musics();
	List list_albums();
	vector<Music*> get_musics();
	Album* get_album(string completeName);
	string get_type(){return "Artist";}
	string get_short_name();
	string get_name(){return get_short_name();}
	void rate(int rate_value);
	int getRate(){}
	int getURates();
	void putCriticRate(int rate_value);
	int getCriticRate();
	void play(){}
	List search(string , List&);
private:
	vector<Album*>albums;
	vector<int>rates;
	vector<int>cRates;
};
#endif