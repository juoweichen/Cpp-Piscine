#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iostream>

class Span
{
	public:
		Span(void);
		Span(unsigned int n);
		Span(Span const & src);
		~Span(void);

		Span const &operator=(Span const & rhs);

		void addNumber(int addNum);
		unsigned int shortestSpan(void);
		unsigned int longestSpan(void);

		void printContent(void);

		class SpanOverSizeException : public std::exception
		{
			public: 
				SpanOverSizeException(void);
				SpanOverSizeException(SpanOverSizeException const & src);
				virtual ~SpanOverSizeException(void) throw();
				SpanOverSizeException const &operator=(SpanOverSizeException const & rhs);
				virtual const char* what() const throw();
		};

		class SpanNoContentException : public std::exception
		{
			public:
				SpanNoContentException(void);
				SpanNoContentException(SpanNoContentException const & src);
				virtual ~SpanNoContentException(void) throw();
				SpanNoContentException const &operator=(SpanNoContentException const & rhs);
				virtual const char* what() const throw();
		};

	private:
		std::vector<int> _v;
};

#endif
