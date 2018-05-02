#pragma once
#include "CBox.h"

namespace gui {
class CBaseButton : virtual public CBox
{
public:
	CBaseButton(const std::string &textureFile, sf::Vector2f position,
				EState a_state = NORMAL);

	int isMouseOver(sf::Vector2f position) const override;
	EState getState() const;
	sf::Vector2f getPosition() const;

	void setState(EState a_state, bool isInit = false);
	void setPosition(sf::Vector2f position);
	void setTexture(const std::string &textureFile);

	void draw(sf::RenderWindow &window) override;

protected:
	EState			m_state;
	sf::Texture		m_tex_button;
	sf::Sprite		m_spr_button;
};
};