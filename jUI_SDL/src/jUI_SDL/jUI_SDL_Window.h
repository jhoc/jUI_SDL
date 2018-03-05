#pragma once

#include "jUI_SDL.h"
#include "jUI_SDL_Window_Listener.h"

class jUI_SDL_Window : public jUI_SDL {
public:
	jUI_SDL_Window();
	bool create( std::string _windowTitle, int _windowXPos, int _windowYPos, int _windowWidth, int _windowHeight );
	bool close();

	void loop();

	void draw();
	void handleInput();

	void setListener( jUI_SDL_Window_Listener* _listener );

private:
	std::string TAG;
	SDL_Window* m_window;
	SDL_Event m_event;
	bool m_exit = false;
	int m_timer;
	int m_frameRate = 100;

	jUI_SDL_Window_Listener* m_listener = nullptr;
};

//#endif
