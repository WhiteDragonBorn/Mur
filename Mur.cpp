
#include <iostream>

#include "node.h"

int main() {
  Tlist Test = nullptr;
  addToHead(Test, 0);
  addToHead(Test, 11);
  addToHead(Test, -1);
  addToHead(Test, 0);
  addToHead(Test, 8);
  addToHead(Test, 9);
  addToHead(Test, 0);


  betweenZeros(Test);

  //Tlist beg = Test;
  /*while (beg != nullptr) {
    std::cout << beg->data << " " << beg->next << std::endl;
    beg = beg->next;
  }
  std::cout << searchList(Test, 12)->data << "  " << searchList(Test, 13)->data << std::endl;
  std::cout << sumList(Test) << std::endl;*/
}