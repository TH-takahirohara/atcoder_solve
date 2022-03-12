#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  int V, A, B, C;
  cin >> V >> A >> B >> C;
  
  string cur = "F";
  while (V > 0) {
    if (cur == "F") {
      V = V-A;
      if (V < 0) break;
      cur = "M";
    }
    if (cur == "M") {
      V = V-B;
      if (V<0) break;
      cur = "T";
    }
    if (cur == "T") {
      V = V-C;
      if (V<0) break;
      cur = "F";
    }
  }
  
  cout << cur << endl;
}
