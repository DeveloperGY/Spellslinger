#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "Game/Entities/Entity.h"
#include "Game/Scene.h"

namespace gm
{
	// Game Engine
	class Engine
	{
	private:
		sf::RenderWindow _window; // Game Window
		int   _height   = NULL;   // Window Height
		int   _width    = NULL;   // Window Width
		char* _name     = NULL;   // Window Name
		int   _style    = NULL;   // Window Style
		char* _iconPath = NULL;   // Icon Path

		sf::Image _defaultIcon;   // Default Texture

		std::vector<gm::Scene> scenes; // Scene Vector

	public:
		// Creates the Engine
		Engine(char*, int, int, char*);
		// Destroys the Engine
		virtual ~Engine();

		// Initializes the Engine
		int initEngine();
		// Initializes the Game
		int initGame();
		// Runs the Game Loop
		void loop();

		// Getters

		// Returns a referance to the Game Window
		sf::RenderWindow* getWin();

		// Setters
	};
}