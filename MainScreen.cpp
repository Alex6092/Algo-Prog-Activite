#include "MainScreen.h"


MainScreen::MainScreen(tgui::Gui * gui)
{
	this->gui = gui;
	gui->removeAllWidgets();
	font.loadFromFile("./assets/font/neuropol_x_rg.ttf");

	startExerciceButton = tgui::Button::create();
	startExerciceButton->setInheritedFont(font);

}