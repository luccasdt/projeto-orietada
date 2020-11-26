#include <iostream>
#include <string>

#include <vector>
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>

#include "../class/personagem.h"
#include "../class/viking.h"
#include "../class/ingles.h"
#include "../class/alemao.h"
#include "../class/indio.h"
#include "../class/americano.h"

using namespace std;

int x = 0, y = 0;
string nome;

bool lerTeclas(int limx, int limy)
{

  cin.clear();
  fflush(stdin);
  switch (_getch())
  {
  case 72:
    if (y > 0)
      y -= 1;
    return false;
    break;
  case 80:
    if (y < limy)
      y += 1;
    return false;
    break;
  case 75:
    if (x > 0)
      x -= 1;
    return false;
    break;
  case 77:
    if (x < limx)
      x += 1;
    return false;
    break;
  case '\r':
    return true;
    break;
  default:
    cout << "\n\n caiu no default lerTeclas() \n\n";
    return false;
  };
}

Personagem *perfilJogador(int i)
{
  system("cls");
  cout << "Pessoa: " << i << endl;
  cout << "HEY GUERREIRO, qual seu nome? " << endl;
  cin >> nome;

  do
  {
    system("cls");
    cout << "E VEIO DE ONDE? Inglaterra, franca ou dos mares?\n"
         << endl;

    switch (y)
    {
    case 0:
      cout << right << setw(2) << ">>" << left << setw(20) << "Ingles"
           << " - Com um forte senso de justica e compaixao" << endl;
      cout << right << setw(2) << " " << left << setw(20) << "Alemao"
           << "   os Ingless lutam para defender o povo e" << endl;
      cout << right << setw(2) << " " << left << setw(20) << "Viking"
           << "   seu reino, sendo escudos inabalaveis." << endl;
      break;
    case 1:
      cout << right << setw(2) << " " << left << setw(20) << "Ingles"
           << "   Grandes estudiosos das artes misticas, os Alemaos" << endl;
      cout << ">>" << left << setw(20) << "Alemao"
           << " - estao sempre sedentos por sabedoria e buscam se" << endl;
      cout << right << setw(2) << " " << left << setw(20) << "Viking"
           << "   aprofundar nos misterios do mundo imaterial, detendo poderes inimaginaveis" << endl;
      break;

    case 2:
      cout << right << setw(2) << " " << left << setw(20) << "Ingles"
           << "   Sem piedade, sem escrupulos, brutais e metodicos os Vikings" << endl;
      cout << right << setw(2) << " " << left << setw(20) << "Alemao"
           << "   ceifam as almas daqueles que desejam, sempre perfeitos e" << endl;
      cout << ">>" << left << setw(20) << "Viking"
           << " - silenciosos, geram mais medo do que a propria morte, por serem ageis e precisos" << endl;
      break;
    default:
      cout << right << setw(2) << ">>" << left << setw(20) << "Ingles"
           << " - Com um forte senso de justica e compaixao" << endl;
      cout << right << setw(2) << " " << left << setw(20) << "Alemao"
           << "   os Ingless lutam para defender o povo e" << endl;
      cout << right << setw(2) << " " << left << setw(20) << "Viking"
           << "   seu reino, sendo escudos inabalaveis." << endl;
      break;
    }
  } while (lerTeclas(0, 3) != true);

  switch (y)
  {
  case 0:
    return new Ingles{nome, "Ingles", 360, 45, 0.8, 100, 1, 4, 3, 2};
    break;

  case 1:
    return new Alemao{nome, "Alemao", 360, 45, 0.8, 100, 1, 4, 3, 2};
    break;

  case 2:
    return new Viking{nome, "Viking", 360, 45, 0.8, 100, 1, 4, 3, 2};
    break;
  default:
    cout << "\n\n default "
         << "o y e: " << y << endl;
    return new Ingles{nome, "Ingles", 360, 45, 0.8, 100, 1, 4, 3, 2};
  }
  system("cls");
}

vector<Personagem> iniciaEnemy()
{
  // Cria o vetor de inimigos
  Personagem enemy[5];

  // Cria o vetor de pontos
  vector<double> pontos[5];

  // define os pontos em cada nivel
  /*
  Nivel 1: 20pts
  Nivel 2: 25pts
  Nivel 3: 30pts
  Nivel 4: 35pts
  Nivel 5: 40pts
  */
  pontos[0] = 20;
  pontos[1] = 25;
  pontos[2] = 30;
  pontos[3] = 35;
  pontos[4] = 40;

  // Sorteia os pontos em cada atributo
  for (i = 0; i < 5; i++)
  {
    do
    {
      double pts_vida = (rand() % 5);
      if (pontos[i] > pts_vida)
      {
        pontos[i] -= pta_vida;
        vida[i] = pts_vida;
      }
      double pts_dano = (rand() % 5);
      if (pontos[i] > pts_dano)
      {
        pontos[i] -= pts_dano;
        dano[i] = pts_dano;
      }
      double ReduzDano_pts = (rand() % 5);
      if (pontos[i] > ReduzDano_pts)
      {
        pontos[i] -= ReduzDano_pts;
        ReduzDano[i] = ReduzDano_pts;
      }
      double armadura_pts = (rand() % 5);
      if (pontos[i] > armadura_pts)
      {
        pontos[i] -= armadura_pts;
        armadura[i] = armadura_pts;
      }
    } while (pontos[i] >= 0);
  }

  // Inicializa os atributos dos inimigos
  Viking enemy[0] = new Viking{"Luccas", vida[0], dano[0], ReduzDano[0], armadura[0], 1, 4, 3, 2};
  Ingles enemy[1] = new Ingles{"ingles1", vida[1], dano[1], ReduzDano[1], armadura[1], 2, 4, 3, 2};
  Alemao enemy[2] = new Alemao{"alemao", vida[2], dano[2], ReduzDano[2], armadura[2], 3, 4, 3, 2};
  //Indio enemy[3] = new Indio{"joao", vida[3], dano[3], ReduzDano[3], armadura[3], 4, 4, 3, 2};
  //Americano enemy[4] = new Americano{"Americano", vida[4], dano[4], ReduzDano[4], armadura[4], 5, 4, 3, 2};

  return enemy;
}

int main()
{
  // Cria o vetor de inimigos
  Personagem *myEnemy[5];

  //nome{noMe}
  //nacionalidade{nacio}
  vector<double> vida[5];
  vector<double> dano[5];
  vector<double> ReduzDano[5];
  vector<double> armadura[5];

  myEnemy = iniciaEnemy();


  /*
  Personagem *p1 = new Personagem{"Luccas", 360, 45, 0.8, 100, 1, 4, 3, 2};
  Viking *p2 = new Viking{"Luccas", 360, 45, 0.8, 100, 1, 4, 3, 2};
  Viking *p3 = new Viking{"joao", 360, 45, 0.8, 100, 1, 4, 3, 2};
  Ingles *p4 = new Ingles{"ingles1", 360, 45, 0.8, 100, 1, 4, 3, 2};
  Alemao *p5 = new Alemao{"alemao", 360, 45, 0.8, 100, 1, 4, 3, 2};

  p2->detalhes();
  p3->detalhes();
  p4->detalhes();
  p5->detalhes();

  p2->ataque(p3);

  p3->detalhes();

  p3->ataque(p2);

  p2->detalhes();
*/

  return 0;
}
