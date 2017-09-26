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

void insertNumber(float currentMedian, int newValue);
void balanceHeaps();
float findMedian();

priority_queue<int, vector<int>, greater<int> > minHeap; // larger half of numbers
priority_queue <int> maxHeap; // smaller half of numbers

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    float median = 0;
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];

       insertNumber(median, a[a_i]);
       balanceHeaps();
       median = findMedian();
       printf("%.1f\n", median);
    }
    return 0;
}


void insertNumber(float currentMedian, int newValue){
    if( currentMedian <= newValue ){
       minHeap.push(newValue);
    }
    else if ( currentMedian > newValue){
       maxHeap.push(newValue);
    }
}

void balanceHeaps( ){
    // larger half of numbers have 2 more elements than smaller half
    if( minHeap.size() == maxHeap.size() + 2){
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }
    // larger half of numbers have 2 less elements than smaller half
    else if (minHeap.size() + 2 == maxHeap.size() ){
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }

}

float findMedian(){

    float median;

    if( minHeap.size() == maxHeap.size() ){
        median = (float)(minHeap.top() + maxHeap.top()) /2;
    }
    else if (minHeap.size() > maxHeap.size()){
       median =  (float) minHeap.top();
    }
    else if (minHeap.size() < maxHeap.size()){
       median =  (float) maxHeap.top();
    }

    return median;

}
