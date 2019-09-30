<<<<<<< HEAD
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;


void initBoard(int (&arr)[7][7]){
    srand (time(NULL));
    int i = 0;
    int j = 0;
    for (i = 0; i < 7; ++i){
        for (j = 0; j < 7; ++j){
            arr[i][j] = 0;
        }
    }
    int x;
    int y;
    for (int k = 1; k < 6; k++){
        x = (rand() % 7);
        y = (rand() % 7);
        while (arr[x][y] != 0){
            x = (rand() % 7);
            y = (rand() % 7);
        }
        arr[x][y] = k;
    }
    cout << "1 = Player | 2 = Roadtser | 3 = Juge | 4 = Pinto | 5 = Elon Musk!" << endl;
}

void dispBoard(int arr[7][7], int x, int y){
    int i = 0;
    int j = 0;
    for (i = 0; i < 7; ++i){
        cout << "| ";
        for (j = 0; j < 7; ++j){
            if ((abs(x - i) <= 2) && (abs(y - j) <= 2))
                cout << arr[i][j] << " ";
            else
                cout << "0" << " ";
        }
        cout << "|";
        cout << endl;
    }
}

int main()
{
    int arr[7][7];
    initBoard(arr);
    int i = 0;
    int j = 0;
    int x = 0;
    int y = 0;
    int ex = 0;
    int ey = 0;
    int oldx;
    int oldy;
    int totalMoves = 1;
    for (i = 0; i < 7; ++i){
        for (j = 0; j < 7; ++j){
            if (arr[i][j] == 1){
                x = i;
                y = j;
            }
        }
    }
    for (i = 0; i < 7; ++i){
        for (j = 0; j < 7; ++j){
            if (arr[i][j] == 5){
                ex = i;
                ey = j;
            }
        }
    }
    bool win = false;
    bool lose = false;
    bool awakeElon = false;
    int elonCaught = 0;
    char move;
    int oldValue;
    int eMove;
    while ((win == false) && (lose == false)){
        dispBoard(arr,x,y);
        cin >> move;
        if (move == 'w'){
            oldValue = arr[x - 1][y];
            arr[x][y] = 0;
            arr[x - 1][y] = 1;
            x = x - 1;
        }
        else if (move == 'a'){
            oldValue = arr[x][y - 1];
            arr[x][y] = 0;
            arr[x][y - 1] = 1;
            y = y - 1;
        }
        else if (move == 's'){
            oldValue = arr[x + 1][y];
            arr[x][y] = 0;
            arr[x + 1][y] = 1;
            x = x + 1;
        }
        else if (move == 'd'){
            oldValue = arr[x][y + 1];
            arr[x][y] = 0;
            arr[x][y + 1] = 1;
            y = y + 1;
        }
        else if (move == 'c'){
            lose = true;
            cout << "Game Over" << endl;
            cout << "Total moves: " << totalMoves << endl;
        }
        else{
            cout << "Please enter valid key (WASD to move | C to quit)" << endl;
        }
        if (oldValue == 2){
            win = true;
            cout << "You successfully escaped in the Roadster!" << endl;
            cout << "Total moves: " << totalMoves << endl;
            return 0;
        }
        else if((oldValue == 3) || (oldValue == 4)){
            if (awakeElon == true){
                lose = true;
                cout << "Elon caught you!" << endl;
                cout << "Total moves: " << totalMoves << endl;
                return 0;
            }
            else{
                win = true;
                cout << "You successfully escaped!" << endl;
                cout << "Total moves: " << totalMoves << endl;
                return 0;
            }
        }
        else if (oldValue == 5){
            lose = true;
            cout << "Elon caught you!" << endl;
            cout << "Total moves: " << totalMoves << endl;
            return 0;
        }
        if (awakeElon == false){
            if ((abs(x - ex) <= 1) && (abs(y - ey) <= 1)){
                awakeElon = true;
                cout << "Elon is now awake!" << endl;
            }
        }
        else if (awakeElon == true){
            eMove = (rand() % 4);
            if (eMove == 0){
                arr[ex][ey] = 0;
                arr[ex][ey + 1] = 5;
                ey = ey + 1;
            }
            else if (eMove == 1){
                arr[ex][ey] = 0;
                arr[ex][ey - 1] = 5;
                ey = ey - 1;
            }
            else if (eMove == 2){
                arr[ex][ey] = 0;
                arr[ex + 1][ey] = 5;
                ex = ex + 1;
            }
            else if (eMove == 3){
                arr[ex][ey] = 0;
                arr[ex - 1][ey] = 5;
                ex = ex - 1;
            }
            if ((abs(x - ex) <= 1) && (abs(y - ey) <= 1)){
                if (elonCaught == 0){
                    cout << "You managed to escape Elon!" << endl;
                    elonCaught = 1;
                }
                else{
                    lose = true;
                    cout << "Elon caught you!" << endl;
                    cout << "Total moves: " << totalMoves << endl;
                    return 0;
                }
            }
                
        }
        totalMoves += 1;
    }
    return 0;
}
=======
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;


void initBoard(int (&arr)[7][7]){
    srand (time(NULL));
    int i = 0;
    int j = 0;
    for (i = 0; i < 7; ++i){
        for (j = 0; j < 7; ++j){
            arr[i][j] = 0;
        }
    }
    int x;
    int y;
    for (int k = 1; k < 6; k++){
        x = (rand() % 7);
        y = (rand() % 7);
        while (arr[x][y] != 0){
            x = (rand() % 7);
            y = (rand() % 7);
        }
        arr[x][y] = k;
    }
    cout << "1 = Player | 2 = Roadtser | 3 = Juge | 4 = Pinto | 5 = Elon Musk!" << endl;
}

void dispBoard(int arr[7][7], int x, int y){
    int i = 0;
    int j = 0;
    for (i = 0; i < 7; ++i){
        cout << "| ";
        for (j = 0; j < 7; ++j){
            if ((abs(x - i) <= 2) && (abs(y - j) <= 2))
                cout << arr[i][j] << " ";
            else
                cout << "0" << " ";
        }
        cout << "|";
        cout << endl;
    }
}

int main()
{
    int arr[7][7];
    initBoard(arr);
    int i = 0;
    int j = 0;
    int x = 0;
    int y = 0;
    int ex = 0;
    int ey = 0;
    int oldx;
    int oldy;
    int totalMoves = 1;
    for (i = 0; i < 7; ++i){
        for (j = 0; j < 7; ++j){
            if (arr[i][j] == 1){
                x = i;
                y = j;
            }
        }
    }
    for (i = 0; i < 7; ++i){
        for (j = 0; j < 7; ++j){
            if (arr[i][j] == 5){
                ex = i;
                ey = j;
            }
        }
    }
    bool win = false;
    bool lose = false;
    bool awakeElon = false;
    int elonCaught = 0;
    char move;
    int oldValue;
    int eMove;
    while ((win == false) && (lose == false)){
        dispBoard(arr,x,y);
        cin >> move;
        if (move == 'w'){
            oldValue = arr[x - 1][y];
            arr[x][y] = 0;
            arr[x - 1][y] = 1;
            x = x - 1;
        }
        else if (move == 'a'){
            oldValue = arr[x][y - 1];
            arr[x][y] = 0;
            arr[x][y - 1] = 1;
            y = y - 1;
        }
        else if (move == 's'){
            oldValue = arr[x + 1][y];
            arr[x][y] = 0;
            arr[x + 1][y] = 1;
            x = x + 1;
        }
        else if (move == 'd'){
            oldValue = arr[x][y + 1];
            arr[x][y] = 0;
            arr[x][y + 1] = 1;
            y = y + 1;
        }
        else if (move == 'c'){
            lose = true;
            cout << "Game Over" << endl;
            cout << "Total moves: " << totalMoves << endl;
        }
        else{
            cout << "Please enter valid key (WASD to move | C to quit)" << endl;
        }
        if (oldValue == 2){
            win = true;
            cout << "You successfully escaped in the Roadster!" << endl;
            cout << "Total moves: " << totalMoves << endl;
            return 0;
        }
        else if((oldValue == 3) || (oldValue == 4)){
            if (awakeElon == true){
                lose = true;
                cout << "Elon caught you!" << endl;
                cout << "Total moves: " << totalMoves << endl;
                return 0;
            }
            else{
                win = true;
                cout << "You successfully escaped!" << endl;
                cout << "Total moves: " << totalMoves << endl;
                return 0;
            }
        }
        else if (oldValue == 5){
            lose = true;
            cout << "Elon caught you!" << endl;
            cout << "Total moves: " << totalMoves << endl;
            return 0;
        }
        if (awakeElon == false){
            if ((abs(x - ex) <= 1) && (abs(y - ey) <= 1)){
                awakeElon = true;
                cout << "Elon is now awake!" << endl;
            }
        }
        else if (awakeElon == true){
            eMove = (rand() % 4);
            if (eMove == 0){
                arr[ex][ey] = 0;
                arr[ex][ey + 1] = 5;
                ey = ey + 1;
            }
            else if (eMove == 1){
                arr[ex][ey] = 0;
                arr[ex][ey - 1] = 5;
                ey = ey - 1;
            }
            else if (eMove == 2){
                arr[ex][ey] = 0;
                arr[ex + 1][ey] = 5;
                ex = ex + 1;
            }
            else if (eMove == 3){
                arr[ex][ey] = 0;
                arr[ex - 1][ey] = 5;
                ex = ex - 1;
            }
            if ((abs(x - ex) <= 1) && (abs(y - ey) <= 1)){
                if (elonCaught == 0){
                    cout << "You managed to escape Elon!" << endl;
                    elonCaught = 1;
                }
                else{
                    lose = true;
                    cout << "Elon caught you!" << endl;
                    cout << "Total moves: " << totalMoves << endl;
                    return 0;
                }
            }
                
        }
        totalMoves += 1;
    }
    return 0;
}
>>>>>>> 18d3673e13e740eac16ec121a03c3b714e03dc9d
