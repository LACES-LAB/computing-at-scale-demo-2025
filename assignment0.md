(a) How did you test your code? What are the limitations of your testing ?  
I test my code by computing the matrix and vector prodcut results by hand or use online tools (their results are correct),
and then compare with the output of my code.  
(b) What are the limitations of the matrix market format for dense matrices ?  
It reads each item in the matrix sequentially and thus dense matrices will increase the processing time.  
(c) If you know the size of the matrices at compile time, how would you change your code to take advantage of this information?  
I will allocate memory first and no unnecessary memory will be used. I can know when to do malloc, relloc and free the memory.  
(d) Was your matrix representation row-major or column-major? How did you decide? Do you think this will have an impact on performance?  
C++ is row-major. The memory is [row1: elements row2: elements ...]. I think the performance depend on the memory usage and process time.  
From my experience, I think row-major is more suitbale for CPU/GPU memory. And since MATLAB is column-major and the code is slower than C/C++,  
but I do not have idea to proof it ...  
(e) What approach did you take to document your functions and driver program ?
I follow the standrad to write comment for vaiable and function definitions, but I will also add some documents to some important parts and  
I can better understand my code.  
(f) Is your code robust to errors in the input files? How did you test this?
I think so, beacuse I create about 10 test cases including some strange cases, such as wrong input format, diemnsion dismatch and type dismatch,  
but I may miss something ...  
(g) Are there any limitations in your implementation you are aware of? Do you have any ideas on how
to address them? e.g., what is the maximum size of the matrices you can handle
I do not find limitation of my code, maybe it need to input matrix, vector, can not do input like vector matrix.  
I think can use try... catch to better handle all possible cases.  
The maximum size of matrices: 

(h) If you wanted to optimize the performance of your code, what approach would you take?  
I think need to avoid use for loop, takes lots of time.  
I think can parallel the code, each process handles part of the matrix (if matrix is too big).

