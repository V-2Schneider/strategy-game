game: ./sources/main.c ./sources/resources.c ./sources/logger.c
	gcc -o $@ $^ -Iheaders
