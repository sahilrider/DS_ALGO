#include <iostream>
using namespace std;
//Dynamic Programming 
int maximumSumSubarray(int arr[], int len) 
{ 
   int max = arr[0]; 
   int current = arr[0]; 
  
   for (int i = 1; i < len; i++) 
   { 
        current = (arr[i]>current+arr[i])?arr[i]:current+arr[i]; 
        max = (max>current)?max:current;
   } 
   return max; 
} 

int main() {
	
	int arr[] =  {-1,2,5,7,-6,2,4}; 
	int len = sizeof(arr)/sizeof(arr[0]); 
	int max = maximumSumSubarray(arr, len); 
	cout << "Subarray with maximum sum is " << max; 
	return 0; 
}

  
