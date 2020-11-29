#ifndef INDIO_H
#define INDIO_H
#include "personagem.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

class Indio : public Personagem
{
public:
  Indio(string noMe, string nacio, double vv, double dd, double rd, double aa, int nn = 1, int cc = 5, int mm = 2, int ss = 1)
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

#endif

void Indio::ataque(Personagem *oponente)
{
  srand(time(NULL));
  double aux1 = (rand() % 10);
  double aux = aux1 / 10 + 1;
  oponente->defesa(dano * aux);
  cout << "----> aux: " << aux << endl;
}

void Indio::ataqueEsp(Personagem *oponente) {

}

void Indio::defesa(int _dano)
{
  if (armadura <= 0)
  {
    vida = vida - _dano * reduzDano;
    cout << "\n---> O Indio " << nome << " perdeu " << _dano * reduzDano << "de vida!" << endl;
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

void Indio::detalhes()
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

void Indio::info()
{
  cout << "Os Indio são um povo da...";
}

// int Indio::getLVL(){
//   return nivel;
// }
// int Indio::getSPD(){
//   return velocidade;
// }

// string Indio::getName(){
//   return nome;
// }

// double Indio::getHP(){
//   return experiencia;
// }