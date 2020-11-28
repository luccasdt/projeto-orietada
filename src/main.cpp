#include <iostream>
#include <string>

#include <string>
#include <vector>
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <windows.h>

#include "../class/personagem.h"
#include "../class/viking.h"
#include "../class/ingles.h"
#include "../class/alemao.h"
#include "../class/indio.h"
#include "../class/americano.h"

using namespace std;

int x = 0, y = 0;
string nome;

// LE AS TECLAS CIMA, BAIXO E ENTER
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
  case '\r':
    return true;
    break;
  default:
    return false;
    break;
  };
}

// AGUARDA O USUARIO PRESSINAR ENTER
void pressEnter()
{
  do
  {
    cout << "\nPressione ENTRER para continuar...\n";
  } while (lerTeclas(0, 0) != true);
}

// MENU DE ATRIBUICAO DE PONTOS DO PLAYER
void setScore(double *pontos_dispon, double *pts_vida, double *pts_dano, double *pts_reduzDano, double *pts_armadura)
{
  double pts_input;
  int estado = 0;

  // Imprime pontos iniciais
  system("cls");
  cout << "Vamos comecar distribuindo seus pontos!\n"
       << endl;

  cout << "\nPontos disponiveis: "
       << *pontos_dispon;
  cout << "\nPontos de vida: "
       << *pts_vida;
  cout << "\nPontos de dano: "
       << *pts_dano;
  cout << "\nPontos de reducao de dano: "
       << *pts_reduzDano;
  cout << "\nPontos de armadura: "
       << *pts_armadura << endl;

  pressEnter();

  system("cls");

  // Solicita a distribuicao dos pontos
  do
  {
    switch (estado)
    {
    case 0:
      cout << "Voce ainda tem " << *pontos_dispon << " pontos." << endl;
      cout << "Vida (0-5)pts: ";
      cin >> pts_input;
      if ((pts_input >= 0 && pts_input <= 5) && (pts_input <= *pontos_dispon))
      {
        *pts_vida += pts_input;
        *pontos_dispon -= pts_input;
        system("cls");
        cout << "Valor atribuido!\n"
             << endl;
        estado = 1;
      }
      else
      {
        system("cls");
        cout << "Valor impossivel!\n"
             << endl;
        estado = 0;
      }
      break;
    case 1:
      cout << "Voce ainda tem " << *pontos_dispon << " pontos." << endl;
      cout << "Dano (0-5)pts: ";
      cin >> pts_input;
      if ((pts_input >= 0 && pts_input <= 5) && (pts_input <= *pontos_dispon))
      {
        *pts_dano += pts_input;
        *pontos_dispon -= pts_input;
        system("cls");
        cout << "Valor atribuido!\n"
             << endl;
        estado = 2;
      }
      else
      {
        system("cls");
        cout << "Valor impossivel!\n"
             << endl;
        estado = 1;
      }
      break;
    case 2:

      cout << "Voce ainda tem " << *pontos_dispon << " pontos." << endl;
      cout << "reducao de dano do inimigo (0-5)pts: ";
      cin >> pts_input;
      if ((pts_input >= 0 && pts_input <= 5) && (pts_input <= *pontos_dispon))
      {
        *pts_reduzDano += pts_input;
        *pontos_dispon -= pts_input;
        system("cls");
        cout << "Valor atribuido!\n"
             << endl;
        estado = 3;
      }
      else
      {
        system("cls");
        cout << "Valor impossivel!\n"
             << endl;
        estado = 2;
      }
      break;
    case 3:

      cout << "Voce ainda tem " << *pontos_dispon << " pontos." << endl;
      cout << "Armadura (0-5)pts: ";
      cin >> pts_input;
      if ((pts_input >= 0 && pts_input <= 5) && (pts_input <= *pontos_dispon))
      {
        *pts_armadura += pts_input;
        *pontos_dispon -= pts_input;
        system("cls");
        cout << "Valor atribuido!\n"
             << endl;
        estado = 0;
      }
      else
      {
        system("cls");
        cout << "Valor impossivel!\n"
             << endl;
        estado = 3;
      }
      break;
    }

  } while (*pontos_dispon > 0);


  // Imprime os pontos finais
  cout << "\nPontos disponiveis: "
       << *pontos_dispon;
  cout << "\nPontos de vida: "
       << *pts_vida;
  cout << "\nPontos de dano: "
       << *pts_dano;
  cout << "\nPontos de reducao de dano: "
       << *pts_reduzDano;
  cout << "\nPontos de armadura: "
       << *pts_armadura << endl;
}

// INICIA A CLASSE DO PLAYER
Personagem *iniciaJogador()
{

  double pontos_dispon = 20;
  double pts_vida = 0, pts_dano = 0, pts_reduzDano = 0, pts_input = 0, pts_armadura = 0;

  // Solicita o nome
  system("cls");
  cout << "HEY GUERREIRO, qual seu nome? " << endl;
  cin >> nome;

  // Solicita a nacionalidade
  do
  {
    system("cls");
    cout << "E VEIO DE ONDE? Inglaterra, franca, dos mares, Brasil ou Ameria?" << endl;

    switch (y)
    {
    case 0:
      cout << ">>" << left << setw(20) << "Ingles"
           << " - Grandes estudiosos das artes misticas, os Alemaos" << endl;
      cout << right << setw(2) << " " << left << setw(20) << "Alemao"
           << "   estao sempre sedentos por sabedoria e buscam se" << endl;
      cout << right << setw(2) << " " << left << setw(20) << "Viking"
           << "   aprofundar nos misterios do mundo imaterial, detendo poderes inimaginaveis" << endl;
      cout << right << setw(2) << " " << left << setw(20) << "do Brasil"
           << "   seu reino, sendo escudos inabalaveis." << endl;
      cout << right << setw(2) << " " << left << setw(20) << "america"
           << "   seu reino, sendo escudos inabalaveis." << endl;
      break;
    case 1:
      cout << right << setw(2) << " " << left << setw(20) << "Ingles"
           << "   Grandes estudiosos das artes misticas, os Alemaos" << endl;
      cout << ">>" << left << setw(20) << "Alemao"
           << " - estao sempre sedentos por sabedoria e buscam se" << endl;
      cout << right << setw(2) << " " << left << setw(20) << "Viking"
           << "   aprofundar nos misterios do mundo imaterial, detendo poderes inimaginaveis" << endl;
      cout << right << setw(2) << " " << left << setw(20) << "do Brasil"
           << "   seu reino, sendo escudos inabalaveis." << endl;
      cout << right << setw(2) << " " << left << setw(20) << "america"
           << "   seu reino, sendo escudos inabalaveis." << endl;
      break;

    case 2:
      cout << right << setw(2) << " " << left << setw(20) << "Ingles"
           << "   Grandes estudiosos das artes misticas, os Alemaos" << endl;
      cout << right << setw(2) << " " << left << setw(20) << "Alemao"
           << "   estao sempre sedentos por sabedoria e buscam se" << endl;
      cout << ">>" << left << setw(20) << "Viking"
           << " - aprofundar nos misterios do mundo imaterial, detendo poderes inimaginaveis" << endl;
      cout << right << setw(2) << " " << left << setw(20) << "do Brasil"
           << "   seu reino, sendo escudos inabalaveis." << endl;
      cout << right << setw(2) << " " << left << setw(20) << "america"
           << "   seu reino, sendo escudos inabalaveis." << endl;
      break;
    case 3:
      cout << right << setw(2) << " " << left << setw(20) << "Ingles"
           << "   Grandes estudiosos das artes misticas, os Alemaos" << endl;
      cout << right << setw(2) << " " << left << setw(20) << "Alemao"
           << "   estao sempre sedentos por sabedoria e buscam se" << endl;
      cout << right << setw(2) << " " << left << setw(20) << "Viking"
           << "   aprofundar nos misterios do mundo imaterial, detendo poderes inimaginaveis" << endl;
      cout << ">>" << left << setw(20) << "do Brasil"
           << "  -  seu reino, sendo escudos inabalaveis." << endl;
      cout << right << setw(2) << " " << left << setw(20) << "america"
           << "   seu reino, sendo escudos inabalaveis." << endl;
      break;
    case 4:
      cout << right << setw(2) << " " << left << setw(20) << "Ingles"
           << "   Grandes estudiosos das artes misticas, os Alemaos" << endl;
      cout << right << setw(2) << " " << left << setw(20) << "Alemao"
           << "   estao sempre sedentos por sabedoria e buscam se" << endl;
      cout << right << setw(2) << " " << left << setw(20) << "Viking"
           << "   aprofundar nos misterios do mundo imaterial, detendo poderes inimaginaveis" << endl;
      cout << right << setw(2) << " " << left << setw(20) << "do Brasil"
           << "   seu reino, sendo escudos inabalaveis." << endl;
      cout << ">>" << left << setw(20) << "america"
           << " - seu reino, sendo escudos inabalaveis." << endl;
      break;
    default:
      cout << ">>" << left << setw(20) << "Ingles"
           << " - Grandes estudiosos das artes misticas, os Alemaos" << endl;
      cout << right << setw(2) << " " << left << setw(20) << "Alemao"
           << "   estao sempre sedentos por sabedoria e buscam se" << endl;
      cout << right << setw(2) << " " << left << setw(20) << "Viking"
           << "   aprofundar nos misterios do mundo imaterial, detendo poderes inimaginaveis" << endl;
      cout << right << setw(2) << " " << left << setw(20) << "do Brasil"
           << "   seu reino, sendo escudos inabalaveis." << endl;
      cout << right << setw(2) << " " << left << setw(20) << "america"
           << "   seu reino, sendo escudos inabalaveis." << endl;
      break;
    }
  } while (lerTeclas(0, 4) != true);

  // Explica o sistema de pontos
  system("cls");
  cout << "\nOla, caro " << nome << endl;
  cout << "Agora vamos distribuir seus pontos..." << endl;
  cout << "\nVai funcionar assim:" << endl;
  cout << "\nNivel 1: 20pts\nNivel 2: 25pts\nNivel 3: 30pts\nNivel 4: 35pts\nNivel 5: 40pts" << endl;
  cout << "\n   Voce comeca no nivel 1. Logo vai poder distribuir 20pts," << endl;
  cout << "e conforme derrotar um inimigo, sobe de nivel e ganha mais" << endl;
  cout << "pontos para distribuir!" << endl;

  pressEnter();

  // Chama o sistema de adicionar pontos
  setScore(&pontos_dispon, &pts_vida, &pts_dano, &pts_reduzDano, &pts_armadura);

  pressEnter();

  // cria e retorna o objeto com base nas preferencias do jogador
  switch (y)
  {
  case 0:
    return new Ingles{nome, "Ingles", pts_vida, pts_dano, pts_reduzDano, pts_armadura, 1, 4, 3, 2};
    break;

  case 1:
    return new Alemao{nome, "Alemao", pts_vida, pts_dano, pts_reduzDano, pts_armadura, 1, 4, 3, 2};
    break;

  case 2:
    return new Viking{nome, "Viking", pts_vida, pts_dano, pts_reduzDano, pts_armadura, 1, 4, 3, 2};
    break;
  default:
    cout << "\n\n default "
         << "o y e: " << y << endl;
    return new Ingles{nome, "Ingles", pts_vida, pts_dano, pts_reduzDano, pts_armadura, 1, 4, 3, 2};
  }
}

// CRIA UM VETOR DE OBJETOS DE INIMIGOS
void setEnemy(Personagem* enemy[5])
{
  
  // Cria o vetor de pontos e atributos aleatorios
  double pontos[5];
  double vida[5];
  double dano[5];
  double ReduzDano[5];
  double armadura[5];

  // Define os pontos em cada nivel
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
      if (pontos[i] >= pts_vida)
      {
        pontos[i] -= pts_vida;
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
    } while (pontos[i] > 0);
  }

  // Inicializa os atributos dos inimigos
  enemy[0] = new Viking{"Luccas", "Viking", vida[0], dano[0], ReduzDano[0], armadura[0], 1, 4, 3, 2};
  enemy[1] = new Ingles{"Pedro", "Ingles", vida[1], dano[1], ReduzDano[1], armadura[1], 2, 4, 3, 2};
  enemy[2] = new Alemao{"Cleveo", "Alemao", vida[2], dano[2], ReduzDano[2], armadura[2], 3, 4, 3, 2};
  enemy[3] = new Indio{"joao", "Indio", vida[3], dano[3], ReduzDano[3], armadura[3], 4, 4, 3, 2};
  enemy[4] = new Americano{"Maria", "Americano", vida[4], dano[4], ReduzDano[4], armadura[4], 5, 4, 3, 2};

}



int main()
{

  // Cria o vetor de inimigos
  Personagem* enemy[5];

  // Inicializa os inimigos com valores aleatorios
  setEnemy(enemy);

  // Cria o player
  Personagem *player;

  // inicializa o player de acordo com suas preferencias
  player = iniciaJogador();

  // Testes
  player->detalhes();
  enemy[0]->detalhes();
  enemy[1]->detalhes();
  enemy[2]->detalhes();
  enemy[3]->detalhes();
  enemy[4]->detalhes();

  return 0;
}