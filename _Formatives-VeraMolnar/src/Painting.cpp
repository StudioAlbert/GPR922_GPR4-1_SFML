#include "Painting.h"

void Painting::Init() {

	window.create(sf::VideoMode(800, 600), "Fireball : The Game");

	// Basic Setup of the window
	// Vertical sync, framerate
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(30);

}

bool Painting::IsOpen()
{
	return window.isOpen();
}

void Painting::CheckInputs()
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();

		ManageEvents(event);

	}
}

void Painting::Display() {

	// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
	// Graphical Region
	window.clear(sf::Color::Black);

	Draw();

	// Window Display
	window.display();

}

void Painting::Update()
{

}
