#ifndef ROUTE_H
#define ROUTE_H

#include <iostream>

class Route {
private:
    char* startPoint; //название начального пункта
    char* endPoint; //название конечного пункта
    int   routeNumber; //номер маршрута

    static char* copyString(const char* src);
    static void  freeString(char*& s);

public:
    // Конструкторы и деструктор
    Route();
    Route(const char* start, const char* end, int number);
    Route(const Route& other);
    ~Route();

    // Оператор присваивания
    Route& operator=(const Route& other);

    // get и set
    const char* getStartPoint() const;
    const char* getEndPoint()   const;
    int         getRouteNumber() const;

    void setStartPoint(const char* start);
    void setEndPoint(const char* end);
    void setRouteNumber(int number);

    // Перегруженные операции вставки и извлечения
    friend std::ostream& operator<<(std::ostream& os, const Route& r);
    friend std::istream& operator>>(std::istream& is, Route& r);

    // Сравнение по номеру маршрута (для сортировки)
    bool operator<(const Route& other) const;
};

#endif