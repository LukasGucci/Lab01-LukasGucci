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

vector<int> tests(int n){
    vector<int> nums;

    int a = rand() % 100 + 1;
    int b = rand() % 100 + 1;
    nums.push_back(-a);
    nums.push_back(-b);
    nums.push_back(a + b);

    while (nums.size() < n){
        nums.push_back(rand() % 400 - 200);
    }

    return nums;
}

int main(){
    vector<int> lengthNumbers = {400,800,1600,3200,8000};
    for(int i =0; i < 5; i++){
        vector<int> testCase = tests(lengthNumbers.at(i));
        auto start = chrono::high_resolution_clock::now();
        vector<vector<int>> result = threeSum(testCase);
        auto end = chrono::high_resolution_clock::now();
        double time_ms = chrono::duration_cast<chrono::microseconds>(end - start).count() / 1000.0;
        cout << "n = " << lengthNumbers.at(i) << " → Time: " << time_ms << " ms, Found: " << result.size() << " triplets" << endl;
    }
    return 0;

}