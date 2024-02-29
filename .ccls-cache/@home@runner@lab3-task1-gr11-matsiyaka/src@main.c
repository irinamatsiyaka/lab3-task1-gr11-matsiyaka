#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Функция для подсчета суммы цифр числа
int sumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Сравнение для qsort
int compare(const void* a, const void* b) {
    int A = *(int*)a;
    int B = *(int*)b;
    return sumOfDigits(A) - sumOfDigits(B);
}

// Структура ZNAK
typedef struct {
    char Name[50];
    char ZOD[20];
    int DATE[3]; // год, месяц, день
} ZNAK;

typedef struct {
    char lastName[50];
    char firstName[50];
    char middleName[50];
    char phoneNumber[20];
    int postalCode;
    char country[50];
    char region[50];
    char district[50];
    char city[50];
    char street[50];
    int house;
    int apartment;
    char carMake[50];
    char carNumber[20];
    char techPassportNumber[20];
} CarOwner;

// Сравнение для сортировки ZNAK по дате рождения
int compareZNAK(const void* a, const void* b) {
    ZNAK* A = (ZNAK*)a;
    ZNAK* B = (ZNAK*)b;
    if (A->DATE[0] != B->DATE[0])
        return A->DATE[0] - B->DATE[0];
    else if (A->DATE[1] != B->DATE[1])
        return A->DATE[1] - B->DATE[1];
    else
        return A->DATE[2] - B->DATE[2];
}

int main() {
    printf("Задача 1: Сортировка массива по сумме цифр\n");
    int n = 5;
    int array[] = {123, 456, 789, 101, 32};

    qsort(array, n, sizeof(int), compare);

    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");

    // Задача 2: Ввод и сортировка структур ZNAK
    printf("Задача 2: Ввод и сортировка структур ZNAK\n");
    ZNAK znaki[10];
    for (int i = 0; i < 10; i++) {
        printf("Введите имя, знак зодиака и дату рождения (год месяц день) для элемента %d:\n", i + 1);
        if (scanf("%49s %19s %d %d %d", znaki[i].Name, znaki[i].ZOD, &znaki[i].DATE[0], &znaki[i].DATE[1], &znaki[i].DATE[2]) != 5) {
            printf("Ошибка ввода. Пожалуйста, введите данные заново.\n");
            i--; // Повторить ввод для текущего индекса
            while(getchar() != '\n'); // Очистить буфер ввода
            continue;
        }
    }

    qsort(znaki, 10, sizeof(ZNAK), compareZNAK);

    char searchZOD[20];
    printf("Введите знак зодиака для поиска: ");
    while(getchar() != '\n'); // Очистить буфер ввода
    if (scanf("%19s", searchZOD) != 1) {
        printf("Ошибка ввода.\n");
    } else {
        int found = 0;
        for (int i = 0; i < 10; i++) {
            if (strcmp(znaki[i].ZOD, searchZOD) == 0) {
                printf("%s, %s, %d-%d-%d\n", znaki[i].Name, znaki[i].ZOD, znaki[i].DATE[0], znaki[i].DATE[1], znaki[i].DATE[2]);
                found = 1;
            }
        }

        if (!found) {
            printf("Никто не родился под знаком %s.\n", searchZOD);
        }
    }
    printf("\n");

    // Задача 3: Вывод данных о владельцах автомобилей марки "Ваз"
    printf("Задача 3: Вывод данных о владельцах автомобилей марки \"Ваз\"\n");
    // Здесь должен быть дополнительный код для задачи 3, включая структуру CarOwner и логику обработки
CarOwner owners[3]; // Массив для хранения данных трех владельцев

    // Заполнение данных первого владельца
    strcpy(owners[0].lastName, "Иванов");
    strcpy(owners[0].firstName, "Иван");
    strcpy(owners[0].middleName, "Иванович");
    strcpy(owners[0].phoneNumber, "89991234567");
    owners[0].postalCode = 123456;
    strcpy(owners[0].country, "Россия");
    strcpy(owners[0].region, "Московская область");
    strcpy(owners[0].district, "Центральный");
    strcpy(owners[0].city, "Москва");
    strcpy(owners[0].street, "Ленина");
    owners[0].house = 1;
    owners[0].apartment = 10;
    strcpy(owners[0].carMake, "Ваз");
    strcpy(owners[0].carNumber, "А123ВС77");
    strcpy(owners[0].techPassportNumber, "1234567890");

    // Заполнение данных второго владельца
    strcpy(owners[1].lastName, "Петров");
    strcpy(owners[1].firstName, "Петр");
    strcpy(owners[1].middleName, "Петрович");
    strcpy(owners[1].phoneNumber, "89997654321");
    owners[1].postalCode = 654321;
    strcpy(owners[1].country, "Россия");
    strcpy(owners[1].region, "Нижегородская область");
    strcpy(owners[1].district, "Автозаводский");
    strcpy(owners[1].city, "Нижний Новгород");
    strcpy(owners[1].street, "Гагарина");
    owners[1].house = 5;
    owners[1].apartment = 20;
    strcpy(owners[1].carMake, "Ваз");
    strcpy(owners[1].carNumber, "В321СА77");
    strcpy(owners[1].techPassportNumber, "0987654321");

    // Заполнение данных третьего владельца
    strcpy(owners[2].lastName, "Сидоров");
    strcpy(owners[2].firstName, "Сергей");
    strcpy(owners[2].middleName, "Николаевич");
    strcpy(owners[2].phoneNumber, "89998887766");
    owners[2].postalCode = 112233;
    strcpy(owners[2].country, "Россия");
    strcpy(owners[2].region, "Свердловская область");
    strcpy(owners[2].district, "Ленинский");
    strcpy(owners[2].city, "Екатеринбург");
    strcpy(owners[2].street, "Мира");
    owners[2].house = 12;
    owners[2].apartment = 34;
    strcpy(owners[2].carMake, "Toyota");
    strcpy(owners[2].carNumber, "С123ММ77");
    strcpy(owners[2].techPassportNumber, "1122334455");

for (int i = 0; i < 3; i++) {
    printf("Проверка данных: %s, марка авто: %s\n", owners[i].lastName, owners[i].carMake);
}


    // Вывод информации о владельцах автомобилей марки "Ваз"
    for (int i = 0; i < 3; i++) {
        if (strcmp(owners[i].carMake, "Ваз") == 0) {
            printf("Владелец: %s %s %s, Телефон: %s\n", owners[i].lastName, owners[i].firstName, owners[i].middleName, owners[i].phoneNumber);
            printf("Адрес: %d, %s, %s, %s, %s, ул. %s, дом %d, кв. %d\n", owners[i].postalCode, owners[i].country, owners[i].region, owners[i].district, owners[i].city, owners[i].street, owners[i].house, owners[i].apartment);
            printf("Марка авто: %s, Номер авто: %s, Номер техпаспорта: %s\n\n", owners[i].carMake, owners[i].carNumber, owners[i].techPassportNumber);
        }
    }
    return 0;
}

