#ifndef BOOMERANG_H_
#define BOOMERANG_H_
#include "Monkey.h"

class Boomerang: public Monkey {
 public:
  Boomerang();
  Boomerang(string, int, int);
  ~Boomerang();
  int Attack(vector<Bloon*>);
};
#endif
