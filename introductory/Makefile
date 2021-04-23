CC=gcc

gcd:
	mkdir -p bin
	$(CC) ./src/gcd.c -o ./bin/gcd
	./bin/gcd
	gnuplot -p ./plot_scripts/plot_gcd.gpi
	rm euclid.txt cicm.txt msm.txt 

search:
	mkdir -p bin
	$(CC) ./src/search.c -o ./bin/search
	./bin/search
	gnuplot -p ./plot_scripts/plot_search.gpi
	rm linear.txt binary.txt

clean:
	rm -rf ./bin