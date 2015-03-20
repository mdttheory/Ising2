rm data/*
rm images/*
make clean -f ising_makefile
make ising2.exe -f ising_makefile
./ising2.exe
python3 plot_spins.py
