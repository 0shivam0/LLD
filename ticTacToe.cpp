#include <bits/stdc++.h>
using namespace std;

enum pieces{
  Empty,
  X,
  O
};

class playingPieces{
private:
  pieces type;
public:
  playingPieces(pieces type){
    this->type = type;
  }

  pieces getType(){
    return type;
  }
};

class cross: public playingPieces{
public:
  cross(): playingPieces(X) {}
};

class circle: public playingPieces{
public:
  circle(): playingPieces(O) {}
};


class players{
private:
  string name;
  playingPieces playingPiece;
public:
  players(string name, playingPieces playingPiece) : name(name), playingPiece(playingPiece) {}
  void setName(string name){
    this->name = name;
  }
  void getName(){
    cout<<name;
  }
  void setPiece(playingPieces playingPiece){
    this->playingPiece = playingPiece;
  }
  playingPieces getPlayingPiece(){
    return playingPiece;
  }
};


class board{
private:
  int size;
  vector<vector<pieces>> grid;
public:
  board(int size){
    this->size = size;
    vector<vector<pieces>> temp(size, vector<pieces>(size, Empty));
    grid = temp;
  }

  void showboard(){
     char symbols[] = {'-', 'X', 'O'};
    for(auto it: grid){
      for(auto it2: it){
        cout << symbols[it2] << " ";
      }
      cout<<"\n";
    }
  }
  bool verfiy(int row, int col){
    if(grid[row][col] == 0 && row >= 0 && row < size && col >= 0 && col < size){
      return true;
    }
    else{
      return false;
    }
  }
  void insert(int row, int col, pieces symbol){
    grid[row][col] = symbol;
  }
  bool checkWin(int row, int col, pieces symbol){
    bool rowWin = true;
    for (int j = 0; j < size; j++) {
      if (grid[row][j] != symbol) {
        rowWin = false;
        break;
      }
    }

    bool colWin = true;
    for (int i = 0; i < size; i++) {
      if (grid[i][col] != symbol) {
        colWin = false;
        break;
      }
    }
    bool mainDiagonalWin = true;
    if (row == col) {
      for (int i = 0; i < size; i++) {
        if (grid[i][i] != symbol) {
          mainDiagonalWin = false;
          break;
        }
      }
    } else {
      mainDiagonalWin = false;
    }
    bool antiDiagonalWin = true;
    if (row + col == size - 1) {
      for (int i = 0; i < size; i++) {
        if (grid[i][size - 1 - i] != symbol) {
          antiDiagonalWin = false;
          break;
        }
      }
    } else {
      antiDiagonalWin = false; 
    }
    return rowWin || colWin || mainDiagonalWin || antiDiagonalWin;
  }

};
class TicTacToe{
private:
  board gameBoard;
  queue<players> users;

public:

  TicTacToe(string n1, string n2):gameBoard(3){
    cross crossPiece;
    circle circlePiece;
    players p1(n1, crossPiece);
    players p2(n2, circlePiece);
    users.push(p1);
    users.push(p2);
  }
  
  void startGame(){
    bool gameEnd = true;
    int moves = 0;
    gameBoard.showboard();
    cout<<"\n";
    while(gameEnd){
      players currPlayer = users.front();
      cout<<"enter coordinates ";
      currPlayer.getName();
      cout<<"\n";
      int row, col;
      cin>>row>>col;
      if(gameBoard.verfiy(row, col)){
        gameBoard.insert(row, col, currPlayer.getPlayingPiece().getType());
        moves++;
        gameBoard.showboard();
        cout<<"\n";
        if(gameBoard.checkWin(row, col, currPlayer.getPlayingPiece().getType())){
          gameEnd = false;
          cout<<"Wins ";
          currPlayer.getName();
          continue;
        }
        else{
          users.pop();
          users.push(currPlayer);
        }
        if(moves == 9){
          gameEnd = false;
          cout<<"Tie"<<"\n";
          continue;
        }
      }
      else{
        cout<<"Wrong coordinates enter again "<<"\n";
        continue;
      }
    }
  }
};

int main(){
    TicTacToe game1("", "");
    game1.startGame();
 return 0;
}

