#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
void sort_errors(unsigned int **errors, unsigned int n, unsigned int m){
    for(auto i = n-1u; i > 0; i--){
        for(auto j = 0u; j < i; j++){
            int sum_1 = 0;
            int sum_2 = 0;
            for( auto l = 0u; l< m; l++){
                sum_1 += errors[j][l];
                sum_2 += errors[j+1][l];
            }
            if(std::abs(sum_1 - sum_2) > 0.01*m and sum_1 > sum_2){
                auto buffer = errors[j];
                errors[j] = errors[j+1];
                errors[j+1] = buffer;
            }
        }
    }
}
int main()
{
    unsigned int n, m;
    cin >> n >> m;
    unsigned int** data = new unsigned int*[n];
    for (unsigned int i = 0; i < n; i++)
        data[i] = new unsigned int[m];
    for (unsigned int i = 0; i < n; i++)
        for (unsigned int j = 0; j < m; j++)
            cin >> data[i][j];
    sort_errors(data, n, m);
    for (unsigned int i = 0; i < n; i++)
    {
        for (unsigned int j = 0; j < m; j++)
           cout << data[i][j] << " ";
        cout << endl;
    }
    for (unsigned int i = 0; i < n; i++)
        delete[] data[i];
    delete[] data;
    return 0;
}





