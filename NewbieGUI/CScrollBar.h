#pragma once
#include "CBaseButton.h"

namespace gui {
class CScrollBar
{
public:
	CScrollBar(sf::Vector2f firstArrowPosition, float distanceBetweenArrows,
			   const std::string &arrowTextureFile, bool a_vertical = true);
	int isMouseOverButtons(sf::Vector2f &position) const;
	void setArrowTexture(const std::string &textureFile);
	void setJumplineTexture(const std::string &textureFile);
	void setCursorTexture(const std::string &textureFile);

	void setUseJumpline(bool a_useJumpline);
	void setVisible(bool a_visible);
	void setDistanceBetweenArrows(int m_distance);
	void setRange(sf::Vector2f a_diapason);
	void setScrolledZone(sf::FloatRect a_scroledZone);
	void setPosition(const sf::Vector2f &position);

	bool getUseJumpline() const;
	bool getVisible() const;
	int getDistanceArrow() const;
	sf::Vector2f getDiapason() const;
	const sf::FloatRect& getScrolledZone() const;
	sf::Vector2f getPosition() const;

	void draw(sf::RenderWindow &window);

protected:
	sf::Texture		m_tex_arrow;
	sf::Sprite		m_spr_arrow1;
	sf::Sprite		m_spr_arrow2;
	sf::Texture		m_tex_jumpline;
	sf::Sprite		m_spr_jumpline;
	sf::Texture		m_tex_cursor;
	sf::Sprite		m_spr_cursor;

	bool			m_isUseJumpline;
	bool			m_isVisible;
	float			m_distanceBetweenArrows;
	sf::Vector2i	m_range;
	sf::FloatRect	m_scroledZone;
};
};