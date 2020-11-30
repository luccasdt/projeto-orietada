#ifndef VIKING_H
#define VIKING_H
#include "personagem.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Viking : public Personagem
{
public:
  Viking(string noMe, string nacio, double vv, double dd, double rd, double aa, double vel, int nn = 1, int cc = 5, int mm = 2, int ss = 1)
      : Personagem{noMe, nacio, vv * 1.2, dd * 2, rd * 1.6, aa, nn, cc, mm, ss, vel} {}
  void ataque(Personagem *oponente);
  void ataqueEsp(Personagem *oponente);
  void defesa(int);
  void detalhes();
  void info(); 

  string getName();
  double getHP();
  double getSPD();
  int getLVL();
  double getARM();
};

#endif

void Viking::ataque(Personagem *oponente)
{
  srand(time(NULL));
  double aux1 = (rand() % 10);
  double aux = aux1 / 10 + 1;
  oponente->defesa(dano * aux);
  cout << "----> aux: " << aux << endl;
}

void Viking::ataqueEsp(Personagem *oponente) {

}

void Viking::defesa(int _dano)
{
  if (armadura <= 0)
  {
    vida = vida - _dano * reduzDano;
    cout << "\n---> O Viking " << nome << " perdeu " << _dano * reduzDano << "de vida!" << endl;
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

void Viking::detalhes()
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

void Viking::info()
{
  cout << "Os Viking são um povo da...";
}


int Viking::getLVL(){
  return nivel;
}

double Viking::getSPD(){
  return velocidade;
}

string Viking::getName(){
  return nome;
}

double Viking::getHP(){
  return experiencia;
}

double Viking::getARM(){
  return armadura;
}
