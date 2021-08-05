#include "Engine.h"

gm::Engine::Engine(char* winName, int width, int height, char* iconPath)
{
	this->_name = winName;
	this->_width = width;
	this->_height = height;
	this->_style = sf::Style::Close | sf::Style::Titlebar;
	this->_iconPath = iconPath;

	// Make default texture
	sf::Image col;
	col.create(8, 8, sf::Color(73, 170, 16));
	this->_defaultIcon.create(16, 16, sf::Color(0, 0, 0));
	this->_defaultIcon.copy(col, 0, 0);
	this->_defaultIcon.copy(col, 8, 8);

	return;
}

gm::Engine::~Engine()
{
	return;
}

int gm::Engine::initEngine()
{
	// Create the window and set the window icon
	this->_window.create(sf::VideoMode(this->_width, this->_height), this->_name, this->_style);
	sf::Image icon;
	icon.create(16, 16, sf::Color(0, 0, 0));

	try // If the icon path is invalid, load the default icon and print an error, else load the icon
	{
		if (!icon.loadFromFile(this->_iconPath))
		{
			throw "ERROR: Window icon file was not found!\n";
		}
		else
		{
			this->_window.setIcon(16, 16, icon.getPixelsPtr());
		}
	}
	catch (const char* err)
	{
		this->_window.setIcon(16, 16, this->_defaultIcon.getPixelsPtr());
		std::cout << err;
	}

	return 0;
}

void gm::Engine::loop()
{
	while(this->_window.isOpen())
	{
		sf::Event ev;

		while (this->_window.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
			{
				this->_window.close();
			}
		}

		// Update Scene

		this->_window.clear();

		// Draw Scene

		this->_window.display();
	}
}

int gm::Engine::addScene(gm::Scene* scene)
{
	// If scene doesnt have a name, send error and dont add it
	if (scene->getName() == NULL)
	{
		std::cout << "ERROR: Scene doesn't have a name!\n";
		return -1;
	}

	// if scene with identical name already exists, send error and dont add scene
	for (int i = 0; i < (int)this->_scenes.size(); i++)
	{
		if (this->_scenes[i]->getName() == scene->getName())
		{
			std::cout << "ERROR: Scene with identical scene name already exists!\n";
			return -1;
		}
	}

	this->_scenes.push_back(scene);
	return 0;
}

// Getters

sf::RenderWindow* gm::Engine::getWin()
{
	return &this->_window;
}

gm::Scene* gm::Engine::getMainScene()
{
	return this->_mainScene;
}

// Setters

int gm::Engine::setMainScene(char* name)
{
	// If none of the scenes have the name, output an error, else set the main scene
	for (int i = 0; i < (int)this->_scenes.size(); i++)
	{
		if (i == this->_scenes.size() - 1 && this->_scenes[i]->getName() != name)
		{
			std::cout << "ERROR: Cannot set main scene to \"" << name << "\"! Scene called \"" << name << "\" doesnt exist!\n";
			return -1;
		}
		else if (this->_scenes[i]->getName() == name)
		{
			this->_mainScene = this->_scenes[i];
		}
		else
		{
			continue;
		}
	}
	return 0;
}

int gm::Engine::setMainScene(const char* name)
{
	// If none of the scenes have the name, output an error, else set the main scene
	for (int i = 0; i < (int)this->_scenes.size(); i++)
	{
		if (i == this->_scenes.size() - 1 && this->_scenes[i]->getName() != name)
		{
			std::cout << "ERROR: Cannot set main scene to \"" << name << "\"! Scene called \"" << name << "\" doesnt exist!\n";
			return -1;
		}
		else if (this->_scenes[i]->getName() == name)
		{
			this->_mainScene = this->_scenes[i];
		}
		else
		{
			continue;
		}
	}
	return 0;
}