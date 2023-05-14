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
  int length = 0; // длина поезда
  Cage *currentCage = first;
  do {
    length++;
    currentCage = currentCage->next;
  } while (currentCage != first);
  return length;
}
int Train::getOpCount() {
  return countOp;
}
