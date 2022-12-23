#include <bits/stdc++.h>
#include "VectorClass.h"
using namespace std;
int main() {
    VectorClass<int> a(4);
    a.push_back(3);
    a.push_back(4);
    cout << a << endl;
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    a.push_back(8);
    a.push_back(10);
    a.push_back(11);
    cout << a << endl;
    a.pop_back();
    cout << a << endl;
    a.pop_back();
    cout << a << endl;
    a.clear();
    cout << a << endl;

    return 0;
}
