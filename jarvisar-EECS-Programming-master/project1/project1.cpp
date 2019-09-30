/*
 * Project Title:
 * - Zork Clone
 * Description: 
 * A player must collect items found in different rooms
 * to find and unlock the treasure chest. Once the treasure
 * is found, the player must return to the beginning room.
 *
 * Developers:
 * - Adam Jarvis - jarvisar@mail.uc.edu
 * - Will Dentino - dentinwm@mail.uc.edu
 *
 *
 * Developer comments: // Not optional
 * Adam Jarvis:
 * Created the initial layout of the map and programmed
 * player movement. Learned that functions are incredibly
 * powerful since they can be reused whenever.
 * 
 * Will Dentino:
 * Created the inventory system and programmed how to
 * track what items the player currently has. Learned
 * that structures are very useful since they can be used
 * for a wide variety of purposes.
 */

// Milestone 2 was not checked off since the project was uploaded to GitHub Wednesday, March 13th. 

#include <iostream>

using namespace std;

struct Player {
    int loc = 1;
    bool hasAxe = false;
    bool hasCoin = false;
    bool hasKey = false;
    bool hasDet = false;
    bool hasTreasure = false;
};

/* Function Name: useItem()
 *
 * Function Description:
 * Runs when the player chooses to "use an item", can change level layout based on inventory.
 *
 * Parameters:
 * The p1 parameter is player structure.
 * The treeCut parameter determines whether the tree in the forest was cleared.
 * The paidToll parameter determines whether the toll was paid.
 * The foundCoin parameter determins whether the player found the coin yet.
 * The win paremeter determins whether win conditions have been met.
 *
 */

void useItem(Player &p1, bool &treeCut, bool &paidToll, bool &foundCoin, bool &win){
	if ((p1.loc == 3) && (treeCut == false)){
        if (p1.hasAxe == true){
            cout << "You cut down the tree with the axe!" << endl;
            treeCut = true;
        }
        else{
            cout << "No item can be used here." << endl;
        }  
    }
    else if (p1.loc == 2){
        if ((p1.hasDet == true) && (p1.hasCoin == false)){
            cout << "You found a coin with the metal detector!" << endl;
            p1.hasCoin = true;
            foundCoin = true;
        }
        else{
            cout << "No item can be used here." << endl;
        }  
    }
    else if (p1.loc == 4){
        if ((p1.hasCoin == true) && (paidToll == false)){
            cout << "You paid the toll!" << endl;
            paidToll = true;
        }
        else{
            cout << "No item can be used here." << endl;
        }  
    }
    else if (p1.loc == 6){
        if ((p1.hasKey == false) && (p1.hasDet == true)){
            cout << "You found a metal key!" << endl;
            p1.hasKey = true;
        }
        else{
            cout << "No item can be used here." << endl;
        }  
    }
    else if (p1.loc == 5){
        if (p1.hasKey == true){
            cout << "You unlocked the chest! Return to start to win!" << endl;
            p1.hasTreasure = true;
        }
        else{
            cout << "No item can be used here." << endl;
        }
    }
    else{
        cout << "No item can be used here." << endl;
    }
}

/* Function Name: startPlay()
 *
 * Function Description:
 * Prints current valid controls.
 *
 * Parameters:
 * The p1 parameter is player structure.
 *
 */
void startPlay(Player &p1){
	cout << "Choose what to do: ";
    if (p1.loc == 1){
        cout << "S: south | D: east ";
    }
    else if (p1.loc == 2){
        cout << "S: south | A: west ";
    }
    else if (p1.loc == 3){
        cout << "W: north | S: south | D: east ";
    }
    else if (p1.loc == 4){
        cout << "W: north | S: south | A: west ";
    }
    else if (p1.loc == 5){
        cout << "W: north ";
    }
    else if (p1.loc == 6){
        cout << "W: north ";
    }
    cout << "| Q: look around | E: use item" << endl;
}

/* Function Name: lookAround()
 *
 * Function Description:
 * Initiates the player's "look around" ability, finds specific items in specific rooms.
 *
 * Parameters:
 * The p1 parameter is player structure.
 *
 */
void lookAround(Player &p1){
	if (p1.loc == 1){
        if (p1.hasAxe == false){
            cout << "You find an axe stuck in an old tree stump." << endl;
            p1.hasAxe = true;
        }
        else
            cout << "You find nothing." << endl;
    }
    else if (p1.loc == 5){
        if (p1.hasDet == false){
            cout << "You find a metal detector behind the chest!" << endl;
            p1.hasDet = true;
        }
        else
            cout << "You find nothing." << endl;
    }
    else if (p1.loc == 6){
        if (p1.hasKey == false)
            cout << "You have an odd sensation something is beneath you." << endl;
    }
    else
        cout << "You find nothing." << endl;
}

/* Function Name: movePlayer()
 *
 * Function Description:
 * Moves the player based on input and boolean values.
 *
 * Parameters:
 * The p1 parameter is player structure.
 * The input paremeter is the player's input.
 * The treeCut paremeter determines whether the tree has been cleared or not.
 * The paidToll parameter determines whether the toll has been paid or not.
 *
 */
void movePlayer(Player &p1, char input, bool treeCut, bool paidToll){
	if (input == 'w'){
        if ((p1.loc == 1) || (p1.loc == 2))
            cout << "You hit a wall. Choose a different direction." << endl;
        else
            p1.loc = p1.loc - 2;
    }
    else if (input == 'a'){
        if ((p1.loc == 1) || (p1.loc == 3) || (p1.loc == 5) || (p1.loc == 6))
            cout << "You hit a wall. Choose a different direction." << endl;
        else
            p1.loc = p1.loc - 1;
    }
    else if (input == 's'){
        if ((p1.loc == 5) || (p1.loc == 6))
            cout << "You hit a wall. Choose a different direction." << endl;
        else if (p1.loc == 3){
            if (treeCut == false){
                cout << "A big tree is in your way." << endl;
            }
            else if (treeCut == true)
                p1.loc = p1.loc + 2;
        }
        else if (p1.loc == 4){
            if (paidToll == false){
                cout << "You have not paid the toll!" << endl;
            }
            else if (paidToll == true){
                p1.loc = p1.loc + 2;
            }
        }
        else
            p1.loc = p1.loc + 2;
    }
    else if (input == 'd'){
        if ((p1.loc == 2) || (p1.loc == 4) || (p1.loc == 6) || (p1.loc == 5))
            cout << "You hit a wall. Choose a different direction." << endl;
        else
            p1.loc = p1.loc + 1;
    }
}

/* Function Name: reportLocation()
 *
 * Function Description:
 * Prints a statement about the player's location.
 *
 * Parameters:
 * The p1 parameter is player structure.
 *
 */
void reportLocation(Player &p1){
	if (p1.loc == 1){
        cout << "You enter a grassy field." << endl;
    }
    else if (p1.loc == 2){
        cout << "You find yourself on a beach." << endl;
    }
    else if (p1.loc == 3){
        cout << "You walk into a forest." << endl;
    }
    else if (p1.loc == 4){
        cout << "You come across a bridge with a troll demanding a toll." << endl;
    }
    else if (p1.loc == 5){
        cout << "You enter a sacred room with a locked treasure chest in the center." << endl;
    }
    else if (p1.loc == 6){
        cout << "You find yourself in a desert." << endl;
    }
}

int main()
{
    cout << "Find, unlock, and escape with the treasure! Use WASD to move, Q to look around, E to use items, and C to quit." << endl;
    Player p1;
    bool win = false;
    bool treeCut = false;
    bool paidToll = false;
    bool foundCoin = false;
    char input;
    int oldLoc;
    reportLocation(p1);
    do{
        startPlay(p1);
        cin >> input;
        oldLoc = p1.loc;
        if (input == 'c'){
            cout << "Player has quit the game." << endl;
            return 0;
        }
        else if (input == 'e'){
            useItem(p1, treeCut, paidToll, foundCoin, win);
        }
        else if (input == 'q'){
            lookAround(p1);
        }
        else
            movePlayer(p1, input, treeCut, paidToll);
        if (oldLoc != p1.loc){
            reportLocation(p1);
        }
        if ((p1.loc == 1) && (p1.hasTreasure == true)){
            cout << "You successfully escaped with the treasure!" << endl;
            win = true;
        }
    }while(win == false);
    return 0;
}
