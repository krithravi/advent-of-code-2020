#include <stdio.h>
#include <string.h>

int main () {
    char myStr [100] = "Hello World";
    char tmp [100] = "rld";

    printf("%s\n", myStr);


    printf("%d\n", *strstr(myStr, tmp));
}

