#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack<T>(void) {}
		MutantStack<T>(MutantStack const & src) { *this = src; }
		~MutantStack<T>(void) {}
		MutantStack const & operator=(MutantStack const & rhs) { *this = rhs; return *this; }

		bool 			empty(void) { return _stack.empty(); }
		size_t		 	size(void) { return _stack.size(); }
		T & 			top(void) { return _stack.front(); }
		void 			push(T elem) { _stack.push_front(elem); }
		void			pop(void) { _stack.pop_front(); }

		typedef typename std::list<T>::iterator iterator;

		iterator		begin(void) { return _stack.begin(); }
		iterator		end(void) { return _stack.end(); }

	private:
		std::list<T> _stack;
};

#endif