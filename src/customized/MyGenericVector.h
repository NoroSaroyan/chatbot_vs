#ifndef MY_GENERIC_VECTOR_H
#define MY_GENERIC_VECTOR_H

#include <memory>
#include <stdexcept>

/**
 * @class MyGenericVector
 * @brief Простой обобщенный класс вектора, поддерживающий динамическое изменение размера.
 *
 * @tparam T Тип элементов, хранящихся в векторе.
 */
template<typename T>
class MyGenericVector {
public:
    /**
     * @brief Конструктор по умолчанию. Инициализирует пустой вектор с емкостью 10.
     */
    MyGenericVector();

    /**
     * @brief Конструктор копирования. Инициализирует вектор как копию другого вектора.
     *
     * @param other Вектор, из которого производится копирование.
     */
    MyGenericVector(const MyGenericVector &other);

    /**
     * @brief Конструктор перемещения. Инициализирует вектор, захватывая ресурсы другого вектора.
     *
     * @param other Вектор, из которого производится перемещение.
     */
    MyGenericVector(MyGenericVector &&other) noexcept;

    /**
     * @brief Оператор присваивания копированием. Присваивает вектор, копируя другой вектор.
     *
     * @param other Вектор, из которого производится копирование.
     * @return Ссылка на этот вектор.
     */
    MyGenericVector &operator=(const MyGenericVector &other);

    /**
     * @brief Оператор присваивания перемещением. Присваивает вектор, захватывая ресурсы другого вектора.
     *
     * @param other Вектор, из которого производится перемещение.
     * @return Ссылка на этот вектор.
     */
    MyGenericVector &operator=(MyGenericVector &&other) noexcept;

    /**
     * @brief Добавляет элемент в конец вектора.
     *
     * @param value Элемент для добавления.
     */
    void push_back(const T &value);

    /**
     * @brief Обращается к элементу по указанному индексу.
     *
     * @param index Индекс элемента для доступа.
     * @return Ссылка на элемент по указанному индексу.
     * @throws std::out_of_range Если индекс выходит за пределы диапазона.
     */
    T &operator[](std::size_t index);

    /**
     * @brief Обращается к элементу по указанному индексу (константная версия).
     *
     * @param index Индекс элемента для доступа.
     * @return Константная ссылка на элемент по указанному индексу.
     * @throws std::out_of_range Если индекс выходит за пределы диапазона.
     */
    const T &operator[](std::size_t index) const;

    /**
     * @brief Возвращает количество элементов в векторе.
     *
     * @return Количество элементов в векторе.
     */
    std::size_t getSize() const;

    /**
     * @brief Возвращает итератор к началу вектора.
     *
     * @return Итератор к началу вектора.
     */
    T *begin();

    /**
     * @brief Возвращает итератор к концу вектора.
     *
     * @return Итератор к концу вектора.
     */
    T *end();

    /**
     * @brief Возвращает константный итератор к началу вектора.
     *
     * @return Константный итератор к началу вектора.
     */
    const T *begin() const;

    /**
     * @brief Возвращает константный итератор к концу вектора.
     *
     * @return Константный итератор к концу вектора.
     */
    const T *end() const;

private:
    /**
     * @brief Изменяет размер вектора в два раза.
     */
    void resize();

    std::size_t size; ///< Количество элементов в векторе.
    std::size_t capacity; ///< Текущая емкость вектора.
    std::unique_ptr<T[]> data; ///< Динамически выделенный массив для хранения элементов.
};

template<typename T>
MyGenericVector<T>::MyGenericVector() : size(0), capacity(10), data(std::make_unique<T[]>(capacity)) {
}

template<typename T>
MyGenericVector<T>::MyGenericVector(const MyGenericVector &other)
    : size(other.size), capacity(other.capacity), data(std::make_unique<T[]>(other.capacity)) {
    for (std::size_t i = 0; i < other.size; ++i) {
        data[i] = other.data[i];
    }
}

template<typename T>
MyGenericVector<T>::MyGenericVector(MyGenericVector &&other) noexcept
    : size(other.size), capacity(other.capacity), data(std::move(other.data)) {
    other.size = 0;
    other.capacity = 0;
}

template<typename T>
MyGenericVector<T> &MyGenericVector<T>::operator=(const MyGenericVector &other) {
    if (this == &other) {
        return *this;
    }
    size = other.size;
    capacity = other.capacity;
    data = std::make_unique<T[]>(other.capacity);
    for (std::size_t i = 0; i < other.size; ++i) {
        data[i] = other.data[i];
    }
    return *this;
}

template<typename T>
MyGenericVector<T> &MyGenericVector<T>::operator=(MyGenericVector &&other) noexcept {
    if (this == &other) {
        return *this;
    }
    size = other.size;
    capacity = other.capacity;
    data = std::move(other.data);
    other.size = 0;
    other.capacity = 0;
    return *this;
}

template<typename T>
void MyGenericVector<T>::push_back(const T &value) {
    if (size >= capacity) {
        resize();
    }
    data[size++] = value;
}

template<typename T>
T &MyGenericVector<T>::operator[](std::size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template<typename T>
const T &MyGenericVector<T>::operator[](std::size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template<typename T>
std::size_t MyGenericVector<T>::getSize() const {
    return size;
}

template<typename T>
T *MyGenericVector<T>::begin() {
    return &data[0];
}

template<typename T>
T *MyGenericVector<T>::end() {
    return &data[size];
}

template<typename T>
const T *MyGenericVector<T>::begin() const {
    return &data[0];
}

template<typename T>
const T *MyGenericVector<T>::end() const {
    return &data[size];
}

template<typename T>
void MyGenericVector<T>::resize() {
    capacity *= 2;
    std::unique_ptr<T[]> newData = std::make_unique<T[]>(capacity);
    for (std::size_t i = 0; i < size; ++i) {
        newData[i] = std::move(data[i]);
    }
    data = std::move(newData);
}

#endif // MY_GENERIC_VECTOR_H
