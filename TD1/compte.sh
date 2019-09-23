gcc -Wall -o exo3 exo3.c
./exo3 > nombres.data
sort -n nombres.data > nombres_tries.data
uniq nombres_tries.data > nombres_uniq.data
wc -l nombres_uniq.data
