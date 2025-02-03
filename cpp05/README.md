Rendu du chapitre CPP05 - Piscine C++ - Ecole 42

Infos general : 

This Chapter introduces exceptions which will be awfully useful when protecting our code.
We'll keep using Cannonical form which implies declaring a default constructor, a copy constructor, a copy assignement operator and a destructor in each class that aren't abstract or exception derived.
Let me remind you that using C11 functions is forbidden, as such we will compile with -std=c++98 flag.
Same concerning containers, we're not allowed to use them.
All the rules can be check on the subject present in the currrent directory.

EX00 - 
Introduction to the try-catch blocks.
The idea is that if an error is "throw"n during a "try", the binary will directly skip to the next catch function. If the exception used in the throw function is caught in this block, then, we'll use this code. Otherwise, will go back to the previous catch to find the exception.
Every variable defined inside a try cant be called to the catch. So if it's a variable used in the error message, we have to build a specific exception class to store in the data.
Every exception class is based of std::exception, and some already defined exceptions can be used to make the code simpler. For exemple, runtime_error() can be used to keep in memory a string which will describe the content of the error.

EX01 -


EX02 -


EX03 -
