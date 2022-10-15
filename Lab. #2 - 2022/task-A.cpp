#include <iostream>

using std::cin;
using std::cout;

int main() {
    int elem_quant;
    int ins_number;
    int position;
    int* ptr;

    cin >> elem_quant;

    ptr = (int*) malloc(elem_quant + 1 * sizeof(int));

    int count = 0;

    while (count <= elem_quant - 1) {
        cin >> ptr[count];
        count++;
    }

    cin >> ins_number >> position;

    int swapper = elem_quant;
    while (swapper > position - 1) {
        ptr[swapper] = ptr[swapper - 1];
        swapper--;
    }

    ptr[position - 1] = ins_number;

    count = 0;
    while (count < elem_quant + 1) {
        cout << ptr[count] << " ";
        count++;
    }

    free(ptr);
    return 0;
}
