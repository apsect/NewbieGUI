#include <assert.h>
#include "Function.h"

namespace gui{
void alignText(sf::FloatRect field, sf::Text &text, ETextAlignment align, sf::Vector2f margin)
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
		assert(false);
	}

	text.setPosition(text.getPosition().x + margin.x, text.getPosition().y + margin.y);
}

float calculateSymbolWidth(const sf::Font &font, unsigned fontSize, bool bold)
{
	return (font.getGlyph(L'0', fontSize, bold).advance + font.getKerning(L'0', L'0', fontSize));
}
};