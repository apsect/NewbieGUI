#include "CButton.h"

namespace gui {
CButton::CButton(const std::string &textureFile, sf::Vector2f position, 
				 const sf::Font& font, EState a_state,
				 const std::string& text):
	CBaseButton(textureFile, position, a_state),
	CLabel(text, font),
	m_colorTextBuffer(0, 0, 0, 255)
{
	m_boundRect = m_spr_button.getGlobalBounds();
}

int CButton::isMouseOver(sf::Vector2f position) const
{
	return CBaseButton::isMouseOver(position);
}

void CButton::setState(EState a_state)
{
	if (m_state == a_state)
		return;

	if (m_state == DISABLED)
		m_text.setFillColor(m_colorTextBuffer);

	switch (a_state) {
	case NORMAL:
		m_spr_button.setColor(BUTTON_NORMAL);
		break;

	case OVER:
		m_spr_button.setColor(BUTTON_HIGHLIGHT);
		break;

	case DISABLED:
		m_spr_button.setColor(BUTTON_SHADE);
		m_colorTextBuffer = m_text.getFillColor();
		m_text.setFillColor(TEXT_SHADE);
		break;

	default:
		return;
	}

	m_state = a_state;	
}

void CButton::setPosition(sf::Vector2f position)
{
	m_spr_button.setPosition(position);
	updateTextAlignment();
}

void CButton::setTexture(const std::string &textureFile, bool updAlignment)
{
	m_tex_button.loadFromFile(textureFile);
	m_spr_button.setTexture(m_tex_button, true);
	if (updAlignment)
		updateTextAlignment();
}

void CButton::setTextColor(const sf::Color &color)
{
	if (m_state != DISABLED)
		m_text.setFillColor(color);
	else
		m_colorTextBuffer = color;
}

void CButton::updateTextAlignment()
{
	m_boundRect = m_spr_button.getGlobalBounds();
	CLabel::alignText(m_boundRect, m_text, m_alignment, m_identAlignment);
}

void CButton::draw(sf::RenderWindow &window)
{
	if (!m_isVisible)
		return;

	window.draw(m_spr_button);
	window.draw(m_text);
}
};