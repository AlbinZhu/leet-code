/*
 * @author:      Swing
 * @create:      2019-12-19 16:44
 * @description: entrance
 */

#include <iostream>
#include "two_sum.cpp"

using namespace std;
int main() {
    cout << "Hello World!" << endl;

    // TODO: code here.

    int nums[] =  {2, 11, 15, 7};
    int numSize = 4;
    int target = 9;

    int *indices = twoSum(nums, numSize, target);

    cout << indices << endl;

    return 0;
}