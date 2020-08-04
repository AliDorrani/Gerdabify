#include "album.hpp"


using namespace std;



int Album::getCriticRate()
{
	int tprate;
	for(int i = 0 ; i < cRates.size() ; i++)
	{
		tprate += cRates[i];
	}
	return (tprate/(cRates.size()));
}

List Album::search(string name, List& list)
{
	for(int i = 0 ; i < musics.size() ; i++)
	{
		if(musics[i]->get_name().find(name) != string::npos)
			list.push_back(musics[i]->get_name());
	}
}

MusicContainer* Album::findSelectedMusicContainer(string completeName)
{
	for(int i = 0 ; i < musics.size() ; i++)
	{
		if(musics[i]->get_name()== completeName)
			return musics[i];
	}
}

List Album::list_musics(){
	return list();
}

List Album::list()
{
	List list;
	for(int i = 0 ; i < musics.size() ; i++){
		list.push_back(musics[i]->get_name());
	}
	return list;
}

int Album::getURates()
{
	int tprate;
	for(int i = 0 ; i < rates.size() ; i++)
	{
		tprate += rates[i];
	}
	return (tprate/(rates.size()));
}

void Album::putCriticRate(int rate_value)
{
	cRates.push_back(rate_value);
}

void Album::add_music(Music* selectedMusic){
	musics.push_back(selectedMusic);
	selectedMusic->update_full_name(get_name());
}

void Album::remove_music(string completeName ,User* user){
	for(int i = 0 ; i < musics.size() ; i++){
		if(completeName.compare(musics[i]->get_name()) == 0){
			if(user->getUserDetails().username.compare(albumArtist->getUserDetails().username) == 0){
				musics.erase(musics.begin() + i);
				return;
			}
			throw NotAuthorized();
		}
	}
}

void Album::rate(int rate_value){
	rates.push_back(rate_value);
}

int Album::get_length(){
	int totalLength;
	for(int i = 0 ; i < musics.size() ; i++)
		totalLength += musics[i]->get_length();
	return totalLength;
}

string Album::get_short_name(){
	string littleName = albumName;
	size_t pos = littleName.find('-');
	littleName.erase(0 , pos + 1);
	return littleName;
}

void Album::remove_music(Music* selectedMusic){
	for(int i = 0 ; i < musics.size() ; i++){
		if(selectedMusic == musics[i])
			musics.erase(musics.begin() + i);
	}
}