#ifndef ROUTEARRAY_H
#define ROUTEARRAY_H

#include "Route.h"

class RouteArray {
private:
    Route* data; //указатель на первый элемент массива в куче
    int size; //кол-во добавленных элементов
    int capacity; //сколько можно поместить элементов в выделенную память
                  //не выделяем память каждый раз
    void ensureCapacity(int minCap); //проверка: хватит ли места
    void resize(int newCap); //выделяет новый массив побольше 
                             //и копирует туда старые данные
    bool hasNumber(int number) const; //проверка на наличие номера маршрута
    //сравнивает строки без регистра ->
    static bool equalsIgnoreCase(const char* str1, const char* str2);
public:
    RouteArray();
    RouteArray(const RouteArray& other);
    ~RouteArray();

    RouteArray& operator=(const RouteArray& other);

    int getSize() const;
    Route& at(int index); //возврат ссылки на элемент по индексу
    const Route& at(int index) const;

    void addToEnd(const Route& r); //добавление в конец
    void addAt(int pos, const Route& r); //добавление по индексу
    void removeAt(int pos); //удаление по индексу
    void setAt(int pos, const Route& r); //замена по индексу (редактирование)
    void sortByNumber(); //сортировка по номеру маршрута

    void printByPoint(const char* point) const; //поиск и вывод маршрутов
};

#endif