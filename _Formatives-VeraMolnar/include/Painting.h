#pragma once

#include "SFML/Graphics.hpp"

class Painting
{

private:
	sf::RenderWindow window;

public:
	void Init();

	void Update();
	void CheckInputs();
	void Display();

	bool IsOpen();

protected:
	virtual void ManageEvents(sf::Event event) = 0;
	virtual void Draw() = 0;
};
