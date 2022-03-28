# CSCI 3081 Project - Beta Code

This directory contains the support code needed to visualize the CSCI 3081 project and run tests.  The beta support code explains how to quickly get a drone moving.  Most of the logic should be moved into the simulation facade so that the simulation is not dependent on the view.  See <code>web_app.cc</code> for more details.

#### What is in this directory?
<ul>
  <li>  <code>README.md</code>
  <li>  <code>.gitignore</code>
  <li>  <code>src</code> folder, which contains:
    <ul>
      <li>  <code>main.cc</code>
      <li>  <code>web_app.h</code> and <code>web_app.cc</code>
    </ul>
  <li>  <code>test</code> folder, which contains:
    <ul>
      <li>  <code>example_test.cc</code> to get you started
    </ul>
  <li>  <code>web</code> folder, which contains:
    <ul>
      <li> The javascript visualization code
    </ul>
</ul>

## Getting Started

Here is a quick overview of how to run the visualization (These steps are similar in each build environment.  See below for environment details.):

    ```bash
    # Go to the project directory
    cd /path/to/repo/project
    
    # Build the project
    make -j
    
    # Run the tests
    ./build/test-app
    
    # Run the project (./build/web-app <port> <web folder>)
    ./build/web-app 8081 web
    ```
    
Navigate to http://127.0.0.1:8081 and you should see a visualization.  You can move a drone around by using the arrow keys and wsda.  

Below are instructions that detail how to build and run in several different environments.  

### Getting Started with Docker

#### Pre-requisites
  * [Git](https://git-scm.com/)

#### Docker Pre-requisites
  * Windows 10 Home
    * Install [wsl2 and Ubuntu](https://www.youtube.com/watch?v=ilKQHAFeQR0&list=RDCMUCzLbHrU7U3cUDNQWWAqjceA&start_radio=1&t=7)
  * Install [Docker Desktop](https://hub.docker.com/?overlay=onboarding) from [Docker Hub](https://hub.docker.com/)
  * Linux
    * Use [docker group instead of sudo](https://www.digitalocean.com/community/tutorials/how-to-install-and-use-docker-on-ubuntu-18-04)

#### Building and running the project

1. Build docker image

    ```bash
    bin/build-env.sh
    ```

2. Run docker image

    ```bash
    #Usage bin/run-env.sh <port - optional(default 8081)>
    bin/run-env.sh
    ```
    
3. Build project web server (inside docker image) NOTE: You won't be able to `cd` here yet because the project directory does not exist. If you were able to launch the above commands you should now be inside the docker image. You can exit it with CTRL+D now.

    ```bash
    # Inside docker image
    cd /home/user/repo/project
    make -j
    ```
    
4. Run web server (inside docker image)

    ```bash
    # MUST be within project/ directory inside docker image
    cd /home/user/repo/project
    ./build/web-app 8081 web
    ```
    
5. Open up Firefox and browse to http://127.0.0.1:8081/


### Getting Started using SSH on CSE Lab machines

1. SSH into a CSE Lab Machine using port forwarding for the UI

   **Note:** If port `8081` is not available, choose a different port (e.g. 8082, 8083, etc...)

    ```bash
    ssh -L 8081:127.0.0.1:8081 x500@csel-xxxx.cselabs.umn.edu
    ```
    
    Example:
    ```bash
    # ssh -L 8081:127.0.0.1:8081 x500@csel-kh1250-05.cselabs.umn.edu
    ```

2. Compile the project (within ssh session)

    ```bash
    cd /path/to/cloned/repository
    cd project
    make -j
    ```
    
 2. Run project (within ssh session)

    ```bash
    # MUST be within project/ directory
    ./build/web-app 8081 web
    ```

5. Open up Firefox and browse to http://127.0.0.1:8081/

### Getting Started with CSE Lab Machines, VOLE-3D, or VOLE

1. Log on to CSE Lab Macines, [VOLE-3D, or VOLE](https://vole.cse.umn.edu/) (VOLE is slower for graphics, but is great for tests, etc...)

2. Build project

    ```bash
    cd /path/to/cloned/repository
    cd project
    make -j
    ```
    
 2. Run project

    ```bash
    # MUST be within project/ directory
    ./build/web-app 8081 web
    ```
    
 5. Open up Firefox and browse to http://127.0.0.1:8081/
