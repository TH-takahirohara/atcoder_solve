#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<ll>> A(N, vector<ll>(M, 0LL));
  
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      cin >> A.at(i).at(j);
    }
  }
  
  ll max_score = 0;
  for (int i=0; i<M; i++) {
    for (int j=i+1; j<M; j++) {
      ll tmp = 0;
      for (int k=0; k<N; k++) {
        if (A.at(k).at(i) >= A.at(k).at(j)) tmp += A.at(k).at(i);
        else tmp += A.at(k).at(j);
      }
      
      max_score = max(max_score, tmp);
    }
  }
  
  cout << max_score << endl;
}

