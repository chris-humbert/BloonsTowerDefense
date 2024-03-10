#ifndef BLOON_H_
#define BLOON_H_
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

//Parent class for all factions
class Bloon {
 public:

  Bloon();
  Bloon(int health, int location);
  virtual ~Bloon();
  int GetHealth();
  void SetHealth(int);
  int GetLocation();
  void SetLocation(int);
  virtual int Pop(int damage) = 0;
  virtual string GetColor() = 0;
  friend ostream& operator<<(ostream&, Bloon&);
private:
  int m_health; //Health of bloon
  int m_location; //Location of bloon on track
};
#endif
