/*** 
 * @Author: pfzhang
 * @E-mail: zhangpengfei@youibot.com
 * @Date: 2022-03-14 18:23:56
 * @LastEditors: pfzhang
 * @LastEditTime: 2022-03-14 19:20:47
 * @Description: Do not edit
 * @FilePath: /learning/src/main.cpp
 */

#include <iostream>
#include <unistd.h>
#include <thread>

using namespace std;

class TA
{
public:
    void operator()(){
        cout << "child thread start!" << endl;
        sleep(1);
        cout << "child thread end!" << endl;
    }

    TA(int data) :mData(data) {
        cout << "constructor exec!" << endl;
    }

    TA(const TA &ta) {
        cout << "copy constructor exec!" << endl;
    }

    ~TA() {
        cout << "destructor exec!" << endl;
    }

    int getData() const {
        return mData;
    }

private:
    int mData;
};

int main(int argc, char **argv)
{
    int a = 10;
    TA ta(a);
    thread myThread(ta);
    myThread.detach();
    cout << "main thread end!" << endl;
    return 0;
}
