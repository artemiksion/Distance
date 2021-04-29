Условие задачи:
Рассмотрим целочисленный массив a длины n. Назовём расстоянием от индекса i до множества индексов S величину dist(i,S)=∑j∈S∣∣ai−aj∣∣.Зафиксируем целое число k. Рассмотрим функцию f(i)=min dist(i,S), где минимум берётся по множествам S размера k, не содержащим индекс i.Определите значение f(i) для всех i от 1 до n.
Формат ввода:
В первой строке заданы два целых числа n и k (2≤n≤300000, 1≤k<n), описанные в условии.Во второй строке содержится n целых чисел ai (1≤ai≤10^9) — элементы массива a.
Формат вывода:
Выведите n целых чисел: значения f(i) для i=1,i=2,…,i=n.
