#include "span.hpp"

Span::Span(void) {}

Span::Span(unsigned int n)
{
	this->_v.reserve(n);
}

Span::Span(Span const & src)
{
	*this = src;
}

Span::~Span(void) {}

Span const & Span::operator=(Span const & rhs)
{
	this->_v.assign(rhs._v.begin(), rhs._v.end());
	return *this;
}

void Span::addNumber(int addNum)
{
	if (this->_v.capacity() > this->_v.size())
	{
		this->_v.push_back(addNum);
	}
	else
		throw SpanOverSizeException();
}

unsigned int Span::shortestSpan(void)
{
	if (this->_v.empty() == true || this->_v.size() == 1)
	{
		throw SpanNoContentException();
		std::cout << "short" << std::endl;
		return (0);
	}
	sort(this->_v.begin(), this->_v.end());
	return (this->_v.at(1) - this->_v.at(0));
}

unsigned int Span::longestSpan(void)
{
	if (this->_v.empty() == true || this->_v.size() == 1)
	{
		throw SpanNoContentException();
		std::cout << "long" << std::endl;
		return (0);
	}
	sort(this->_v.begin(), this->_v.end());
	return (this->_v.at(this->_v.size() - 1) - this->_v.at(0));
}

void Span::printContent(void)
{
	std::vector<int>::iterator it = this->_v.begin();

	for (; it != this->_v.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

Span::SpanOverSizeException::SpanOverSizeException(void) {}
Span::SpanOverSizeException::SpanOverSizeException(SpanOverSizeException const & src) { *this = src; }
Span::SpanOverSizeException::~SpanOverSizeException(void) throw() {}
Span::SpanOverSizeException const &Span::SpanOverSizeException::operator=(SpanOverSizeException const & rhs) { (void)rhs; return *this; }
const char* Span::SpanOverSizeException::what() const throw()
{
	return "Span Over Size";
}

Span::SpanNoContentException::SpanNoContentException(void) {}
Span::SpanNoContentException::SpanNoContentException(SpanNoContentException const & src) { *this = src; }
Span::SpanNoContentException::~SpanNoContentException(void) throw() {}
Span::SpanNoContentException const &Span::SpanNoContentException::operator=(SpanNoContentException const & rhs) { (void)rhs; return *this; }
const char* Span::SpanNoContentException::what() const throw()
{
	return "Span No Content";
}