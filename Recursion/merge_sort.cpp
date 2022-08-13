#include <iostream>
#include <vector>
using namespace std;
class Solution
{
private:
    vector<int> merge_sort(vector<int> &nums)
    {
        if(nums.size() <= 1)
        {
            return nums;
        }
        int mid = nums.size() / 2;
        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid, nums.end());
        vector<int> left_list = merge_sort(left);
        vector<int> right_list = merge_sort(right);
        return merge(left_list, right_list);
    }
    vector<int> merge(vector<int> &left, vector<int> &right)
    {
        vector<int> ret(left.size() + right.size());
        int left_cursor = 0, right_cursor = 0, ret_cursor = 0;
        while(left_cursor < left.size() && right_cursor < right.size())
        {
            if(left[left_cursor] < right[right_cursor])
            {
                ret[ret_cursor++] = left[left_cursor++];
            }
            else
            {
                ret[ret_cursor++] = right[right_cursor++];
            }
        }
        while(left_cursor < left.size())
        {
            ret[ret_cursor++] = left[left_cursor++];
        }
        while(right_cursor < right.size())
        {
            ret[ret_cursor++] = right[right_cursor++];
        }
        return ret;
    }
public:
    vector<int> sortArray(vector<int> nums)
    {
        return merge_sort(nums);
    }
};

int main()
{
    vector<int> input({2, 4, -1, 0, 10, 9, 5, 8});
    Solution answer;
    vector<int> output;
    output = answer.sortArray(input);
    for(int x: output)
    {
        cout << x << " " << endl;
    }
    return 0; 
}