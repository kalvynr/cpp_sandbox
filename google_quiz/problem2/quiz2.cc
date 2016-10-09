#include <iostream>
using namespace std;

int main() {
  //int Boys = 3, Girls = 5;
  void F1(int males, int females);
  void F2(int &m, int &f);

  F1(Boys, Girls);
  cout << "\nAfter calling F1, within main()";
  cout << "\n\tBoys = " << Boys; // #2
  cout << "\n\tGirls = " << Girls;

  F2(Boys, Girls);
  cout << "\nAfter calling F2, within main()";
  cout << "\n\tBoys = " << Boys; // #4
  cout << "\n\tGirls = " << Girls;
  cout << endl;
}

void F1(int b, int g) {
  b += 3, g += 4;
  cout << "\nF1";
  cout << "\n\tBoys = " << b; // #1
  cout << "\n\tGirls = " << g;
}

void F2(int &b, int &g) {
  b = b + 8, g = g + 5;
  cout << "\nF2";
  cout << "\n\tBoys = " << b; // #3
  cout << "\n\tGirls = " << g;
}