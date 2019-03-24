#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <exception>
# include <algorithm>

template <typename T>
int easyfind(T & container, int target)
{
	typename T::const_iterator it;

	it = find(container.begin(), container.end(), target);
	if (it != container.end())
		return (1);
	throw std::exception();
} 

#endif