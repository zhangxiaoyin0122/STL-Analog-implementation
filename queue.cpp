#include <iostream>
#include <queue>
using namespace std;


template<class T,class Container = deque<T> >
class Queue{
public:
    //队列的插入:尾插
    void push(const T& val){
        _con.push_back(val); 
    }
    //队列的删除:头删
    void pop(){
        _con.pop_front();
    }
    //获取元素个数
    size_t size()const{
        return _con.size();
    }
    //获取队头元素
    const T& front(){
        return _con.front();
    }
    //判空
    bool empty(){
        return _con.empty();
    }

private:
    Container _con;
};

void test(){
        Queue<int> q;
        q.push(1);
        q.push(2);
        q.push(3);
        q.push(4);
        q.push(5);
        q.push(6);
        cout << q.size() << endl;
        q.pop();
        cout << q.size() << endl;
        cout << q.front() << endl;

}

int main(){
    test();
    return 0;
}
