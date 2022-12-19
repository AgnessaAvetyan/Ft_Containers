#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <functional>
#include <iostream>
#include "reverse_iterator.hpp"
#include "enable_if.hpp"
#include "equal.hpp"
#include "is_const.hpp"
#include "lexicographical_compare.hpp"
#include "is_integral.hpp"
// #include "make_pair.hpp"
#include "pair.hpp"
#include "remove_const.hpp"

#define RED_     1
#define BLACK_   0
#define LEFT    0
#define RIGHT   1
#define NIL     NULL


template <typename Key, typename T, typename Compare = std::less<Key>,
              typename Allocator = std::allocator<std::pair<const Key, T> > > class map;

#endif // UTILITIES_HPP