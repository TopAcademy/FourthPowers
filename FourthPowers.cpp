/*
 * Задача "Четвертые степени"
 * -------------------------------------
 * Описать функцию, находящую 3 числа
 * в диапазоне от 2 до 10000, сумма
 * четвертых степеней цифр которых равна
 * самому числу
 */

#include <iostream>
using std::cout;
using std::endl;


// Функция разложения числа на разряды.
// Аргумент m - адрес массива, куда будут занесены цифры разрядов
// Вместе с адресом массива функция не принимает его размер
// так как предполагается, что массив передан "с запасом", то
// есть - его размер не менее 10 элементов, чтобы поместить
// цифры целого числа типа unsigned int.
// Функция возвращает число цифр.
short decomposition(unsigned x, short m[])
{
    short digit;                // хранилище очередной цифры
    short counter=0;            // счетчик разрядов
    do {
        digit = x % 10;
        m[counter++] = digit;
        x /= 10;
    } while (x > 0);
    return counter;
}


// Функция возведения в 4 степень
int power4(int x)
{
    int res = x;
    for (int i = 1; i < 4; i++)
        res *= x;
    return res;
}


// Старт!
int main()
{
    const short MAX_DIGITS = 10;            // максимальное число разрядов для int
    const int RANGE_MIN = 1000;             // в каком диапазоне ищем числа
    const int RANGE_MAX = 10000;
    short digits_array[MAX_DIGITS];         // вспомогательный массив для функции разложения числа на разряды
    short digits_count;
    int i, j, sum;
    // полный перебор чисел диапазона
    for (i = RANGE_MIN; i < RANGE_MAX; i++) {
        digits_count = decomposition(i, digits_array);
        // проверка на соответствие условию для числа
        sum = 0;
        for (j = 0; j < digits_count; j++) 
            sum += power4(digits_array[j]);
        if (sum == i) {
            // найдено число!
            cout << i << endl;
        }
    }
}
