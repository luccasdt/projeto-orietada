#ifndef Battle_h
#define Battle_h
#include "Personagem.h"

#include <time.h>
#include <string>

using namespace std;

class Battle{
    private:
        Personagem *player;
        Personagem *bot;
        int Vida[2];

    public:
        Battle(Personagem *player, Personagem *bot);
        ~Battle(){};
        int Vivos();
        bool Vitoria();
        float Derrota();
};

#endif

Battle :: Battle( Personagem *player, Personagem *bot){
  srand((unsigned)time(NULL));
  int i;
  Vida[0] = player->getHP();
  Vida[1] = bot->getHP();
  player = player;
  bot = bot;

  if(player->getSPD()>=bot->getSPD()){
    
  }else{

  }
}

bool Battle::Vitoria(){

  //Implementar ainda
  return true;
}