#include "FaseStart.hpp"

void FaseStart::init()
{
//	heroMove1 = new ObjetoDeJogo("Hero1",Sprite("rsc/GustavoeMoto"),3,2);
//	objs.push_back(heroMove1);
	
//	heroMove2 = new ObjetoDeJogo("Hero2",SpriteAnimado("rsc/littleKnight.anm",4),38,61);
//	objs.push_back(heroMove2);
//	heroMove2->desativarObj();
}

unsigned FaseStart::run(SpriteBuffer &screen)
{
    std::string ent;
    screen.clear();
    system("clear");
    Sprite SpriteStart("rsc/StartSprite1");
    SpriteStart.draw(screen, 0, 20);
    TextSprite Message("Voce precisa voltar pra joao pessoa e visitar seus parentes, porem, antes disso vá buscar Sabrina para não chegar ao seu destino sozinho!");
    Message.draw(screen, 8, 0);
	//padrão
	draw(screen);
	system("clear");
	show(screen);
	
	int state = RIDING;
	int countPracing = 0;
	
	while (true)
	{
		//lendo entrada
		getline(std::cin,ent);
		if (ent == "q")
			return Fase::END_GAME;
		
        else{
            
            return Fase::LEVEL_COMPLETE;
				
		}
		
		//padrão
//		update();
//		draw(screen);
//		system("clear");
//		show(screen);
	}
	
	return Fase::END_GAME; // não necessário
}
