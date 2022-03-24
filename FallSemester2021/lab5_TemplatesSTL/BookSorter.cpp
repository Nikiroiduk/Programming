#pragma once
#include "Book.h"

struct BookSorter {
    bool operator()(Book lhs, Book rhs) const
    {
        return lhs < rhs;
    }
};