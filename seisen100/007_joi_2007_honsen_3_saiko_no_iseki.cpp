#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int menseki(int dx, int dy) {
  return dx*dx + dy*dy;
}

int main() {
  int N;
  cin >> N;
  vector<vector<bool>> pils(11000, vector<bool>(11000, false));
  
  vector<int> X(N);
  vector<int> Y(N);
  
  for (int i=0; i<N; i++) {
    int tmpx, tmpy;
    cin >> tmpx >> tmpy;
    X.at(i) = tmpx;
    Y.at(i) = tmpy;
    pils.at(tmpy).at(tmpx) = true;
  }
    
  int output = 0;
  for (int i=0; i<N; i++) {
    for (int j=i+1; j<N; j++) {
      int x1 = X.at(i); int y1 = Y.at(i);
      int x2 = X.at(j); int y2 = Y.at(j);
      
      int dx = X.at(j) - X.at(i);
      int dy = Y.at(j) - Y.at(i);
      if (y1-dx >= 0 && x1+dy >= 0 && y2-dx >= 0 && x2+dy >=0) {
        if (pils.at(y1 - dx).at(x1 + dy) && pils.at(y2 - dx).at(x2 + dy)) output = max(output, menseki(dx, dy));
      }
      
      if (y1+dx >= 0 && x1-dy >= 0 && y2+dx >= 0 && x2-dy >=0) {
        if (pils.at(y1 + dx).at(x1 - dy) && pils.at(y2 + dx).at(x2 - dy)) output = max(output, menseki(dx, dy));
      }      
    }
  }
  
  cout << output << endl;
}
