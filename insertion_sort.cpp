#include <bits/stdc++.h> 


void insertionSort(int n, vector<int> &nums){
    // Write your code here.
    for(int i=1;i<n;i++){
        int temp=nums[i];
        int j=i-1;
        for (;j>=0;j--){
            if(nums[j]>temp){
                nums[j+1]=nums[j];
            }
            else{
                break;
            }
        }
        nums[j+1]=temp;

    }
}

// DO IT WITH WHILE LOOP :))

