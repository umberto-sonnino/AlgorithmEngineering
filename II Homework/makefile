CC = gcc
FLAGS = -O3
TEAM = Sonnino

all: mat-transp-perf make-matrix-file check-mat-transp seq-file-scan

mat-transp-perf: mat-transp-$(TEAM).o mat-transp-perf.c
	$(CC) $(FLAGS) mat-transp-perf.c mat-transp-$(TEAM).o \
		-o mat-transp-perf -lm

make-matrix-file: make-matrix-file.c
	$(CC) $(FLAGS) make-matrix-file.c -o make-matrix-file

mat-transp-$(TEAM).o: mat-transp-$(TEAM).c mat-transp.h
	$(CC) $(FLAGS) mat-transp-$(TEAM).c -c

check-mat-transp: check-mat-transp.c
	$(CC) $(FLAGS) check-mat-transp.c -lm -o check-mat-transp

seq-file-scan: seq-file-scan.c
	$(CC) $(FLAGS) seq-file-scan.c -o seq-file-scan

20000x20000.mat:
	time ./make-matrix-file 20000x20000.mat 20000

30000x30000.mat:
	time ./make-matrix-file 30000x30000.mat 30000

40000x40000.mat:
	time ./make-matrix-file 40000x40000.mat 40000

60000x60000.mat:
	time ./make-matrix-file 60000x60000.mat 60000

80000x80000.mat:
	time ./make-matrix-file 80000x80000.mat 80000

check:
	./make-matrix-file 4x4.mat 4
	./mat-transp-perf 4x4.mat 2
	./check-mat-transp 4x4.mat
	rm -f 4x4.mat
	./make-matrix-file 4000x4000.mat 4000
	./mat-transp-perf 4000x4000.mat 2000
	./check-mat-transp 4000x4000.mat
	rm -f 4000x4000.mat

test20000: 20000x20000.mat mat-transp-perf
	echo "\nSequential scan...\n";                            \
	time ./seq-file-scan 20000x20000.mat;                     \
	for b in 2500 5000 10000 20000; do                        \
	echo "\nTransposing matrix with block size "$$b"...\n";   \
	time ./mat-transp-perf 20000x20000.mat $$b;               \
	done

test30000: 30000x30000.mat mat-transp-perf
	echo "\nSequential scan...\n";                            \
	time ./seq-file-scan 30000x30000.mat;                     \
	for b in 2500 5000 10000 15000; do                        \
	echo "\nTransposing matrix with block size "$$b"...\n";   \
	time ./mat-transp-perf 30000x30000.mat $$b;               \
	done

test40000: 40000x40000.mat mat-transp-perf
	echo "\nSequential scan...\n";                            \
	time ./seq-file-scan 40000x40000.mat;                     \
	for b in 2500 5000 10000 20000; do                        \
	echo "\nTransposing matrix with block size "$$b"...\n";   \
	time ./mat-transp-perf 40000x40000.mat $$b;               \
	done

test60000: 60000x60000.mat mat-transp-perf
	echo "\nSequential scan...\n";                            \
	time ./seq-file-scan 60000x60000.mat;                     \
	for b in 2500 5000 10000 20000; do                        \
	echo "\nTransposing matrix with block size "$$b"...\n";   \
	time ./mat-transp-perf 60000x60000.mat $$b;               \
	done

test80000: 80000x80000.mat mat-transp-perf
	echo "\nSequential scan...\n";                            \
	time ./seq-file-scan 30000x30000.mat;                     \
	for b in 2500 5000 10000 20000; do                        \
	echo "\nTransposing matrix with block size "$$b"...\n";   \
	time ./mat-transp-perf 80000x80000.mat $$b;               \
	done

clean:
	rm -f mat-transp-perf check-mat-transp make-matrix-file   \
	seq-file-scan *.o *.mat
