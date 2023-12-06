#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <cstdlib>
#include <ctime>
#include "ASCII_Engine/ObjetoDeJogo.hpp"

class Enemy : public ObjetoDeJogo
{
public:
	Enemy(const ObjetoDeJogo &obj, int level) :
			ObjetoDeJogo(obj), linha(2), level(level) {}
	
	virtual ~Enemy(){}
	
	

    virtual void update(){
        if (level == 1){
            if (this->getPosC()-5 <= 1){
                this->moveRight(140);
                switch(linha){
                    case 1: moveTo(12,150);linha++;break;
                    case 2: moveTo(17,150);linha=1;break;
                }
            }
            else{this->moveLeft(5);}
        }
        
        else if (level == 2){
            if (this->getPosC()-10 <= 1){
                this->moveRight(140);
                switch(linha){
                    case 1: moveTo(12,150);linha++;break;
                    case 2: moveTo(17,150);linha++;break;
                    case 3: moveTo(22,150);linha=1;break;
                }
            }
            else{this->moveLeft(10);}
        }

    }
private:
    int linha;
    int level;
};

#endif // ENEMY_HPP
