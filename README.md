# Spirograph

Spirograph implementation using Jgraph.

# Setup

1. Clone the repository
2. Run `sh setup.sh`

# Usage

To use Spirograph you first need to create a file to use as input to the program. 
The file formatt is `r g b outer-radius inner-radius pen-dist starting-angle starting-position fill`.
These are defined as follows:
* rgb: color value for the spriograph
* outer-radius: radius of outer circle
* inner-radius: radius of the inner circle
* pen-dist: distance of the drawing pin from the center of the inner circle
* starting-angle: the starting position of the inner circle in radians
* starting-position: the starting position of the pen in radians
* fill: 1 to fill in the spriograph and 0 to just have the line

Each line of the file will be a different Spirograph and they will all be laid on top of each other in the order they 
were listed in the file.

After making this file you should run `sh run.sh <input-file> <output-file>` to generate the file. 
The output-file can be either a jpg or png.

If you wish to use the executable without the shell script the usage is `./Spiro < input-file > output-file`.
The program takes input on standard in and outputs the jgraph on standard out. To convert the jgraph code into the graph
run `./jgraph/jgraph -P <input-file> | ps2pdf - | convert -density 300 - -quality 100 <output-file>`. With input-file being the output
of the Spiro program and the output-file being a jpg.

There are some example inputs in the examples directory.

# Resources

If you want to learn more about the math of a spirograph here are some good resources.

* [Spirograph Wikipedia](https://en.wikipedia.org/wiki/Spirograph)
* [Spirograph Simulator](https://sciencedemos.org.uk/spirograph.php)
* [Math Explanation](http://mathadinfinitum.weebly.com/the-math-of-spirographs.html)

For some info on how jgraph works go [here](http://web.eecs.utk.edu/~jplank/plank/jgraph/jgraph.html).