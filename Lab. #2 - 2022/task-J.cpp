#include <iostream>

using std::cin;
using std::cout;

void anti_quicksort (int* array, int length) {
    int temp;
    for (int count = 0; count < length; ++count) {
        if (count != 1) {
            temp = array[count];
            array[count] = array[count / 2];
            array[count / 2] = temp;
        }
    }
}

int main() {
    int el_num;
    int* array;

    cin >> el_num;

    array = (int*) calloc(el_num, sizeof(int));

    for (int count = 0; count < el_num; count++) {
        array[count] = count + 1;
    }

    anti_quicksort(array, el_num);

    for (int count = 0; count < el_num; count++) {
        cout << array[count] << " ";
    }

    free(array);
    return 0;
}
