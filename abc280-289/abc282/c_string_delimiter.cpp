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
  cin >> N;
  string S;
  cin >> S;

  bool kukurare = false;
  rep(i,0,N) {
    if (kukurare && S.at(i) == '"') {
      kukurare = false;
      continue;
    } else if (kukurare) {
      continue;
    }
    if (S.at(i) == '"') {
      kukurare = true;
      continue;
    }

    if (S.at(i) == ',') S.at(i) = '.';
  }
  cout << S << endl;
}
