#include <iostream>
#include <unordered_set>

using namespace std;

class Solution{
public:
	int getSum(int n){
		int sum=0;
		while ( n!=0 ){
            sum += (n%10) * (n%10);
            n /= 10;
        }
        return sum;
	}
	bool isHappy(int n){
        unordered_set<int> hashset;
        while( true ){
            int sum = getSum(n);
            if ( sum == 1) {
                cout << " 是快乐数" << "\n";
                return true;
            }
            n = sum;
            if ( hashset.find(sum) != hashset.end()){
                // 如果hashset没有返回end()，则说明找到了，所以就结束迭代
                cout << "不是快乐数" << "\n";
                return false;
            }else{
                hashset.insert(sum);
            }
        }
	}
};


int main(int argc, char *argv[])
{
	int n;
	cin>>n;

	Solution so;
	so.isHappy(n);
	return 0;
}
