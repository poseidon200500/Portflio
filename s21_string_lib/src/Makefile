#Флаги
GCC= gcc -c
GCCG= gcc
FLAGS= -Wall -Werror -Wextra -std=c11
GCOV_FLAGS= -fprofile-arcs -ftest-coverage -fPIC
ifeq ($(UNAME),Linux)
	LDFLAGS=-lcheck_pic -lsubunit -lm -lrt -lpthread
	OPEN_CM=xdg-open
endif
ifeq ($(UNAME),Darwin)
	LDFLAGS=-lcheck -lm
	OPEN_CM=open
endif

#-fprofile-arcs -ftest-coverage
#файлы проекта
F_C_1= functions/*.c
F_C_2= functions/add_funcs/*.c
F_C_3= functions/s21_sprintf/*.c
F_C_4= functions/s21_sscanf/*.c
F_H= s21_string.h
F_C= ${F_C_1} ${F_C_2} ${F_C_3} ${F_C_4}
#файлы тестов
FT_H= tests/s21_string_tests.h
FT_C= tests/*.c
SOURCE_TESTS= -lcheck -o test

#======================================== ALL =========================================================================
all: clean s21_string.a gcov_report

# ======================================= Компиляция тестов ===========================================================
# -pthread -lcheck_pic -pthread -lrt -lm -lsubunit // флаги сообщающие путь к библиотеке check  убунту
test: clean s21_string.a
	${GCCG} ${FLAGS} ${SOURCE_TESTS} tests/*.c s21_string.a ${LDFLAGS} 
	./test


# ======================================= Вывод тестов в HTML отчет ===================================================
# gcov_report: clean gs21_string.a
# 	${GCCG} ${FLAGS} ${FT_C} s21_string.a ${SOURCE_TESTS} ${LDFLAGS} ${GCOV_FLAGS}
# 	./test
# 	rm -rf *_tests.gcda *_tests.gcno main.gc*
# 	gcovr -p
# 	mkdir report
# 	gcovr -p --html-details -o report/report.html
# 	open report/report.html
# 	rm -rf *.gcda *gcno

gcov_report: clean s21_string.a
	${GCCG} ${FLAGS} ${FT_C} s21_string.a ${SOURCE_TESTS} ${LDFLAGS} ${GCOV_FLAGS}
	./test
	lcov -t "String_tests" -o test_rez.info -c -d .
	genhtml -o report test_rez.info
	rm *.gcda *.gcno *.info
	open report/index.html

# ======================================= Тесты на утечки =============================================================
tests_valgrind: test
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=res_leak.txt ./test
	grep -e ERROR res_leak.txt
	rm -rf *.gcda
tests_valgrind_gcov: gcov_report
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=res_leak.txt ./test
	grep -e ERROR res_leak.txt
	rm -rf *.gcda
# ======================================= Сборка библиотеки в файл s21_string.a =========================================
s21_string.a: clean
	${GCC} ${FLAGS} ${F_C}
	ar rc s21_string.a *.o
	ranlib s21_string.a
	make clean.o

gs21_string.a: clean 
	${GCC} ${FLAGS} ${F_C} ${GCOV_FLAGS}
	ar rc s21_string.a *.o
	ranlib s21_string.a
	make clean.o

# ======================================= Работа со стилями в проекте =================================================
style:
	clang-format -n ${F_C} ${F_H} ${FT_C} ${FT_H}
	
style_red:
	clang-format -i ${F_C} ${F_H} ${FT_C} ${FT_H}

# ======================================= Clean =======================================================================
clean.o:
	rm -rf *.o
clean.a:
	rm -rf *.a
clean.gcno:
	rm -rf *.gcno
clean.gcda:
	rm -rf *.gcda
clean:
	rm -rf *.o
	rm -rf *.a
	rm -rf test
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *.gcov
	rm -rf *.txt
	rm -rf *.html
	rm -rf *.css
	rm -rf report
