#pragma once
#include "CBox.h"

namespace gui {
class CSpinButton : public CBox
{
public:
	CSpinButton(const std::string &arrowTextureFile, sf::Vector2f position);

	int isMouseOver(sf::Vector2f position) const override;
	void add(int value);
	void setPosition(sf::Vector2f position, int whatItem = ARROWS);
	void setBoundRect(sf::FloatRect a_boundRect);
	void setTexture(const std::string &arrowTextureFile, int whatItem = ARROWS);
	void setRange(sf::Vector2i position);
	void setVerticalOrientated(bool a_isVerticalOrientated);
	void setDistanceBetweenArrows(int a_distanceBetweenArrows);

	void draw(sf::RenderWindow &window) override;

protected:
	void moveBottomArrow();

protected:
	bool			m_isVerticalOrientated;
	int				m_currentValue;
	int				m_distanceBetweenArrows;
	sf::Vector2i	m_range;
	sf::Texture		m_tex_arrow;
	sf::Sprite		m_spr_topArrow;
	sf::Sprite		m_spr_bottomArrow;
};
};