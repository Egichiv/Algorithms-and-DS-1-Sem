#include <iostream>

using namespace std;

int main() {
    int a;
    cin >> a;
    if (a > 9) {
        a = a % 10;
        cout << a;
    }
    else {
        if (a >= 0) {
            cout << a;
        }
        else {
            return 1;
        }
    }
    return 0;
}
