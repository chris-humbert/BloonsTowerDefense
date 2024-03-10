#ifndef DART_H_
#define DART_H_
#include "Monkey.h"

class Dart: public Monkey {
 public:
  Dart();
  Dart(string, int, int);
  ~Dart();
  int Attack(vector<Bloon*>);
};
#endif
