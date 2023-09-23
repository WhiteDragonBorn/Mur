#include "node.h"

void addToHead(Tlist& head, const datatype& elem) {
  Tlist p = new Node;
  p->data = elem;
  p->next = head;
  head = p;
}

void addAfterNode(const Tlist& curNode, const datatype& elem) {
  Tlist p = new Node;
  p->data = elem;
  p->next = curNode->next;
  curNode->next = p;
}

void deleteFromHead(Tlist& head) {
  Tlist p = head;
  head = head->next;
  p->next = nullptr;
  delete p;
  p = nullptr;
}

void deleteAfterNode(const Tlist& curNode) {
  if (curNode->next != nullptr) {
    Tlist p = curNode->next;
    curNode->next = p->next;
    p->next = nullptr;
    delete p;
    p = nullptr;
  }
}

inline bool isEmpty(const Tlist& head) { return head == nullptr; }

void clearList(Tlist& head) {
  while (!isEmpty(head)) {
    deleteFromHead(head);
  }
}

Tlist searchList(const Tlist& head, const datatype& elem) {
  Tlist p = head;
  Tlist res = nullptr;
  while (p != nullptr && res == nullptr) {
    if (p->data == elem) {
      res = p;
    } else {
      p = p->next;
    }
  }
  return res;
}

datatype sumList(const Tlist& head) {
  datatype toReturn = -1;
  if (!isEmpty(head)) {
    toReturn = head->data;
    Tlist p = head->next;
    while (p != nullptr) {
      toReturn += p->data;
      p = p->next;
    }
  }
  return toReturn;
}

// [begin, end]
void printList(const Tlist& begin, const Tlist& end) {
  Tlist p = begin;
  while (p != end->next) {
    std::cout << p->data << " ";
    p = p->next;
  }
}

void printList(const Tlist& head) {
  Tlist p = head;
  while (p != nullptr) {
    std::cout << p->data << " ";
    p = p->next;
  }
}

// void createAsStack(Tlist& , const datatype );
// void createAsQueue(Tlist& , const datatype );
// Tlist findPlace(const Tlist&, const datatype);
// void createByOrder(Tlist& , const datatype );

void betweenZeros(const Tlist& head) {
  if (!isEmpty(head)) {
    Tlist p = head;
    Tlist fZero = nullptr;
    Tlist sZero = nullptr;
    fZero = searchList(head, 0);
    if (fZero != nullptr) {
      sZero = searchList(fZero->next, 0);
      if (sZero == nullptr) {
        std::cout << "Not enough zeros found.";
      } else {
        printList(fZero, sZero);
      }
    } else {
      std::cout << "Not enough zeros found.";
    }
  } else {
    std::cout << "Empty list.";
  }
}

void deleteOddGroup(Tlist& head) {
  Tlist p = head;
  //Tlist h = head->next;
  Tlist beginOdd = nullptr;
  Tlist endOdd = nullptr;

  while (p != nullptr) {
    if (p->data % 2 != 0) {
      Tlist h = p->next;
      bool flag = false;
      while (h->data % 2 != 0) {
        flag = true;
        h = h->next;
      }
    }


    p = p->next;
  }
}

void deleteAllNegativeNums(Tlist& head) {
  if (!isEmpty(head)) {
    while (head->data < 0) deleteFromHead(head);
    Tlist p = head;
    while (p != nullptr) {
      while (p->next != nullptr && p->next->data < 0) deleteAfterNode(p);
      p = p->next;
    }
  } else {
    std::cout << "Empty list.";
  }
}