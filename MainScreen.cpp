#include "MainScreen.h"


MainScreen::MainScreen(tgui::Gui * gui)
{
	this->gui = gui;
	gui->removeAllWidgets();
	font.loadFromFile("./assets/font/neuropol_x_rg.ttf");

	startExerciceButton = tgui::Button::create();
	startExerciceButton->setInheritedFont(font);
	startExerciceButton->setTextSize(20);
	startExerciceButton->getRenderer()->setTextColor(sf::Color(50, 50, 50, 255));
	startExerciceButton->setText("Démarrer exercice");
	startExerciceButton->setSize(300, 50);

	exerciceIdEdit = tgui::EditBox::create();
	exerciceIdEdit->setInheritedFont(font);
	exerciceIdEdit->setTextSize(20);
	exerciceIdEdit->setSize(300, 50);
	exerciceIdEdit->setDefaultText("Numéro exercice");
	exerciceIdEdit->getRenderer()->setBackgroundColor(sf::Color(255, 255, 255, 200));

	gui->add(startExerciceButton);
	gui->add(exerciceIdEdit);

	startExerciceButton->connect("pressed", [&]() {
		int idExercice = this->getExerciceId();
		
		// Changement de screen
		Screen * nextScreen = NULL;
		switch (idExercice)
		{
		case 1:

			break;
		}

		if (nextScreen != NULL)
		{

		}
	});
}

MainScreen::~MainScreen()
{
}

void MainScreen::handleEvents(sf::RenderWindow * window, tgui::Gui * gui)
{
	float windowSizeX = window->getSize().x / 2;
	float windowSizeY = window->getSize().y / 2;

	startExerciceButton->setPosition(windowSizeX - startExerciceButton->getSize().x / 2, windowSizeY + 50);
	exerciceIdEdit->setPosition(windowSizeX - exerciceIdEdit->getSize().x / 2, windowSizeY - 50);

	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
		else if (event.type == sf::Event::Resized)
		{
			int sizeX = event.size.width;
			int sizeY = event.size.height;

			sf::View view = window->getView();
			view.setSize(event.size.width, event.size.height);
			window->setView(view);
		}

		gui->handleEvent(event);
	}
}

void MainScreen::update(float deltatime)
{
	Screen::update(deltatime);

}

void MainScreen::render(sf::RenderWindow * window)
{

}

int MainScreen::getExerciceId()
{
	return std::atoi(exerciceIdEdit->getText().toAnsiString().c_str());
}
