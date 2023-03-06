#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class Solution{
	public:
		int search(vector<int>& nums, int target){
			if( nums.size() ==1 )
				return target == nums[0] ? 0 : -1;

			int left = 0;
			int right = nums.size()-1;
			while( left <= right ){
				
				//int mid = (left + right) /2    left+right这种写法很可能会out of range
				int mid = left + (right - left)/2;
				// 判断条件不取等号, left = mid +1；right = mid -1;
				// 这样取才能有right < left 退出 while循环
				if( target > nums[mid] ){
					left = mid + 1;
				}else{ // target <= mid
					right = mid - 1;
				}
			}
			
			if(nums[left] != target) return -1;
			else
				return left;
		}
	
};

int main(int argc, char *argv[])
{
	vector<int> nums = {-1,0,3,5,9,12};
	int target1 = 9;
	int target2 = 2;
	Solution solution;
	solution.search(nums, target2);
	return 0;
}
