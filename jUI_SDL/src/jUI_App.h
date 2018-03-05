#pragma once

#include <iostream>
#include "jUI_SDL/jUI_SDL.h"
#include "jUI_SDL/jUI_SDL_App.h"
#include "jUI_SDL/jUI_SDL_Image.h"
#include "jUI_SDL/jUI_SDL_Font.h"
#include "jUI_SDL/jUI_SDL_FilePath.h"

class jUI_App : public jUI_SDL_App {
public:
	void setup();
	void update();
	void draw();
	void exit();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void mouseScrolled(int x, int y, float scrollX, float scrollY);

	void windowResized(int w, int h);
	// void dragEvent(ofDragInfo dragInfo);
	// void gotMessage(ofMessage msg);

private:
	std::string TAG = "jUI_App::";

	jUI_SDL_Image m_image;
	int m_mouseXPos = 0;
	int m_mouseYPos = 0;
	jUI_SDL_Font m_font;
};
