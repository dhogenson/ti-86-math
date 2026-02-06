#ifndef MENU_H
#define MENU_H

typedef void (*func_p)(void);

int menu(func_p functions[], char *names[], int names_length);

#endif
