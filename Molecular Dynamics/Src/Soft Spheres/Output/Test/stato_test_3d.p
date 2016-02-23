##Stampo lo stato inziale le particelle come cerchietti e sovrappongo le velocità

clear
reset
set size ratio -1




#particelle
splot 'Stato_test1.dat' u 1:2:3 pt 5
#velocità
replot 'Stato_test1.dat' using 1:2:3:4:5:6 with vectors head filled lt 1
#accelerazioni
replot 'Stato_test1.dat' using 1:2:3:7:8:9 with vectors head filled lt 2

#replot 'Stato_test2.dat' u 1:2:3 pt 5
#velocità
replot 'Stato_test2.dat' using 1:2:4:5 with vectors head filled lt 5
#accelerazioni
replot 'Stato_test2.dat' using 1:2:6:7 with vectors head filled lt 6



L =7.47
R = 2**(1/5)
#set style circle radius graph R
#set xrange [0:L]
#set yrange [0:L]
