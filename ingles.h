#ifndef INGLES_H
#define INGLES_H
#include "personagem.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Ingles : public Personagem {
  public:
    Ingles(string noMe, double vv, double dd, double rd, double aa=200.0, int nn=1, int cc=5, int mm=2, int ss=1)
    : Personagem{noMe, vv*1.2, dd*2, rd*1.6, aa, nn, cc, mm, ss} { }
    void ataque(Personagem*);
    void defesa(int);
    void detalhes();
    void info();
};

#endif

void Ingles::ataque(Personagem* oponente){
  srand (time(NULL));
  double aux1 = (rand() % 10);
  double aux = aux1/10 + 1;
  oponente->defesa(dano*aux);
  cout << "----> aux: " << aux << endl;
}

void Ingles::defesa(int _dano){
  if(armadura <= 0){
    vida = vida - _dano*reduzDano;
    cout << "\n---> O Ingles " << nome << " perdeu " << _dano*reduzDano << "de vida!" << endl;
  }else{
    armadura = armadura - _dano*reduzDano;
    if(armadura < 0){
      vida = vida + armadura;
      armadura = 0;
    }
    cout << "\n---> tirou " << _dano*reduzDano << " da armadura do personagem" << endl;
  }
}

void Ingles::detalhes(){
  cout << "________personagem_________" << endl;
  cout << "Nome: " << nome << endl;
  cout << "Vida: " << vida << endl;
  cout << "Armadura: " << armadura << endl;
  cout << "Dano: " << dano << endl;
  cout << "Reduz dano: " << reduzDano << endl;
  cout << "Nivel: " << nivel << endl;
  cout << "_______________________" << endl;
}

void Ingles::info(){
  cout << "Os Ingles são um povo da...";
}
