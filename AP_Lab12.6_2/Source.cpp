#include <iostream>
#include <fstream>

using namespace std;

struct Elem
{
    Elem* link;
    int info;
};

void enqueue(Elem*& first, Elem*& last, int value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->link = NULL;
    if (last != NULL)
        last->link = tmp;
    last = tmp;
    if (first == NULL)
        first = tmp;
}

int dequeue(Elem*& first, Elem*& last)
{
    Elem* tmp = first->link;
    int value = first->info;
    delete first;
    first = tmp;
    if (first == NULL)
        last = NULL;
    return value;
}

void printQueue(Elem* first)
{
    Elem* current = first;
    while (current != NULL)
    {
        cout << current->info << " ";
        current = current->link;
    }
    cout << endl;
}

Elem* searchAndSplitQueue(Elem*& first, Elem*& last, int value)
{
    Elem* current = first;
    Elem* previous = NULL;
    while (current != NULL)
    {
        if (current->info == value)
        {
            Elem* secondFirst = current;
            if (previous != NULL)
                previous->link = NULL;
            else
                first = NULL;
            last = previous;
            return secondFirst;
        }
        previous = current;
        current = current->link;
    }
    return NULL;
}

int main()
{
    Elem* first = NULL;
    Elem* last = NULL;

    // Зчитування значень з текстового файлу
    ifstream file("numbers.txt");
    int value;
    while (file >> value)
    {
        enqueue(first, last, value);
    }
    file.close();

    // Виведення елементів черги
    cout << "Queue elements: ";
    printQueue(first);

    // Пошук та розділення черги
    int searchValue;
    cout << "Enter the value to search: ";
    cin >> searchValue;
    Elem* secondFirst = searchAndSplitQueue(first, last, searchValue);

    // Виведення отриманих черг
    cout << "First Queue: ";
    printQueue(first);
    cout << "Second Queue: ";
    printQueue(secondFirst);

    return 0;
}
