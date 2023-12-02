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
        
        SpriteBuffer Screen(250, 35);
        ObjetoDeJogo Bg("Background", Sprite ("rsc/ROAD"), 0, 0);
        Hero Guga (ObjetoDeJogo("Gustavo", Sprite("rsc/GustavoeMoto"), 13, 0));
        Enemy carro1 (ObjetoDeJogo("carro1", Sprite("rsc/carro1"), 12, 150));
        Enemy carro2 (ObjetoDeJogo("carro2", Sprite("rsc/carro2"), 17, 50));
        Enemy carro3 (ObjetoDeJogo("carro3", Sprite("rsc/carro3"), 22, 110));
        
        Cenario plantinha(ObjetoDeJogo("plantinha", Sprite("rsc/plants"), 0, 50 ));
        Cenario Firmino(ObjetoDeJogo("Firmino", Sprite("rsc/Firmino"), 26, 70 ));
        TextSprite Vida(std::to_string(Guga.getLife()));
        LifeUP lifeup(ObjetoDeJogo("lifeup", Sprite("rsc/Cogumelo"), 15, 160));
        
        system("clear");
        std::cout << Screen << std::endl;
        
        
        std::string str;

        while(1){
            
            
            
            
            initscr();
            cbreak();
            noecho();
            int str = getch();
            endwin();
            
            if (str=='d' && Guga.getPosC()+9 < 159){
                Guga.acelera();
            }
            else if(str == 'a'){
                Guga.freia();
            }
            else if (str == 's' && Guga.getPosL()+3 <Bg.getPosL() + 26 && Guga.getPosC()+3 < 159){
                Guga.moveDown(2);
                Guga.moveRight(2);
            }
            else if (str == 'w' && Guga.getPosL() > Bg.getPosL()+ 12 && Guga.getPosC()+3 < 159){
                Guga.moveUp(2);
                Guga.moveRight(2);
                
            }
            
            if(Guga.colideCom(lifeup)){
                Guga.aumentagasolina();
                lifeup.desativarObj();
            }
            
            Bg.update();
            Guga.update();
            carro1.update();
            carro2.update();
            carro3.update();
            plantinha.update(Guga);
            Firmino.update(Guga);
            lifeup.update(Guga);
            TextSprite Vida(std::to_string(Guga.getLife()));
            
            
            Vida.draw(Screen,0,1);
            Bg.draw(Screen, Bg.getPosL(), Bg.getPosC());
            Guga.draw(Screen, Guga.getPosL(), Guga.getPosC());
            carro1.draw(Screen, carro1.getPosL(), carro1.getPosC());
            carro2.draw(Screen, carro2.getPosL(), carro2.getPosC());
            carro3.draw(Screen, carro3.getPosL(), carro3.getPosC());
            plantinha.draw(Screen, plantinha.getPosL(), plantinha.getPosC());
            Firmino.draw(Screen, Firmino.getPosL(), Firmino.getPosC());
            Vida.draw(Screen, Vida.getAltura(), Vida.getLargura());
            lifeup.draw(Screen, lifeup.getPosL(),lifeup.getPosC());

            
            
            
            system("clear");
            std::cout << Screen << std::endl;
            
            
            //se bater fudeu
            if (Guga.colideCom(carro1) || Guga.colideCom(carro2) || Guga.colideCom(carro3) || (Guga.getLife() <= 0)){
                break;
            }
             
        }
        //srand
        
//		SpriteBuffer buffer(250,67);
////
//		FaseStart start("FaseStart",Sprite("./rsc/ROAD"));
//		FaseLevel1 fase1("Fase1",Sprite("./rsc/ROAD"));
////		FaseFinal faseFinal("Fase1",Sprite("./rsc/ROAD"));
//		
//		start.init();
//		start.run(buffer);
//		
//		buffer.clear();
//		fase1.init();
//		int ret1 = fase1.run(buffer);
//		if ( ret1 != Fase::GAME_OVER && ret1 != Fase::END_GAME){
//		
//			buffer.clear();
////			faseFinal.init();
////			faseFinal.run(buffer);
//		}
//		else
        
        system("clear");
        Sprite GameOver("rsc/GameOver");
        GameOver.draw(Screen, 0, 0);
        std::cout << Screen << std::endl;
        
//
//		std::cout << "Saindo..." << std::endl;
	}
    
    
//    int adicionacarro(SpriteBuffer screen,Enemy ArrCarros[], int looptime){
//        srand(time(0));
//        int indicesprite = rand() % 3 + 1;
//        if (looptime == 10){
//            screen.draw(ArrCarros[indicesprite], 150, 3);
//            looptime = 0;
//            return looptime;
//        }
//        looptime++;
//        return looptime;
//    }
    
    
};

#endif // GAME_HPP
