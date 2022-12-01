#ifndef REMOVE_CONST_HPP
#define REMOVE_CONST_HPP

template <typename T>
struct remove_const
{ typedef T type; };

template <typename T>
struct remove_const<const T>
{ typedef T type; };

template<bool B, class T, class F>
struct conditional
{ typedef F type; };

template <class T, class F>
struct conditional<true, T, F>
{ typedef T type; };
#endif // REMOVE_CONST_HPP