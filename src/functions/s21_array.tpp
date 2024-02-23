#ifndef CPP2_S21_CONTAINERS_2_SRC_S21_FUNCTIONS_S21_ARRAY_TPP
#define CPP2_S21_CONTAINERS_2_SRC_S21_FUNCTIONS_S21_ARRAY_TPP

namespace s21 {

// Конструктор создания
template <typename T, size_t N>
array<T, N>::array() = default;

// Конструктор инициилизации списков
template <typename T, size_t N>
array<T, N>::array(std::initializer_list<value_type> const &items) {
    // Проверяем, что размер списка не превышает N.
    if (items.size() > N) {
        throw std::out_of_range("Initializer list size is larger than array size");
    }
    // Копируем элементы из списка в массив.
    std::copy(items.begin(), items.end(), data_);
}

// Конструктор копирования
template <typename T, size_t N>
array<T, N>::array(const array &a) {
    std::copy(a.begin(), a.end(), data_);
}

// Конструктор перемещения
template <typename T, size_t N>
array<T, N>::array(array &&a) noexcept {
    // Копируем элементы из массива 'a' в текущий массив.
    std::move(a.data_, a.data_ + N, data_);
    // После перемещения массив 'a' не удаляется в деструкторе, остается забит "мусором"
}

// Оператор присвваивания для перем-го объекта (перемещение)
template <typename T, size_t N>
array<T, N>& array<T, N>::operator=(array &&other) {
    if (this != &other) {
        // Перемещение элементов из other в текущий массив.
        std::move(other.begin(), other.end(), data_);
        // После перемещения массив 'other' не удаляется в деструкторе, остается забит "мусором"
    }
    return *this;
}
// Оператор присвваивания для перем-го объекта (копирование)
template <typename T, size_t N>
array<T, N>& array<T, N>::operator=(const array &other) {
    if (this != &other) {
        // Копируем элементы из other в текущий массив.
        std::copy(other.begin(), other.end(), data_);
        // После перемещения массив 'other' остается неизменным
    }
    return *this;
}

// Доступ к элементу по индексу с проверкой границ
template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::at(size_type pos) {
    if (pos >= N) {
        throw std::out_of_range("Index is out of range");
    }

    return data_[pos];
}

// Доступ к элементу по индексу (без проверки)
template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::operator[](size_type pos) {
    return data_[pos];
}

// Доступ к первому элементу
template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::front() {
    if (N == 0) {
        throw std::invalid_argument("Incorrect array size");
    }
   return data_[0];
}

// Доступ к последнему элементу
template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::back() {
    if (N == 0) {
        throw std::invalid_argument("Incorrect array size");
    }
   return data_[N - 1];
}

// Прямой доступ к массиву (указ на перв элемент)
template <typename T, size_t N>
typename array<T, N>::iterator array<T, N>::data() {
    return data_;
}

// Вызов итератора, указывающего на 1й элемент массива
template <typename T, size_t N>
typename array<T, N>::iterator array<T, N>::begin() {
    return data_;
}

// Вызов итератора, указывающего на 1й элемент после последнего элемента массива
template <typename T, size_t N>
typename array<T, N>::iterator array<T, N>::end() {
    return data_ + N;
}

// Константные варианты для const объектов
template <typename T, size_t N>
typename array<T, N>::const_iterator array<T, N>::begin() const {    return data_;
}
template <typename T, size_t N>typename array<T, N>::const_iterator array<T, N>::end() const {
    return data_ + N;}

// Проверка на пустой контейнер
template <typename T, size_t N>
bool array<T, N>::empty() {
    return N == 0;
}

// Возвращает размер массива
template <typename T, size_t N>
typename array<T, N>::size_type array<T, N>::size() {
    return N;
}

// Возвращает размер массива
template <typename T, size_t N>
typename array<T, N>::size_type array<T, N>::max_size() {
    return N;
}

// Меняем местами содержимое массива с содержимым массивом "other"
template <typename T, size_t N>
void array<T, N>::swap(array& other) {
    std::swap_ranges(data_, data_ + N, other.data_);
}
 
template <typename T, size_t N>
void array<T, N>::fill(const_reference value) {
    for (size_type i = 0; i < N; i++) {
        data_[i] = value;
    }
}

}  // namespace s21

#endif  // CCPP2_S21_CONTAINERS_2_SRC_S21_FUNCTIONS_S21_ARRAY_TPP
