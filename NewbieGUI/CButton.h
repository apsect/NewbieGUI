#pragma once
#include "CBaseButton.h"
#include "CLabel.h"

namespace gui {
class CButton : public CBaseButton, public CLabel
{
public:
	CButton(const std::string &textureFile, sf::Vector2f position, 
			const sf::Font& font, EState a_state = NORMAL,
			const std::string& text = std::string());

	int isMouseOver(sf::Vector2f position) const override;
	void setState(EState a_state);
	void setPosition(sf::Vector2f position);
	void setTexture(const std::string &textureFile, bool updAlignment = true);
	void setTextColor(const sf::Color &color);

	void draw(sf::RenderWindow &window) override;

protected:
	void updateTextAlignment();

protected:
	sf::Color		m_colorTextBuffer;
};
};