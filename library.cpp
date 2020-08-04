#include "library.hpp"
using namespace std;



List Library::list(){
	List list;
	for(int i = 0 ; i < UTArtistsInLib.size() ; i++){
		list.push_back(UTArtistsInLib[i]->getUserDetails().username);
	}	
	return list;
}

List Library::list_musics(){
	List list;
	for(int i = 0 ; i < albumsInLib.size() ; i++){
		list.insert( list.end(), albumsInLib[i]->list_musics().begin(), albumsInLib[i]->list_musics().end() );
	}
	return list;
}

List Library::list_albums(){
	List list;
	for(int i = 0 ; i < albumsInLib.size() ; i++){
		list.push_back(albumsInLib[i]->get_name());
	}
	return list;
}

List Library::list_artists(){
	list();
}

bool Library::findDestinationForAdding(string completeName , Music* selectedMusic){
	for(int i = 0 ; i < UTArtistsInLib.size() ; i++){
		Album* selectedAlbum = UTArtistsInLib[i]->get_album(completeName);
		if(selectedAlbum != NULL){
			if(selectedMusic->getArtist() == UTArtistsInLib[i] && selectedAlbum->getArtist() == selectedMusic->getArtist()){
				selectedAlbum->add_music(selectedMusic);
				return true;
			}
			throw NotAuthorized();
		}
	}
	return false;
}

bool Library::findDestinationForAdding(string completeName , Album* albumForAdding){
	for(int i = 0 ; i < UTArtistsInLib.size() ; i++){
		Album* selectedAlbum = UTArtistsInLib[i]->get_album(completeName);
		if(selectedAlbum != NULL){
			if(UTArtistsInLib[i] == albumForAdding->getArtist()){
				vector<Music*>musics = albumForAdding->get_musics();
				for(int i = 0 ; i < musics.size() ; i++){
					selectedAlbum->add_music(musics[i]);
					musics[i]->update_full_name(selectedAlbum->get_name());
					musics[i]->setArtist(UTArtistsInLib[i]);
				}
				return true;
			}
			throw NotAuthorized();
		}
	}
	return false;
}

List Library::search(string name , List& list){
	for(int i = 0 ; i < UTArtistsInLib.size() ; i++){
		if(UTArtistsInLib[i]->get_name().find(name) != string::npos)
			list.push_back(UTArtistsInLib[i]->get_name());
		UTArtistsInLib[i]->search(name , list);
	}
}

MusicContainer* Library::findSelectedMusicContainer(string completeName){
	MusicContainer* temp;
	for(int i = 0 ; i < UTArtistsInLib.size() ; i++){
		if(UTArtistsInLib[i]->get_name().compare(completeName) == 0)
			return UTArtistsInLib[i];
	}
	for(int i = 0 ; i < albumsInLib.size() ; i++){
		if(albumsInLib[i]->get_name().compare(completeName) == 0)
			return albumsInLib[i];
		temp = albumsInLib[i]->findSelectedMusicContainer(completeName);
		if(temp	!= NULL)
			return temp;
	}
	return NULL;
}

void Library::addToValidateMusics(Music* musicSelected){
	validatedNewMusics->add_music(musicSelected);
	NotvalidatedNewMusics->remove_music(musicSelected);

}

void Library::addToValidateAlbums(Album* selectedAlbum){
	albumsInLib.push_back(selectedAlbum);
	for(int i = 0 ; i < NotvalidatedNewAlbums.size() ; i++){
		if(NotvalidatedNewAlbums[i] == selectedAlbum)
			NotvalidatedNewAlbums.erase(NotvalidatedNewAlbums.begin() + i);
	}
}

void Library::addToNotValidateAlbums(Album* newAlbum){
	NotvalidatedNewAlbums.push_back(newAlbum);
}

Artist* Library::findArtist(string username){
	for(int i = 0 ; i < UTArtistsInLib.size() ; i++){
		if(UTArtistsInLib[i]->getUserDetails().username.compare(username) == 0){
			return UTArtistsInLib[i];
		}
	}
	return NULL;
}

void Library::addArtist(Artist* newArtist){
	UTArtistsInLib.push_back(newArtist);
}