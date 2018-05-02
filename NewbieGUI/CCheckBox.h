#pragma once
#include "CBaseButton.h"

namespace gui {
class CCheckBox : public CBaseButton
{
public:
	CCheckBox(const std::string &textureFile, sf::Vector2f position,
			  const std::string &checkedTextureFile, 
			  EState a_state = NORMAL, bool a_checked = false);

	bool getChecked();
	void setChecked(bool a_checked);
	void setTextureChecked(const std::string &checkedTextureFile);
	void setPosition(sf::Vector2f position);

	void draw(sf::RenderWindow &window) override;

protected:
	sf::Texture m_tex_checked;
	sf::Sprite m_spr_checked;
	bool m_checked;
};
};