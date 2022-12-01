#include "vector/vector.hpp"
#include <iomanip>
#include <vector>

int main()
{
    {
        ft::vector<int> empty_vec;
        std::cout << std::endl << "\e[1m" <<"*-----------Empty Vector--------------------*" << "\e[0m" << std::endl;
        std::cout << "Empty Vector  size(): " << empty_vec.size() << std::endl;
        std::cout << "Empty Vector  max_size(): " << empty_vec.max_size() << std::endl;
        std::cout << "Empty Vector  capacity(): " << empty_vec.capacity() << std::endl;
        std::cout << "Empty Vector  empty(): " << empty_vec.empty() << std::endl;
        std::cout << "\e[1m" << "*-------------------------------------------*" << std::endl;
    }

    {
        ft::vector<int> vec;
        vec.push_back(5);
        vec.push_back(42);
        vec.push_back(15);
        std::cout << std::endl << "\e[1m" << "*-----------vector[5, 42, 15]---------------*" << "\e[0m" <<std::endl;
        for (size_t i = 0; i < vec.size(); i++)
            std::cout << "vector[" << i << "]= " << vec[i] << " == vector.at("
                        << i << ")= " << vec.at(i) << std::endl;
        std::cout << "vec.size(): " << vec.size() << std::endl;
        // std::cout << "vec.max_size(): " << vec.max_size() << std::endl;
        std::cout << "vec.capacity(): " << vec.capacity() << std::endl;
        std::cout << "vec.empty(): " << vec.empty() << std::endl;
        std::cout << "vec.front(): " << vec.front() << " (" << *(vec.begin()) << ")" << std::endl;
        std::cout << "vec.back(): " << vec.back() << " (" << *(vec.end() - 1) << ")" << std::endl;    
        ft::vector<int>::reverse_iterator b_it = vec.rbegin();
        ft::vector<int>::reverse_iterator e_it = vec.rend();
        int i = 0;
        while (b_it != e_it)
        {
            std::cout << "reverse_vector[" << i << "]= " << *b_it << " " << std::endl;
            b_it++;
            i++;
        }
        std::cout << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;
    }
    {
        ft::vector<int> empty_vec;
        std::cout << std::endl << "\e[1m" << "*-----------------reserve-------------------*" << "\e[0m" <<std::endl;
        empty_vec.reserve(256);
        std::cout << "Empty Vector reverse 256: " << empty_vec.capacity() << std::endl;
        empty_vec.reserve(64);
        std::cout << "Empty Vector reverse 64: " << empty_vec.capacity() << std::endl;
        empty_vec.reserve(500);
        std::cout << "Empty Vector reverse 500: " << empty_vec.capacity() << std::endl;
        std::cout << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;
    }

    {
        std::cout << std::endl << "\e[1m" << "*-----pop_back()---(r)begin()---(r)end------*" << "\e[0m" <<std::endl;
        ft::vector<int> vec;
        vec.push_back(5);
        vec.push_back(15);
        vec.push_back(25);
        vec.pop_back();
        for (size_t i = 0; i < vec.size(); i++)
            std::cout << "vector[" << i << "]= " << vec[i] << " == vector.at("
                    << i << ")= " << vec.at(i) << std::endl;
        ft::vector<int> vec2(vec);
        std::cout << "vec.size(): " << vec.size() << std::endl;
        std::cout << "vec.capacity(): " << vec.capacity() << std::endl;
        for (size_t i = 0; i < vec2.size(); i++)
            std::cout << "copy_vector[" << i << "] = " << vec2[i] << " == copy_vector.at("
                    << i << ") = " << vec2.at(i) << std::endl;
        ft::vector<int>::reverse_iterator rbit = vec.rbegin();
        ft::vector<int>::reverse_iterator reit = vec.rend();
        int i = 1;
        while (rbit != reit)
            std::cout << i++ << "->" << *rbit++ << std::endl;
        ft::vector<int>::iterator b_it;
        ft::vector<int>::iterator e_it;
        b_it = vec.begin();
        e_it = vec.end();
        while (b_it != e_it)
            std::cout << *b_it++ << ",";
        std::cout << std::endl << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;
    }

    {
        std::cout << std::endl << "\e[1m" << "*---------swap/resize/reserve/clear---------*" << "\e[0m" <<std::endl;
        ft::vector<int> vec;
        vec.push_back(5);
        vec.push_back(15);
        vec.push_back(25);
        vec.push_back(35);
        vec.push_back(45);

        ft::vector<int> vec1;
        vec1.push_back(85);
        vec1.push_back(105);
        vec1.push_back(205);
        vec1.push_back(305);
        vec1.push_back(405);

        // std::vector<int> origin_vec;
        // origin_vec.push_back(5);
        // origin_vec.push_back(15);
        // origin_vec.push_back(25);
        // origin_vec.push_back(35);
        // origin_vec.push_back(45);
        // std::cout << "origin Erase: " << *origin_vec.erase(origin_vec.end() - 1) << std::endl;
        // for (size_t i = 0; i < origin_vec.size(); i++)
        //     std::cout << "origin_vector[" << i << "]= " << origin_vec[i] << std::endl;
        std::cout << "Erase: " << *vec.erase(vec.end() - 1) << std::endl;
        std::cout << std::endl;
        for (size_t i = 0; i < vec.size(); i++)
            std::cout << "vector[" << i << "]= " << vec[i] << std::endl;

        vec.swap(vec1);

        vec.resize(10, 100);
        for (size_t i = 0; i < vec.size(); i++)
            std::cout << "resize_vector[" << i << "]= " << vec[i] << std::endl;
        vec.reserve(30);
        std::cout << std::endl << "resize_vec.size(): " << vec.size() << std::endl;
        std::cout << "resize_vec.max_size(): " << vec.max_size() << std::endl;
        std::cout << "resize_vec.capacity(): " << vec.capacity() << std::endl;
        std::cout << std::endl;
        ft::vector<int>::iterator bit = vec.begin() + 2;
        ft::vector<int>::iterator eit = vec.end();
        vec.erase(bit, eit);
        for (size_t i = 0; i < vec.size(); i++)
            std::cout << "erase_iterator_vec[" << i << "]= " << vec[i] << std::endl;
        vec.clear();
        for (size_t i = 0; i < vec.size(); i++)
            std::cout << "clear_vector[" << i << "]= " << vec[i] << std::endl;
        std::cout << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;
    }
    
    {
        std::cout << std::endl << "\e[1m" << "*--------------------assign-----------------*" << "\e[0m" <<std::endl;
        ft::vector<int> vec;
        vec.assign(5, 42);
        for (size_t i = 0; i < vec.size(); i++)
            std::cout << "vector[" << i << "]= " << vec[i] << std::endl;
        std::cout << std::endl;
        ft::vector<int> vec1;
        vec1.assign(3, 45);
        // vec.assign(vec1.begin(), vec1.end());
        for (size_t i = 0; i < vec1.size(); i++)
            std::cout << "vector[" << i << "]= " << vec1[i] << std::endl;
        std::cout << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;
    }
    {
        std::cout << std::endl << "\e[1m" << "*--------------------insert-----------------*" << "\e[0m" <<std::endl;
        ft::vector<int> vec;
        vec.push_back(15);
        vec.push_back(25);
        vec.insert(vec.begin(), 5, 4);
        vec.insert(vec.begin(), 5);
        // vec.insert(vec.begin(), vec.begin() + 6, vec.end());
        for (size_t i = 0; i < vec.size(); i++)
            std::cout << "vector[" << i << "]= " << vec[i] << std::endl;
        std::cout << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;
    }
    {
        std::cout << std::endl << "\e[1m" << "*----------------resize----------------*" << "\e[0m" <<std::endl;
        ft::vector<int> vec;
        vec.push_back(5);
        vec.push_back(15);
        vec.push_back(25);
        vec.push_back(35);
        vec.push_back(45);
        // vec.resize(vec.max_size(), 45);
        // vec.resize(-1, 100);
        vec.resize(10, 100);
        std::cout << "\e[1m" << "resize(10, 100) size: " << "\e[0m" << vec.size() << std::endl;
        for (size_t i = 0; i < vec.size(); i++)
            std::cout << "resize_vector[" << i << "]= " << vec[i] << std::endl;
        vec.resize(0);
        std::cout << "\e[1m" << "resize(0) size: " << "\e[0m" << vec.size() << std::endl;
        for (size_t i = 0; i < vec.size(); i++)
            std::cout << "resize_vector[" << i << "]= " << vec[i] << std::endl;
        vec.resize(5);
        std::cout << "\e[1m" << "resize(5) size: " << "\e[0m" << vec.size() << std::endl;
        for (size_t i = 0; i < vec.size(); i++)
            std::cout << "resize_vector[" << i << "]= " << vec[i] << std::endl;
        std::cout << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;

    }

    {
        ft::vector<int> vec;
        vec.push_back(5);
        vec.push_back(42);

        ft::vector<int> vec1;
        vec1.push_back(5);
        vec1.push_back(42);

        ft::vector<int> vec3;
		vec3.push_back(5);
		vec3.push_back(42);
		vec3.push_back(43);

        ft::vector<int> vec4;
		vec4.push_back(99);
		vec4.push_back(42);
		vec4.push_back(43);

        std::cout << std::endl << "\e[1m" << "*---------------Operators----------------*" << "\e[0m" <<std::endl;
        std::cout << "operator== " << (vec == vec1) << std::endl;
        std::cout << "operator!= " << (vec != vec1) << std::endl;
        std::cout << "operator<  " << (vec < vec1) << std::endl;
        std::cout << "operator>  " << (vec > vec1) << std::endl;
        std::cout << "operator<= " << (vec <= vec1) << std::endl;
        std::cout << "operator>= " << (vec >= vec1) << std::endl;
        std::cout << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;

        std::cout << std::endl << "\e[1m" << "*---------------Operators----------------*" << "\e[0m" <<std::endl;
        std::cout << "operator== " << (vec == vec3) << std::endl;
        std::cout << "operator!= " << (vec != vec3) << std::endl;
        std::cout << "operator<  " << (vec < vec3) << std::endl;
        std::cout << "operator>  " << (vec > vec3) << std::endl;
        std::cout << "operator<= " << (vec <= vec3) << std::endl;
        std::cout << "operator>= " << (vec >= vec3) << std::endl;
        std::cout << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;

        std::cout << std::endl << "\e[1m" << "*---------------Operators----------------*" << "\e[0m" <<std::endl;
        std::cout << "operator== " << (vec4 == vec) << std::endl;
        std::cout << "operator!= " << (vec4 != vec) << std::endl;
        std::cout << "operator<  " << (vec4 < vec) << std::endl;
        std::cout << "operator>  " << (vec4 > vec) << std::endl;
        std::cout << "operator<= " << (vec4 <= vec) << std::endl;
        std::cout << "operator>= " << (vec4 >= vec) << std::endl;
        std::cout << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;

        // std::vector<int> v;
        // std::vector<int> v1;
        // std::vector<int> v3;
        // std::vector<int> v4;

        // v.push_back(5);
        // v.push_back(42);
        // v1.push_back(5);
        // v1.push_back(42);
        // v3.push_back(5);
		// v3.push_back(42);
		// v3.push_back(43);
        // v4.push_back(99);
		// v4.push_back(42);
		// v4.push_back(43);

        // std::cout << std::endl << "\e[1m" << "*---------------Original Operators----------------*" << "\e[0m" <<std::endl;
        // std::cout << "operator== " << (v == v1) << std::endl;
        // std::cout << "operator!= " << (v != v1) << std::endl;
        // std::cout << "operator<  " << (v < v1) << std::endl;
        // std::cout << "operator>  " << (v > v1) << std::endl;
        // std::cout << "operator<= " << (v <= v1) << std::endl;
        // std::cout << "operator>= " << (v >= v1) << std::endl;
        // std::cout << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;

        // std::cout << std::endl << "\e[1m" << "*---------------Original Operators----------------*" << "\e[0m" <<std::endl;
        // std::cout << "operator== " << (v == v3) << std::endl;
        // std::cout << "operator!= " << (v != v3) << std::endl;
        // std::cout << "operator<  " << (v < v3) << std::endl;
        // std::cout << "operator>  " << (v > v3) << std::endl;
        // std::cout << "operator<= " << (v <= v3) << std::endl;
        // std::cout << "operator>= " << (v >= v3) << std::endl;
        // std::cout << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;

        // std::cout << std::endl << "\e[1m" << "*---------------Original Operators----------------*" << "\e[0m" <<std::endl;
        // std::cout << "operator== " << (v4 == v) << std::endl;
        // std::cout << "operator!= " << (v4 != v) << std::endl;
        // std::cout << "operator<  " << (v4 < v) << std::endl;
        // std::cout << "operator>  " << (v4 > v) << std::endl;
        // std::cout << "operator<= " << (v4 <= v) << std::endl;
        // std::cout << "operator>= " << (v4 >= v) << std::endl;
        // std::cout << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;
    }

}