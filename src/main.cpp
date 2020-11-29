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
#include "../class/battle.h"

using namespace std;

int y = 0;

// PREPARA PARA LER AS TECLAS NOVAMENTE
void resetLerTeclas()
{
     y = 0;
}

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
     resetLerTeclas();
     do
     {
          cout << "\nPressione ENTRER para continuar...\n";
     } while (lerTeclas(0, 0) != true);
}

// SOLICITA PARA O USUARIO ESCOLHER ENTRE JOGAR NOVMENTE OU SAIR
bool playAgain()
{
     resetLerTeclas();
     do
     {
          system("cls");
          cout << "Parece que voce foi derrotado em uma batalha ;'(\n"
               << endl;

          switch (y)
          {
          case 0:
               cout << ">>" << left << setw(20) << "Tentar novamente" << endl;
               cout << right << setw(2) << " " << left << setw(20) << "Sair" << endl;
               break;
          case 1:
               cout << right << setw(2) << " " << left << setw(20) << "Tentar novamente" << endl;
               cout << ">>" << left << setw(20) << "Sair" << endl;
               break;
          default:
               cout << "\n\nvalor inesperado de y no default playAgain()\n\n";
          }
     } while (lerTeclas(0, 2) != true);

     if (y == 0)
          return true;
     else
          return false;
}

// MENU DE ATRIBUICAO DE PONTOS DO PLAYER
void setScore(double *pontos_dispon, double *pts_vida, double *pts_dano, double *pts_reduzDano, double *pts_armadura, double *pts_velocidade)
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
          << *pts_armadura;
     cout << "\nPontos de velocidade: "
          << *pts_velocidade << endl;

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
                    estado = 4;
               }
               else
               {
                    system("cls");
                    cout << "Valor impossivel!\n"
                         << endl;
                    estado = 3;
               }
               break;
          case 4:
               cout << "Voce ainda tem " << *pontos_dispon << " pontos." << endl;
               cout << "Velocidade (0-5)pts: ";
               cin >> pts_input;
               if ((pts_input >= 0 && pts_input <= 5) && (pts_input <= *pontos_dispon))
               {
                    *pts_velocidade += pts_input;
                    *pontos_dispon -= pts_input;
                    system("cls");
                    cout << "Valor atribuido!\n"
                         << endl;
                    estado = 5;
               }
               else
               {
                    system("cls");
                    cout << "Valor impossivel!\n"
                         << endl;
                    estado = 4;
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
     cout << "\nPontos de armadura: "
          << *pts_velocidade << endl;
}

// INICIA A CLASSE DO PLAYER
Personagem *iniciaJogador()
{
     string nome;
     double pts_vida = 0, pts_dano = 0, pts_reduzDano = 0, pts_input = 0, pts_armadura = 0, pts_velocidade = 0, pontos_dispon = 20;

     // Solicita o nome
     system("cls");
     cout << "HEY GUERREIRO, qual seu nome? " << endl;
     cin >> nome;

     // Solicita a nacionalidade
     resetLerTeclas();
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
     setScore(&pontos_dispon, &pts_vida, &pts_dano, &pts_reduzDano, &pts_armadura, &pts_velocidade);

     pressEnter();

     // cria e retorna o objeto com base nas preferencias do jogador
     switch (y)
     {
     case 0:
          return new Ingles{nome, "Ingles", pts_vida, pts_dano, pts_reduzDano, pts_armadura, pts_velocidade, 1, 4, 3, 2};
          break;

     case 1:
          return new Alemao{nome, "Alemao", pts_vida, pts_dano, pts_reduzDano, pts_armadura, pts_velocidade, 1, 4, 3, 2};
          break;

     case 2:
          return new Viking{nome, "Viking", pts_vida, pts_dano, pts_reduzDano, pts_armadura, pts_velocidade, 1, 4, 3, 2};
          break;
     case 3:
          return new Indio{nome, "Do brasil", pts_vida, pts_dano, pts_reduzDano, pts_armadura, pts_velocidade, 1, 4, 3, 2};
          break;
     case 4:
          return new Americano{nome, "America", pts_vida, pts_dano, pts_reduzDano, pts_armadura, pts_velocidade, 1, 4, 3, 2};
          break;
     default:
          cout << "\n\n default "
               << "o y e: " << y << endl;
          return new Americano{nome, "America", pts_vida, pts_dano, pts_reduzDano, pts_armadura, pts_velocidade, 1, 4, 3, 2};
          break;
     }
}

// CRIA UM VETOR DE OBJETOS DE INIMIGOS
void setEnemy(Personagem *enemy[])
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
     enemy[0] = new Viking{"Luccas", "Viking", vida[0], dano[0], ReduzDano[0], armadura[0], 1, 4, 3, 2, 0};
     enemy[1] = new Ingles{"Pedro", "Ingles", vida[1], dano[1], ReduzDano[1], armadura[1], 2, 4, 3, 2, 0};
     enemy[2] = new Alemao{"Cleveo", "Alemao", vida[2], dano[2], ReduzDano[2], armadura[2], 3, 4, 3, 2, 0};
     enemy[3] = new Indio{"joao", "Indio", vida[3], dano[3], ReduzDano[3], armadura[3], 4, 4, 3, 2, 0};
     enemy[4] = new Americano{"Maria", "Americano", vida[4], dano[4], ReduzDano[4], armadura[4], 5, 4, 3, 2, 0};
}

// MAQUINA DE ESTADO DAS BATALHAS
void stateBattles(Personagem *enemy[], Personagem *player)
{
     int stateMachine = 1;
     Battle *fight;
     bool win = false;
     /*
          stateMachine = 1 => vilao 1
          stateMachine = 2 => vilao 2
          stateMachine = 3 => vilao 3
          stateMachine = 4 => vilao 4
          stateMachine = 5 => vilao 5
          stateMachine = 6 => fim de jogo ganhou
          stateMachine = 7 => fim de jogo desistiu
     */

     system("CLS");
     cout << "Historiaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl;
     cout << "Historiaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl;
     cout << "Historiaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl;
     cout << "Historiaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl;
     cout << "Historiaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl;
     cout << "Historiaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl;
     cout << "Historiaa..." << endl;

     pressEnter();
      
     while (stateMachine < 6)
     {
          cout << stateMachine;
          // Inicia as batalhas entre o player Vs inimigo. E verifica seu progresso
          switch (stateMachine)
          {
          case 1:
              
               fight = new Battle(player,enemy[0]);
              
               system("cls");
               fight->Lutar();
               
              // Verifica se o player ganhou
               if (fight->Vitoria())
               //if(true)
               {
                    system("CLS");
                    cout << "Voce ganhou! Parabens..." << endl;
                    stateMachine = 2;
                    // ---------------------------------------------
                    // setar o nivel na classe
                    // chamar a func de adicionar pontos setScore()
                    // ---------------------------------------------

                    pressEnter();
               }
               // Executa caso o player perdeu
               else
               {
                    // Verifica se quer batalhar novamente
                    if (playAgain())
                    {
                         system("CLS");
                         cout << "Vamos tentar novamente..." << endl;
                         stateMachine = 1;
                         pressEnter();
                    }
                    else
                    {
                         system("CLS");
                         cout << "Voce decidiu sair do jogo?" << endl;
                         cout << "Nos vemos na proxima..." << endl;
                         stateMachine = 7;
                         pressEnter();
                    }
               }
               break;
          case 2:
               
               fight = new Battle(player, enemy[1]);
                                               
               // Verifica se o player ganhou
               if (fight->Vitoria())
               {
                    system("CLS");
                    cout << "Voce ganhou! Parabens..." << endl;
                    stateMachine = 3;
                    pressEnter();
               }
               // Executa caso o player perdeu
               else
               {
                    // Verifica se quer batalhar novamente
                    if (playAgain())
                    {
                         system("CLS");
                         cout << "Vamos tentar novamente..." << endl;
                         stateMachine = 2;
                         pressEnter();
                    }
                    else
                    {
                         system("CLS");
                         cout << "Voce decidiu sair do jogo?" << endl;
                         cout << "Nos vemos na proxima..." << endl;
                         stateMachine = 7;
                         pressEnter();
                    }
               }
               break;
          case 3:

               fight = new Battle(player, enemy[1]);
                                               
               // Verifica se o player ganhou
               if (fight->Vitoria())
               {
                    system("CLS");
                    cout << "Voce ganhou! Parabens..." << endl;
                    stateMachine = 4;
                    pressEnter();
               }
               // Executa caso o player perdeu
               else
               {
                    // Verifica se quer batalhar novamente
                    if (playAgain())
                    {
                         system("CLS");
                         cout << "Vamos tentar novamente..." << endl;
                         stateMachine = 3;
                         pressEnter();
                    }
                    else
                    {
                         system("CLS");
                         cout << "Voce decidiu sair do jogo?" << endl;
                         cout << "Nos vemos na proxima..." << endl;
                         stateMachine = 7;
                         pressEnter();
                    }
               }
               break;
          case 4:
               fight = new Battle(player, enemy[1]);
                                               
               // Verifica se o player ganhou
               if (fight->Vitoria())
               {
                    system("CLS");
                    cout << "Voce ganhou! Parabens..." << endl;
                    stateMachine = 5;
                    pressEnter();
               }
               // Executa caso o player perdeu
               else
               {
                    // Verifica se quer batalhar novamente
                    if (playAgain())
                    {
                         system("CLS");
                         cout << "Vamos tentar novamente..." << endl;
                         stateMachine = 4;
                         pressEnter();
                    }
                    else
                    {
                         system("CLS");
                         cout << "Voce decidiu sair do jogo?" << endl;
                         cout << "Nos vemos na proxima..." << endl;
                         stateMachine = 7;
                         pressEnter();
                    }
               }
               break;
          case 5:
               fight = new Battle(player, enemy[1]);
                                               
               // Verifica se o player ganhou
               if (fight->Vitoria())
               {
                    system("CLS");
                    cout << "Voce ganhou! Parabens..." << endl;
                    stateMachine = 6;
                    pressEnter();
               }
               // Executa caso o player perdeu
               else
               {
                    // Verifica se quer batalhar novamente
                    if (playAgain())
                    {
                         system("CLS");
                         cout << "Vamos tentar novamente..." << endl;
                         stateMachine = 5;
                         pressEnter();
                    }
                    else
                    {
                         system("CLS");
                         cout << "Voce decidiu sair do jogo?" << endl;
                         cout << "Nos vemos na proxima..." << endl;
                         stateMachine = 7;
                         pressEnter();
                    }
               }
               break;
          default:
               cout << "\n\n inesperado default stateMachine()\n\n";
               break;
          }
     }

     // Verifica como o jogo terminou
     if (stateMachine == 6){
          system("CLS");
          cout << "Parabens guerreiro!!!" << endl;
          cout << "\n\nFim de jogo! Voce ganhou!" << endl;
     }
     if (stateMachine == 7){
          system("CLS");
          cout << "Voce e um fracasso!!!" << endl;
          cout << "\n\nFim de jogo! Voce perdeu!" << endl;
     }
}

int main()
{

     // Cria o vetor de inimigos
     Personagem *enemy[5];

     // Inicializa os inimigos com valores aleatorios
     setEnemy(enemy);

     // Cria o player
     Personagem *player;

     // Inicializa o player de acordo com suas preferencias
     player = iniciaJogador();

     // Inicia a batalha com os viloes
     stateBattles(enemy, player);

     // Testes
     player->detalhes();
     enemy[0]->detalhes();
     enemy[1]->detalhes();
     enemy[2]->detalhes();
     enemy[3]->detalhes();
     enemy[4]->detalhes();

     //-------------------------------PROBLEMAS-----------------
     // VER PORQUE A ANCIONALIDADE TA INDO ERRADO
     //---------------------------------------------------------
     return 0;
}