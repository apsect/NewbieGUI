#pragma once
#include "CBox.h"

namespace gui {
class CLabel : virtual public CBox
{
public:
	CLabel(const std::string& text, const sf::Font& font, 
		   unsigned characterSize = 30u, sf::FloatRect a_boundRect = sf::FloatRect());

	int isMouseOver(sf::Vector2f position) const override;
	sf::FloatRect getBoundRect() const;
	const sf::String& getText() const;
	const sf::Color& getTextColor() const;
	unsigned getTextCharacterSize() const;
	sf::Vector2f getTextPosition() const;

	void setTextBoundRect(sf::FloatRect a_boundRect);
	void setText(const std::string &text);
	void setTextColor(sf::Color color);
	void setCharacterSize(unsigned size);
	void setTextAlignment(ETextAlignment a_alignment, 
						  sf::Vector2f a_identAlignment = sf::Vector2f(0, 0));

	void draw(sf::RenderWindow &window) override;

protected:
	//If in text will be char like 'y' or like this - outer rectangle will have different height (height "hi" != "hiy")
	//Solution - in constructor/setFont/setFontSize we must calculate the maximum possible height
	void alignText(sf::FloatRect field, sf::Text &text, ETextAlignment align, 
						  sf::Vector2f identAlignment); 

protected:
	sf::FloatRect	m_boundRect;
	sf::Text		m_text;
	ETextAlignment	m_alignment;
	sf::Vector2f	m_identAlignment;
};
};