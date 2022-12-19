#ifndef IS_CONST_HPP
#define IS_CONST_HPP


namespace   ft
{
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

    template <bool B, class T = void, class U = void >
	struct conditional {};

	template <class T, class U>
	struct conditional<true, T, U> { typedef T type; };

	template <class T, class U>
	struct conditional<false, T, U> { typedef U type; };

    template <class T, class U>
	struct is_same { static const bool value = false; };

	template <class T>
	struct is_same<T, T> { static const bool value = true; };
} // namespace ft

#endif // IS_CONST_HPP