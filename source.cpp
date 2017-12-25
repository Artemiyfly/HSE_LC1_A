#include <iostream>

using namespace std;

template <typename T>
struct SingleLinkedList {
  struct Node {
    T value;
    Node *nxt = nullptr;
  };
  Node *first = nullptr, *last = nullptr;
  void push_back(T value) {
    if(last) {
      last = (last->nxt) = new Node();
    } else {
      first = last = new Node();
    }
    last->value = value;
  }
  void push_back(Node *n) {
    //cout << "PUSHING " << n->v << endl;
    if(last) {
      last->nxt = n;
    } else {
      first = n;
    }
    last = n;
    //cout << "done" << endl;
  }
  void append(SingleLinkedList<T>& b) {
    if(!b.last)
      return;
    if(last) {
      last->nxt = b.first;
    } else {
      first = b.first;
    }
    last = b.last;
    b.first = b.last = nullptr;
  }
  Node *pop_front() {
    Node *res = first;
    if(first == last)
      last = nullptr;
    first = first->nxt;
    res->nxt = nullptr;
    return res;
  }
  void sort() {
    if(first == last)
      return;
    SingleLinkedList<T> lower, pivot, higher;
    pivot.push_back(pop_front());
    while(first) {
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
  void print() {
    for(auto i = first; i != nullptr; i = i->nxt) {
      cout << i->value << ' ';
    }
    cout << "\n";
  }
};

int main() {
  int n, current;
  SingleLinkedList<int> l;
  cin >> n;
  while(n--) {
    cin >> current;
    l.push_back(current);
  }
  l.sort();
  l.print();
  return 0;
}
