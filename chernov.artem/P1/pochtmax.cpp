#include "pochtmax.hpp"

void pochtmax(int num, int& maxi, int& premaxi)
{
  if (num >= maxi)
  {
    premaxi = maxi;
    maxi = num;
  }
  else if (num >= premaxi)
  {
    premaxi = num;
  }
}
