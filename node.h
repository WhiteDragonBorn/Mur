#pragma once
#include <iostream>
#include <vector>
#include <ctime>

typedef int datatype;

struct Node {
  datatype data;
  Node* next;
};

typedef Node* Tlist;

void addToHead(Tlist&, const datatype&);
void addAfterNode(const Tlist&, const datatype&);
void deleteFromHead(Tlist&);
void deleteAfterNode(const Tlist&);
inline bool isEmpty(const Tlist&);
void clearList(Tlist&);

Tlist searchList(const Tlist&, const datatype&);
datatype sumList(const Tlist&);
void printList(const Tlist&, const Tlist&);
void printList(const Tlist&);
void createFromSeries(Tlist&, std::vector<datatype>);
Tlist createAsStack(const datatype);
Tlist createAsQueue(const datatype);
Tlist findPlace(const Tlist& , const datatype);
Tlist createByOrder(const datatype);



// HomeWork_1
void betweenZeros(const Tlist&);  // done

inline bool isOdd(const datatype&);
void deleteOddGroup(Tlist&); // done

void deleteAllNegativeNums(Tlist&);  // done



void selListSort(const Tlist& head);
void swapListNodes(Tlist a, Tlist b);
bool isEqual(const Tlist&fHead, const Tlist &sHead);


// ДЗ
// 1) Поменять местами первый и последний элементы списка путем перестановки ссылок
// 2) Поменять местами макс и мин ссылками, они единственны
// 3) Проверить содержит ли один список другой список

// HomeWork_1
void swapListEdges(Tlist& head); // done
void swapListExtremes(Tlist& head); // done
bool subListSearch(Tlist& f_list, Tlist& s_list); // done

