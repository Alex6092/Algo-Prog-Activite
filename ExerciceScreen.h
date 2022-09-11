#pragma once
#include "Screen.h"
class ExerciceScreen :
	public Screen
{
	tgui::Gui * gui;
	int exerciceId;

	sf::Font font;
	sf::Text title;
	sf::Text subtitle;

	tgui::Button::Ptr startExerciceButton;
	tgui::EditBox::Ptr exerciceIdEdit;

public:
	ExerciceScreen(int exerciceId, tgui::Gui * gui);
	~ExerciceScreen();

	virtual void handleEvents(sf::RenderWindow * window, tgui::Gui * gui);
	virtual void update(float deltatime);
	virtual void render(sf::RenderWindow * window);

	virtual void solve() = 0;

	void moveForward();
	void turnRight();
	void turnLeft();
	void collectGem();

	bool canMoveForward();
	bool isOnGem();

	//void getMap();
};

