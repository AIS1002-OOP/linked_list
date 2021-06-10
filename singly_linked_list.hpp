
#ifndef LISTS_SINGLY_LINKED_LIST_HPP
#define LISTS_SINGLY_LINKED_LIST_HPP

#include <utility>
#include <exception>
#include <iostream>
#include <sstream>

namespace ais1002 {

    template<typename T>
    class node {

    public:
        explicit node(const T &data) : data_(std::move(data)) {}

        T data_;
        node *next_ = nullptr;
    };

    template<typename T>
    class singly_linked_list {

    public:

        singly_linked_list() : size_(0) {}

        [[nodiscard]] bool empty() const {
            return size_ == 0;
        }

        T get(unsigned int index) {
            if (index > size_) throw std::runtime_error("Index out of bounds");

            node<T> *current = head_;
            for (int i = 0; i < index; i++) {
                current = current->next_;
            }
            return current->data_;
        }

        T operator[](int index) {
            return get(index);
        }


        void add(const T data) {
            insert(size_, data);
        }

        void insert(unsigned int index, const T &data) {
            if (index > size_) throw std::runtime_error("Index out of bounds");

            node<T> *current = head_;
            node<T> *prev = nullptr;

            for (int i = 0; i < index; i++) {
                prev = current;
                current = current->next_;
            }

            node<T> *insert = new node(data);
            insert->next_ = current;
            if (!prev) {
                head_ = insert;
            } else {
                prev->next_ = insert;
            }

            size_++;

        }

        T remove(unsigned int index) {
            if (index >= size_) throw std::runtime_error("Index out of bounds");

            node<T> *current = head_;
            node<T> *prev = nullptr;

            for (int i = 0; i < index; i++) {
                prev = current;
                current = current->next_;
            }

            T data = current->data_;
            if (!prev) {
                head_ = current->next_;
            } else {
                prev->next_ = current->next_;
            }

            delete current;

            size_--;

            return data;

        }

        [[nodiscard]] unsigned int size() const {
            return size_;
        }

        T removeFirst() {
            if (empty()) throw std::runtime_error("List is empty..");
            return remove(0);
        }

        T removeLast() {
            if (empty()) throw std::runtime_error("List is empty..");
            return remove(size_ - 1);
        }

        void print() {

            if (empty()) std::cout << "[]" << std::endl;

            std::stringstream ss;

            ss << "[";

            node<T> *head = head_;
            while (true) {
                ss << head->data_;
                node<T> *next = head->next_;
                if (!next) {
                    ss << "]";
                    break;
                } else {
                    ss << ", ";
                    head = next;
                }
            }

            std::cout << ss.str() << std::endl;

        }

    private:
        node<T> *head_ = nullptr;
        unsigned int size_;
    };

}

#endif //LISTS_SINGLY_LINKED_LIST_HPP
