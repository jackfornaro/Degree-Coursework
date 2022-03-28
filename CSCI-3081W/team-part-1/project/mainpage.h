/*! \mainpage Canny Edge Dectector Team 8
*
*
* \section intro_sec Introduction
* 1. A brief description of the project.(Liyuan Zheng) \n\n
*
*     We developed the Canny Edge algorithm as a team together, utilizing polymorphism and inheritance methods on our filter class. The base filter class can be act as the foundation class to generate different filters such as "Greyscale filter, Gaussian Blur filter, Sobel filter, Non Max filter, Double Threshold filter, and Hysteresis filter" that can be apply to an input image,  thus we can produce our edge detection using these filters. 
*
*    From the original project, the work of building the framework was separated into separate issues/features, and the use of Github, such as repository setup, using branches and pull requests, follow process as a team.
*
*    For Canny edge detection, we implemented Greyscale, Gaussian blur, Sobel filter, Non-max suppression, Double threshold, Hysteresis, Pixelate, Remove Light filter and combined all these filters into a canny edge filter.
*
*    Finally, Documented and built all classes and methods by using Doxygen the Doxygen mainpage design for the project.
*
*
*
* 2.  How to build and run the project. (Jack Fornaro)\n\n
*
*     To start, change directories into the\n
*     repo-team-8/project directory by using the command:\n\n
*
*     cd repo-team-8/project\n\n
*
*     Then, run:\n\n
*
*     clear; make clean; make;\n\n
*
*     to clear the screen, clean the current make of
*     the program and recompile the Makefile.  Now that the
*     image_processor is up to date with the current make,
*     we can run the program with the following command:\n\n
*
*     ./image_processor <inputPath> <filterType> <outputPath>\n\n
*
*     which, if using our data file and canny_edge:\n\n
*
*     ./image_processor data/statue.png canny_edge data/statuecanny.png\n\n
*
*     The output file should appear in the project/data folder,
*     with the name given in the last parameter.  The Image
*     will have the canny_edge filter applied to it.\n\n
*
* 3. Overview of the main classes (Liang Zhang):\n\n
*
*    main.cc: This class is used during program startup and we take in the input arguments in the command lines to determine which filter we would like to use in our program, the location of the input image, and the output of the image. Then main.cc will call the apply the filter onto the output image and save it.\n
*    color.h & color.cc class: This class is used for representation of the image pixel.\n
*    filter.h class: This class is the base class for all the filters.\n
*    image.h & image.cc class: This class is used to initialize the image, copy the image, and storing the image.\n
*    kernel.h & kernel.cc class: This class is used for initialize for the kernel for different filters.\n
*    greyscale_filter.h & greyscale_filter.cc class: This class is inherited from the filter class, and it is used for applying the greyscale filter to the output image.\n
*    gaussian_blur_filter.h & gaussian_blur_filter.cc class: This class is inherited from the filter class, and it is used for applying the gaussian blur filter to the output image.\n
*    non_max_suppression.h & non_max_suppression.cc class: This class is inherited from the filter class, and it is used for applying the non max suppression filter to the output image.\n
*    double_threshold.h & double_threshold.cc class: This class is inherited from the filter class, and it is used for applying the double threshold filter to the output image.\n
*    hysteresis.h hysteresis.cc class: This class is inherited from the filter class, and it is used for applying the hysteresis filter to the output image.\n
*    canny_edge_detect.h & canny_edge_detect.cc class: This class is inherited from the filter class, and it is used for applying the canny edge detection to the output image.\n
*\n
*     Extra filters:\n
*     remove_light_pixels.h & remove_light_pixels.cc light pixel class: This class is inherited from the filter class, and it is used for removing the light pixel to the output image.\n
*     pixelation.h & pixelation.cc class: This class is inherited from the filter class, and it is used for applying pixelation to the output image.\n
*\n
* 4.  How to start extending the system (Jack Fornaro)\n\n
*
*     If you would like to add a new filter, you must first create a
*     header and implementation file for that filter.  In example:\n
*     new_filt.h & new_filt.cc.\n\n
*
*     In the header file, you must include "filter.h" to inherit the
*     abstract class filter.  Next, ensure the class declaration extends
*     from the Filter class.  The class delcation should be a name similar
*     to the filter name.  In this example, we will call the class
*     NewExampleFilter.  Since the Apply(<Image*> orig, <Image*> filt)
*     method is pure virtual in filter.h, it must be declared here.\n
*
*     In the implementation file, you must include "new_filt.h".
*     Next, you must implement the functions declared in "new_filt.h".\n
*
*     Once this is done, the filter itself must be added to main.cc.
*     This is done by including "new_filt.h", which includes the
*     implemenation of new_filt.  Next, the filter must be added to
*     the filter map with the following line of code:\n\n
*
*     filters["new_filt"] = unique_ptr<Filter>(new NewExampleFilter());\n\n
*
*     Now the filter has been added to the system within the code.  A UML
*     class for new_filt will have to be created and added to the UML
*     Diagram.  Additionally, to run the filter, perform the command:\n\n
*
*     ./image_processor data/statue.png new_filt data/statueNewFilt\n\n
*
*     And the output file will be the image with the filter applied.\n
*/
