#include <iostream>
using namespace std;

// 1. Forward: 1 → n
void forward_1_to_n(int i, int n) {
    if (i > n) return;
    cout << i << " ";
    forward_1_to_n(i + 1, n);
}

// 2. Forward: n → 1
void forward_n_to_1(int n) {
    if (n == 0) return;
    cout << n << " ";
    forward_n_to_1(n - 1);
}

// 3. Backtrack: n → 1
void backtrack_n_to_1(int i,int n) {
    if (i>n) return;
    backtrack_n_to_1(i+1,n);
    cout << i << " ";
}

// 4. Backtrack: 1 → n
void backtrack_1_to_n(int n) {
    if (n == 0) return;
    backtrack_1_to_n(n - 1);
    cout << n << " ";
}

int main() {
    int n = 5;

    cout << "Forward 1 to n: ";
    forward_1_to_n(1, n);
    cout << endl;

    cout << "Forward n to 1: ";
    forward_n_to_1(n);
    cout << endl;

    cout << "Backtrack n to 1: ";
    backtrack_n_to_1( 1,n);
    cout << endl;

    cout << "Backtrack 1 to n: ";
    backtrack_1_to_n(n);
    cout << endl;

    return 0;
}