#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Функция для вычисления суммы цифр числа
int sumOfDigits(int num) {
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// Структура для хранения информации о человеке
struct ZNAK {
    char Name[50];  // Фамилия и имя
    char ZOD[20];   // Знак зодиака
    int DATE[3];    // Дата рождения (год, месяц, число)
    struct Car {
        char OwnerSurname[50];    // Фамилия владельца автомобиля
        char OwnerName[50];       // Имя владельца автомобиля
        char OwnerMiddleName[50]; // Отчество владельца автомобиля
        char Phone[20];           // Номер телефона владельца автомобиля
        char Address[100];        // Домашний адрес владельца автомобиля
        char Brand[50];           // Марка автомобиля
        char CarNumber[20];       // Номер автомобиля
        char TechPassport[20];    // Номер техпаспорта автомобиля
    } CarInfo;
};

int main() {
    // Задаем массив MASS для хранения 10 элементов типа ZNAK
    struct ZNAK MASS[10];

    // Ввод данных о людях с клавиатуры и сортировка по дате рождения
    printf("Введите информацию о людях:\n");
    for (int i = 0; i < 10; i++) {
        printf("Человек %d:\n", i + 1);
        printf("Фамилия и имя: ");
        fgets(MASS[i].Name, 50, stdin);
        printf("Знак зодиака: ");
        fgets(MASS[i].ZOD, 20, stdin);
        printf("Дата рождения (год месяц число): ");
        scanf("%d %d %d", &MASS[i].DATE[0], &MASS[i].DATE[1], &MASS[i].DATE[2]);
        getchar(); // Чтение символа новой строки после scanf

        // Если введенная фамилия содержит слово "Ваз", запрашиваем дополнительную информацию про автомобиль
        if (strstr(MASS[i].Name, "Ваз")) {
            printf("Данные про автомобиль марки \"Ваз\":\n");
            printf("Фамилия владельца: ");
            fgets(MASS[i].CarInfo.OwnerSurname, 50, stdin);
            printf("Имя владельца: ");
            fgets(MASS[i].CarInfo.OwnerName, 50, stdin);
            printf("Отчество владельца: ");
            fgets(MASS[i].CarInfo.OwnerMiddleName, 50, stdin);
            printf("Номер телефона владельца: ");
            fgets(MASS[i].CarInfo.Phone, 20, stdin);
            printf("Домашний адрес владельца: ");
            fgets(MASS[i].CarInfo.Address, 100, stdin);
            printf("Марка автомобиля: ");
            fgets(MASS[i].CarInfo.Brand, 50, stdin);
            printf("Номер автомобиля: ");
            fgets(MASS[i].CarInfo.CarNumber, 20, stdin);
            printf("Номер техпаспорта автомобиля: ");
            fgets(MASS[i].CarInfo.TechPassport, 20, stdin);
        }
    }

    // Вывод информации о людях, родившихся под знаком зодиака, название которых вводится с клавиатуры
    char zodiac[20];
    printf("\nВведите название знака зодиака: ");
    fgets(zodiac, 20, stdin);

    printf("\nЛюди, родившиеся под знаком зодиака %s:\n", zodiac);
    int found = 0; // Флаг для отслеживания наличия людей с указанным знаком зодиака
    for (int i = 0; i < 10; i++) {
        if (strcmp(MASS[i].ZOD, zodiac) == 0) {
            printf("Фамилия и имя: %s", MASS[i].Name);
            printf("Дата рождения: %d.%d.%d\n", MASS[i].DATE[2], MASS[i].DATE[1], MASS[i].DATE[0]);
            found = 1; // Устанавливаем флаг, если найден человек с указанным знаком зодиака
        }
    }
    if (!found) {
        printf("Нет людей, родившихся под знаком зодиака %s\n", zodiac);
    }

    // Вывод данных про автомобили марки "Ваз"
    printf("\nДанные про автомобили марки \"Ваз\":\n");
    for (int i = 0; i < 10; i++) {
        if (strstr(MASS[i].Name, "Ваз")) {
            printf("Владелец %d:\n", i + 1);
            printf("Фамилия: %s", MASS[i].CarInfo.OwnerSurname);
            printf("Имя: %s", MASS[i].CarInfo.OwnerName);
            printf("Отчество: %s", MASS[i].CarInfo.OwnerMiddleName);
            printf("Номер телефона: %s", MASS[i].CarInfo.Phone);
            printf("Домашний адрес: %s", MASS[i].CarInfo.Address);
            printf("Марка автомобиля: %s", MASS[i].CarInfo.Brand);
            printf("Номер автомобиля: %s", MASS[i].CarInfo.CarNumber);
            printf("Номер техпаспорта: %s", MASS[i].CarInfo.TechPassport);
            printf("\n");
        }
    }

    return 0;
}
