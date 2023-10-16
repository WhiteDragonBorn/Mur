#pragma once
#include <ctime>
#include <iostream>
#include <vector>

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
Tlist findPlace(const Tlist&, const datatype);
Tlist createByOrder(const datatype);

// HomeWork_1
void betweenZeros(const Tlist&);  // done

inline bool isOdd(const datatype&);
void deleteOddGroup(Tlist&);  // done

void deleteAllNegativeNums(Tlist&);  // done

// selection sort
void selListSort(const Tlist& head);
void swapListNodes(Tlist a, Tlist b);
bool isEqual(const Tlist& fHead, const Tlist& sHead);
bool isEqual(const Tlist& fHead, const Tlist& fEnd, const Tlist& sHead,
             const Tlist& sEnd);

// ƒ«
// 1) ѕомен€ть местами первый и последний элементы списка путем перестановки
// ссылок 2) ѕомен€ть местами макс и мин ссылками, они единственны 3) ѕроверить
// содержит ли один список другой список

void swapListEdges(Tlist& head);
void swapListExtremes(Tlist& head);
bool subListSearch(Tlist& f_list, Tlist& s_list);

// Ќаписать фукнцию, котора€ переставл€ет элементы в списке в обратном пор€дке
void reverseList(Tlist& head);
Tlist reversedList(Tlist head);

// за один проход списка вывести его середину (если четное количество, то перед
// серединой)
Tlist middleOfList(Tlist head);

// проверить €вл€етс€ ли он палиндромом
bool isListPalindrome(Tlist head);

// дз
// задача иосифа флави€: в кругу стоит 41 воин, убивают каждого третьего, куда
// надо встать чтобы отстатьс€ в живых 1) ¬ списке L периеставить в обратном
// пор€дке все элементы между первым и последним вхождением элемента E, если E
// входит в L не менее двух раз 2) ƒаны два упор€доченных по не убыванию списка,
// объединить эти списки в один, упор€доченный по неубыванию. использу€
// перестановку указателей