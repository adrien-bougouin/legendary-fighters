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
};

#endif // __MODELS_VECTOR_2D_HPP

