#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll MAX = 1000000000000000000;

int main() {
  ll A, B;
  cin >> A >> B;
  
  ll gcd_num = __gcd(A, B);
  ll left = A / gcd_num;
  if (log10(left) + log10(B) > 18) {
    cout << "Large" << endl;
    return 0;
  }
  ll ans = left * B;
  
  if (MAX < ans) {
    cout << "Large" << endl;
  } else {
    cout << ans << endl;
  }
}

