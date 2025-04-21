#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = nullptr;
}

void StudentRoll::insertAtTail(const Student &s) {
  Student *studentCopy = new Student(s);
  Node *newNode = new Node{studentCopy, nullptr};

  if (tail == nullptr) {
    head = tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
}

std::string StudentRoll::toString() const {
  std::string result = "[";
  Node *curr = head;
  while (curr != nullptr) {
    result += curr->s->toString();
    if (curr->next != nullptr)
      result += ",";
    curr = curr->next;
  }
  result += "]";
  return result;
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  head = tail = nullptr;
  for (Node *curr = orig.head; curr != nullptr; curr = curr->next) {
    insertAtTail(*(curr->s));
  }
}

StudentRoll::~StudentRoll() {
  Node *curr = head;
  while (curr != nullptr) {
    Node *next = curr->next;
    delete curr->s;
    delete curr;
    curr = next;
  }
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...
  Node *curr = head;
  while (curr != nullptr) {
    Node *next = curr->next;
    delete curr->s;
    delete curr;
    curr = next;
  }

  head = tail = nullptr;

  for (Node *r = right.head; r != nullptr; r = r->next) {
    insertAtTail(*(r->s));
  }

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}





