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
  if (!isEmpty(head)) {
    Tlist p = head;
    while (p != nullptr) {
      std::cout << p->data << " ";
      p = p->next;
    }
  } else {
    std::cout << "Empty list.";
  }
}

void createFromSeries(Tlist& head, std::vector<datatype> vec) {
  if (vec.size() > 0) {
    clearList(head);
    addToHead(head, vec[0]);
    Tlist p = head;
    for (int i = 1; i < vec.size(); ++i) {
      addAfterNode(p, vec[i]);
      p = p->next;
    }
    p = nullptr;
  } else {
    std::cout << "Not enough elems.";
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

inline bool isOdd(const datatype& number) { return (int(number) % 2 != 0); }

void deleteOddGroup(Tlist& head) {
  if (!isEmpty(head) && head->next != nullptr) {
    Tlist p = head;
    // (beginOdd, endOdd)
    Tlist beginOdd = nullptr;
    Tlist endOdd = nullptr;

    if (isOdd(head->data) && isOdd(head->next->data)) {
      while (isOdd(head->data)) {
        deleteFromHead(head);
      }
    } else {
      bool flag = false;
      while (p->next != nullptr && !flag) {
        if (isOdd(p->next->data)) {
          beginOdd = p;
          Tlist h = p->next->next;
          while (h != nullptr && isOdd(h->data)) {
            flag = true;
            h = h->next;
          }
          endOdd = h;
        }
        p = p->next;
      }
      if (!flag) {
        std::cout << "No elements to delete." << std::endl;
      } else {
        while (beginOdd->next != endOdd) {
          deleteAfterNode(beginOdd);
        }
      }
    }
  } else {
    std::cout << "Empty list or no odd elements to delete.";
  }
}

// не обращайте внимание...
// std::cout << beginOdd->data << " - ";
// if (endOdd == nullptr) {
//   std::cout << endOdd << std::endl;
// }
// else {
//   std::cout << endOdd->data << std::endl;
// }
// std::cout << flag << std::endl;

void deleteAllNegativeNums(Tlist& head) {
  if (!isEmpty(head)) {
    while (head != nullptr && head->data < 0) deleteFromHead(head);
    Tlist p = head;
    while (p != nullptr) {
      while (p->next != nullptr && p->next->data < 0) deleteAfterNode(p);
      p = p->next;
    }
  } else {
    std::cout << "Empty list.";
  }
}