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

// Bottom up DP approach
long make_changeDP(vector<int> coins, int money) {
    long ways[coins.size() + 1][money + 1] = { };

    for(int r = 0; r <= coins.size(); r++) {
        ways[r][0] = 1;
    }

    for(int c = 1; c <= money; c++) {
        ways[0][c] = 0;
    }


    for( int n = 1; n <= money; n++ ){
        for( int c = 1; c <= coins.size(); c++ ){
            if(coins[c - 1] > n){
                ways[c][n] = ways[c - 1][n];
            } else {
                ways[c][n] = ways[c][n - coins[c - 1]] + ways[c - 1][n];
            }
        }
    }

    return ways[coins.size()][money];
}

// Memorization DP approach
long make_changeMem(vector<int> coins, int money, int coinIndex, map<std::string, int> pastWork) {
    if(money <= 0){
        return 1;
    }

    if(coinIndex >= coins.size()){
        return 0;
    }

    string key = "i-" + coinIndex;

    if (pastWork.count(key)){
        return pastWork[key];
    }

    long ways = 0;
    for(int i = 0; i*coins[coinIndex] <= money; i++ ){
        ways += make_changeMem(coins, money - i*coins[coinIndex], coinIndex + 1, pastWork);
    }

    pastWork[key] = ways;

    return ways;
}

int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<int> coins(m);
    for(int coins_i = 0;coins_i < m;coins_i++){
       cin >> coins[coins_i];
    }

    map<std::string, int> pastWork;

    //cout << make_changeDP(coins, n, 0, pastWork) << endl;
    cout << make_changeDP(coins, n) << endl;
    return 0;
}
