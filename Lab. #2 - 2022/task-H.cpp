#include <iostream>

using std::cin;
using std::cout;

int total_fences (int** array, int length) {
    int total = 0;
    int max = 0;
    for (int count = 0; count < length; ++count) {
        if (count == 0) {
            total += array[count][1] - array[count][0] + 1;
            max = array[count][1];
        }
        else {
            if ((array[count][0] == array[count - 1][0]) || array[count][1] <= array[count - 1][1] || array[count][1] <= max) {
                continue;
            }
            else if (array[count][0] > max) {
                total += array[count][1] - array[count][0] + 1;
                max = array[count][1];
            }
            else {
                total += array[count][1] - max;
                max = array[count][1];
            }
        }
    }
    return total;
}

void merge (int** array, int left, int mid, int right) {
    int it1 = 0;
    int it2 = 0;

    int** temp_array;
    temp_array = (int**) malloc((right - left) * sizeof(int*));
    for (int i = 0; i < (right - left); i++) {
        temp_array[i] = (int*) malloc(2 * sizeof(int));
    }

    while ((left + it1 < mid) && (mid + it2 < right)) {
        if (array[left + it1][0] < array[mid + it2][0]) {
            temp_array[it1 + it2][0] = array[left + it1][0];
            temp_array[it1 + it2][1] = array[left + it1][1];
            it1++;
        }
        else if (array[left + it1][0] == array[mid + it2][0]) {
            if (array[left + it1][1] > array[mid + it2][1]) { //тут для нужной сортировки второго элемента можно знак поменять
                temp_array[it1 + it2][0] = array[left + it1][0];
                temp_array[it1 + it2][1] = array[left + it1][1];
                it1++;
            }
            else {
                temp_array[it2 + it1][0] = array[mid + it2][0];
                temp_array[it2 + it1][1] = array[mid + it2][1];
                it2++;
            }
        }
        else {
            temp_array[it2 + it1][0] = array[mid + it2][0];
            temp_array[it2 + it1][1] = array[mid + it2][1];
            it2++;
        }
    }

    while (left + it1 < mid) {
        temp_array[it1 + it2][0] = array[left + it1][0];
        temp_array[it1 + it2][1] = array[left + it1][1];
        it1++;
    }

    while (mid + it2 < right) {
        temp_array[it1 + it2][0] = array[mid + it2][0];
        temp_array[it1 + it2][1] = array[mid + it2][1];
        it2++;
    }

    for (int i = 0; i < it1 + it2; i++) {
        array[left + i][0] = temp_array[i][0];
        array[left + i][1] = temp_array[i][1];
    }
    free(temp_array);
}

void morj_sort_4pairs (int** array1, int left, int right) {
    if (left + 1 >= right) {
        return;
    }
    int mid;
    mid = (left + right) / 2;
    morj_sort_4pairs(array1, left, mid);
    morj_sort_4pairs(array1, mid, right);
    merge(array1, left, mid, right);
}

int main() {
    int pair_num;
    int** fences;

    cin >> pair_num;

    fences = (int**) malloc(pair_num * sizeof(int*));
    for (int i = 0; i < pair_num; i++) {
        fences[i] = (int*) malloc(2 * sizeof(int));
    }

    for (int first_count = 0; first_count < pair_num; first_count++) {
        cin >> fences[first_count][0] >> fences[first_count][1];
    }

    morj_sort_4pairs(fences, 0, pair_num);

    cout << total_fences(fences, pair_num);

    free(fences);
    return 0;
}
