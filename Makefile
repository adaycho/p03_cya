client_p03_cya: client_p03_cya.cc language.cc chain.cc alphabet.cc symbol.cc
	g++ -o client_p03_cya client_p03_cya.cc language.cc chain.cc alphabet.cc symbol.cc

clean:
	rm -r client_p03_cya *.txt