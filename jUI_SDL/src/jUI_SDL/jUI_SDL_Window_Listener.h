#pragma once

class jUI_SDL_Window_Listener {
public:
	virtual void setup() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void exit() = 0;

	virtual void keyPressed(int key) = 0;
	virtual void keyReleased(int key) = 0;
	virtual void mouseMoved(int x, int y) = 0;
	virtual void mouseDragged(int x, int y, int button) = 0;
	virtual void mousePressed(int x, int y, int button) = 0;
	virtual void mouseReleased(int x, int y, int button) = 0;
	virtual void mouseEntered(int x, int y) = 0;
	virtual void mouseExited(int x, int y) = 0;
	virtual void mouseScrolled(int x, int y, float scrollX, float scrollY) = 0;

	virtual void windowResized(int w, int h) = 0;
};
