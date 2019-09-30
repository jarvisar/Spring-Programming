#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int rollDie(){
    // Returns a number between 1 and 6
    return (rand() % 6) + 1;
}


bool playOneGame(){
    // Runs the game once, returns true if win, false if otherwise
    int temp = 0;
    int point = -999;
    do{
        if ((point == -999)){
            cout << "Enter point between 1 and 6: " << endl;
            cin >> point;
        }
        else{
            cout << "Error: Enter point between 1 and 6: " << endl;
            cin >> point;
        }
    }while ((point <= 0) || (point > 6));
    for (int i=0; i<3; ++i){
        temp = rollDie();
        cout << "Roll " << i + 1 << ": " << temp << endl;
        if (temp == point){
            cout << "You won!" << endl;
            return true;
        }
    }
    cout << "You lost!" << endl;
    return false;
    
    
}

double percentage(double wins, double total){
    // Returns percentage of games won
    double percentage = wins / total;
    percentage = percentage * 100;
    return percentage;
}

void returnBank(int bank){
    // Prints amount left in bank
    cout << "Bank: $" << bank << endl;
}

void printStats(double wins, double total, int bank){
    // Prints game statistics after the game ends
    cout << "Won " << wins << " games out of " << total << endl;
    cout << "Percentage of games won: " << percentage(wins, total) << "%" << endl;
    returnBank(bank);
    
}

int main()
{
    int bank = 100;
    int wager = 0;
    srand(time(NULL));
    double wins = 0;
    double total = 0;
    while(wager < bank){
        returnBank(bank);
        cout << "Enter wager (0 to exit):" << endl;
        cin >> wager;
        if (wager == 0){
            printStats(wins, total, bank);
            return 0;
        }
        else if (((wager > bank) && (bank > 0)) || (wager < 0)){
            do{
                cout << "Invalid wager! Must be between 0 and " << bank << ". Enter valid wager: " << endl;
                cin >> wager;
            }while(((wager > bank) && (bank > 0)) || (wager < 0));
        }
        else if (bank <= 0){
            printStats(wins, total, bank);
            return 0;
        }
        if (playOneGame() == true){
            wins = wins + 1;
            bank = bank + wager;
        }
        else
            bank = bank - wager;
        
        total = total + 1;
    }
    
    printStats(wins, total, bank);
    return 0;
}
