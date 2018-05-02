#include "CRadioButton.h"
#include <iostream>

namespace gui{
CRadioButton::CRadioButton(const std::string &highlightTextureFile)
{
	m_tex_highlight.loadFromFile(highlightTextureFile);
	m_spr_highlight.setTexture(m_tex_highlight);
}

void CRadioButton::addNewButton(const std::string &textureFile, sf::Vector2f position,
								EState a_buttonState)
{
	m_buttons.push_back(new CBaseButton(textureFile, position, a_buttonState));
}

int CRadioButton::isMouseOverButtons(sf::Vector2f position) const
{
	for (unsigned index = 0; index < m_buttons.size(); index++)
		if (m_buttons[index]->isMouseOver(position))
			return index;
	return NEGATIVE;
}

void CRadioButton::changeButtonState(EState a_buttonState, int item)
{
	if (item == EXECUTE_FOR_ALL)
	{
		for (auto iter = m_buttons.begin(); iter != m_buttons.end(); iter++)
			(*iter)->setState(a_buttonState);
		return;
	}
		
	m_buttons[item]->setState(a_buttonState);
}

void CRadioButton::setCheckedButton(int item)
{
	m_currentItem = item;
	m_spr_highlight.setPosition(m_buttons[item]->getPosition());
}

void CRadioButton::changePositionButton(sf::Vector2f position, int item)
{
	m_buttons[item]->setPosition(position);
	if (item == m_currentItem)
		m_spr_highlight.setPosition(m_buttons[item]->getPosition());
}

void CRadioButton::changeTextureButton(const std::string &textureFile, int item)
{
	if (item == EXECUTE_FOR_ALL)
	{
		for (auto iter = m_buttons.begin(); iter != m_buttons.end(); iter++)
			(*iter)->setTexture(textureFile);
		return;
	}
		
	m_buttons[item]->setTexture(textureFile);
}

void CRadioButton::changeHighlight(const std::string &textureFile)
{
	m_tex_highlight.loadFromFile(textureFile);
	m_spr_highlight.setTexture(m_tex_highlight, true);
}

void CRadioButton::draw(sf::RenderWindow &a_window) 
{
	for (auto iter = m_buttons.begin(); iter != m_buttons.end(); iter++)
		(*iter)->draw(a_window);
	a_window.draw(m_spr_highlight);
}
};