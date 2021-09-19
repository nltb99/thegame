//
//  Vector2D.hpp
//  CPP
//
//  Created by nltbao on 19/09/2021.
//

#ifndef Vector2D_h
#define Vector2D_h

template<typename T>
struct Vector2D {
    T x, y;
    
    Vector2D()
    {
        this->x = 0;
        this->y = 0;
    }
    
    Vector2D(T x, T y)
    {
        this->x = x;
        this->y = y;
    }
    
    // addition
    inline Vector2D<T> operator+(const Vector2D<T>& v2) const
    {
        return Vector2D<T>(x + v2.x, y + v2.y);
    }
    
    inline friend Vector2D<T> operator+=(const Vector2D<T>& v1, const Vector2D<T>& v2)
    {
        v1.x += v2.x;
        v1.y += v2.y;
        return v1;
    }
    
    // subtraction
    inline Vector2D<T> operator-(const Vector2D<T>& v2) const
    {
        return Vector2D<T>(x - v2.x, y - v2.y);
    }
    
    inline friend Vector2D<T> operator-=(const Vector2D<T>& v1, const Vector2D<T>& v2)
    {
        v1.x -= v2.x;
        v1.y -= v2.y;
        return v1;
    }
    
    // multiplication
    inline Vector2D<T> operator*(const T scalar) const
    {
        return Vector2D<T>(x * scalar, y * scalar);
    }
    
    // division
    inline Vector2D<T> operator/(const T d) const
    {
        return d != 0 ? Vector2D<T>(x / d, y / d) : Vector2D<T>();
    }
    
    // cout
    inline friend std::ostream& operator<<(std::ostream& stream, const Vector2D<T>& v)
    {
        stream << "(" << v.x << "," << v.y << ")";
        return stream;
    }
    
    inline Vector2D<T> initValue(const int x, const int y)
    {
        this->x = x;
        this->y = y;
        return *this;
    }

};

using Vector2I = Vector2D<int>;
//using Vector2U = Vector2D<unsigned, int>;

using Vector2F = Vector2D<float>;
using Vector2LF = Vector2D<double>;

#endif /* Vector2D_h */
