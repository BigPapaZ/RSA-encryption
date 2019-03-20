OPTS = -Wall

all: encrypt decrypt keygen

tests: numberTheory_TEST ReallyLongInt_TEST

encrypt: encrypt.cpp numberTheory.tpp numberTheory.hpp ReallyLongInt.o
	g++ ${OPTS} -o encrypt encrypt.cpp ReallyLongInt.o

decrypt: decrypt.cpp numberTheory.tpp numberTheory.hpp ReallyLongInt.o
	g++ ${OPTS} -o decrypt decrypt.cpp ReallyLongInt.o

keygen: keygen.cpp ReallyLongInt.o numberTheory.tpp numberTheory.hpp
	g++ ${OPTS} -o keygen keygen.cpp ReallyLongInt.o

ReallyLongInt.o: ReallyLongInt.cpp ReallyLongInt.hpp
	g++ ${OPTS} -c ReallyLongInt.cpp

numberTheory.o: numberTheory.hpp numberTheory.tpp
	g++ ${OPTS} -c numberTheory.tpp

numberTheory_TEST: numberTheory_TEST.cpp numberTheory.hpp ReallyLongInt.o catch.hpp
	g++ ${OPTS} -o numberTheory_TEST numberTheory_TEST.cpp ReallyLongInt.o

ReallyLongInt_TEST: ReallyLongInt_TEST.cpp ReallyLongInt.cpp ReallyLongInt.hpp catch.hpp
	g++ ${OPTS} --coverage -o ReallyLongInt_TEST ReallyLongInt_TEST.cpp ReallyLongInt.cpp

clean:
	rm -f *.o ReallyLongInt_TEST numberTheory_TEST encrypt decrypt keygen *.txt

cleancov:
	rm -f -r *.gcda *.gcno *.gcov *.info coverage

cleanemacs:
	rm *~

runtests:
	make clean
	make cleancov
	make tests
	./ReallyLongInt_TEST
	./numberTheory_TEST

runRSA:
	make clean
	make cleancov
	make all
	./keygen 1500450271 45095080578985454453 "public.txt" "private.txt"
	./encrypt "public.txt" "plain.txt" "encry.txt"
	./decrypt "private.txt" "encry.txt" "decry.txt"