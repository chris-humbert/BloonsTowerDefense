#include "Boomerang.h"
Boomerang::Boomerang()
{

}

Boomerang::Boomerang(string type, int damage, int location)
{
    SetType(type);
    SetDamage(damage);
    SetLocation(location);
}

Boomerang::~Boomerang()
{

}

int Boomerang::Attack(vector<Bloon*> theBloons)
{

    //Money gotten from pops
    int special = 0;
    int bloonSize = theBloons.size();

    //This for loop iterates through the bloon vector
    for(int i = 0; i < bloonSize; i++)
    {
        //This if statement checks each bloon to see if its in the same location as the monkey and if its health is greater than 0
        //If both are true it uses Pop() on the bloon using the monkeys damage and it returns num pops used for money
        if(theBloons[i]->GetLocation() == GetLocation() && (theBloons[i]->GetHealth() > 0) && theBloons[i]->GetColor() != "lead")
        {
            cout << "The boomerang monkey throws a boomerang!" << endl;

            //This for loop has it so the monkey clearly hits twice using output statments
            for(int j = 0; j < 2; j++)
            {
                special += theBloons[i]->Pop(GetDamage());

                //Output statement for hitting twice otherwise you cant tell as easily
                //if(j == 1)
                //    cout << "The boomerang monkey returns the boomerang!" << endl;
            }
        }
    }
    return special;


}


