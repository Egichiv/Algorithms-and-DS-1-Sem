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
    free(sub_ptr);
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

void array_contraction (int* original_array, int orig_arr_length, int* new_array, int* new_arr_length) {
    int count = 0;
    int new_array_count = 0;
    while (count <= orig_arr_length - 1) {
        if (count == 0) {
            new_array[new_array_count] = original_array[count];
            new_array_count++;
        }
        else if ((original_array[count] != original_array[count - 1])) {
            new_array[new_array_count] = original_array[count];
            new_array_count++;
        }
        count++;
    }
    *new_arr_length = new_array_count;
}

int main() {
    int el_num_1;
    int el_num_2;
    int* array_1;
    int* array_2;
    int* short_array_1;
    int* short_array_2;

    cin >> el_num_1;
    array_1 = (int*) malloc(el_num_1 * sizeof(int));
    short_array_1 = (int*) malloc(el_num_1 * sizeof(int));

    int count = 0;
    while (count <= el_num_1 - 1) {
        cin >> array_1[count];
        count++;
    }
    merge_sort(array_1, 0, el_num_1);

    cin >> el_num_2;
    array_2 = (int*) malloc(el_num_2 * sizeof(int));
    short_array_2 = (int*) malloc(el_num_2 * sizeof(int));

    count = 0;
    while (count <= el_num_2 - 1) {
        cin >> array_2[count];
        count++;
    }
    merge_sort(array_2, 0, el_num_2);

    int short_array_1_length = 0;
    int short_array_2_length = 0;
    int* ptr1 = &short_array_1_length;
    int* ptr2 = &short_array_2_length;
    array_contraction(array_1, el_num_1, short_array_1, ptr1);
    array_contraction(array_2, el_num_2, short_array_2, ptr2);

    if (short_array_1_length != short_array_2_length) {
        cout << "NO";
        return 0;
    }

    bool flag = true;
    count = 0;
    while (count <= short_array_1_length - 1) {
        if (short_array_1[count] == short_array_2[count]) {
            count++;
        }
        else {
            flag = false;
            break;
        }
    }

    if (flag) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    free(array_1);
    free(array_2);
    return 0;
}
