#include <iostream>
#include <string>
#define BUFFSIZE 10000000

using namespace std;
long long table[BUFFSIZE];

long long exchange(long long coin){
	if(coin <= 1)
		return coin;
	if(coin < BUFFSIZE && table[coin] > 0)
		return table[coin];
	bool exch = false;
	long long exVal = (exchange(coin/2) + exchange(coin/3) + exchange(coin/4)); 
	if(exVal > coin){
		if(coin < BUFFSIZE)
			table[coin] = exVal;
		exch = true;
	} else if(coin < BUFFSIZE)
		table[coin] = coin;
	return exch ? exVal : coin; 
}
