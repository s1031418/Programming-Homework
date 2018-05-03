//s1031418 hw1class cpp
#include <iostream>
#include"s1031418hw1_HugeUInteger.h"
using namespace std;
	// constru all=0
	HugeUInteger::HugeUInteger (){ 
		for (int i=0;i<1000;i++)
		arr[i]=0;
		nsize=0;
	}
	//copy constru
	HugeUInteger::HugeUInteger (HugeUInteger &in){
		nsize=in.nsize;
		for(int i=0;i<nsize;i++)
			arr[i]=in.arr[i];
	}
	//random
	void HugeUInteger::random(unsigned int size){
		nsize=size;
		if(nsize<=0)//size cannot be 0 ;
		{
			cout<<"error messenge!";
			nsize=0;
			arr[0]=0;
		}
		else if (nsize==1) //size=1 include "0" ;
		{
			nsize=1;
			arr[0]=rand()%10;
		}
		else
		{
			for(int i=0;i<nsize;i++)
					arr[i]=rand()%10;
			arr[nsize-1]=rand()%9+1;//the highest !=0
		}
	}
	//check sub n1 and n3 if they equal
	bool HugeUInteger::equal(HugeUInteger obj){
		if (nsize!=obj.nsize)
			return false;		
		for(int i=0;i<nsize;i++)
				if(arr[i]!=obj.arr[i])
					return false;
		return true;
	}	
	//check sub n1 size < n3 size 
	bool HugeUInteger::greater(HugeUInteger obj){
		if(obj.nsize>nsize)
			return false;
		else if(obj.nsize<nsize)
			return true;
		if (obj.nsize==nsize){
			for(int i=nsize-1;i>=0;i--)
			{
				if(arr[i]<obj.arr[i])
					return false;
				if(arr[i]>obj.arr[i])
					return true;
			}
		}
		return false;
	}
	//do add
	void HugeUInteger::add(HugeUInteger &add){

		int sumsize= (nsize>=add.nsize)  ? nsize+1 : add.nsize+1;
	
		for (int i=0;i<sumsize;i++){
			arr[i]+=add.arr[i];
		}
		for	(int i=0;i<sumsize;i++)
			if(arr[i]>9){
				arr[i]=arr[i]-10;
				arr[i+1]++;
			}
		nsize=sumsize;
		if (arr[nsize-1]==0)
			nsize--;
	}
	void HugeUInteger::subtract(HugeUInteger &sub){
		//check n1 ==n3 ==0;
		if (equal(sub)==true){///
			cout<<"(equal)";
			nsize=1;
			arr[0]=0;//
		}
		//check n1 size<n3 size if true then =0;
		else if(greater(sub)==false){
			cout<<"(negative)";
			nsize=1;
			arr[0]=0;
		}
		//do sub 
		else 
		{
		for(int i=0;i<sub.nsize;i++)
		{
			arr[i]=arr[i]-sub.arr[i];
			//borrow 
			while(arr[i]<0)
			{
				arr[i]+=10;
				arr[i+1]-=1;
			}
		}
		//check size;
		for(nsize=1000;arr[nsize-1]==0&&nsize>0;)
			nsize--;
		}
	}
	void HugeUInteger:: print(){
		for(int i=nsize-1;i>=0;i--)
			cout<<arr[i];
	}
