/*
 * Title: heap.cpp
 * Abstract:  When the program starts, it should read a set of numbers from a 
 * user and store them in an array in the order the numbers are entered. 
 * Author: Wais Robleh
 * ID: 1624
 * Date: 02/22/2020
 */

#include <bits/stdc++.h>

using namespace std;

bool checkHeap(vector<int> arr, int size){
    int left, right;
    
    for(int i = size/2; i >= 1; i--){
        left = 2 * i;
        right = 2 * i + 1;
        if(left == size){
            right = 0;
        } else if (right > size){
            left = 0;
            right = 0;
        }
        
        if (arr[left] > arr[i] || arr[right] > arr[i]){
            return false;
        }
    }
    
    return true;
    
}

int main() {

    int inSize, num;
    cout << "Input Size: ";
    cin >> inSize;
    cout << endl;
    
    vector<int> heap(inSize+1,0);
    
    cout << "Enter numbers:";

    for (int i = 1; i <= inSize; i++)
    {
        cin >> num;
        heap[i] = num;
    }
    
    if(checkHeap(heap, inSize))
    {
        cout << "This is a heap.\n";
    }
    
    for (int i = 1; i <= inSize; i++)
    {
        cout << heap[i] << endl;
    }
    
    return 0;
}