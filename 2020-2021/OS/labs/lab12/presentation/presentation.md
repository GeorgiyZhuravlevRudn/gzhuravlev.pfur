---
lang: ru-RU
title: "Презентация лабараторной работы №12"
author: "Журавлев Георгий Иванович"
---

# Цель работы
 Изучить основы программирования в оболочке ОС UNIX, научиться писать более сложные командные файлы с использованием логических управляющих конструкций и циклов.

# Ход работы.

### 1. Используя команды getopts grep, написал командный файл, который анализирует командную строку с ключами:
        – -i — прочитать данные из указанного файла;
        – -o — вывести данные в указанный файл;
        – -p - шаблон — указать шаблон для поиска;
        – -C — различать большие и малые буквы;
        – -n — выдавать номера строк.
        а затем ищет в указанном файле нужные строки, определяемые ключом -p.
![](screens/01.jpg)

### 2. Написал на языке Cpp программу, которая вводит число и определяет, является ли оно больше нуля, меньше нуля или равно нулю. Затем программа завершается с помощью функции exit(n), передавая информацию в о коде завершения в оболочку. Командный файл должен вызывать эту программу и, проанализировав с помощью команды $?, выдать сообщение о том, какое число было введено.
![](screens/02.jpg)
![](screens/03.jpg)
![](screens/04.jpg)

### 3. Написал командный файл, создающий указанное число файлов, пронумерованных последовательно от 1 до i. Число файлов, которые необходимо создать, передаётся в аргументы командной строки. Этот же командный файл должен уметь удалять все созданные им файлы (если они существуют).
![](screens/05.jpg)
![](screens/06.jpg)
![](screens/07.jpg)

### 4. Написал командный файл, который с помощью команды tar запаковывает в архив все файлы в указанной директории. Модифицировал его так, чтобы запаковывались только те файлы, которые были изменены менее недели тому назад (использовал команду find).
![](screens/10.jpg)
![](screens/11.jpg)
![](screens/09.jpg)

# Вывод
Благодаря этой лабараторной работе, я написал некоторые интересные скрипты , которые оказались сложнее предыдущих; развился в сфере взаимодействия с bash.