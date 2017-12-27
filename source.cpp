#include <iostream>

template <typename T>
class SingleLinkedList {
  struct Node {
    T value;
    Node *next = nullptr;
  };

  Node *first = nullptr, *last = nullptr;
 public:
  void push_back(T value) {
    if(last != nullptr) {
      last = (last->next) = new Node();
    } else {
      first = last = new Node();
    }
    last->value = value;
  }

  void push_back(Node *n) {
    if(last != nullptr) {
      last->next = n;
    } else {
      first = n;
    }
    last = n;
  }

  void append(SingleLinkedList<T>& b) {
    if(b.last == nullptr)
      return;
    if(last != nullptr) {
      last->next = b.first;
    } else {
      first = b.first;
    }
    last = b.last;
    b.first = nullptr;
    b.last = nullptr;
  }

  Node *pop_front() {
    Node *res = first;
    if(first == last)
      last = nullptr;
    first = first->next;
    res->next = nullptr;
    return res;
  }

  void sort() {
    if(first == last)
      return;
    SingleLinkedList<T> lower, pivot, higher;
    pivot.push_back(pop_front());
    while(first != nullptr) {
      if((first->value) == (pivot.first->value))
        pivot.push_back(pop_front());
      else if((first->value) > (pivot.first->value))
        higher.push_back(pop_front());
      else
        lower.push_back(pop_front());
    }
    lower.sort();
    higher.sort();
    append(lower);
    append(pivot);
    append(higher);
  }

  void print() const {
    for(auto i = first; i != nullptr; i = i->next) {
      std::cout << i->value << ' ';
    }
    std::cout << "\n";
  }
};

int main() {
  SingleLinkedList<int> l;
  size_t n = 0; // actually variable from the task
  std::cin >> n;
  while(n--) {
    int item; // initialization consist of reading
    std::cin >> item;
    l.push_back(item);
  }
  l.sort();
  l.print();
  return 0;
}
