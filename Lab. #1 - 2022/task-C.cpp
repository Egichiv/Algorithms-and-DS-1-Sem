#include <iostream>

using namespace std;

int main() {
    int droid_quant;
    int* ptr;

    cin >> droid_quant;

    ptr = (int*)malloc(2 * sizeof(int));
    cin >> ptr[0] >> ptr[1];
    int temp;
    if (ptr[1] < ptr[0]) {
        temp = ptr[0];
        ptr[0] = ptr[1];
        ptr[1] = temp;
    }

    int count = 2;
    int current;

    while (count < droid_quant) {
        cin >> current;
        if (current < ptr[0]) {
            ptr[1] = ptr[0];
            ptr[0] = current;
        }
        else if (current < ptr[1]) {
            ptr[1] = current;
        }
        count++;
    }

    cout << ptr[0] << " " << ptr[1];

    free(ptr);
    return 0;
}
