// Fifth

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int sum(int n, int *array);

/* int sum(int n, int* array) {
    int result = 0;

    for(auto i = 0; i < n;) {
        result += i++[array];
    }

    return result;
} */


#include <numeric>
int sum(int n, int* array) {
    return std::accumulate(array, array + n, 1, [](int left, int right){
        return left * right;
    });
}
// Место для вашего кода.
int main()
{
    int a[10];
    for (int i = 0; i < 10; i++)
        cin >> a[i];
    cout << sum(10, a) << endl;
    return 0;
}
