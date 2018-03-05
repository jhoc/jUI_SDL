#include "jUI_SDL_Font.h"

jUI_SDL_Font::jUI_SDL_Font(){
	TAG = "jUI_Font::";
}

jUI_SDL_Font::~jUI_SDL_Font() {
	//Clean up the surface and font
	// SDL_FreeSurface( surf );
	TTF_CloseFont( m_font );	
}

bool jUI_SDL_Font::load( const std::string _path, int _size ) {
	m_font = TTF_OpenFont( _path.c_str(), _size);
	if ( m_font == nullptr) {
		std::cout << TAG << "TTF_OpenFont failed\n";
		return false;
	}
	return true;
}

void jUI_SDL_Font::drawString( const std::string _string, int _x, int _y ) {
//We need to first render to a surface as that's what TTF_RenderText
	//returns, then load that surface into a texture
	SDL_Color color;
	color.r = 255;
	color.g = 255;
	SDL_Surface *surf = TTF_RenderText_Blended( m_font, _string.c_str(), color);
	if (surf == nullptr){
		TTF_CloseFont( m_font);
		std::cout << TAG << "TTF_RenderText failed\n";
		return;
	}
	SDL_Texture *texture = SDL_CreateTextureFromSurface( jUI_SDL::renderer, surf);
	if (texture == nullptr){
		std::cout << TAG << "TTF_CreateTexture failed\n";
		return;
	}
	SDL_Rect dst;
	dst.x = _x;
	dst.y = _y;
	SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy( jUI_SDL::renderer, texture, nullptr, &dst);
	// SDL_RenderCopy( jUI_SDL::renderer, texture, nullptr, nullptr );

}
