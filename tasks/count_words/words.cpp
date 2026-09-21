//
// Created by Ruslan on 21.09.2026.
//

#include "words.h"

int countWords(const char* text, const char* target) {

    int count = 0;
    int i = 0;

    while (text[i] != '\0') {
        while (text[i] == ' ') i++;

        int start = i;

        while (text[i] != ' ' && text[i] != '\0') i++;

        int j = 0;

        while (target[j] == text[start + j] && target[j] != '\0') j++;

        if (target[j] == '\0' && text[j + start] == '\0' || text[start + j] == ' ') count++;
    }
    return count;
}