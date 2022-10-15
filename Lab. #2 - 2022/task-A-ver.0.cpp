#include <iostream>

using std::cin;
using std::cout;

int main() {
    int elem_quant;
    int ins_number;
    int position;

    cin >> elem_quant;
    int array[elem_quant + 1];
    //array = (int*) malloc(elem_quant + 1 * sizeof(int));

    int count = 0;

    while (count <= elem_quant - 1) {
        cin >> array[count];
        count++;
    }

    cin >> ins_number >> position;

    int swapper = elem_quant;
    while (swapper > position - 1) {
        array[swapper] = array[swapper - 1];
        swapper--;
    }

    array[position - 1] = ins_number;

    count = 0;
    while (count < elem_quant + 1) {
        cout << array[count] << " ";
        count++;
    }

    return 0;
}