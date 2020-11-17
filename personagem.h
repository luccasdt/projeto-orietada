#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <string>
using namespace std;

class Personagem {
  protected:
    // atributos comuns
    string nome; //nome do personagem
    int vida; //vida do personagem, pode variar de acordo com a categoria
    int dano; //dano que o personagem da em outros players
    double reduzDano; //valor aleatório entre 0 e 0.3 que reduz o dano causado pelo oponente
    int armadura; //valor de 0 a 100. É gasta antes da vida
    int nivel; //nivel do jogador. Começa em 0 e cada nível tem 100 pontos de experiencia (xp)
    //atributos especiais. É intrinseco à categoria que o personagem pertence.
    int corpo; // valor de 0 - 5 que aumenta o dano e reduzDano
    int mente; // valor de 0 - 5 que aumenta a vida
    int sabedoria; // valor de 0 - 5 que aumenta a experiencia ganha pelo Personagem
  public:
    Personagem(string noMe, int vv, int dd, double rd, int aa=100, int nn=1, int cc=0, int mm=0, int ss=0) :
      nome{noMe}, vida{vv}, dano{dd}, reduzDano{rd}, armadura{aa}, nivel{nn}, corpo{cc}, mente{mm}, sabedoria{ss} {}
    ~Personagem(){ }

    //funcoes virtuais
    virtual void ataque() const = 0;
    virtual void defesa() const = 0;

};

#endif
