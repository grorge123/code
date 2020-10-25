test -e ./$1.out && rm ./$1.out
g++ -std=c++11 -O2 -Wall -Wextra -fsanitize=undefined -fsanitize=address -o $1.out $1.cpp
test -e ./$1.out && ./$1.out
