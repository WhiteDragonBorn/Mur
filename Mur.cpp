
#include <iostream>

#include "node.h"

int main() {
  Tlist TestZeros = nullptr;
  addToHead(TestZeros, 0);
  addToHead(TestZeros, 11);
  addToHead(TestZeros, -1);
  addToHead(TestZeros, 0);
  addToHead(TestZeros, 8);
  addToHead(TestZeros, 9);
  addToHead(TestZeros, 0);

  printList(TestZeros);
  std::cout << std::endl;
  betweenZeros(TestZeros);
  std::cout << std::endl;

  Tlist TestNegative = nullptr;
  addToHead(TestNegative, -1);
  addToHead(TestNegative, -1);
  addToHead(TestNegative, 3);
  addToHead(TestNegative, -1);
  addToHead(TestNegative, -1);
  addToHead(TestNegative, 2);
  addToHead(TestNegative, -1);
  addToHead(TestNegative, 1);
  addToHead(TestNegative, 0);
  addToHead(TestNegative, -1);
  addToHead(TestNegative, -1);

  printList(TestNegative);
  std::cout << std::endl;
  deleteAllNegativeNums(TestNegative);
  printList(TestNegative);
  std::cout << std::endl;

  Tlist TestOdd = nullptr;
  addToHead(TestOdd, 1);
  addToHead(TestOdd, 2);
  addToHead(TestOdd, 1);
  addToHead(TestOdd, 1);
  printList(TestOdd);
  std::cout << std::endl;
  deleteOddGroup(TestOdd);
  printList(TestOdd);

  //Tlist beg = Test;
  /*while (beg != nullptr) {
    std::cout << beg->data << " " << beg->next << std::endl;
    beg = beg->next;
  }
  std::cout << searchList(Test, 12)->data << "  " << searchList(Test, 13)->data << std::endl;
  std::cout << sumList(Test) << std::endl;*/
}