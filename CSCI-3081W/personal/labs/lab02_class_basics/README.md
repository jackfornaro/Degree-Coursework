# 3081 Lab02 C++ Class Basics
_(Due: Friday, Sept. 17, 2021 @ 11:59pm)_

## What You Will Learn

1. Create the header and source file for a new C++ class.
2. Create a constructor for a class.
3. Define public methods and private class members.
4. Use operator overloading.
5. How to understand makefiles.

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

**_What just happened?_** If you run the above command, you "switch" into the _support-code_ branch. This means that git changes the filesystem to represent the state of files under the _support-code_ branch, which is likely to be different than they are in the main branch. This doesn't mean that you have changed the main branch! It simply means that the files currently visible to you on your system reflect what is in the current branch. After pulling the latest shared code into your local support-code branch, you switch back to the main branch exactly as it appeared before, and then you merged what you just pulled down from the shared-upstream repo into the main branch. Now the main branch has both the work that you have done and the shared code.

**Why didn't we do _git pull_ when in the support-code branch?** The default command in the Git workflow would indeed be _git pull_. However, that command uses the default target _origin_. For our work, _origin_ is the target for your remote repository, repo-<your_id> residing on the github.umn.edu server. We set up shared-upstream as a secondary remote target repository, with the name of _upstream_. To complete the pull action for that shared repo, we need to add the target name to the _git pull_ command.

**Why do we have support-code?** Technically, we could issue a command that takes these changes and merges them directly into _main_, without having to deal with our own local _support-code_ branch. That's true, and we could do that. But, we wanted to A) make sure that students maintain a clean copy of the provided code on their local machine. If you make a mistake in your _main_ branch, having the clean copy may be beneficial. And B) give you practice in handling merges, since that will be a beneficial skill to have when we start making more complex branching structures during the project.

As stated, branches are integral to Git workflow. To this end, the roles of each branch are made very clear below:

- `support-code`: This branch is essentially a landing pad for the support code base that we will be giving to you throughout the course (hence the name). When you want to pull any support code from the `shared-upstream` repo, you want to checkout this branch, pull from upstream with above command, then merge into whichever branch you want to develop on.

- `main`: A branch for development. Here is where you can play around with code, add features, refactor old code, etc.

- `feedback`: Feedback will be published to this branch for specific labs (for example Lab01_git_basics).

- Future feature branches: Later on in the course, we will be expanding on the branching philosophy and introducing `feature` branches. These are singular purpose branches created for a single job. Good traits of a feature branch include a descriptive name and very isolated changes. Generally a feature branch will fork off from a development branch then be merged back into the development branch as soon as the feature is complete.

**Optional reading and last thoughts before "real" coding:** The following is a useful link further describing a successful git branching model. Just browsing the figures will give you a good mental picture of an effective git repo, and reading the entire article will give you a leg up on anyone in the industry that just googles whatever git command they need for a particular situation. <https://nvie.com/posts/a-successful-git-branching-model/>. Keep it mind that not all git workflows are the same, but this is a good reference for a traditional git workflow.

### What's in labs/lab02_class_basics

- .gitignore:
  - This file exists to ensure that certain file types like .o and the executables are not added to the git repository.  This saves on file space and repository maintenance.  Take a look at the contents of the file to see what is being ignored.

- main.cc:
  - This contains the main function, which creates and operates on a set of vectors.

- Makefile:
  - This makefile is provided to allow you to easily build the executable to run this program, assuming you've created a proper vector3.h and vector3.cc set of files. It also provides for a _clean_ target, to ease removal of the resulting files generated by the build process.

- README.md:
  - You're reading this now.

- checkpoint1:
  - This is a folder will be used for the project iteration 1 checkpoint described below.

### What You Will Add

- vector3.h:
  - The header file for this new class. It should include the declaration of two constructors and the five class methods: Print, the addition operator +, the substration operator -, the multiplication operator *, and the division operator /.

- vector3.cc:
  - The source file for the class definition.

### Building the Class Vector3

<hr>
  **The primary goal of this lab is for you to build a simple C++ class to fulfill the interface as exhibited in the provided main.cc file.**
<hr>

Review _main.cc_ now to see how the class will be used. Notice the class method Print and several operators (+,-,*,/). A vector3 should have an x, y, and z component, both of which are private to the class, but there is no indication in the _main.cc_ of how those are specified or used, thus implementation is up to you.

 Here is an example of how to create the addition operator using operator overloading:

 ```c++
Vector3 operator+(Vector3 vec) {
  return Vector3(x + vec.x, y + vec.y, z + vec.z);
}
```

Notice that the operator _operator+(Vector3)_ is a class method. It adds two vectors together, but only 1 Vector3 object is passed in.  Notice that we can access the private members of the Vector3 that is passed in because it is of the same type.

Keep in mind that although the x and y components of a Vector3 object are private, they are private only to objects of different types. It means any Vector3 object can directly access private components of any other Vector3 object!

### Executing Lab Code

The code provided for lab02 will create an executable by compiling the provided
C++ files using the _Makefile_. The resulting executable, _vector_app_, should be created if your vector3.h and vector3.cc files do not cause syntax errors.

Open the _Makefile_ and take note of each rule.  Determine the target, dependencies, and recipe for each.  For example, to build vector3.o, it depends on vector3.h and vector3.cc.  The recipe for building vector3.o is ```g++ -c vector3.cc -o vector3.o```.  Look at the _Makefile_ to consider the target, dependencies, and recipe for building the vector_app.

Build the executable using the makefile and run the executable.

```bash
% cd labs/lab02_class_basics
% make
% ./vector_app
```

If there is an error when typing make, resolve the error and run make again.  Your output should look like the following:

```
CSCI3081W Lab 2
Vector 1 contains the following: 
[0, 0, 0]
Vector 2 contains the following: 
[1, 1, 1]
Vector 3 contains the following: 
[3, 4, 5]
Vector 4 contains the following: 
[4, 5, 6]
Vector 5 contains the following: 
[2, 3, 4]
Vector 6 contains the following: 
[9, 12, 15]
Vector 7 contains the following: 
[1.5, 2, 2.5]
Initial Position: [0, 0, 0]
Velocity: [1, 1, 0]
dt: 0.1
Position at i=0: [0.1, 0.1, 0]
Position at i=1: [0.2, 0.2, 0]
Position at i=2: [0.3, 0.3, 0]
Position at i=3: [0.4, 0.4, 0]
Position at i=4: [0.5, 0.5, 0]
Position at i=5: [0.6, 0.6, 0]
Position at i=6: [0.7, 0.7, 0]
Position at i=7: [0.8, 0.8, 0]
Position at i=8: [0.9, 0.9, 0]
Position at i=9: [1, 1, 0]
```

Run the following:

```
make clean
```

Consider the following questions: What happens to the .o files and the vector_app?  Why would you want to do this?

### Add Changes to Repo Locally and On Server

You need to _stage_ all changes to the repository, which prepares those items to be permanently part of the repository. 
When you _commit_ those changes, they are saved to your local repository, which lives in your cselabs account (or your
personal computer if that is what you are working on). When you _push_ those changes, they will be copied to the repo on the server. The difference between
_commit_ and _push_ is what separates git from centralized version control systems.

```bash
% git status
% git add -A
% git status
% git commit -m "Adding lab02 deliverables"
% git push
```

**_What just happened?_** Double-checking the files to be staged using the _git status_ command. All of the tracked changes are staged with `git add -A`.  The second _git status_ command shows the staged changes.  Those staged changes were committed to your local repository and tagged with the message that follows `-m`, then pushed to the server in your remote repository.

### Submitting your Lab

Submit your work by uploading the following files to Gradescope for the Lab02 assignment.  Your code will be automatically graded and your score recorded.

 - vector3.h
 - vector3.cc

You are welcome to keep changing and submitting this lab up to the deadline.  Gradescope will recompile and test your code.

THIS LAB IS COMPLETE.

Congratulations!


# Iteration 1: Checkpoint 1 - Drone Movement 
_(Due Thurs, Sept. 23, 2021 @ 11:59)_

This extended lab checkpoint uses the results above as a starting place for moving a drone in our project.  You are to use your Vector3 class that was created in this lab and apply _Euler integration_ to update a drone's position based on keyboard input.  We will provide a simple 2D interface that will help you visualize your results and walk you though some of the steps for making the drone move with the keys "w", "s", "d", "a" and the arrow keys.

## What You Will Learn

1. Basic commands for compiling and linking a C++ program to build the executable.
2. How Makefiles compile and link C++ programs.
3. How to build a Makefile to automate the build process.
4. How to link external libraries.
5. **Optional:** How to start interacting with a drone.

## The 2D interface for graphics

This application is a web based application which allows us to use 2D graphics.  A C++ opens up a web socket to communicate with an html document using the javascript web sockets api.  This application uses a few external libraries (libwebsockets, CppWebServer, and picojson).  You will not need to know too much about these for this assignment except how to link them in your Makefile.

For your information, the graphics for this application is written using P5.js, which is similar to Java Processing.  In the future we will use a library called Three.js, a 3D graphics library for web pages.  We are using web based technologies so that we can take advantage of the graphical capabilities of browsers rather than focusing on the complexities of cross platform graphics development (which can be difficult to configure).  The browser based application combined with docker allows us to run these types of applications on the major operatings systems (e.g. Linux, Mac, and Windows).  In other words, you will have the opportunity to run these on your own machines in the future due to this design decision.

The function of the arrow keys for our application are described below:

* "w" - Move in the positive z direction
* "s" - Move in the negative z direction
* "UpArrow" - Move in the positive y direction
* "DownArrow" - Move in the positive y direction
* "RightArrow" - Move in the positive x direction
* "LeftArrow" - Move in the positive x direction
* "a" - Rotate to the left
* "d" - Rotate to the right

To run this application, you will need to build it by creating a Makefile.

## Configuring make to build the application

<hr>
  **The primary goal of this lab is for you to build a makefile that can compile this visual application and optionally implement Euler integration to move the drone.**
<hr>

To start you can navigate to the following and list the files:

```bash
% cd labs/lab02_class_basics/checkpoint1
% ls
```

### What's in labs/lab02_class_basics/checkpoint1

- main.cc:
  - This contains the main function, which runs the web application DroneApp (defined in drone_app.h).  You will not need to change this file, but you should look at it to get an idea of how to start a web server with the CppWebServer library (more information on this will come later).

- drone_app.h
  - This contains the _interface_ for the DroneApp class web based drone application.  It has special methods that allow us to send text (in JSON format) back and forth between the C++ code and the web page.  You will not need to change this file.  It has methods for updating the web page and receiving keyborad commans.  You should look at the interface to get an idea of how this application works.

- drone_app.cc:
  - This file contains the _implementation_ of the DroneApp class.  This code shows how we technically accomplish communication between the web and the C++ code.  Do not worry too much about how this works right now.

- drone.h
  - This contains the _interface_ for the Drone class, which is used within the DroneApp class.  You may edit this file to add member variables or methods.

### What's outside the scope of this class

You do not need to change or understand these files, as they are beyond the scope of this course.  You are welcome to view or modify the files.

- web/index.html:
  - This is the web page that is loaded when navigating to http://localhost:8081/. 
  
- web/p5.min.js:
  - This is the P5.js javascript library used for 2D graphics on the web.  

- web/sketch.js:
  - This is the drone UI writen in P5.js.

- web/WSApi.js:
  - This file handles web socket code to communicate between the web page and the C++ code. 


### What You Will Add

- vector3.h:
  - The Vector3 class _interface_ you created in the first part of the lab.

- vector3.cc:
  - The Vector3 class _implementation_ you created in the first part of the lab.

- drone.cc:
  - The Drone class _implementation_ based on drone.h.  You will create this file and implement the methods.

- Makefile:
  - You will create a makefile to compile the DroneApp by creating object files and linking them together.

### Step 1: Import your Vector3 class

If you are working on the lab machines, you may need to first load a version of g++ that support c++ 11 standard (-std=c++11) with the following command:

```bash
% module load soft/gcc/7.1
```

Then follow the steps below:

1. The first step of this checkpoint is to copy your vector3.h and vector3.cc to this folder:
2. Create a file named Makefile and add a rule to create the vector.o object file.  You may refer to the Makefile from earlier.
3. Add a similar clean rule to the Makefile to remove object files (*.o) and the drone_app.

```bash
% make vector3.o
% ls
```

You should see a vector3.o object file.

### Step 2: Add the drone class to your makefile

Create a drone.cc file and _implement_ the Drone _interface_ in drone.h.  It is fine, for now, to create methods that do not do anything, however, be sure to return a value if the method has a return value (non void methods).

Follow a similar process from Step 1 to add this class to your makefile and create the drone.o object file.  Remember that the drone.o file depends on both the drone.h and drone.cc.

### Step 3: Use the makefile to create the other object files

Create rules for drone_app.o and main.o.  Run make to see what happens:

```bash
% make main.o
```

**_What just happened?_** You should see a compile error saying that WebServer.h does not exist.  This is because we need to specify where to find this external header file.  This a header file that defines a web server within the CppWebServer library.  On the lab machines, you can find this file in the following CSCI 3081 directory: /project/grades/Fall-2021/csci3081/dependencies/include (An include directory is often where header files are stored.  We will do this as well later in the project.)

You can view this file as well as other libraries we will use throught this project with the following commands:

```bash
% ls /project/grades/Fall-2021/csci3081/dependencies
% ls /project/grades/Fall-2021/csci3081/dependencies/include
% cat /project/grades/Fall-2021/csci3081/dependencies/include/WebServer.h
```

To add this directory let's create a variable at the top of the Makefile as follows:

```
DEPENDENCY_DIR = /project/grades/Fall-2021/csci3081/dependencies
INCLUDE_DIRS = -I$(DEPENDENCY_DIR)/include
```

This will create a variable called INCLUDE_DIRS that the compiler will look for header files using the -I option for g++.  We then can modify the main.o build rule as follows:

```
main.o: main.cc
	g++ -std=c++11 $(INCLUDE_DIRS) -c main.cc -o main.o
```

Try building the main.o object file again now that we set the include directories:

```bash
% make main.o
% ls
```

You should now see that the main.o is created.  You will also need to add the include directories to the drone_app.o rule.

### Step 4: Build the application

Finally, we need to build the drone_app executable by linking all the *.o files together.  To start, lets add a rule for building drone_app, where the dependencies are each object file (*.o) file.  Edit your Makefile to build the drone_app at the top of the file below the variable definitions (so it will be the default target).  Refer to the previous makefile where we built the vector_app in the lab.  After adding, we will try to build the app by running ```make```.

```bash
% make 
```

You should see the following insane linking error:

```
main.o: In function `main':
main.cc:(.text+0xb8): undefined reference to `WebServerBase::service(int)'
main.o: In function `WebServerBase::Session::Session()':
main.cc:(.text._ZN13WebServerBase7SessionC2Ev[_ZN13WebServerBase7SessionC5Ev]+0xb): undefined reference to `vtable for WebServerBase::Session'
main.o: In function `JSONSession::~JSONSession()':
main.cc:(.text._ZN11JSONSessionD2Ev[_ZN11JSONSessionD5Ev]+0x22): undefined reference to `WebServerBase::Session::~Session()'
main.o: In function `csci3081::DroneApp::DroneApp()':
main.cc:(.text._ZN8csci30818DroneAppC2Ev[_ZN8csci30818DroneAppC5Ev]+0x1c): undefined reference to `vtable for csci3081::DroneApp'
main.o: In function `WebServer<csci3081::DroneApp>::~WebServer()':
main.cc:(.text._ZN9WebServerIN8csci30818DroneAppEED2Ev[_ZN9WebServerIN8csci30818DroneAppEED5Ev]+0x22): undefined reference to `WebServerBase::~WebServerBase()'
main.o: In function `WebServer<csci3081::DroneApp>::WebServer(int, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)':
main.cc:(.text._ZN9WebServerIN8csci30818DroneAppEEC2EiRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE[_ZN9WebServerIN8csci30818DroneAppEEC5EiRKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE]+0x24): undefined reference to `WebServerBase::WebServerBase(int, std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)'
main.o:(.data.rel.ro._ZTV9WebServerIN8csci30818DroneAppEE[_ZTV9WebServerIN8csci30818DroneAppEE]+0x10): undefined reference to `WebServerBase::createSession(void*)'
main.o:(.data.rel.ro._ZTV11JSONSession[_ZTV11JSONSession]+0x28): undefined reference to `WebServerBase::Session::sendMessage(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)'
main.o:(.data.rel.ro._ZTV11JSONSession[_ZTV11JSONSession]+0x38): undefined reference to `WebServerBase::Session::onWrite()'
main.o:(.data.rel.ro._ZTI9WebServerIN8csci30818DroneAppEE[_ZTI9WebServerIN8csci30818DroneAppEE]+0x10): undefined reference to `typeinfo for WebServerBase'
main.o:(.data.rel.ro._ZTI11JSONSession[_ZTI11JSONSession]+0x10): undefined reference to `typeinfo for WebServerBase::Session'
collect2: error: ld returned 1 exit status
Makefile:5: recipe for target 'drone_app' failed
make: *** [drone_app] Error 1
```

**_What just happened?_** Undefined reference means that we are not linking some object file.  In this case we are missing the WebServerBase object file (although we were able to define the symbol and compile using the header file).  We need to tell the compiler where the .o file is.  In this case, the .o file is stored in a group of object files (called a library).  The library is stored again in our dependencies directory here: /project/grades/Fall-2021/csci3081/dependencies/lib/libCppWebServer.a  (our external libraries are stored in the lib directory.  Try the following: ```ls /project/grades/Fall-2021/csci3081/dependencies/lib``` for other libraries we may need to link).

#### Link a library

Let's start by linking the libCppWebServer.a library.  This is a bit more complicated then setting the include directories because we need to provide the location of the library and also tell the compiler which library to link.  To do this, we will add the following variables (LIB_DIRS and LIBS) at the top of the Makefile:

```
DEPENDENCY_DIR = /project/grades/Fall-2021/csci3081/dependencies
INCLUDE_DIRS = -I$(DEPENDENCY_DIR)/include
LIB_DIRS = -L$(DEPENDENCY_DIR)/lib
LIBS = -lCppWebServer
```

Notice we use -L to define the library directories and -l to define which library to use.  Notice also that for the -l command we leave off the lib and .a of libCppWebServer.a.  Finally, let's modify our drone_app target as follows:

```
drone_app: drone.o drone_app.o main.o vector3.o
	g++ -std=c++11 $(LIB_DIRS) drone.o drone_app.o main.o vector3.o $(LIBS) -o drone_app
```

Unfortunately, you should get another underfinded reference error:

```
/project/grades/Fall-2021/csci3081/dependencies/lib/libCppWebServer.a(WebServer.cpp.o): In function `WebServerBase::Session::sendMessage(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)':
/env/CppWebServer/src/WebServer.cpp:30: undefined reference to `lws_callback_on_writable'
/project/grades/Fall-2021/csci3081/dependencies/lib/libCppWebServer.a(WebServer.cpp.o): In function `WebServerBase::Session::onWrite()':
/env/CppWebServer/src/WebServer.cpp:45: undefined reference to `lws_write'
/env/CppWebServer/src/WebServer.cpp:50: undefined reference to `lws_callback_on_writable'
/project/grades/Fall-2021/csci3081/dependencies/lib/libCppWebServer.a(WebServer.cpp.o): In function `callback_web_server(lws*, lws_callback_reasons, void*, void*, unsigned long)':
...
collect2: error: ld returned 1 exit status
Makefile:9: recipe for target 'drone_app' failed
make: *** [drone_app] Error 1
```

**_What just happened?_** libCppWebServer.a actually relies on other libraries like libwebsockets.a and other system level libraries (e.g. libssl and libz).  We will need to add these to our LIBS variable as follows:

```
LIBS = -lCppWebServer -lwebsockets -lssl -lcrypto -lz
```

Now, finally, after running make, you should be able to build drone_app!  Run the following and notice that drone_app finally exists (occassionally, you may need to run ```make clean``` to rebuild everything):

```
make clean
make
```

#### Running the program

Finally, we can run the program by running drone_app and passing in a web port (traditionally we use the port 8081, but you may use a different one) to start the web server as follows:

```
./drone_app 8081
```

Open up Firefox and browse to http://127.0.0.1:8081/.  You should see a simple 2D drone.  You can kill the web application by using CTRL+C on the command line.

You now have a working system where you can add the code needed to move your drone!  If you see the visual, it means you have completed your checkpoint.  You may submit your work at this time as described in the next section once the Gradescope link is available.  Now, you can try to make the drone move using your Vector3 class in the _Optional_ portion of the lab.

### Submitting your Checkpoint 1 (staring Monday, 9/20/2021)

Submit your work by uploading the following files to Gradescope for the Checkpoint1 assignment (which will be available starting Monday evening, September 20, 2021).  Your code will be automatically graded and your score recorded.

 - vector3.h
 - vector3.cc
 - drone.h
 - drone.cc
 - Makefile

You are welcome to keep changing and submitting this checkpoint up to the deadline.  Gradescope will recompile and test your code.

THIS CHECKPOINT IS COMPLETE.

Congratulations!

# Optional: Actually make the drone move

The main purpose of the checkpoint was to learn how to build a larger program using multiple libraries.  Now you have a working system connected to the visualization that you can begin to modify.  Making the drone move is perhaps a team effort.  Throughout iteration 1 we will provide hints on how drones move and how to accomplish this.  You may start prototyping movement now using the methods in the Drone class.  Here are a description of each method:

 - ```void Update(double dt);``` 
 	- Called repeatedly every simulation frame.  dt is the time since the last update call.  You should use Euler integration here to update the position of the drone based on the joystick information.  _Hint:_ Look at example code for Euler integration in the labs/lab02_class_basics/main.cc using your Vector3 class.
 - ```void SetJoystick(double x, double y, double z, double rotate);``` 
 	- Called to set the state of keyboard button presses.  Print out the parameters to see what values are returned for "w", "s", "a", "d", and arrow keys.  This is how to get information from the keyboard.
 - ```double GetPosition(int index);``` 
 	- This method is called by the DroneApp to get the drone's current 3D position.  Index = 0 is the x position, index = 1 is the y position, and index = 2 is the z position.  Return the current position of the drone based on the index value.
 - ```double GetPropellerSpeed(int index);``` 
 	- The drone has four propellers.  This method is called by the DroneApp to send to the visualization the speed of each propeller.  The index is the propeller number.  Speeds can be any number, but values between 0 and 2 work well with the demo application.

We will release a video on Canvas showing what a moving drone will look like using the arrow keys described above.  The video will also illustrate the speed of propellers.  This shows how quadcopters work.  The link to the video will be provided soon.
