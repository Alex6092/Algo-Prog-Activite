#include "MainScreen.h"
#include "ScreenManager.h"
#include <TGUI/TGUI.hpp>

int main(int argc, char** argv)
{
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Algorithmique et programmation"/*, sf::Style::Fullscreen*/);
	tgui::Gui gui{ window };
	window.setVerticalSyncEnabled(true);
	ScreenManager::getInstance()->setCurrentScreen(new MainScreen(&gui));
	//tw::Screen * battle = new tw::BattleScreen(&gui);
	sf::Clock deltaClock;

	while (window.isOpen())
	{
		ScreenManager::getInstance()->getCurrentScreen()->handleEvents(&window, &gui);
		ScreenManager::getInstance()->getCurrentScreen()->update(deltaClock.restart().asSeconds());
		window.clear();
		ScreenManager::getInstance()->getCurrentScreen()->render(&window);
		gui.draw();
		window.display();
	}

	delete ScreenManager::getInstance()->getCurrentScreen();

	return 0;
}



/*
#include <SFML/Graphics.hpp>


int main(int argc, char **argv)
{
	sf::Window window(sf::VideoMode(800, 600), "My window");

	// on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
	while (window.isOpen())
	{
		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		sf::Event event;
		while (window.pollEvent(event))
		{
			// évènement "fermeture demandée" : on ferme la fenêtre
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}

	return 0;
}
*/