#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <iostream>
# include <iomanip>
# include <ctime>
# include <cstdlib>
# include <string>

template <typename T>
class Array {

public:
	Array<T>( void ) : _n(0), _array(NULL)  {}
	Array<T>( unsigned int n ): _n(n), _array(new T[n]) {}
	Array<T>( Array const & src ) { *this = src; }

	Array<T>	&operator=( Array const & rhs) {
		_n = rhs._n;
		delete _array;
		_array = new T [rhs._n];
		for (unsigned int i = 0; i < _n; i++)
			_array[i] = rhs._array[i];
		return *this;
	}

	~Array<T>( void ) { delete [] _array; }

	T	&operator[](unsigned int i) {
		if (i >= _n)
			throw std::exception();
		return (_array[i]);
	}

	unsigned int	size( void ) { return _n; }

private:
	unsigned int	_n;
	T *			_array;
};


#endif