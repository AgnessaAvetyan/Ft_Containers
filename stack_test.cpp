#include "stack/stack.hpp"
#include <stack>

void stack_test()
{
    {
        std::cout << std::endl << "\e[1m" << "*-----------------Empty stack------------------*" << "\e[0m" <<std::endl;
        ft::stack<int> empty_stack;
        std::cout << "Stack is empty: " << empty_stack.empty() << std::endl;
        std::cout << "Empty stack size: " << empty_stack.size() << std::endl;
        std::cout << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;
    }
    {
        std::cout << std::endl << "\e[1m" << "*----------push/pop/top/size------------*" << "\e[0m" <<std::endl;
        ft::stack<int> stack;
        std::cout << "Stack size: " << stack.size() << std::endl;
        stack.push(5);
        std::cout << "Stack[5] top: " << stack.top() << std::endl;
        std::cout << "Stack[5] size: " << stack.size() << std::endl;
        stack.push(42);
        std::cout << "Stack[5, 42] top: " << stack.top() << std::endl;
        std::cout << "Stack[5, 42] size: " << stack.size() << std::endl;
        stack.top() = 99;
        std::cout << "Stack[5, 99] top: " << stack.top() << std::endl;
        stack.pop();
        std::cout << "Stack[5] size: " << stack.size() << std::endl;
        stack.pop();
        std::cout << "Stack size: " << stack.size() << std::endl;
        std::cout << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;
    }
    {
        std::cout << std::endl << "\e[1m" << "*----------Operators------------*" << "\e[0m" <<std::endl;
        ft::stack<int> st1;
        st1.push(5);
        st1.push(42);
        ft::stack<int> st2;
        st2.push(5);
        st2.push(42);
        ft::stack<int> st3;
        st3.push(5);
        st3.push(42);
        st3.push(43);
        ft::stack<int> st4;
        st4.push(99);
        st4.push(5);
        st4.push(42);

        // std::cout << "stack1 size: " << st1.size() << std::endl;
        // std::cout << "stack2 size: " << st2.size() << std::endl;

        std::cout << "\e[1m" << "same stack:" << "\e[0m" << std::endl;
        std::cout << "operator== " << (st1 == st2) << std::endl;
        std::cout << "operator!= " << (st1 != st2) << std::endl;
        std::cout << "operator<  " << (st1 < st2) << std::endl;
        std::cout << "operator>  " << (st1 > st2) << std::endl;
        std::cout << "operator<= " << (st1 <= st2) << std::endl;
        std::cout << "operator>= " << (st1 >= st2) << std::endl;
        std::cout << "\e[1m" << "lesser stack:" << "\e[0m" << std::endl;
        std::cout << "operator== " << (st1 == st3) << std::endl;
        std::cout << "operator!= " << (st1 != st3) << std::endl;
        std::cout << "operator<  " << (st1 < st3) << std::endl;
        std::cout << "operator>  " << (st1 > st3) << std::endl;
        std::cout << "operator<= " << (st1 <= st3) << std::endl;
        std::cout << "operator>= " << (st1 >= st3) << std::endl;
        std::cout << "\e[1m" << "upper stack:" << "\e[0m" << std::endl;
        std::cout << "operator== " << (st4 == st1) << std::endl;
        std::cout << "operator!= " << (st4 != st1) << std::endl;
        std::cout << "operator<  " << (st4 < st1) << std::endl;
        std::cout << "operator>  " << (st4 > st1) << std::endl;
        std::cout << "operator<= " << (st4 <= st1) << std::endl;
        std::cout << "operator>= " << (st4 >= st1) << std::endl;

        // std::stack<int> o_st1;
        // o_st1.push(5);
        // o_st1.push(42);
        // std::stack<int> o_st2;
        // o_st2.push(5);
        // o_st2.push(42);
        // std::stack<int> o_st3;
        // o_st3.push(5);
        // o_st3.push(42);
        // o_st3.push(43);
        // std::stack<int> o_st4;
        // o_st4.push(99);
        // o_st4.push(5);
        // o_st4.push(42);
        // std::cout << "\e[1m" << "original same stack:" << "\e[0m" << std::endl;
        // std::cout << "operator== " << (o_st1 == o_st2) << std::endl;
        // std::cout << "operator!= " << (o_st1 != o_st2) << std::endl;
        // std::cout << "operator<  " << (o_st1 < o_st2) << std::endl;
        // std::cout << "operator>  " << (o_st1 > o_st2) << std::endl;
        // std::cout << "operator<= " << (o_st1 <= o_st2) << std::endl;
        // std::cout << "operator>= " << (o_st1 >= o_st2) << std::endl;
        // std::cout << "\e[1m" << "original lesser stack:" << "\e[0m" << std::endl;
        // std::cout << "operator== " << (o_st1 == o_st3) << std::endl;
        // std::cout << "operator!= " << (o_st1 != o_st3) << std::endl;
        // std::cout << "operator<  " << (o_st1 < o_st3) << std::endl;
        // std::cout << "operator>  " << (o_st1 > o_st3) << std::endl;
        // std::cout << "operator<= " << (o_st1 <= o_st3) << std::endl;
        // std::cout << "operator>= " << (o_st1 >= o_st3) << std::endl;
        // std::cout << "\e[1m" << "original upper stack:" << "\e[0m" << std::endl;
        // std::cout << "operator== " << (o_st4 == o_st1) << std::endl;
        // std::cout << "operator!= " << (o_st4 != o_st1) << std::endl;
        // std::cout << "operator<  " << (o_st4 < o_st1) << std::endl;
        // std::cout << "operator>  " << (o_st4 > o_st1) << std::endl;
        // std::cout << "operator<= " << (o_st4 <= o_st1) << std::endl;
        // std::cout << "operator>= " << (o_st4 >= o_st1) << std::endl;
        
        std::cout << "\e[1m" << "*-------------------------------------------*" << "\e[0m" << std::endl;
    }
}