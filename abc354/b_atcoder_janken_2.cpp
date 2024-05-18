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
  int sum = 0;
  vector<string> S(N);
  rep(i,0,N) {
    string s;
    int c;
    cin >> s >> c;
    sum += c;
    S.at(i) = s;
  }

  sort(S.begin(), S.end());

  int amari = sum % N;

  cout << S.at(amari) << endl;
}
