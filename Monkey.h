#ifndef MONKEY_H_
#define MONKEY_H_
#include "Bloon.h"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

class Monkey {
 public:
  Monkey();
  Monkey(string, int, int);
  virtual ~Monkey();
  int GetDamage();
  string GetType();
  int GetLocation();
  void SetDamage(int);
  void SetType(string);
  void SetLocation(int);
  virtual int Attack(vector<Bloon*>) = 0;
  friend ostream& operator<<(ostream&, Monkey&);
private:
  int m_damage; //Damage of monkey
  string m_type; //Type of monkey (Dart, Bomb, or Boomerang)
  int m_location; //Location of monkey on track
};
#endif
