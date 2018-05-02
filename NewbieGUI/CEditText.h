#pragma once
#include "CButton.h"

namespace gui {
class CEditBox : public CButton
{
public:
	CEditBox(const std::string &textureFile, sf::Vector2f position, 
			 const sf::Font &textFont, const std::string &cursorTextureFile, 
			 EState a_state = NORMAL);
	
	bool getActive();
	const std::string& getText();

	void setActive(bool a_active);
	void setText(const std::string &text, unsigned a_cursorIndex = 0);
	void setMaxTextSymbols(unsigned a_maxTextSymbols);
	void setPosition(sf::Vector2f position);
	void setTexture(const std::string &textureFile);
	void setCharacterSize(unsigned size);

	void addSymbol(sf::Uint32 symbol);
	void removeSymbol();
	void moveCursorUp(bool up);

	void draw(sf::RenderWindow &window) override;

protected:
	unsigned calculateVisibleRange();
	void updateCursorPosition();
	void updateVisibleText();
	void updateTextField();
	void updateTextAlignment();

protected:
	std::string		m_allText;
	std::string		m_visibleText;
	sf::Texture		m_tex_cursor;
	sf::Sprite		m_spr_cursor;
	bool			m_active;
	unsigned		m_cursorIndex;
	unsigned		m_visibleRangeText;
	unsigned		m_lowerVisibleSymbol;
	unsigned		m_maxTextSymbols;
	float			m_symbolWidth;
};
};