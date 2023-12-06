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
        Sprite win("rsc/chegamos");
        Sprite GameOver("rsc/GameOver");
		FaseStart start1("FaseStart",Sprite("./rsc/blank"),"Fim de ano chegando... Voce precisa ir a Joao Pessoa visitar a familia, mas antes vá buscar Sabrina(muié) em Queimadas para chegar em Joao Pessoa bem acompanhado!",Sprite("rsc/StartSprite1"));
        FaseStart start2("Fasestart2", Sprite("./rsc/blank"), "Beijos Beijos... Voce chegou até Sabrina, agora simbora pra Joao Pessoa",Sprite("rsc/StartSprite2"));
        FaseStart Win("Win", Sprite("./rsc/blank"), "",Sprite("rsc/Win"));
		
        FaseLevel1 fase1("Fase1",Sprite("./rsc/ROAD1"));
		FaseFinal faseFinal("Fasefinal",Sprite("./rsc/ROAD2"));
		
		start1.init();
		start1.run(Screen);
		
//		Screen.clear();
		fase1.init();
		int ret1 = fase1.run(Screen);
		if ( ret1 != Fase::GAME_OVER && ret1 != Fase::END_GAME){
            start2.init();
            start2.run(Screen);
        
		
			Screen.clear();
			faseFinal.init();
			int ret2 = faseFinal.run(Screen);
            if (ret2 != Fase::GAME_OVER && ret2 != Fase::END_GAME){
                system("clear");
                Win.init();
                Win.run(Screen);
//                std::cout << Screen << std::endl;
            }
            
            else{
                system("clear");
                GameOver.draw(Screen, 0, 0);
                std::cout << Screen << std::endl;
            }
        }
        else{
            system("clear");
            GameOver.draw(Screen, 0, 0);
            std::cout << Screen << std::endl;
        }
	}
    
    

    
    
};

#endif // GAME_HPP
