#ifndef SEQUENCE_OPERATIONS_HPP
#define SEQUENCE_OPERATIONS_HPP

#include <algorithm>
#include <iterator>
#include <vector>

namespace erohin
{
  template< class T >
  T random(std::pair< T, T > range)
  {
    return (rand() % (range.second - range.first) + range.first);
  }

  template<>
  float random(std::pair< float, float > range)
  {
    return ((static_cast< float >(rand()) / RAND_MAX) * (range.second - range.first) + range.first);
  }

  template< class T, class Container >
  void generate_random(Container & cnt, size_t n)
  {
    std::vector< T > temp;
    for (size_t i = 0; i < n; ++i)
    {
      temp.push_back(random(std::make_pair(0, 100)));
    }
    cnt.assign(temp.begin(), temp.end());
  }
}

#endif
