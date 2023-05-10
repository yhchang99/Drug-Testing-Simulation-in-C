set xlabel 'M'
set ylabel 'prob.'
set title 'Comparison Beteween M"
plot 'data.dat' with linespoints pointtype 7 pointsize 1
set output 'results.png'