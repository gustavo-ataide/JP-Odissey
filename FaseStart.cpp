#include "FaseStart.hpp"

void FaseStart::init()
{
}

unsigned FaseStart::run(SpriteBuffer &screen)
{
    std::string ent;
    screen.clear();
    system("clear");
    sprite.draw(screen, 0, 0);
    TextSprite Message(text);
    Message.draw(screen, 20, 0);
	//padrão
	draw(screen);
	system("clear");
	show(screen);
    
		getline(std::cin,ent);
		if (ent == "q")
			return Fase::END_GAME;
		
        else{
            return Fase::LEVEL_COMPLETE;
		}
}

