#ifndef FASELEVEL1_HPP
#define FASELEVEL1_HPP

#include "ASCII_Engine/Fase.hpp"
#include "Enemy.hpp"
#include "Hero.hpp"
#include "Cenario.hpp"
#include "LifeUP.hpp"
#include <iostream>


class FaseLevel1 : public Fase
{
public:
	FaseLevel1(std::string name, const Sprite &bkg) : Fase(name,bkg) {}
	FaseLevel1(std::string name, const SpriteAnimado &bkg) : Fase(name,bkg) {}
	virtual ~FaseLevel1() {}
	
	
	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);
	
	
private:
	Enemy *carro[2];
	Hero *Guga;
    Cenario *Placa;
    Cenario *Aluisiocampos;
	Cenario *Montanhas;
    TextSprite *Vida;
    LifeUP *lifeup;
	
//	std::list<ObjetoDeJogo*> colisoes;
};

#endif // FASELEVEL1_HPP
