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

// LIFO
Tlist createAsStack(const datatype num) {
  Tlist head = nullptr;
  for (datatype i = 1; i < num; ++i) {
    addToHead(head, i);
  }
  return head;
}

Tlist createAsQueue(const datatype num) {
  Tlist head = nullptr;
  Tlist moveN = nullptr;
  addToHead(head, 1);
  moveN = head;
  for (datatype i = 2; i < num; ++i) {
    addAfterNode(moveN, i);
    moveN = moveN->next;
  }
  return head;
}

Tlist findPlace(const Tlist& head, const datatype value) {
  Tlist p = head;
  Tlist toReturn = nullptr;

  if (p->data > value) {
    return toReturn;
  }

  while (toReturn == nullptr && p != nullptr) {
    if (p->next == nullptr || p->next->data > value) {
      toReturn = p;
    }
    p = p->next;
  }
  return toReturn;
}

Tlist createByOrder(const datatype num) {
  Tlist head = nullptr;
  datatype temp = rand() % 99 + 1;
  addToHead(head, temp);
  for (int i = 1; i < num; ++i) {
    temp = rand() % 99 + 1;
    Tlist temp_p = findPlace(head, temp);
    if (temp_p == nullptr) {
      addToHead(head, temp);
    } else {
      addAfterNode(temp_p, temp);
    }
  }
  return head;
}

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

// не работает
void selListSort(const Tlist& head) {
  Tlist p = head;
  if (p == nullptr || p->next == nullptr) return;
  while (p->next->next != nullptr) {
    Tlist max = p;
    Tlist q = p->next;
    while (q != nullptr) {
      if (max->data < q->data) max->data = q->data;
      q = q->next;
    }
    if (p->data != max->data) {
      datatype temp = p->data;
      p->data = max->data;
      max->data = temp;
    }
    p = p->next;
  }
}

// разобрать
void swapListNodes(Tlist a, Tlist b) {
  a->data += b->data;
  b->data = a->data - b->data;
  a->data -= b->data;
}


bool isEqual(const Tlist& fHead, const Tlist& sHead) {
  Tlist pf = fHead;
  Tlist ps = sHead;
  if (pf == nullptr && ps == nullptr) {
    return true;
  }
  if (pf == nullptr || ps == nullptr) { // что?
    return false;
  }

  while (pf != nullptr && ps != nullptr) {
    if (pf->data != ps->data) return false;
    pf = pf->next;
    ps = ps->next;
  }
  return pf == ps;
}

void swapListEdges(Tlist& head) {
  if (head && head->next != nullptr) {  // размер > 1
    Tlist tail = nullptr;

    if (head->next->next == nullptr) {  // отдельный случай для размера == 2
      tail = head->next;
      tail->next = head;
      head->next = nullptr;
      head = tail;
      tail = nullptr;
      return;
    }

    Tlist prevTail = head;
    while (prevTail->next->next != nullptr) {
      prevTail = prevTail->next;  // находим предпоследнюю ноду
    }
    tail = prevTail->next;  // запоминаем последнюю ноду

    tail->next = head->next;
    head->next = nullptr;
    prevTail->next = head;
    head = tail;

    tail = nullptr;
    prevTail = nullptr;
  }
  else
    return;
}


void swapListExtremes(Tlist& head) {
  if (head && head->next && head->next->next) {
    Tlist min_(nullptr), max_(nullptr), prevMin(nullptr), prevMax(nullptr);

    Tlist p = head->next;
    Tlist pprev = head;

    // поиск максимального
    max_ = head;
    int max_i = head->data;
    while (p) {
      if (p->data > max_i) {
        max_i = p->data;
        prevMax = pprev;
        max_ = p;
      }
      p = p->next;
      pprev = pprev->next;
    }

    p = head->next;
    pprev = head;

    // поиск минимального
    min_ = head;
    int min_i = head->data;
    while (p) {
      if (p->data < min_i) {
        min_i = p->data;
        prevMin = pprev;
        min_ = p;
      }
      p = p->next;
      pprev = pprev->next;
    }

    if (max_ != head) {
      prevMax->next = min_;
    }
    else {
      head = min_;
    }

    if (prevMin !=
      nullptr) {  // не можем сделать (min_ != head) из-за строчки 365
      prevMin->next = max_;
    }
    else {
      head = max_;
    }

    Tlist temp = min_->next;
    min_->next = max_->next;
    max_->next = temp;

  }
  else {
    return;
  }
}

bool subListSearch(Tlist& f_list, Tlist& s_list) {
  Tlist p1 = f_list, p2 = s_list;

  if (f_list == nullptr || s_list == nullptr) return false;

  while (s_list != nullptr) {
    p2 = s_list;

    while (p1 != nullptr) {
      if (p2 == nullptr) {
        return false;
      }
      else if (p1->data == p2->data) {
        p1 = p1->next;
        p2 = p2->next;
      }
      else {
        break;
      }
    }
    if (p1 == nullptr) return true;

    p1 = f_list;

    s_list = s_list->next;
  }

  return false;
}