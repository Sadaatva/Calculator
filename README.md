# Калькулятор на Qt

![Calculator](Calculator/Calculator/output.png)

## Обзор
Проект представляет собой приложение-калькулятор, созданное с использованием Qt. Оно позволяет выполнять базовые арифметические операции, такие как сложение, вычитание, умножение, деление, возведение в квадрат и извлечение квадратного корня.

## Особенности
- **Базовые операции**: Сложение, вычитание, умножение, деление.
- **Расширенные операции**: Возведение в квадрат, извлечение квадратного корня.

## Использование
Используйте кнопки интерфейса или клавиатуру для ввода чисел и выполнения операций.

## Описание функций
1) `Calculator::Calculator()`: Конструктор класса, инициализирующий интерфейс пользователя и связывающий кнопки с соответствующими слотами.
2) `void Calculator::sqrt()`: Вычисляет квадратный корень числа. При отрицательном числе выводит ошибку.
3) `void Calculator::square()`: Возводит число в квадрат.
4) `void Calculator::mathOperation(QString oprt)`: Сохраняет число и операцию для последующего выполнения.
5) `void Calculator::equal()`: Выполняет арифметическую операцию и отображает результат.
6) `void Calculator::pointAndNum()`: Обрабатывает ввод чисел и точки.
7) `void Calculator::zero()`: Вставляет ноль, если ввод пуст.
8) `void Calculator::clearAll()`: Удаляет последний символ или устанавливает "0", если ввод пуст.
9) `Calculator::~Calculator()`: Деструктор класса, удаляющий элементы интерфейса.
