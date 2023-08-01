# Проект Разложения Холецкого (метод квадратного корня)

## Описание проекта

Этот проект реализует алгоритм разложения Холецкого, который используется для решения систем линейных уравнений. Это метод численного решения, применимый к положительно определенным симметричным матрицам.

## Структура проекта

/Cholesky_decomposition
/basic 
- main.c
/functions
- chol_decomp.c
- chol_decomp.h
/ files
- matrix.txt
- 
# Сложность алгоритма
Внешний цикл (переменная i) проходит от 0 до n, делая n итераций.
Средний цикл (переменная j) проходит от 0 до i+1, в среднем делая n/2 итераций.
Внутренний цикл (переменная k) проходит от 0 до j, в среднем делая n/4 итераций.
Учитывая, что каждый из этих циклов вложен в предыдущий, общая временная сложность алгоритма будет O(n^3).

## Инструкции по установке

1. Клонируйте репозиторий в вашу локальную систему "git clone https://github.com/aklto/Cholesky_decomposition".
2. Перейдите в корневую директорию проекта.

## Использование

1. Перейдите в директорию `Cholesky_decompositioin`.
2. Выполнить gcc -o output main.c functions/chol_decomp.c tests/chol_decomp_test.c
3. Запустите программу с помощью команды `./output`.
4. Результаты разложения Холецкого для матрицы, указанной в файле `matrix.txt`, будут выведены в консоль.
