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
  string S;
  int K;
  cin >> S >> K;

  sort(S.begin(), S.end());

  int cnt = 1;

  do {
    if (cnt == K) {
      cout << S << endl;
      return 0;
    }

    cnt++;
  } while (next_permutation(S.begin(), S.end()));
}
