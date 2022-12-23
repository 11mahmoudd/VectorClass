#include "VectorClass.h"

#include <iostream>

using namespace std;

int main()
{
//    int *ptr = new int [10] {0,1,2,3,4,5,6,7,8,9};
    VectorClass <int> v(5);
    v.push_back(5);
    v.push_back(2);
    v.push_back(1);
    cout<<v<<endl;
    cout<<v.size()<<endl;

    VectorClass <int> c=v;
//    cout<<c<<endl;
    c.push_back(8);
    cout<<c<<endl;
    cout<<c.size()<<endl;

    if(c<v)
    {
        cout<<5;
    }


}
