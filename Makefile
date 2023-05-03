game: ./sources/main.c ./sources/resources.c ./sources/logger.c ./sources/console.c
	gcc -o $@ $^ -Iheaders
