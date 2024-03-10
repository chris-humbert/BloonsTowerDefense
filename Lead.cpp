#include "Lead.h"
Lead::Lead()
{

}

Lead::Lead(int health, int location)
{
    SetHealth(health);
    SetLocation(location);
    m_color = LEAD_BLOON;
}

Lead::~Lead()
{

}

int Lead::Pop(int damage)
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

    else
    {
        cout << "The " << m_color << " bloon pops!" << endl;

        //What happens after a lead bloon pops turns health to 10 and makes it a black bloon
        SetHealth(AFTER_POP_LEAD);
        m_color = "black";

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
            int myColor = bloonHealth;
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
    if(originalBloonHealth > damage)
        numPops = damage;
    else if(originalBloonHealth < damage)
        numPops = originalBloonHealth;

    //returns value from above
    return numPops;
}

string Lead::GetColor()
{
    return m_color;
}
