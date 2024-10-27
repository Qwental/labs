#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void show_dice(int face) {
    // Выводим стороны кубика в зависимости от выпавшего значения
    switch (face) {
        case 1:
            printf("┌───────┐\n");
            printf("│       │\n");
            printf("│   ●   │\n");
            printf("│       │\n");
            printf("└───────┘\n");
            break;
        case 2:
            printf("┌───────┐\n");
            printf("│ ●     │\n");
            printf("│       │\n");
            printf("│     ● │\n");
            printf("└───────┘\n");
            break;
        case 3:
            printf("┌───────┐\n");
            printf("│ ●     │\n");
            printf("│   ●   │\n");
            printf("│     ● │\n");
            printf("└───────┘\n");
            break;
        case 4:
            printf("┌───────┐\n");
            printf("│ ●   ● │\n");
            printf("│       │\n");
            printf("│ ●   ● │\n");
            printf("└───────┘\n");
            break;
        case 5:
            printf("┌───────┐\n");
            printf("│ ●   ● │\n");
            printf("│   ●   │\n");
            printf("│ ●   ● │\n");
            printf("└───────┘\n");
            break;
        case 6:
            printf("┌───────┐\n");
            printf("│ ●   ● │\n");
            printf("│ ●   ● │\n");
            printf("│ ●   ● │\n");
            printf("└───────┘\n");
            break;
    }
}

int main() {
    // Инициализация генератора случайных чисел
    srand(time(NULL));

    printf("Бросаем кубик...\n");

    // Анимация вращения
    for (int i = 0; i < 10; i++) {
        int random_face = (rand() % 6) + 1;  // Случайное число от 1 до 6
        printf("\033[H\033[J");  // Очистка консоли
        show_dice(random_face);  // Отображаем текущую "сторону" кубика
        usleep(100000);          // Задержка 0.1 секунды
    }

    // Финальное значение кубика
    int final_face = (rand() % 6) + 1;
    printf("\033[H\033[J");      // Очистка консоли
    show_dice(final_face);       // Отображаем финальное значение
    printf("Выпало число: %d\n", final_face);

    return 0;
}
