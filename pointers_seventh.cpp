#include <iostream>
using std::cin;
using std::cout;
using std::endl;
void copy_array_reverse(int n, char *array_source, char *array_destination);
// Место для вашего кода.

/*
void copy_array_reverse(int n, char *array_source,
                        char *array_destination) {
    for(auto i = 0; i < n; i++) {
        array_destination[n - i - 1] = array_source[i];
    }
}
*/

#include <algorithm>
void copy_array_reverse(int n, char *array_source,
                        char *array_destination) {
    std::reverse_copy(array_source, array_source + n, array_destination);
}

int main()
{
    char a[] = {"Hello there."}, b[] = {"General Kenobi..."};
    copy_array_reverse(6, a, b + 4);
    cout << b << endl;
    return 0;
}
