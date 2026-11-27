#include "Route.h"
#include <cstring>
#include <stdexcept>
#include <iostream>

char* Route::copyString(const char* src) {
    if (!src) return nullptr; //если пришла пустая строка, возвращаем пустоту
    size_t len = std::strlen(src) + 1; //опред. длину строки
    char* dst = new char[len]; //выделяем память ровно под нее ^
    strcpy_s(dst, len, src);
    return dst;
}

void Route::freeString(char*& s) { //char*& s -- ссылка на указатель
    delete[] s; //освобождаем память, выделенную через new
    s = nullptr; //обнуляем указатель
}

// Конструктор по умолчанию
Route::Route() : startPoint(nullptr), endPoint(nullptr), routeNumber(0) {
    std::cout << "[Route] Вызван конструктор по умолчанию\n";
    startPoint = copyString("не задано");
    endPoint = copyString("не задано");
}

// Конструктор с параметрами
Route::Route(const char* start, const char* end, int number)
    : startPoint(nullptr), endPoint(nullptr), routeNumber(number) {
    std::cout << "[Route] Вызван конструктор с параметрами (номер "
        << number << ")\n";
    if (!start || !end)
        throw std::invalid_argument("Route: пустое название пункта маршрута");
    if (number <= 0)
        throw std::invalid_argument("Route: номер маршрута должен быть > 0");
    startPoint = copyString(start);
    endPoint = copyString(end);
}

// Конструктор копирования
Route::Route(const Route& other)
    : startPoint(nullptr), endPoint(nullptr), routeNumber(other.routeNumber) {
    std::cout << "[Route] Вызван конструктор копирования (номер "
        << other.routeNumber << ")\n";
    startPoint = copyString(other.startPoint);
    endPoint = copyString(other.endPoint);
}

// Деструктор
Route::~Route() {
    std::cout << "[Route] Вызван деструктор (номер " << routeNumber << ")\n";
    freeString(startPoint);
    freeString(endPoint);
}

Route& Route::operator=(const Route& other) {
    if (this != &other) { //проверка на самоприсваивание
        freeString(startPoint);
        freeString(endPoint);
        routeNumber = other.routeNumber;
        startPoint = copyString(other.startPoint);
        endPoint = copyString(other.endPoint);
    }
    return *this;
}

const char* Route::getStartPoint() const { return startPoint; }
const char* Route::getEndPoint()   const { return endPoint; }
int Route::getRouteNumber() const { return routeNumber; }

void Route::setStartPoint(const char* start) {
    if (!start) throw std::invalid_argument("setStartPoint: nullptr");
    freeString(startPoint);
    startPoint = copyString(start);
}

void Route::setEndPoint(const char* end) {
    if (!end) throw std::invalid_argument("setEndPoint: nullptr");
    freeString(endPoint);
    endPoint = copyString(end);
}

void Route::setRouteNumber(int number) {
    if (number <= 0) throw std::invalid_argument("setRouteNumber: номер должен быть > 0");
    routeNumber = number;
}

// Перегрузка вывода
std::ostream& operator<<(std::ostream& os, const Route& r) {
    os << "Маршрут №" << r.routeNumber
        << " : " << (r.startPoint ? r.startPoint : "")
        << " -> " << (r.endPoint ? r.endPoint : "");
    return os;
}

// Перегрузка ввода
std::istream& operator>>(std::istream& is, Route& r) {
    char bufStart[256], bufEnd[256];
    int num;
    if (!(is >> bufStart >> bufEnd >> num)) {
        is.setstate(std::ios::failbit);
        return is;
    }
    try {
        r.setStartPoint(bufStart);
        r.setEndPoint(bufEnd);
        r.setRouteNumber(num);
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка при вводе ROUTE: " << e.what() << "\n";
        is.setstate(std::ios::failbit);
    }
    return is;
}

// Сравнение номеров маршрута
bool Route::operator<(const Route& other) const {
    return routeNumber < other.routeNumber;
}