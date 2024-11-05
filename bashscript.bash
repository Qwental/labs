
# Цикл для создания директорий task1-task10
for i in {1..10}; do
  # Создаем директории task$i/src и task$i/include
  mkdir -p task$i/src task$i/include

  touch task$i/src/task3_${i}_functions.c
  touch task$i/include/task3_${i}_functions.h
  # Создаем файл task$i_main.c в директории task$i
  touch task$i/task3_${i}_main.c
done

echo "Директории task1-task10 с поддиректориями src и include и файлами taskX_main.c созданы."
