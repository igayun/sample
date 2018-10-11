all: clean build exec logtool logdecode

build:
	./tool/mkFileId.sh src > src/fileid.h
	cd log; gcc -c fastlog.c -I./
	cd src; gcc sample1.c sample2.c ../log/fastlog.o -I../log -I./

exec:
	cd src; ./a.out
	hexdump -C -v src/outlog.mem > mem.dump

logtool:
	cd src; gcc -E -c sample1.c -o sample1.o -I../log -I./
	cd src; gcc -E -c sample2.c -o sample2.o -I../log -I./
	./tool/genLogTable.sh > ./tool/log_decode/log_table.c
	cd tool/log_decode; gcc -g log_table.c log_decode.c -I./ -I../../src/ -o logdec.out

logdecode:
	tool/log_decode/logdec.out src/outlog.mem

clean:
	rm -rf ./*~ ./*/*~ ./*/*/*~ src/a.out src/outlog.mem ./*/*.o tool/log_decode/logdec.out
	rm -rf mem.dump

