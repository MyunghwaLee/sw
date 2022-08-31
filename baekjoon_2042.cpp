#include <stdio.h>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

int N,M,K,depth,action,val1;
long long startIdx, treeN, num, val2, sumVal;
vector<long long> tree;

void updateTree(int idx, long long val) {
	int index = idx + startIdx - 1;
	tree[index] = val;
	index = index / 2;
	
	while(index > 0) {
		tree[index] = tree[index*2] + tree[index*2+1];
		index = index / 2;
	}
}
void sum(int from, int to) {
	int start = from + startIdx - 1;
	int end = to + startIdx - 1;
	
	while(start <= end) {
		if(start%2==1) sumVal += tree[start];
		if(end%2==0) sumVal += tree[end];
		
		start = (start+1)/2;
		end = (end-1)/2;
	}
}
int main() {
	
	scanf("%d %d %d", &N,&M,&K);
	//cin >> N >> M >> K;
	
	//depth
	depth = ceil(log2(N));
	//startIdx
	startIdx = 1<<depth;
	//treeN
	treeN = startIdx*2;
	
	//printf("depth: %d startIdx: %ld treeN: %ld", depth, startIdx, treeN);
	
	tree = vector<long long>(treeN);
	for(int k=0; k<treeN; k++) tree[k] = 0;
	
	for(int i=1; i<=N; i++) {
		scanf("%lld", &num);
		//cin >> num;
		updateTree(i, num);
	}
	
	for(int j=1; j<=M+K; j++) {
		sumVal = 0;
		scanf("%d %d %lld", &action, &val1, &val2);
		//cin >> action >> val1 >> val2;
		
		if(action == 1)
		{
			updateTree(val1, val2);
		}
		else if(action == 2) 
		{
			sum(val1, val2);
			//cout<<sumVal<<endl;
			printf("%lld\n", sumVal);
		}
	}	
}
