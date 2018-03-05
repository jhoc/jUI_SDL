#include "jUI_App.h"

void jUI_App::setup() {
	std::cout << TAG << "setup\n";
	jUI_EnableAlphaBlending();

	m_image.load( jUI_SDL_FilePath::getResourcePath("Hello_World") + "hello.bmp" );
	m_font.load(  jUI_SDL_FilePath::getResourcePath("Hello_World") + "sample.ttf", 20 );
}

void jUI_App::update() {
	// std::cout << TAG << "update\n";
}

void jUI_App::draw() {
	// std::cout << TAG << "draw\n";
	// m_image.draw();

	jUI_SetColor( 0, 0, 155 );
	jUI_Fill();
	jUI_DrawRectangle( m_mouseXPos, m_mouseYPos, 60, 60 );
	jUI_SetColor( 0, 255, 0, 100 );
	jUI_DrawRectangle( m_mouseXPos - 30, m_mouseYPos - 30, 60, 60 );

	jUI_SetColor( 255, 0, 0, 100 );
	// jUI_NoFill();
	jUI_DrawCircle( m_mouseXPos, m_mouseYPos, 70 );

	m_font.drawString( "Winnie", m_mouseXPos, m_mouseYPos );
}

void jUI_App::exit() {
	std::cout << TAG << "exit\n";
}


void jUI_App::keyPressed(int key) {
	std::cout << TAG << "key " << key << std::endl;
}

void jUI_App::keyReleased(int key) {
	std::cout << TAG << "keyReleased " << key << std::endl;
}

void jUI_App::mouseMoved(int x, int y) {
	// std::cout << TAG << "mouseMoved " << x << ", " << y<< std::endl;
	m_mouseXPos = x;
	m_mouseYPos = y;

	m_image.setPos( x, y );
}

void jUI_App::mouseDragged(int x, int y, int button) {
	std::cout << TAG << "mouseDragged " << x << ", " << y<< std::endl;
}

void jUI_App::mousePressed(int x, int y, int button) {
	std::cout << TAG << "mousePressd " << x << ", " << y << ", btn:" << button << std::endl;
}

void jUI_App::mouseReleased(int x, int y, int button) {
	std::cout << TAG << "mouseReleased " << x << ", " << y << ", btn:" << button << std::endl;
}

void jUI_App::mouseEntered(int x, int y) {

}

void jUI_App::mouseExited(int x, int y) {

}

void jUI_App::mouseScrolled(int x, int y, float scrollX, float scrollY) {

}


void jUI_App::windowResized(int w, int h) {

}
