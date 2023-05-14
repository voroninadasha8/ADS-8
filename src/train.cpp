// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() : countOp(0), first(nullptr) {}
void Train::addCage(bool light) {
  Cage *newCage = new Cage;
  newCage->light = light;
  if (first == nullptr) {
    first = newCage;
    newCage->next = first;
    newCage->prev = first;
  } else {
    Cage *lastCage = first->prev;
    newCage->prev = lastCage;
    newCage->next = first;
    first->prev = newCage;
    lastCage->next = newCage;
  }
}
int Train::getLength() {
  Cage* tmpCage = first;
  tmpCage->light = true;
  int count = 1;
  while (true) {
    tmpCage = tmpCage->next;
    if (tmpCage->light == false) {
      count++;
      countOp++;
    } else {
      countOp++;
      tmpCage->light = false;
      for (int i = count; i > 0; i--) {
        tmpCage = tmpCage->prev;
        countOp++;
      }
      if (tmpCage->light == false)
        return count;
      count = 1;
    }
  }
}
int Train::getOpCount() {
  return countOp;
}
