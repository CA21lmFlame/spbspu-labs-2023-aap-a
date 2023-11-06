#include <iostream>
#include <stdexcept>
#include "sequence_counter.hpp"
#include "pochtmax.hpp"
#include "piftriples_counter.hpp"

int main()
{
  int number = 0;
  using namespace chernov;
  int maxim = 0;
  int premaxim = 0;
  PifTriples_counter piftriples;
  SequenceCounter counter;
  do
  {
    std::cin >> number;
    if (!std::cin)
    {
      std::cerr << "Is not a sequence\n";
      return 1;
    }
    else if (number != 0)
    {
      try
      {
        counter(number);
        piftriples(number);
      }
      catch (const std::exception & e)
      {
        std::cerr << "Error: " << e.what() << "\n";
        return 2;
      }
      pochtmax(number, maxim, premaxim);
    }
  }
  while (number != 0);
  std::cout << piftriples() << "\n";

  if (maxim == 0 || premaxim == 0)
  {
    std::cerr << "Not enough numbers entered\n";
    return 2;
  }
  std::cout << premaxim << "\n";
  return 0;
}
