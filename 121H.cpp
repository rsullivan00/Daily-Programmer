#include <iostream>
#include <string>
#define BUFFSIZE 1000

using namespace std;
long long maxTable[BUFFSIZE];
int toOneTable[BUFFSIZE];

//Returns the maximum possible value for exchanging
//a coin in machine 1
long long maxExchange(long long coin){
	if(coin <= 1)
		return coin;
	if(coin < BUFFSIZE && maxTable[coin] > 0)
		return maxTable[coin];
	bool exch = false;
	long long exVal = (maxExchange(coin/2) + maxExchange(coin/3) 
					 + maxExchange(coin/4)); 
	if(exVal > coin){
		if(coin < BUFFSIZE)
		 maxTable[coin] = exVal;
		exch = true;
	} else if(coin < BUFFSIZE)
	 maxTable[coin] = coin;
	return exch ? exVal : coin; 
}

//Reduces a given coin value to an integer
//number of coins of value one
int toValueOne(long long coin){
	if(coin == 0)
		return 0;
	if(coin <= 2)
		return 1;
	if(coin < BUFFSIZE && toOneTable[coin] > 0)
		return toOneTable[coin];
	if(coin < BUFFSIZE){
		toOneTable[coin] = toValueOne(coin/2) + toValueOne(coin/3)
							+toValueOne(coin/4);
		return toOneTable[coin];
	}
	return toValueOne(coin/2) + toValueOne(coin/3) + toValueOne(coin/4);
}

//Returns true iff N-value coin can be turned into
// an N-value coin and a 1-value coin.
bool operatable(long long coin){
	
}

int main(){
	long long input;
	//Initialize tables
	for(int i = 0; i < BUFFSIZE; i++){
		maxTable[i] = 0;
		toOneTable[i] = 0;
	}

	cout << ;

	return 0;
}
