Assignment 01 - A small step of the huge one

===================





Create a `class` called ***HugeInteger*** for performing add & subtraction operations with huge integers. Please extend following incomplete `class` to do above works. Now, use provided driver program (**main_hw1.cpp**) to test your work. **(Due date: 4/5)**



----------



```c

    #define MAX 1000 //< max length of huge integer

    class HugeUInteger 

    {

    public:

       HugeUInteger (); //< default constructor

       HugeUInteger (HugeUInteger &in);  //< copy constructor

       void random( unsigned int size ); //< randomly generate an integer

    void add(HugeUInteger &add); //< add a number 

                                       //< (Use ZERO to replace negative result)

    void subtract(HugeUInteger &sub);  //< subtract a number

    void print(); //< print out the huge unsigned integer

    private:

    ///add something to stores a huge integer (dynamic array or std::vector or …)

    ///add some helper functions

    };

```







Sample outputs

-------------

> 


> Enter seed: 13


> Enter the lengths of three huge integers: 20 18 16


> N1: 18699035430339962866


> N2: 338925430226058207


> N3: 4175151280964515


> N1 + N3 = 18703210581620927381


> N2 - N3 = 334750278945093692




> 


> Enter seed: 21


> Enter the lengths of three huge integers: 9 5 7


> N1: 930123690


> N2: 54757


> N3: 3584963


> N1 + N3 = 933708653


> N2 - N3 = (negative)0





A common workflow of preparation of your homework

-------------

(In the following text, we assume your student ID is s1234567 and # is the NUMBER of homework in one digit, Please replace it with your student ID and follow the steps exactly!)



 1. Clone your private repository of hw# to your home directory on server or another suitable location from our organization on GitHub (https://github.com/YZU-CSE-CS114-Computer-Programming-II)

 2. After you start to deal with your homework, add a file s1234567hw#_main.cpp as your main program and s1234567 hw#_report.md as your report (optional). Then, commit it! **(Don’t forget to push it onto GitHub, too)** 


    ***.Any of your code should be prefixed with “s1234567hw#_”.** For example: s1234567hw3_Vecotr.h

 3. Complete your program and write your report (if necessary) with Markdown.


    ***. Please commit your homework when you have any progress.**

 4. Make sure you have complete the assignment and prepare a clear demo in your report. Do it ON YOUR OWN and ON TIME.



How to complete your report with markdown?

-------------

* In this course, please use **markdown** to complete your reports and commit it with your homework.


A powerful on-line editor: https://stackedit.io (Check this link first)



Markdown is a markup language with plain text formatting syntax designed so that it can be converted to HTML and many other formats using a tool by the same name.


Markdown in GitHub:

* https://help.github.com/articles/markdown-basics/ (tutorial)

* https://help.github.com/articles/github-flavored-markdown/ << GitHub Flavored Markdown!

Complete documents of Markdown syntax: 

* http://daringfireball.net/projects/markdown/syntax (Chinese version: http://markdown.tw)


