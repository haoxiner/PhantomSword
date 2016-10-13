#include <iostream>
#include <vector>
using namespace std;
int main()
{
  vector<uint64_t> v;
  cout << v.capacity() << endl;
  cout << sizeof(v) << endl;
  return 0;
}