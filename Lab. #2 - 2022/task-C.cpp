#include <iostream>

using std::cout;
using std::cin;

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

int capacity (const int* array1, const int* array2, int length1, int length2) {
    int result = 0;
    int i = 0;
    int j = 0;
    while (i <= length1 - 1 && j <= length2 - 1) {
        if (array1[i] >= array2[j]) {
            result++;
            i++;
            j++;
        }
        else {
            i++;
        }
    }
    return result;
}

int main() {
    int n, m;
    int mesklin_quant;
    int* mesklin_arr;
    int* raft_arr;

    cin >> n >> m;

    int raft_quant = n * m;
    raft_arr = (int*) malloc(raft_quant * sizeof(int));

    int count = 0;
    while (count <= n*m - 1) {
        cin >> raft_arr[count];
        count++;
    }
    insertion_sort(raft_arr, raft_quant);

    cin >> mesklin_quant;

    mesklin_arr = (int*) malloc(mesklin_quant * sizeof(int));

    count = 0;
    while (count <= mesklin_quant -1) {
        cin >> mesklin_arr[count];
        count++;
    }
    insertion_sort(mesklin_arr, mesklin_quant);

    int answer;
    answer = capacity(raft_arr, mesklin_arr, raft_quant, mesklin_quant);

    cout << answer;

    free(mesklin_arr);
    free(raft_arr);
    return 0;
}
