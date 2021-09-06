#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "warmup.owelford.h"

#define BUFLEN 256
int test(char *testName, char *s1, char *s2, int expval, int exprc) {
    int rc, val, fail;
    char buf1[BUFLEN];
    char buf2[BUFLEN];

    fail = 0;

    if (s1 != NULL && s2 != NULL) {
        printf("test %s: call stringOps() with '%s' and '%s'; expect %d with return code %d\n", testName, s1, s2, expval, exprc);
    } else {
        if (s1 != NULL) {
            printf("test %s: call stringOps() with '%s' and NULL; expect %d with return code %d\n", testName, s1, expval, exprc);
        } else if (s2 != NULL) {
            printf("test %s: call stringOps() with NULL and '%s'; expect %d with return code %d\n", testName, s2, expval, exprc);
        } else {
            printf("test %s: call stringOps() with NULL and NULL; expect %d with return code %d\n", testName, expval, exprc);
        }
    }

    if (s1 != NULL && s2 != NULL) {
        strcpy(buf1, s1);
        strcpy(buf2, s2);

        rc = stringOps(buf1, buf2, &val);
        if (rc != exprc) {
            printf("FAIL test %s: expected return code %d; got %d\n", testName, exprc, rc);
            fail = 1;
        }
    }

    if (exprc == 0) {
        if (val != expval) {
            printf("FAIL test %s: expected value %d; got %d\n", testName, expval, val);
            fail = 1;
        }
    }

    if (fail == 0)
        printf("test %s: passed\n", testName);

    return fail;
}

int main() {
    int failCount, rc;
//char buf1[BUFLEN];
//char buf2[BUFLEN];

    failCount = 0;

    rc = test("S1", "now is the time", "i win again", 3, 0);
    failCount = failCount + rc;

    rc = test("S2", "for all good men", "", 0, 0);
    failCount = failCount + rc;

    rc = test("S3", "", "to come to the aid", 0, 0);
    failCount = failCount + rc;

    rc = test("S4", NULL, "to come to the aid", 0, 1);
    failCount = failCount + rc;

    rc = test("S5", "to come to the aid", NULL, 0, 1);
    failCount = failCount + rc;

    rc = test("S6", NULL, NULL, 0, 1);
    failCount = failCount + rc;

    if (failCount == 0)
        printf("all tests pass\n");
    else
        printf("%d tests fail\n", failCount);

    return failCount;
}
