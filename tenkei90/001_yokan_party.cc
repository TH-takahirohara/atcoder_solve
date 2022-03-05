#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N, L, K;
  cin >> N >> L >> K;
  vector<int> A(N, 0);
  
  for (int i=0; i<N; i++) cin >> A.at(i);
  
  int left = 0, right = L;
  int output = 0;
  
  while (right >= left) {
    int now = 0, cnt = 0;
    int mid = left + (right - left) / 2;
    
    for (int i=0; i<N; i++) {
      if (mid <= (A.at(i) - now) && (L - A.at(i)) >= mid) {
        cnt += 1;
        now = A.at(i);
      }
    }
    
    if (cnt >= K) {
      output = mid;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  
  cout << output << endl;
}
