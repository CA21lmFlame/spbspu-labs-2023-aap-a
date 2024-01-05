#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "base-types.hpp"
#include "shape.hpp"
class Rectangle: public Shape
{
public:
  Rectangle(point_t fp,point_t sp);
  virtual double getArea() const;
  virtual rectangle_t getFrameRect();
  virtual void move(const point_t point);
  virtual void move(const double delX, const double delY);
  virtual void scale(const double k);
  // void getData() const;
  virtual ~Rectangle();
private:
  point_t pointRightUp_;
  point_t pointLeftDown_;
  point_t midpoint_;
};
#endif
