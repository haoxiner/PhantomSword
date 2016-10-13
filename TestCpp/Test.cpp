#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class A
{
public:
  const int v = 1;
};
class B
{
public:
  const int v = 2;
};
class C
{
public:
  const int v = 0;
};
template<class T>
T *fun()
{
  return new T;
}
template<>
A *fun<A>()
{
  return new A();
}
template<>
B *fun<B>()
{
  return new B();
}

int main()
{
  vector<uint64_t> v;
  cout << v.capacity() << endl;
  cout << sizeof(v) << endl;

  cout << fun<A>()->v << endl;
  cout << fun<B>()->v << endl;
  cout << fun<C>()->v << endl;

  cout << "NEW" << endl;
  vector<int> vec = {1,2,3,4,5,6,7,8,9};
  remove(vec.begin(), vec.end(), 9);
  for (auto v : vec)
  {
    cout << v << endl;
  }
  return 0;
}