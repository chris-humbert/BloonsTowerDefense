#ifndef _GAME_H_
#define _GAME_H_

//Includes of required classes
#include "Monkey.h"
#include "Dart.h"
#include "Bomb.h"
#include "Boomerang.h"
#include "Bloon.h"
#include "Basic.h"
#include "Lead.h"
#include "Zebra.h"

//Includes of required libraries
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

//Constants for start
const int START_ROUND = 1;
const int START_LIFE = 100;
const int START_MONEY = 10;

//Constants for length
const int PATH_LENGTH = 3;
const int START_BLOON = 0;

//Constants for money/cost
const int COST_DART = 2;
const int COST_BOOMERANG = 4;
const int COST_BOMB = 6;
const int COST_IMPROVE = 2;
const int EARN_POP = 1;
const int IMPROVE_VALUE = 2;

//Constants for damage
const int DAMAGE_DART = 1;
const int DAMAGE_BOOM = 1;
const int DAMAGE_BOMB = 1;


class Game {
public:
  Game();
  ~Game();
  void PrintMap();
  void ImproveMonkey();
  void BuyMonkey();
  void PlaceMonkey(int choice);
  void StartGame();
  int MainMenu();
  void Stats();
  void PlayRound();
  void PopulateBloons();
  void ResolveBattle();
  void RemovePopped();
  void MoveBloons();
  void CheckPath();
private:
  vector<Bloon*> m_bloons;
  vector<Monkey*> m_monkeys;
  int m_curRound;
  int m_curMoney;
  int m_curLife;
};
#endif
