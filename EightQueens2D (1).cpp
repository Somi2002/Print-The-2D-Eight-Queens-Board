#include <iostream>
using namespace std;

int main(){
  int q[8][8] = {0};
  int r = 0, c = 0;
  q[r][c] = 1; 

  nextCol:
    c++;
    if (c == 8) goto print;
    r = -1; 

  nextRow:
    r++;
    if (r == 8) goto backtrack;
    // row test
    for (int i = 0; i < c; i++){
      if (q[r][i] == 1) goto nextRow; 
    }

    // up diagonal test 
    for (int i = 1; ((r-i)>=0 && (c-i)>=0); i++){ 
      if (q[r-i][c-i] == 1) goto nextRow;
    }

    // down diagonal test
    for (int i = 1; ((r+i)<8 && (c-i)>=0); i++){
      if (q[r+i][c-i] == 1) goto nextRow;
    }

    q[r][c] = 1;
    goto nextCol;

  backtrack:
    c--;
    if (c == -1){
      return 0;
    }
    r = 0;
    while (q[r][c] != 1){
      r++;
    }

    q[r][c] = 0;
    goto nextRow;

  print:
    static int solutionNum = 0;
    cout << "Solution #" << ++solutionNum << ": " << endl;
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) 
            cout << q[i][j]; 
            cout << endl; 
    }
    goto backtrack;
}