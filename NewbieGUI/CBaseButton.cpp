#include "CBaseButton.h"

namespace gui {
CBaseButton::CBaseButton(const std::string &textureFile, sf::Vector2f position, 
						 EState a_state):
	m_state(EState(-1))
{
	m_tex_button.loadFromFile(textureFile);
	m_spr_button.setTexture(m_tex_button);
	m_spr_button.setPosition(position);
	setState(a_state, true);
}

int CBaseButton::isMouseOver(sf::Vector2f position) const
{
	if ((m_state == NORMAL || m_state == OVER) && m_isVisible)
		return m_spr_button.getGlobalBounds().contains(position);
	return false;
}

EState CBaseButton::getState() const
{
	return m_state;
}

sf::Vector2f CBaseButton::getPosition() const
{
	return m_spr_button.getPosition();
}

void CBaseButton::setState(EState a_state, bool isInit)
{
	if (!isInit && m_state == a_state)
		return;

	switch (a_state) {
	case NORMAL:
		m_spr_button.setColor(BUTTON_NORMAL);
		break;

	case OVER:
		m_spr_button.setColor(BUTTON_HIGHLIGHT);
		break;

	case DISABLED:
		m_spr_button.setColor(BUTTON_SHADE);
		break;

	default:
		return;
	}

	m_state = a_state;	
}

void CBaseButton::setPosition(sf::Vector2f position)
{
	m_spr_button.setPosition(position);
}

void CBaseButton::setTexture(const std::string &textureFile)
{
	m_tex_button.loadFromFile(textureFile);
	m_spr_button.setTexture(m_tex_button, true);
}

void CBaseButton::draw(sf::RenderWindow &window)
{
	if (!m_isVisible)
		return;

	window.draw(m_spr_button);
}
};