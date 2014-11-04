#include <iostream>
using namespace std;


template<class T>
T sum (T a, T b)
{
    T result;
    result = a + b;
    return result;
}

// Now classes with members that use template parameters as types
template<class T>
class MyPair {
    T a, b;
  public:
    MyPair (T first, T second) {
        a=first; b=second;
        //values[0]=first, values[1]=second;
    }
    T getmax();
    //T a, b;
};

template <class T>
T MyPair<T>::getmax() {
    T retval;
    
    retval = a > b ? a : b;

    return retval;
}


int main() 
{
    int i=5, j=6, k;
    double f=2.0, g=0.5, h;
    k=sum<int>(i,j);
    h=sum<double>(f,g);
    cout << k << '\n';
    cout << h << '\n';

    cout << "Now for class templates" << endl;

    MyPair <int> myObj(100, 17);
    /* 
     * The next two lines can only run if MyPair::a and MyPair::b are
     * public
     */
    //cout << "MyPair.a = " << myObj.a << endl;
    //cout << "MyPair.b = " << myObj.b << endl;
    cout << "MyPair.getmax() = " << myObj.getmax() << endl;
    
    return 0;
}

