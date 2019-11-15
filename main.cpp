#include "./trie.hpp"
#include <fstream>
int main()
{
  Trie a;
  ifstream val("ApellidosDeLaLibertad.txt");
  string value;
  while(val >> value)
  {
    a.insert(value);
  }
  a.printwords();
  val.close();
  return 0;
}
