#include "stack/stack.hpp"
#include <iomanip>
#include <vector>
#include <stack>
// #include "tests/track/track_allocator.hpp"
// #define PRINT_FILE_LINE()                                                                          \
//     {                                                                                              \
//         std::cout << " (file: " << __FILE__ << ", line: " << __LINE__ << ")" << std::endl;         \
//     }

// #define PRINT_LINE(msg, value)                                                                     \
//     {                                                                                              \
//         std::cout << msg << " " << (value);                                                        \
//         PRINT_FILE_LINE();                                                                         \
//     }

// #define PRINT_MSG(msg)                                                                             \
//     {                                                                                              \
//         std::cout << msg;                                                                          \
//         PRINT_FILE_LINE();                                                                         \
//     }
// #define PRINT_SIZE(c)                                                                              \
//     {                                                                                              \
//         PRINT_LINE("Size:", c.size());                                                             \
//     }

// template <typename Iter>
// void print_range(Iter first, Iter last)
// {
//     for (Iter it = first; it != last; ++it) {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;
// }

// #define PRINT_VEC(vec)                                                                             \
//     {                                                                                              \
//         std::cout << "\nVector content:\n";                                                        \
//         print_range(vec.begin(), vec.end());                                                       \
//         std::cout << std::endl;                                                                    \
//     }

// #define PRINT_ALL(vec)                                                                             \
//     {                                                                                              \
//         PRINT_SIZE(vec);                                                                           \
//         PRINT_VEC(vec);                                                                            \
//     }

// #define CHECK_CAPACITY(vec)                                                                        \
//     {                                                                                              \
//         if (!(vec.capacity() >= vec.size())) {                                                     \
//             PRINT_MSG("Capacity is smaller than size");                                            \
//         } else {                                                                                   \
//             PRINT_MSG("Capacity Ok");                                                              \
//         }                                                                                          \
//     }

// #define CHECK_AND_PRINT_ALL(vec)                                                                   \
//     {                                                                                              \
//         CHECK_CAPACITY(vec);                                                                       \
//         PRINT_ALL(vec);                                                                            \
//     }

// typedef ft::vector<char, track_allocator<char> > charvector;

// void vec_test_assign()
// {
//     {
//         charvector v;

//         v.assign(0, 'c');

//         CHECK_AND_PRINT_ALL(v);

//         v.assign(64, 'A');

//         CHECK_AND_PRINT_ALL(v);

//         v.assign(32, '5');

//         CHECK_AND_PRINT_ALL(v);

//         v.assign(49, '8');

//         CHECK_AND_PRINT_ALL(v);

//         v.assign(77, '2');

//         CHECK_AND_PRINT_ALL(v);
//     }

//     // {
//     //     strvector v;

//     //     v.assign(0, "");

//     //     CHECK_AND_PRINT_ALL(v);

//     //     v.assign(64, "vector-string");

//     //     CHECK_AND_PRINT_ALL(v);
//     // }
// }








int main()
{
    {
        {
            std::vector<int> empty_vec;
            std::cout << std::endl << "\e[1m" <<"*-----------Empty Vector--------------------*" << "\e[0m" << std::endl;
            std::cout << "Empty Vector  size(): " << empty_vec.size() << std::endl;
            std::cout << "Empty Vector  max_size(): " << empty_vec.max_size() << std::endl;
            std::cout << "Empty Vector  capacity(): " << empty_vec.capacity() << std::endl;
            std::cout << "Empty Vector  empty(): " << empty_vec.empty() << std::endl;
            std::cout << "\e[1m" << "*-------------------------------------------*" << std::endl;
            ft::vector<std::string> ch_vec;
            ch_vec.assign(64, "vector-string");
            for (size_t i = 0; i < ch_vec.size(); i++)
                std::cout << "vector[" << i << "]= " << ch_vec[i] << " == vector.at("
                            << i << ")= " << ch_vec.at(i) << std::endl;
            std::vector<std::string> O_ch_vec;
            O_ch_vec.assign(64, "vector-string");
            for (size_t i = 0; i < O_ch_vec.size(); i++)
                std::cout << "or_vector[" << i << "]= " << O_ch_vec[i] << " == vector.at("
                            << i << ")= " << O_ch_vec.at(i) << std::endl;
        }
    }
}

//         {
//             std::cout << std::endl << "\e[1m" << "*-----------vector[5, 42, 15]---------------*" << "\e[0m" <<std::endl;
//             ft::vector<int> vec;
//             vec.push_back(5);
//             vec.push_back(42);
//             vec.push_back(15);
//             for (size_t i = 0; i < vec.size(); i++)
//                 std::cout << "vector[" << i << "]= " << vec[i] << " == vector.at("
//                             << i << ")= " << vec.at(i) << std::endl;
//             std::cout << "vec.size(): " << vec.size() << std::endl;
//             // std::cout << "vec.max_size(): " << vec.max_size() << std::endl;
//             std::cout << "vec.capacity(): " << vec.capacity() << std::endl;
//             std::cout << "vec.empty(): " << vec.empty() << std::endl;
//             std::cout << "vec.front(): " << vec.front() << " (" << *(vec.begin()) << ")" << std::endl;
//             std::cout << "vec.back(): " << vec.back() << " (" << *(vec.end() - 1) << ")" << std::endl;    
//             ft::vector<int>::reverse_iterator b_it = vec.rbegin();
//             ft::vector<int>::reverse_iterator e_it = vec.rend();
//             int i = 0;
//             while (b_it != e_it)
//             {
//                 std::cout << "reverse_vector[" << i << "]= " << *b_it << " " << std::endl;
//                 b_it++;
//                 i++;
//             }
//             std::cout << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;
//         }

//         {
//             std::cout << std::endl << "\e[1m" << "*-----------------reserve-------------------*" << "\e[0m" <<std::endl;
//             ft::vector<int> empty_vec;
//             empty_vec.reserve(256);
//             std::cout << "Empty Vector reverse 256: " << empty_vec.capacity() << std::endl;
//             empty_vec.reserve(64);
//             std::cout << "Empty Vector reverse 64: " << empty_vec.capacity() << std::endl;
//             empty_vec.reserve(500);
//             std::cout << "Empty Vector reverse 500: " << empty_vec.capacity() << std::endl;
//             std::cout << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;
//         }

//         {
//             std::cout << std::endl << "\e[1m" << "*-----pop_back()---(r)begin()---(r)end------*" << "\e[0m" <<std::endl;
//             ft::vector<int> vec;
//             vec.push_back(5);
//             vec.push_back(15);
//             vec.push_back(25);
//             vec.pop_back();
//             for (size_t i = 0; i < vec.size(); i++)
//                 std::cout << "vector[" << i << "]= " << vec[i] << " == vector.at("
//                         << i << ")= " << vec.at(i) << std::endl;
//             ft::vector<int> vec2(vec);
//             std::cout << "vec.size(): " << vec.size() << std::endl;
//             std::cout << "vec.capacity(): " << vec.capacity() << std::endl;
//             for (size_t i = 0; i < vec2.size(); i++)
//                 std::cout << "copy_vector[" << i << "] = " << vec2[i] << " == copy_vector.at("
//                         << i << ") = " << vec2.at(i) << std::endl;
//             ft::vector<int>::reverse_iterator rbit = vec.rbegin();
//             ft::vector<int>::reverse_iterator reit = vec.rend();
//             int i = 1;
//             while (rbit != reit)
//                 std::cout << i++ << "->" << *rbit++ << std::endl;
//             ft::vector<int>::iterator b_it;
//             ft::vector<int>::iterator e_it;
//             b_it = vec.begin();
//             e_it = vec.end();
//             while (b_it != e_it)
//                 std::cout << *b_it++ << ",";
//             std::cout << std::endl << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;
//         }

//         {
//             std::cout << std::endl << "\e[1m" << "*---------swap/resize/reserve/clear---------*" << "\e[0m" <<std::endl;
//             ft::vector<int> vec;
//             vec.push_back(5);
//             vec.push_back(15);
//             vec.push_back(25);
//             vec.push_back(35);
//             vec.push_back(45);
//             ft::vector<int> vec1;
//             vec1.push_back(85);
//             vec1.push_back(105);
//             vec1.push_back(205);
//             vec1.push_back(305);
//             vec1.push_back(405);
//             // std::vector<int> origin_vec;
//             // origin_vec.push_back(5);
//             // origin_vec.push_back(15);
//             // origin_vec.push_back(25);
//             // origin_vec.push_back(35);
//             // origin_vec.push_back(45);
//             // std::cout << "origin Erase: " << *origin_vec.erase(origin_vec.end() - 1) << std::endl;
//             // for (size_t i = 0; i < origin_vec.size(); i++)
//             //     std::cout << "origin_vector[" << i << "]= " << origin_vec[i] << std::endl;
//             std::cout << "Erase: " << *vec.erase(vec.end() - 1) << std::endl;
//             std::cout << std::endl;
//             for (size_t i = 0; i < vec.size(); i++)
//                 std::cout << "vector[" << i << "]= " << vec[i] << std::endl;
//             vec.swap(vec1);
//             vec.resize(10, 100);
//             for (size_t i = 0; i < vec.size(); i++)
//                 std::cout << "resize_vector[" << i << "]= " << vec[i] << std::endl;
//             vec.reserve(30);
//             std::cout << std::endl << "resize_vec.size(): " << vec.size() << std::endl;
//             std::cout << "resize_vec.max_size(): " << vec.max_size() << std::endl;
//             std::cout << "resize_vec.capacity(): " << vec.capacity() << std::endl;
//             std::cout << std::endl;
//             ft::vector<int>::iterator bit = vec.begin() + 2;
//             ft::vector<int>::iterator eit = vec.end();
//             vec.erase(bit, eit);
//             for (size_t i = 0; i < vec.size(); i++)
//                 std::cout << "erase_iterator_vec[" << i << "]= " << vec[i] << std::endl;
//             vec.clear();
//             for (size_t i = 0; i < vec.size(); i++)
//                 std::cout << "clear_vector[" << i << "]= " << vec[i] << std::endl;
//             std::cout << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;
//         }
        
//         {
//             std::cout << std::endl << "\e[1m" << "*--------------------assign-----------------*" << "\e[0m" <<std::endl;
//             ft::vector<int> vec;
//             vec.assign(5, 42);
//             for (size_t i = 0; i < vec.size(); i++)
//                 std::cout << "vector[" << i << "]= " << vec[i] << std::endl;
//             std::cout << std::endl;
//             ft::vector<int> vec1;
//             vec1.assign(3, 45);
//             vec1.assign(vec.begin() + 2, vec.end());
//             for (size_t i = 0; i < vec1.size(); i++)
//                 std::cout << "vector[" << i << "]= " << vec1[i] << std::endl;
//             std::cout << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;
//         }

//         {
//             std::cout << std::endl << "\e[1m" << "*--------------------insert-----------------*" << "\e[0m" <<std::endl;
//             ft::vector<int> vec;
//             vec.push_back(15);
//             vec.push_back(25);
//             vec.insert(vec.begin(), 5, 4);
//             vec.insert(vec.begin(), 5);
//             vec.insert(vec.begin(), vec.begin(), vec.end());
//             for (size_t i = 0; i < vec.size(); i++)
//                 std::cout << "vector[" << i << "]= " << vec[i] << std::endl;
//             // std::vector<int> v;
//             // v.push_back(15);
//             // v.push_back(25);
//             // v.insert(v.begin(), 5, 4);
//             // v.insert(v.begin(), 5);
//             // v.insert(v.begin(), v.begin(), v.end());
//             // for (size_t i = 0; i < v.size(); i++)
//             //     std::cout << "vtor[" << i << "]= " << v[i] << std::endl;
//             std::cout << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;
//         }

//         {
//             std::cout << std::endl << "\e[1m" << "*----------------resize----------------*" << "\e[0m" <<std::endl;
//             ft::vector<int> vec;
//             vec.push_back(5);
//             vec.push_back(15);
//             vec.push_back(25);
//             vec.push_back(35);
//             vec.push_back(45);
//             // vec.resize(vec.max_size(), 45);
//             // vec.resize(-1, 100);
//             vec.resize(10, 100);
//             std::cout << "\e[1m" << "resize(10, 100) size: " << "\e[0m" << vec.size() << std::endl;
//             for (size_t i = 0; i < vec.size(); i++)
//                 std::cout << "resize_vector[" << i << "]= " << vec[i] << std::endl;
//             vec.resize(0);
//             std::cout << "\e[1m" << "resize(0) size: " << "\e[0m" << vec.size() << std::endl;
//             for (size_t i = 0; i < vec.size(); i++)
//                 std::cout << "resize_vector[" << i << "]= " << vec[i] << std::endl;
//             vec.resize(5);
//             std::cout << "\e[1m" << "resize(5) size: " << "\e[0m" << vec.size() << std::endl;
//             for (size_t i = 0; i < vec.size(); i++)
//                 std::cout << "resize_vector[" << i << "]= " << vec[i] << std::endl;
//             std::cout << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;
//         }

//         {
//             std::cout << std::endl << "\e[1m" << "*---------------Operators----------------*" << "\e[0m" <<std::endl;
//             ft::vector<int> vec;
//             vec.push_back(5);
//             vec.push_back(42);
//             ft::vector<int> vec1;
//             vec1.push_back(5);
//             vec1.push_back(42);
//             ft::vector<int> vec3;
//             vec3.push_back(5);
//             vec3.push_back(42);
//             vec3.push_back(43);
//             ft::vector<int> vec4;
//             vec4.push_back(99);
//             vec4.push_back(42);
//             vec4.push_back(43);
//             std::cout << "operator== " << (vec == vec1) << std::endl;
//             std::cout << "operator!= " << (vec != vec1) << std::endl;
//             std::cout << "operator<  " << (vec < vec1) << std::endl;
//             std::cout << "operator>  " << (vec > vec1) << std::endl;
//             std::cout << "operator<= " << (vec <= vec1) << std::endl;
//             std::cout << "operator>= " << (vec >= vec1) << std::endl;
//             std::cout << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;

//             std::cout << std::endl << "\e[1m" << "*---------------Operators----------------*" << "\e[0m" <<std::endl;
//             std::cout << "operator== " << (vec == vec3) << std::endl;
//             std::cout << "operator!= " << (vec != vec3) << std::endl;
//             std::cout << "operator<  " << (vec < vec3) << std::endl;
//             std::cout << "operator>  " << (vec > vec3) << std::endl;
//             std::cout << "operator<= " << (vec <= vec3) << std::endl;
//             std::cout << "operator>= " << (vec >= vec3) << std::endl;
//             std::cout << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;

//             std::cout << std::endl << "\e[1m" << "*---------------Operators----------------*" << "\e[0m" <<std::endl;
//             std::cout << "operator== " << (vec4 == vec) << std::endl;
//             std::cout << "operator!= " << (vec4 != vec) << std::endl;
//             std::cout << "operator<  " << (vec4 < vec) << std::endl;
//             std::cout << "operator>  " << (vec4 > vec) << std::endl;
//             std::cout << "operator<= " << (vec4 <= vec) << std::endl;
//             std::cout << "operator>= " << (vec4 >= vec) << std::endl;
//             std::cout << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;

//             // std::vector<int> v;
//             // std::vector<int> v1;
//             // std::vector<int> v3;
//             // std::vector<int> v4;
//             // v.push_back(5);
//             // v.push_back(42);
//             // v1.push_back(5);
//             // v1.push_back(42);
//             // v3.push_back(5);
//             // v3.push_back(42);
//             // v3.push_back(43);
//             // v4.push_back(99);
//             // v4.push_back(42);
//             // v4.push_back(43);

//             // std::cout << std::endl << "\e[1m" << "*---------------Original Operators----------------*" << "\e[0m" <<std::endl;
//             // std::cout << "operator== " << (v == v1) << std::endl;
//             // std::cout << "operator!= " << (v != v1) << std::endl;
//             // std::cout << "operator<  " << (v < v1) << std::endl;
//             // std::cout << "operator>  " << (v > v1) << std::endl;
//             // std::cout << "operator<= " << (v <= v1) << std::endl;
//             // std::cout << "operator>= " << (v >= v1) << std::endl;
//             // std::cout << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;

//             // std::cout << std::endl << "\e[1m" << "*---------------Original Operators----------------*" << "\e[0m" <<std::endl;
//             // std::cout << "operator== " << (v == v3) << std::endl;
//             // std::cout << "operator!= " << (v != v3) << std::endl;
//             // std::cout << "operator<  " << (v < v3) << std::endl;
//             // std::cout << "operator>  " << (v > v3) << std::endl;
//             // std::cout << "operator<= " << (v <= v3) << std::endl;
//             // std::cout << "operator>= " << (v >= v3) << std::endl;
//             // std::cout << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;

//             // std::cout << std::endl << "\e[1m" << "*---------------Original Operators----------------*" << "\e[0m" <<std::endl;
//             // std::cout << "operator== " << (v4 == v) << std::endl;
//             // std::cout << "operator!= " << (v4 != v) << std::endl;
//             // std::cout << "operator<  " << (v4 < v) << std::endl;
//             // std::cout << "operator>  " << (v4 > v) << std::endl;
//             // std::cout << "operator<= " << (v4 <= v) << std::endl;
//             // std::cout << "operator>= " << (v4 >= v) << std::endl;
//             // std::cout << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;
//         }
//     }

//     {
//         {
//             std::cout << std::endl << "\e[1m" << "*-----------------Empty stack------------------*" << "\e[0m" <<std::endl;
//             ft::stack<int> empty_stack;
//             std::cout << "Stack is empty: " << empty_stack.empty() << std::endl;
//             std::cout << "Empty stack size: " << empty_stack.size() << std::endl;
//             std::cout << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;
//         }
//         {
//             std::cout << std::endl << "\e[1m" << "*----------push/pop/top/size------------*" << "\e[0m" <<std::endl;
//             ft::stack<int> stack;
//             std::cout << "Stack size: " << stack.size() << std::endl;
//             stack.push(5);
//             std::cout << "Stack[5] top: " << stack.top() << std::endl;
//             std::cout << "Stack[5] size: " << stack.size() << std::endl;
//             stack.push(42);
//             std::cout << "Stack[5, 42] top: " << stack.top() << std::endl;
//             std::cout << "Stack[5, 42] size: " << stack.size() << std::endl;
//             stack.top() = 99;
//             std::cout << "Stack[5, 99] top: " << stack.top() << std::endl;
//             stack.pop();
//             std::cout << "Stack[5] size: " << stack.size() << std::endl;
//             stack.pop();
//             std::cout << "Stack size: " << stack.size() << std::endl;
//             std::cout << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;
//         }
//         {
//             std::cout << std::endl << "\e[1m" << "*----------Operators------------*" << "\e[0m" <<std::endl;
//             ft::stack<int> st1;
//             st1.push(5);
//             st1.push(42);
//             ft::stack<int> st2;
//             st2.push(5);
//             st2.push(42);
//             ft::stack<int> st3;
//             st3.push(5);
//             st3.push(42);
//             st3.push(43);
//             ft::stack<int> st4;
//             st4.push(99);
//             st4.push(5);
//             st4.push(42);

//             // std::cout << "stack1 size: " << st1.size() << std::endl;
//             // std::cout << "stack2 size: " << st2.size() << std::endl;

//             std::cout << "\e[1m" << "same stack:" << "\e[0m" << std::endl;
//             std::cout << "operator== " << (st1 == st2) << std::endl;
//             std::cout << "operator!= " << (st1 != st2) << std::endl;
//             std::cout << "operator<  " << (st1 < st2) << std::endl;
//             std::cout << "operator>  " << (st1 > st2) << std::endl;
//             std::cout << "operator<= " << (st1 <= st2) << std::endl;
//             std::cout << "operator>= " << (st1 >= st2) << std::endl;
//             std::cout << "\e[1m" << "lesser stack:" << "\e[0m" << std::endl;
//             std::cout << "operator== " << (st1 == st3) << std::endl;
//             std::cout << "operator!= " << (st1 != st3) << std::endl;
//             std::cout << "operator<  " << (st1 < st3) << std::endl;
//             std::cout << "operator>  " << (st1 > st3) << std::endl;
//             std::cout << "operator<= " << (st1 <= st3) << std::endl;
//             std::cout << "operator>= " << (st1 >= st3) << std::endl;
//             std::cout << "\e[1m" << "upper stack:" << "\e[0m" << std::endl;
//             std::cout << "operator== " << (st4 == st1) << std::endl;
//             std::cout << "operator!= " << (st4 != st1) << std::endl;
//             std::cout << "operator<  " << (st4 < st1) << std::endl;
//             std::cout << "operator>  " << (st4 > st1) << std::endl;
//             std::cout << "operator<= " << (st4 <= st1) << std::endl;
//             std::cout << "operator>= " << (st4 >= st1) << std::endl;

//             // std::stack<int> o_st1;
//             // o_st1.push(5);
//             // o_st1.push(42);
//             // std::stack<int> o_st2;
//             // o_st2.push(5);
//             // o_st2.push(42);
//             // std::stack<int> o_st3;
//             // o_st3.push(5);
//             // o_st3.push(42);
//             // o_st3.push(43);
//             // std::stack<int> o_st4;
//             // o_st4.push(99);
//             // o_st4.push(5);
//             // o_st4.push(42);
//             // std::cout << "\e[1m" << "original same stack:" << "\e[0m" << std::endl;
//             // std::cout << "operator== " << (o_st1 == o_st2) << std::endl;
//             // std::cout << "operator!= " << (o_st1 != o_st2) << std::endl;
//             // std::cout << "operator<  " << (o_st1 < o_st2) << std::endl;
//             // std::cout << "operator>  " << (o_st1 > o_st2) << std::endl;
//             // std::cout << "operator<= " << (o_st1 <= o_st2) << std::endl;
//             // std::cout << "operator>= " << (o_st1 >= o_st2) << std::endl;
//             // std::cout << "\e[1m" << "original lesser stack:" << "\e[0m" << std::endl;
//             // std::cout << "operator== " << (o_st1 == o_st3) << std::endl;
//             // std::cout << "operator!= " << (o_st1 != o_st3) << std::endl;
//             // std::cout << "operator<  " << (o_st1 < o_st3) << std::endl;
//             // std::cout << "operator>  " << (o_st1 > o_st3) << std::endl;
//             // std::cout << "operator<= " << (o_st1 <= o_st3) << std::endl;
//             // std::cout << "operator>= " << (o_st1 >= o_st3) << std::endl;
//             // std::cout << "\e[1m" << "original upper stack:" << "\e[0m" << std::endl;
//             // std::cout << "operator== " << (o_st4 == o_st1) << std::endl;
//             // std::cout << "operator!= " << (o_st4 != o_st1) << std::endl;
//             // std::cout << "operator<  " << (o_st4 < o_st1) << std::endl;
//             // std::cout << "operator>  " << (o_st4 > o_st1) << std::endl;
//             // std::cout << "operator<= " << (o_st4 <= o_st1) << std::endl;
//             // std::cout << "operator>= " << (o_st4 >= o_st1) << std::endl;
            
//             std::cout << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;
//         }

//     }
// }

// #include <iostream>
// #include <string>
// #include <deque>
// #if 1 //CREATE A REAL STL EXAMPLE
// 	#include <map>
// 	#include <stack>
// 	#include <vector>
// 	namespace ft = std;
// #else
// 	#include <map.hpp>
// 	#include <stack.hpp>
// 	#include <vector.hpp>
// #endif

// #include <stdlib.h>

// #define MAX_RAM 4294967296
// #define BUFFER_SIZE 4096
// struct Buffer
// {
// 	int idx;
// 	char buff[BUFFER_SIZE];
// };


// #define COUNT (MAX_RAM / (int)sizeof(Buffer))

// template<typename T>
// class MutantStack : public ft::stack<T>
// {
// public:
// 	MutantStack() {}
// 	MutantStack(const MutantStack<T>& src) { *this = src; }
// 	MutantStack<T>& operator=(const MutantStack<T>& rhs) 
// 	{
// 		this->c = rhs.c;
// 		return *this;
// 	}
// 	~MutantStack() {}

// 	typedef typename ft::stack<T>::container_type::iterator iterator;

// 	iterator begin() { return this->c.begin(); }
// 	iterator end() { return this->c.end(); }
// };

// int main(int argc, char** argv) {
// 	if (argc != 2)
// 	{
// 		std::cerr << "Usage: ./test seed" << std::endl;
// 		std::cerr << "Provide a seed please" << std::endl;
// 		std::cerr << "Count value:" << COUNT << std::endl;
// 		return 1;
// 	}
// 	const int seed = atoi(argv[1]);
// 	srand(seed);

// 	ft::vector<std::string> vector_str;
// 	ft::vector<int> vector_int;
// 	ft::stack<int> stack_int;
// 	ft::vector<Buffer> vector_buffer;
// 	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;
// 	// ft::map<int, int> map_int;

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		vector_buffer.push_back(Buffer());
// 	}

// 	for (int i = 0; i < COUNT; i++)
// 	{
// 		const int idx = rand() % COUNT;
// 		vector_buffer[idx].idx = 5;
// 	}
// 	ft::vector<Buffer>().swap(vector_buffer);

// 	try
// 	{
// 		for (int i = 0; i < COUNT; i++)
// 		{
// 			const int idx = rand() % COUNT;
// 			vector_buffer.at(idx);
// 			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
// 		}
// 	}
// 	catch(const std::exception& e)
// 	{
// 		//NORMAL ! :P
// 	}
	
// 	// for (int i = 0; i < COUNT; ++i)
// 	// {
// 	// 	map_int.insert(ft::make_pair(rand(), rand()));
// 	// }

// 	// int sum = 0;
// 	// for (int i = 0; i < 10000; i++)
// 	// {
// 	// 	int access = rand();
// 	// 	sum += map_int[access];
// 	// }
// 	// std::cout << "should be constant with the same seed: " << sum << std::endl;

// 	// {
// 	// 	ft::map<int, int> copy = map_int;
// 	// }
// 	MutantStack<char> iterable_stack;
// 	for (char letter = 'a'; letter <= 'z'; letter++)
// 		iterable_stack.push(letter);
// 	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
// 	{
// 		std::cout << *it;
// 	}
// 	std::cout << std::endl;
// 	return (0);
// }