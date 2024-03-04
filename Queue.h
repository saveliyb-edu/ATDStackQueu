#pragma once

template <class T>
class Queue {
public:
	~Queue() {}
	virtual void enQueue(const T& e) = 0; // Добавление элемента в очередь
	virtual T deQueue() = 0; // Удаление элемента из очереди
	virtual bool isEmpty() = 0;
};

