# fillit

Third project with Mydeall @ 42 Paris
---------------------------------------------

The aim of this project is to efficiently place N number of 
valid tetromino pieces, stored in a file, in 4 x 4 format 
constituted of '#' and '.' for blank spaces, into the smallest
square possible. 

With help from Corentin Cepre, we created a simple recursive
algorithm, after parsing the content of the file into a linked
list.

--> 'make' to compile library and fillit sources into binary 'fillit'
--> usage : ./fillit [valid tetriminos file]
--> tetris_tests contains valid tetrominos file examples. Tetrominos
    must be SEPARATED by a '\n'. Any other content will be considered 
    invalid.

