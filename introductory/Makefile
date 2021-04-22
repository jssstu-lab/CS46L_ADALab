CC=gcc

gcd:
	mkdir -p bin
	$(CC) ./src/gcd.c -o ./bin/gcd
	./bin/gcd
	gnuplot -p ./plot_scripts/plot_gcd.gpi
	rm euclid.txt cicm.txt msm.txt 

clean:
	rm -rf ./bin