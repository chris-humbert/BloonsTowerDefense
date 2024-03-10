#include "Bomb.h"
Bomb::Bomb()
{

}

Bomb::Bomb(string type, int damage, int location)
{
    SetType(type);
    SetDamage(damage);
    SetLocation(location);
}

Bomb::~Bomb()
{

}

int Bomb::Attack(vector<Bloon*> theBloons)
{
    //Earnings is the amount of pops the monkey gets
    int earnings = 0;

    int bloonSize = theBloons.size();

    //This for loop iterates through the bloon vector
    for(int i = 0; i < bloonSize; i++)
    {
        //This if statement checks each bloon to see if its in the same location as the monkey and if its health is greater than 0
        //If both are true it uses Pop() on the bloon using the monkeys damage and it returns num pops used for money
        if(theBloons[i]->GetLocation() == GetLocation() && (theBloons[i]->GetHealth() > 0))
        {
            cout << "The bomb monkey launches a powerful bomb at the Bloons!!!" << endl;
            earnings += theBloons[i]->Pop(GetDamage());
        }
    }
    return earnings;
}
