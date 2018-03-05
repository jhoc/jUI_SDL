#pragma once

#include "jUI_SDL_Base.h"


class jUI_SDL_Font : jUI_SDL_Base {
public:
	jUI_SDL_Font();
	~jUI_SDL_Font();
	bool load( const std::string _path, int _size );
	void drawString( const std::string _string, int _x, int _y );

private:
	TTF_Font *m_font = nullptr;
};
