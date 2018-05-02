#include "CSpinButton.h"

namespace gui {
CSpinButton::CSpinButton(const std::string &arrowTextureFile, sf::Vector2f position):
	m_isVerticalOrientated(true),
	m_currentValue(50),
	m_distanceBetweenArrows(0),
	m_range(0, 100)
{
	m_tex_arrow.loadFromFile(arrowTextureFile);
	m_spr_topArrow.setTexture(m_tex_arrow);
	m_spr_topArrow.setPosition(position);

	m_spr_bottomArrow.setTexture(m_tex_arrow);
	m_spr_bottomArrow.setRotation(180.f);
	m_spr_bottomArrow.setPosition(position.x, position.y + m_tex_arrow.getSize().y);
}

int CSpinButton::isMouseOver(sf::Vector2f position) const
{
	if (m_spr_topArrow.getGlobalBounds().contains(position))
		return ARROW_TOP;
	if (m_spr_bottomArrow.getGlobalBounds().contains(position))
		return ARROW2_BUTTOM;
	else
		return false;
}

void CSpinButton::add(int value)
{
	if ((m_currentValue + value) <= m_range.x &&
		(m_currentValue + value) >= m_range.y)
	m_currentValue += value;
}

void CSpinButton::setPosition(sf::Vector2f position, int whatItem)
{
}

void CSpinButton::setBoundRect(sf::FloatRect a_boundRect)
{
}

void CSpinButton::setTexture(const std::string &arrowTextureFile, int whatItem)
{
}

void CSpinButton::setRange(sf::Vector2i a_diapason)
{
	m_range = a_diapason;
}

void CSpinButton::setVerticalOrientated(bool a_isVerticalOrientated)
{
}

void CSpinButton::setDistanceBetweenArrows(int a_dictanceBetwenArrows)
{
	m_distanceBetweenArrows = a_dictanceBetwenArrows;
}

void  CSpinButton::moveBottomArrow()
{
	if (m_isVerticalOrientated)
		m_spr_bottomArrow.setPosition(m_spr_topArrow.getGlobalBounds().left, 
									  m_spr_topArrow.getGlobalBounds().top + 
										m_tex_arrow.getSize().y + m_distanceBetweenArrows);
	else
		m_spr_bottomArrow.setPosition(m_spr_topArrow.getGlobalBounds().left + 
										m_tex_arrow.getSize().x + m_distanceBetweenArrows, 
									  m_spr_topArrow.getGlobalBounds().top);
}

void CSpinButton::draw(sf::RenderWindow &window)
{
	if (!m_isVisible)
		return;

	window.draw(m_spr_topArrow);
	window.draw(m_spr_bottomArrow);
}
};