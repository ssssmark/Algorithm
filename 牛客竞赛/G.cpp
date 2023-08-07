#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

int shortestSubsequence(vector<int>& nums, int k) {
    unordered_map<int, int> counts;                 
    int left = 0, right = 0;                        
    int minLen = INT_MAX;                          
    int count4 = 0;                                
    // ��ʼ����ϣ��
    for (int i = 1; i <= 4; i++) {
        counts[i] = 0;
    }

    // ��������
    while (right < nums.size()) {
        counts[nums[right]]++;                      
        // ��������1��2��3�ĺ�4�ĸ���������Ҫ��ʱ����ʼ�ƶ���ָ��
        while (counts[1]>=1 && counts[2] >= 1&& counts[3] >= 1 && counts[4] >= k) {
            minLen = min(minLen, right - left);      
            counts[nums[left]]--;                   
            left++;                                
        }

        right++;                                   
    }
    if (minLen == INT_MAX) {
        return -1;                                 
    }
    return minLen + 1;
}

int main() {
    int n, k;
    cin >> n >> k;                                  
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];                            
    }
    int result = shortestSubsequence(nums, k);      
    cout << result << endl;                         
    return 0;
}
