#ifndef __MODELS_VECTOR_2D_HPP
#define __MODELS_VECTOR_2D_HPP

class Vector2D {
  private:
    double x_;
    double y_;
  public:
    Vector2D(const double &x, const double &y);

    const double &x() const;
    const double &y() const;
    void set_x(const double &x);
    void set_y(const double &y);

    bool operator==(const Vector2D &vector) const;
    bool operator!=(const Vector2D &vector) const;
    Vector2D operator*(const double &scalar) const;
    void operator+=(const Vector2D &vector);
    void operator-=(const Vector2D &vector);
};

#endif // __MODELS_VECTOR_2D_HPP

