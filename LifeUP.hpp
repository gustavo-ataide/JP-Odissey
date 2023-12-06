//
//  LifeUP.hpp
//  JP Odissey
//
//  Created by Gustavo  Henrique on 30/11/23.
//

#ifndef LifeUP_hpp
#define LifeUP_hpp
#include "ASCII_Engine/ObjetoDeJogo.hpp"
#include "Hero.hpp"
#include <iostream>


class LifeUP: public ObjetoDeJogo {
public:
    LifeUP(const ObjetoDeJogo &obj, int level): ObjetoDeJogo(obj), linha(2), level(level){}
    
    virtual void update(const Hero &hero){
        if (level == 1){
            if (this->getPosC()-15 <0){
                this->moveRight(130);
                switch(linha){
                    case 1: moveTo(12,150);linha++;break;
                    case 2: moveTo(17,150);linha=1;break;
                }
            }
            else{this->moveLeft(5);}
        }
        
        else if (level == 2){
            if (this->getPosC()-10 <= 1){
                this->moveRight(130);
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
    int level;
    int linha;
};

#endif /* LifeUP_hpp */
