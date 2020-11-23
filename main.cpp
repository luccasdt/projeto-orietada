#include <iostream>
#include <string>
#include "personagem.h"
#include "viking.h"
#include "ingles.h"
#include "alemao.h"

using namespace std;

int main() {

  Personagem* p1 = new Personagem{"Luccas", 360, 45, 0.8, 100, 1, 4, 3, 2};
  Viking* p2 = new Viking{"Luccas", 360, 45, 0.8, 100, 1, 4, 3, 2};
  Viking* p3 = new Viking{"joao", 360, 45, 0.8, 100, 1, 4, 3, 2};
  Ingles* p4 = new Ingles{"ingles1", 360, 45, 0.8, 100, 1, 4, 3, 2};
  Alemao* p5 = new Alemao{"alemao", 360, 45, 0.8, 100, 1, 4, 3, 2};

  p2->detalhes();
  p3->detalhes();
  p4->detalhes();
  p5->detalhes();

  p2->ataque(p3);

  p3->detalhes();

  p3->ataque(p2);

  p2->detalhes();


  return 0;
}
