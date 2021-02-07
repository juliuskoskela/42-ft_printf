#!/bin/bash
mv eval_tests/test_usr.c.test eval_tests/test_usr.c
gcc eval_tests/test_usr.c libftprintf.a
mv eval_tests/test_usr.c eval_tests/test_usr.c.test

./a.out a > usr.txt

mv eval_tests/test_lib.c.test eval_tests/test_lib.c
gcc eval_tests/test_lib.c libftprintf.a
mv eval_tests/test_lib.c eval_tests/test_lib.c.test

./a.out a > lib.txt
valgrind --leak-check=full ./a.out a > leaks.txt

diff --suppress-common-lines -y usr.txt lib.txt > diff.txt
wc -l diff.txt

mv eval_tests/test_usr.c.test eval_tests/test_usr.c
gcc eval_tests/test_usr.c libftprintf.a
mv eval_tests/test_usr.c eval_tests/test_usr.c.test

./a.out + > additional_tests.txt