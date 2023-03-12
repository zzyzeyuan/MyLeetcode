//
// Created by 赵泽源 on 2023/3/12.
//
#include <iostream>
#include <vector>

/*
 * 必须用模板类实现，适用于任意类型数据
 *
 * 用vector实现stack的基本功能：
 * void pop() : 弹出栈顶元素
 * void  push() : 元素入栈
 * T top() : 取得栈顶元素
 * bool empty() : 是否为空
 * int size() : 栈中元素个数*/

using std::cout;

template <class T>
class Stack{
private:
    std::vector<T> _stack;
public:
    Stack() {
        cout << "调用Construction Function" << "\n";
    } // Construction Function

    void pop(){  // 基于vector.pop_back()实现  删除vector的末尾元素
        //调用pop()的前提， 栈不为空
        if(_stack.empty()){
            cout << " Stack now is empty." << "\n";
            return;
        }
        _stack.pop_back();
    }

    void push(T elem){
        _stack.push_back(elem);
    }

    T top(){
        //调用top()前提， 栈不为空
        if(_stack.empty()) {
            cout << " Stack now is empty." << "\n";
            return 0;
        }
        return _stack.back();
    }

    int size(){
        return _stack.size();
    }

    bool empty(){
        return _stack.empty();
    }
};

int main(){
    Stack<int> stack;
    stack.push(5);
    int top = stack.top();
    cout << "Get top elem: "  << top << "\n";
    stack.push(10);
    stack.push(2);

    cout << "元素出栈顺序 ："  << "\n";
    while( !stack.empty()){

        int tmp = stack.top();
        stack.pop();
        cout <<  tmp << ", ";
    }
    return 0;
}
