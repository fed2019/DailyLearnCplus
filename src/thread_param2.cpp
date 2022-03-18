/*** 
 * @Author: pfzhang
 * @E-mail: zhangpengfei@youibot.com
 * @Date: 2022-03-15 14:39:44
 * @LastEditors: pfzhang
 * @LastEditTime: 2022-03-16 16:20:36
 * @Description: Do not edit
 * @FilePath: /learning/src/thread_param_tip2.cpp
 */

#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <thread>
#include <memory>

using namespace std;

class TA
{
public:
    int mData;
public:
    TA(int data);
    TA(const TA &ta);
    ~TA();
};

TA::TA(int data) :mData(data) {
    cout << "constructor exec! obj addr:" << this << ",thread id:" << this_thread::get_id() << endl;
}

TA::TA(const TA &ta) :mData(ta.mData){
    cout << "copy constructor exec! obj addr:" << this << ",thread id:" << this_thread::get_id() << endl;
}

TA::~TA()
{
    cout << "destructor exec! obj addr" << this << ",thread id:" << this_thread::get_id() << endl;
}


void myfun(const int &i,const TA &ta) {
    cout << "i content:" << i
         << ",i addr:" << &i << endl;
    printf("ta addr:%p\n",ta);
}

void myfun2(TA &ta) {
    ta.mData += 100;
}

void myfun3(unique_ptr<int> param_ptr) {
    *param_ptr += 100;
}

int main() {
    int main_thread_i = 10;
    int i_ta = 20;
    
    //cout << "main thread i addr: " << &main_thread_i << endl;
    //printf("main thread ta addr:%p\n",i_ta);
    cout << "main thread id:" << this_thread::get_id() << endl;

    //若使用隐式类型转换给线程传参后，使线程分离，则很可能在临时变量销毁之前，也无法完成构造
    //thread myThread(myfun,main_thread_i,i_ta);

    //若传递一个临时对象，则可完成构造和拷贝过程
    //thread myThread(myfun,main_thread_i,TA(i_ta));

    //使用std::ref()传递真引用
    // TA ta(i_ta);
    // cout << "content of ta:" << ta.mData << endl;
    // thread myThread(myfun2,std::ref(ta));


    //使用智能指针
    std::unique_ptr<int> uni_p(new int(15));
    thread myThread(myfun3,std::move(uni_p));

    sleep(1);

    //cout << "after run thread,content of ta:" << ta.mData << endl;
    cout << "main thread end!" << endl;
    return 0;
    
}

//线程传参总结：
//1.若传递int这种内建简单数据类型，建议使用值传递，而不是引用传递，避免节外生枝
//2.如果传递类对象，建议避免使用隐式类型转换。全部在创建线程这一行就构建出临时对象，然后在函数参数里，使用引用来接（避免多次拷贝）
//3.使用隐式类型转换，对象会在子线程构建，使用临时对象，对象会在子线程构建
//4.如果向传递真引用到线程，则需要使用std::ref()函数