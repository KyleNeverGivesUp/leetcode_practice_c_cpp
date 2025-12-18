/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k%=size;
        // solution 1 reverse
        // reverse(nums.begin(), nums.end());
        // reverse(nums.begin(), nums.begin()+k);
        // reverse(nums.begin()+k, nums.end());

        //solution 2 more Using Extra Array

        // vector<int> vt(size);
        // for (int i=0; i<size; ++i){
        //     vt[(i+k)%size] = nums[i];
        // }
        // nums = vt;

        // solution 3 brute force
        // int temp, previous = 0;
        // for (int i=0; i < k; ++i){
        //     previous = nums[size - 1];
        //     for (int j=0; j< size; ++j){
        //         temp = nums[j];
        //         nums[j] = previous;
        //         previous = temp;
        //     }
        // }

        // solution Cyclic Replacements
        int temp=0, prev=0, current=0, count=0, start = 0;
        while(count < size){
            current = start; prev = nums[start];
            do{
                int next = (current + k) % size;
                temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            }while( current != start);
            start++;
        }
    }
};
// @lc code=end

