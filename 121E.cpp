#include <iostream>
#include <string>

using namespace std;

int exchange(int coin){
	if(coin == 0)
		return 1;
	return exchange(coin/2) + exchange(coin/3) + exchange(coin/4);
}

int main(){
	int input = 0;
	cin >> input;
	cout << exchange(input) << endl;
}
