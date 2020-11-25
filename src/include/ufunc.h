#ifndef UFUNC_H
#define UFUNC_H

void add(int argc, char **args);
void mul(int argc, char **args);
void help(void);
void ufuncs(void);
void umem_status(void);
void mem_hops(void);
void print_mem(int argc, char **args);
void mem_poke(int argc, char **args);
void echo(int argc, char **args);
void time(int argc, char **args);
void udefrag(void);

/* in music.c */
void sans_undertale(void);
void happy_birthday(void);

#endif
