#include <bits/stdc++.h> 


void bubbleSort(vector<int>& nums, int n)
{   
    bool swapped=false;
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(nums[j+1]<nums[j]){
                swapped=true;
                swap(nums[j],nums[j+1]);
            }
        }
        if(swapped==false){
            break;
        }
    }
}
