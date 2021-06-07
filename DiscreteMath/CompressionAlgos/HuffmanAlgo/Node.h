//
// Created by Евгений Дмитриев on 06.06.2021.
//

#ifndef TRAIN_NODE_H
#define TRAIN_NODE_H


#include <memory>

using std::shared_ptr;

template<typename T>
class Node
{
public:
    Node(const T value) {
        this->left = nullptr;
        this->right = nullptr;
        this->count = 1;
        this->value = value;
    }
    Node(const T value, const int count) {
        this->left = nullptr;
        this->right = nullptr;
        this->count = count;
        this->value = value;
    }
    Node(const int count) {
        this->left = nullptr;
        this->right = nullptr;
        this->count = count;
    }
    Node(const int count, const shared_ptr<Node>& left, const shared_ptr<Node>& right) {
        this->left = left;
        this->right = right;
        this->count = count;
    };

    int get_count() {
        return count;
    }
    T get_value() {
        return value;
    }

    bool has_left() {
        return left != nullptr;
    }
    bool has_right() {
        return right != nullptr;
    }
    const shared_ptr<Node<T>>& get_left() {
        return left;
    }
    const shared_ptr<Node<T>>& get_right() {
        return right;
    }
    Node& operator ++ () {
        ++count;
        return *this;
    }

private:
    shared_ptr<Node<T>> left;
    shared_ptr<Node<T>> right;

    int count{};
    T value;
};

#endif //TRAIN_NODE_H
