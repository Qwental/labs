#include <stdio.h>
#include <math.h>
#include <unistd.h>

#define WIDTH 40     // Ширина экрана
#define HEIGHT 20    // Высота экрана
#define PI 3.14159

int main() {
    // Параметры пончика и анимации
    float A = 0, B = 0;
    float i, j;
    
    // Основной цикл анимации
    while (1) {
        char buffer[HEIGHT][WIDTH];         // Буфер экрана
        float zbuffer[HEIGHT][WIDTH];       // Буфер глубины
        for (int y = 0; y < HEIGHT; y++) {  // Очистка буферов
            for (int x = 0; x < WIDTH; x++) {
                buffer[y][x] = ' ';
                zbuffer[y][x] = 0;
            }
        }
        
        // Визуализация пончика
        for (i = 0; i < 2 * PI; i += 0.07) {       // Углы для "малого" круга
            for (j = 0; j < 2 * PI; j += 0.02) {   // Углы для "большого" круга
                // Применение трехмерных координат и вращение
                float sinA = sin(A), cosA = cos(A), sinB = sin(B), cosB = cos(B);
                float sinI = sin(i), cosI = cos(i), sinJ = sin(j), cosJ = cos(j);
                
                float circle_x = cosJ + 2;  // "Большой" круг
                float circle_y = sinJ;      // "Малый" круг
                
                // Координаты в трехмерном пространстве
                float x = circle_x * (cosB * cosI + sinA * sinB * sinI) - circle_y * cosA * sinB;
                float y = circle_x * (sinB * cosI - sinA * cosB * sinI) + circle_y * cosA * cosB;
                float z = 1 / (circle_x * sinA * sinI + circle_y * sinA + 5);  // Изменение глубины
                int screen_x = (int)(WIDTH / 2 + WIDTH * z * x / 2);
                int screen_y = (int)(HEIGHT / 2 - HEIGHT * z * y / 2);
                
                // Отображение, если точка видима
                if (screen_x >= 0 && screen_x < WIDTH && screen_y >= 0 && screen_y < HEIGHT) {
                    if (z > zbuffer[screen_y][screen_x]) {
                        zbuffer[screen_y][screen_x] = z;
                        buffer[screen_y][screen_x] = ".,-~:;=!*#$@"[(int)(z * 8) % 12];
                    }
                }
            }
        }

        // Очистка экрана
        printf("\033[H\033[J");

        // Вывод буфера экрана
        for (int y = 0; y < HEIGHT; y++) {
            for (int x = 0; x < WIDTH; x++) {
                putchar(buffer[y][x]);
            }
            putchar('\n');
        }

        // Обновление углов вращения
        A += 0.04;
        B += 0.02;

        // Задержка для анимации
        usleep(30000);
    }

    return 0;
}
