./bin/Spiro > test.txt
./jgraph/jgraph -P test.txt | ps2pdf - | convert -density 300 - -quality 100 test.jpg