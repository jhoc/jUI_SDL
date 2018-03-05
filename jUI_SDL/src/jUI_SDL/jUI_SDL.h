#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>

struct jUI_Color {
	jUI_Color( int _r, int _g, int _b, int _a = 255 ) {
		r = _r;
		g = _g;
		b = _b;
		a = _a;
	}
	int r = 0;
	int g = 0;
	int b = 0;
	int a = 255;
	void operator=( const jUI_Color& _color ) {
		r = _color.r;
		g = _color.g;
		b = _color.b;
		a = _color.a;
	}
};

class jUI_SDL {
public:
	jUI_SDL( );

	static SDL_Renderer* renderer;

	static bool fill;
	static jUI_Color color;

};

static void jUI_NoFill() {
	jUI_SDL::fill = false;
}
static void jUI_Fill() {
	jUI_SDL::fill = true;
}
static void jUI_EnableAlphaBlending( bool _b = true ) {
	if( _b ) {
		SDL_SetRenderDrawBlendMode( jUI_SDL::renderer, SDL_BLENDMODE_BLEND );
	} else {
		SDL_SetRenderDrawBlendMode( jUI_SDL::renderer, SDL_BLENDMODE_NONE );
	}
}

static void jUI_SetColor( int _r, int _g, int _b, int _a = 255 ) {
	SDL_SetRenderDrawColor( jUI_SDL::renderer, _r, _g, _b, _a);
	jUI_SDL::color = jUI_Color( _r, _g, _b, _a );
}

static void jUI_DrawRectangle( float _x, float _y, float _w, float _h) {
	// std::cout  << "jUI_SDL::ofDrawRectangle\n";
	// std::cout  << "jUI_SDL::ofDrawRectangle " << jUI_SDL::m_renderer << std::endl;
	SDL_Rect rect;
	rect.x = _x;
	rect.y = _y;
	rect.w = _w;
	rect.h = _h;
	if( jUI_SDL::fill ) {
		SDL_RenderFillRect( jUI_SDL::renderer, &rect );
	} else {
		SDL_RenderDrawRect( jUI_SDL::renderer, &rect );
	}
}

static void set_pixel(int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
	SDL_SetRenderDrawColor( jUI_SDL::renderer, r,g,b,a);
	SDL_RenderDrawPoint( jUI_SDL::renderer, x, y);
}

static void jUI_DrawCircle_NoFill( int n_cx, int n_cy, int radius ) {
	// if the first pixel in the screen is represented by (0,0) (which is in sdl)
	// remember that the beginning of the circle is not in the middle of the pixel
	// but to the left-top from it:

	double error = (double)-radius;
	double x = (double)radius - 0.5;
	double y = (double)0.5;
	double cx = n_cx - 0.5;
	double cy = n_cy - 0.5;
	int r = jUI_SDL::color.r;
	int g = jUI_SDL::color.g;
	int b = jUI_SDL::color.b;
	int a = jUI_SDL::color.a;

	while (x >= y)
	{
		set_pixel((int)(cx + x), (int)(cy + y), r, g, b, a);
		set_pixel((int)(cx + y), (int)(cy + x), r, g, b, a);

		if (x != 0)
		{
			set_pixel((int)(cx - x), (int)(cy + y), r, g, b, a);
			set_pixel((int)(cx + y), (int)(cy - x), r, g, b, a);
		}

		if (y != 0)
		{
			set_pixel((int)(cx + x), (int)(cy - y), r, g, b, a);
			set_pixel((int)(cx - y), (int)(cy + x), r, g, b, a);
		}

		if (x != 0 && y != 0)
		{
			set_pixel((int)(cx - x), (int)(cy - y), r, g, b, a);
			set_pixel((int)(cx - y), (int)(cy - x), r, g, b, a);
		}

		error += y;
		++y;
		error += y;

		if (error >= 0)
		{
			--x;
			error -= x;
			error -= x;
		}
	}
}

static void jUI_FillCircle( int cx, int cy, int radius ) {
	double dx;
	for (double dy = 1; dy < radius; dy += 1.0) {
		// This loop is unrolled a bit, only iterating through half of the
		// height of the circle.  The result is used to draw a scan line and
		// its mirror image below it.

		// The following formula has been simplified from our original.  We
		// are using half of the width of the circle because we are provided
		// with a center and we need left/right coordinates.

		dx = floor(sqrt((2.0 * radius * dy) - (dy * dy)));
		SDL_RenderDrawLine( jUI_SDL::renderer, cx - dx, cy + dy - radius, cx + dx, cy + dy - radius);
		SDL_RenderDrawLine( jUI_SDL::renderer, cx - dx, cy - dy + radius, cx + dx, cy - dy + radius);
	}
	dx = floor(sqrt((2.0 * radius * radius) - (radius * radius)));
	SDL_RenderDrawLine( jUI_SDL::renderer, cx - dx, cy - radius + radius, cx + dx, cy - radius + radius);
}

static void jUI_DrawCircle( int n_cx, int n_cy, int radius ) {
	if( jUI_SDL::fill ) {
		jUI_FillCircle( n_cx, n_cy, radius );
	} else {
		jUI_DrawCircle_NoFill( n_cx, n_cy, radius );
	}
}
