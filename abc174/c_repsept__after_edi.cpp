#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

typedef vector<vector<int>> Graph;
double PI = 3.14159265359;

int main() {
  int K;
  cin >> K;
  
  int amari = 0;
  rep(i,1,K+1) {
    int tmp = (amari * 10 + 7) % K;
    if (tmp == 0) {
      cout << i << endl;
      return 0;
    } else {
      amari = tmp;
    }
  }
  
  cout << -1 << endl;
}

