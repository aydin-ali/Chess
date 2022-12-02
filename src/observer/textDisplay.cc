#include "textDisplay.h"
#include <iostream>
#include <cctype>
using namespace std;

TextDisplay::TextDisplay(){
    printedBoard.resize(64, vector<char>(64, ' '));
}

void TextDisplay::notify(vector<vector<Piece*>> &b){
    cout << endl;
    for(int row = 0; row < 8; ++row){
        for(int col = 0; col < 8; ++col){
            if(b[row][col] == nullptr){
                if((row + col) % 2 == 0){
                    printedBoard[row][col] = '-';
                } else {
                    printedBoard[row][col] = ' ';
                }
            } else {
                if(b[row][col]->getColour() == "black"){
                    printedBoard[row][col] = b[row][col]->getType();
                } else {
                    printedBoard[row][col] = toupper(b[row][col]->getType()); 
                }
            }
        }
    }
    for(int row = 0; row < 8; ++row){
        cout << 8 - row << " ";
        for(size_t col = 0; col < printedBoard.size(); ++col){
            cout << printedBoard[row][col];
        }
        cout << endl;
    }
    cout << endl;
    cout << "  abcdefgh" << endl;
    cout << endl;
}
