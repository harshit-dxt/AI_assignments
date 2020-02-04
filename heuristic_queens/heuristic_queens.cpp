#include <bits/stdc++.h>
using namespace std;

typedef pair<int, vector<vector<int>>> pvi;



// Count conflict for a queen already placed
int countConflict(vector<vector<int>> v, int row, int col){
    int count = 0;
    int i, j;
    for (i = 0; i < col; i++)
        if (v[row][i])
            count++;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (v[i][j])
            count++;
    for (i = row, j = col; j >= 0 && i < 8; i++, j--)
        if (v[i][j])
            count++;
    return count;
}

int countQueens(vector<vector<int>> v){
    int count = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(v[i][j]) {
                count++;
            }
        }
    }
    return count;
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
    while(!q.empty()){
        vector< vector<int>> v = q.top().second;
        int conflict = q.top().first;
        if(conflict==8&&countQueens(v)==8){
            cout << "Solution Found!!!\n";
            print_board(v);
            break;
        }
        q.pop();
        int count = countQueens(v);
        for(int i = 0; i < 8; i++){
            int isConflict = countConflict(v,i,count);
            v[i][count] = 1;
            q.push(make_pair(1+conflict+isConflict, v));
            v[i][count] = 0;
            
        }   
    }
    return 0;
}
