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

// ��
// 1) �������� ������� ������ � ��������� �������� ������ ����� ������������
// ������ 2) �������� ������� ���� � ��� ��������, ��� ����������� 3) ���������
// �������� �� ���� ������ ������ ������

void swapListEdges(Tlist& head);
void swapListExtremes(Tlist& head);
bool subListSearch(Tlist& f_list, Tlist& s_list);

// �������� �������, ������� ������������ �������� � ������ � �������� �������
void reverseList(Tlist& head);
Tlist reversedList(Tlist head);

// �� ���� ������ ������ ������� ��� �������� (���� ������ ����������, �� �����
// ���������)
Tlist middleOfList(Tlist head);

// ��������� �������� �� �� �����������
bool isListPalindrome(Tlist head);

// ��
// ������ ������ ������: � ����� ����� 41 ����, ������� ������� ��������, ����
// ���� ������ ����� ��������� � ����� 1) � ������ L ������������ � ��������
// ������� ��� �������� ����� ������ � ��������� ���������� �������� E, ���� E
// ������ � L �� ����� ���� ��� 2) ���� ��� ������������� �� �� �������� ������,
// ���������� ��� ������ � ����, ������������� �� ����������. ���������
// ������������ ����������