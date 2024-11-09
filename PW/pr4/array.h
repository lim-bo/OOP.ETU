#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include "number.h"
#include "math.h"
#include "algorithm"
class Array
{
    number* values;
    unsigned len;
public:
    Array();
    Array(unsigned);
    ~Array();
    Array(const Array&);

    number mean() const;
    number standartDeviation();
    bool setAt(unsigned, number);
    void sort(bool);
    void resize(unsigned);
    number get(unsigned) const;
    unsigned size() const;

    friend std::ostream& operator << (std::ostream&, const Array&);
    Array& operator= (const Array&);
};

#endif // ARRAY_H

