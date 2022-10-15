#include <iostream>

using namespace std;

int main() {
    int elem_quant;
    int* ptr;
    cin >> elem_quant;

    ptr = (int*) malloc(elem_quant * sizeof(int));

    int count = 0;
    while (count < elem_quant) {
        cin >> ptr[count];
        count++;
    }

    int the_number;
    cin >> the_number;
    int closest;
    int min_differ = 3000;
    int curr_differ;

    count = 0;
    while (count < elem_quant) {
        if (ptr[count] < the_number) {
            curr_differ = the_number - ptr[count];
        }
        else {
            curr_differ = ptr[count] - the_number;
        }

        if (curr_differ < min_differ) {
            min_differ = curr_differ;
            closest = ptr[count];
        }
        count++;
    }

    cout << closest;

    free(ptr);
    return 0;
}
