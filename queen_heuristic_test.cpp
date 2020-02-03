#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

typedef pair<int, vector<vector<int>>> pvi;

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
  vector<vector<int>> vec = q.top().second;
  vector<vector<int>> sol;
  int heuristic = q.top().first;
  cout << heuristic;
  if(heuristic==0) {sol = vec; print_board(sol);}
  while(heuristic!=0&&!q.empty()){
    vector<vector<int>> vec1 = vec;
    for(int i = 0 ; i < 8; i++){
      vec1[i] = vector<int> (8,0);
      for(int j = 0; j < 8;j++){
        vec1[i][j] = 1;
        cout << i << j << "\n";
        if(heuristic_function(vec1)<heuristic){
          q.push(make_pair(heuristic_function(vec1), vec1));
          heuristic = heuristic_function(vec1);
          if(heuristic == 0){
            sol = vec1;
            print_board(sol);
            return;
          }
        }
        vec1[i][j] = 0;
      }
      vec1 = vec;
    }
    vec = q.top().second;
    q.pop();
  }
}
int main(){
  srand(time(0));
  priority_queue <pvi, vector<pvi>, greater<pvi>> q;
  for(int i = 0; i< 50000;i++){
    vector<vector<int>> vec(8, vector<int>(8,0));
    generate_initial(vec);
    q.push(make_pair(heuristic_function(vec), vec));
  }
  generate_next(q);

  return 0;
}
