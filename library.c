#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stddef.h>


int my_str_create(my_str_t *str, size_t buf_size) {
    str->capacity_m = buf_size;
    str->data = (char *) malloc(buf_size);
    str->size_m = 0;
    return 0;
}

//! Створити стрічку із буфером вказаного розміру із переданої С-стрічки.
//! Якщо розмір -- 0, виділяє блок, рівний розміру С-стрічки, якщо
//! менший за її розмір -- вважати помилкою.
//! Пам'ять виділяється динамічно.
//! 0 -- якщо все ОК, -1 -- недостатній розмір буфера, -2 -- не вдалося виділити пам'ять
int my_str_from_cstr(my_str_t *str, const char *cstr, size_t buf_size) {

    if (buf_size == 0) {
        printf("0");
        str->capacity_m = sizeof(cstr);
        str->data = (char *) malloc(sizeof(cstr));
        if (str->data == NULL) { return -2; }
        str->size_m = sizeof(cstr);
        for (int i = 0; i < sizeof(cstr); ++i) {
            str->data[i] = cstr[i];
        }

    } else {

        if (buf_size < sizeof(cstr)) {
            printf("1");
            return -1;
        } else {
            printf("2\n");
            str->capacity_m = buf_size;
            printf("capacity_m %d\n", str->capacity_m);
            str->data = (char *) malloc(buf_size);

            if (str->data == NULL) { return -2; }
            str->size_m = sizeof(cstr);
            printf("sizeof(cstr)%d\n", sizeof(cstr) * sizeof(char));
            for (int i = 0; i < sizeof(cstr); ++i) {
                str->data[i] = cstr[i];
            }
            printf("%s\n", cstr);
            printf("%s\n", str->data);
        }
    }

    return 0;
}

//! Звільнє пам'ять, знищуючи стрічку:
void my_str_free(my_str_t *str) {
//    твоє
}

//! Повертає розмір стрічки:
size_t my_str_size(const my_str_t *str) {
    return str->size_m;
}

//! Повертає розмір буфера:
size_t my_str_capacity(const my_str_t *str) {
    return str->capacity_m;
}

//! Повертає булеве значення, чи стрічка порожня:
int my_str_empty(const my_str_t *str) {
    if (str->size_m != 0) {
        return 1;
    }
    return 0;
}

//! Повертає символ у вказаній позиції, або -1, якщо вихід за межі стрічки
//! Тому, власне, int а не char
int my_str_getc(const my_str_t *str, size_t index) {
    if (str->size_m < index) {
        return -1;
    }

    return str->data[index];
}

//! Записує символ у вказану позиції (заміняючи той, що там був),
//! Повертає 0, якщо позиція в межах стрічки,
//! Поветає -1, не змінюючи її вмісту, якщо ні.
int my_str_putc(my_str_t *str, size_t index, char c) {
    if (str->size_m < index) {
        return -1;
    }
    str->data[index] = c;
    return 0;
}

//! Додає символ в кінець.
//! Повертає 0, якщо успішно, -1, якщо буфер закінчився.
int my_str_pushback(my_str_t *str, char c) {
//    твоє
    if (str->size_m + 1 > str->capacity_m){

    }
    return 0;
}

//! Викидає символ з кінця.
//! Повертає його, якщо успішно, -1, якщо буфер закінчився.
int my_str_popback(my_str_t *str) {
//    твоє
    return 0;
}

//! Копіює стрічку. Якщо reserve == true,
//! то із тим же розміром буферу, що й вихідна,
//! інакше -- із буфером мінімального достатнього розміру.
//! Старий вміст стрічки перед тим звільняє, за потреби.
int my_str_copy(const my_str_t *from, my_str_t *to, int reserve) {
    return 0;
}

//! Очищає стрічку -- робить її порожньою. Складність має бути О(1).
void my_str_clear(my_str_t *str) {
//    твоє
//    я думаю тут просто довжину треба поставити 1

}

//! Вставити символ у стрічку в заданій позиції, змістивши решту символів праворуч.
//! Якщо це неможливо, повертає -1, інакше 0.
int my_str_insert_c(my_str_t *str, char c, size_t pos) {
//    твоє
    return 0;
}

//! Вставити стрічку в заданій позиції, змістивши решту символів праворуч.
//! Якщо це неможливо, повертає -1, інакше 0.
int my_str_insert(my_str_t *str, const my_str_t *from, size_t pos) {
    //    твоє
    return 0;
}

//! Вставити C-стрічку в заданій позиції, змістивши решту символів праворуч.
//! Якщо це неможливо, повертає -1, інакше 0.
int my_str_insert_cstr(my_str_t *str, const char *from, size_t pos) {
    //    твоє
    return 0;
}

//! Додати стрічку в кінець.
//! Якщо це неможливо, повертає -1, інакше 0.
int my_str_append(my_str_t *str, const my_str_t *from) {
    return 0;
}

//! Додати С-стрічку в кінець.
//! Якщо це неможливо, повертає -1, інакше 0.
int my_str_append_cstr(my_str_t *str, const char *from) {
    //    твоє
    return 0;
}

//! Порівняти стрічки, повернути 0, якщо рівні (за вмістом!)
//! -1, якщо перша менша, 1 -- якщо друга.
//! Поведінка має бути такою ж, як в strcmp.
int my_str_cmp(my_str_t *str, const char *from) {
    return 0;
}

//! Скопіювати підстрічку, із beg включно, по end не включно ([beg, end)).
//! Якщо end виходить за межі str -- скопіювати скільки вдасться, не вважати
//! це помилкою. Якщо ж в ціловій стрічці замало місця, або beg більший
//! за розмір str -- це помилка. Повернути відповідний код завершення.
int my_str_substr(const my_str_t *str, const char *to, size_t beg, size_t end) {
    //    твоє
    return 0;
}


//! Повернути вказівник на С-стрічку, еквівалентну str.
//! Вважатимемо, що змінювати цю С-стрічку заборонено.
//! Якщо в буфері було зарезервовано на байт більше за макс. розмір, можна
//! просто додати нульовий символ в кінці та повернути вказівник data.
const char *my_str_get_cstr(my_str_t *str) {
    return 0;
}

//! Знайти першу підстрічку в стрічці, повернути номер її
//! початку або -1u, якщо не знайдено. from -- місце, з якого починати шукати.
//! Якщо більше за розмір -- вважати, що не знайдено.
size_t my_str_find(const my_str_t *str, const my_str_t *tofind, size_t from) {
    return 0;
}

//! Знайти перший символ в стрічці, повернути його номер
//! або -1u, якщо не знайдено. from -- місце, з якого починати шукати.
//! Якщо більше за розмір -- вважати, що не знайдено.
size_t my_str_find_c(const my_str_t *str, char tofind, size_t from) {

    return 0;
}

//! Знайти символ в стрічці, для якого передана
//! функція повернула true, повернути його номер
//! або -1u, якщо не знайдено:
size_t my_str_find_if(const my_str_t *str, int (*predicat)(char)) {
    return 0;
}

//! Прочитати стрічку із файлу. Повернути, 0, якщо успішно, -1,
//! якщо сталися помилки. Кінець вводу -- не помилка, однак,
//! слід не давати читанню вийти за межі буфера!
//! Рекомендую скористатися fgets().
size_t my_str_read_file(my_str_t *str, FILE *file) {
    return 0;
}

//! Аналог my_str_read_file, із stdin
size_t my_str_read(my_str_t *str) {
    return 0;
}




