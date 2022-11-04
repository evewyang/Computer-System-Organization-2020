#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXWORDLENGTH 20
char word[MAXWORDLENGTH];
int  bufp = 0;

struct node1d {
    struct node1d *next;//pointer to the next node 1D
    char *name;//name of node 1D
};
struct node2d {
    struct node1d *first;//head of node 1D
    char *name;//name of node 2D
    struct node2d *down;//pointer to the below node 2D
};
//global var: save the 2d head
struct node2d *head = NULL;

//set the 2d head
void initialize2d(char *name){
    head = (struct node2d*)malloc(sizeof(struct node2d));
    head->name = (char*)malloc(sizeof(MAXWORDLENGTH));
    strcpy(head->name,name);
    head->first = NULL;
    head->down = NULL;
    // head->name = name; 
}
//set the 1d head
void initialize1d(char *name, struct node2d *this2D){
    struct node1d *new1d = (struct node1d*)malloc(sizeof(struct node1d));
    new1d->name = (char*)malloc(sizeof(MAXWORDLENGTH));
    strcpy(new1d->name,name);
    // new1d->name = name;
    new1d->next = NULL;
    this2D->first = new1d;
}
//2.1.1 Append 2D Node
int appendRear2D(char *name){
    if (head == NULL){
        initialize2d(name);
        return 0;
    }
    //initialise this new node2d
    struct node2d *new2d = (struct node2d*)malloc(sizeof(struct node2d));
    //space for name
    new2d->name = (char*)malloc(sizeof(MAXWORDLENGTH));
    strcpy(new2d->name,name);
    // new2d->name = name;
    new2d->first = NULL;
    new2d->down = NULL;
    struct node2d *ptr = head;
    //find the end of the node2d List 
    while (ptr != NULL){
        if (ptr->down == NULL){
            //found end, append
            ptr->down = new2d;
            return 0;
        }
        ptr = ptr->down;
        
    }
    return 0; 
}
//2.1.2 Append After 2D Node
int appendAfter2D (char *name, char *afterName){
    if (head == NULL){
        initialize2d(name);
        return 0;
    }
    struct node2d *ptr = head;
    while (ptr != NULL){
        //if find node2D with the afterName
        if (strcmp(ptr->name,afterName) == 0){
            //construct a node2D after
            struct node2d *new2d = (struct node2d*)malloc(sizeof(struct node2d));
            //space for name
            new2d->name = (char*)malloc(sizeof(MAXWORDLENGTH));
            strcpy(new2d->name,name);
            // new2d->name = name;
            new2d->first = NULL;
            new2d->down = ptr->down;
            ptr->down = new2d;
            return 0;
        }
        ptr = ptr->down;
        
    }
    printf("Error: node2D '%s' is not found.\n\n",afterName);
    return 1;
}
//2.1.3 Append 1D Node
int appendRear1D (char *name, char *name2D){
    struct node2d *ptr = head;
    while (ptr != NULL){
        if (strcmp(ptr->name,name2D) == 0){
            //if the head2D's first is not initialized, add the name to the 2D's first;
            if (ptr->first == NULL){
                initialize1d(name, ptr);
                return 0;
            }
            //if the head2D's first is initialized, create new 1D and append;
            struct node1d *pos = ptr->first;
            while (pos != NULL){
                if (pos->next == NULL){
                    struct node1d *new1d = (struct node1d*)malloc(sizeof(struct node1d));
                    new1d->name = (char*)malloc(sizeof(MAXWORDLENGTH));
                    strcpy(new1d->name,name);
                    // new1d->name = name;
                    new1d->next = NULL;
                    pos->next = new1d;
                    return 0;
                }
                pos = pos->next;
            }
        }
        ptr = ptr->down;
    }
    printf("Error: node2D '%s' is not found.\n\n",name2D);
    return 1;
}
//2.1.4 Append After 1D Node
int appendAfter1D (char *name, char *afterName1D){
    //find the node named *name first
    struct node2d *ptr = head;
    while (ptr != NULL){
        struct node1d *pos = ptr->first;
        while (pos != NULL){
            if (strcmp(pos->name,afterName1D) == 0){
                struct node1d *new1d = (struct node1d*)malloc(sizeof(struct node1d));
                new1d->name = (char*)malloc(sizeof(MAXWORDLENGTH));
                strcpy(new1d->name,name);
                // new1d->name = name;
                new1d->next = pos->next;
                pos->next = new1d;
                return 0;
            }
            pos = pos->next;
        }
        ptr = ptr->down;
        
    }
    printf("Error: node1D '%s' is not found.\n\n",afterName1D);
    return 1;
    //if not found, print error message
}
//2.2.1 Print All
int printAll(){
    struct node2d *start = head;
    while (start != NULL){
        printf("[head2D]%s:",start->name);
        struct node1d *ptr = start->first;
        while (ptr != NULL){
            printf( " %s =>", ptr->name);
            ptr = ptr->next;
        }
        printf(" NULL");
        start = start->down;
        printf("\n  |\n  V\n");
    }
    printf(" NULL\n\n");
    return 0;
}
//2.2.2 Print 1D List
int print1DList(char *name2D){
    struct node2d *find2d = head;
    while (find2d != NULL){
        if (strcmp(find2d->name,name2D) == 0){
            struct node1d *ptr = find2d->first;
            printf("1D List headed by 2D node '%s':",find2d->name);
            while (ptr != NULL){
                printf( " %s =>", ptr->name);
                ptr = ptr->next;
            }
            printf(" NULL");
            printf("\n\n");
            return 0;
        }
        find2d = find2d->down;
    }
    printf("Error: node2D '%s' is not found.\n\n",name2D);
    return 0;

}
//2.3.1 Find 1D Node
struct node1d *find1D (char *name1D){
    struct node2d *ptr = head;
    while (ptr != NULL){
       struct node1d *found = ptr->first;
       while (found != NULL){
           if (strcmp(found->name,name1D) == 0){
               printf("Success: node1D '%s' is found.\n\n",name1D);
               return found;
           }
           found = found->next;
       }
       
       ptr = ptr->down;
    }
    printf("Error: node1D '%s' is not found.\n\n",name1D);
    return NULL;
} 
//2.3.2 Find 2D Node
struct node2d *find2D (char *name2D){
    struct node2d *found = head;
    while (found != NULL){
       if (strcmp(found->name,name2D) == 0){
           printf("Success: node2D '%s' is found.\n\n",name2D);
           return found;
       }
       found = found->down;
    }
    printf("Error: node2D '%s' is not found.\n\n",name2D);
    return NULL;
}
//getch()
char getch() {
    return (bufp>0) ? word[--bufp] : getchar();
}
//ungetch()
void ungetch(char c) {
    if (bufp >= MAXWORDLENGTH)
        printf("ungetch: too many chars\n");
    else
        word[bufp++] = c;
}
//getword(),returns a string 
char *getword(char *word, int lim) {
    char c;
    char *p = word;
    while (isspace(c = getch())) 
        ;
    if (c != EOF){
        *word++ = c;
    } 
    if (!isalpha(c)) {
      *word = '\0';
      return c;
    }
    for ( ; --lim >= 0; word++){
       if (!isalnum(*word = getch())) {
        ungetch(*word);
        break;
      } 
    } 
    *word = '\0';
    return p;
}  
//run the getword in main
int run(){
    char word[MAXWORDLENGTH];
    char *command;
    char *newname;
    char *after;
    printf("\nWelcome to Wenhan Yang's \"lab2--2D Linked List\" program.\n");
    printf("Please type in a command each time to operate your 2D Linked List:\n");
    printf("e.g. appendRear2D name, appendAfter2D name afterName,...\n");
    printf("Type \"exit\" or just ctrl + C to terminate the program\n\n");

    while (0==0){
        command = getword(word, MAXWORDLENGTH);
        //compare each command 
        if(strcmp(command,"appendRear2D") == 0){
            //appendRear2D newname
            newname = getword(word, MAXWORDLENGTH);
            appendRear2D(newname);
        }else if(strcmp(command,"appendAfter2D") == 0){
            newname = (char*)malloc(sizeof(MAXWORDLENGTH));
            strcpy(newname,getword(word, MAXWORDLENGTH));
            after = getword(word, MAXWORDLENGTH);
            // printf("%s %s\n",newname,after);
            appendAfter2D(newname,after);
            free(newname);
        }else if(strcmp(command,"appendRear1D") == 0){
            newname = (char*)malloc(sizeof(MAXWORDLENGTH));
            strcpy(newname,getword(word, MAXWORDLENGTH));
            after = getword(word, MAXWORDLENGTH);
            appendRear1D(newname,after);
            free(newname);
        }else if(strcmp(command,"appendAfter1D") == 0){
            newname = (char*)malloc(sizeof(MAXWORDLENGTH));
            strcpy(newname,getword(word, MAXWORDLENGTH));
            after = getword(word, MAXWORDLENGTH);
            appendAfter1D(newname,after);
            free(newname);
        }else if(strcmp(command,"printAll") == 0){
            printAll();
        }else if(strcmp(command,"print1DList") == 0){
            newname = getword(word, MAXWORDLENGTH);
            print1DList(newname);
        }else if(strcmp(command,"find1D") == 0){
            newname = getword(word, MAXWORDLENGTH);
            find1D(newname);
        }else if(strcmp(command,"find2D") == 0){
            newname = getword(word, MAXWORDLENGTH);
            find2D(newname);
        }else if (strcmp(command,"exit")==0){
            printf("Quit the program!\n");
            return 0;
        }else{
            printf("Invalid command!\n\n");
            continue;
        }
    } 
    return 0;
}
//test main
int main(){
    run();
    return 0;
}

