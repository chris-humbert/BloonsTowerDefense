#ifndef ZEBRA_H_
#define ZEBRA_H_
#include "Bloon.h"

//Color of zebra bloon
const string ZEBRA_BLOON = "zebra";
const int AFTER_POP_ZEBRA = 10;

//Child class Zebra of Bloon
class Zebra: public Bloon{
 public:
  Zebra();
  Zebra(int, int);
  ~Zebra();
  int Pop(int damage);
  string GetColor();
private:
  string m_color;
};
#endif
