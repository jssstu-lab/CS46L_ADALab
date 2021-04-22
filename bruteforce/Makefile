CC=gcc

selectionsort:
	mkdir -p bin
	$(CC) ./src/selectionSort.c -o ./bin/selectionsort 
	./bin/selectionsort
	gnuplot -p ./plot_scripts/plot_selection.gpi
	rm ./graph.txt

bubblesort:
	mkdir -p bin
	$(CC) ./src/bubbleSort.c -o ./bin/bubblesort 
	./bin/bubblesort
	gnuplot -p ./plot_scripts/plot_bubble.gpi
	rm ./graph.txt

stringmatching:
	mkdir -p bin
	$(CC) ./src/bruteforceStringMatching.c -o ./bin/stringmatching 
	./bin/stringmatching

clean:
	rm -rf ./bin