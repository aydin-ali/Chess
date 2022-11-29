#include "textDisplay.h"
#include <iostream>
#include <cctype>
using namespace std;

TextDisplay::TextDisplay(){
    printedBoard.resize(64, vector<char>(64, ' '));
}

void TextDisplay::notify(vector<vector<Piece*>> &b){
    for(int row = 0; row < 8; ++row){
        for(int col = 0; col < 8; ++col){
            if(b[row][col] != nullptr){
                if(b[row][col]->getColour() == "black"){
                    printedBoard[row][col] = b[row][col]->getType();
                } else {
                    printedBoard[row][col] = toupper(b[row][col]->getType()); 
                }
            }
        }
    }
    for(int i = 7; i >=0; --i){
        cout << i + 1 << " ";
        for(int j = 0; j < printedBoard.size(); ++j){
            cout << printedBoard[j][i];
        }
        cout << endl;
    }
    cout << "  abcdefgh" << endl;
}
