#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> answer;
    sort(nums.begin(),nums.end());
    for (int i = 0; i < nums.size() - 2; i++){
        int next = i+1;
        int last = nums.size() - 1;
        if((i == 0) || nums[i] != nums[i-1]){
            while(next < last){
                int sum = nums[i] + nums[next] + nums[last];
                if (sum == 0){
                    answer.push_back({nums[i],nums[next],nums[last]});
                    while((next < last) && nums[next] == nums[next+1]){
                        next++;
                    }
                    while((next < last) && nums[last] == nums[last-1]){
                        last--;
                    }
                    next++;
                    last--;
                }
                else if(sum < 0){
                    next++;
                }
                else{
                    last--;
                }
            }   
        }
    }
    return answer;
}