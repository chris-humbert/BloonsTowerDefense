#include "Basic.h"
// All bloons with health >= 6 are black 

// Name: Basic() - Default Constructor
// Description: Creates a new Basic Bloon
// Preconditions: None
// Postconditions: Can create a Basic Bloon
Basic::Basic()
{

}

// Name: Basic(int health, int location)
// Description: Creates a new basic bloon with health at a specific location
// if health = 1, red, 2=blue, 3=green, 4=yellow, 5=pink, >=6=black
// Preconditions: None
// Postconditions: Can create a basic bloon
Basic::Basic(int health, int location)
{
    //Calls SetHealth() from the Bloon class using the passed in health value
    SetHealth(health);
    //Calls SetLocation() from the Bloon class using the past in location value
    SetLocation(location);

    //This switch case passes in the health value to give the balloon a color based on its health
    switch(color(health))
    {
        case 1:
            m_color = "red";
            break;
        case 2:
            m_color = "blue";
            break;
        case 3:
            m_color = "green";
            break;
        case 4:
            m_color = "yellow";
            break;
        case 5:
            m_color = "pink";
            break;
        default:
            m_color = "black";
            break;
    }
}

// Name: ~Basic - Virtual Destructor
// Description: Makes sure everything in child class is deallocated
// Preconditions: None
// Postconditions: Everything dynamically allocated is deallocated
Basic::~Basic()
{
}


// Name: Pop
// Description: Changes the color of the bloon based on how many health it has left
// red = 1, blue = 2, green = 3, yellow = 4, pink = 5, black >=6
// Preconditions: None
// Postconditions: Returns number of pops that occurred.
//                 Number of pops is the lesser of (health left of bloon) or (damage caused by monkey).
int Basic::Pop(int damage)
{
    //Gets the health of the bloon so it can compare how much damage the monkey did at the end of the function and return the lower value
    int originalBloonHealth = GetHealth();
    int numPops = 0;
    int bloonHealth = GetHealth();

    //This statement checks to see if the bloon is already dead before taking damage and if it is it returns 0
    if(bloonHealth <= 0)
    {
        return 0;
    }


    //Otherwise outputs the monkey popped the colored bloon and then if its health is <= 0 it outputs the bloon is gone
    else
    {
        cout << "The " << m_color << " bloon pops!" << endl;
        //Bloon takes damage given by monkey
        bloonHealth = GetHealth() - damage;

        SetHealth(bloonHealth);
        bloonHealth = GetHealth();

        //Checks to see if the bloon was killed by the monkey
        if(bloonHealth <= 0)
            cout << "The bloon is gone" << endl;

        //If bloon isnt dead it finds out what color it should be based off health
        else
        {
            int myColor = color(bloonHealth);
            switch(myColor)
            {
                case 1:
                    m_color = "red";
                    break;
                case 2:
                    m_color = "blue";
                    break;
                case 3:
                    m_color = "green";
                    break;
                case 4:
                    m_color = "yellow";
                    break;
                case 5:
                    m_color = "pink";
                    break;
                default:
                    m_color = "black";
                    break;
            }
        }
    }

    //This block uses if and else if to determine which value of originalbloonHealth and damage was less
    if(originalBloonHealth > damage)
        numPops = damage;
    else if(originalBloonHealth < damage)
        numPops = originalBloonHealth;

    //returns value from above
    return numPops;
}


// Name: GetColor()
// Description: Returns the current color of a bloon
// Preconditions: None
// Postconditions: None
string Basic::GetColor()
{
    return m_color;
}

