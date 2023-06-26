# include <iostream>

using namespace std;

class Vector2 {
public:
    Vector2();
    Vector2(float x, float y);

    float GetX() const; 
    float GetY() const; 

    static Vector2 Sum(Vector2 a, Vector2 b) {
        return Vector2(a.x + b.x, a.y + b.y);
    }

    Vector2 Add(Vector2 rhs) {
        return Vector2(x + rhs.x, y + rhs.y);
    }

    Vector2 operator+(const Vector2 rhs) const;
    Vector2 operator-(const Vector2 rhs) const;
    Vector2 operator*(const float rhs) const;
    Vector2 operator/(const float rhs) const;
    float operator*(const Vector2 rhs) const;

private:
    float x;
    float y;

};

int main() {
    Vector2 a(2,3);
    Vector2 b(-1,4); 
    Vector2 c = a-b;
    Vector2 d = a* 1.6;
    Vector2 e = a/2;
    Vector2 f = a + b;
    float g = a * b;

    cout << a.GetX() << "," << a.GetY() << endl;
    cout << b.GetX() << "," << b.GetY() << endl;
    cout << c.GetX() << "," << c.GetY() << endl;
    cout << d.GetX() << "," << d.GetY() << endl;
    cout << e.GetX() << "," << e.GetY() << endl;
    cout << f.GetX() << "," << f.GetY() << endl;
    cout << f.GetX() << "," << f.GetY() << endl;
    cout << g << endl;
}

Vector2::Vector2() : x(0), y(0) {}
Vector2::Vector2(float x, float y) : x(x), y(y) {}
float Vector2::GetX() const {return x;}
float Vector2::GetY() const {return y;}

Vector2 Vector2::operator+(const Vector2 rhs) const {
    return Vector2(x + rhs.x, y + rhs.y);
    } 

Vector2 Vector2::operator-(const Vector2 rhs) const {
    return Vector2(x - rhs.x, y - rhs.y);
}

Vector2 Vector2::operator*(const float rhs) const {
    return Vector2(x*rhs, y*rhs);
}

Vector2 Vector2::operator/(const float rhs) const {
    return Vector2(x/rhs, y/rhs);
}

float Vector2::operator*(const Vector2 rhs) const {
    return x*rhs.x + y*rhs.y;
}