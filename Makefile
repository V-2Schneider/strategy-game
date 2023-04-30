game: ./sources/pipes.c ./sources/resources.c ./sources/logger.c
	gcc -o $@ $^ -Iheaders
