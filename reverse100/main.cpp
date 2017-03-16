//
//  main.cpp
//  gameofpwners1
//
//  Created by Onur on 23/01/2017.
//

#include <iostream>
#include <sys/ptrace.h>

#define KEY_LENGTH 29


char map[5] = {1, 3, 3, 7};
char comp[KEY_LENGTH] = "fbnbnespofqtfbnbnespofqt0103";
void create(char str1[KEY_LENGTH], char str2[KEY_LENGTH]);

//gameofpwnersgameofpwners1234

int main(int argc, const char * argv[]) {

    char in_string[KEY_LENGTH];
    char new_string[KEY_LENGTH];
    
    ptrace(PT_DENY_ATTACH, 0, 0, 0);
    
    std::cout << "Enter the key: \n";
    std::cin >> in_string;
    
    create(in_string, new_string);
    //std::cout << new_string << std::endl;
    
    if (strcmp(new_string, comp) == 0)
        std::cout << "congratz. your flag is: GoP_{" << in_string << "}" << std::endl;
    else
        std::cout << "try harder." << std::endl;
    
    return 0;
}


void create(char str1[KEY_LENGTH], char str2[KEY_LENGTH]) {

    for (int i = 0; i < KEY_LENGTH; i += 4) {
        str2[i] = str1[i] ^ map[0];
        str2[i + 1] = str1[i + 1] ^ map[1];
        str2[i + 2] = str1[i + 2] ^ map[2];
        str2[i + 3] = str1[i + 3] ^ map[3];
    }
    str2[KEY_LENGTH - 1] = '\0';
}
