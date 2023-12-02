#ifndef HERO_HPP
#define HERO_HPP

#include "ASCII_Engine/ObjetoDeJogo.hpp"

class Hero : public ObjetoDeJogo
{
public:
	Hero(const ObjetoDeJogo &obj, int gasolina=1000000) : ObjetoDeJogo(obj), gasolina(10000000) {
        estagiovelocidade=1;
    }
	virtual ~Hero()	{}
	
	bool isAlive() const { return gasolina != 0; }
	int getLife() const { return gasolina; }
    int getEstagiovelocidade(){return this->estagiovelocidade;}

	
     int  getvelocidade() const{
        return estagiovelocidade*3;
    }
    
    void acelera(){
        if (estagiovelocidade<=3){estagiovelocidade++;}
        moveRight(estagiovelocidade*3);
    }
    void freia(){
        if (estagiovelocidade>1){estagiovelocidade--;}
        moveLeft(estagiovelocidade*3);
        
    }
    
    virtual void update() {
        gasolina = gasolina - 4;
    }
    
    void aumentagasolina(){
//        if(gasolina + 20 <=100)
//            gasolina = gasolina + 20;
//        else{gasolina = 100;}
    }

    

private:
    int estagiovelocidade;
	int gasolina;
	
};

#endif // HERO_HPP
