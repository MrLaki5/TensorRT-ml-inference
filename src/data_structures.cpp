#include "data_structures.hpp"

#include <algorithm>

//===============================
// Point2D
//===============================
Point2D::Point2D() 
{
    _x = -1;
    _y = -1;
}

Point2D::Point2D(const int& x, const int& y)
{
    this->_x = x;
    this->_y = y;
}

int Point2D::getX() const
{
    return this->_x;
}

int Point2D::getY() const
{
    return this->_y;
}

void Point2D::setX(const int& x) 
{
    this->_x = x;
}

void Point2D::setY(const int& y) 
{
    this->_y = y;
}

//===============================
// Rect
//===============================
Rect::Rect()
{
    this->_top_left_corner = Point2D();
    this->_width = -1;
    this->_height = -1;
    this->_score = 0;
}

Rect::Rect(const int& x, const int& y, const int& width, const int& height, const float& score)
{
    this->_top_left_corner = Point2D(x, y);
    this->_width = width;
    this->_height = height;
    this->_score = score;
}

Rect::Rect(const Point2D& top_left_corner, const int& width, const int& height, const float& score)
{
    this->_top_left_corner = top_left_corner;
    this->_width = width;
    this->_height = height;
    this->_score = score;
}

Point2D Rect::getTopLeftCorner() const
{
    return this->_top_left_corner;
}

int Rect::getX() const
{
    return this->_top_left_corner.getX();
}

int Rect::getY() const
{
    return this->_top_left_corner.getY();
}

int Rect::getWidth() const
{
    return this->_width;
}

int Rect::getHeight() const
{
    return this->_height;
}

float Rect::getScore() const
{
    return this->_score;
}

void Rect::setTopLeftCorner(const Point2D& top_left_corner) 
{
    this->_top_left_corner = top_left_corner;
}

void Rect::setX(const int& x) 
{
    this->_top_left_corner.setX(x);
}

void Rect::setY(const int& y)
{
    this->_top_left_corner.setY(y);
}

void Rect::setWidth(const int& width)
{
    this->_width = width;
}

void Rect::setHeight(const int& height)
{
    this->_height = height;
}

void Rect::setScore(const float& score)
{
    this->_score = score;
}

float Rect::iou(const Rect& rect) const
{
    // Find intersection area coordinates
    float x_a = std::max(this->getX(), rect.getX());
    float y_a = std::max(this->getY(), rect.getY());
    float x_b = std::min(this->getX() + this->getWidth(), rect.getX() + rect.getWidth());
    float y_b = std::min(this->getY() + this->getHeight(), rect.getY() + rect.getHeight());

    // Calculate intersection area
    float inter_area = (std::max(0.f, x_b - x_a + 1)) * (std::max(0.f, y_b - y_a + 1));

    // Calculate rect areas
    float rect1_area = (this->getWidth() + 1) * (this->getHeight() + 1);
    float rect2_area = (rect.getWidth() + 1) * (rect.getHeight() + 1);

    // Calculate intersection over union
    float iou = inter_area / (rect1_area + rect2_area - inter_area);
    return iou;
}
