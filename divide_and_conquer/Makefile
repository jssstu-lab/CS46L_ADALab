CC=gcc

arraysum:
	mkdir -p bin
	$(CC) ./src/array_sum.c -o ./bin/array_sum 
	./bin/array_sum
	gnuplot -p ./plot_scripts/array_sum.gpi
	rm ./graph.txt

mergesort:
	mkdir -p bin
	$(CC) ./src/merge_sort.c -g -o ./bin/merge_sort
	./bin/merge_sort
	gnuplot -p ./plot_scripts/merge_sort.gpi
	rm ./graph.txt

quicksort:
	mkdir -p bin
	$(CC) ./src/quick_sort.c -o ./bin/quick_sort
	./bin/quick_sort
	gnuplot -p ./plot_scripts/quick_sort.gpi
	rm ./graph.txt

clean:
	rm -rf ./bin