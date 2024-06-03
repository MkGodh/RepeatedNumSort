#include <iostream>


using namespace std;

int quickSort(int* numbers, int left, int right) {
    int i = left, j = right;

    int middle = numbers[(left + right) / 2];

    while (i <= j) {
        while (numbers[i] < middle) {
            i++;
        }
        while (numbers[j] > middle) {
            j--;
        }
        if (i <= j) {
            swap(numbers[i], numbers[j]);
            i++;
            j--;
        }
    }
    if (left < j) {
        quickSort(numbers, left, j);
    }
    if (i < right) {
        quickSort(numbers, i, right);
    }
    return numbers[left];
}
int main() {

    int numbers[15] = { 110, 123, 105, 111, 132, 121, 119, 118, 117, 126, 114, 101, 123, 137, 112 };

    quickSort(numbers, 0, 14);

    int repeatedNumber = -1;
    for (int i = 0; i < 14; i++) {
        if (numbers[i] == numbers[i + 1]) {
            repeatedNumber = numbers[i];
            break;
        }
    }
    if (repeatedNumber != -1) {
        cout << "Repeated number: " << repeatedNumber << endl;
    }
    else {
        cout << "No repeated number found." << endl;
    }

    return 0;
}
