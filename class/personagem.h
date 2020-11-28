#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <string>
using namespace std;

class Personagem {
  protected:
    // atributos comuns
    string nome; //nome do personagem
    string nacionalidade; // nacionalidade (Ingles, Alemao ou Viking)
    double vida; //vida do personagem, pode variar de acordo com a categoria
    double dano; //dano que o personagem da em outros players
    double reduzDano; //valor aleatório entre 0 e 0.3 que reduz o dano causado pelo oponente
    double armadura; //valor de 0 a 100. É gasta antes da vida
    int nivel; //nivel do jogador. Começa em 0 e cada nível tem 100 pontos de experiencia (xp)
    //atributos especiais. É intrinseco à categoria que o personagem pertence.
    int corpo; // valor de 0 - 5 que aumenta o dano e reduzDano
    int mente; // valor de 0 - 5 que aumenta a vida
    int sabedoria; // valor de 0 - 5 que aumenta a experiencia ganha pelo Personagem
  public:
    Personagem(string noMe, string nacio, double vv, double dd, double rd, double aa, int nn, int cc, int mm, int ss) :
      nome{noMe}, nacionalidade{nacio}, vida{vv}, dano{dd}, reduzDano{rd}, armadura{aa}, nivel{nn}, corpo{cc}, mente{mm}, sabedoria{ss} {}
    ~Personagem(){ }

    //funcoes virtuais
    virtual void ataque(Personagem* op) {}
    virtual void defesa(int _dano) {}
    virtual void detalhes() {}
    virtual void info() {}

};

#endif
