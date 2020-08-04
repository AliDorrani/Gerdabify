all: gerdabify_handler.o music.o artist.o album.o playlist.o home_page.o library.o user.o userhandler.o
	g++ gerdabify_handler.o main.cpp music.o artist.o album.o playlist.o home_page.o library.o user.o userhandler.o -o ca7
music.o: music.cpp requirements.hpp music.hpp
	g++ -c music.cpp
playlist.o: playlist.hpp requirements.hpp
	g++ -c playlist.cpp
library.o: library.hpp library.cpp requirements.hpp
	g++ -c library.cpp
user.o: user.cpp user.hpp requirements.hpp
	g++ -c user.cpp
gerdabify_handler.o: gerdabify_handler.hpp gerdabify_handler.cpp requirements.hpp music.hpp album.hpp artist.hpp library.hpp home_page.hpp user.hpp
	g++ -c gerdabify_handler.cpp
album.o: album.hpp requirements.hpp album.cpp
	g++ -c album.cpp
home_page.o: home_page.hpp home_page.cpp
	g++ -c home_page.cpp
artist.o: artist.hpp artist.cpp requirements.hpp
	g++ -c artist.cpp
userhandler.o: userhandler.hpp userhandler.cpp user.cpp user.hpp requirements.hpp
	g++ -c userhandler.cpp
main.o:	main.cpp gerdabify_handler.hpp gerdabify_handler.cpp
	g++ -c main.cpp
player.o: player.hpp player.cpp
	g++ -c player.cpp
gerdabServer.o: src/gerdabServer.cpp
	g++ -std=c++11 -c src/gerdabServer.cpp -o src/gerdabServer.o
web++.o: src/web++.cpp
	g++ -std=c++11 -c src/web++.cpp -o src/web++.o
clean:
	rm *.o

