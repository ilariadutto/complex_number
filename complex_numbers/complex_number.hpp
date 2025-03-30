#pragma once


template<typename T> requires std::floating_point<T>
class complex_number
{	
	T a;
 	T b;

public:
/* Default constructor */
    complex_number() 
        : a(0), b(0)
    {}
	
	explicit complex_number(T r)
        : a(r), b(0)
    {
        std::cout << "converting constructor called" << std::endl;
    }



/* User-defined constructor */
	complex_number(T r, T i)
        : a(r), b(i)
    {}


	T rea(void) const {
        return a;
    }

	T ima(void) const {
        return b;
    }
    
	
	complex_number<T> conj(void) const {
		return complex_number(a,-b);
	}

// Overload dell'operatore += 
	complex_number& operator+=(const complex_number& other) {
        T u = a;
        T v = b;
        T w = other.a;
        T z = other.b;
        a = u + w;
        b = v + z;
        return *this;
	}

/* Define operator+ in terms of operator +=. */
	complex_number operator+(const complex_number& other) const {
        complex_number ret = *this;
        ret += other;
        return ret;
    }
	
	complex_number& operator+=(const T& other) {
        a += other;
        return *this;
    }
	
	complex_number operator+(const T& other) const {
        complex_number ret = *this;
        ret += other;
        return ret;
    }
	
/* Overload dell'operatore *= */
	complex_number& operator*=(const complex_number& other) {
        T p = a;
        T q = b;
        T s = other.a;
        T t = other.b;
        a = p*s - q*t;
        b = p*t + q*s;
       
        return *this;
	}
	
/* Define operator* in terms of operator *=. */
	complex_number operator*(const complex_number& other) const {
        complex_number ret = *this;
        ret *= other;
        return ret;
    }
	

	complex_number& operator*=(const T& other) {
		a *=other;
		b *=other;
        return *this;
	}
	complex_number operator*(const T& other) const {
        complex_number ret = *this;
        ret *=other;
        return ret;
    }	


}; // end of complex class

double err = 1.0e-6;

/* Overload of <<, to make the complex printable. */
template<typename T>
std::ostream&
operator<<(std::ostream& os, const complex_number<T>& c) {

	if (abs(c.ima()) < err)
        os << c.rea();
    else if (abs(c.rea()) < err)
        os << c.ima() << "i";
    else if (c.ima() < -err)
        os << c.rea() << c.ima() << "i";
    else if (c.ima() > err)
        os << c.rea() << "+" << c.ima() << "i";
	return os;
}

