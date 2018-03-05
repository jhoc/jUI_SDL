#pragma once

#include "jUI_SDL_Base.h"
#include <iostream>
#include <SDL.h>

class jUI_SDL_Image : public jUI_SDL_Base {
public:
	jUI_SDL_Image( );
	~jUI_SDL_Image( );

	bool load( std::string _path );
	void setPos( int _x, int _y );
	bool draw();

private:
	SDL_Surface* m_bmp = nullptr;
	SDL_Texture* m_texture = nullptr;
	int m_xPos = 0;
	int m_yPos = 0;
};
