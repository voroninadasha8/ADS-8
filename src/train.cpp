// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() : countOp(0), first(nullptr) {}

void Train::addCage(bool light) {
    Cage* cage = new Cage;
    cage->light = light;
    cage->next = nullptr;
    cage->prev = nullptr;
    if (first == nullptr) {
        first = cage;
        first->next = cage;
        cage->prev = first;
    } else {
        cage->next = first->next;
        cage->prev = first;
        first->next->prev = cage;
        first->next = cage;
    }
}

int Train::getLength() {
    Cage* tmpCage = first;
    tmpCage->light = true;
    int count = 1;
    while (true) {
        tmpCage = tmpCage->next;
        if (tmpCage->light == false) {
            ++count;
            ++countOp;
        } else {
            ++countOp;
            tmpCage->light = false;
            for (int i = count; i > 0; --i) {
                tmpCage = tmpCage->prev;
                ++countOp;
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
