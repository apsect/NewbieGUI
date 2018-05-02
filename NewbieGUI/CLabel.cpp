#include "CLabel.h"

namespace gui {
CLabel::CLabel(const std::string& text, const sf::Font& font, 
			   unsigned characterSize, sf::FloatRect a_boundRect):
	m_text(text, font, characterSize),
	m_boundRect(a_boundRect)
{
	setTextAlignment(TOP);
	if (text.size())
		alignText(m_boundRect, m_text, m_alignment, m_identAlignment);
}

int CLabel::isMouseOver(sf::Vector2f position) const
{
	return (m_text.getGlobalBounds().contains(position) && m_isVisible);
}

sf::FloatRect CLabel::getBoundRect() const
{
	return m_boundRect;
}

const sf::String& CLabel::getText() const
{
	return m_text.getString();
}

const sf::Color& CLabel::getTextColor() const
{
	return m_text.getFillColor();
}

unsigned CLabel::getTextCharacterSize() const
{
	return m_text.getCharacterSize();
}

sf::Vector2f CLabel::getTextPosition() const
{
	return m_text.getPosition();
}

void CLabel::setTextBoundRect(sf::FloatRect a_boundRect)
{
	m_boundRect = a_boundRect;
	alignText(m_boundRect, m_text, m_alignment, m_identAlignment);
}

void CLabel::setText(const std::string &text)
{
	m_text.setString(text);
	if (text.size())
		alignText(m_boundRect, m_text, m_alignment, m_identAlignment); 
}

void CLabel::setTextColor(sf::Color color)
{
	m_text.setFillColor(color);
}

void CLabel::setCharacterSize(unsigned size)
{
	m_text.setCharacterSize(size);
	alignText(m_boundRect, m_text, m_alignment, m_identAlignment);
}

void CLabel::setTextAlignment(ETextAlignment a_alignment, 
							  sf::Vector2f a_identAlignment)
{
	m_alignment = a_alignment;
	m_identAlignment = a_identAlignment;
	alignText(m_boundRect, m_text, m_alignment, m_identAlignment);
}

void CLabel::alignText(sf::FloatRect field, sf::Text &text, ETextAlignment align, 
						sf::Vector2f identAlignment)
{
	sf::FloatRect textRect(text.getGlobalBounds());
	switch (align) {
	case TOPLEFT:
		text.setPosition(field.left, field.top);
		break;

	case TOP:
		text.setPosition(field.left + (field.width / 2.f) - (textRect.width / 2.f), 
						 field.top);
		break;

	case TOPRIGHT:
		text.setPosition(field.left + field.width - textRect.width, 
						 field.top);
		break;

	case LEFT:
		text.setPosition(field.left, 
						 field.top + (field.height / 2.f) - (textRect.height / 2.f));
		break;

	case CENTER:
		text.setPosition(field.left + (field.width / 2.f) - (textRect.width / 2.f), 
						 field.top + (field.height / 2.f) - (textRect.height / 2.f));
		break;

	case RIGHT:
		text.setPosition(field.left + field.width - textRect.width, 
						 field.top + (field.height / 2.f) - (textRect.height / 2.f));
		break;

	case BUTTOMLEFT:
		text.setPosition(field.left, 
						 field.top + field.height - textRect.height);
		break;

	case BUTTOM:
		text.setPosition(field.left + (field.width / 2.f) - (textRect.width / 2.f),
						 field.top + field.height - textRect.height);
		break;

	case BUTTOMRIGHT:
		text.setPosition(field.left + field.width - textRect.width, 
						 field.top + field.height - textRect.height);
		break;

	default:
		return;
	}
	
	text.setPosition(text.getPosition().x + identAlignment.x, 
					 text.getPosition().y + identAlignment.y);	
}

void CLabel::draw(sf::RenderWindow &window)
{
	if (!m_isVisible)
		return;

	window.draw(m_text);
}
};