#ifndef SEQUENCE_VECTOR_H
#define SEQUENCE_VECTOR_H

#include "List.h"
#include <stdexcept>

class SequencePair
{
  std::string name;
  List< int > sequence;

  public:
    SequencePair() {}

    SequencePair(const std::string & name, const List< int >& sequence):
      name(name), sequence(sequence) {}

    const std::string & getName() const
    {
      return name;
    }

    const List< int >& getSequence() const
    {
      return sequence;
    }
};
