#include <iostream>
#include "StackArray.h"

int main()
{
    try {
        StackArray<int> stack(3);

        stack.push(1);
        stack.push(2);
        stack.push(3);

        while (!stack.isEmpty()) {
            std::cout << stack.pop();
        }
        std::cout << std::endl;
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


}



//int main() {
//    // Создаем и заполняем первый стек
//    StackArray<int> stack1 (5);
//    for (int i = 0; i < 5; ++i) {
//        stack1.push(i);
//    }
//
//    // Тестируем оператор присваивания для копирования
//    StackArray<int> stack2(10);
//    stack2 = stack1;
//
//    // Выводим содержимое второго стека
//    while (!stack2.isEmpty()) {
//        std::cout << stack2.pop() << " ";
//    }
//    std::cout << std::endl;
//
//    // Создаем и заполняем третий стек
//    StackArray<int> stack3 (15);
//    for (int i = 10; i < 15; ++i) {
//        stack3.push(i);
//    }
//
//    // Тестируем оператор присваивания для перемещения
//    StackArray<int> stack4 (10);
//    stack4 = std::move(stack3);
//
//    // Выводим содержимое четвертого стека
//    while (!stack4.isEmpty()) {
//        std::cout << stack4.pop() << " ";
//    }
//    std::cout << std::endl;
//
//    return 0;
//}
