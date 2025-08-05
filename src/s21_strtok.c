#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
    static char *buffer = S21_NULL;
    char *token_start = S21_NULL;

    // Если передана новая строка, используем её
    if (str != S21_NULL) {
        buffer = str;
    }

    // Проверяем что есть что обрабатывать
    if (buffer != S21_NULL && *buffer != '\0') {
        // Пропускаем ведущие разделители
        while (*buffer != '\0' && s21_strchr(delim, *buffer) != S21_NULL) {
            buffer++;
        }

        // Если нашли начало токена
        if (*buffer != '\0') {
            token_start = buffer;
            
            // Ищем конец токена
            while (*buffer != '\0' && s21_strchr(delim, *buffer) == S21_NULL) {
                buffer++;
            }

            // Завершаем токен
            if (*buffer != '\0') {
                *buffer = '\0';
                buffer++;
            } else {
                buffer = S21_NULL;  // Конец строки
            }
        } else {
            buffer = S21_NULL;  // Не нашли токен
        }
    }

    return token_start;
}