#include <iostream>
#include <SFML/Graphics.hpp>
#include "Function.h"
#include "CLabel.h"
#include "CBaseButton.h"
#include "CButton.h"
#include "CEditText.h"
#include "CCheckBox.h"
#include "CRadioButton.h"

using namespace std;

int main() 
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "GuiTest");
	window.setFramerateLimit(60);
	window.setMouseCursorVisible(false);
	sf::CircleShape cursor;
	cursor.setFillColor(sf::Color::Red);
	cursor.setRadius(2.f);
	sf::Texture texture;
	texture.loadFromFile("oM0m0.png");
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sf::Event event;

	sf::Font font;
	font.loadFromFile("DroidSansMono.ttf");

	//RadioButton
	/*int buff;
	gui::CRadioButton radiobutton("radiobuttonchecked1.png");
	radiobutton.addNewButton("radiobutton1.png", sf::Vector2f(200, 200));
	radiobutton.addNewButton("radiobutton1.png", sf::Vector2f(264, 200));
	radiobutton.addNewButton("radiobutton1.png", sf::Vector2f(200, 264), gui::DISABLED);
	radiobutton.addNewButton("radiobutton1.png", sf::Vector2f(264, 264), gui::DISABLED);
	radiobutton.setCheckedButton(1);*/

	//CheckBox
	/*gui::CCheckBox checkbox("checkbox1.png", sf::Vector2f(200, 200), "checked1.png");*/

	//EditText
	/*gui::CEditBox editbox("edittext.png", sf::Vector2f(30, 200), font, "cursor.png");
	editbox.setActive(true);
	editbox.setTextColor(sf::Color::Green);
	editbox.setText("Hello, Droid");*/

	//Button
	//srand(static_cast<unsigned int>(time(0)));
	//gui::CButton button("button1.png", sf::Vector2f(200, 200), font);
	////button.setText("Hi ^^!");
	//button.setCharacterSize(30u);
	//button.setTextColor(sf::Color(64, 0, 140));

	//BaseButton
	/*gui::CBaseButton basebutton("button1.png", sf::Vector2f(200, 200));*/

	//Label
	/*gui::CLabel label("hello", font, 24u, sf::FloatRect(0, 0, 640, 480));
	label.setTextColor(sf::Color::Black);*/

	//Function
	/*sf::Text text;
	text.setString("AAA");
	text.setFillColor(sf::Color(64, 0, 128));
	text.setCharacterSize(45u);
	text.setStyle(sf::Text::Bold);
	text.setFont(font);
	alignText(sf::Rect<float>(320, 240, 320, 240), text, gui::TOPLEFT);*/

    while (window.isOpen())
    {
		//sf::Vector2i pixelPos(sf::Mouse::getPosition(window));
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

			//RadioButton
			/*if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				radiobutton.changeButtonState(gui::NORMAL, 2);
				radiobutton.changeButtonState(gui::NORMAL, 3);
			}

			if (event.type == sf::Event::MouseButtonPressed && 
				event.key.code == sf::Mouse::Left && 
				((buff = radiobutton.isMouseOverButtons(
					sf::Vector2f(sf::Mouse::getPosition(window)))) != -1))
				radiobutton.setCheckedButton(buff);

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
			{
				radiobutton.changePositionButton(sf::Vector2f(0, 0), 0);
				radiobutton.changePositionButton(sf::Vector2f(0, 40), 1);
				radiobutton.changePositionButton(sf::Vector2f(0, 80), 2);
				radiobutton.changePositionButton(sf::Vector2f(0, 120), 3);
				radiobutton.changeTextureButton("button1.png");
				radiobutton.changeHighlight("button2.png");
			}*/

			//CheckBox
			/*if (event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left &&
				checkbox.isMouseOver(sf::Vector2f(sf::Mouse::getPosition(window))))
				if (checkbox.getChecked())
					checkbox.setChecked(false);
				else
					checkbox.setChecked(true);*/

			//EditText
			/*if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				cout << editbox.getText().c_str() << endl;
				//edittext.setPosition(sf::Vector2f(static_cast<float>(rand() % 420), 
												 // static_cast<float>(rand() % 420)));

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
				editbox.moveCursorUp(false);

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
				editbox.moveCursorUp(true);

			if (event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left)
				if (editbox.isMouseOver(sf::Vector2f(sf::Mouse::getPosition(window))))
					editbox.setActive(true);
				else if (editbox.getActive())
					editbox.setActive(false);

			if (editbox.getActive() && event.type == sf::Event::TextEntered)
				if (event.text.unicode == 8)
					editbox.removeSymbol();
				else
					editbox.addSymbol(event.text.unicode);*/

			//Button
			/*if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				button.setState(gui::NORMAL);

			if (event.type == sf::Event::MouseButtonPressed && 
				event.key.code == sf::Mouse::Left && 
				button.isMouseOver(sf::Vector2f(sf::Mouse::getPosition(window))))
				button.setState(gui::DISABLED);

			if (button.isMouseOver(sf::Vector2f(sf::Mouse::getPosition(window))))
				button.setState(gui::OVER);
			else if (button.getState() != gui::DISABLED)
					button.setState(gui::NORMAL);

			if (event.type == sf::Event::MouseButtonPressed && 
				event.key.code == sf::Mouse::Right && 
				button.isMouseOver(sf::Vector2f(sf::Mouse::getPosition(window))))
				//button.setTexture("radiobutton1.png");
			{
				button.setCharacterSize(30u);
				button.setText("Hello-helloy");
				//button.setTextColor(sf::Color::Red);
				button.setTexture("button2.png");
				//button.setTextBoundRect(sf::FloatRect(0, 0, 640, 480));
				button.setPosition(sf::Vector2f(static_cast<float>(rand() % 480), 
												static_cast<float>(rand() % 440)));//cout << "Click!\n";
			}*/

			//BaseButton
			/*if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				basebutton.setPosition(sf::Vector2f(20.f, 20.f));
				basebutton.setTexture("button2.png");
				basebutton.setState(gui::NORMAL);
			}

			if (event.type == sf::Event::MouseButtonPressed && 
				event.key.code == sf::Mouse::Left && 
				basebutton.isMouseOver(sf::Vector2f(sf::Mouse::getPosition(window))))
			{
				cout << "over\n";
				basebutton.setState(gui::DISABLED);
			}

			if (basebutton.isMouseOver(sf::Vector2f(sf::Mouse::getPosition(window))))
				basebutton.setState(gui::OVER);
			else if (basebutton.getState() != gui::DISABLED)
				basebutton.setState(gui::NORMAL);*/

			//Label
			/*if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				label.setText("eeeyT");
				label.setTextColor(sf::Color::Magenta);
				label.setBoundRect(sf::FloatRect(640 / 2, 480 / 2, 640 / 2, 480 / 2));
				label.setTextAlignment(gui::LEFT);
			}

			if (event.type == sf::Event::MouseButtonPressed && 
				event.key.code == sf::Mouse::Left && 
				label.isMouseOver(sf::Vector2f(sf::Mouse::getPosition(window))))
				cout << "over\n";*/
        }
		cursor.setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));
		window.clear();
		window.draw(sprite);
		//RadioButton
		/*radiobutton.draw(window);*/
		//CheckBox
		/*checkbox.draw(window);*/
		//EditText
		/*editbox.draw(window);*/
		//Button
		/*button.draw(window);*/
		//BaseButton
		/*basebutton.draw(window);*/
		//Label
		/*label.draw(window);*/
		//Function
		/*window.draw(text);*/
        window.draw(cursor);
        window.display();
    }
	return 0;
}