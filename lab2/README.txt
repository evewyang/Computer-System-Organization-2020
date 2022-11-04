Wenhan Yang -- Lab 2

Content 
    lab2.c: 2D Linked List Realization 
        -void initialize2d(char *name)
        -void initialize1d(char *name, struct node2d *this2D)
        -int appendRear2D(char *name)
        -int appendAfter2D (char *name, char *afterName)
        -int appendRear1D (char *name, char *name2D)
        -int appendAfter1D (char *name, char *afterName1D)
        -int printAll()
        -int print1DList(char *name2D)
        -struct node1d *find1D (char *name1D)
        -struct node2d *find2D (char *name2D)
        -char getch()
        -void ungetch(char c)
        -char *getword(char *word, int lim)
        -int run()

Compile & Run
    gcc lab2.c
    ./a.out

Instructions On the Run 
    1) Once the program is run, a series of welcome messages will be printed
    2) List of aalid of commands:
        appendRear2D name
        appendAfter2D name afterName
        appendRear1D name name2D
        appendAfter1D name afterName1D
        printAll
        print1DList name2D
        find1D name1D
        find2D name2D
    3) To end the program, you can either type:
        exit
       or just use ctrl + C for termination.
