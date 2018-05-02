#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Function.h"

namespace gui {
class CBox
{
public:
	CBox(bool a_isVisible = true): m_isVisible(a_isVisible) {}

	virtual int isMouseOver(sf::Vector2f position) const = 0;
	bool getVisible() const					{return m_isVisible;}
	void setVisible(bool a_isVisible)		{m_isVisible = a_isVisible;}

	virtual void draw(sf::RenderWindow&) = 0;

protected:
	bool			m_isVisible;
};
};