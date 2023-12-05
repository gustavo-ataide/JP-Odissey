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
    Cenario(const ObjetoDeJogo &obj, int time_input=20) : ObjetoDeJogo(obj), apareceu_sn(false), time(time_input){
        this->desativarObj();
    }
    
    virtual void update(const Hero &hero){
        if(apareceu_sn == true){this->moveLeft(hero.getvelocidade());}
        
//        if (this->getPosC() + hero.getvelocidade() <=0){this->desativarObj();}
        
        if (time == time_loop){
            apareceu_sn = true;
            this->ativarObj();
            time_loop++;
        }
        else{time_loop++;}
    }
    
private:
    int time;
    int time_loop;
    bool apareceu_sn;

};

#endif /* Cenario_hpp */
