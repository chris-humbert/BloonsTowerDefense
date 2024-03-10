#include "Monkey.h"
Monkey::Monkey()
{

}

Monkey::Monkey(string type, int damage, int location)
{

}

Monkey::~Monkey()
{

}

int Monkey::GetDamage()
{
    return m_damage;
}

string Monkey::GetType()
{
    return m_type;
}

int Monkey::GetLocation()
{
    return m_location;
}

void Monkey::SetDamage(int damage)
{
    m_damage = damage;
}

void Monkey::SetType(string type)
{
    m_type = type;
}

void Monkey::SetLocation(int location)
{
    m_location = location;
}

ostream& operator<<(ostream& output, Monkey &myMonkey)
{
    //Output for a Monkey based on project check file
    output << myMonkey.GetType() << " Monkey: Location " << myMonkey.GetLocation() << " Damage:" << myMonkey.GetDamage() << endl;
    return output;
}