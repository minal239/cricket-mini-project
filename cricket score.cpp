#include <iostream>
#include <limits>
using namespace std;

class Player
{
public:
    char name[20];
    int X; // Total overs played

    virtual void inputDetails(int playerNumber) = 0;
    virtual void displayDetails(int playerNumber) = 0;
};

class Batsman : public Player
{
public:
    int R;           // Runs scored
    int Total_over;  // Total overs played
    char status;     // 'N' if out, 'Y' if not out

    void inputDetails(int playerNumber) override
    {
        cout << "Name of the batsman " << playerNumber << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.getline(name, 20);
        cout << "Runs scored by the batsman " << playerNumber << endl;
        cin >> R;
        cout << "Overs played by the batsman " << playerNumber << endl;
        cin >> Total_over;
        cout << "Status of the batsman (N if out, Y if not out)" << endl;
        cin >> status;
    }

    void displayDetails(int playerNumber) override
    {
        cout << "Batsman number: " << playerNumber << endl;
        cout << "Batsman name: " << name << endl;
        cout << "Runs scored by the batsman: " << R << endl;
        cout << "Total overs played by the batsman: " << Total_over << endl;
        cout << "Player status: " << (status == 'N' ? "Out" : "Not Out") << endl;
    }
};

class Bowler : public Player
{
public:
    int Y; // Runs given 
    int Z; // Wickets taken 

    void inputDetails(int playerNumber) override
    {
        cout << "Name of the bowler " << playerNumber << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.getline(name, 20);
        cout << "Runs given by the bowler " << playerNumber << endl;
        cin >> Y;
        cout << "Wickets taken by the bowler " << playerNumber << endl;
        cin >> Z;
        cout << "Total overs played by the bowler " << playerNumber << endl;
        cin >> X;
    }

    void displayDetails(int playerNumber) override
    {
        cout << "Bowler number: " << playerNumber << endl;
        cout << "Bowler name: " << name << endl;
        cout << "Runs given by the bowler: " << Y << endl;
        cout << "Total overs played by the bowler: " << X << endl;
        cout << "Total wickets taken by the bowler: " << Z << endl;
    }
};

int main()
{
    Player* players[3];

    cout << "Enter the details of Batsmen:" << endl;
    for (int i = 0; i < 3; i++)
    {
        players[i] = new Batsman();
        players[i]->inputDetails(i + 1);
    }

    cout << "Enter the details of Bowlers:" << endl;
    for (int i = 0; i < 3; i++)
    {
        players[i] = new Bowler();
        players[i]->inputDetails(i + 1);
    }

    cout << "THANKS" << endl;

    while (true)
    {
        cout << "Press 1 to see Batsmen details OR Press 2 to see Bowlers details" << endl;
        int player_type;
        cin >> player_type;

        switch (player_type)
        {
        case 1:
            cout << "Enter the batsman number to see details:" << endl;
            int batsmanNumber;
            cin >> batsmanNumber;
            players[batsmanNumber - 1]->displayDetails(batsmanNumber);
            break;

        case 2:
            cout << "Enter the bowler number to see details:" << endl;
            int bowlerNumber;
            cin >> bowlerNumber;
            players[bowlerNumber - 1]->displayDetails(bowlerNumber);
            break;

        default:
            cout << "Enter a valid value" << endl;
        }

        cout << "Do you wish to continue? (Y-1 N-2)" << endl;
        int continueChoice;
        cin >> continueChoice;

        if (continueChoice != 1)
        {
            cout << "THANKS.....\nPress any key to exit";
            break;
        }
    }

    // Free allocated memory
    for (int i = 0; i < 3; i++)
    {
        delete players[i];
    }

    return 0;
}
