#include "FaseLevel1.hpp"

#include "FaseStart.hpp"
#include "FaseFinal.hpp"
#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteAnimado.hpp"

#include <random>
#include "Enemy.hpp"
#include <cstdlib>
#include <ctime>
#include "ncurses.h"
#include "ncurses.h"

#include <iostream>

void FaseLevel1::init()
{
//	objs.push_back(new ObjetoDeJogo("B8",Sprite("rsc/castleBlock8.img"),31,199));
//	colisoes.push_back(objs.back());
//	
}

unsigned FaseLevel1::run(SpriteBuffer &screen)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(50, 150);
    std::mt19937 gerA(rd());
    std::uniform_int_distribution<> disA(12, 17);
    
    
    ObjetoDeJogo Bg("Background", Sprite ("rsc/ROAD1"), 0, 0);
    Hero Guga (ObjetoDeJogo("Gustavo", Sprite("rsc/GustavoeMoto"), 13, 0));
    Enemy carro1 (ObjetoDeJogo("carro1", Sprite("rsc/carro1"), 12, 150),1);
    Enemy carro2 (ObjetoDeJogo("carro2", Sprite("rsc/carro2"), 17, 50),1);
    
    Cenario Placa (ObjetoDeJogo("placa", Sprite("rsc/placa_queimadas"), 23, 120 ),20);
    Cenario Aluisiocampos (ObjetoDeJogo("aluisiocampos", Sprite("rsc/aluisiocampos"), 3, 120 ), 40);
    Cenario Montanhas (ObjetoDeJogo("montanhas", Sprite("rsc/montanhas_queimadas"), 2, 110 ), 70);
    
    TextSprite Vida(std::to_string(Guga.getLife()));
    LifeUP lifeup(ObjetoDeJogo("lifeup", Sprite("rsc/Cogumelo"), 15, 160),1);
    
  
    
    
    system("clear");
    draw(screen);
    show(screen);
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
        else if(str == 'a' && Guga.getPosC()>1){
            Guga.freia();
        }
        else if (str == 's' && Guga.getPosL()+3 <Bg.getPosL() + 20 && Guga.getPosC()+3 < 159){
            Guga.moveDown(2);
            Guga.moveRight(2);
        }
        else if (str == 'w' && Guga.getPosL() > Bg.getPosL()+ 12 && Guga.getPosC()+3 < 159){
            Guga.moveUp(2);
            Guga.moveRight(2);
            
        }
        else{
            Guga.moveRight(2);
        }
        

        
        Bg.update();
        Guga.update();
        carro1.update();
        carro2.update();
        Placa.update(Guga);
        Aluisiocampos.update(Guga);
        lifeup.update(Guga);
        Montanhas.update(Guga);
        TextSprite Vida(std::to_string(Guga.getLife()));
        
        if(Guga.colideCom(lifeup)){
            Guga.aumentagasolina();
            lifeup.moveTo(disA(gerA), dis(gen));
        }
        
        
        Bg.draw(screen, Bg.getPosL(), Bg.getPosC());
        Guga.draw(screen, Guga.getPosL(), Guga.getPosC());
        carro1.draw(screen, carro1.getPosL(), carro1.getPosC());
        carro2.draw(screen, carro2.getPosL(), carro2.getPosC());
        Placa.draw(screen, Placa.getPosL(), Placa.getPosC());
        Aluisiocampos.draw(screen, Aluisiocampos.getPosL(), Aluisiocampos.getPosC());
        Vida.draw(screen, Guga.getPosL()-1,Guga.getPosC() );
        lifeup.draw(screen, lifeup.getPosL(),lifeup.getPosC());
        Montanhas.draw(screen, Montanhas.getPosL(), Montanhas.getPosC());

        
        
        
        
        system("clear");
        std::cout << screen << std::endl;
        
        
        //se bater fudeu
        if (Guga.colideCom(carro1) || Guga.colideCom(carro2) || (Guga.getLife() <= 0)){
            return Fase::GAME_OVER;
        }
         
    }
    
    
    return Fase::END_GAME; // não necessário
}



