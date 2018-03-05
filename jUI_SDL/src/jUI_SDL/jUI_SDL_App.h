#pragma once

#include "jUI_SDL_Window_Listener.h"
#include "jUI_SDL_Window.h"
#include "jUI_SDL_Base.h"
#include "jUI_SDL.h"

class jUI_SDL_App : public jUI_SDL_Window_Listener, public jUI_SDL_Base {
// class jUI_SDL_App {
public:
	jUI_SDL_App() {	};

	virtual ~jUI_SDL_App(){};

	void init( jUI_SDL_Window& _window ) {
		_window.setListener( this );
		// setRenderer( _window.getRenderer() );
	}

	// virtual void setup() {};
	// virtual void update() {};
	// virtual void draw() {};
	// virtual void exit() {};

	// virtual void keyPressed(int key) {};
	// virtual void keyReleased(int key) {};
	// virtual void mouseMoved(int x, int y) {};
	// virtual void mouseDragged(int x, int y, int button) {};
	// virtual void mousePressed(int x, int y, int button) {};
	// virtual void mouseReleased(int x, int y, int button) {};
	// virtual void mouseEntered(int x, int y) {};
	// virtual void mouseExited(int x, int y) {};
	// virtual void mouseScrolled(int x, int y, float scrollX, float scrollY) {};

	// virtual void windowResized(int w, int h) {};
};
