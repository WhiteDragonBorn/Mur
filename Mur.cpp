
#include <iostream>

#include "node.h"

using std::endl;
using std::cout;

int main() {
  srand(time(NULL));
  /*
  // ------------------------ FIRST LAB
  Tlist TestZeros = nullptr;
  std::vector<datatype> TZ_1{0, 9, 8, 0, -1, 11, 0};
  std::vector<datatype> TZ_2{0, 9, 8, -1, 11, 0, 0};
  std::vector<datatype> TZ_3{9, 8, 0, -1, 0, 11, 0, 1};

  createFromSeries(TestZeros, TZ_1);
  printList(TestZeros);
  std::cout << std::endl;
  betweenZeros(TestZeros);
  std::cout << std::endl << std::endl;

  createFromSeries(TestZeros, TZ_2);
  printList(TestZeros);
  std::cout << std::endl;
  betweenZeros(TestZeros);
  std::cout << std::endl << std::endl;

  createFromSeries(TestZeros, TZ_3);
  printList(TestZeros);
  std::cout << std::endl;
  betweenZeros(TestZeros);
  std::cout << std::endl;

  std::cout << std::endl << std::endl << std::endl;
  std::cout << "-----------------------------------" << std::endl;
  // ------------------------ FIRST LAB END

  // ------------------------ SECOND LAB
  Tlist TestOdd = nullptr;
  std::vector<datatype> TO_1{1, 1, 1, 1, 2};
  std::vector<datatype> TO_2{1, 2, 1, 2, 1, 2, 1};
  std::vector<datatype> TO_3{1, 2, 1, 1, 2, 1, 1, 1};
  std::vector<datatype> TO_4{1, 2, 1, 2, 1, 1, 1};

  createFromSeries(TestOdd, TO_1);
  printList(TestOdd);
  std::cout << std::endl;
  deleteOddGroup(TestOdd);
  printList(TestOdd);
  std::cout << std::endl << std::endl;

  createFromSeries(TestOdd, TO_2);
  printList(TestOdd);
  std::cout << std::endl;
  deleteOddGroup(TestOdd);
  printList(TestOdd);
  std::cout << std::endl << std::endl;

  createFromSeries(TestOdd, TO_3);
  printList(TestOdd);
  std::cout << std::endl;
  deleteOddGroup(TestOdd);
  printList(TestOdd);
  std::cout << std::endl << std::endl;

  createFromSeries(TestOdd, TO_4);
  printList(TestOdd);
  std::cout << std::endl;
  deleteOddGroup(TestOdd);
  printList(TestOdd);
  std::cout << std::endl;

  std::cout << std::endl << std::endl << std::endl;
  std::cout << "-----------------------------------" << std::endl;
  // ------------------------ SECOND LAB END

  // ------------------------ THIRD LAB
  Tlist TestNegative = nullptr;
  std::vector<datatype> TN_1{-1, -2, -3, 3, 2, 1, -1, 0};
  std::vector<datatype> TN_2{-1, 0, -1};
  std::vector<datatype> TN_3{-1};

  createFromSeries(TestNegative, TN_1);
  printList(TestNegative);
  std::cout << std::endl;
  deleteAllNegativeNums(TestNegative);
  printList(TestNegative);
  std::cout << std::endl << std::endl;

  createFromSeries(TestNegative, TN_2);
  printList(TestNegative);
  std::cout << std::endl;
  deleteAllNegativeNums(TestNegative);
  printList(TestNegative);
  std::cout << std::endl << std::endl;

  createFromSeries(TestNegative, TN_3);
  printList(TestNegative);
  std::cout << std::endl;
  deleteAllNegativeNums(TestNegative);
  printList(TestNegative);
  std::cout << std::endl;

  std::cout << std::endl << std::endl << std::endl;
  std::cout << "-----------------------------------" << std::endl;
  // ------------------------ THIRD LAB END


  // ------------------------ OTHER TESTS
  Tlist listQueue = nullptr;
  Tlist listStack = nullptr;
  Tlist listOrder = nullptr;
  listQueue = createAsQueue(10);
  listStack = createAsStack(10);
  listOrder = createByOrder(10);
  std::cout << std::endl << "Queue: ";
  printList(listQueue);
  std::cout << std::endl;
  selListSort(listQueue);
  printList(listQueue);
  std::cout << std::endl << "Stack: ";
  printList(listStack);
  std::cout << std::endl << "Ordered: ";
  printList(listOrder);
  // ------------------------ OTHER TESTS END

  */

  Tlist TestNegative = nullptr;
  Tlist Test2 = nullptr;
  std::vector<datatype> TN_1{-3, -2, 3, 2, 4, 1};
  std::vector<datatype> TN_2{-3, -2, 3, 2, 3};
  std::vector<datatype> TN_3{-1};

  createFromSeries(TestNegative, TN_1);
  createFromSeries(Test2, TN_2);
  cout << subListSearch(Test2, TestNegative);

  //printList(TestNegative);
  //cout << endl;
  //swapListExtremes(TestNegative);
  //printList(TestNegative);

  //cout << endl;

  //createFromSeries(TestNegative, TN_2);
  //printList(TestNegative);
  //cout << endl;
  ////swapListEdges(TestNegative);
  //printList(TestNegative);
}