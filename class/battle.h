#ifndef BATTLE_h
#define BATTLE_h
#include "../class/personagem.h"

#include <time.h>
#include <string>

using namespace std;

class Battle{
    private:
        // Personagem *player;
        // Personagem *bot;
        int Vida[2];

    public:
        Battle(Personagem *player, Personagem *bot);
        ~Battle(){}
        //int Vivos();
        bool Vitoria();
        //float Derrota();
};

#endif

Battle :: Battle(Personagem *player, Personagem *bot){

  // player = player;
  // bot = bot;
  // Vida[0] = player->getHP();
  // Vida[1] = bot->getHP();


  // if(player->getSPD()>=bot->getSPD()){
    
  // }else{

  // }
}

bool Battle::Vitoria(){

  //Implementar ainda
  return true;
}