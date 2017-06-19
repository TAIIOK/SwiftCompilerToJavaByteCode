del bison_tab.c
del bison_tab.h
bison.exe -d --verbose --debug bison.y
move bison.tab.h bison_tab.h
move bison.tab.c bison_tab.c