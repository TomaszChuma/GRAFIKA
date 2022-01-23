#include <SFML\Graphics.hpp>
#include "Engine.h"
#include "Player.h"
#include <iostream>



int main()
{
	Engine engine(1024, 768, "GAME");
	try {
		engine.init();
	}
	catch (const int s) {
		exit(s);
	}
	
	return 0;
	
	
}