PA4
========================================

Model loader is added
The file name should be given as a command line argument
A sample board object model is created using blender
Note: 
mtl file loader is written didn`t have time to integrate it in the porgram
The program runs well on ECC machines but could not run it on nomachine due to a seg fault

Building This Example
---------------------

*This example requires GLM*
*On ubuntu it can be installed with this command*

>$ sudo apt-get install libglm-dev

*On a Mac you can install GLM with this command(using homebrew)*
>$ brew install glm

To build this example just 

>$ cd build
>$ make

*If you are using a Mac you will need to edit the makefile in the build directory*

The excutable will be put in bin

Additional Notes For OSX Users
------------------------------

Ensure that the latest version of the Developer Tools is installed.
