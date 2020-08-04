#ifndef __HOME_PAGE_H__
#define __HOME_PAGE_H__

#include <iostream>
#include <vector>
#include <string>
#include "requirements.hpp"
using namespace std;


class Home : public MusicContainer{
public:
 	List list();
 	void go_to_playlists();
 	void goToLibrary(){}
 	string get_type(){return "Home";}
 	string get_short_name(){return get_type();}
 	string get_name(){return get_type();}

};

class Browser : public MusicContainer{
public:
	string get_type(){return "Browser";}
	void go_to_gome(){}
	string get_short_name(){return get_type();}
};

#endif