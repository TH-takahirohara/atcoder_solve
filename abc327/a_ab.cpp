#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)
// 桁数指定： cout << fixed << setprecision(10)

int main() {
  int N;
  string S;
  cin >> N >> S;

  rep(i,0,N-1) {
    if ((S.at(i) == 'a' && S.at(i+1) == 'b') || (S.at(i) == 'b' && S.at(i+1) == 'a')) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}
