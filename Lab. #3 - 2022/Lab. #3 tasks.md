# Лабораторная работа №3

## №1 - Экспедиция
Месклиниты собрались в экспедицию на край света. У них есть корабль, состоящий из **n × m** плотов, связанных между собой. У каждого плота есть своя грузоподъемность, а у каждого месклинита – своя масса. На каждом плотике может находиться не более одного месклинита. Если грузоподъемность выбранного плотика меньше массы месклинита, то бедный месклинит утонет при посадке.

Руководитель экспедиции продумывает рассадку по плотикам. Помогите ему определить, какому максимальному количеству месклинитов удастся отправиться в путь.

### ***Входные данные***

В первой строке даны числа **n** и **m** (**1 ≤ n, m ≤ 40**). В каждой из последующих nn строк содержится по **m** чисел, обозначающих грузоподъемность соответствующего плотика. В **(n+2)-ой** строке находится число **k** (**1 ≤ k ≤ 2000**) – ***количество месклинитов***. В **(n+3)-ей** строке содержатся **k** чисел, **i-ое** из которых – ***масса i-ого месклинита***. Все массы месклинитов и грузоподъемности плотиков – натуральные числа, не превышающие **10^9** .

### ***Выходные данные***

Требуется вывести одно число – максимально возможное **количество участников** экспедиции.

### ***Примечание***

Это задача на использование **сортировок**, поэтому при её решении **запрещено** использовать **структуры данных**, помогающие **искать** элементы в неупорядоченных наборах (*сеты, мапы, хеш-таблицы, деревья поиска и прочие*).

### ***Пример ввода / вывода***

**Input:**

3 2\
5 10\
7 5\
5 5\
6\
9 5 3 5 12 10

**Output:**

4