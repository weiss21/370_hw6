/*
 * Title: prim.cpp
 * Abstract:  Implementation of Prim's algorithm using txt files as input.
 * Author: Wais Robleh
 * ID: 1624
 * Date: 02/23/2020
 */

#include <bits/stdc++.h>

using namespace std;


int minKey(int* key, bool* inMST, int vertices);
int main() {
    int vertices, edges, count;
    string fileName;
    
    cout << "Enter input file name: ";
    cin >> fileName;
    cout << "Enter the first vertex to start: ";
    cin >> count;
    cout << endl;
    
    ifstream inStream(fileName.c_str());
    
   
    inStream >> vertices;
    inStream >> edges;
    
    int dynamArray[vertices][vertices];
    
    for(int i=0; i<vertices; i++){    
		for(int j=0; j<vertices; j++){
			dynamArray[i][j] = 0;
		}
	}
	
	for(int i=0; i<edges; i++){
	    int x, y, weight; 
	    inStream >> x;
	    inStream >> y;
	    inStream >> weight;
	    dynamArray[x-1][y-1] = weight;
	    dynamArray[y-1][x-1] = weight;
	}
	inStream.close();
	
    int parent[vertices]; 
    int key[vertices]; 
    bool inMST[vertices]; 
  
    for (int i=0; i<vertices; i++) 
        key[i] = 1000, inMST[i] = false; 
  
    key[count-1] = 0; 
    parent[count-1] = -1;  
  
    for (int count=0; count<vertices-1; count++) { 
        int i = minKey(key, inMST, vertices); 
  
        inMST[i] = true; 
  
        for (int j=0; j<vertices; j++) 
  
            if (dynamArray[i][j] && inMST[j] == false && dynamArray[i][j] < key[j]) 
                parent[j] = i, key[j] = dynamArray[i][j]; 
    } 
  
    for (int i = 1; i < vertices; i++) 
        cout << "(" << i << ") New edge: " << parent[i]+1 << "," << i+1 << " - cost " << dynamArray[i][parent[i]] << endl;
}

int minKey(int* key, bool* inMST, int vertices) 
{ 
    int min = 1000, min_index; 
  
    for (int i = 0; i < vertices; i++) 
        if (inMST[i] == false && key[i] < min) 
            min = key[i], min_index = i; 
  
    return min_index; 
} 