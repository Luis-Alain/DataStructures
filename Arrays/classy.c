/*"Classy" is interchangable with "fancy".
If you add fancy-looking items, you will increaseyour "classiness".
Create a function in "Classy" that takes a string as input and adds it to the "items" list.
Another function should calculate the "classiness" value based on the items.
The following items have classiness points associated with them:
"tophat" = 2
"bowtie" = 4
"monocle" = 5
Everything else has 0 points.*/

#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

struct Classy{
    char items[MAX_ITEMS][20];
    int itemCount;
};

void addItem(struct Classy *classy, const char *item){
    strcpy(classy->items[classy->itemCount], item); 
    classy->itemCount++; // increments the itemCount member of the Classy struct.
}

int getClassiness(struct Classy *classy){
    int classiness = 0;
    for (int i = 0; i < classy->itemCount; i++){
        if (strcmp(classy->items[i], "tophat") == 0){
            classiness += 2;
        }
        else if (strcmp(classy->items[i], "bowtie") == 0){
            classiness += 4;
        }
        else if (strcmp(classy->items[i], "monocle") == 0){
            classiness += 5;
        }
    }
    return classiness;
}

int main(){
    struct Classy me;
    me.itemCount = 0;

    // Test cases
    printf("%d\n", getClassiness(&me)); // Should be 0

    addItem(&me, "tophat");
    printf("%d\n", getClassiness(&me)); // Should be 2

    addItem(&me, "bowtie");
    addItem(&me, "jacket");
    addItem(&me, "monocle");
    printf("%d\n", getClassiness(&me)); // Should be 11

    addItem(&me, "bowtie");
    printf("%d\n", getClassiness(&me)); // Should be 15

    return 0;
}