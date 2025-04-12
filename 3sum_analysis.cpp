#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;


vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> answer;
    for (int i = 0; i < nums.size() - 2; i++){
       for (int j = i + 1; j < nums.size() - 1; j++){
            for (int k = j + 1; k < nums.size(); k++){
                if ((nums[i] + nums[j] + nums[k]) == 0){
                    vector<int> subVector;
                    subVector.push_back(nums[i]);
                    subVector.push_back(nums[j]);
                    subVector.push_back(nums[k]);
                    sort(subVector.begin(), subVector.end());
                    answer.push_back(subVector);        
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(),answer.end()),answer.end());
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