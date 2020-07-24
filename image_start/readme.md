# Goals
In this assignment, I want you to really focus on learning about how information is stored in files. You will approach this by, first, creating a program in C++ that can copy TGA files. The program will utilize the TGA header structure, which is already included in skeleton code.

First, you would read in and copy the header information to the new file.

Next, pixel by pixel you will copy the image data to the new file.

*NOTE:* You may find that the information is actually stored in BGR format (which is typical) instead of RGB. How will you overcome this?

I may add that it is quite obvious a better way of copying files is to simply read and copy each byte over to the new file (without worrying about capturing header information in a struct, for example). However, this assignment will lead into the next one.

I expect the use of two structs:

  * struct Header - **provided**
  * struct RGBTriple (Pixel, whatever name you find best)

Talk soon Daniel!