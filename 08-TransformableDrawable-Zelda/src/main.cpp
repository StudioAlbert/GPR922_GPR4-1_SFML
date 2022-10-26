// SAE921-GPR4100-SFML-03c-Events.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>

#include "SFML/Main.hpp"
#include "SFML/Graphics.hpp"

#include "Link.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML First Window");
	Link link;

	// Basic Setup of the window
	// Vertical sync, framerate
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(30);
	// Setting up thh events
	window.setKeyRepeatEnabled(true);

	while (window.isOpen())
	{

		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		sf::Event event;

		while (window.pollEvent(event))
		{

			switch (event.type)
			{
				// évènement "fermeture demandée" : on ferme la fenêtre
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				// Test de la valeur de la touche
				std::cout << "Key pressed : " << event.key.code << std::endl;
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					std::cout << "UP ^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
					link.Move(sf::Vector2f(0, -1));
					break;

				case sf::Keyboard::Down:
					std::cout << "DOWN vvvvvvvvvvvvvvvvvvvvvvvvvvv" << std::endl;
					link.Move(sf::Vector2f(0, 1));
					break;

				case sf::Keyboard::Left:
					std::cout << "LEFT <<<<<<<<<<<<<<<<<<<<<<<<<<<" << std::endl;
					link.Move(sf::Vector2f(-1, 0));
					break;

				case sf::Keyboard::Right:
					std::cout << "RIGHT >>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
					link.Move(sf::Vector2f(1,0));
					break;

				default:
					break;
				}
				break;

			default:
				break;
			}


		}

		// Window Display
		window.clear(sf::Color::Black);
		window.draw(link);
		window.display();

	}

}
