#include "FaseFinal.hpp"
#include "FaseStart.hpp"
#include "FaseFinal.hpp"
#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteAnimado.hpp"
#include "Enemy.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "ncurses.h"
#include "ncurses.h"
#include "Enemy.hpp"
#include "Door.hpp"
#include "Hero.hpp"
#include "Cenario.hpp"
#include "LifeUP.hpp"
void FaseFinal::init()
{
	objs.push_back(new ObjetoDeJogo("Loving",SpriteAnimado("rsc/rescuePrincess.anm",4),24,30));
}

unsigned FaseFinal::run(SpriteBuffer &screen)
{
	std::string ent;
	
    ObjetoDeJogo Bg("Background", Sprite ("rsc/ROAD"), 0, 0);
    Hero Guga (ObjetoDeJogo("Gustavo", Sprite("rsc/GustavoeMoto"), 13, 0));
    Enemy carro1 (ObjetoDeJogo("carro1", Sprite("rsc/carro1"), 12, 150));
    Enemy carro2 (ObjetoDeJogo("carro2", Sprite("rsc/carro2"), 17, 50));
    Enemy carro3 (ObjetoDeJogo("carro3", Sprite("rsc/carro3"), 23, 110));
    
    Cenario Firmino (ObjetoDeJogo("Firmino", Sprite("rsc/Firmino"), 0, 120 ),20);
    Cenario plantinha (ObjetoDeJogo("plantinha", Sprite("rsc/carro1"), 30, 120 ), 40);
    
    TextSprite Vida(std::to_string(Guga.getLife()));
    LifeUP lifeup(ObjetoDeJogo("lifeup", Sprite("rsc/Cogumelo"), 15, 160));
    
    //padrão
    draw(screen);
    system("clear");
    show(screen);
    
    
    
    
    system("clear");
    std::cout << screen << std::endl;
    
    
    
    int looptime=0;
    while(1){
        looptime++;
        if (looptime>=100){
            return Fase::LEVEL_COMPLETE;
        }
        
        
        
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
        
        
        Bg.draw(screen, Bg.getPosL(), Bg.getPosC());
        Guga.draw(screen, Guga.getPosL(), Guga.getPosC());
        carro1.draw(screen, carro1.getPosL(), carro1.getPosC());
        carro2.draw(screen, carro2.getPosL(), carro2.getPosC());
        carro3.draw(screen, carro3.getPosL(), carro3.getPosC());
        plantinha.draw(screen, plantinha.getPosL(), plantinha.getPosC());
        Firmino.draw(screen, Firmino.getPosL(), Firmino.getPosC());
        Vida.draw(screen, Vida.getAltura(), Vida.getLargura());
        lifeup.draw(screen, lifeup.getPosL(),lifeup.getPosC());
        

        
        
        
        
        system("clear");
        std::cout << screen << std::endl;
        
        
        //se bater fudeu
        if (Guga.colideCom(carro1) || Guga.colideCom(carro2) || Guga.colideCom(carro3) || (Guga.getLife() <= 0)){
            system("clear");
            Sprite GameOver("rsc/GameOver");
            GameOver.draw(screen, 0, 0);
            break;
        }
         
    }
	
	return Fase::END_GAME; // não necessário
}

