#ifndef ROUTEARRAY_H
#define ROUTEARRAY_H

#include "Route.h"

class RouteArray {
private:
    Route* data;
    int size;
    int capacity;

    void ensureCapacity(int minCap);
    void resize(int newCap);

public:
    RouteArray();
    RouteArray(const RouteArray& other);
    ~RouteArray();

    RouteArray& operator=(const RouteArray& other);

    int getSize() const;
    Route& at(int index); //с проверкой диапазона
    const Route& at(int index) const;

    void addToEnd(const Route& r);
    void addAt(int pos, const Route& r); //вставка на любую позицию
    void removeAt(int pos); //удаление любого
    void setAt(int pos, const Route& r); //замена (редактирование)
    void sortByNumber(); //по номеру маршрута

    // Поиск по пункту (начало ИЛИ конец)
    void printByPoint(const char* point) const;
};

#endif