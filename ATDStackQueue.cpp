#include <iostream>
#include "StackArray.h"
#include "CircularQueue.h"

bool checkBalanceBrackets(const std::string& text, const int maxDeep)
{
    try {
        StackArray<char> s(maxDeep);
        char x;
        for (int i = 0; i < text.length(); i++)
        {
            if (text[i] == '(' || text[i] == '[' || text[i] == '{')
            {
                s.push(text[i]);
                continue;
            }
            if (s.isEmpty())
                return false;

            x = s.pop();
            switch (text[i]) {
            case ')':
                
                if (x == '{' || x == '[')
                    return false;
                break;

            case '}':
                if (x == '(' || x == '[')
                    return false;
                break;

            case ']':
                if (x == '(' || x == '{')
                    return false;
                break;
            }
        }

        return (s.isEmpty());
    } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
    }
}

int main()
{
    //test stackArray
    std::cout << "test stackArray:\n";
    try {
        StackArray<int> stack(4);

        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);

        while (!stack.isEmpty()) {
            std::cout << stack.pop() << " ";
        }
        std::cout << std::endl;
        //stack.pop();
        StackArray<int> stack1(10);
        stack1 = stack;

        while (!stack1.isEmpty()) {
            std::cout << stack1.pop() << " ";
        }
        std::cout << std::endl;

        StackArray<int> stack2(15);
        for (int i = 10; i < 15; ++i) {
            stack2.push(i);
        }

        StackArray<int> stack3(10);
        stack3 = std::move(stack2);

        while (!stack3.isEmpty()) {
            std::cout << stack3.pop() << " ";
        }
        std::cout << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    //test checkBalanceBrackets
    std::cout << "\n\ntest checkBalanceBrackets:\n";
    
    std::string text1 = "(({}))";
    std::string text2 = "()({[][]([][{}()])})";
    std::string text3 = "[(]{)}";
    std::string text4 = "{()}[]";
    std::string text5 = "{";
    std::string text6 = ")";
    std::string text7 = "()()(){}{}[]{()[(){}[]]}{{[]}}";
    std::string text8 = "{{{{{{{{{{(((((((((([[[[[[[[[[()]]]]]]]]]]))))))))))}}}}}}}}}}";
    int maxDeep = 21;
    std::cout << text1 << " " << checkBalanceBrackets(text1, maxDeep) << std::endl;
    std::cout << text2 << " " << checkBalanceBrackets(text2, maxDeep) << std::endl;
    std::cout << text3 << " " << checkBalanceBrackets(text3, maxDeep) << std::endl;
    std::cout << text4 << " " << checkBalanceBrackets(text4, maxDeep) << std::endl;
    std::cout << text5 << " " << checkBalanceBrackets(text5, maxDeep) << std::endl;
    std::cout << text6 << " " << checkBalanceBrackets(text6, maxDeep) << std::endl;
    std::cout << text7 << " " << checkBalanceBrackets(text7, maxDeep) << std::endl;
    //std::cout << text8 << " " << checkBalanceBrackets(text8, maxDeep) << std::endl;

    //test CircularQueue
    std::cout << "\n\ntest CircularQueue:\n";
    
    try {
        //CircularQueue<int> queue(-5);
        CircularQueue<int> queue(5);

        queue.enQueue(1);
        queue.enQueue(2);
        queue.enQueue(3);
        queue.enQueue(4);
        queue.enQueue(5);

        //queue.enQueue(6);

        while (!queue.isEmpty()) {
            std::cout << queue.deQueue() << " ";
        }
        std::cout << std::endl;

        //queue.deQueue();
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
