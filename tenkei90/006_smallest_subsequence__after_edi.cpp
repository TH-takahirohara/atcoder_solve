#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  int N,K;
  cin >> N >> K;
  
  string S;
  cin >> S;
  
  vector<vector<int>> C(26, vector<int>(N, -1));
    
  for (int i=0; i < 26; i++) {
    for (int j=N-1; j>=0; j--) {
      char ch = 'a' + i;
      if (S.at(j) == ch) {
        C.at(i).at(j) = j;
      } else if (j < N-1) {
        C.at(i).at(j) = C.at(i).at(j+1);
      }
    }
  }
  
  int ind = 0;
  string ans = "";
  while (ans.size() < K) {
    rep(i,0,26) {
      if (C.at(i).at(ind) != -1 && !(C.at(i).at(ind) > N-K+ans.size())) {
        ind = C.at(i).at(ind) + 1;
        char tmp = 'a' + i;
        ans += tmp;
        break;
      }
    }
  }
  
  cout << ans;
}
