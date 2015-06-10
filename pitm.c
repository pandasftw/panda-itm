//
//  pitm.c
//  
//
//  Created by Jakob Stendahl on 10.06.15.
//  Made for UNIX systems, specifically for OS X
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    // Print Logo
    printf("\n");
    
    int c;
    FILE *file;
    file = fopen("logo.c", "r");
    if (file) {
        while ((c = getc(file)) != EOF)
            putchar(c);
        fclose(file);
    }
    
    printf("            Panda In The Middle \n");
    
    // sjekk etter tillgang til ip_forward-fila
    char testForValue;
    char commandResult;
    
    testForValue = system("sysctl -w net.inet.ip.forwarding");
    printf(testForValue);
    
    char stringvalue;
    if (testForValue == "net.inet.ip.forwarding: 0") {
        
        commandResult = system("sysctl -w net.inet.ip.forwarding=1");
        printf(commandResult);
        
    } else {
        
        printf("YES! \n");
        
    }
    
    
    printf("Goodbye :) \n");
    return 0;
}