#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

class Node {
public:
    int val;
    int key;
    Node *prev;
    Node *next;
    Node(int x, int y, Node *pre) : key(x), val(y),prev(pre), next(nullptr) {}
};

class LRUCache {
public:
    int maxIndex = 0, nowIndex = 0;
    unordered_map<int, Node*> storage;
    Node *head = NULL, *end = NULL;

    LRUCache(int capacity) {
        maxIndex = capacity;
    }
    
    int get(int key) {
        if(storage.find(key) == storage.end())
            return -1;
        else
        {
            move(key);
            return storage[key]->val;
        }
    }
    
    void put(int key, int value) {
        if(storage.find(key) == storage.end())
        {
            if(maxIndex == nowIndex)
            {
                pop();
                push(key, value);
            }
            else
            {
                push(key, value);
                nowIndex++;
            }
        }
        else
        {
            storage[key]->val = value;
            move(key);
        }
    }

private:
    void push(int key, int value)
    {
        if(head == NULL)
        {
            head = new Node(key, value, nullptr);
            storage[key] = head;
            end = head;
        }
        else
        {
            end->next = new Node(key, value, end);
            end = end->next;
            storage[key] = end;
        }
    }

    void pop()
    {
        storage.erase(head->key);
        Node *ptr = head;
        head = head->next;
        if(head != nullptr)
            head->prev = nullptr;
        delete ptr;
    }

    void move(int key)
    {
        if(storage[key]->next == nullptr)
            return;
        else if(storage[key]->prev == nullptr)
        {
            head = head->next;
            head->prev = nullptr;
        }
        else
        {
            storage[key]->prev->next = storage[key]->next;
            storage[key]->next->prev = storage[key]->prev;  
        }

        storage[key]->next = nullptr;
        storage[key]->prev = end;
        end->next = storage[key];
        end = end->next;
    }
};