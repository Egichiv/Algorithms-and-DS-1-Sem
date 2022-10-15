#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void insertion_sort_4pairs (int* array1, int* array2, int length) {
    int temp1;
    int temp2;
    int j;
    for (int i = 1; i <= length - 1; i++) {
        temp1 = array1[i];
        temp2 = array2[i];
        j = i - 1;
        while (j >= 0 && array2[j] < temp2) {
            array1[j + 1] = array1[j];
            array2[j + 1] = array2[j];
            j--;
        }
        array1[j + 1] = temp1;
        array2[j + 1] = temp2;
    }

    int temp;
    j = 0;
    for (int i = 1; i <= length - 1; i++) {
        temp = array1[i];
        j = i - 1;
        while (j >= 0 && array1[j] > temp && array2[j] == array2[j + 1]) {
            array1[j + 1] = array1[j];
            j--;
        }
        array1[j + 1] = temp;
    }
}

int main() {
    int pair_quant;
    int* numbers;
    int* points;

    cin >> pair_quant;

    numbers = (int*) malloc((pair_quant) * sizeof(int));
    points = (int*) malloc((pair_quant) * sizeof(int));

    int count = 0;
    while (count <= pair_quant - 1) {
        cin >> numbers[count] >> points[count];
        count++;
    }

    insertion_sort_4pairs(numbers, points, pair_quant);

    count = 0;
    while (count <= pair_quant - 1) {
        cout << numbers[count] << " " << points[count] << endl;
        count++;
    }

    free(numbers);
    free(points);
    return 0;
}
