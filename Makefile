bin/main: obj/main.o
	cc obj/main.o -o bin/main

obj/%.o: src/%.c
	mkdir -p obj/
	cc -c -o $@ $<

clear:
	rm -rf obj/*
	rm -rf bin/*

loopkeys:
	cd utils/loopkeys && make
