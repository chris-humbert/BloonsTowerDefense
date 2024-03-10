#include "Bloon.h"
Bloon::Bloon()
{

}

Bloon::Bloon(int health, int location)
{

}

Bloon::~Bloon()
{

}

int Bloon::GetHealth()
{
    return m_health;
}

void Bloon::SetHealth(int health)
{
    m_health = health;
}

int Bloon::GetLocation()
{
    return m_location;
}

void Bloon::SetLocation(int location)
{
    m_location = location;
}

ostream& operator<<(ostream& output, Bloon& myBloon)
{
    //Setup for how bloon is output on the map
    output << "Bloon: " << myBloon.GetColor() << " Health: " << myBloon.GetHealth() << endl;
    return output;
}

