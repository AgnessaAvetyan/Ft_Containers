#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

namespace ft
{
    // template <class T>
    // struct is_integral { static const bool val = false; };

    // template <>
    // struct is_integral<bool>{ static const bool val = true; };

    // template <>
    // struct is_integral<char> { static const bool val = true; };

    // template <>
    // struct is_integral<char16_t> { static const bool val = true; };

    // template <>
    // struct is_integral<char32_t> { static const bool val = true; };

    // template <>
    // struct is_integral<wchar_t> { static const bool val = true; };

    // template <>
    // struct is_integral<signed char> { static const bool val = true; };

    // template <>
    // struct is_integral<short int> { static const bool val = true; };

    // template <>
    // struct is_integral<int> { static const bool val = true; };

    // template <>
    // struct is_integral<long int> { static const bool val = true; };

    // template <>
    // struct is_integral<long long int> { static const bool val = true; };

    // template <>
    // struct is_integral<unsigned char> { static const bool val = true; };
    
    // template <>
    // struct is_integral<unsigned short int> { static const bool val = true; };
    
    // template <>
    // struct is_integral<unsigned int> { static const bool val = true; };

    // template <>
    // struct is_integral<unsigned long int> { static const bool val = true; };

    // template <>
    // struct is_integral<unsigned long long int> { static const bool val = true; };
    template<class T, bool val>
    struct integral_constant
    {
        static const bool value = val;
        typedef T                   value_type;
        typedef integral_constant   type;
        operator value_type() const { return value; }
    };

    template <class T>
    struct is_integral : public ft::integral_constant<T, false> {};

    template <>
    struct is_integral<bool> : public ft::integral_constant<bool, true>{  };

    template <>
    struct is_integral<char> : public ft::integral_constant<bool, true>{  };

    template <>
    struct is_integral<signed char> : public ft::integral_constant<bool, true>{  };

    template <>
    struct is_integral<short> : public ft::integral_constant<bool, true>{  };

    template <>
    struct is_integral<wchar_t> : public ft::integral_constant<bool, true>{  };

    template <>
    struct is_integral<char16_t> : public ft::integral_constant<bool, true>{  };

    template <>
    struct is_integral<int> : public ft::integral_constant<bool, true>{  };

    template <>
    struct is_integral<long> : public ft::integral_constant<bool, true>{  };

    template <>
    struct is_integral<long long> : public ft::integral_constant<bool, true>{  };

    template <>
    struct is_integral<unsigned char> : public ft::integral_constant<bool, true>{  };

    template <>
    struct is_integral<unsigned short> : public ft::integral_constant<bool, true>{  };

    template <>
    struct is_integral<unsigned int> : public ft::integral_constant<bool, true>{  };

    template <>
    struct is_integral<unsigned long> : public ft::integral_constant<bool, true>{  };

    template <>
    struct is_integral<unsigned long long> : public ft::integral_constant<bool, true>{  };
}

#endif //IS_INTEGRAL_HPP