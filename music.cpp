#include "music.hpp"

using namespace std;


int Music::getCriticRate(){
	int tprate;
	for(int i = 0 ; i < cRates.size() ; i++){
		tprate += cRates[i];
	}
	return (tprate/(cRates.size()));
}

string Music::_getArtist()
{
	return musicArtist->getUserDetails().username;
}
string Music::_getAlbum()
{
	return musicAlbum->get_name();
}
void Music::rate(int rate_value){
	rates.push_back(rate_value);
}

string Music::get_short_name(){
	string littleName = musicName;
	size_t pos = littleName.find('-');
	littleName.erase(0 , pos + 1);
	pos = littleName.find('-');
	littleName.erase(0 , pos + 1);
	return littleName;
}

int Music::getURates(){
	int tprate;
	for(int i = 0 ; i < rates.size() ; i++){
		tprate += rates[i];
	}
	return (tprate/(rates.size()));
}

void Music::putCriticRate(int rate_value){
	cRates.push_back(rate_value);
}
void Music::update_full_name(string newAlbumName){
	size_t pos = musicName.find('-');
	if(pos != string::npos){
		musicName.erase(0 , pos + 1);
		pos = musicName.find('-');
		musicName.erase(0 , pos + 1);
	}
	musicName = newAlbumName + musicName;
}