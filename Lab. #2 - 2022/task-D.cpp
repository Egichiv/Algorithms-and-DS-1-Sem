#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void insertion_sort_mechanism (int* array, int length) {
    int temp;
    int j;
    int* comp_array;

    comp_array = (int*) malloc (length * sizeof (int));
    for (int i = 1; i <= length - 1; i++) {

        int comp_count = 0;
        while (comp_count <= length -1) {
            comp_array[comp_count] = array[comp_count];
            comp_count++;
        }

        int count = 0;
        temp = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > temp) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;

        comp_count = 0;
        bool flag = false;
        while (comp_count <= length - 1) {
            if (comp_array[comp_count] != array[comp_count]) {
                flag = true;
            }
            comp_count++;
        }

        if (flag) {
            count = 0;
            while (count <= length - 1) {
                cout << array[count] << " ";
                count++;
            }
            cout << endl;
        }
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

    insertion_sort_mechanism(ptr, elem_quant);

    count = 0;
    //while (count <= elem_quant - 1) {
    //    cout << ptr[count] << " ";
    //    count++;
    //}

    free(ptr);
    return 0;
}
