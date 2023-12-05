#ifndef GAME_HPP
#define GAME_HPP
#include <cstdlib>
#include <ctime>
#include "ncurses.h"
#include "ncurses.h"

#include "FaseLevel1.hpp"
#include "FaseStart.hpp"
#include "FaseFinal.hpp"
#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteAnimado.hpp"

class Game
{
public:
	Game(){}
	~Game(){}
	
	static void run()
	{
        
        
        
        SpriteBuffer Screen(250, 41);
		
//
		FaseStart start("FaseStart",Sprite("./rsc/blank"));
		FaseLevel1 fase1("Fase1",Sprite("./rsc/ROAD"));
		FaseFinal faseFinal("Fase1",Sprite("./rsc/ROAD"));
		
		start.init();
		start.run(Screen);
		
//		Screen.clear();
		fase1.init();
		int ret1 = fase1.run(Screen);
		if ( ret1 != Fase::GAME_OVER && ret1 != Fase::END_GAME){
		
			Screen.clear();
			faseFinal.init();
			faseFinal.run(Screen);
		}
		else
        
//        system("clear");
//        Sprite GameOver("rsc/GameOver");
//        GameOver.draw(Screen, 0, 0);
        std::cout << Screen << std::endl;
        
//
//		std::cout << "Saindo..." << std::endl;
	}
    
    

    
    
};

#endif // GAME_HPP
