#include "Engine.h"
#include <iostream>

int main(void)
{
	std::cout << "DO NOT close this window, if you do it will close your game at an unexpected point and could cause errors!\n" <<
		         "If you want, you can minimize this window.\n" <<
				 "This window displays any errors that occur during the game and will automatically close when you exit the game.\n\n";

	gm::Engine engine((char*)"Spell Slinger", 720, 480, (char*)"assets/graphics/game_icon.png");
	if (engine.initEngine())
		return -1;

	if (engine.initGame())
		return -1;

	engine.loop();
	return 0;
}