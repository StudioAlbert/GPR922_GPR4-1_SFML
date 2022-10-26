#pragma once

#include "SFML\Graphics.hpp"

class Link : public sf::Drawable, public sf::Transformable
{
private:
	// Loading a file as texture
	sf::Texture _up;
	sf::Texture _down;
	sf::Texture _left;
	sf::Texture _right;

	sf::Sprite _sprite;

	void ChangeTexture(const sf::Vector2f& direction);

public:
	Link();

	void Move(const sf::Vector2f& direction);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


