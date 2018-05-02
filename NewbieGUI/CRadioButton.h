#pragma once
#include "CButton.h"

namespace gui {
class CRadioButton
{
public:
	CRadioButton(const std::string &highlightTextureFile);
	void addNewButton(const std::string &textureFile, sf::Vector2f position,
					  EState a_buttonState = NORMAL);
	int isMouseOverButtons(sf::Vector2f position) const;
	void changeButtonState(EState a_buttonState, int item = EXECUTE_FOR_ALL);
	void setCheckedButton(int item);
	void changePositionButton(sf::Vector2f position, int item);
	void changeTextureButton(const std::string &textureFile, int item = EXECUTE_FOR_ALL);
	void changeHighlight(const std::string &textureFile);
	void draw(sf::RenderWindow &a_window); 

private:
	std::vector<CBaseButton*> m_buttons;
	unsigned m_currentItem;
	sf::Texture m_tex_highlight;
	sf::Sprite m_spr_highlight;
};
};