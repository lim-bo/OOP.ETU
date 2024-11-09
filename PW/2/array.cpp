#include "array.h"

Array::Array() {
    len = 0;
    values = nullptr;
}

Array::Array(unsigned size) {
    values = new number[size];
    len = size;
}

bool Array::setAt(unsigned ind, number val) {
    // В случае выхода за пределы массива метод
    // будет возвращать ложь для обработки на слое выше
    if (ind >= len) return false;
    values[ind] = val;
    return true;
}

std::ostream& operator<< (std::ostream& out, const Array& arr) {
    for (unsigned i = 0; i < arr.len; i++) {
        out << arr.values[i] << " ";
    }
    return out;
}

number Array::mean() {
    number meanValue{};
    for (unsigned i = 0; i < len; i++) {
        meanValue += values[i];
    }
    return meanValue / len;
}

number Array::standartDeviation() {
    number meanValue = mean();
    number temp{};
    for (unsigned i = 0; i < len; i++) {
        temp += (values[i] - meanValue) * (values[i] - meanValue);
    }
    temp /= len - 1;
    temp = num_sqrt(temp);
    return temp;
}

void Array::sort(bool isAsc) {
    number temp;
    for (unsigned i = 0; i < len - 1; i++)
        for (unsigned j = 0;  j < len - i - 1; j++) {
            if (isAsc ? values[j] > values[j + 1] : values[j] < values[j+1]) {
                temp = values[j];
                values[j] = values[j+1];
                values[j+1] = temp;
            }

        }
}

void Array::resize(unsigned size) {
    number* newValues = new number[size];
    for (unsigned i = 0; i < size; i++) {
        if (i >= len)
            newValues[i] = number{};
        else
            newValues[i] = values[i];
    }
    // Если массив не инициализирован, просто присвоим ему новый размер
    if (values == nullptr) {
        values = newValues;
    } else {
        number* temp = values;
        values = newValues;
        delete[] temp;
    }
    len = size;
}

Array::~Array() {
    if (values != nullptr)
        delete[] values;
}

number Array::get(unsigned i) {
    return values[i];
}

Array& Array::operator=(const Array& rvalue) {
    number* temp = this->values;
    number* newValues = new number[rvalue.len];
    this->len = rvalue.len;
    for (unsigned i = 0; i < this->len; i++) {
        newValues[i] = rvalue.values[i];
    }
    this->values = newValues;
    delete[] temp;
    return *this;
}