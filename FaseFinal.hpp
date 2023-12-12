#ifndef FASEFINAL_HPP
#define FASEFINAL_HPP

#include "ASCII_Engine/Fase.hpp"
#include "Enemy.hpp"
#include "Hero.hpp"
#include "Cenario.hpp"
#include "LifeUP.hpp"
#include <iostream>
class FaseFinal : public Fase
{
public:
	FaseFinal(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
	FaseFinal(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
	virtual ~FaseFinal() {}
	
	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);

    
private:
    Enemy *carro[3];
    Hero *Guga;
    Cenario *placa_saindo;
    Cenario *placa_caja;
    Cenario *Firmino;
    Cenario *greenville;
    Cenario *plantinha;
    Cenario *placa_JP;
    TextSprite *Vida;
    LifeUP *lifeup;
};

#endif // FASEFINAL_HPP
