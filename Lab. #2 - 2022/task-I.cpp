#include <iostream>

using std::cin;
using std::cout;

int partition(int* array, int left, int right) {
    int v = array[(left + right) / 2];
    int i = left;
    int j = right;
    while (i <= j) {
        while (array[i] < v) {
            i++;
        }
        while (array[j] > v) {
            j--;
        }
        if (i >= j) {
            break;
        }
        int temp = array[i];
        array[i++] = array[j--];
        array[j + 1] = temp;
    }
    return j;
}

void quick_sort (int* array, int left, int right) {
    if (left < right) {
        int pivot = partition (array, left, right);
        quick_sort (array, left, pivot);
        quick_sort (array, pivot + 1, right);
    }
}

int main() {
    int el_num;
    int* array;

    cin >> el_num;

    array = (int*) calloc (el_num, sizeof (int));

    for (int count = 0; count < el_num; ++count) {
        cin >> array[count];
    }

    quick_sort(array, 0, el_num - 1);

    for (int count = 0; count < el_num; ++count) {
        cout << array[count] << " ";
    }

    free (array);
    return 0;
}
