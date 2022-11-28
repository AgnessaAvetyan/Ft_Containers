#ifndef REMOVE_CONST_HPP
#define REMOVE_CONST_HPP

template <typename T>
struct remove_const
{ typedef T type; };

template <typename T>
struct remove_const<const T>
{ typedef T type; };

#endif // REMOVE_CONST_HPP