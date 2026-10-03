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

const int suspiciousCount = sizeof(suspicious) / sizeof(suspicious[0]);
const int credibleCount   = sizeof(credible) / sizeof(credible[0]);

int countMatches(char text[], const char *list[], int n)
{
    int matches = 0;
    for (int i = 0; i < n; i++) {
        if (strstr(text, list[i]) != NULL) {
            matches++;
        }
    }
    return matches;
}

void toLowerCopy(const char src[], char dest[])
{
    size_t i;
    for (i = 0; src[i] != '\0' && i < MAX - 1; i++) {
        dest[i] = (char)tolower((unsigned char)src[i]);
    }
    dest[i] = '\0';
}

int countCapitals(const char text[])
{
    int count = 0;
    for (size_t i = 0; text[i] != '\0'; i++) {
        if (isupper((unsigned char)text[i])) {
            count++;
        }
    }
    return count;
}

int countExclamations(const char text[])
{
    int count = 0;
    for (size_t i = 0; text[i] != '\0'; i++) {
        if (text[i] == '!') {
            count++;
        }
    }
    return count;
}

void clearInputLine(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void analyse(char text[])
{
    char lower[MAX];
    int length = (int)strlen(text);

    toLowerCopy(text, lower);

    int fake     = countMatches(lower, suspicious, suspiciousCount);
    int trust    = countMatches(lower, credible, credibleCount);
    int capitals = countCapitals(text);   /* original text: case matters */
    int excl     = countExclamations(text);

    int score = fake * 2;
    if (excl >= 2) {
        score += 2;
    }

    if (length > 0 && (capitals * 100 / length) > 40) {
        score += 2;
    }
    score -= trust;

    printf("\n--- Analysis ---\n");
    printf("Suspicious words found : %d\n", fake);
    printf("Credible words found   : %d\n", trust);
    printf("Exclamation marks      : %d\n", excl);
    printf("Fake score             : %d\n", score);

    if (score >= 3) {
        printf("Result: LIKELY FAKE NEWS - verify from trusted sources!\n");
    } else if (score >= 1) {
        printf("Result: SUSPICIOUS - check the source before sharing.\n");
    } else {
        printf("Result: LIKELY REAL NEWS.\n");
    }
}

int main(void)
{
    char text[MAX];
    char again = 'y';

    printf("===== FAKE NEWS DETECTION SYSTEM =====\n");

    while (again == 'y' || again == 'Y') {
        printf("\nEnter a news headline/text:\n> ");

        if (fgets(text, MAX, stdin) == NULL) {
            break;
        }

        if (strchr(text, '\n') == NULL) {
            clearInputLine();
        }
        text[strcspn(text, "\n")] = '\0';

        analyse(text);

        printf("\nCheck another? (y/n): ");
        if (scanf(" %c", &again) != 1) {
            break;
        }

        clearInputLine();
    }

    printf("Stay informed, stay safe!\n");
    return 0;
}