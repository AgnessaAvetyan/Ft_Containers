#include "vector/vector.hpp"
#include <vector>
#include <iomanip>

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
        std::cout << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;
    }

    // typename ft::vector<int>::reverse_iterator b_it = vec.rbegin();
    // typename ft::vector<int>::reverse_iterator e_it = vec.rend();
    // while (b_it != e_it)
    // {
    //     std::cout << *b_it << " ";
    //     b_it++;
    // }
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
        std::cout << std::endl << "\e[1m" << "*-----------------clear---------------------*" << "\e[0m" <<std::endl;
        ft::vector<int> vec;
        vec.push_back(5);
        vec.push_back(15);
        vec.push_back(25);
        vec.pop_back();
        for (size_t i = 0; i < vec.size(); i++)
            std::cout << "vector[" << i << "]= " << vec[i] << " == vector.at("
                    << i << ")= " << vec.at(i) << std::endl;
        ft::vector<int> vec2(vec);
        vec.clear();
        std::cout << "vec.size(): " << vec.size() << std::endl;
        std::cout << "vec.capacity(): " << vec.capacity() << std::endl;
        for (size_t i = 0; i < vec2.size(); i++)
            std::cout << "copy_vector[" << i << "] = " << vec2[i] << " == copy_vector.at("
                    << i << ") = " << vec2.at(i) << std::endl;
        // typename ft::vector<int>::reverse_iterator rbit = vec.rbegin();
        // typename ft::vector<int>::reverse_iterator reit = vec.rend();
        // int i = 1;
        // while (rbit != reit)
        //     std::cout << i++ << "->" << *rbit++ << std::endl;
        // typename ft::vector<int>::iterator b_it;
        // typename ft::vector<int>::iterator e_it;
        // b_it = vec.begin();
        // e_it = vec.end();
        // while (b_it != e_it)
        //     std::cout << *b_it++ << ",";
        std::cout << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;
    }

    {
        std::cout << std::endl << "\e[1m" << "*-----------------clear---------------------*" << "\e[0m" <<std::endl;
        ft::vector<int> vec;
        vec.push_back(5);
        vec.push_back(15);
        vec.push_back(25);
        vec.push_back(35);
        vec.push_back(45);
        std::cout << "Erase: " << *vec.erase(vec.begin()) << std::endl;

        std::cout << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;
    }
    // std::cout << "vec.rbegin(): " << *(vec.rbegin()) << std::endl;
    // std::cout << "vec.rend(): " << *(vec.rend()) << std::endl;


}