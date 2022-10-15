#include <iostream>

using std::cin;
using std::cout;

void insertion_sort (int* array, int length) {
    int temp;
    int j;
    for (int i = 1; i <= length - 1; i++) {
        temp = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > temp) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}

int main() {
    int elem_quant;
    int* ptr;

    cin >> elem_quant;

    ptr = (int*) malloc(elem_quant * sizeof(int));

    int count = 0;
    while (count <= elem_quant - 1) {
        cin >> ptr[count];
        count++;
    }

    insertion_sort(ptr, elem_quant);

    count = 0;
    while (count <= elem_quant - 1) {
        cout << ptr[count] << " ";
        count++;
    }

    free(ptr);
    return 0;
}
