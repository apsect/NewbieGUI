#include "CEditText.h"

namespace gui {
CEditBox::CEditBox(const std::string &textureFile, sf::Vector2f position, 
				   const sf::Font &textFont, const std::string &cursorTextureFile, 
				   EState a_state):
	CButton				(textureFile, position, textFont, a_state), 
	m_active			(false),
	m_cursorIndex		(0),
	m_visibleRangeText	(0),
	m_lowerVisibleSymbol(0),
	m_symbolWidth		(calculateSymbolWidth(textFont)),
	m_maxTextSymbols	(32)
{
	m_tex_cursor.loadFromFile(cursorTextureFile);
	m_spr_cursor.setTexture(m_tex_cursor);
	m_spr_cursor.setOrigin(m_tex_cursor.getSize().x / 2.f, 0);
	m_spr_cursor.setColor(sf::Color::Red);
	CLabel::setTextAlignment(TOPLEFT, sf::Vector2f(DEFAULT_MARGIN_WIDTH, 0));
	m_visibleRangeText = calculateVisibleRange();
	updateCursorPosition();
}

bool CEditBox::getActive()
{
	return m_active;
}

const std::string& CEditBox::getText()
{
	return m_allText;
}

void CEditBox::setActive(bool a_active)
{
	m_active = a_active;
}

void CEditBox::setText(const std::string &text, unsigned a_cursorIndex)
{
	if (text.size() > m_maxTextSymbols)
		m_allText.assign(text.begin() + (text.size() - m_maxTextSymbols), text.end());
	else
		m_allText = text;

	m_cursorIndex = m_allText.size();
	if (m_allText.size() > m_visibleRangeText)
		m_lowerVisibleSymbol = m_allText.size() - m_visibleRangeText;
	else 
		m_lowerVisibleSymbol = 0;

	updateTextField();
}

void CEditBox::setMaxTextSymbols(unsigned a_maxTextSymbols)
{
	m_maxTextSymbols = a_maxTextSymbols;
}

void CEditBox::setPosition(sf::Vector2f position)
{
	CButton::setPosition(position);
	updateCursorPosition();
}

void CEditBox::setTexture(const std::string &textureFile)
{
	CButton::setTexture(textureFile, false);
	m_visibleRangeText = calculateVisibleRange();
	updateTextAlignment();
	updateCursorPosition();
}

void CEditBox::setCharacterSize(unsigned size)
{
	m_text.setCharacterSize(size);
	m_symbolWidth = calculateSymbolWidth(*m_text.getFont(), size);
	m_visibleRangeText = calculateVisibleRange();
	updateTextField();
}

void CEditBox::addSymbol(sf::Uint32 symbol)
{	
	if (m_allText.size() >= m_maxTextSymbols)
		return;

	m_allText.insert(m_cursorIndex, sf::String(symbol));
	moveCursorUp(true);
}

void CEditBox::removeSymbol()
{
	if (!(m_allText.size() && m_cursorIndex))
		return;
	
	m_allText.erase(m_cursorIndex - 1, 1);
	if (m_lowerVisibleSymbol)
		--m_lowerVisibleSymbol;
	moveCursorUp(false);
}

void CEditBox::moveCursorUp(bool up)
{
	if (up && (m_allText.size() > m_cursorIndex))
	{
		if (++m_cursorIndex > (m_lowerVisibleSymbol + m_visibleRangeText))
		{
			++m_lowerVisibleSymbol;
		}
	}
	else if (!up && m_cursorIndex)
	{
		if (--m_cursorIndex < m_lowerVisibleSymbol)
		{
			--m_lowerVisibleSymbol;
		}
	}
	else
		return;

	updateTextField();
}

unsigned CEditBox::calculateVisibleRange()
{
	return static_cast<unsigned>(
		(m_spr_button.getGlobalBounds().width - (m_identAlignment.x * 2)) / m_symbolWidth);
}

void CEditBox::updateCursorPosition()
{
	if (m_allText.size())
	{
		sf::Vector2f currentPos(m_text.getPosition());
		m_spr_cursor.setPosition(currentPos.x + 
							   ((m_cursorIndex - m_lowerVisibleSymbol) * m_symbolWidth), 
								 currentPos.y );
	}
	else
	{
		sf::Vector2f currentPos(m_spr_button.getPosition()); //?
		m_spr_cursor.setPosition(currentPos.x + (m_cursorIndex * m_symbolWidth) + m_identAlignment.x, 
								 currentPos.y);
	}
}

void CEditBox::updateVisibleText()
{
	m_visibleText.assign(m_allText.begin() + m_lowerVisibleSymbol, 
						(m_allText.size()  > m_visibleRangeText)?
						 m_allText.begin() + m_lowerVisibleSymbol + m_visibleRangeText :
						 m_allText.end());

	m_text.setString(m_visibleText);
}

void CEditBox::updateTextField()
{
	updateVisibleText();
	updateTextAlignment();
	updateCursorPosition();
}

void CEditBox::updateTextAlignment()
{
	if (static_cast<int>(m_alignment) % 3)
		return;

	CLabel::alignText(m_boundRect, m_text, m_alignment, m_identAlignment);
}

void CEditBox::draw(sf::RenderWindow &window)
{
	if (!m_isVisible)
		return;

	window.draw(m_spr_button);
	window.draw(m_text);
	if (m_active)
		window.draw(m_spr_cursor);
}
};