#ifndef OUTPUT_SHAPE_HPP
#define OUTPUT_SHAPE_HPP

#include <iosfwd>
#include "shape.hpp"

namespace erohin
{
  void outputShape(std::ostream& output, const Shape* const* shape, size_t size);
}

#endif
