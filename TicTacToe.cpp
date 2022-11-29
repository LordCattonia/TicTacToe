#include <iostream>
#include <bits/this_thread_sleep.h>
#include <ctype.h>
using namespace std;
char space[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row;
int column;
bool isCircle = { false };
bool gameOver = { false };

bool isWon() {
    for(int i=0; i<3; i++) {
        if(space[i][0]==space[i][1]&&space[i][0]==space[i][2]||space[0][i]==space[1][i]&&space[0][i]==space[2][1]) {
            return true;
        }
    }
    if(space[0][0]==space[1][1]&&space[1][1]==space[2][2]||space[2][0]==space[1][1]&&space[1][1]==space[0][2]) {
        return true;
    }

    return false;
}

void printNextMove() {
    string board = "      |     |\n"
    +string("   ")+space[0][0]+"  |  "+space[0][1]+"  |  "+space[0][2]+'\n'
    +" _____|_____|_____\n"
    +"      |     |\n"
    +string("   ")+space[1][0]+"  |  "+space[1][1]+"  |  "+space[1][2]+'\n'
    +" _____|_____|_____\n"
    +"      |     |\n"
    +string("   ")+space[2][0]+"  |  "+space[2][1]+"  |  "+space[2][2]+'\n'
    +"      |     |\n";
    cout<<board;
}

int checkValid() {
    if (isdigit(space[column][row])) return 0;
    else {
        return 1;
    }
}

void renderNextMove() {
    if(!isCircle) {
        system("CLS");
        cout<<std::flush;
        space[column][row] = 'X';
        printNextMove();
        if(isWon()) {
            cout<<"\n\nPlayer 1 wins"; 
            gameOver = true;
        }
    } else {
        space[column][row] = 'O';
        system("CLS");
        cout<<std::flush;
        printNextMove();
        if(isWon()) {
            cout<<"\n\nPlayer 2 wins";
            gameOver = true;
        }
    }
    isCircle = !isCircle;
}

int convertToGrid(int move) {
    if (move==1){
        row=0;
        column=0;
    } if (move==2){
        row=1;
        column=0;
    } if (move==3){
        row=2;
        column=0;
    } if (move==4){
        row=0;
        column=1;
    } if (move==5){
        row=1;
        column=1;
    } if (move==6){
        row=2;
        column=1;
    } if (move==7){
        row=0;
        column=2;
    } if (move==8){
        row=1;
        column=2;
    } if (move==9){
        row=2;
        column=2;
    } else if (move<1||move>9) {
        cout<<"\n\nInvalid move!!!"<<endl;
        std::this_thread::sleep_for(2s);
        printf("\33[2K\r");
        return 1;
    }
    if (checkValid()) {
        cout<<"\n\nInvalid move!!!"<<endl;
        std::this_thread::sleep_for(2s);
        printf("\33[2K\r");
        return 1;
    } else {
        return 0;
    }
}

int main() {
    system("cls");
    printNextMove();
    while(!gameOver) {
        int move;
        cout<<"Player "<<isCircle+1<<" move: ";
        cin>>move;
        int res = convertToGrid(move);
        while(res) {
            cout<<"Player "<<isCircle+1<<" move: ";
            cin>>move;
            res = convertToGrid(move);
        }
        renderNextMove();
    }
    return 0;
}