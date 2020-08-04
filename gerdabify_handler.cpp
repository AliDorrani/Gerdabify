#include "gerdabify_handler.hpp"
using namespace std;



void GerdabifyHandler::goToAlbum(){
	state->goToAlbum();
	selectedAlbum = musicSelected->getAlbum();
	musicSelected = NULL;
	state = selectedAlbum;
}

void GerdabifyHandler::goToArtist(){
	state->goToArtist();
	if(selectedAlbum != NULL){
		selectedArtist = selectedAlbum->getArtist();
		state = selectedArtist;
		selectedAlbum = NULL;
		return;
	}
	else if(musicSelected != NULL){
		selectedArtist = musicSelected->getArtist();
		state = selectedArtist;	
		musicSelected = NULL;
	}
}

void GerdabifyHandler::play(){
	state->play();
	if(musicSelected != NULL){
		user->addToQueue(musicSelected);
	}
	else{
		user->addToQueue(state->get_musics());
	}
	player->SetQueue(user->getQueue());
	player->play();
}

void GerdabifyHandler::addTo(string completeName){
	findDestination(completeName);
}

void GerdabifyHandler::findDestination(string completeName){
	state->addTo(completeName);
	bool flag;
	if(musicSelected != NULL){
		if(completeName.compare("music_queue") == 0){
			user->addToQueue(musicSelected);
			return;
		}
		flag = library->findDestinationForAdding(completeName , musicSelected);
		if(!flag){
			flag = playlists->findDestinationForAdding(completeName , musicSelected , user);
		}
	}
	else if(selectedAlbum != NULL){
		if(completeName.compare("music_queue") == 0){
			user->addToQueue(selectedAlbum->get_musics());
			return;
		}
		flag = library->findDestinationForAdding(completeName , selectedAlbum);
		if(!flag){
			flag = playlists->findDestinationForAdding(completeName , selectedAlbum , user);
		}
	}
	throw MusicContainerDoesNotExists();
}

void GerdabifyHandler::goTo(string completeName){
	selectedPlayList = playlists->FindPlayList(completeName);
	if(selectedPlayList != NULL){
		findStateAndChange(state , selectedPlayList);
		return;
	}
	throw MusicContainerDoesNotExists();
}

GerdabifyHandler::GerdabifyHandler() {
	Play* newplayer = new Play();
	player = newplayer;
	UserHandler* newUserHandler = new UserHandler();
	interState = newUserHandler;
	Library* newLibrary = new Library();
	library = newLibrary;
	PlaylistsHandler* newPlayLists = new PlaylistsHandler();
	playlists = newPlayLists;
}


void GerdabifyHandler::enterBrowserMode(){
	if(browser == NULL)
		browser = new Browser();
	state = browser; 
}

void GerdabifyHandler::go_to_gome(){
	if(home != NULL ){
		state = home;
		return;
	}
	state->go_to_gome();
	state = new Home();
}

void GerdabifyHandler::go_to_playlists(){
	state->goToPlayList();
	state = playlists;
}

void GerdabifyHandler::goToLibrary(){
	state->goToLibrary();
	state = library;
}


void GerdabifyHandler::findStateAndChange(MusicContainer* pastState , MusicContainer* newState){
	string type = pastState->get_type();
	if(type.compare("Music") == 0)
		musicSelected = NULL;
	else if(type.compare("Album") == 0)
		selectedAlbum = NULL;
	else if(type.compare("PlayList") == 0)
		selectedPlayList = NULL;
	else if(type.compare("Artist") == 0)
		selectedArtist = NULL;
	state = newState;
}

void GerdabifyHandler::createPlaylist(string completeName){
	PlayList* newPlayList = playlists->FindPlayList(completeName);
	if(newPlayList != NULL)
		throw AlreadyExists();
	newPlayList = playlists->addPlayLists(completeName , user);
	user->addPlayLists(newPlayList);
}

void GerdabifyHandler::clear(string completeName){
	PlayList* newPlayList = playlists->FindPlayList(completeName);
	if(newPlayList == NULL)
		throw MusicContainerDoesNotExists();
	if(newPlayList->getUser() == user){
		newPlayList->clear();
		return;
	}
	throw NotAuthorized();
}

void GerdabifyHandler::remove(string completeName){
	state->remove(completeName);	
	if(selectedPlayList != NULL){
		selectedPlayList->remove_music(completeName , user);
	}
	else if(selectedAlbum != NULL){
		selectedAlbum->remove_music(completeName , user);
	}
}

void GerdabifyHandler::orderMusicContainer(string completeName,int newPos){
	state->orderMusicContainer(completeName,newPos);
}	

void GerdabifyHandler::rate(int rate_value){
	if(user->getUserDetails().userType == UTEditor){
		if(user->getValidate()){
			state->putCriticRate(rate_value);
			return;
		}
	}
	state->rate(rate_value);
	user->addToratedThings(rate_value , state);
}

string GerdabifyHandler::getArtist(){
	return state->_getArtist();
}

string GerdabifyHandler::getAlbum(){
	return state->_getAlbum();
}

int GerdabifyHandler::get_length(){
	return state->get_length();
}

string GerdabifyHandler::get_name(){
	return state->get_short_name();
}

string GerdabifyHandler::getCompleteName(){
	return state->get_name();
}

int GerdabifyHandler::getRate(){
	state->getRate();
	return user->getRate(state);
}

int GerdabifyHandler::getURates(){
	return state->getURates();
}

int GerdabifyHandler::getCriticRate(){
	return state->getCriticRate();
}

void GerdabifyHandler::enterPlayerMode(){
	state->enterPlayerMode();
	state = player;
}

void GerdabifyHandler::next(){
	state->next();
}

void GerdabifyHandler::pause(){
	state->pause();
}

void GerdabifyHandler::repeat(){
	state->repeat();
}

void GerdabifyHandler::signup(UserData userData, string password){
	//if(userData.)
	user = interState->signup(userData , password);
	state = NULL;
}
void GerdabifyHandler::login(string username, string password){
	user = interState->login(username , password);
	state = NULL;
}

void GerdabifyHandler::add_music(string musicName , string filePath){
	if(user->getUserDetails().userType != UTArtist && !user->getValidate()){
		throw NotAuthorized();
	}
	Music* newMusic = new Music(musicName , filePath);
	Artist* newArtist = library->findArtist(user->getUserDetails().username);
	if(newArtist == NULL){
		throw NotAuthorized();
	}
	library->NotvalidatedNewMusics->add_music(newMusic);
	newMusic->setArtist(newArtist);
}

void GerdabifyHandler::addAlbum(string UTArtist_name , string albumName){
	if(user->getUserDetails().userType != UTArtist){
		throw NotAuthorized();
	}
	Album* newAlbum = new Album(UTArtist_name , albumName);
	Artist* newArtist = library->findArtist(user->getUserDetails().username);
	if(newArtist == NULL){
		throw NotAuthorized();
	}
	library->addToNotValidateAlbums(newAlbum);
	newAlbum->setArtist(newArtist);
}

bool GerdabifyHandler::is_user_logged_in(string token){
	if(interState->is_user_logged_in(token))
		return true;
	return false;
}

List GerdabifyHandler::search(string name){
	List list ;
	library->search(name , list);
	playlists->search(name , list);
}

void GerdabifyHandler::select(string completeName){
	MusicContainer* temp;
	temp = library->findSelectedMusicContainer(completeName);
	if(temp != NULL){
		findStateAndChange(state , temp);
		return;
	}
	temp = playlists->findSelectedMusicContainer(completeName);
	if(temp != NULL){
		findStateAndChange(state , temp);
		return;
	}
	throw MusicContainerDoesNotExists();
}

void GerdabifyHandler::validate(){
	if(user->getUserDetails().userType != UTAdmin)
		throw NotAuthorized();
	state->validate();
	if(musicSelected != NULL){
		library->addToValidateMusics(musicSelected);
	}
	else if(selectedAlbum != NULL){
		library->addToValidateAlbums(selectedAlbum);
	}
	else{
		if(user->getUserDetails().userType == UTArtist){
			Artist* newArtist = new Artist(user);
			library->addArtist(newArtist);
		}
	}
}