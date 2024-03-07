all: gcov_report

test:
	gcc -c --coverage s21_math.c
	ar rcs s21_math.a s21_math.o
	ranlib s21_math.a
	gcc -c test.c
	gcc test.o s21_math.a -lcheck -lsubunit -lgcov -lm -o test
	rm -rf *.o *.a
	./test

s21_math.a:
	gcc -c s21_math.c
	ar rcs s21_math.a s21_math.o
	ranlib s21_math.a

gcov_report: test
	lcov -o s21_math.info -c -d .
	genhtml -o report s21_math.info
	open report/index.html
	rm -rf *.o *.a *.gcno *.gcda *.info test

clean: 
	rm -rf *.o *.a *.gcno *.gcda *.info report test
