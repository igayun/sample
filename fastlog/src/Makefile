all:
	../tool/mkFileId.sh . > fileid.h
	cd ../log; gcc -c fastlog.c -I./
	gcc sample1.c sample2.c ../log/fastlog.o -I../log -I./

clean:
	rm -rf ../*/*~ a.out outlog.mem
	cd ../log; rm -rf *.o