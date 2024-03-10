#ifndef LEAD_H_
#define LEAD_H_
#include "Bloon.h"

const string LEAD_BLOON = "lead";
const int AFTER_POP_LEAD = 10;

class Lead: public Bloon{
 public:
  Lead();
  Lead(int, int);
  ~Lead();
  int Pop(int damage);
  string GetColor();
private:
  string m_color;
};
#endif
