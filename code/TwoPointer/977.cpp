#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void f(vector<int>& v){
        int l=0, r = v.size()-1;
        vector<int> ans(v.size());
        int cur = ans.size()-1;
        while(l <= r){
            if( v[l]*v[l] > v[r]*v[r]){
                ans[cur--] = v[l]*v[l];
                l++;
            }else{
                ans[cur--] = v[r]*v[r];
                r--;
            }
        }
        for(auto a : ans) cout << a << ", ";
    }
};

int main(){
    int n;
    cin>> n;
    vector<int> vec;
    for (int i = 0; i < n; ++i) {
        int elem;
        cin>>elem;
        vec.emplace_back(elem);
    }
    Solution solution;
    solution.f(vec);

    return 0;
}