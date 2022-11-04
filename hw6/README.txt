Wenhan Yang--HW6

Content 
    cso6_1.c: Optional Command Line Argument: tab() 
                tab -en   # performs like entab()
                tab -de   # performs like detab()

    cso6_2.c: Write two versions of mkRectangle, one that accepts two points, and one that accepts 4 real numbers.

    cso6_3.c: How big is each version of sizeof(struct gameValType)? How big is sizeof employee?
                -The answers are included as comments in the file. 


Compile & Run
    cso6_1.c: gcc cso6_1.c -nostartfiles -e_tab -o out6_1
                ./out6_1 test.txt -en       (for entab)
         or     ./out6_1 test.txt -de       (for detab)
         (Where test.txt is the input file)
    cso6_2.c: gcc cso6_2.c
                ./a.out
                (no main included)

    
