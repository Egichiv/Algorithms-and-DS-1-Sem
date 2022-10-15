#include <iostream>

using std::cin;
using std::cout;

void merge(int* array, int left, int mid, int right) {
    int it1 = 0;
    int it2 = 0;

    int* sub_ptr;
    sub_ptr = (int*) malloc((right - left) * sizeof(int));

    while ((left + it1 < mid) && (mid + it2 < right)) {
        if (array[left + it1] < array[mid + it2]) {
            sub_ptr[it1 + it2] = array[left + it1];
            it1++;
        }
        else {
            sub_ptr[it2 + it1] = array[mid + it2];
            it2++;
        }
    }

    while (left + it1 < mid) {
        sub_ptr[it1 + it2] = array[left + it1];
        it1++;
    }

    while (mid + it2 < right) {
        sub_ptr[it1 + it2] = array[mid + it2];
        it2++;
    }

    for (int i = 0; i < it1 + it2; i++) {
        array[left + i] = sub_ptr[i];
    }
}

void merge_sort (int* array, int left, int right) {
    if (left + 1 >= right) {
        return;
    }
    int mid;
    mid = (left + right) / 2;
    merge_sort(array, left, mid);
    merge_sort(array, mid, right);
    merge(array, left, mid, right);
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

    merge_sort(ptr, 0, elem_quant);

    count = 0;
    while (count <= elem_quant - 1) {
        cout << ptr[count] << " ";
        count++;
    }

    free(ptr);
    return 0;
}
