#ifndef BATTLE_h
#define BATTLE_h
#include "../class/personagem.h"

#include <time.h>
#include <string>

using namespace std;

class Battle{
    private:
        Personagem *player;
        Personagem *bot;
        int Vida[2], prioridade = 0;
        double armadura[2];

    public:
        Battle(Personagem *player1, Personagem *bot1);
        ~Battle(){}
        int Vivos();
        void Lutar();
        bool Vitoria();

};

#endif

Battle :: Battle(Personagem *player1, Personagem *bot1){

  player = player1;
  bot = bot1;
  Vida[0] = player->getHP();
  Vida[1] = bot->getHP();
  armadura[0] = player->getARM();
  armadura[1] = bot->getARM();

  if(player->getSPD()>=bot->getSPD()){
    prioridade = 1;
  }else{
    prioridade = 2;
  }

}

void Battle::Lutar() {

}


int Battle::Vivos(){

  if (Vida[0]<=0){
    return 1;
  }
  if (Vida[1]<=0){
    return 2;
  }
  return 3;

}

bool Battle::Vitoria(){

  // Implementar
  return true;
}