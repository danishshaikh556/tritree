tritree
=======

Implemented the TIRE DataStructure for Phonebook searches 

This tar file contains the following files:
 - README.txt: this file
 - main.cpp: a small piece of code that demonstrates how to use your
             class
 - name_lookup.h: a placeholder file where you can declare your
                  class
 - name_lookup.cpp: a placeholder file where you can implement your
                    class
 - Makefile: a sample build script to compile the project on Unix-like
             systems
 - vs2010: a directory containing VisualStudio 2010 solution and
           project files

Instructions
------------
This archive contains the files and instructions for this coding
exercise.  When complete, please return your results, via email,
to your contact at Suitable Technologies.

Please spend no more than three hours on this exercise.  If you haven't 
finished within three hours, send whatever you have completed, along
with an explanation of your strategy and how you planned to continue.

If you have any questions regarding this problem, please send email to
your contact at Suitable Technologies.

Problem
-------
Design and implement a class in C++ to hold a large number of names.
Assume that the only legal characters in a name are uppercase
letters, numbers, space, comma, period, dash, and apostrophe.

Your class should support the following methods:

 - insert: insert a valid name into the class, return true
           on insertion, false if the name is a duplicate
 - erase: delete a name from the class, return true if the
          name was deleted, false if the name does not exist in 
          the class
 - clear: remove all names from the class
 - getNamesStartingWith: return a list of valid names that begin
                         with the given prefix
 - getNumNamesStartingWith: return the number of valid names that
                            begin with the given prefix string
 - getNextChars: given a prefix string, return a list of characters that
                 are possible next characters.  For example, if the class
                 contains the names (Albert, Alberta, Alberton, Albertville),
                 and this method was called with the prefix "Albert", then
                 it should return the list ('\0', 'a', 'o', 'v').  Note:
                 the '\0' character denotes that the prefix string is also
                 a valid name itself.

Assume that the class will be used to hold a large number of names and that
while the performance of insert and erase are important, the majority of the
operations will be the get*() methods.

Error Handling
--------------
Any errors should be handled by throwing an exception class derived
from std::exception

Implementation and Compilation
------------------------------
Implement your class in the files: name_lookup.h and name_lookup.cpp.
Your code should compile against the provided main.cpp.  The expected
output is indicated in the comments of main.cpp.

Documentation
-------------
Please include a description of your implementation.  Indicate any
trade offs or assumptions that you made while developing your
solution.

This test is an attempt to simulate "real world" working conditions.
Feel free to use external resources to assist in your development
(e.g. Google or man pages).  Be sure to include a citation for any
reference materials you used, including personal conversations.

