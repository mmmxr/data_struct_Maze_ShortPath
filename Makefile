.PHONY:clean

maze:maze.c seqstack.c
	gcc -o $@ $^ 
clean:
	rm -f maze
