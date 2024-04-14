#include "data_types.hpp"
#include <stdexcept>

namestnikov::PartValue::PartValue():
  operand(0)
{}

namestnikov::PartValue::PartValue(long long number):
  operand(number)
{}

namestnikov::PartValue::PartValue(char symbol):
  operation(symbol)
{}
