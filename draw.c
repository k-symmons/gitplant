
#define CANVAS_START "\033[?25l\033[32m"
#define EMPTY "                                                        \n"
#define SOIL "\033[43m                                                        \033[0m\n"
#define SOIL_LAST "\033[43m                                                        \033[0m"

char level_0[] = CANVAS_START
	EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY
	EMPTY EMPTY EMPTY EMPTY
	"                         -OOOO+                         \n"
	SOIL SOIL_LAST;

char level_1[] = CANVAS_START
	EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY
	"                        ...                             \n"
	"                      -OOOO+                            \n"
	"                        '''+                            \n"
	"                           +                            \n"
	"                           +                            \n"
	SOIL SOIL_LAST;

char level_2[] = CANVAS_START
	EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY
	"                           .                            \n"
	"                          .+                            \n"
	"                        ...+                            \n"
	"                      -OOO++                            \n"
	"                        ''++                            \n"
	"                           +                            \n"
	SOIL SOIL_LAST;

char level_3[] = CANVAS_START
	EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY EMPTY
	"                         ...                            \n"
	"                       -OOOO+                           \n"
	"                         '''+                           \n"
	"                            +                           \n"
	"                    OOO+    +                           \n"
	"                      '+++++                            \n"
	"                            +                           \n"
	"                            +                           \n"
	SOIL SOIL_LAST;

char level_4[] = CANVAS_START
	EMPTY EMPTY EMPTY EMPTY EMPTY
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

char level_5[] = CANVAS_START
	EMPTY EMPTY
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
	write(1, levels[lvl], strlen(levels[lvl]));
}
