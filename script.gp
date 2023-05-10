reset
set xlabel 'M'
set ylabel 'prob.'
set title 'Comparison Beteween M with different prob'
set term png enhanced font 'Verdana,10'
set output 'image/results.jpg'
plot \
'data/data1.dat' with linespoints linewidth 2 title "Drug1 prob = .9/Drug2 prob = .5",\
'data/data2.dat' with linespoints linewidth 2 title "Drug1 prob = .8/Drug2 prob = .5",\
'data/data3.dat' with linespoints linewidth 2 title "Drug1 prob = .7/Drug2 prob = .5",\
'data/data4.dat' with linespoints linewidth 2 title "Drug1 prob = .6/Drug2 prob = .5",\
'data/data5.dat' with linespoints linewidth 2 title "Drug1 prob = .5/Drug2 prob = .5" \