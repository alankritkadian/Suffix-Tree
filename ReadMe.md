--- Welcome to Grocery Management System ---

To Compile the code :-
         
         g++ Suffix_tree.c PatternSearch.c  main.cpp bloom.cpp BK_Tree.cpp
       
The Project has 2 Ends

          Buyer End                                             Seller End
          This is where the buyer enter's his/her name          This is where the Seller adds the items and can search the order List
          along with the items needed.                          along with Full Reciept
          Features:                                             Features:
          -Auto Correct (using BK-Tree)                         -Unique Item List (using Bloom Filter)
                                                                -Fast Search (using Suffix Tree)
Warning :-

-After each Item name entered by buyer press Enter.

-Dont Use Items which are subset of one another.

-Don't use names longer than 99 characters or less than 1.
