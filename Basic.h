#ifndef BASIC_H_
#define BASIC_H_

#include "Bloon.h"
enum color{red, blue, green, yellow, pink, black};

class Basic: public Bloon {
public:
Basic();
Basic(int, int);
~Basic();
int Pop(int damage);
  string GetColor();
private:
  string m_color;
};
#endif
