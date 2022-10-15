#include <iostream>

using namespace std;

int main() {
    int elem_quant;
    int* ptr;
    cin >> elem_quant;
    if (elem_quant == 0 || elem_quant == 1) {
        cout << 0;
        exit(0);
    }

    ptr = (int*) malloc(elem_quant * sizeof(int));

    int count = 0;

    while (count < elem_quant) {
        cin >> ptr[count];
        count++;
    }
    count = 0;
    int result = 0;
    while (count < elem_quant) {
        if (count > 0 && count < elem_quant - 1) {
            if (ptr[count] > ptr[count - 1] && ptr[count] > ptr[count + 1]) {
                result++;
            }
        }
        count++;
    }

    cout << result;

    free(ptr);
    return 0;
}
