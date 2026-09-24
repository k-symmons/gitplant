#include "plant.h"
#include <string.h>
#define CLEAR_TERMINAL "\033[2J"
#define GO_TO_START "\033[H"
#define HIDE_CURSOR "\033[?25l"
#define GREEN_TEXT "\033[32m"
#define BROWN_TEXT "\033[43m"
#define CANVAS_START CLEAR_TERMINAL GO_TO_START HIDE_CURSOR
#define EMPTY "                                                        \n"
#define SOIL "\033[43m                                                        \033[0m\n"
#define SOIL_LAST "\033[43m                                                        \033[0m"
#define START

char level_0[] = GREEN_TEXT
	EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY
	EMPTY EMPTY EMPTY EMPTY
	"                         -OOOO+                         \n"
	SOIL SOIL_LAST;

char level_1[] = GREEN_TEXT
	EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY
	"                        ...                             \n"
	"                      -OOOO+                            \n"
	"                        '''+                            \n"
	"                           +                            \n"
	"                           +                            \n"
	SOIL SOIL_LAST;

char level_2[] = GREEN_TEXT
	EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY
	"                           .                            \n"
	"                          .+                            \n"
	"                        ...+                            \n"
	"                      -OOO++                            \n"
	"                        ''++                            \n"
	"                           +                            \n"
	SOIL SOIL_LAST;

char level_3[] = GREEN_TEXT
	EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY
	"                         ...                            \n"
	"                       -OOOO+                           \n"
	"                         '''+                           \n"
	"                            +                           \n"
	"                    OOO+    +                           \n"
	"                      '+++++                            \n"
	"                            +                           \n"
	"                            +                           \n"
	SOIL SOIL_LAST;

char level_4[] = GREEN_TEXT
	EMPTY EMPTY EMPTY EMPTY
	"                          ...                           \n"
	"                        -OOOO+                          \n"
	"                          '''+                          \n"
	"                             +                          \n"
	"                    ...      +                          \n"
	"                  -OOOO+++++++                          \n"
	"                    '''      +   ...                    \n"
	"                             +++OOOO+                   \n"
	"                             +   '''                    \n"
	"                             +                          \n"
	"                             +                          \n"
	"                             +                          \n"
	SOIL SOIL_LAST;

char level_5[] = GREEN_TEXT
	EMPTY
	"                          ...                           \n"
	"                     ..+OOOOO+..                        \n"
	"                   -OOOOOOOOOOOOO+                      \n"
	"                     ''OOOOOOO''                        \n"
	"                       '''O'''                          \n"
	"                          +++                           \n"
	"                    ...    +                            \n"
	"                  -OOOO+++++                            \n"
	"                    '''    +    ...                     \n"
	"                           +++++OOOO+                    \n"
	"                           +     '''                     \n"
	"                           +                             \n"
	"                           +                             \n"
	"                           +                             \n"
	"                           +                             \n"
	SOIL SOIL_LAST;

void draw_plant(int lvl)
{
	char *levels[] = {level_0, level_1, level_2, level_3, level_4, level_5};
	if (lvl < 0)
		return;
	if (lvl > 5)
		lvl = 5;

	write(1, "\r", 1);
	write(1, levels[lvl], strlen(levels[lvl]));
}










void draw_progress(int points)
{
	char bar[] = "[--------------------]\n";
	int percent = (points % 1000) / 50;
	int i = 1;
	while (i<= percent)
		bar[i++] = '#';
	write(1, CANVAS_START, strlen(CANVAS_START));

	write(1, bar,strlen(bar));

}
