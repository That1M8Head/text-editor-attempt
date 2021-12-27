/* Attempted Text Editor
 * By Arsalan Kazmi
 *
 * ed on negative steroids
 */

/* Header stuff */
#include <stdio.h>
#include <string.h>

/* Main function */
int main(int argc, char* argv[])
{
    /* Variable stuff */
    char str[100];
    FILE *textfile;

    /* Check if the user specified --overwrite
     * If it does, open the file in write mode, otherwise open it in append mode
     */
    if (argc > 1 && !strcmp(argv[1], "--overwrite")) {
	textfile = fopen("textfile.txt", "w");
    } else {
	textfile = fopen("textfile.txt", "a");
    }

    /* Startup message */
    puts("Welcome to Attempted Text Editor");
    puts("Start typing stuff or type '!exit' to exit");
    
    /* Main loop */
    while (strcmp(str, "!exit")) {
	fgets(str, 100, stdin);
	str[strcspn(str, "\n")] = 0;
	if (strcmp(str, "!exit")) {
	    fputs(str, textfile);
	    fputs("\n", textfile);
	} 
    }

    /* Close the file */
    fclose(textfile);

    return 0;
}
