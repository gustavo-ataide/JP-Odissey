//
//  Cenario.hpp
//  JP Odissey
//
//  Created by Gustavo  Henrique on 29/11/23.
//

#ifndef Cenario_hpp
#define Cenario_hpp
#include "ASCII_Engine/ObjetoDeJogo.hpp"

class Cenario : public ObjetoDeJogo
{
public:
    Cenario(const ObjetoDeJogo &obj) : ObjetoDeJogo(obj){}
    
    virtual void update(const Hero &hero){
        this->moveLeft(hero.getvelocidade());
    }
    

};

#endif /* Cenario_hpp */
