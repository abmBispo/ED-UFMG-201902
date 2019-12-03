#ifndef __WORD__
#define __WORD__
#include <string>
class Word {
private:
  int count;
  int leaves;
  std::string word;
public:
  Word(int count, str::string word);
  ~Word();
  LinkedList get_word();
};
#endif
