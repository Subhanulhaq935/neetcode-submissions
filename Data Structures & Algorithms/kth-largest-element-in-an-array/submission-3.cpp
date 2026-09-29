class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> freq(2001 , 0);

        for(int i : nums){
            freq[i + 1000]++;
        }

        for(int i = 1000 ; i >= -1000 ; i--)
        {
            k-= freq[i + 1000];
            if(k <= 0) return i;
        }

        return -1;
    }
};
