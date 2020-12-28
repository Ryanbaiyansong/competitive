#include <set>
#include <map>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <deque>
using namespace std;
 
//struct bintree {
//	int ident;
//	struct bintree* left;
//	struct bintree* right;
//
//
//
//
//};
//
//
//
//struct bintree *addnode(int x, bintree *tree) {
//	if (tree == NULL) { 
//		tree = new bintree; 
//		tree->ident = x;   
//		tree->left = NULL;
//		tree->right = NULL; 
//	}
//	else  if (x < tree->ident)   
//		tree->left = addnode(x, tree->left);
//	else    
//		tree->right = addnode(x, tree->right);
//	return(tree);
//}
//
//int findnum (int x, bintree* tree) {
//	if (tree == NULL) {
//		return 0;
//	}
//	else if (tree->ident == x) {
//		return 1;
//	}
//	else {
//		int q1 = findnum(x, tree->left);
//		int q2 = findnum(x, tree->right);
//		return q1 + q2;
//
//	}
//}
//
//
//
//
int iint(deque<bool> a) {
	int sum = 0;
	for (int i = 0; i < a.size(); ++i) {
		sum = sum * 2;
		if (a[i] == true)
			++sum;
 
	}
	return sum;
 
 
}
 
 
 
int main() {
	int q;
	cin >> q;
	for (int w = 0; w < q; ++w) {
		int s;
		cin >> s;
		int k;
		cin >> k;
		string S;
		cin >> S;
 
		int y = 20;
		if (k < y)
			y = k;
 
		int mult = 1;
		for (int i = 0; i < y; ++i) {
			mult += mult;
		}
		--mult;
 
 
		vector<bool> chck(mult + 1, false);
 
 
 
		deque<bool> Q;
		map<char, bool> M;
		M['1'] = true;
		M['0'] = false;
 
 
		for (int i = 0; i < s; ++i) {
			if (Q.size() < y) {
				Q.push_back(M[S[i]]);
			}
			else {
				if (i >= k) {
					chck[iint(Q)] = true;
				}
				Q.pop_front();
				Q.push_back(M[S[i]]);
			}
		}
		chck[iint(Q)] = true;
		int tru = 0;
		int p = -1;
		for (int i = mult; i >= 0; --i) {
			if (chck[i] == false) {
				tru = 1;
				p = i;
				break;
 
			}
		}
		if (tru == 0)
			cout << "NO" << "\n";
		else {
			cout << "YES" << "\n";
			deque<int> Z;
			while (p != 0) {
				Z.push_front((p % 2 + 1) % 2);
				p = p / 2;
 
			}
			while (Z.size() < y) {
				Z.push_front(1);
			}
			while (Z.size() < k) {
				Z.push_front(0);
			}
			for (int i = 0; i < Z.size(); ++i) {
				cout << Z[i];
			}
			cout << "\n";
		}
 
 
 
	}
 
 
	return 0;
 
}