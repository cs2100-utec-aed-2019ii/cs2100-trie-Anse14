#include "./trie.hpp"
int main()
{
  Trie a;
  a.insert("OWO");
  a.insert("AWO");
  a.insert("UWO");
  a.insert("UWU");
  cout << a.search_by_complete_word("OWO") << endl;
  a.delet("OW");
  cout << a.search_by_prefix("OW") << endl;
  a.print();
  return 0;
}
