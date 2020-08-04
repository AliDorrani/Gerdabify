#include "gerdabPlayer.hpp"
#include <iostream>

using namespace std;



Mix_Music* GerdabPlayer::music;
bool GerdabPlayer::repeat;
int GerdabPlayer::index;
std::vector<std::string> GerdabPlayer::music_queue;
std::string GerdabPlayer::nextMusic;

void GerdabPlayer::resume()
{
    Mix_ResumeMusic();
}
void GerdabPlayer::setNextMusic(std::string path)
{
    nextMusic = path;
}


GError::GError(){}

GError::GError(std::string errorMessage){
    message = errorMessage;
  }
std::string GError::getMessage()
{
    return message;
  }


GerdabPlayer::GerdabPlayer(){
  Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
  index = 0;
  repeat = 0;
}

void musicFinishCallback(){
  GerdabPlayer::goToNext();
}

void GerdabPlayer::goToNext(){
  GerdabPlayer::stop();
  index++;
  if(index >= music_queue.size()){
    if(repeat){
      index = 0;
    }else{
      music_queue.clear();
      return;
    }
  }
  GerdabPlayer::setMusic(music_queue[index]);
  GerdabPlayer::play();
}

void musicFinishCallback(){
  GerdabPlayer::goToNext();
}

void GerdabPlayer::play()
{

    if(music_queue.size() != 0){
      cout<<music_queue[index]<<endl;
      music = Mix_LoadMUS(music_queue[index].c_str());
      Mix_PlayMusic(music, 1);
      Mix_HookMusicFinished(musicFinishCallback);
    }

}

void GerdabPlayer::setMusic(std::string path)
{
  Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
  music = Mix_LoadMUS(path.c_str());
}
void GerdabPlayer::pause()
{
  Mix_PauseMusic();
}


void GerdabPlayer::stop()
{
  Mix_HaltMusic();
}
void GerdabPlayer::setRepeat(bool _repeat)
{ 
  repeat = _repeat;
}
void GerdabPlayer::setQueue(std::vector<std::string> _music_queue)
{
  music_queue = _music_queue;
}