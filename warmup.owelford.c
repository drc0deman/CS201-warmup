#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "warmup.owelford.h"

#define S_LEN 16
#define BUFLEN 256

//---------------------------------------------------------

//1.1
//
//int calculate(int a, int b, int *sum, int *quotient) {
//    *sum = a + b;
//    if (b != 0) {
//        *quotient = a / b;
//    } else {
//        return 1;
//    }
//
//    return 0;
//
//}
//
////---------------------------------------------------------

//1.2

int stringOps(char *s1, char *s2, int *count) {
    //check if array values are null
    if(s1 == NULL || s2 == NULL) {
        return 1;
    }

    //call sorting function
    sortAndRemoveDups(s1);
    sortAndRemoveDups(s2);

    int len1 = strlen(s1); 
    int len2 = strlen(s2);
    count = malloc(sizeof(int));
    *count = 0;
    
    //compare arrays of characters for matching chars
    for(int i = 0; i < len1; i++) {
        for(int j = 0; j < len2; j++) {
            if (s1[i] == s2[j]) {
                *count += 1;
            }
        }
    }

    printf("there are %d matching characters in s1 and s2\n", *count);

    return 0;
}
//---------------------------------------------------------

int compfcn(const void *p1, const void *p2) {
    char *c1, *c2;
    c1 = (char *) p1;
    c2 = (char *) p2;
    if (*c1 < *c2)
        return -1;
    else if (*c1 > *c2)
        return 1;
    else
        return 0;
}

//---------------------------------------------------------

int sortAndRemoveDups(char *s) {
    char buf[BUFLEN];
    int len, i, j;

    if (s == NULL)
        return 1;

    len = strlen(s);
    strcpy(buf, s);
    qsort(buf, len, sizeof(char), compfcn);

    j = 0;
    for (i=0; i<len; ++i) {
        if (buf[i] != ' ')
            s[j] = buf[i];
        if (buf[i+1] != buf[i] && buf[i] != ' ')
            j = j + 1;
    }
    s[j] = '\0';
    printf("sorted: |%s|\n", buf);
    printf("without dups: |%s|\n", s);
    return 0;
}


//---------------------------------------------------------

//1.3
//
//typedef struct {
//    char name[BUFLEN];
//    int id;
//} Record;
//
//

// int createRecord(char *name, int id, Record **rec) {
//     if (name == NULL || rec == NULL) {
//         return 1;
//     }
//     else if (id <= 1) {
//         return 1;
//     }
//     else {
//         rec = (Record **) malloc(sizeof(Record));
//         rec->name = "lwaxana troi";
//         rec->id = 19;
//         printf("the being is %s", rec);
//         return 0;
//     }
// }

//---------------------------------------------------------
//tester for 1.3

// int main() {
//     Record **record;
//     char name;
//     int id;

//    createRecord(name, id, record);

//    return 0;

// }