#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector < int > a(n);
    for (int a_i = 0; a_i < n; a_i++) {
        cin >> a[a_i];
    }

    // Code below
    int temp = 0;
    int totalOfSwaps = 0;

    for (int i = 0; i < n; i++) {
        int numberOfSwaps = 0;
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                numberOfSwaps++;
            }
        }

        if( numberOfSwaps == 0 ){
            break;
        }
        totalOfSwaps = totalOfSwaps + numberOfSwaps;
    }

    printf("Array is sorted in %i swaps. \n", totalOfSwaps);
    printf("First Element: %i \n", a[0]);
    printf("Last Element: %i \n", a[n-1]);
    return 0;
}
