#include<iostream>
#include<string.h>
#include<bitset>
using namespace std;

string hex2bin(string hex){
	int i,temp;
	string bin="";
	
	if (hex.length()%2!=0){
		cout<<"Invalid hex length!!!!!";
	}
	else{
		for(i=0;i<hex.length();i+=2){
			string sub = hex.substr(i,2);
			temp=stoi(sub,0,16);
			bin += bitset<8>(temp).to_string();
		}
		
	return bin;
	}

}


string base64(string bin,int hex_len){
	int i,rem,pad,temp;
	string result="";
	string enc="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	rem = bin.length()%6;
		
	if (rem!=0){
		for(i=0;i<6-rem;i++)
			bin+="0";
	}
		
		
	for(i=0;i<bin.length();i+=6){		
		string sub = bin.substr(i,6);
		temp=stoi(sub,0,2);
		result += enc[temp];
	}
		
		
		
	pad=hex_len%3;
		
	if (pad!=0){
		for(i=0;i<3-rem;i++)
			result+="=";
	}
		
	return result;
}

int main()

{
	string hex,bin,encoded;
	
	//cout<<"Input hex: ";
	//cin>>hex;
	
	hex="49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
	bin=hex2bin(hex);
	
	encoded=base64(bin,hex.length());
	
	cout<<encoded<<endl;
	
	return 0;
  
}
