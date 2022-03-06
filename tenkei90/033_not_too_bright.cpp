#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int H, W;
  cin >> H >> W;
  
  if (H == 1) {
    cout << W << endl;
    return 0;
  } else if (W == 1) {
    cout << H << endl;
    return 0;
  }
  
  cout << ((H-1)/2 + 1) * ((W-1)/2 + 1) << endl;
}

