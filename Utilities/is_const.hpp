#ifndef IS_CONST_HPP
#define IS_CONST_HPP

template <typename T, bool constness>
struct is_const
{
    typedef T type;
};

template <typename T>
struct is_const<T, true>
{
    typedef const T type;
};


#endif // IS_CONST_HPP