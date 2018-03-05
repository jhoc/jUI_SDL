$ mkdir build && cd build
$ cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug ../
	
in: /build/jUI_SDL/CMakeFiles/jUI_SDL.dir/link.txt
add: -lSDL2_ttf
// for using SDL_ttf

$ make
$ make install
