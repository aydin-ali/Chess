#include "textDisplay.h"
#include <iostream>
using namespace std;

TextDisplay::TextDisplay(){
    printedBoard.resize(64, vector<char>(64, ' '));
}

void TextDisplay::notify(vector<vector<Piece*>> &b){
    for(int i = 7; i >=0; --i){
        cout << i + 1 << " ";
        for(int j = 0; j < printedBoard.size(); ++j){
            cout << printedBoard[j][i];
        }
        cout << " ";
    }
}
