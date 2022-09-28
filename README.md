# Spirograph

Spirograph implementation using Jgraph.

# Setup

1. Clone the repository
2. Run `sh setup.sh`

# Usage

To use Spirograph you first need to create a file to use as input to the program. 
The file formatt is `r g b outer-radius inner-radius pen-dist starting-angle starting-position`.
With pen-dist being the distance from the center of the inner circle to the pen and starting-angle being the starting theta of the inside circle in radians.
Starting-position is the starting angle of the pen inside the inside circle.
Each line of the file will be a different Spirograph and they will all be laid on top of each other in the order they 
were listed in the file.

After making this file you should run `sh run.sh <input-file> <output-file>` to generate the file. 
It is assumed that the output file will be a jpg.

If you wish to use the executable without the shell script the usage is `./Spiro < input-file > output-file`.
The program takes input on standard in and outputs the jgraph on standard out. To convert the jgraph code into the graph
run `./jgraph/jgraph -P <input-file> | ps2pdf - | convert -density 300 - -quality 100 <output-file>`. With input-file being the output
of the Spiro program and the output-file being a jpg.

# Resources

If you want to learn more about the math of a spirograph here are some good resources.

* [Spirograph Wikipedia](https://en.wikipedia.org/wiki/Spirograph)
* [Spirograph Simulator](https://sciencedemos.org.uk/spirograph.php)
* [Math Explanation](http://mathadinfinitum.weebly.com/the-math-of-spirographs.html)

For some info on how jgraph works go [here](http://web.eecs.utk.edu/~jplank/plank/jgraph/jgraph.html).