#include<bits/stdc++.h>
using namespace std;

typedef pair<int, vector<vector<int>>> pvi;


// Checking if board is in a safe state
bool isSafe(vector<vector<int>> v, int row, int col){
    int i, j;
    for (i = 0; i < col; i++)
        if (v[row][i])
            return false;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (v[i][j])
            return false;
    for (i = row, j = col; j >= 0 && i < 8; i++, j--)
        if (v[i][j])
            return false;
    return true;
}

// Print the board
void print_board(vector<vector<int>> v){
  for(int i = 0; i < 8;i++){
    for(int j = 0;j < 8;j++){
      cout << v[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}

int main(){
    priority_queue <pvi, vector<pvi>, greater<pvi>> q;
    q.push(make_pair(0, vector<vector <int>>(8, vector<int>(8,0))));
    int count = 0;
    int sol = 0;
    while(!q.empty()){
        vector< vector<int>> v = q.top().second;
        //print_board(v);
        int already_filled = q.top().first;
        if(already_filled == 8){
            cout << "Sol " << ++sol << "\n\n";
            print_board(v);
        }
        q.pop();
        for(int i = 0; i < 8; i++){
            if(isSafe(v, i, already_filled)){
                v[i][already_filled] = 1;
                q.push(make_pair(already_filled+1, v));
            }
            v[i][already_filled] = 0;
        }
    }
    return 0;
}