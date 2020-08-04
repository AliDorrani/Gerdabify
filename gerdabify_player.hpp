#ifndef __GERDABIFY_PLAYER_H__
#define __GERDABIFY_PLAYER_H__

#include "sdlHeaders.hpp"
#include <iostream>
#include <string>
#include <vector>

void Delay(int milis);
class GerdabPlayer
{
  public:

    GerdabPlayer();
    static void play();
    static void setMusic(std::string path);
    static void pause();
    static void resume();
    static void stop();
    static void setRepeat(bool repeat);
    static void setQueue(std::vector<std::string> music_queue);
    friend void musicFinishCallback();
    static std::string nextMusic;
    static void goToNext();
  private:
    static Mix_Music *music;
    static std::vector<std::string> music_queue;
    static bool repeat;
    static int index;
    
};

class GError{
private:
  std::string message;
public:
  GError();
  GError(std::string errorMessage);
  std::string getMessage();
};

#endif