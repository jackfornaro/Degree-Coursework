# 3081 Lab03 - C++ Memory
_(Due: Monday, Sept. 27, 2021 @ 11:59pm)_

## What You Will Learn

1. How to configure make for different environments.
2. How to use make to flexibly build larger projects.
3. How to use a header only library.
4. Examples of how to work with memory in C++.
5. How to load, modify, and save an image.

### Retrieve Class Materials

Navigate to your repository.

```bash
% cd <path_to_directory_repo-userid>
```

You will again pull and merge the support-code branch from the remote shared-upstream repository. First, orient yourself to the branch that you are on and any uncommitted changes. The command

```bash
% git status
```

will output the branch you are currently working in and indicate if there are any changes locally that need to be committed and pushed. In general, you want to check the following:

1. If you are on your main branch and you have made changes that are not yet committed and pushed, you should probably do that before proceeding.

2. Move to the support-code branch with `git checkout support-code`.

3. `git pull upstream support-code` to grab the latest changes from the shared class repo.

4. `git checkout main` to move back to the main branch for merging.

5. `git merge support-code`

### What's in labs/lab03_memory

- memory.cc:
  - This contains the main function for the Gradescope assignment below.

- image.cc:
  - This contains the main function for loading in an image, modifying it, and saving the result.

- Makefile:
  - This makefile is provided to allow you an easy start to configure and build the executables.  You will need to edit this.

- README.md:
  - You're reading this now.

- checkpoint2:
  - This is a folder will be used for the project iteration 1 checkpoint described below.

### What You Will Add

- stb_image.h:
  - A single header file for reading images from the file system.

- stb_image_write.h:
  - A single header file for writing images to the file system.

### What You Will Modify

- Makefile:
  - You will update this Makefile to build two applications (memory_app and image_app).

- image.cc:
  - You will edit image.cc to modify an image and share on discord.

### Goal

<hr>
  **The primary goal of this lab is for you to understand C++ memory concepts (Part A) and to start modifying images (Part B).**
<hr>

### Prerequisites

We are going to use header only libraries for this lab.  Header only libraries are nice because you can place them directly in your code without having to link them.  In this case we will use stb_image and stb_image_write.  These are found at <https://github.com/nothings/> along with several other libraries.  You will need to download the following header files and put them in the lab folder:

- stb_image.h <https://github.com/nothings/stb/blob/master/stb_image.h>
- stb_image_write.h <https://github.com/nothings/stb/blob/master/stb_image_write.h>

In case you are interested, here are many other useful header file libraries for C++: <https://github.com/nothings/single_file_libs>

### Configuring Makefiles

Depending on the system, environment being used, or customized compiler options it is common to configure your makefile based on the specific machine.  For example, we may want to specify the compiler that should be used.  We often use variables to accomplish this as we have seen in lab02.  Notice the top of the Makefile provided:

```
CXX=g++
CXXFLAGS = -std=c++11
ROOT_DIR := $(shell git rev-parse --show-toplevel)
-include $(ROOT_DIR)/config/settings
-include $(DEP_DIR)/env
```

__What does all that mean?__
- `CXX` : The name of the compiler you would like to use
- `CXXFLAGS` : Specific compiler flags that tell how to build the program
- `ROOT_DIR` : The top directory in your repository (found using git)
- `-include $(ROOT_DIR)/config/settings` : Loads repository level configuration variables (look at the file in x500-repo/config/settings).  Notice the settings file includes a path to DEP_DIR, which is useful for finding the path to the dependencies.  This way we only need to put this path in one place.
- `-include $(DEP_DIR)/env` : Loads environment level configuration variables.  ssh into one of the lab machines and see that it sets the compiler to: `CXX=/soft/gcc/7.1.0/Linux_x86_64/bin/g++`.  This will override the default compiler if we use the $(CXX) variable in our commands to build targets (as we will see).  This is what enables us to build on VOLE where the default compiler may be a different version.

Going forward, you will want to put these configuration variables at the top of your Makefiles to enable multiple different environments (CSE Labs Machines, VOLE, SSH, Docker).


### Building Projects with Makefiles

In the last lab we added a target for each .o file we created (e.g. main.o, drone.o, vector3.o, etc...). We could continue adding each target/dependency/command into the Makefile one at a time, however, that isn't very efficient, especially for large projects. We need a shortcut!

The solution is to use wildcards.  Open up the Makefile in the lab03_memory directory.  Notice there is an `all` target which builds two separate applications: memory_app and image_app.  Notice how there are no targets for building either application or the object files (*.o).   Make allows us to be flexible by adding the following target with wildcards:

```
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@
```

Notice we are using the configuration variables defined above.

**What's happening here?** You can get a sense of what all those symbols are representing by comparing to our Makefile from lab02.

- `%`  : The `%` symbol is the wildcard. It matches to any `<filename>.o` target that you want to make, and it uses that matching filename in the dependency list as well.

- `$^` : is a synonym for the slightly longer shortcut `$(inputs)`, which is just the list of all dependencies listed after the target.
    > e.g. all the `.cc` files listed as dependencies

- `$<` : similar to the `$^` command, the `$<` only appends one of the `$(inputs)` following the target. Since, we are only working with one .cc file, `$<` is more logical but if there were multiple .cc, `$^` would be more appropriate.

- `$@` : is a shortcut meaning the name of the target without the .o extension.

Now, we can use this to build any number of object files. Give it a try.

```
$ make memory.o
$ make image.o
```

Finally, lets add the flexible target for building the applications:

```
%_app: %.o
	$(CXX) $(CXXFLAGS) $< -o $@
```

Now, let's run `make` to build our applications.

    $ make

Note it builds all the applications. Let's execute them:

    $ ./memory_app
    $ ./image_app

We are now ready to start Part A of this assignment.

### Part A - Understanding C++ Memory (Gradescope assignment)
_(50% of Lab03 Grade)_

Part A consists of running the `memory_app` program and answering questions on the Gradescope Lab 3 assignment.  You can take the multiple times and the highest score will be used.  **Note:** You are welcome to modify `memory.cc` to help answer any questions.

#### Type Sizes

Run the following and study the `type_sizes()` function within `memory.cc`.  This function lists out the sizes for different types and the sizes of variables in memory:

```
% ./memory_app type_sizes
```

Answer questions 1-5 in the Gradescope assignment.

#### Private Variables

Run the following and study the `private_variables()` function within `memory.cc`.  This function casts a DVec3 to a double array:

```
% ./memory_app private_variables
```

Answer question 6 in the Gradescope assignment.

#### Byte Arrays

Run the following and study the `byte_arrays()` function within `memory.cc`.  This function converts an integer into a byte array:

```
% ./memory_app byte_arrays
```

Answer questions 7-8 in the Gradescope assignment.

#### Arrays

Run the following and study the `arrays()` function within `memory.cc`.  This function investigates the buffer overflow problem:

```
% ./memory_app arrays
```

Answer questions 9-10 in the Gradescope assignment.


### Part B - Modifying an Image
_(50% of Lab03 Grade)_

Create a folder named `data`.  Add an image of your choice and name it: `data/input.png`.

Open up `image.cc` and notice how it uses stb_image and stb_image_write to load in an image and save it.  You will use this in Checkpoint 2. Notice that the program saves a new image as `data/output.png`.    Run the program:

```
% ./image_app
```

**_What just happened?_** You should see an image, `data/output.png`, which is a color modification of `data/input.png`.  Here we are changing the red value of the image from left to right:

```c++
  // Loop through the image pixels and modify values
  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      // Get the pixel as a byte array
      unsigned char* pixel = &image[(y*width + x)*4];

      // Edit these [red, green, blue, alpha / transparency] values below (values between 0 and 255):
      pixel[0] = 255*x/width;
      //pixel[1] = 0;      
      //pixel[2] = 0;
      //pixel[3] = 255;
    }
  }
```

Here we use a pointer `pixel` which points to a specific four byte array for the (x,y) location in the 2D image (stored as a 1D array indexed by `(y*width+x)*4`).  The number 4 represents the number of components (RGBA).

Change the program to edit the RGBA pixel values and a create new image (output.png) based on your original image (input.png).  We want to see fun and interesing renditions of your original image.  You should prototype interesting and creative modifications.  You will submit your original and modified image to Discord (see below).

### Add Changes to Repo Locally and On Server

You need to _stage_ all changes to the repository, which prepares those items to be permanently part of the repository. 
When you _commit_ those changes, they are saved to your local repository, which lives in your cselabs account (or your
personal computer if that is what you are working on). When you _push_ those changes, they will be copied to the repo on the server. The difference between
_commit_ and _push_ is what separates git from centralized version control systems.

```bash
% git status
% git add -A
% git status
% git commit -m "Adding lab03 deliverables"
% git push
```

**_What just happened?_** Double-checking the files to be staged using the _git status_ command. All of the tracked changes are staged with `git add -A`.  The second _git status_ command shows the staged changes.  Those staged changes were committed to your local repository and tagged with the message that follows `-m`, then pushed to the server in your remote repository.

### Submitting your Lab

Submit your work by completing the two tasks below:
 - Complete the Lab 03 Gradescope assignment (you may take this multiple times).
 - In the Discord channel `#lab03-memory` post your _original_ (input.png) and _modified_ (output.png) pictures to share with the class (make sure they are appropriate).  Enjoy and be creative!

THIS LAB IS COMPLETE.

Congratulations!



# Iteration 1: Checkpoint 2 - Image Editing
_(Due Thurs, Sept. 30, 2021 @ 11:59)_

This extended lab checkpoint uses the results above as a starting place for image editing in our project.  You may use the code in `image.cc` from the lab to help you get started.  Your goal is to create an Image class that stores and modifies the memory for an image.  You will also create an application that uses your image class to create and modify images.

## What You Will Learn

1. How to manage dynamically allocated memory in a class (e.g the Big Three).
2. How to copy bytes of memory.
3. How to design a cohesive image class.
4. How to load, modify, copy, and save images.
5. Simple image editing techniques.

### What's in labs/lab03_memory/checkpoint2

- Makefile:
  - This makefile is provided to automate the building of your project.  You may edit this if you need.

- main.cc:
  - This file contains the main method with no implementation.  It does contain comments corresponding to the image editing requirements in this write-up.

### What You Will Add

- image.h:
  - A single header file for reading images from the file system.

- image.cc:
  - A single header file for writing images to the file system.

- Other Necessary Files 
  - any other file or classes needed to read in images (e.g. stb_image.h and stb_image_write.h).  You are welcome to add other classes that could be helpful.  For example, you may want to create a Color class that edits pixel values, but this is not required.

### Goal

<hr>
  **The primary goal of this checkpoint is for you to create a dynamic image class that handles the loading, editing access, and saving functionality.**
<hr>

### Getting Started

Navigate to lab02_memory/checkpoint2 in one of the development environments (VOLE / CSE Labs, SSH, Docker).  You can run the program with the following commands using the provided `Makefile` and `main.cc`.

```bash
% cd x500-repo/labs/lab03_memory/checkpoint2
% make
% ./image_processor
```

Create a new `Image` class that includes both an interface (image.h) and an implementation (image.cc).  This image class should be able to load and save images.  It should also give users the ability to edit images by setting pixel values.  The following are constructors and methods that should be implemented to help reach this goal:
 * **Constructors**
   * `Image(width, height)` - Creates a "blank" image of a given width and height.
   * `Image(filename)` - Load an image from the hard drive if a string (or character array) is passed into the constructor.  **Hint:** Use stb_image (see image.cc in Lab03 above).
 * **Methods**
   * `SaveAs(filename)`- A method that takes in a string (or character array) and saves the image.  **Hint:** Use stb_image_write (see image.cc in Lab03 above).
   * `GetHeight(), GetWidth(), GetComponentNum()` - for getting height, width, and number of components.  For now, we will hard code the number of components to 4 to handle RGBA images.
   * `GetPixel(x,y)` - method that returns a pixel value (it is up to you how you want to represent a pixel.  Perhaps it could return a color object or an array).
   * `SetPixel(x,y,pixel)`- method that sets a pixel value at a place on the image.  Again, it is up to you how you represent these objects.  There is freedom here.

We highly recommend that you refer to image.cc (from Lab03) to help you create and save images.  It is also recommended that you manage your own image buffer similar to image.cc rather than using the data from stb_image.  This is so that you can create your own images using the `Image(width, height)` constructor that does not rely on stb_image.

### Guidelines for building your image class

The following are guidelines for implementing your image class.  We will be reviewing your classes to make sure these items are followed:

 * **Classes / Constructors / Methods** - You have freedom to design these image classes and any other class as you like.  We are interested in how you would solve the problem.
 * **Memory Management** - Be sure to use best practices for dynamic memory management (No memory leaks, the Big Three, etc...).  You may also use smart pointers if you use them correctly (we will cover these in class).
 * **Efficient** - Write efficient and safe code.  For example, be sure to use a const reference wherever possible to save space on the stack and avoid copying too much information.  In fact, you may want to go back and modify your Vector3 class to include const references whenever you pass a value that is larger than a pointer.  
 * **Useful** - After creating your class, you will need to accomplish the tasks in `main.cc` detailed in the next section.  These are also commented in the `main.cc` to help with implementation.

### Editing Images

Create a data folder to store your input and output *.png images (copy the images from <https://github.umn.edu/umn-csci-3081-f21/examples/tree/main/data/images>).  Then follow these steps:

1. Inside your main() method, load in “data/statue.png” (found here: <https://github.umn.edu/umn-csci-3081-f21/examples/blob/main/data/images/statue.png>) using the Image class.  Print out the width and height.  Save a new file as “data/statue_copy.png”.  Verify that the new image is a copy of the old one.
2. Next create a new image by specifying the width = 256 and height = 256 in the constructor.  Set each pixel color to (255, 0, 0, 255), which is red.  Save the image as “data/red.png”.  Verify that the image created is completely red.
3. Finally, create a gradient image from left to right (width = 256, height = 32) that increases the green intensity.  So at the left the intensity is black and the right it is green.  Save the image as “data/green_gradient.png”.  Verify the image looks similar to the following gradient:

![](https://github.umn.edu/umn-csci-3081-f21/examples/blob/main/data/images/green_gradient.png?raw=true)

**Optional:** Feel free to add more.  Consider resizing an image or try applying a threshold filter.  To apply a simple threshold filter, iterate through the pixels and set any pixel to black if red is less than 0.5 and white if red is greater than 0.5.

### Submitting your Checkpoint 2 (staring Monday, 9/27/2021)

Submit your work by uploading the following files to Gradescope for the Checkpoint 2 assignment (which will be available starting Monday evening, September 27, 2021).  We will inspect your code quality (no memory leaks, efficient memory paradigms, secure, etc...) and design in grading this assignment.

 - Makefile
 - image.h
 - image.cc
 - main.cc
 - Any other file relavent to this checkpoint and your design.

You are welcome to keep changing and submitting this checkpoint up to the deadline.

THIS CHECKPOINT IS COMPLETE.

Congratulations!
