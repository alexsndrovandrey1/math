# math

## Реализация собственной версии математической библиотеки math.h.

### Библиотека math.h является стандартной библиотекой языка программирования C. Она предоставляет функции и константы для выполнения различных математических операций.

- Реализованные функции:
    
    * `int abs(int x)` - вычисляет абсолютное значение целого числа
    
    * `long double acos(double x)` - вычисляет арккосинус
    
    * `long double asin(double x)` - вычисляет арксинус
    
    * `long double atan(double x)` - вычисляет арктангенс
    
    * `long double ceil(double x)` - возвращает ближайшее целое число, не меньшее заданного значения
    
    * `long double cos(double x)` - вычисляет косинус
    
    * `long double exp(double x)` - возвращает значение e, возведенное в заданную степень
    
    * `long double fabs(double x)` - вычисляет абсолютное значение числа с плавающей точкой
    
    * `long double floor(double x)` - возвращает ближайшее целое число, не превышающее заданное значение
    
    * `long double fmod(double x, double y)` - остаток операции деления с плавающей точкой
    
    * `long double log(double x)` - вычисляет натуральный логарифм
    
    * `long double pow(double base, double exp)` - возводит число в заданную степень
    
    * `long double sin(double x)` - вычисляет синус
    
    * `long double sqrt(double x)` - вычисляет квадратный корень
    
    * `long double tan(double x)` - вычисляет тангенс

## Запуск

1. Для запуска потребуется компилятор gcc и утилита gcov и библиотека check.h:

- Утилита gcov является частью GNU Compiler Collection (GCC) и предназначена для анализа покрытия кода программ на языке C и C++.
- gcov предоставляет информацию о том, какие строки кода были выполнены и какие остались неиспользованными во время выполнения программы. Она позволяет определить, насколько хорошо код тестируется и какие части кода нуждаются в дополнительных тестах.
- В процессе компиляции программы с флагом -coverage, GCC внедряет в исходный код дополнительный код, который собирает данные о покрытии во время выполнения программы. Затем gcov используется для анализа этих данных и создания отчетов о покрытии.
- Отчеты, сгенерированные gcov, включают информацию о количестве выполненных и невыполненных строк кода, процентах покрытия для каждой строки и функции, а также другие метрики покрытия кода. Эти отчеты могут быть использованы для определения участков кода, которые нуждаются в дополнительных тестах, и для оценки общего покрытия кода тестами.

    > Для ОС Windows:
    Установите MinGW:

    1) Загрузите и установите MinGW (Minimalist GNU for Windows) с официального сайта: https://mingw.ru
    
    2) При установке выберите компоненты, включающие GCC (C Compiler), Binutils (GNU Binary Utilities) и MSYS (Minimal SYStem)..
    
    3) Добавьте путь к MinGW в переменную среды PATH:

        3.1. Откройте "Свойства системы" (нажмите Win + Pause/Break, затем выберите "Дополнительные параметры системы").
        
        3.2. Перейдите на вкладку "Дополнительно" и нажмите на кнопку "Переменные среды".
        
        3.3. В разделе "Системные переменные" найдите переменную "Path" и нажмите на кнопку "Изменить".
        
        3.4. Добавьте путь к директории bin в установленном MinGW (например, C:\MinGW\bin) в качестве нового значения переменной PATH.
        
        3.5. Нажмите "ОК", чтобы сохранить изменения.

    4) Установите утилиту gcov:

        4.1. Откройте командную строку (нажмите Win + R, введите "cmd" и нажмите Enter).
        
        4.2. Выполните команду 

        `mingw-get install gcov` 
        
        для установки утилиты gcov с использованием установленного MinGW.
    
    5) Установите необходимые зависимости:

        5.1. Откройте командную строку (нажмите Win + R, введите "cmd" и нажмите Enter).
        
        5.2. Выполните команду `mingw-get install msys` , чтобы установить MSYS, который содержит необходимые инструменты для сборки и установки библиотек.
    
    6) Загрузите и скомпилируйте библиотеку check:

        6.1. Загрузите исходный код библиотеки check с официального сайта: https://libcheck.github.io/check/
        
        6.2. Распакуйте архив с исходным кодом.
        
        6.3. Откройте командную строку в папке с распакованными исходными файлами.
        
        6.4. Выполните следующие команды:
        
        ```
        ./configure
        make
        make install
        ```

    > Для ОС Linux: 
    ```
    sudo apt-get install gcc
    sudo apt-get install gcov
    sudo apt-get install check
    ```

2. Склонируйте репозиторий в удобную для вас диреторию

3. Для демонстрации работы собственной реализации библиотеки math:

    3.1. Перейдите в директорию `/src/`

    3.2. Возможности Makefile:

        * make или make gcov_repor -  сгенерирует отчет (HTML) покрытия кода unit-тестами.
        
        * make test - прогонит unit-тесты и выведет результат в консоль.
        
        * make s21_math.a - сборка проекта. 
        
        * make clean - удалит все исполняемые файлы. 


