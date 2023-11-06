#include <limits>
#include <stdexcept>
#include "piftriples_counter.hpp"

chernov::PifTriples_counter::PifTriples_counter():
  piftriples_(0),
  perv_el_(0),
  vtor_el_(0)
{}

void chernov::PifTriples_counter::operator()(int number)
{
  if (PifTriple(number) == 1 && perv_el_ != 0 && vtor_el_ != 0)
  {
    size_t max_size = std::numeric_limits< size_t >::max();
    if (piftriples_ == max_size)
    {
      throw std::logic_error("Sequence is too long");
    }
    ++piftriples_;
  }
  perv_el_ = vtor_el_;
  vtor_el_ = number;
}

int chernov::PifTriples_counter::PifTriple(int number)
{
  int a = perv_el_;
  int b = vtor_el_;
  int c = number;
  if ((a * a + b * b) == c * c)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

size_t chernov::PifTriples_counter::operator()() const
{
  return piftriples_;
}
