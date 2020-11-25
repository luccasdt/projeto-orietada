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

using namespace std;

int x = 0, y = 0;
string nome;

int numJogadores()
{
  int numjogador = 2;
  system("cls");
  do
  {
    if (numjogador < 2 || numjogador > 4)
    {
      cout << "Quantidade invalida! Tente novamente..." << endl;
    }
    cout << "Para iniciar, me diga quantas pessoas vao jogar! (min:2, max: 4)" << endl;
    cout << ">>";
    cin >> numjogador;
  } while (numjogador < 2 || numjogador > 4);

  system("cls");
  cout << "Ok, voce escolheu " << numjogador << " jogadores!" << endl;

  return numjogador;
}

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

Personagem* perfilJogador(int i)
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
    cout << "\n\n default " << "o y e: " << y << endl;
    return new Ingles{nome, "Ingles", 360, 45, 0.8, 100, 1, 4, 3, 2};
  }
  system("cls");

}

int main()
{
  int qnt_jogadores;

  // Recebe quantos jogadores vão jogar
  qnt_jogadores = numJogadores();

  // Cria o vetor de personagem com base em quantos jogadores vao jogar
  Personagem* person[qnt_jogadores-1];

  // Inicia as perguntas de cada jogador: Nome e nacionalidade
  for(int i = 0; i < qnt_jogadores; i++)
  {
    person[i] = perfilJogador(i+1);
  }

  for(int i = 0; i < qnt_jogadores; i++)
  {
    person[i]->detalhes();
  }

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
