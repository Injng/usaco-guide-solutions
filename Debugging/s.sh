for((i = 1; ; ++i)); do
  echo $i
  ./gen $i > int
  diff <(./643 < int) <(./test < int) || break
done