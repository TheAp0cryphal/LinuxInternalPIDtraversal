For the First question, It was hard to figure out how to actually traverse through a directory to find the necessary PIDs, the code path had to changed every loop to fetch from a 
different file with their corresponding names. We ran into segmentation fault once, but we figured it out by changing the if to read the directory. The question was very informative

For the second question, it took us few hours to code and understand the /proc/meminfo file. We used basic Libraries of c and extracted the code from the file, then performed 
some operation to get our final result. The question was intellectually challenging as I got to learn how my memory works and how it gets released when I close processes.

For the third question, the hint given was useful to know the location of the OS name and kernel. Had to read the file just like in the previous questions, looking for the specific 
string PRETTY_NAME was an interesting addition and gave me insight on how to traverse a file. This question was completely relevant.