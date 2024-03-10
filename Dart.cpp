#include "Dart.h"
Dart::Dart()
{

}

Dart::Dart(string type, int damage, int location)
{
    SetType(type);
    SetDamage(damage);
    SetLocation(location);
}

Dart::~Dart()
{
    
}

int Dart::Attack(vector<Bloon*> theBloons)
{
    int earnings = 0;
    bool hitBloon = false;
    int bloonSize = theBloons.size();

    //This for loop iterates through the bloon vector
    for(int i = 0; i < bloonSize; i++)
    {
        //Checks to see if a bloon has been hit yet using bool hitBloon and once one has it ends hitting bloons
        if(hitBloon == false)
        {
            //This if statement checks each bloon to see if its in the same location as the monkey and if its health is greater than 0
            //If both are true it uses Pop() on the bloon using the monkeys damage and it returns num pops used for money
            if(theBloons[i]->GetLocation() == GetLocation() && (theBloons[i]->GetHealth() > 0) && theBloons[i]->GetColor() != "lead")
            {
                cout << "The dart monkey throws a dart!" << endl;
                earnings += theBloons[i]->Pop(GetDamage());
                hitBloon = true;
            }
        }
    }
return earnings;
}