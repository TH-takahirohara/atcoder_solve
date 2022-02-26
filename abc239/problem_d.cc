#include <bits/stdc++.h>
using namespace std;

bool check_sosuu(int value) {
  if (value == 2) {
    return true;
  }
  for (int i=1; i<= value/2; i++) {
    if (i==1) {
      continue;
    }
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  
  // 高橋は、AからBまでのそれぞれの値に対してCからDのそれぞれを足して、
  // 素数が存在しないようなAからBの値があれば、勝ち
  bool no_sosuu = false;
  for (int i=A; i<=B; i++) {
    bool sosuu_exist = false;
    
    for (int j=C; j<=D; j++) {
      if (check_sosuu(i+j)) {
        sosuu_exist = true;
        break;
      }
    }
    
    if (!sosuu_exist) {
      no_sosuu = true;
      break;
    }
  }
  
  if (no_sosuu) {
    cout << "Takahashi";
  } else {
    cout << "Aoki";
  }
}
