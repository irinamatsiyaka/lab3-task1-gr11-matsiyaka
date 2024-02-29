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

// Задача 1: Сортировка массива по сумме цифр чисел
void task1() {
    int n;
    printf("Введите размер массива: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Ошибка выделения памяти\n");
        return;
    }

    printf("Введите элементы массива:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Сортировка массива по сумме цифр чисел
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (sumOfDigits(arr[j]) > sumOfDigits(arr[j + 1])) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("Отсортированный массив:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
}

// Задача 2: Описание структуры и ввод данных о людях
struct ZNAK {
    char Name[50];
    char ZOD[20];
    int DATE[3];
};

void task2() {
    struct ZNAK MASS[10];

    printf("Введите информацию о людях:\n");
    // Здесь должен быть код для ввода данных о людях
}

// Задача 3: Вывод данных о владельцах автомобилей марки "Ваз"
struct Car {
    char OwnerSurname[50];
    char OwnerName[50];
    char OwnerMiddleName[50];
    char Phone[20];
    char Address[100];
    char Brand[50];
    char CarNumber[20];
    char TechPassport[20];
};

void task3() {
    struct Car cars[10];

    printf("Данные про автомобили марки \"Ваз\":\n");
    // Здесь должен быть код для вывода данных о владельцах автомобилей марки "Ваз"
}

int main() {
    printf("Началась задача 1:\n");
    task1();
    printf("\nЗадача 1 завершена.\n\n");

    printf("Началась задача 2:\n");
    task2();
    printf("\nЗадача 2 завершена.\n\n");

    printf("Началась задача 3:\n");
    task3();
    printf("\nЗадача 3 завершена.\n");

    return 0;
}
