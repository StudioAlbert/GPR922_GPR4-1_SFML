

#include <iostream>

#include "SFML/Main.hpp"
#include "SFML/Graphics.hpp"

#include "Painting.h"

int main()
{
	// Create the game
	Painting paintingA, paintingB;

	// Init the game
	paintingA.Init();
	paintingB.Init();

	// Run the game
	while (paintingA.IsOpen() || paintingB.IsOpen())
	{
		paintingA.CheckInputs();
		paintingB.CheckInputs();

		paintingA.Update();
		paintingB.Update();

		paintingA.Display();
		paintingB.Display();

	}

	return EXIT_SUCCESS;

}
