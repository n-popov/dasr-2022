#include <iostream>
using namespace std;
/* int* copyarr(int* a, unsigned int size) {
    int* result = new int[size];
    for(auto i = 0u; i < size; i++) {
        i[result] = i[a];
    }
    return result;
} */

#include <algorithm>
int* copyarr(int* a, unsigned int size) {
    int* result = new int[size];
    std::copy(a, a + size, result);
    return result;
}
// Место для вашего кода.
int main()
{
    unsigned int n;
    int* a;
    cin >> n;
    a = new int[n];
    for(unsigned int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int* b = copyarr(a, n);
    for(unsigned int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
    delete[] a;
    delete[] b;
    return 0;
}
