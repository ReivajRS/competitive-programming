set -e
g++ E.cpp -o E
g++ gen.cpp -o gen
g++ checker.cpp -o checker
for((i=1;;++i)) do
  ./gen $i > input_file
  ./code < input_file > answer
  ./checker > checker_log
  echo "Passed test: " $i
  done