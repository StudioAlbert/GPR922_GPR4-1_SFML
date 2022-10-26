#include "Link.h"

#include <iostream>

constexpr float SPEED = 8.0f;

Link::Link()
{

	_up.loadFromFile("data/sprites/ZeldaUp.png");
	_down.loadFromFile("data/sprites/ZeldaDown.png");
	_left.loadFromFile("data/sprites/ZeldaLeft.png");
	_right.loadFromFile("data/sprites/ZeldaRight.png");

	// Using a sprite
	// https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1Sprite.php
	_sprite.setTexture(_up);
	_sprite.setOrigin(_up.getSize().x / 2.0f, _up.getSize().y / 2.0f);
	setPosition(400, 300);
	
}

void Link::Move(const sf::Vector2f& direction)
{
	ChangeTexture(direction);

	// Move the sprite
	auto position = getPosition();
	position += (direction * SPEED);
	setPosition(position);

}

void Link::ChangeTexture(const sf::Vector2f& direction)
{
	if (direction.x > 0)
		_sprite.setTexture(_right);

	if (direction.x < 0)
		_sprite.setTexture(_left);

	if (direction.y > 0)
		_sprite.setTexture(_down);

	if (direction.y < 0)
		_sprite.setTexture(_up);

}

void Link::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	std::cout << "Drawing Link" << std::endl;

	states.transform *= getTransform();

	// You can draw other high-level objects
	target.draw(_sprite, states);

}
