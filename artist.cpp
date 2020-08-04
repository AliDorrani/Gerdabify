#include "artist.hpp"

using namespace std;



List Artist::list_albums(){
	return list();
}

Album* Artist::get_album(string completeName)
{
	for(int i = 0 ; i < albums.size() ; i++)
	{
		if(completeName.compare(albums[i]->get_name()) == 0){
			return albums[i];
		}
	}
	return 	NULL;
}

string Artist::get_short_name(){
	return getUserDetails().username;
}

void Artist::rate(int rate_value){
	rates.push_back(rate_value);
}

int Artist::getURates(){
	int tprate;
	for(int i = 0 ; i < rates.size() ; i++){
		tprate += rates[i];
	}
	return (tprate/(rates.size()));
}

void Artist::putCriticRate(int rate_value){
	cRates.push_back(rate_value);
}

Artist::Artist(User* _user) : User(_user->getUserDetails() , _user->getPassword()){
	validUser = true;
}

vector<Music*> Artist::get_musics(){
	vector<Music*>UTArtistMusics;
	for(int i = 0 ; i < albums.size() ; i++){
		UTArtistMusics.insert( UTArtistMusics.end(), albums[i]->get_musics().begin(), albums[i]->get_musics().end());
	}
	return UTArtistMusics;
}

List Artist::list_musics()
{
	List list;
	for(int i = 0 ; i < albums.size() ; i++){
		list.insert( list.end(), albums[i]->list_musics().begin(), albums[i]->list_musics().end() );
	}	
	return list;
}

List Artist::list()
{
	List list;
	for(int i = 0 ; i < albums.size() ; i++){
		list.push_back(albums[i]->get_name());
	}	
	return list;
} 

int Artist::getCriticRate(){
	int tprate;
	for(int i = 0 ; i < cRates.size() ; i++){
		tprate += cRates[i];
	}
	return (tprate/(cRates.size()));
}

List Artist::search(string name, List& list){
	for(int i = 0 ; i < albums.size() ; i++){
		if(albums[i]->get_name().find(name) != string::npos)
			list.push_back(albums[i]->get_name());
		albums[i]->search(name , list);
	}
}