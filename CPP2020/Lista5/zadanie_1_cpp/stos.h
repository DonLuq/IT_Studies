#ifndef MAIN_STOS_H
#define MAIN_STOS_H
#include <cstdlib>
#include <cassert>

class Stos
{
public:
    Stos (); //konstruktor domyślny
    Stos(Stos const&); //konstruktor kopiujący
    ~Stos(); //destruktor

    void push(int i); //dokłada liczbę na stos
    void pop(); //zdejmuje liczbę ze stosu
    int top()const; //udostępnia wartość liczby na szczycie stosu
    int& top(); //udostępnia referencję do liczby na szczycie stosu
    bool empty() const; //czy stos jest pusty?
    size_t size() const; //bieżacy rozmiar logiczny stosu
    Stos& operator=(Stos const&); //operator przypisania
private:
    enum {initial_capacity = 1}; //stała wyliczeniowa
    void _grow(); //prywatna funkcja służąca do rozszerzania stosu
    void _shrink(); //zmniejsza pojemność stosu dwukrotnie

    size_t _capacity; //rzeczywisty (fizyczny) rozmiar tablicy
    size_t _size; //pozorny (logiczny) rozmiar tablicy
    int *_tab; //tablica z danymi
};

inline Stos::Stos()
        :_capacity(initial_capacity),
         _size(0),
         _tab(new int[initial_capacity])
{
    assert (initial_capacity > 0);
}

inline Stos::~Stos() {delete []_tab;}

inline void Stos::push(int n)
{
    if (_size == _capacity) // jeśli nie ma więcej miejsca na stosie
        _grow();
    _tab[_size] = n;
    _size++;
}

inline void Stos::pop()
{
    assert(!empty());
    _size--;
    if (_capacity == 4 * _size)
        _shrink();
}

inline int Stos::top() const
{
    assert(!empty());
    return _tab[_size-1];
}

inline int& Stos::top()
{
    assert(!empty());
    return _tab[_size-1];
}

inline bool Stos::empty() const {return _size == 0;}

inline size_t Stos::size() const {return _size;}
#endif //MAIN_STOS_H