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
    LifeUP(const ObjetoDeJogo &obj): ObjetoDeJogo(obj){}
    
    virtual void update(const Hero &hero){
        this->moveLeft(hero.getvelocidade());
    }
};

#endif /* LifeUP_hpp */
