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

int main()
{

  // Cria o vetor de inimigos
  Personagem *enemy[5];

  // Cria o vetor de pontos
  double pontos[5];
  double vida[5];
  double dano[5];
  double ReduzDano[5];
  double armadura[5];

  // define os pontos em cada nivel
  pontos[0] = 20.0; //nivel 1
  pontos[1] = 25.0; //nivel 2
  pontos[2] = 30.0; //nivel 3
  pontos[3] = 35.0; //nivel 4
  pontos[4] = 40.0; //nivel 5

  // Sorteia os pontos em cada atributo
  for (int i = 0; i < 5; i++)
  {
    do
    {
      double pts_vida = (rand() % 5);
      cout << "\npontos sorteados:" << pts_vida;
      if (pontos[i] >= pts_vida)
      {
        pontos[i] -= pts_vida;
        cout << "\npontos:" << pontos[i];
        cout << "\nvida:" << vida[i];
        vida[i] = pts_vida;
      }
      double pts_dano = (rand() % 5);
      if (pontos[i] >= pts_dano)
      {
        pontos[i] -= pts_dano;
        dano[i] = pts_dano;
      }
      double ReduzDano_pts = (rand() % 5);
      if (pontos[i] >= ReduzDano_pts)
      {
        pontos[i] -= ReduzDano_pts;
        ReduzDano[i] = ReduzDano_pts;
      }
      double armadura_pts = (rand() % 5);
      if (pontos[i] >= armadura_pts)
      {
        pontos[i] -= armadura_pts;
        armadura[i] = armadura_pts;
      }
    } while (pontos[i] >= 0);
  }

  // Inicializa os atributos dos inimigos
  enemy[0] = new Viking{"Luccas", "Pedro", vida[0], dano[0], ReduzDano[0], armadura[0], 1, 4, 3, 2};
  enemy[1] = new Ingles{"ingles1", "Pedro", vida[1], dano[1], ReduzDano[1], armadura[1], 2, 4, 3, 2};
  enemy[2] = new Alemao{"alemao", "Pedro", vida[2], dano[2], ReduzDano[2], armadura[2], 3, 4, 3, 2};
  enemy[3] = new Indio{"joao", "Pedro", vida[3], dano[3], ReduzDano[3], armadura[3], 4, 4, 3, 2};
  enemy[4] = new Americano{"Americano", "Pedro", vida[4], dano[4], ReduzDano[4], armadura[4], 5, 4, 3, 2};

  for (auto x : enemy)
  {
    x->detalhes();
  }

  cout << sizeof(enemy);

  return 0;
}