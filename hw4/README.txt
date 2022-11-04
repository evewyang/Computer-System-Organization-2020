Wenhan Yang -- HW4

Content 
    cso4_1.c: Rewrite changeltox() to use array style and a for loop.

    cso4_2.c: What is wrong with the following calls to alloc() and afree()? Assume that ALLOCSIZE is big enough.
                problem: Yes. As we call the function alloc() and assign the storage to p1, p2, p3 in order,
                        the order of releasing (afree()) the storage must be p3, p2, p1. afree(p) will release 
                        the storage space of p and all other assigned spaces after it. 
                        For example, releasing p3 will not affect the assigned storage space for p2 or p1, because
                        p2 & p1's are assigned before p3.
                        Yet, in the function call, afree(p1) is called before afree(p2), so the storage space
                        assigned to p2 will be released in advaced, diminishing its meaning. 

    cso4_3.c: 5-5 (first part). Write a version of the library functions char *strncpy(char *s, char *t, int n). 
                This copies at most n characters from t to s. 
                This code is not scary like other copies since a user of the routine can simply declare s to have space for n characters.


Compile & Run
    gcc xxx.c
    ./a.out