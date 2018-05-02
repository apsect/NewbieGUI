#pragma once
#include <SFML\Graphics\Rect.hpp>
#include <SFML\Graphics\Text.hpp>

namespace gui {
const float DEFAULT_MARGIN_WIDTH		(10.f);
const unsigned int MAX_VISIBLE_SYMBOLS	(5);
const int NEGATIVE						(-1);
const int EXECUTE_FOR_ALL				(-2);
const sf::Color BUTTON_HIGHLIGHT		(sf::Color(255, 255, 255, 255));
const sf::Color BUTTON_NORMAL			(sf::Color(224, 224, 224, 255));
const sf::Color BUTTON_SHADE			(sf::Color(160, 160, 160, 255));
const sf::Color TEXT_SHADE				(sf::Color(32, 32, 32, 255));

enum ETextAlignment
{
	TOPLEFT,
	TOP,
	TOPRIGHT,
	LEFT,
	CENTER,
	RIGHT,
	BUTTOMLEFT,
	BUTTOM,
	BUTTOMRIGHT
};

enum EState {
	NORMAL = 20,
	OVER,
	DISABLED
};

enum ESpinButtonItems
{
	ARROWS = 40,
	ARROW_TOP,
	ARROW2_BUTTOM,
	CURSOR,
	JUMPLINE
};

void alignText(sf::FloatRect field, sf::Text &text, ETextAlignment align, 
					  sf::Vector2f margin = sf::Vector2f());
float calculateSymbolWidth(const sf::Font &font, unsigned fontSize = 30u, bool bold = false);
};