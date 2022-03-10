#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int N, Q;

int main() {
  cin >> N;
  vector<int> S(N);
  rep(i, 0, N) {
    cin >> S[i];
  }
  sort(S.begin(), S.end());
  
  cin >> Q;
  vector<int> T(N);
  rep(i, 0, Q) {
    cin >> T[i];
  }
  
  int cnt = 0;
  rep(i, 0, Q) {
    int tar = T[i];
    int right = N;
    int left = -1;
    while (right - left > 1) {
      int mid = left + (right - left ) / 2;
      if (S[mid] >= tar) right = mid;
      else left = mid;
    }
    
    if (S[right] == tar) cnt++;
  }
  
  cout << cnt << endl;
}
