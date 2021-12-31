#pragma once
#include "Book.h"

struct BookFinder{
    BookFinder(int start, int end) {
        this->start = start;
        this->end = end;
    }
    bool operator()(Book b) const
    {
        return b.getYear() <= end && b.getYear() >= start;
    }
private:
    int start;
    int end;
};