#pragma once
#include "Screen.h"

class MainScreen : public Screen
{
	tgui::Gui * gui;

	sf::Font font;
	sf::Text title;
	sf::Text subtitle;

	tgui::Button::Ptr startExerciceButton;
	tgui::EditBox::Ptr exerciceIdEdit;

public:
	MainScreen(tgui::Gui * gui);
	~MainScreen();

	virtual void handleEvents(sf::RenderWindow * window, tgui::Gui * gui);
	virtual void update(float deltatime);
	virtual void render(sf::RenderWindow * window);

	int getExerciceId();
};

