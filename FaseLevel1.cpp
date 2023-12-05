#include "FaseLevel1.hpp"

#include "FaseStart.hpp"
#include "FaseFinal.hpp"
#include "ASCII_Engine/Sprite.hpp"
#include "ASCII_Engine/SpriteAnimado.hpp"

#include "Enemy.hpp"
#include <cstdlib>
#include <ctime>
#include "ncurses.h"
#include "ncurses.h"

#include <iostream>

void FaseLevel1::init()
{	
    
	//Objetos de jogo
//	princesa = new ObjetoDeJogo("Princess",SpriteAnimado("rsc/carro2",2),16,196);
//	objs.push_back(princesa);
	
    
	//carro[0] = new Enemy(ObjetoDeJogo("Enemy1",Sprite("rsc/carro1"),0,0));
	//objs.push_back(carro[0]);
	
	//carro[1] = new Enemy(ObjetoDeJogo("Enemy2",Sprite("rsc/carro2"),0,0));
	//objs.push_back(carro[1]);
	
	//objs.push_back(new ObjetoDeJogo("Cama",Sprite("rsc/bed.img"),12,168));
	
	//chave = new ObjetoDeJogo("Chave",Sprite("rsc/key.img"),12,140);
//	objs.push_back(chave);
//
//	miniChave = new ObjetoDeJogo("MiniChave",TextSprite("O=;"),7,118);
//	objs.push_back(miniChave);
//	miniChave->desativarObj();
//
//	porta = new Door(ObjetoDeJogo("Door",SpriteAnimado("rsc/door.anm"),31,182));
//	objs.push_back(porta);
//
//	tapetePorta = new ObjetoDeJogo("Tapete",SpriteBuffer(17,1),35,182);
//	objs.push_back(tapetePorta);
//	
//	hero = new Hero(ObjetoDeJogo("Hero",SpriteAnimado("rsc/hero.anm",2),39,108));
//	objs.push_back(hero);
//	
//	portao = new ObjetoDeJogo("frontDoor",Sprite("rsc/frontDoor.img"),49,102);
//	objs.push_back(portao);
//													 //std::string(20,'#')
//	objs.push_back(new ObjetoDeJogo("Life",TextSprite("####################"),7,85));
//	SpriteBase *tmp = const_cast<SpriteBase*> (objs.back()->getSprite());
//	life = dynamic_cast<TextSprite*> (tmp);
//	
//	//blocos
//	objs.push_back(new ObjetoDeJogo("B1",Sprite("rsc/castleBlock1.img"),18,38));
//	colisoes.push_back(objs.back());
//	
//	objs.push_back(new ObjetoDeJogo("B2",Sprite("rsc/castleBlock2.img"),33,38));
//	colisoes.push_back(objs.back());
//	
//	objs.push_back(new ObjetoDeJogo("B3",Sprite("rsc/castleBlock3.img"),33,132));
//	colisoes.push_back(objs.back());
//	
//	objs.push_back(new ObjetoDeJogo("B4",Sprite("rsc/castleBlock4.img"),18,45));
//	colisoes.push_back(objs.back());
//	
//	objs.push_back(new ObjetoDeJogo("B5",Sprite("rsc/castleBlock5.img"),18,120));
//	colisoes.push_back(objs.back());
//	
//	objs.push_back(new ObjetoDeJogo("B6",Sprite("rsc/castleBlock6.img"),10,158));
//	colisoes.push_back(objs.back());
//	
//	objs.push_back(new ObjetoDeJogo("B7",Sprite("rsc/castleBlock7.img"),31,158));
//	colisoes.push_back(objs.back());
//	
//	objs.push_back(new ObjetoDeJogo("B8",Sprite("rsc/castleBlock8.img"),31,199));
//	colisoes.push_back(objs.back());
//	
}

unsigned FaseLevel1::run(SpriteBuffer &screen)
{
    
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



