#include "number.h"

number num_sqrt(number val) {
	return static_cast<number>(sqrt(static_cast<double>(val)));
}