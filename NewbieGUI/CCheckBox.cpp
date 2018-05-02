#include "CCheckBox.h"

namespace gui {
CCheckBox::CCheckBox(const std::string &textureFile, sf::Vector2f position,
					 const std::string &checkedTextureFile, 
					 EState a_state, bool a_checked):
	CBaseButton(textureFile, position, a_state),
	m_checked(a_checked)
{
	m_tex_checked.loadFromFile(checkedTextureFile);
	m_spr_checked.setTexture(m_tex_checked);
	m_spr_checked.setPosition(position);
}

void CCheckBox::setChecked(bool a_checked) 
{
	m_checked = a_checked;
}

bool CCheckBox::getChecked() 
{
	return m_checked;
}

void CCheckBox::setTextureChecked(const std::string &checkedTextureFile) 
{
	m_tex_checked.loadFromFile(checkedTextureFile);
	m_spr_checked.setTexture(m_tex_checked, true);
}

void CCheckBox::setPosition(sf::Vector2f position)
{
	CBaseButton::setPosition(position);
	m_spr_checked.setPosition(position);
}

void CCheckBox::draw(sf::RenderWindow &window)
{
	if (!m_isVisible)
		return;

	window.draw(m_spr_button);
	if (m_checked)
		window.draw(m_spr_checked);
}
};