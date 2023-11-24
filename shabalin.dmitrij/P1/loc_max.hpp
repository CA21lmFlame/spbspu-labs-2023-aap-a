#ifndef LOC_MAX_HPP
#define LOC_MAX_HPP
#include <cstddef>
namespace shabalin
{
  class LocMax
  {
  public:
    LocMax();
    void operator()(long long Number);
    size_t operator()() const;
  private:
    long long firstNumber_;
    long long secondNumber_;
    size_t count_;
  };
}
#endif
