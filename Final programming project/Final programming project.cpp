#include <iostream>
#include <random>
#include <windows.h>
#include <vector>
using namespace std;
int restart = 0; 
int p = 1;
char board[3][3] = { '1','2','3','4','5','6','7','8','9' };
int row, column;
char sympol1, sympol2;
vector <int> taken;
HANDLE console_color;
int computer_choice() {
    srand((unsigned)time(NULL));
    int random = 1 + (rand() % 9);
    return random;
}
void play_again(){
    SetConsoleTextAttribute(console_color, 15);
    cout << "\t\t\t\t\tDo you want to play again ? (y/n) ";
    char player_response;
    cin >> player_response;
    if ((player_response == 'Y') || (player_response == 'y'))
    {
        ++restart;
    }
    else if ((player_response == 'n') || (player_response == 'N'))
    {
        cout << "\t\t\t\tThank you for playing :)";
        restart = 0;
    }
    else
    {
        cout << "\t\t\t\tInvalid response :(\n\t\t\t\tPlease enter your response again:";
        play_again();
    }
}
void board_shape() {
    cout << endl << endl;
    cout << "\t\t\t\t\t\t     |     |     \n";
    cout << "\t\t\t\t\t\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << " \n";
    cout << "\t\t\t\t\t\t_____|_____|_____\n";
    cout << "\t\t\t\t\t\t     |     |     \n";
    cout << "\t\t\t\t\t\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << " \n";
    cout << "\t\t\t\t\t\t_____|_____|_____\n";
    cout << "\t\t\t\t\t\t     |     |     \n";
    cout << "\t\t\t\t\t\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << " \n";
    cout << "\t\t\t\t\t\t     |     |     \n";
}
int player = 1;
void player_vs_computer() {
    int pos;
    if (player == 1) {
        pos = computer_choice();
        cout << "\t\t\t\tWaiting...\n";
        int i = 0;
        for (i; i < taken.size(); ++i) {
            if (pos == taken[i]) {
                pos = computer_choice();
                i = 0;}
            else continue;}
        switch (pos) {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        }
    }
    else if (player == 2) {
        cout << "\n\t\t\t\t\tPlayer - 2 [" << sympol1 << "] turn : ";
        cin >> pos;
        taken.push_back(pos);
        switch (pos) {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default:
            cout << "\t\t\t\tInvalid Move";
        }
    }
    if (player == 2 && board[row][column] != 'x' && board[row][column] != 'o') {

        board[row][column] = sympol1;
        --player;
    }
    else if (player == 1 && board[row][column] != 'x' && board[row][column] != 'o')
    {
        board[row][column] = sympol2;
        ++player;
        taken.push_back(pos);
    }
    else if (player == 2) {

        cout << "\n\t\t\t\tPlease choose another!!\n";
    }
    else {}
}
void party() {
    int pos;
    if (player == 1) {
        cout << "\t\t\t\tWaiting...\n";
        if (board[1][0] == sympol2 && board[2][0] == sympol2) {
                 pos= 1;
           } else if (board[1][1] == sympol2 && board[2][2] == sympol2) {
                 pos = 1;
           } else if (board[0][1] == sympol2 && board[0][2] == sympol2) {
                 pos = 1;
           } else if (board[1][1] == sympol2 && board[2][1] == sympol2) {
                 pos = 2;
           } else if (board[0][0] == sympol2 && board[0][2] == sympol2) {
                 pos = 2;
           } else if (board[0][0] == sympol2 && board[0][1] == sympol2) {
                 pos = 3;
           } else if (board[1][1] == sympol2 && board[2][0] == sympol2) {
                 pos = 3;
           } else if (board[1][2] == sympol2 && board[2][2] == sympol2) {
                 pos = 3;
           } else if (board[1][1] == sympol2 && board[1][2] == sympol2) {
                 pos = 4;
           } else if (board[0][0] == sympol2 && board[2][0] == sympol2) {
                 pos = 4;
           } else if (board[0][0] == sympol2 && board[2][2] == sympol2) {
                 pos = 5;
           } else if (board[0][1] == sympol2 && board[2][1] == sympol2) {
                 pos = 5;
           } else if (board[0][2] == sympol2 && board[2][0] == sympol2 ) {
                 pos = 5;
           } else if (board[1][0] == sympol2 && board[1][2] == sympol2) {
                 pos = 5;
           } else if (board[0][2] == sympol2 && board[2][2] == sympol2) {
                 pos = 6;
           } else if (board[1][0] == sympol2  && board[1][1] == sympol2) {
                 pos = 6;
           } else if (board[0][2] == sympol2 && board[1][1] == sympol2) {
                 pos = 7;
           } else if (board[0][0] == sympol2 && board[1][0] == sympol2) {
                 pos = 7;
           } else if (board[2][1] == sympol2 && board[2][2] == sympol2) {
                 pos = 7;
           } else if (board[2][0] == sympol2 && board[2][2] == sympol2) {
                 pos = 8;
           } else if (board[0][1] == sympol2 && board[1][1] == sympol2) {
                 pos = 8;
           } else if (board[0][2] == sympol2 && board[1][2] == sympol2) {
                 pos = 9;
           } else if (board[2][0] == sympol2 && board[2][1] == sympol2) {
                 pos = 9;
           } else if (board[0][0] == sympol2 && board[1][1] == sympol2) {
                 pos = 9;
           }
          else 
              pos =computer_choice() ;
        int i = 0;
        for (i; i < taken.size(); ++i) {
            if (pos == taken[i]) {
                pos = computer_choice();
                i = 0;
            }
            else
                continue;
        }
        switch (pos) {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        }
    }
    else if (player == 2) {
        cout << "\n\t\t\t\t\tPlayer - 2 [" << sympol1 << "] turn : ";
        cin >> pos;
        taken.push_back(pos);
        switch (pos) {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default:
            cout << "\t\t\t\tInvalid Move";
        }
    }
    console_color = GetStdHandle(STD_OUTPUT_HANDLE);
      SetConsoleTextAttribute(console_color, p);
    p++;
    if (p == 15)
        p = 1;
    if (player == 2 && board[row][column] != 'x' && board[row][column] != 'o') {

        board[row][column] = sympol1;
        --player;
    }
    else if (player == 1 && board[row][column] != 'x' && board[row][column] != 'o')
    {
        board[row][column] = sympol2;
        ++player;
        taken.push_back(pos);
    }
    else if (player == 2) {

        cout << "\n\t\t\t\tPlease choose another!!\n";
    }
    else{}
}
void player_vs_player() {
    int pos;
    if (player == 1) {
        cout << "\n\t\t\t\t\tPlayer - 1 [x] turn : ";
    }
    else if (player == 2) {
        cout << "\n\t\t\t\t\tPlayer - 2 [o] turn : ";
    }
    cin >> pos;


    switch (pos) {
    case 1: row = 0; column = 0; break;
    case 2: row = 0; column = 1; break;
    case 3: row = 0; column = 2; break;
    case 4: row = 1; column = 0; break;
    case 5: row = 1; column = 1; break;
    case 6: row = 1; column = 2; break;
    case 7: row = 2; column = 0; break;
    case 8: row = 2; column = 1; break;
    case 9: row = 2; column = 2; break;
    default:
        cout << "\t\t\t\tInvalid Move";
        player_vs_player();
    }
    if (player == 1 && board[row][column] != 'o' && board[row][column] != 'x') {

        board[row][column] = 'x';
        ++player;
    }
    else if (player == 2 && board[row][column] != 'x' && board[row][column] != 'o') {

        board[row][column] = 'o';
        --player;
    }
    else {

        cout << "\n\t\t\t\tPlease choose another!!\n";
    }
}
char winner() {
    int cnt = 0;
    for (int i = 0; i < 3; i++){
        int xcnt = 0, ocnt = 0;
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'x' && board[i][j] != 'o')
                cnt++;
            if (board[i][j] == 'x')
                xcnt++;
            if (board[i][j] == 'o')
                ocnt++;
            if (xcnt == 3)
                return 'x';
            if (ocnt == 3)
                return 'o';}}
    for (int i = 0; i < 3; i++){
        int xcnt = 0, ocnt = 0;
        for (int j = 0; j < 3; j++)

        {
            if (board[j][i] == 'x')
                xcnt++;
            if (board[j][i] == 'o')
                ocnt++;
            if (xcnt == 3)
                return 'x';
            if (ocnt == 3)
                return 'o';
        }}
    if (board[0][0] == 'x' && board[1][1] == 'x' && board[2][2] == 'x')
        return 'x';
    if (board[0][2] == 'x' && board[1][1] == 'x' && board[2][0] == 'x')
        return 'x';
    if (board[0][0] == 'o' && board[1][1] == 'o' && board[2][2] == 'o')
        return 'o';
    if (board[0][2] == 'o' && board[1][1] == 'o' && board[2][0] == 'o')
        return 'o';
    if (cnt == 0)
        return 'd';
    return 'w';
}
void player_choice2() {
    bool f = 1;
    while (f) {
        cout <<endl<< "\t\t\t\t\tPlayer, choose your symbol: ";
        cin >> sympol1; cout << endl;
        if (sympol1 != 'x' && sympol1 != 'o' && sympol1 != 'X' && sympol1 != 'O')
        {
            cout << "\t\t\t\tInvalid choice :|" << endl;
        }
        else {
            f = 0;
            if (sympol1 == 'x' || sympol1 == 'X')
            {
                sympol1 = 'x';
                sympol2 = 'o';
                player = 2;
            }
            else if (sympol1=='o'|| sympol1=='O'){sympol1 = 'o';
                sympol2 = 'x';
                player = 1;
            }
        }
    }
}
int main()
{do
    {       if (restart != 0){
            system("cls");
            board[0][0] = '1'; board[0][1] = '2'; board[0][2] = '3'; board[1][0] = '4'; board[1][1] = '5'; board[1][2] = '6'; board[2][0] = '7'; board[2][1] = '8'; board[2][2] = '9';
            taken.clear();
            player = 1;
            p = 1;}
        char mode;
        cout << endl; cout << endl; cout << endl <<endl <<endl;
        cout << "\t\t\t\t\t\t     Tic_Tac_Toe" << endl << endl;
        cout << "\t\t\t\t\t\t1. Computer vs Player\n" << "\t\t\t\t\t\t2. Player vs Player\n" << "\t\t\t\t\t\t3. Party Mode!!!\n" <<endl;
        cout << "\t\t\t\t\t\tSelect game mode: ";
        cin >> mode;cout << endl;cout << endl;
        if (mode == '1')
        { system("cls");
            player_choice2();
            cout << "\t\t\t\tCOMPUTER [" << sympol2 << "]\t PLAYER - [" << sympol1 << "]\n";
            while (winner() == 'w') {
                board_shape();
                player_vs_computer();
                system("cls");
            }board_shape();
            if (winner() == 'd')
                cout << "\t\t\t\tGame is draw" << endl;
            if (winner() == sympol2)
                cout << "\t\t\t\tThe computer has won the game\n. Better luck next time :(" << endl;
            if (winner() == sympol1)
                cout << "\t\t\t\tCongrats, You won." << endl;
            play_again();}
        else if (mode == '3')
        {   system("cls");
            player_choice2();
            cout << "\t\t\t\t\tComputer - [" << sympol2 << "]\t PLAYER - [" << sympol1 << "]\n";
            while (winner() == 'w') {
                board_shape();
                party();
                system("cls");
            }board_shape();
            if (winner() == 'd')
                cout << "\t\t\t\tGame is draw.Try again :0" << endl;
            if (winner() == sympol2)
                cout << "\t\t\t\t\tThe computer has won the game" << endl;
            SetConsoleTextAttribute(console_color, 13);
            if (winner() == sympol1)
                cout << "\t\t\t\t\tCongrats, You won :)" << endl;
            play_again();}
        else if (mode=='2'){
            system("cls");
            cout << "\t\t\t\tPLAYER - 1 [x]\t PLAYER - 2 [o]\n";
            while (winner() == 'w') {
                board_shape();
                player_vs_player();
                system("cls");
            }board_shape();
            if (winner() == 'd')
                cout << "\t\t\t\tGame is draw" <<endl;
            if (winner() == 'x' || winner() == 'o')
                cout << "\t\t\t\t\tThe winner of the game is player [" << winner() << "]" << endl << "\t\t\t\t\tWell done :)\n";
            play_again();}
        else
        { cout << "\t\t\t\t\tInvalid choice.\n";
            restart = 1;}
    } while (restart != 0);}