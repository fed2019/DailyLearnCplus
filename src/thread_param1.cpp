/*** 
 * @Author: pfzhang
 * @E-mail: zhangpengfei@youibot.com
 * @Date: 2022-03-15 11:15:20
 * @LastEditors: pfzhang
 * @LastEditTime: 2022-03-15 11:47:23
 * @Description: Do not edit
 * @FilePath: /learning/src/thread_param_tip1.cpp
 */

#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <thread>

using namespace std;

void myfun(const int &i,char *str) {
    cout << "i content:" << i
         << ",i addr:" << &i << endl;
    printf("str addr:%p\n",str);
}

int main() {
    int main_thread_i = 10;
    char main_thread_str[] = "hello";
    
    cout << "main thread i addr: " << &main_thread_i << endl;
    printf("main thread str addr:%p\n",main_thread_str);

    //给线程函数以引用方式传参，实际会发生参数拷贝
    //给线程函数以指针方式传参，子线程的指针仍然指向同一个地址，所以在使用detach()进行线程分离时，注意变量的生命周期
    thread myThread(myfun,main_thread_i,main_thread_str);
    myThread.detach();

    sleep(1);
    cout << "main thread end!" << endl;
    return 0;
    
}