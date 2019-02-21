#  Homework grade for mywc


 Category | Max  | Actual|
--- | --- | ---
 Makefile |  3   |   3    
 git usage|  2   |2
 correct program | 12    |10     
 correct code|  2|  1.5     
 style    |  3   |2
 Total|20|18.5

 ## Comments

 * you don't understand fgets() and made the code much more complex then necessary
 * fgets() returns NULL terminated string including '\n' if line is line than max so you have the lines returned her and mygetchars only needs to check for '\0' making your fudge factor for numchars not needed
 * you tend to make assignments much more difficult than necessary
