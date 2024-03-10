#include "Game.h"
Game::Game()
{
    //Initializes game variables with constants
    m_curLife = START_LIFE;
    m_curMoney = START_MONEY;
    m_curRound = START_ROUND;
}

Game::~Game()
{
    //Sizes of the monkey and bloon vectors
    int monkeySize = m_monkeys.size();
    int bloonSize = m_bloons.size();

    //This for loop goes through the monkey vector and deletes every monkey
    for(int i = 0; i < monkeySize; i++)
    {
        delete m_monkeys[i];
    }

    //This for loop goes through the bloon vector and deletes every bloon
    for(int j = 0; j < bloonSize; j++)
    {
        delete m_bloons[j];
    }
}

void Game::PrintMap()
{
    //Sizes for monkey and bloon vectors
    int bloonSize = m_bloons.size();
    int monkeySize = m_monkeys.size();

    //This for loop goes through the path and outputs the things (monkey or bloon) in the locations
    for(int i = 1; i <= PATH_LENGTH; i++)
    {
        //Counter to check to see if there are any things in specific location
        int counter = 0;
        cout << endl << "**Location " << i << "**" << endl;
        cout << "--Monkeys--" << endl;

        //This for loop goes through the monkey vector and checks to see if there are monkeys in locations
        for(int m = 0; m < monkeySize; m++)
        {
            //This if statement checks to see if there is a monkey in the location
            if(m_monkeys[m]->GetLocation() == i)
            {
                //Increments counter if there is a monkey in the location and outputs the monkey stats
                counter ++;
                cout << counter << ". " << *m_monkeys[m];
            }
        }

        //This if statement checks counter to see if there are any monkeys
        //Counter works the same in bloon as in monkey so I didnt comment
        if(counter == 0)
            cout << "None" << endl;

        //Resets counter to 0 to do the same thing with bloons
        counter = 0;
        cout << "<<Bloons>>" << endl;

        //This for loop goes through the bloon vector and check to see if bloons are in locataions
        for(int b = 0; b < bloonSize; b++)
        {

            //This if statement checks to see if the bloons hp is more than 0 and that its in the same location
            if(m_bloons[b]->GetLocation() == i && m_bloons[b]->GetHealth() > 0)
            {
                counter ++;
                cout << *m_bloons[b];
            }
        }
        if(counter == 0)
            cout << "None" << endl;
    }
}

void Game::ImproveMonkey()
{
    //choice: used in choosing a monkey, chosenFlag: used to check if the choice is valid
    int choice;
    bool chosenFlag = false;
    int monkeySize = m_monkeys.size();

    //This if else statement first checks to see if there are any monkey's in the vector and if there are it lets the user choose one to improve
    if(monkeySize == 0)
        cout << "There are no monkeys to improve" << endl;
    else
    {
        //This do while loop makes the user choose a valid monkey to improve
        do
        {
            cout << "Which monkey would you like to improve " << "(1-" << monkeySize << ")" << endl;

            //This for loop goes through each monkey and prints it out
            for(int i = 0; i < monkeySize; i++)
            {
                cout << i + 1 << ". " << *m_monkeys[i];
            }
            cin >> choice;

            //This if statement checks to see if the choice is valid
            if(choice >= 1 && choice <= monkeySize)
                chosenFlag = true;
        }
        while(chosenFlag == false);

        //This if else statement checks to see if the user has enough money to upgrade and then does the appropriate action
        if(m_curMoney - COST_IMPROVE >= 0)
        {
            //Takes money away for upgrade cost
            m_curMoney = m_curMoney - COST_IMPROVE;
            //This uses the users choice to set the damage using the same monkeys original damage + the improve value
            m_monkeys[choice - 1]->SetDamage(m_monkeys[choice - 1]->GetDamage() + IMPROVE_VALUE);
            cout << m_monkeys[choice - 1]->GetType() << " in position " << choice << " improved!" << endl;
        }
        else
            cout << "You don't have enough money to upgrade this monkey" << endl;

    }
}

void Game::BuyMonkey()
{
    int choice;
    bool choiceFlag = false;

    //This do while loop asks the user which monkey type they want to choose or cancel
    do
    {
        cout << "1. Dart Monkey" << endl;
        cout << "2. Boomerang Monkey" << endl;
        cout << "3. Bomb Monkey" << endl;
        cout << "4. Cancel" << endl;
        cin >> choice;

        //Checks to see if the choice is valid
        if(choice >= 1 && choice <= 4)
            choiceFlag = true;
    }
    while(choiceFlag == false);

    //This switch case uses the monkey type choice above to place a monkey the user chooses if possible
    //Each number corresponds to a monkey
    //Same throughout cases just with different values for each
    switch(choice)
    {
        case 1:
            //This if statement checks to see if the user has enough money
            if(m_curMoney - COST_DART >= 0)
            {
                //Removes the cost of dart monkey from players money
                m_curMoney = m_curMoney - COST_DART;
                //Calls PlaceMonkey with dart monkey as the choice
                PlaceMonkey(choice);
            }
            else
                cout << "You don't have enough money to buy this monkey" << endl;
            break;

        case 2:
            if(m_curMoney - COST_BOOMERANG >= 0)
            {
                m_curMoney = m_curMoney - COST_BOOMERANG;
                PlaceMonkey(choice);
            }
            else
                cout << "You don't have enough money to buy this monkey" << endl;
            break;

        case 3:
            if(m_curMoney - COST_BOMB >= 0)
            {
                m_curMoney = m_curMoney - COST_BOMB;
                PlaceMonkey(choice);
            }
            else
                cout << "You don't have enough money to buy this monkey" << endl;
            break;

        case 4:
            break;
    }
}

void Game::PlaceMonkey(int choices)
{
    //New monkey variable to be placed
    Monkey* newMonkey;
    int place;
    bool placeFlag = false;

    //This do while loop asks where the user would like to place the monkey on the path length
    do
    {
        cout << "Where would you like to place the new monkey? (1-" << PATH_LENGTH << ")" << endl;
        cin >> place;

        //This if statement checks to see if the user entered a correct it sets placeFlag to true
        if(place >= 1 && place <= PATH_LENGTH)
            placeFlag = true;
    }
    while(placeFlag == false);

    //These switch statements just create the monkey with the chosen location above and makes it using the chosen type from the parameter
    switch(choices)
    {
        case 1:
            newMonkey = new Dart("Dart", DAMAGE_DART, place);
            m_monkeys.push_back(newMonkey);
            break;

        case 2:
            newMonkey = new Boomerang("Boomerang", DAMAGE_BOOM, place);
            m_monkeys.push_back(newMonkey);
            break;

        case 3:
            newMonkey = new Bomb("Bomb", DAMAGE_BOMB, place);
            m_monkeys.push_back(newMonkey);
            break;
    }
    //Prints out what monkey the player created at the location
    cout << "New " << newMonkey->GetType() << " monkey created at location " << place << endl;
}

void Game::StartGame()
{
    cout << "Welcome to UMBC Bloons!" << endl;
    int action;

    //Runs main menu until player loses or chooses quit (6) option
    do
    {
        action = MainMenu();
    }
    while(action != 6);
    cout << "Thanks for playing!" << endl;
}

int Game::MainMenu()
{
    //This checks if the user is dead and if so prints a loss statement and quits
    if(m_curLife <= 0)
    {
        cout << "You Lose" << endl;
        return 6;
    }

    //this else block runs the entire main menu
    else
    {
        int action;
        bool actionFlag = false;

        //This do-while loop just asks the user to choose an option 1-5 and if the value chosen isn't
        //1-5 it will reprompt the user
        do
        {
            cout << "What would you like to do?:" << endl;
            cout << "1. View Map" << endl;
            cout << "2. Buy New Monkey" << endl;
            cout << "3. Improve Existing Monkey" << endl;
            cout << "4. Progress Round" << endl;
            cout << "5. Check Stats" << endl;
            cout << "6. Quit" << endl;
            cin >> action;

            //Same as every other flag statement just validates its between the values
            if(action >= 1 &&  action <= 6)
                actionFlag = true;
            else
                cout << "Please select an int (1-6)" << endl;
        }
        while(actionFlag == false);

        //This switch statement uses the option gotten from the do-while loop above and then does that action
        switch(action)
        {
            case 1:
                PrintMap();
                break;

            case 2:
                BuyMonkey();
                break;

            case 3:
                ImproveMonkey();
                break;

            case 4:
                PlayRound();
                break;

            case 5:
                Stats();
                break;

            case 6:
                return 6;
                break;
        }
    }
return 0;
}

void Game::Stats()
{
    //Displays stats
    cout << "**CURRENT STATS**" << endl;
    cout << "Current Round: " << m_curRound << endl;
    cout << "Monkeys Working: " << m_monkeys.size() << endl;
    cout << "Current Money: " << m_curMoney << endl;
    cout << "Current Life: " << m_curLife << endl;
}

void Game::PlayRound()
{
    cout << "Starting Round " << m_curRound << endl;
    //Adds bloons to the vector
    PopulateBloons();
    //Monkey's attack the bloons
    ResolveBattle();
    //Removes all the bloons that have less than or equal to 0 hp
    RemovePopped();
    //Moves the bloons
    MoveBloons();
    cout << "The bloons move along the path" << endl;
    //Checks to see if any bloons are past the damage point
    CheckPath();
    cout << "Round " << m_curRound << " completed!" << endl;
    m_curRound ++;
}

void Game::PopulateBloons()
{
    //For each round adds another bloon to the vector
    for(int i = 1; i <= m_curRound; i++)
    {
        //Creates a new bloon object
        Bloon* newBloon = new Basic(i, START_BLOON);
        //Output statement telling user that the bloon was made
        cout << "A new " << newBloon->GetColor() << " bloon appears!" << endl;
        m_bloons.push_back(newBloon);

        //If the round is 10 this statement makes one lead bloon
        if(m_curRound == 10 && i == 10)
        {
            newBloon = new Lead(i, START_BLOON);
            cout << "A new " << newBloon->GetColor() << " bloon appears!" << endl;
            m_bloons.push_back(newBloon);
        }

        //If the round is 12
        if(m_curRound == 12 && i == 12)
        {
            newBloon = new Zebra(i, START_BLOON);
            cout << "A new " << newBloon->GetColor() << " bloon appears!" << endl;
            m_bloons.push_back(newBloon);
        }
    }
}

void Game::ResolveBattle()
{
    int monkeySize = m_monkeys.size();
    int bloonSize = m_bloons.size();

    //This for loops splits the zebra bloon if it will be attacked
    for(int i = 0; i < monkeySize; i++)
    {
        for(int j = 0; j < bloonSize; j++)
            if((m_bloons[j]->GetLocation() == m_monkeys[i]->GetLocation()) && m_bloons[j]->GetColor() == "zebra" && (m_monkeys[i]->GetType() == "Bomb" || m_monkeys[i]->GetType() == "Boomerang"))
            {
                Bloon* newBloon = new Basic(10, m_bloons[j]->GetLocation());
                m_bloons.push_back(newBloon);
            }
    }

    //This for loop calls attack for all monkeys in the monkey vector and adds the return value (earnings) to the players money after it multiplies it by how much a pop is worth EARN_POP
    for(int m = 0; m < monkeySize; m++)
    {
        m_curMoney += (m_monkeys[m]->Attack(m_bloons) * EARN_POP);
    }
}

void Game::RemovePopped()
{
    int bloonSize = m_bloons.size();

    //Reverses through the list to dealocate any bloon in the bloon vector that has <= health to 0 and removes it through
    for(int i = bloonSize - 1; i >= 0; i--)
    {
        //If the bloon health is <= 0 then it deletes bloon and removes it from the vector
        if(m_bloons[i]->GetHealth() <= 0)
            {
                delete m_bloons[i];
                m_bloons.erase(m_bloons.begin() + i);
            }
    }
}

void Game::MoveBloons()
{
    int bloonSize = m_bloons.size();
    int location;

    //This for loop moves every bloon forward a spot on the map by added 1 to location
    for(int i = 0; i < bloonSize; i++)
    {
        location = m_bloons[i]->GetLocation();
        m_bloons[i]->SetLocation(location + 1);
    }
}

void Game::CheckPath()
{
    int bloonSize = m_bloons.size();

    //This for loop goes through the bloon vector and any bloon past the path length
    for(int i = bloonSize - 1; i >= 0; i--)
    {
        //I changed it to > PATH_LENGTH because when bloons in location 2 moves to 3 it instantly takes damage and the monkeys dont get to attack it first
        //This if statement checks to see if the bloons location is past the path length
        if(m_bloons[i]->GetLocation() > PATH_LENGTH)
            {
                //Removes remaining bloon health from players health as to take damage
                m_curLife -= m_bloons[i]->GetHealth();
                delete m_bloons[i];
                m_bloons.erase(m_bloons.begin() + i);
            }
    }
}

