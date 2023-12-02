#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <cstdlib>
#include <ctime>
#include "ASCII_Engine/ObjetoDeJogo.hpp"

class Enemy : public ObjetoDeJogo
{
public:
	Enemy(const ObjetoDeJogo &obj) :
			ObjetoDeJogo(obj), linha(2) {}
	
	virtual ~Enemy(){}
	
	

    virtual void update(){
        if (this->getPosC()-20 <= 1){
            this->moveRight(140);
            switch(linha){
                case 1: moveTo(12,150);linha++;break;
                case 2: moveTo(17,150);linha++;break;
                case 3: moveTo(22,150);linha=1;break;
            }
        }
        else{this->moveLeft(10);}
    }
private:
    int linha;
};

#endif // ENEMY_HPP
