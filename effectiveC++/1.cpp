// 条款１：尽量使用const和inline而不是#define

// define一般在两种情况下使用：1.定义一个常量２.定义一个简单函数
// 对于define上面的两个作用，都有缺陷，所以使用const和inline来替换define能够提高代码的质量
#include <iostream>
using namespace std;

#define MAX 100;
// const并没有在编译的时候分配内存，而是存储在常量表里面
const int N = 100;
// 为M分配了内存空间
int M = 10;

template<class T>
// 注意这里是不能够传入const T的，否则报错
inline int fun(T& a, T& b) {
    return a > b ? a: b;
}

int main() {
    //  MAX在实际使用的时候只是进行了替换，本身并不占用内存空间，所以需要声明一个变量
    int a = MAX;
    // 这里输出的size是４,一般来说常量会尽量避免分配空间，但是因为这里要将N输出，所以就为其分配了空间
    // 这里的输出并不能代表const常量都是有分配内存空间的
    cout << sizeof(N) << endl;
    cout << a << endl;

    // 从常量表中取出N的值并且赋给k
    int k = N;
    // 从M的内存空间中取出数值赋值给s,注意上下两者的不同
    int s = M;
    cout << fun(k,s) << endl;
    return 0;
}
// 对于define定义的函数，在直接进行替换的时候其运行结果取决于传入的参数，很可能出现各种不同的结果错误
// 例如,#define max(a, b) ((a) > (b) ? (a) : (b))
// 如果是要使用#define的可以直接进行替换的功能的话，可以用inline函数进行代替