#include "box2d.h"


Box2D::Box2D(Point2D const & p1, Point2D const & p2)
  : m_p1(p1), m_p2(p2)
{}
Box2D::Box2D(Box2D const & obj)
  : m_p1(obj.m_p1), m_p2(obj.m_p2)
{}
Box2D::Box2D(float f1, float f2, float f3, float f4)
  : m_p1(f1,f2), m_p2(f3,f4)
{}

Point2D Box2D::p1() { return m_p1; }
Point2D Box2D::p2() { return m_p2; }

void Box2D::SetMin(Point2D const & point)
{
  if (point <<= m_p2) m_p1 = point;
}
void Box2D::SetMax(Point2D const & point)
{
  if (m_p1 <<= point) m_p2 = point;
}

// Оператор логического равенства.
bool Box2D::operator == (Box2D const & obj) const
{
  return (m_p1 == obj.m_p1) && (m_p2 == obj.m_p2);
}

// Оператор присваивания.
Box2D & Box2D::operator = (Box2D const & obj)
{
  if (this == &obj) return *this;
  m_p1 = obj.m_p1;
  m_p2 = obj.m_p2;
  return *this;
}

// Оператор логического неравенства.
bool Box2D::operator != (Box2D const & obj) const
{
  return !Box2D::operator == (obj);
}

// Переопределение оператора [].
Point2D Box2D::operator [] (unsigned int index) const
{
  if (index >= 2) return { 0.0f, 0.0f };
  return index == 0 ? m_p1 : m_p2;
}

// Оператор проверки пересечения
bool Box2D::operator % (Box2D const & obj)
{
  if (m_p2.x() < obj.m_p1.x()) return false;
  if (m_p1.x() > obj.m_p2.x()) return false;
  if (m_p2.y() < obj.m_p1.y()) return false;
  if (m_p1.y() > obj.m_p2.y()) return false;
  return true;
}
