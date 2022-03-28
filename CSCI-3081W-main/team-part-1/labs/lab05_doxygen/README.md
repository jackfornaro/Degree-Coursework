# Lab 5 - Doxygen

*(Due **Monday**, October 11th @ 11:59 PM)*

<br>

### To pull this part of the repository into your local or CSE's machine, refer to previous labs.

<br>

## What should be in this directory?
<ul>
  <li>  This <code>README.md</code>, of course
  <li>  A <code>.gitignore</code> file
  <li>  <code>src</code> folder, which contains:
    <ul>
      <li>  main.cc
      <li>  Entity.cc & Entity.h
      <li>  EntityFactory.cc & EntityFactory.h
      <li>  Makefile
    </ul>
</ul>

<br>

## What you'll learn today:
<ol>
  <li>  How to use Doxygen
  <li>  ...and how to document code with it as well
</ol>

<br>

### Part 1 - Doxygen

With Iteration 1's deadline coming close, and groups have had formed, it's time for you to learn how to generate documentation and UML for the code in this project and future projects. This can be done via Doxygen.

According to their [official website](https://www.doxygen.nl/index.html),
> Doxygen is the de facto standard tool for generating documentation from
> annotated C++ sources, but it also supports other popular programming languages
> such as C, Objective-C, C#, PHP, Java, Python, IDL (Corba, Microsoft, and
> UNO/OpenOffice flavors), Fortran, VHDL, Tcl, and to some extent D.

Notice how the class EntityFactory in EntityFactory.h has a description above the
class definition. Doxygen makes use of this to generate documentation for this
class. Doxygen also generates documentation for all functions of a class.

<br>

***NOTE: Students working on their personal machines will have to [download](https://www.doxygen.nl/manual/install.html) the
doxygen executable before continuing. If a student is using Docker on their personal machine, the Docker image already has doxygen pre-installed, so no additional installation will be necessary. CSE labs machines have doxygen pre-installed as well.***

<br>

1. Create the configuration file.

  To start generating documentation, you must first generate a Doxygen
  configuration file in the docs directory. Run the following command from the
  lab05 directory (where this README is).

  ```
  mkdir docs
  doxygen -g docs/Doxyfile
  ```

  You will now see a new file **Doxyfile** in the <code>docs</code> directory.

2. Modify the Doxyfile to look in the <code>src</code> folder when compiling. You can do
   this by setting the **INPUT** tag of your **Doxyfile** to point to <code>src</code>. It should be around `line 832` within `Doxyfile`.

  ```
  ../src
  ```
  Also, to generate the UML, set the **UML_LOOK** (~ `line 2368`) and **HAVE_DOT** (~ `line 2302`) tag to **YES**.

  ***NOTE: Make sure that there is only a single space after the `=` sign, or else the autograder would not pass.***

  
  e.g. <pre><code>= YES</code></pre> 
  and not
  <pre><code>=      NO</code></pre>

  The path is relative to the directory from which you run/compile the doxygen. ***It is important that you set it up to run from `docs/`*** because Doxygen will not inform you if it does not find the src directory -- it just won't generate any files from your classes.

3. Generate the html pages for this lab. Run the following commands:
  ```
  cd docs
  doxygen Doxyfile
  ```

  You can now view the generated documentation from the `index.html` file in the
  `html` directory that was generated inside the docs folder. Open the `index.html` page which is refered to as the *landing page*. Explore the various menus to see how the comments in the code are organized in the html. Click on the classes and you will see UML-like diagrams showing the relationship between classes. One missing piece is a general overview of the code, which you want in the landing page. Currently it is blank because there is no `mainpage.h` file in your `src` directory.

4. Create a home page for the project. In your ``src`` directory, create a file
   `mainpage.h` and paste the following in it.

  ```
  /*! \mainpage My Personal Index Page
   *
   * \section intro_sec Introduction
   *
   * This is the introduction.
   *
   */
 ```

  Generate documentation again by running doxygen as you did before (step 3) from the
  docs directory and notice how you now have a landing page for your project.

 5. Edit the `mainpage.h` file by giving it a title and write a
    sentence for the introduction.

 6. Now modify the `Entity.h` files to add Doxygen comments and see how that gets added to the documentation. Follow the commenting style that you see in `EntityFactory.h`. Use **@brief** to describe the class and at least one of the class methods and **@return** to specify a function's return values. You can also refer to Doxygen's [manual](https://www.doxygen.nl/manual/docblocks.html) for their commenting standards.

   When you have created this documentation (you only need the _.h_
   file), run it again and see how it appears in the class list. Click on the
   class and you will see more detailed information.

7. **Set your `.gitignore` so that you are not pushing the `html` and `latex` folders** to your repo. These take a lot of space and can be generated from the Doxygen file, thus there is no need to have them in your repo. You can do this by appending the following entries to your `.gitignore` file:
      - `/docs/html/*`
      - `/docs/latex/*`

<br>

## **Submission**

Submit your work by uploading the following files to Gradescope for the Lab04 assignment. Your submission will be automatically graded and your score recorded.

<ul>
  <li>  <code>Doxyfile</code>
  <li>  <code>.gitignore</code>
  <li>  Your edited <code>Entity.h</code> file
</ul>

You are welcome to keep changing and submitting this lab up to the deadline. Gradescope will recompile and test your code. If for some reason the automated feedback does not work for you, TAs can also manually verify your submission.
