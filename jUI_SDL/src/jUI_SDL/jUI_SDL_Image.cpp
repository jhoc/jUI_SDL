#include "jUI_SDL_Image.h"

jUI_SDL_Image::jUI_SDL_Image( ) {
	TAG = "jUI_SDL:Image::";
}

jUI_SDL_Image::~jUI_SDL_Image( ) {
	SDL_FreeSurface(m_bmp);
}

bool jUI_SDL_Image::load( std::string _path ) {
	SDL_FreeSurface(m_bmp);
	// m_texture = nullptr;
	m_bmp = SDL_LoadBMP( _path.c_str() );
	if( m_bmp == nullptr ) {
		std::cout << TAG << "load: " << _path << " FAILED"<< std::endl;
	}
	m_texture = SDL_CreateTextureFromSurface( jUI_SDL::renderer, m_bmp );
	return true;
}

void jUI_SDL_Image::setPos(int _x, int _y) {
	m_xPos = _x;
	m_yPos = _y;
}

bool jUI_SDL_Image::draw() {
	if( jUI_SDL::renderer == nullptr ) {
		std::cout << "jUI_SDL_Image Error: No SDL_Render set." << std::endl;
		return false;
	}
	if( m_bmp == nullptr ) {
		std::cout << "jUI_SDL_Image Error: No Image Loaded set." << std::endl;
		return false;
	}
	SDL_Rect dst;
	dst.x = m_xPos;
	dst.y = m_yPos;

	// SDL_RenderCopy( m_renderer, m_texture, NULL, NULL );
	SDL_QueryTexture( m_texture, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy( jUI_SDL::renderer, m_texture, nullptr, &dst );
	return true;
}
