#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 300

const char *suspicious[] = {
    "shocking", "unbelievable", "miracle", "secret", "exposed",
    "hoax", "conspiracy", "you won't believe", "share before deleted",
    "100%% true", "doctors hate", "cure for all", "leaked", "banned"
};

const char *credible[] = {
    "according to", "officials said", "report", "study", "research",
    "confirmed", "government", "university", "published"
};