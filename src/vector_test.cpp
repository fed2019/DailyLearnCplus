/*** 
 * @Author: pfzhang
 * @E-mail: zhangpengfei@youibot.com
 * @Date: 2022-03-16 21:02:42
 * @LastEditors: pfzhang
 * @LastEditTime: 2022-03-16 21:29:36
 * @Description: Do not edit
 * @FilePath: /learning/src/vector_test.cpp
 */

#include <iostream>
#include <vector>

using namespace std;

class TA
{
public:
    TA() {
        cout << "constructor exec!" << endl;
    }

    TA(const TA &) {
        cout << "copy constructor exec!" << endl;
    }

    ~TA() {
        cout << "destructor exec!" << endl;
    }
};

int main() {
    TA *ta = new TA();
    std::vector<TA *> ta_lists;
    ta_lists.push_back(ta);
    for (auto iter = ta_lists.begin();iter != ta_lists.end(); ++iter) {
        delete *iter;
    }
    return 0;
}