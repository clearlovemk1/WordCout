#include <stdio.h>
int main(int argc, char *argv[]) {
    FILE *fp;
    int cnt = 0;
    int c;
    if (argc != 3) {
        printf("Usage: %s <option> <file_name>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[2], "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    if (argv[1][1] == 'c') { 
        while ((c = fgetc(fp)) != EOF) {
            if(c != ',') {
                cnt++;
            }
        }
        printf("×Ö·ûÊý: %d\n", cnt);
    } else if (argv[1][1] == 'w') { 
        int prev = ' '; 
        while ((c = fgetc(fp)) != EOF) {
            if (c == ' ' || c == ',' || c == '\t' || c == '\n') {
                if (prev != ' ' && prev != ',' && prev != '\t' && prev != '\n') {
                    cnt++;
                }
            }
            prev = c;
        }
        if (prev != ' ' && prev != ',' && prev != '\t' && prev != '\n') {
            cnt++;
        }
        printf("µ¥´ÊÊý: %d\n", cnt);
    }

    fclose(fp);
    return 0;
}
