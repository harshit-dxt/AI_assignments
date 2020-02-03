#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

typedef pair<int, vector<vector<int>>> pvi;

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

int heuristic_function(vector<vector<int>> v){
  int heuristic = 0;
  vector<pair<int, int>> one_location;
  for(int i = 0; i < 8;i++){
    for(int j = 0; j < 8;j++){
      if(v[i][j]){
        one_location.push_back(make_pair(i,j));
      }
    }
  }
  for(int i = 0; i < 8;i++){
    for(int j = i+1;j < 8;j++){
      if(one_location[i].first == one_location[j].first || one_location[j].second == one_location[i].second) heuristic++;
      else if(abs(one_location[i].first-one_location[j].first) == abs(one_location[i].second - one_location[j].second)) heuristic++;
    }
  }
  return heuristic;
}

void generate_initial(vector<vector<int>> &v){
  long b;
  int filled = 0;
  while(filled!=8){
    b = rand()%8;
    if(v[filled][b]==0){
      v[filled][b] = 1;
      filled++;
    }
  }
}
void print_board(vector<vector<int>> v){
  for(int i = 0; i < 8;i++){
    for(int j = 0;j < 8;j++){
      cout << v[i][j] ;
    }
    cout << "\n";
  }
  cout << "\n";
}
void generate_next(priority_queue<pvi, vector<pvi>, greater<pvi>> &q){
      vector< vector<int>> vec = q.top().second;
      while(heuristic_function(vec)!=0){
        vec = vector<vector<int>>(8, vector<int>(8,0));
        q.pop();
        generate_initial(vec);
        q.push(make_pair(heuristic_function(vec), vec));
      }
}
int main(){
  int heuristic = 0;
  vector<vector<int>> vec(8, vector<int>(8,0));
  srand(time(0));
  generate_initial(vec);
  print_board(vec);
  priority_queue <pvi, vector<pvi>, greater<pvi>> q;
  q.push(make_pair(heuristic_function(vec), vec));
  generate_next(q);
  print_board(q.top().second);
  return 0;
}
