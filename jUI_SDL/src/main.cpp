// #pragma once

#include "jUI_SDL/jUI_SDL_Window.h"
#include "jUI_App.h"

int main(int, char**){
  // create window
  jUI_SDL_Window window;
	
	if ( !window.create( "jUI_SDL_Window", 100, 100, 640, 480 ) ) {
    return 0;
  }

	jUI_App app;
	app.init( window );
	app.setup();
	
  window.loop();
  
  return 0;
}

