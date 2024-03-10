#ifndef BOMB_H_
#define BOMB_H_

#include "Monkey.h"
#include "Bloon.h"
#include <vector>
using namespace std;

class Bomb: public Monkey {
 public:
  Bomb();
  Bomb(string, int, int);
  ~Bomb();
  int Attack(vector<Bloon*>);
};
#endif
