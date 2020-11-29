#ifndef Americano_H
#define Americano_H
#include "personagem.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

class Americano : public Personagem
{
public:
  Americano(string noMe, string nacio, double vv, double dd, double rd, double aa, int nn = 1, int cc = 5, int mm = 2, int ss = 1)
      : Personagem{noMe, nacio, vv * 1.2, dd * 2, rd * 1.6, aa, nn, cc, mm, ss} {}
  void ataque(Personagem *);
  void ataqueEsp(Personagem *);
  void defesa(int);
  void detalhes();
  void info();

  // string getName();
  // double getHP();
  // int getSPD();
  // int getLVL();
};

void Americano::ataque(Personagem *oponente)
{
  srand(time(NULL));
  double aux1 = (rand() % 10);
  double aux = aux1 / 10 + 1;
  oponente->defesa(dano * aux);
  cout << "----> aux: " << aux << endl;
}

void Americano::ataqueEsp(Personagem *oponente) {

}

void Americano::defesa(int _dano)
{
  if (armadura <= 0)
  {
    vida = vida - _dano * reduzDano;
    cout << "\n---> O Americano " << nome << " perdeu " << _dano * reduzDano << "de vida!" << endl;
  }
  else
  {
    armadura = armadura - _dano * reduzDano;
    if (armadura < 0)
    {
      vida = vida + armadura;
      armadura = 0;
    }
    cout << "\n---> tirou " << _dano * reduzDano << " da armadura do personagem" << endl;
  }
}

void Americano::detalhes()
{
  cout << "________personagem_________" << endl;
  cout << "Nome: " << nome << endl;
  cout << "Nacionalidade: " << nacionalidade << endl;
  cout << "Vida: " << vida << endl;
  cout << "Armadura: " << armadura << endl;
  cout << "Dano: " << dano << endl;
  cout << "Reduz dano: " << reduzDano << endl;
  cout << "Nivel: " << nivel << endl;
  cout << "_______________________" << endl;
}

void Americano::info()
{
  cout << "Os Americano são um povo da...";
}

#endif


// int Americano::getLVL(){
//   return nivel;
// }
// int Americano::getSPD(){
//   return velocidade;
// }

// string Americano::getName(){
//   return nome;
// }

// double Americano::getHP(){
//   return experiencia;
// }