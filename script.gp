reset
set xlabel 'M'
set ylabel 'prob.'
set title 'Comparison Beteween M'
set output 'image/results.jpg'
plot 'data.dat' with linespoints pointtype 7 pointsize 1
