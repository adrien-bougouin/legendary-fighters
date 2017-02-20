#ifndef __MODELS_VECTOR_2D_HPP
#define __MODELS_VECTOR_2D_HPP

class Vector2D {
  private:
    double x_;
    double y_;

    // TODO void translate(const Vector2D &vector);
  public:
    Vector2D(const double &x, const double &y);

    const double &x() const;
    const double &y() const;
    void set_x(const double &x);
    void set_y(const double &y);

    // TODO operator* for scalar multiplication (const)
    // TODO += for vector translation
    // TODO -= for vector translation (with given vector * -1 first)
};

#endif // __MODELS_VECTOR_2D_HPP

