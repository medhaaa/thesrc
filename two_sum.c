#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// Given nums = [2, 7, 11, 15], target = 9

int* twoSum(int* nums, int numsSize, int target);
int main() {
  //int nums[4] = {2,7,11,15};
  int nums[4] = {1,7,11,15};
  int* numPair = NULL;
  numPair = twoSum(nums,4,9);
  if(numPair[0] & numPair[1])
    printf("pair:[%d,%d]\n", numPair[0], numPair[1]);
  else
    printf("No pair found!\n");
}

int* twoSum(int* nums, int numsSize, int target) {
    int* ret_arr = NULL;
    int i,j;
    ret_arr = malloc(sizeof(int)*2);
    memset(ret_arr,0,sizeof(int)*2);  
    for(i=0,j=numsSize-1; i<numsSize-1 && j>i; ){
        if(nums[i]+nums[j] > target) j--;
        else if(nums[i]+nums[j] < target) i++;
        else if(nums[i]+nums[j] == target){
            ret_arr[0] = i;
            ret_arr[1] = j;
            break;
        }
    }  
    return ret_arr; 
}