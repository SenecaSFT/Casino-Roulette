#include <iostream>
#include <vector>
#include <string>
#include<random>

using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::stoi;
using std::random_device;
using std::uniform_int_distribution;

enum Bet
{
    ZERO,
    EVEN,
    ODD,
    HIGH,
    LOW
};


vector<int> makeRouletteWheel();
Bet placeBet();
int spinWheel(vector<int> wheel);
void evaluateScore(int wheelSpin, Bet userBet);

int main()
{
    cout << "Hello, World!\n";
    cout << "Loading Roulette...";

    vector<int> wheel = makeRouletteWheel();
    Bet userBet = placeBet();
    int wheelSpin = spinWheel(wheel);
    evaluateScore(wheelSpin, userBet);
}

vector<int> makeRouletteWheel()
{
    vector<int> wheel = { 0, 32, 15, 19, 4, 21, 2, 25, 17, 34, 6, 27, 13, 36, 11, 30, 8, 23, 10, 5, 24, 16, 33, 1, 20, 14, 31, 9, 22, 18, 29, 7, 28, 12, 35, 3, 26 };

    return wheel;
}
Bet placeBet()
{
    bool inputIsGood = false;
   
    while (!inputIsGood)
    {
        cout << "Select Type of Bet: \n\n";
        cout << "1. 0 Bet\n";
        cout << "2. Even Bet\n";
        cout << "3. Odd Bet\n";
        cout << "4. High Bet (19-36)\n";
        cout << "5. Low Bet (1-18)\n";

        string userInput;
        cout << "\n\n> ";
        cin >> userInput;

        try
        {
            int userInputInt = stoi(userInput);

            switch (userInputInt)
            {
            case 1:
                inputIsGood = true;
                return Bet::ZERO;
            case 2:
                inputIsGood = true;
                return Bet::EVEN;
            case 3:
                inputIsGood = true;
                return Bet::ODD;
            case 4:
                inputIsGood = true;
                return Bet::HIGH;
            case 5:
                inputIsGood = true;
                return Bet::LOW;
            default:
                cout << "\nBad bet!\n";
                inputIsGood = false;
                break;
            }
        }
        catch (const std::exception&)
        {
            cout << "\n\nBAD INPUT!\n\n";
            inputIsGood = false;
        }


    }
}

int spinWheel(vector<int> wheel)
{
    random_device dev;
    uniform_int_distribution<int> dist(0, wheel.size());

    int wheelSpin = wheel[dist(dev)];

    return wheelSpin;
}

void evaluateScore(int wheelSpin, Bet userBet)
{
    cout << "\nCALCULATING SCORE!\n";
    switch (userBet)
    {
    case ZERO:
        if (wheelSpin != 0)
            cout << "YOU LOST!\n" << "Number was: " << wheelSpin;
        break;
    case EVEN:
        if (wheelSpin % 2)
            cout << "YOU LOST!\n" << "Number was: " << wheelSpin;
        else
            cout << "YOU WON!\n" << "Number was: " << wheelSpin;
        break;
    case ODD:
        if (wheelSpin % 2)
            cout << "YOU WON!\n" << "Number was: " << wheelSpin;
        else
            cout << "YOU LOST!\n" << "Number was: " << wheelSpin;
        break;
    case HIGH:
        if (wheelSpin >= 19)
            cout << "YOU WON!\n" << "Number was: " << wheelSpin;
        else
            cout << "YOU LOST!\n" << "Number was: " << wheelSpin;
        break;
    case LOW:
        if (wheelSpin <= 18)
            cout << "YOU WON!\n" << "Number was: " << wheelSpin;
        else
            cout << "YOU LOST!\n" << "Number was: " << wheelSpin;
        break;
    default:
        break;
    }
}