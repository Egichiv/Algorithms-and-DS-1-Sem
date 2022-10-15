#include <iostream>
#include <malloc.h>

using namespace std;

int main() {
    int* ptr;
    int elem_quant;
    //cout << "Enter the number of elements\n";
    cin >> elem_quant;

    ptr = (int*)malloc(elem_quant * sizeof(int));

    if (ptr == NULL) {
        cout << "Memory not allocated.\n";
        exit(0);
    }
    //else {
    //    cout << "Memory successfully allocated using malloc.\n";
    //}

    int count = 0;

    while (count < elem_quant) {
        if (count != elem_quant - 1) {
            cin >> ptr[count + 1];
        }
        else {
            cin >> ptr[0];
        }
        count++;
    }

    int i;
    for (i = 0; i < elem_quant; ++i) {
        cout << ptr[i] << " ";
    }

    free(ptr);

    return 0;
}
