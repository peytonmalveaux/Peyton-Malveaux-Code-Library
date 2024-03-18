#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "commands.h"


void chgDir(char* path, char* currDir) {
	if (chdir(path, currDir) == -1) {
		perror("We got a problem");
		return;
	}
	if ((getcwd(currDir, 1000)) == NULL) {
		perror("getcwd() error: couldn't get the current working directory.");
	}
	setenv("pwd", currDir, 1);

}
void showpid(int idList[]) {
	int i = 0;
	for (i; i < 5; i++) {
		printf("%d\n", idList[i]);
	}
	return;
 }

