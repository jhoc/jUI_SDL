#include "jUI_SDL_Window.h"

jUI_SDL_Window::jUI_SDL_Window() {
TAG = "jUI_SDL_Window::";
	m_frameRate = 1000 / 60;
}

bool jUI_SDL_Window::create( std::string _windowTitle, int _windowXPos, int _windowYPos, int _windowWidth, int _windowHeight ) {
	//First we need to start up SDL, and make sure it went ok
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return false;
	}

	//init Font , SDL_ttf
	if ( TTF_Init() != 0 ){
		std::cout << "SDL_TTF_Init Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return false;
	}



	//Now create a window with title "Hello World" at 100, 100 on the screen with w:640 h:480 and show it
	m_window = SDL_CreateWindow( _windowTitle.c_str(), _windowXPos, _windowYPos, _windowWidth, _windowHeight, SDL_WINDOW_SHOWN);
	//Make sure creating our window went ok
	if ( m_window == nullptr){
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return false;
	}

	//Create a renderer that will draw to the window, -1 specifies that we want to load whichever
	//video driver supports the flags we're passing
	//Flags: SDL_RENDERER_ACCELERATED: We want to use hardware accelerated rendering
	//SDL_RENDERER_PRESENTVSYNC: We want the renderer's present function (update screen) to be
	//synchronized with the monitor's refresh rate
	jUI_SDL::renderer = SDL_CreateRenderer( m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if ( jUI_SDL::renderer == nullptr ){
		SDL_DestroyWindow( m_window );
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	if( m_listener != nullptr ) {
		m_listener->setup();
	}

	return true;
}

bool jUI_SDL_Window::close() {
	if( m_listener != nullptr ) {
		m_listener->exit();
	}
	SDL_DestroyRenderer( jUI_SDL::renderer );
	SDL_DestroyWindow( m_window );
	SDL_Quit();
	return true;
}

void jUI_SDL_Window::loop() {
	while( !m_exit ) {
		if ( (SDL_GetTicks() - m_timer) >= m_frameRate ) {
			handleInput();
			if( m_listener != nullptr ) {
				m_listener->update();
			}
			draw();
			SDL_Delay( m_frameRate );
			m_timer = SDL_GetTicks();
		}
	}
	close();
}

void jUI_SDL_Window::draw() {
	// clear
	SDL_SetRenderDrawColor( jUI_SDL::renderer, 0, 0, 0, 255);
	SDL_RenderClear( jUI_SDL::renderer );

	if( m_listener != nullptr ) {
		m_listener->draw();
	}
	//Update the screen
	SDL_RenderPresent( jUI_SDL::renderer );
}

void jUI_SDL_Window::handleInput() {
	while (SDL_PollEvent (&m_event) != 0) {
		// if ( SDL_PollEvent(&m_event) ) {
			if (m_event.type == SDL_QUIT) {
				// std::cout << TAG << "handelInput QUIT\n";
				m_exit = true;
				return;
			}
			if (m_event.type == SDL_KEYDOWN) {
				// SDL_Keysym keyPressed = m_event.key.keysym.sym;
				int keyPressed = m_event.key.keysym.scancode;
				if( m_listener != nullptr ) {
					m_listener->keyPressed( keyPressed );
				}
			}
			if (m_event.type == SDL_KEYUP) {
				// SDL_Keysym keyPressed = m_event.key.keysym.sym;
				int keyPressed = m_event.key.keysym.scancode;
				if( m_listener != nullptr ) {
					m_listener->keyReleased( keyPressed );
				}
			}
			if (m_event.type == SDL_MOUSEMOTION) {
				if( m_listener != nullptr ) {
					m_listener->mouseMoved( m_event.motion.x, m_event.motion.y );
				}
			}
			if (m_event.type == SDL_MOUSEBUTTONDOWN) {
				if( m_listener != nullptr ) {
					m_listener->mousePressed( m_event.motion.x, m_event.motion.y, m_event.button.button );
				}
			}
			if (m_event.type == SDL_MOUSEBUTTONUP) {
				if( m_listener != nullptr ) {
					m_listener->mouseReleased( m_event.motion.x, m_event.motion.y, m_event.button.button );
				}
			}
		}
	// }
}

void jUI_SDL_Window::setListener(jUI_SDL_Window_Listener* _listener) {
	m_listener = _listener;
}
