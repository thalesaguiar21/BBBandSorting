#include <iostream>
#include <vector>
#include <cmath>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::vector;

float avg(vector<float> data){
	float sum = 0;
	for(int i = 0; i < data.size(); i++){
		sum += data[i];
	}
	return sum / data.size();
}

float SD(vector<float> data, float avg){
	float variance = 0.0f;
	for(int i = 0; i < data.size(); i++){
		variance += (data[i] - avg) * (data[i] - avg);
	}
	if(data.size() != 1){
		variance /= data.size() - 1;
	}
	return std::sqrt(variance);
}

int main(){
	vector<float> data(10,0.0f);
	float mean = 0.0f;
	int n;
	while(true){
		for(int i = 0; i < 10; i++){
			if(!(cin >> n >> data[i])){
				if(i!=0){
					data.resize(i);
					mean = avg(data);
					cout << n << ' ' << mean << ' ' << SD(data, mean);
				}
				return 0;
			}
		}
		mean = avg(data);
		cout << n << ' ' << mean << ' ' << SD(data, mean) << endl;
	}
}
