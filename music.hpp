#ifndef _MUSIC_H_
#define _MUSIC_H_
#include <iostream>
#include <vector>
#include <string>
#include "requirements.hpp"
#include "artist.hpp"
#include "album.hpp"
using namespace std;


class Album;
class User;
class Artist;

class Music : public MusicContainer{
public:
	Music(string _musicName , string _filePath) : musicName(_musicName) , filePath(_filePath){}
	Album* getAlbum(){return musicAlbum;}
	string get_name(){return musicName;}
	void goToLibrary(){}
	void goToArtist(){}
	void goToAlbum(){}
	Artist* getArtist(){return musicArtist;}
	void addTo(string completeName){}
	string get_type(){return "Music";}
	void rate(int rate_value);
	void putCriticRate(int rate_value);
	string _getArtist();
	string _getAlbum();
	int get_length(){return length;}
	string get_short_name();
	int getRate(){}
	int getURates();
	int getCriticRate();
	void play(){}
	string getPath(){return filePath;}
	void validate(){}
	void update_full_name(string newAlbumName);
	void setArtist(Artist* _musicArtist){musicArtist = _musicArtist;}
private:
	string filePath;
	string musicName;
	Album* musicAlbum;
	vector<User*>musicRated;
	Artist* musicArtist;
	vector<int>rates;
	vector<int>cRates;
	int length;
};
#endif