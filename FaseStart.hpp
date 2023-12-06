#ifndef FASESTART_HPP
#define FASESTART_HPP

#include "ASCII_Engine/Fase.hpp"

class FaseStart : public Fase
{
public:
	FaseStart(std::string name, const Sprite &bkg, std::string text,const Sprite sprite) : Fase(name,bkg), text(text),sprite(sprite) {}
	FaseStart(std::string name, const SpriteAnimado &bkg,std::string text, Sprite sprite) : Fase(name,bkg), text(text),sprite(sprite) {}
	virtual ~FaseStart() {}
	
	virtual void init();
	virtual unsigned run(SpriteBuffer &screen);
private:
    Sprite sprite;
    std::string text;
	enum {RIDING, PRACING, END};

};

#endif // FASESTART_HPP
