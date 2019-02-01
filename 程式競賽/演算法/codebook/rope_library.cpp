sgi官方介绍：http://www.sgi.com/tech/stl/Rope.html

虽然rope是在非标准库中的，但是在比赛中都没有限制它，据说NOI都没限制，所以ACM应该能用，记录下来

头文件：#include <ext/rope>

命名空间：using namespace __gnu_cxx;

只支持G++；

定义: rope<char> rp;

部分操作(几乎都是O(logn)的)：

push_back(x)：在末尾添加x (x是char)

insert(pos,x)：在pos插入x (x是字符串,x后面加个int参数可以只能x中插入几个)

erase(pos,x): 从pos开始删除x个

replace(pos,x): 从pos开始换成x(x是字符串,x后面加个int参数可以只能x中的前几个)

substr(pos,x)：提取pos开始x个

copy(x)：复制rope中所有内容到x字符串

at(x)/[x]：访问第x个元素

【实现可持久化(O(1)记录历史版本)】

rope<char> *his[maxn];
his[0]=new rope<char>();
his[i]=new rope<char>(*his[i-1]);
就可以实现可持久化了，每次new都是O(1)的，只复制了树根